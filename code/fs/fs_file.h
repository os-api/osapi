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
#include "fs/type/fs_type_file.h"

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
/// @param [in] path    - File name
/// @param [in] mode    - File open mode options (specific to each OS)
/// @param [out] file 	- New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_open		( const t_char * path, const char ** mode, t_file * file );

/// @brief Obtain a file descriptor
/// @param [in,out] file	- File descriptor
/// @return SUCCESS if created. An error condition otherwise (e.g. An element already exists with that name).
t_status fs_file_updateInfo	( t_file * file );

// Helper functions
/// @brief Open a file for Reading
/// Location at the beginning and no file creation.
/// @param [in] path    - File name
/// @param [out] file	- New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_openRead	( const t_char * path, t_file * file );

/// @brief Open a file for Writing
/// Location at the end and file created if doesn't exist.
/// @param [in] path    - File name
/// @param [out] file	- New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_openWrite	( const t_char * path, t_file * file );

/// @brief Open a file for Reading and Writing
/// Location at the beginning for reading and at the end for writing. File is created if it doesn't exist.
/// @param [in] path    - File name
/// @param [out] file	- New file descriptor
/// @return SUCCESS if file opened. An error condition otherwise.
t_status fs_file_openReadWrite	( const t_char * path, t_file * file );

/// @brief Create a new file
/// File is created but not opened
/// @param [in] path     - File name
/// @param [in] mode     - File creation options (array of string options specific to each OS)
/// @return SUCCESS if created. An error condition otherwise (e.g. file already exists).
t_status fs_file_create		( const char * path, const char ** mode );


/// @brief Copy a file element
/// If the destination already exists, it will overwrite it
/// @param [in] source     - Copy from
/// @param [in] target     - Copy into
/// @param [in] overwrite  - If file exists, overwrite it ?
/// @return SUCCESS if copied. An error condition otherwise.
t_status fs_file_copy		( const t_char * source, const t_char * target, bool overwrite );


/// @brief Position the file stream according
/// The file position is provided by the start location (begin, end of file)
/// and the displacement offset
/// @param [in] file    - File descriptor
/// @param [in] initial - Initial position
/// @param [in] offset  - Offset of the initial position
/// @return SUCCESS if file positioned. An error condition otherwise.
t_status fs_file_setPosition	( const t_file * file, int initial, t_offset offset );


/// @brief Position the file stream on the beginning of the file
/// Helper function for fs_file_setPosition
/// @param [in] file    - File descriptor
/// @return SUCCESS if file positioned on the begging of the file. An error condition otherwise.
t_status fs_file_setPositionBegin	( const t_file * file );

/// @brief Position the file pointer on the end
/// Helper function for fs_file_setPosition
/// @param [in] file    - File descriptor
/// @return SUCCESS if file positioned on the end of file. An error condition otherwise.
t_status fs_file_setPositionEnd	( const t_file * file );

/// @brief Position the file pointer at the location from the beggining of the file
/// Helper function for fs_file_setPosition
/// @param [in] file    	- File descriptor
/// @param [in] distance	- Set current file position at a distance from the file beginning
/// @return SUCCESS if file positioned at distance. An error condition otherwise.
t_status fs_file_setPositionAt	( const t_file * file, t_offset distance );

/// @brief Change the block size for file operations
/// Helper function for fs_file_setPosition
/// @param [in] file    - File descriptor
/// @param [in] size	- New file block size
/// @return Operation status.
t_status fs_file_setBlockSize	( t_file * file, t_size size );


/// @brief Close a file
/// @param [in] file - File descriptor
/// @return SUCCESS if it exists. An error condition otherwise.
t_status fs_file_close		( t_file * file );

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

/// @brief Obtain an element descriptor from a file descriptor
/// @param [in] file	- File descriptor
/// @param [out] elem	- Element descriptor
/// @return Operation status.
t_status fs_file_getElement	( t_file * file, t_element * elem );

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_FS_FILE_H_ */
