!#ifndef EK_H_INCLUDED
#define EK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>


#define EMSG strerror(errno)

#ifdef DEBUG
#define ERROR(msg) fprintf(stderr, "ERROR : %s:%d (%s) : %s\n", __FILE__, __LINE__, __func__, msg); abort()
#else
#define ERROR(msg) fprintf(stderr, "ERROR : %s\n", msg ); abort()
#endif /* DEBUG */

#define ALLOC(type) (type *) malloc(sizeof(type))

#define END 0
#define CONTINUE 1

#define INFTY MAX_INT

#endif /* EK_H_INCLUDED */
