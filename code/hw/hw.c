/*
 * hw.c
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */

#include <hw/hw.h>

#include <error/error_hw.h>

t_status hw_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports clocks
}
