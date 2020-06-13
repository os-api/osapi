// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API for buffer functionality
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_BUFFER_H_
#define OSAPI_COMMON_BUFFER_H_

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
#include "common/types/common_types_buffer.h"


// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************


// Buffer related
t_status	common_buffer_allocate		( t_size bufsize, t_buffer * p_buffer							);
t_status	common_buffer_reAllocate	( t_size bufsize, t_buffer * p_buffer 							);
t_status	common_buffer_deallocate	( t_buffer * p_buffer									);

t_status	common_buffer_getCapacity	( const t_buffer * p_buffer, t_size * p_size 						);
t_status	common_buffer_getData		( const t_buffer * p_buffer, void **  p_data 						);
t_status	common_buffer_getSize		( const t_buffer * p_buffer, t_size *  size 						);
t_status	common_buffer_setSize		( t_size   size, t_buffer * p_buffer	 						);

// Copy between memory areas
t_status	common_buffer_copy		( const t_buffer * p_source,                    t_buffer * p_target			);
t_status	common_buffer_copyFrom		( const t_buffer * p_source, t_size targetSize, void     * p_target			);
t_status	common_buffer_copyTo		( const void     * p_source, t_size sourceSize, t_buffer * p_target			);



// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_COMMON_BUFFER_H_ */
