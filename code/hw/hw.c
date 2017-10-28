/*
 * hw.c
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */

#include "../../code/hw/hw.h"

#include "../../code/error/error_hw.h"

t_status hw_module_supported( void )
{
  return STATUS_SUCCESS;	// Posix supports clocks
}
