/*
 * status_func_string.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef MODULE_FUNCTIONS_PRIV_STRING_H_
#define MODULE_FUNCTIONS_PRIV_STRING_H_

// Name of functions of UTIL Module
static const char * module_func_string[ OSAPI_MAX_FUNCTIONS ] =
{
    "Call successful",				// = 0
    "module_supported",				// = 1

    // + Instance management
    // ++ Life cycle
    "instance_new",				// = 2
    "instance_create",
    "instance_delete",				// = 3

    // ++ Operations
    "instance_put",
    "instance_set",
    "instance_size",				// = 4
    "instance_clone",				// = 5

    // + Content management
    "message_print",
    "message_get",

    // + Instances management
    "instances_equal",				// = 6
    "instances_compare",			// = 7
    "instances_compareIcase",			// = 7
    "instances_concat",				// = 6

    OSAPI_EMPTY_STRING		// Last +1
};



#endif /* MODULE_FUNCTIONS_PRIV_STRING_H_ */
