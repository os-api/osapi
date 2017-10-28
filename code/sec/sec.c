/*
 * sec.c
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */


#include "../../code/sec/sec.h"

#include "../../code/error/error_sec.h"

t_status sec_module_supported( void )
{
  return STATUS_SUCCESS;	// Posix supports clocks
}
