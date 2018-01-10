/*
 * sec.c
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */


#include <sec/sec.h>

#include <error/error_sec.h>

t_status sec_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports clocks
}
