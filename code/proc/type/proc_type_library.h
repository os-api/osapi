// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module type library declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_TYPE_LIBRARY_H_
#define OSAPI_PROC_TYPE_LIBRARY_H_


// *****************************************************************************************
//
// Section: Constants & macros
//
// *****************************************************************************************

// Maximum internal size of the name of a loaded library
// This value must be the superset of OS values
#define OSAPI_PROC_LIBRARY_MAX_NAME	20

// Wrapper macros to retrieve a library info above given a pointer X and index Y
#define proc_getLibraryName( x )	((x).name)
#define proc_getLibraryVersion( x )	((x).version)


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers

// System includes

// Generic OSAPI includes


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Define process related types
//
// *****************************************************************************************


/// @brief The s_libinfo structure is a wrapper structure for the proc_library_getAllLoaded call to contain the library name and version information
struct osapi_proc_libinfo_S
{
  char			name[ OSAPI_PROC_LIBRARY_MAX_NAME + 1 ];	///< Library Name
  unsigned int		version;					///< Library version
};

/// Define the library info type
typedef struct osapi_proc_libinfo_S	t_libinfo;


///@}
///@}


#endif /* OSAPI_PROC_TYPE_LIBRARY_H_ */
