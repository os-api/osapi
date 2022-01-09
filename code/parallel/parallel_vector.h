// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Parallel module API
//
// *****************************************************************************************

#ifndef OSAPI_PARALLEL_VECTOR_H_
#define OSAPI_PARALLEL_VECTOR_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import system headers
#include <stdint.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"
//#include "common/types/common_type_time.h"

// Own declarations


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PARALLEL
/// @brief The Parallel interface module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: OS module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
/*
// 8 bit integer operations
t_status parallel_vectorInt8_add( int8_t (* r)[], t_size rSize, int8_t (* a)[], t_size aSize, int8_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt8_sub( int8_t (* r)[], t_size rSize, int8_t (* a)[], t_size aSize, int8_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt8_mul( int8_t (* r)[], t_size rSize, int8_t (* a)[], t_size aSize, int8_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt8_div( int8_t (* r)[], t_size rSize, int8_t (* a)[], t_size aSize, int8_t (* b)[], t_size bSize, int strategy );

// 16 bit integer operations
t_status parallel_vectorInt16_add( int16_t (* r)[], t_size rSize, int16_t (* a)[], t_size aSize, int16_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt16_sub( int16_t (* r)[], t_size rSize, int16_t (* a)[], t_size aSize, int16_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt16_mul( int16_t (* r)[], t_size rSize, int16_t (* a)[], t_size aSize, int16_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt16_div( int16_t (* r)[], t_size rSize, int16_t (* a)[], t_size aSize, int16_t (* b)[], t_size bSize, int strategy );

// 32 bit integer operations
t_status parallel_vectorInt32_add( int32_t (* r)[], t_size rSize, int32_t (* a)[], t_size aSize, int32_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt32_sub( int32_t (* r)[], t_size rSize, int32_t (* a)[], t_size aSize, int32_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt32_mul( int32_t (* r)[], t_size rSize, int32_t (* a)[], t_size aSize, int32_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt32_div( int32_t (* r)[], t_size rSize, int32_t (* a)[], t_size aSize, int32_t (* b)[], t_size bSize, int strategy );


// 64 bit integer operations
t_status parallel_vectorInt64_add( int64_t (* r)[], t_size rSize, int64_t (* a)[], t_size aSize, int64_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt64_sub( int64_t (* r)[], t_size rSize, int64_t (* a)[], t_size aSize, int64_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt64_mul( int64_t (* r)[], t_size rSize, int64_t (* a)[], t_size aSize, int64_t (* b)[], t_size bSize, int strategy );
t_status parallel_vectorInt64_div( int64_t (* r)[], t_size rSize, int64_t (* a)[], t_size aSize, int64_t (* b)[], t_size bSize, int strategy );


t_status parallel_vectorFloat_add( float (* r)[], t_size rSize, float (* a)[], t_size aSize, float (* b)[], t_size bSize, int strategy );
t_status parallel_vectorFloat_sub( float (* r)[], t_size rSize, float (* a)[], t_size aSize, float (* b)[], t_size bSize, int strategy );
t_status parallel_vectorFloat_mul( float (* r)[], t_size rSize, float (* a)[], t_size aSize, float (* b)[], t_size bSize, int strategy );
t_status parallel_vectorFloat_div( float (* r)[], t_size rSize, float (* a)[], t_size aSize, float (* b)[], t_size bSize, int strategy );

t_status parallel_vectorDouble_add( double (* r)[], t_size rSize, double (* a)[], t_size aSize, double (* b)[], t_size bSize, int strategy );
t_status parallel_vectorDouble_sub( double (* r)[], t_size rSize, double (* a)[], t_size aSize, double (* b)[], t_size bSize, int strategy );
t_status parallel_vectorDouble_mul( double (* r)[], t_size rSize, double (* a)[], t_size aSize, double (* b)[], t_size bSize, int strategy );
t_status parallel_vectorDouble_div( double (* r)[], t_size rSize, double (* a)[], t_size aSize, double (* b)[], t_size bSize, int strategy );
*/
#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif // OSAPI_PARALLEL_VECTOR_H_
