// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API for (process) signal handling
//
// *****************************************************************************************

#ifndef OSAPI_PROC_SIGNAL_H_
#define OSAPI_PROC_SIGNAL_H_

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

// Common includes
#include "common/types/common_types.h"

// Own declarations
#include "proc/proc_types.h"
#include "proc/proc_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
/// @brief The process management module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Public Function declarations
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Are signals supported by the OSAPI library?
/// @param [out] supportLevel - The level of support may vary, for instance, standard POSIX signals may be supported but not real time signals.
/// @return Operation status
t_status proc_signal_supported( int * supportLevel );

/// @brief Unblock of all signals.
/// If there are any blocked signal, these will be unblocked
/// @return Operation status
t_status proc_signal_clearAll( void );

/// @brief Send a signal to a process
/// The signal identifier will be the standard POSIX constant SIG_xxx
/// @param [in] pid - Target Process ID
/// @param [out] sigNumber - Signal identifier
/// @return Operation status
t_status proc_signal_send( t_pid pid, t_signal sigNumber );

/// @brief Send a signal to a process
/// The signal identifier will be the standard POSIX name "SIG_xxx"
/// @param [in] pid - Target Process ID
/// @param [out] sigName - Signal name
/// @return Operation status
t_status proc_signal_sendByName( t_pid pid, t_char * sigName );

/// @brief Set a signal handler function for a given signal number
/// @param [in] sigNumber - The POSIX signal constant (e.g. SIG_TERM)
/// @param [out] sigFunc - The function name/address
/// @return Operation status
t_status proc_signal_setHandler( t_signal sigNumber, t_sig_func sigFunc );

/// @brief Set a signal handler function for a given signal name
/// @param [in] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @param [out] sigFunc - The function name/address
/// @return Operation status
t_status proc_signal_setHandlerByName( t_char * sigName, t_sig_func sigFunc );

/// @brief Reset a signal to the default behavior
/// @param [in] sigNumber - The POSIX signal constant (e.g. SIG_TERM)
/// @return Operation status
t_status proc_signal_resetHandler( t_signal sigNumber );

/// @brief Reset a signal to the default behavior
/// @param [in] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @return Operation status
t_status proc_signal_resetHandlerByName( t_char * sigName );

/// @brief Get the name of a signal
/// The function maps a signal number to a signal name
/// @param [in] sigNumber - The POSIX signal constant (e.g. SIG_TERM)
/// @param [out] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @return Operation status
t_status proc_signal_getName( t_signal sigNumber, t_char ** sigName );

/// @brief Get the name of a signal
/// The function maps a signal number to a signal name
/// @param [in] sigName - The POSIX signal name (e.g. "SIG_TERM")
/// @param [out] sigNumber - The signal number
/// @return Operation status
t_status proc_signal_getNumber( t_char * sigName, t_signal * sigNumber );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_SIGNAL_H_ */
