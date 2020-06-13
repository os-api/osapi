// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Wrapper for compiler builtins (or not)
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_NUMBER_PRIV_H_
#define OSAPI_COMMON_NUMBER_PRIV_H_



// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************

#if OSAPI_COMPILER == OSAPI_COMPILER_GNU || OSAPI_COMPILER == OSAPI_COMPILER_CLANG

// Define the functions as builtin GCC macros
#define osapi_number_add( x, y, r )	__builtin_add_overflow( x, y, r )
#define osapi_number_sub( x, y, r )	__builtin_sub_overflow( x, y, r )
#define osapi_number_mul( x, y, r )	__builtin_mul_overflow( x, y, r )

#else	// TODO: Replace with generic algorithm

inline bool osapi_number_add( uint64_t x, uint64_t y, uint64_t * r )
{}

inline bool osapi_number_sub( uint64_t x, uint64_t y, uint64_t * r )
{}

inline bool osapi_number_mul( uint64_t x, uint64_t y, uint64_t * r )
{}

#endif

#endif /* OSAPI_COMMON_NUMBER_PRIV_H_ */
