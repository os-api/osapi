// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC module using a POSIX compliant implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <errno.h>
#include <ipc/ipc.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_ipc.h"
#include "status/status.h"

// Own declarations
#include "ipc/ipc.h"
#include "ipc/ipc_posix.h"

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status semaphor_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports semaphores
}


t_status ipc_semaphore_create( key_t key, int sem_value, int sem_options, int * p_semid )
{
  t_status	st;
  t_semun 	semarg;

  status_reset( &st );

   if( p_semid <= (int *) 0 )
       status_iset( OSAPI_MODULE_IPC, __func__, e_ipc_params, &st );
   else
     {
       /* Create Semaphore */
       if( (*p_semid = semget( key, 1, IPC_CREAT | sem_options ) ) < 0 )
           status_eset( OSAPI_MODULE_IPC, __func__, errno, &st );
       else
         {
           /* Initialize semaphore */
           semarg.val = sem_value;
           if( semctl( *p_semid, 0, SETVAL, semarg ) < 0 )
               status_eset( OSAPI_MODULE_IPC, __func__, errno, &st );
         }
     }

  return st;
}

t_status ipc_semaphore_destroy( int semid )
{
  t_status st;

  status_reset( &st );

  if( semid < 0 )
      status_iset( OSAPI_MODULE_IPC, __func__, e_ipc_params, &st );
  else
    {
      if( semctl( semid, 0, IPC_RMID ) < 0 )
          status_eset( OSAPI_MODULE_IPC, __func__, errno, &st );
    }

  return st;

}

t_status ipc_semaphore_open( key_t key, int * p_semid 	)
{
  t_status st;

  status_reset( &st );

  if( p_semid <= (int *) 0 )
      status_iset( OSAPI_MODULE_IPC, __func__, e_ipc_params, &st );
  else
    {
      /* Open Semaphore */
      if( (*p_semid = semget( key, 0, 0 ) ) < 0 )
	  status_eset( OSAPI_MODULE_IPC, __func__, errno, &st );
    }

  return st;

}

t_status ipc_semaphore_lock( int semid )
{
  t_status		st;
  struct sembuf		sem_array[1];

  status_reset( &st );

  if( semid < 0 )
      status_iset( OSAPI_MODULE_IPC, __func__, e_ipc_params, &st );
  else
    { /* Define operation to be performed on semaphore: */

      sem_array[0].sem_num = 0;				/* One semaphore in the array	*/
      sem_array[0].sem_op  = -1;			/* Set lock 			*/
      sem_array[0].sem_flg = 0;				/* Wait on lock			*/

      /* Execute operation */
      errno=0;
      if( semop( semid, sem_array, 1 ) < 0 )
	  status_eset( OSAPI_MODULE_IPC, __func__, errno, &st );
    }

  return st;

}

t_status ipc_semaphore_unlock( int semid )
{
  t_status 		st;
  struct sembuf		sem_array[1];

  status_reset( &st );

  if( semid < 0 )
      status_iset( OSAPI_MODULE_IPC, __func__, e_ipc_params, &st );
  else
    { /* Define operation to be performed on semaphore: */

      sem_array[0].sem_num = 0;				/* One semaphore in the array	*/
      sem_array[0].sem_op  = -1;			/* Release lock			*/

      /* Execute operation */
      errno=0;
      if( semop( semid, sem_array, 1 ) < 0 )
	status_eset( OSAPI_MODULE_IPC, __func__, errno, &st );
    }

  return st;

}

t_status ipc_semaphore_getValue( int semid, int * p_value )
{
  t_status		st;
  unsigned short	sem_value[1];
  struct semid_ds	seminfo;
  t_semun		arg;

  status_reset( &st );

  if( semid < 0 )
      status_iset( OSAPI_MODULE_IPC, __func__, e_ipc_params, &st );
  else
    { /* Get number of semaphores in the Set */

      arg.buf = &seminfo;
      semctl( semid, 0, IPC_STAT, arg );
      if( arg.buf->sem_nsems != 1 )
          status_iset( OSAPI_MODULE_IPC, __func__, e_ipc_diffsem, &st );
      else
        {
          /* Obtain value inside the semaphore array */
          arg.array = &sem_value[0];
          if( semctl( semid, 0, GETVAL, arg ) >= 0 )
 	      *p_value = (int) sem_value[0];
          else
              status_eset( OSAPI_MODULE_IPC, __func__, errno, &st );
        }
     }

  return st;
}


#endif	// If POSIX is defined

