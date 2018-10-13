// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String module single char implementation file
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_string.h"
#include "status/status.h"

// Own declarations
#include "string/string_basic.h"



// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status string_basic_new( t_size size, t_string * p_string )
{
  t_status	st;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER || size == 0 )
      status_iset( OSAPI_MODULE_STRING,__func__, e_string_params, &st );
  else
    {
      errno = 0;
      // Always request 1 byte extra to ensure that the '\0' ends the array of chars
      p_string->ps_location = (char *) calloc(1, size + 1 );

      if( p_string->ps_location == OSAPI_NULL_CHAR_POINTER )
	  status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
      else
	{
	  p_string->tsize = size;	// Don't count the null char
	  p_string->csize = 0;		// Only space is allocated
	}
    }

  return st;
}

t_status string_basic_delete( t_string * p_string )
{
  t_status	st;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      p_string->tsize = 0;
      p_string->csize = 0;

      if( p_string->ps_location == OSAPI_NULL_CHAR_POINTER )
	  status_iset( OSAPI_MODULE_STRING, __func__, e_string_nullPointer, &st );
      else
	  free( (void *) p_string->ps_location );
    }

  return st;
}

t_status string_basic_create( const char * p_initial_string, t_string * p_string )
{
  t_status	st;
  t_size	len;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER || p_initial_string == OSAPI_NULL_CHAR_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      len = (t_size) strlen( p_initial_string );

      errno = 0;
      // Always request 1 byte extra to ensure that the '\0' ends the array of chars
      p_string->ps_location = (char *) calloc(1, len + 1 );

      if( p_string->ps_location == OSAPI_NULL_CHAR_POINTER )
	  status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
      else
	{
	  if( strcpy( p_string->ps_location, p_initial_string ) != OSAPI_NULL_CHAR_POINTER )
	      p_string->tsize = p_string->csize = len;
	  else
	    {
	      // Unable to copy string, release memory
	      string_basic_delete( p_string );
	      status_iset( OSAPI_MODULE_STRING, __func__, e_string_create, &st );
	    }
	}
    }

  return st;
}

t_status string_basic_clone( t_string * ps_old, t_string * ps_new )
{
  t_status	st;

  status_reset( & st );

  if( ps_old == OSAPI_STRING_NULL_POINTER || ps_new == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      // Make sure that new string is not already bounded to some heap address
      if( ps_new->ps_location != OSAPI_NULL_CHAR_POINTER )
	  status_iset( OSAPI_MODULE_STRING, __func__, e_string_exists, &st );
      else
	  st = string_basic_create( ps_old->ps_location, ps_new );
    }

  return st;
}

t_status string_basic_put( const char * message, t_string * p_string )
{
  t_status	st;
  t_size	len;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      if( p_string->ps_location == OSAPI_NULL_CHAR_POINTER )
	  status_iset( OSAPI_MODULE_STRING, __func__, e_string_nullPointer, &st );
      else
	{
	  if( p_string->csize > 0 )
	      status_iset( OSAPI_MODULE_STRING, __func__, e_string_exists, &st );
	  else
	    {
	      len = (t_size) strlen( message );
	      if( p_string->tsize < len )
		  status_iset( OSAPI_MODULE_STRING, __func__, e_string_noSpace, &st );
	      else
		{
		  errno = 0;
		  if( strncpy( p_string->ps_location, message, (size_t) len ) == OSAPI_NULL_CHAR_POINTER )
		      status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
		}
	    }
	}
    }

  return st;
}

t_status string_basic_set( const char * message, t_string * p_string )
{
  t_status	st;
  t_size	len;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      if( p_string->ps_location == OSAPI_NULL_CHAR_POINTER )
	  status_iset( OSAPI_MODULE_STRING, __func__, e_string_nullPointer, &st );
      else
	{
	  len = (t_size) strlen( message );
	  if( len > p_string->tsize )
	      // Limit the size of the copied string
	      len = p_string->tsize;

	  errno = 0;
	  if( strncpy( p_string->ps_location, message, (size_t) len ) == OSAPI_NULL_CHAR_POINTER )
	      status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
	}
    }

  return st;
}

t_status string_basic_size( t_string * p_string, t_size * p_size )
{
  t_status	st;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
      *p_size = p_string->csize;

  return st;
}

t_status string_basic_print( t_string * p_string )
{
  t_status	st;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
      printf("%.*s\n", (int) p_string->csize, p_string->ps_location );

  return st;
}

t_status string_basic_get( t_string * p_string, t_size maxSize, char * message )
{
  t_status	st;

  status_reset( & st );

  if( p_string == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      errno = 0;
      if( strncpy( message, p_string->ps_location, (size_t) maxSize ) == OSAPI_NULL_CHAR_POINTER )
	  status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
    }

  return st;
}

t_status string_basic_concat( t_string * ps_str1, t_string * ps_str2, t_string * ps_final )
{
  t_status	st;

  status_reset( & st );

  if( ps_final == OSAPI_STRING_NULL_POINTER || ps_str1 == OSAPI_STRING_NULL_POINTER || ps_str2 == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      if( ps_final->ps_location == ps_str1->ps_location || ps_final->ps_location == ps_str2->ps_location )
	  status_iset( OSAPI_MODULE_STRING, __func__, e_string_sameString, &st );		// One of the string is the same as the destination string
      else
	{
	  string_basic_delete( ps_final );		  // Make sure to release memory of current string

	  // Allocate memory to hold both strings + '\0'
	  ps_final->ps_location = calloc( 1, ps_str1->csize + ps_str2->csize + 1 );

	  if( ps_final->ps_location == OSAPI_NULL_CHAR_POINTER )
	      status_iset( OSAPI_MODULE_STRING, __func__, e_string_nullPointer, &st );
	  else
	    {
	      ps_final->tsize = ps_str1->csize + ps_str2->csize;

	      errno = 0;
	      if( strncpy( ps_final->ps_location, ps_str1->ps_location, (size_t) ps_str1->csize ) == OSAPI_NULL_CHAR_POINTER )
		  status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
	      else
		{
		  errno = 0;
		  if( strncpy( ps_final->ps_location, ps_str1->ps_location, (size_t) ps_str1->csize ) == OSAPI_NULL_CHAR_POINTER )
		      status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
		  else
		      ps_final->csize = (t_size) strlen( ps_final->ps_location );
		}
	    }
	}
    }

  return st;
}

t_status string_basic_compare( t_string * ps_str1, t_string * ps_str2, Byte * p_result )
{
  t_status	st;

  status_reset( & st );

  if( ps_str1 == OSAPI_STRING_NULL_POINTER || ps_str2 == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      if( ps_str1->ps_location == OSAPI_NULL_CHAR_POINTER || ps_str1->ps_location == OSAPI_NULL_CHAR_POINTER )
	  status_iset( OSAPI_MODULE_STRING, __func__, e_string_nullPointer, &st );
      else
	  *p_result = (Byte) strcmp( ps_str1->ps_location, ps_str2->ps_location );
    }

  return st;
}

t_status string_basic_equal( t_string * ps_str1, t_string * ps_str2, bool * p_result )
{
  t_status	st;

  status_reset( & st );
  *p_result = 0;	// Assume FALSE

  if( ps_str1 == OSAPI_STRING_NULL_POINTER || ps_str2 == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      // Strings must have equal size in the first place
      if( ps_str1->csize == ps_str2->csize )
	{
	  errno = 0;
	  if( strncmp( ps_str1->ps_location, ps_str2->ps_location, (size_t) ps_str1->csize ) == 0 )
	      *p_result = 0;
	  else
	      status_eset( OSAPI_MODULE_STRING, __func__, errno, &st );
	}
    }

  return st;
}

t_status string_basic_compareIcase( t_string * ps_str1, t_string * ps_str2, Byte * p_result )
{
  t_status	st;

  status_reset( & st );

  if( ps_str1 == OSAPI_STRING_NULL_POINTER || ps_str2 == OSAPI_STRING_NULL_POINTER )
      status_iset( OSAPI_MODULE_STRING, __func__, e_string_params, &st );
  else
    {
      if( ps_str1->ps_location == OSAPI_NULL_CHAR_POINTER || ps_str1->ps_location == OSAPI_NULL_CHAR_POINTER )
	  status_iset( OSAPI_MODULE_STRING, __func__, e_string_nullPointer, &st );
      else
	  *p_result = (Byte) strcasecmp( ps_str1->ps_location, ps_str2->ps_location );
    }

  return st;
}


