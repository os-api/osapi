// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	FS declaration for attributes
//
// *****************************************************************************************

#ifndef OSAPI_FS_TYPE_ELEMENT_ATTRIBUTES_H_
#define OSAPI_FS_TYPE_ELEMENT_ATTRIBUTES_H_


// *****************************************************************************************
//
// Section: Type definition
//
// *****************************************************************************************

/// @brief The enum lists the superset of all File systems possible attributes
enum osapi_fs_attributes_E
{
    osapi_fs_at_all		= 0	,  ///< Retrieve all available information
    osapi_fs_at_exists			,  ///< FS element exists
    osapi_fs_at_type			,  ///< Type of filesystem element
    osapi_fs_at_name			,  ///< Name of filesystem element

    // Identification of element inside the FS (ID of file system + ID of element itself)
    osapi_fs_at_fsID			,  ///< File system identifier
    osapi_fs_at_elemID			,  ///< Element identifier inside the file system
    osapi_fs_at_ID			,  ///< IDs of filesystem and FS element

    // Ownership related
    osapi_fs_at_user			,  ///< User owning the element
    osapi_fs_at_group			,  ///< Group owning the element

    // Permissions related
    osapi_fs_at_perm			,  ///< Element permissions

    // Size of element
    osapi_fs_at_size			,  ///< Size of element in butes

    // Time related
    osapi_fs_at_allTimes		,  ///< All available times
    osapi_fs_at_birthTime		,  ///< Time of element creation (Only in FS that support it)
    osapi_fs_at_changeTime		,  ///< Time of last change to the meta-information
    osapi_fs_at_modTime			,  ///< Time of last modification to the contents of the element
    osapi_fs_at_AccessTime		,  ///< Time of last element access (read, write, etc.)

    // Other elements
    osapi_fs_at_links			,  ///< Links to element
    osapi_fs_at_blocks			,  ///< FS blocks (UNIX systems)
    osapi_fs_at_encryption		,  ///< Encrypted element (usually is the entire file system that is encrypted)
    osapi_fs_at_compression		,  ///< Compressed element

    // ....

    osapi_fs_at_max			,  ///< Max number of supported attributes in OSAPI
};

typedef enum osapi_fs_attributes_E	t_fs_attribute;

#endif /* OSAPI_FS_TYPE_ELEMENT_ATTRIBUTES_H_ */
