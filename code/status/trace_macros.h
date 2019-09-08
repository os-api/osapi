// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide tracing macros
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include C standard headers
#include <stdarg.h>

// Import own headers
#include "status/trace.h"

// *****************************************************************************************
//
// Section: Supporting macros
//
// *****************************************************************************************


#ifdef OSAPI_TRACER
 #define TRACE_IF(x)		x;
 #define TRACE_ENTER		osapi_status_trace	( __FUNCTION__, " (", __LINE__, ") - %s", "Entering"		);
 #define TRACE_EXIT		osapi_status_trace	( __FUNCTION__, " (", __LINE__, ") - %s", "Leaving"		);
 #define TRACE_POINT		osapi_status_trace	( __FUNCTION__, " (", __LINE__, ") - %s", "Passing through"	);
 #define TRACE_MSG(x)		osapi_status_trace	( __FUNCTION__, " (", __LINE__, ") - %s", x			);
 #define TRACE(x, ...)		osapi_status_trace	( __FUNCTION__, " (", __LINE__, ") - " x, __VA_ARGS__		);
#else
 #define TRACE_IF(x)
 #define TRACE_ENTER
 #define TRACE_EXIT
 #define TRACE_POINT
 #define TRACE_MSG(x)
 #define TRACE(...)
#endif
