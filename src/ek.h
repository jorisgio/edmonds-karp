#ifndef EK_H_INCLUDED
#define EK_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>


#define EMSG strerror(errno)

#ifdef DEBUG
#define ERROR(msg) fprintf(stderr, "ERROR : %s:%d (%s) : %s\n", __FILE__, __LINE__, __func__, msg)
#else
#define ERROR(msg) fprintf(stderr, "ERROR : %s\n", msg )
#endif /* DEBUG */

#define ALLOC(type) (type *) malloc(sizeof(type))

#define END 0
#define CONTINUE 1

#define INFTY INT_MAX

#define MIN(a,b) ((a<=b) ? (a) : (b))

#define SUCCESS -1 /* négatif car les index des graphes sont > 0 */
#define ENOPATH 1 /* Valeur retournée quand il n'existe pas de chemin entre deux noeuds */

#endif /* EK_H_INCLUDED */