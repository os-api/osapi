// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS type declaration
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_ELEMENT_TYPE_H_
#define OSAPI_FS_TYPE_ELEMENT_TYPE_H_


// *****************************************************************************************
//
// Section: Type definition
//
// *****************************************************************************************

/// @brief The enum represents the possible elements of a file system
enum osapi_fs_e_element_type
{
    osapi_fs_type_unknown		= 0,  ///< Unknown element
    osapi_fs_type_file			= 1,  ///< The element is a file
    osapi_fs_type_directory		= 2,  ///< The element is a directory
    osapi_fs_type_softLink		= 3,  ///< The element is a soft link
    osapi_fs_type_hardLink		= 4,  ///< The element is a hard link
    osapi_fs_type_socket		= 5,  ///< The element is a socket
    osapi_fs_type_charDevice		= 6,  ///< The element is a character device
    osapi_fs_type_blockDevice		= 7,  ///< The element is a block device
    osapi_fs_type_fifo			= 8   ///< The element is a FIFO

    // Other elements
};

typedef enum osapi_fs_e_element_type	t_fs_eType;

#endif /* OSAPI_FS_TYPE_ELEMENT_TYPE_H_ */
