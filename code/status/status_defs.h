/*
 * status_defs.h
 *
 *  Created on: 28/03/2017
 *      Author: joao
 */

#ifndef STATUS_STATUS_DEFS_H_
#define STATUS_STATUS_DEFS_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>

// Definition of opaque status type
#define t_status		uint32_t

// The 32 bit t_status type is constructed as follows:
#define STATUS_BITS_MODULES	6
#define STATUS_BITS_FUNCTIONS	10
#define STATUS_BITS_CODE	16

#define	STATUS_SUCCESS		((t_status) 0)  		// A successful call will always return 0

// Macro section

// Helper definitions for a correct way to check for success/failure of operations
#define status_success( x )	( x == 0 )
#define status_failure( x )	( x != 0 )

#define   status_to_module( x )		( (x & 0xFC000000) >> 26 )
#define status_to_function( x )		( (x & 0x03FF0000) >> 16 )
#define     status_to_code( x )		( (x & 0x0000FFFF)	 )

#define   status_from_module( x )	( (x & 0x0000003F) << 26 )
#define status_from_function( x )	( (x & 0x000003FF) << 16 )
#define     status_from_code( x )	( (x & 0x0000FFFF)	 )



// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* STATUS_STATUS_DEFS_H_ */
