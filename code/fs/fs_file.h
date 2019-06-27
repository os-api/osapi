// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module API for a file element
//
// *****************************************************************************************

#ifndef OSAPI_FS_FILE_H_
#define OSAPI_FS_FILE_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "fs/fs_types.h"

/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup FS
/// @brief The file system module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface


/// @brief Open a file with fine grain control
/// @param [in] path     - File name
/// @param [in] create   - If file doesn't exists, should it be created?
/// @param [in] mode     - Read, Write or both?
/// @param [in] location - Pointer to an initial location in the file (begin/end)
/// @param [in,out] file - New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_open		( const t_char * path, bool create, int mode, int location, t_file * file );

// Helper functions
/// @brief Open a file for Reading
/// Location at the beginning and no file creation.
/// @param [in] path     - File name
/// @param [in,out] file - New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_openRead	( const t_char * path, t_file * file );

/// @brief Open a file for Writing
/// Location at the end and file created if doesn't exist.
/// @param [in] path     - File name
/// @param [in,out] file - New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_openWrite	( const t_char * path, t_file * file );

/// @brief Open a file for Reading and Writing
/// Location at the beginning for reading and at the end for writing. File is created if it doesn't exist.
/// @param [in] path     - File name
/// @param [in,out] file - New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_openReadWrite	( const t_char * path, t_file * file );

/// @brief Create a new file
/// File is created but not opened
/// @param [in] path     - File name
/// @return SUCCESS if created. An error condition otherwise (e.g. file already exists).
t_status fs_file_create		( const char * path );


/// @brief Position the file stream according
/// The file position is provided by the start location (begin, end of file)
/// and the displacement offset
/// @param [in] file    - File descriptor
/// @param [in] initial - Initial position
/// @param [in] offset  - Offset of the initial position
/// @return SUCCESS if file positioned. An error condition otherwise.
t_status fs_file_setPosition	( const t_file * file, int initial, t_offset offset );

/// @brief Close a file
/// @param [in] file - File descriptor
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_file_close	( t_file * file );


/// @brief Read a file content into a given buffer
/// @param [in] file   - File descriptor
/// @return Last file operation status
t_status fs_file_getError	( const t_file * file );


/// @brief Read a file content into a given buffer
/// @param [in] file    - File descriptor
/// @param [out] buffer - Buffer to where to read into
/// @param [out] eof    - Have we finish reading the file
/// @return SUCCESS if read. An error condition otherwise.
t_status fs_file_read		( const t_file * file, t_buffer * buffer, bool * eof );

/// @brief Read a file content into a given buffer
/// @param [in] file   - File descriptor
/// @param [in] buffer - Buffer to write to file
/// @return SUCCESS if written. An error condition otherwise.
t_status fs_file_write		( const t_file * file, t_buffer * buffer );

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_FILE_H_ */
