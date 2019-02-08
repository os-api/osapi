// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Model a cross-platform process state
//
// *****************************************************************************************

#ifndef OSAPI_PROC_STATE_H_
#define OSAPI_PROC_STATE_H_

enum osapi_proc_state
{
  osapi_e_proc_state_inexistent	= 0,
  osapi_e_proc_state_running	= 1,
  osapi_e_proc_state_terminated	= 2,
  osapi_e_proc_state_waiting	= 3,
  osapi_e_proc_state_stopped	= 4
};


#endif /* OSAPI_PROC_STATE_H_ */
