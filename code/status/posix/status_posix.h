// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Linux status declarations
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_POSIX_H_
#define OSAPI_STATUS_POSIX_H_

#ifdef	OSAPI_POSIX

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Function declarations
//
// *****************************************************************************************

void		status_message_cPrint	( t_status status 		);
const char *	status_error_getSystem	( int error 			);
void		status_message_cGet	( t_status, t_size, t_char *	);



#endif	// OSAPI_POSIX

#endif /* OSAPI_STATUS_POSIX_H_ */
