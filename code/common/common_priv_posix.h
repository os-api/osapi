// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common Module POSIX private header
//
// *****************************************************************************************

#ifndef COMMON_PRIV_POSIX_H_
#define COMMON_PRIV_POSIX_H_

// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX



// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************

size_t		get_size_pwd_entry	( void 							);
size_t		get_size_grp_entry	( void							);
void		set_common_status	( int code, const char * funcname, t_status * p_status	);


#endif // Only in POSIX mode

#endif // END of COMMON_PRIV_POSIX_H_
