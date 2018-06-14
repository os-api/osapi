/*
 * general_priv.h
 *
 *  Created on: 10/12/2017
 *      Author: joao
 */

#ifndef GENERAL_PRIV_H_
#define GENERAL_PRIV_H_

#define module_X(a, b, c) [a]=c,

static const char * module_name[] = {
  #include <general/table_modules.h>
};

#undef module_X

#endif /* GENERAL_PRIV_H_ */
