/*
 * status_modfunc.h
 *
 *  Created on: 29/04/2017
 *      Author: joao
 *      Purpose: Match the Library module names to function names
 *      Scope: Private
 */

#ifndef MODULE_FUNCTIONS_PRIV_H_
#define MODULE_FUNCTIONS_PRIV_H_

// Import Module global definitions
#include "../../code/module/module_defs.h"
#include "../../code/module/module_functions_priv_clock.h"
#include "../../code/module/module_functions_priv_hw.h"
#include "../../code/module/module_functions_priv_io.h"
#include "../../code/module/module_functions_priv_machine.h"
#include "../../code/module/module_functions_priv_os.h"
#include "../../code/module/module_functions_priv_proc.h"
#include "../../code/module/module_functions_priv_sec.h"
#include "../../code/module/module_functions_priv_string.h"
#include "../../code/module/module_functions_priv_util.h"



// Name of functions of None Module
static const char * module_func_none[] =
{
	"NONE",
	OSAPI_EMPTY_STRING
};


static const char ** func_name[] =
{
		      module_func_none,
		      module_func_string,
		      module_func_proc,
		      module_func_machine,
		      module_func_hw,
		      module_func_os,
		      module_func_io,
		      module_func_sec,
		      module_func_clock,
		      module_func_util,

		      NULL
};

static const char *	modName_get ( t_status );
static const char *	funcName_get( t_status );
static char *		codeName_get( t_status );


#endif /* MODULE_FUNCTIONS_PRIV_H_ */
