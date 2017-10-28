/*
 * os.c
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#include "../../code/os/os.h"

#include "../../code/error/error_os.h"

t_status os_module_supported( void )
{
  return STATUS_SUCCESS;	// Posix supports clocks
}
