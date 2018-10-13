// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Linux status declarations
//
// *****************************************************************************************

#ifndef STATUS_POSIX_H_
#define STATUS_POSIX_H_

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


#endif /* STATUS_POSIX_H_ */
