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
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_com.h"
#include "status/status.h"

// Common declarations
#include "com/com_ipc.h"

// Own declarations
#include "com/posix/com_posix_ipc.h"

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status com_semaphore_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports semaphores
}


t_status com_semaphore_create( key_t key, int sem_value, int sem_options, int * p_semid )
{
  t_status			st;
  t_semun 			semarg;

  status_reset( &st );

   if( p_semid <= (int *) 0 )
     {
       status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
       return st;
     }

   /* Create Semaphore */
   if( (*p_semid = semget( key, 1, IPC_CREAT | sem_options ) ) < 0 )
     {
       status_eset( OSAPI_MODULE_COM, __func__, errno, &st );
       return st;
     }

   /* Initialize semaphore */
   semarg.val = sem_value;
   if( semctl( *p_semid, 0, SETVAL, semarg ) < 0 )
       status_eset( OSAPI_MODULE_COM, __func__, errno, &st );

  return st;
}

t_status com_semaphore_destroy( int semid )
{
  t_status			st;

  status_reset( &st );

  if( semid < 0 )
    {
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
      return st;
    }

  if( semctl( semid, 0, IPC_RMID ) < 0 )
      status_eset( OSAPI_MODULE_COM, __func__, errno, &st );

  return st;
}

t_status com_semaphore_open( key_t key, int * p_semid 	)
{
  t_status 			st;

  status_reset( &st );

  if( p_semid <= (int *) 0 )
    {
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
      return st;
    }

  /* Open Semaphore */
  if( (*p_semid = semget( key, 0, 0 ) ) < 0 )
   	  status_eset( OSAPI_MODULE_COM, __func__, errno, &st );

  return st;
}

t_status com_semaphore_lock( int semid, bool wait )
{
  t_status			st;
  struct sembuf		sem_array[1];

  status_reset( &st );

  if( semid < 0 )
    {
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
      return st;
    }

  /* Define operation to be performed on semaphore:	*/
  sem_array[0].sem_num = 0;						/* One semaphore in the array	*/
  sem_array[0].sem_op  = -1;					/* Set lock 					*/
  sem_array[0].sem_flg = (short int)(!wait);	/* Wait on lock					*/

  /* Execute operation */
  errno=0;
  if( semop( semid, sem_array, 1 ) < 0 )
  	  status_eset( OSAPI_MODULE_COM, __func__, errno, &st );

  return st;
}

t_status com_semaphore_unlock( int semid, bool wait )
{
  t_status 			st;
  struct sembuf		sem_array[1];

  status_reset( &st );

  if( semid < 0 )
    {
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
      return st;
    }

  /* Define operation to be performed on semaphore:	*/
  sem_array[0].sem_num = 0;						/* One semaphore in the array	*/
  sem_array[0].sem_op  = -1;					/* Release lock	(TODO: -1 ??)	*/
  sem_array[0].sem_flg = (short int)(!wait);	/* Wait on lock?				*/

  /* Execute operation */
  errno=0;
  if( semop( semid, sem_array, 1 ) < 0 )
  	  status_eset( OSAPI_MODULE_COM, __func__, errno, &st );

  return st;
}

t_status com_semaphore_getValue( int semid, int * p_value )
{
  t_status			st;
  unsigned short	sem_value[1];
  struct semid_ds	seminfo;
  t_semun			arg;

  status_reset( &st );

  if( semid < 0 )
    {
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
      return st;
    }

  /* Get number of semaphores in the Set */
  arg.buf = &seminfo;
  semctl( semid, 0, IPC_STAT, arg );

  if( arg.buf->sem_nsems != 1 )
    {
      status_iset( OSAPI_MODULE_COM, __func__, osapi_com_error_params, &st );
      return st;
    }

  /* Obtain value inside the semaphore array */
  arg.array = &sem_value[0];

  if( semctl( semid, 0, GETVAL, arg ) >= 0 )
   	  *p_value = (int) sem_value[0];
  else
      status_eset( OSAPI_MODULE_COM, __func__, errno, &st );

  return st;
}


#endif	// If POSIX is defined

