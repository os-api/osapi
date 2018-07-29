// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Hardware Module API
//
// *****************************************************************************************

#ifndef MACHINE_MACHINE_H_
#define MACHINE_MACHINE_H_

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
#include "machine/machine_types.h"


// *****************************************************************************************
//
// Section: Machine module API
//
// *****************************************************************************************


#pragma GCC visibility push(default)		// Start of public interface

// Functions bellow
t_status	machine_module_supported	( void					);

// Host name related calls

t_status	machine_host_getName		( t_size maxlen, t_char * hostname	);
t_status	machine_host_setName		( t_char * hostname			);

// Domain name related calls

t_status	machine_domain_getName		( t_size maxlen, t_char * hostname	);
t_status	machine_domain_setName		( t_char * hostname			);

// HW related
/*
// Get total available RAM
t_status	machine_memory_getTotal
// Get total physical CPUs / Sockets
t_status	machine_cpu_getTotal
// Get total Ethernet Ports
t_status	machine_ports_getTotal
// Get total physical disks
t_status	machine_disks_getTotal
*/

// IP related
t_status	machine_ip_getNumber		( t_protocol selector, t_size * number					);
t_status	machine_ip_getList		( t_protocol selector, t_size number, t_ip * list			);

#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* MACHINE_MACHINE_H_ */
