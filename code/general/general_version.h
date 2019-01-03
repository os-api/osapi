// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General version declaration
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_VERSION_H_
#define OSAPI_GENERAL_VERSION_H_

// *****************************************************************************************
//
// Section: Constant definitions
//
// Purpose: Define OSAPI wide symbol information
//
// *****************************************************************************************

// Include own version definitions
#define osapi_version_X(a, b, c) a b,
enum version_X {
	  #include "general/mappings/table_version.h"
};
#undef osapi_version_X


#define osapi_quality_X(a, b, c) a b,
enum version_quality_X {
	  #include "general/mappings/table_version_quality.h"
};
#undef osapi_quality_X


// Define first the OSAPI LIB VERSION related information for client applications
#define OSAPI_VERSION_QUALITY		e_version_unstable 		// Under development

#endif /* OSAPI_GENERAL_VERSION_H_ */
