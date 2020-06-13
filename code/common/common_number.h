// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API for number operations
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_NUMBER_H_
#define OSAPI_COMMON_NUMBER_H_

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
#include <stdint.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "common/common_types.h"
#include "common/common_number_priv.h"

// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************


// Functions to detect number operation errors for the largest of the numbers
// It uses a 64 bit integer type only since other integer types can always use the 64-bit one, e.g.:
// int64_t result = int32_t x + int32_t y

/// @brief The call adds two numbers: result = x + 5
/// It detects operation errors such as overflows
/// @param [in] x 	- First number to add
/// @param [in] y	- Second number to add
/// @param [out] result - Result of addition
/// @return Operation status
t_status	common_number_add	( int64_t x, int64_t y, int64_t * result	);

/// @brief The call subtracts a number from another: result = x - y
/// It detects operation errors such as overflows
/// @param [in] x 	- First number
/// @param [in] y	- Second number to subtract
/// @param [out] result - Result of addition
/// @return Operation status
t_status	common_number_subtract	( int64_t x, int64_t y, int64_t * result	);

/// @brief The call multiplies two numbers: : result = x * y
/// It detects operation errors such as overflows
/// @param [in] x 	- First number to add
/// @param [in] y	- Second number to add
/// @param [out] result - Result of addition
/// @return Operation status
t_status	common_number_multiply	( int64_t x, int64_t y, int64_t * result	);

/// @brief The call adds two real numbers decomposed in integer and fraction part using a fraction ceiling
/// It detects operation errors such as overflows and invalid fractions
/// @param [in] i1 	- First integer  to add
/// @param [in] f1 	- First fraction to add
/// @param [in] i2 	- Second integer  to add
/// @param [in] f2 	- Second fraction to add
/// @param [in] ir 	- Integer sum result
/// @param [in] fr 	- Fraction sum result
/// @return Operation status
t_status common_realNumber_add		( int64_t i1, int64_t f1, int64_t i2, int64_t f2, int64_t ceiling, int64_t * ir, int64_t * fr );

/// @brief The call subtracts two real numbers decomposed in integer and fraction part using a fraction ceiling
/// It detects operation errors such as overflows and invalid fractions
/// @param [in] i1 	- First integer  to add
/// @param [in] f1 	- First fraction to add
/// @param [in] i2 	- Second integer  to add
/// @param [in] f2 	- Second fraction to add
/// @param [in] ir 	- Integer sum result
/// @param [in] fr 	- Fraction sum result
/// @return Operation status
t_status common_realNumber_subtract	( int64_t i1, int64_t f1, int64_t i2, int64_t f2, int64_t ceiling, int64_t * ir, int64_t * fr );



// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_COMMON_NUMBER_H_ */
