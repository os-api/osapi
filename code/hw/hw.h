// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Hardware Module API
//
// *****************************************************************************************

#ifndef HW_HW_H_
#define HW_HW_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include <status/status_types.h>
#include <hw/hw_types.h>
#include <hw/hw_platform.h>

#pragma GCC visibility push(default)		// Start of public interface

// Functions bellow
t_status	hw_module_supported		( void					);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* HW_HW_H_ */
