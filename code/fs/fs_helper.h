// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Helper macros for File system elements
//
// *****************************************************************************************

#ifndef OSAPI_FS_HELPER_H_
#define OSAPI_FS_HELPER_H_


// *****************************************************************************************
//
// Section: Macro helpers
//
// *****************************************************************************************

// Positive check

#define isElementOpen(x)	(x->element.state == osapi_fs_ostate_opened)
#define isFileOpen(x)		(x->file.state    == osapi_fs_ostate_opened)
#define isDirOpen(x)		(x->dir.state     == osapi_fs_ostate_opened)
#define isLinkOpen(x)		(x->link.state    == osapi_fs_ostate_opened)

#define isElementClose(x)	(x->element.state == osapi_fs_ostate_closed)
#define isFileClose(x)		(x->file.state    == osapi_fs_ostate_closed)
#define isDirClose(x)		(x->dir.state     == osapi_fs_ostate_closed)
#define isLinkClose(x)		(x->link.state    == osapi_fs_ostate_closed)

#define isTypeFile(x)		(x->element.type == osapi_fs_type_file)
#define isTypeDir(x)		(x->element.type == osapi_fs_type_directory)
#define isTypeLink(x)		(x->element.type == osapi_fs_type_softLink || x->element.type == osapi_fs_type_hardLink)

// Negative check

#define isElementNotOpen(x)	(x->element.state != osapi_fs_ostate_opened)
#define isFileNotOpen(x)	(x->file.state    != osapi_fs_ostate_opened)
#define isDirNotOpen(x)		(x->dir.state     != osapi_fs_ostate_opened)
#define isLinkNotOpen(x)	(x->link.state    != osapi_fs_ostate_opened)

#define isElementNotClose(x)	(x->element.state != osapi_fs_ostate_closed)
#define isFileNotClose(x)	(x->file.state    != osapi_fs_ostate_closed)
#define isDirNotClose(x)	(x->dir.state     != osapi_fs_ostate_closed)
#define isLinkNotClose(x)	(x->link.state    != osapi_fs_ostate_closed)

#define isTypeNotFile(x)	(x->element.type != osapi_fs_type_file)
#define isTypeNotDir(x)		(x->element.type != osapi_fs_type_directory)
#define isTypeNotLink(x)	(x->element.type != osapi_fs_type_softLink && x->element.type != osapi_fs_type_hardLink)

// File specific macros
#define isFileAvailable(x)	(x->file.handle  >= 0)
#define isFileNotAvailable(x)	(x->file.handle  < 0)


// Directory specific macros
#define isDirNull(x)		(x->dir.handle  == NULL)
#define isDirNotNull(x)		(x->dir.handle  != NULL)


#endif 		// OSAPI_FS_HELPER_H_
