// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API for list of items
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_LIST_H_
#define OSAPI_COMMON_LIST_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard headers

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "common/types/common_types_list.h"


// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************


// Item List related
t_status	common_list_allocate		( t_size nItems, t_size itemSize, t_list * p_list					);
t_status	common_list_reAllocate		( t_size nItems, t_list * p_list 							);
t_status	common_list_deallocate		( t_list * p_list									);

t_status	common_list_getCapacity		( const t_list * p_list, t_size * p_size 						);
t_status	common_list_hasCapacity		( const t_list * list, t_size size							);
t_status	common_list_getRequiredCapacity	( const t_list * p_list, t_size * p_size 						);
t_status	common_list_getData		( const t_list * p_list, t_size item, void **  p_data					);
t_status	common_list_getSize		( const t_list * p_list, t_size *  size 						);
t_status	common_list_setSize		( t_size   size, t_list * p_list	 						);
t_status	common_list_setRequiredCapacity	( t_size   size, t_list * p_list							);

// Copy between memory areas
t_status	common_list_copy		( const t_list * p_source, t_list * p_target						);
t_status	common_list_copyFrom		( const t_list * p_source, t_size sourceItem, t_size targetSize, void   * p_target	);
t_status	common_list_copyTo		( const void   * p_source, t_size sourceSize, t_size targetItem, t_list * p_target	);



// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_COMMON_LIST_H_ */
