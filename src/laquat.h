/*
 * Copyright (c) 2008 Riccardo Lucchese, riccardo.lucchese at gmail.com
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 *    1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 
 *    2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 
 *    3. This notice may not be removed or altered from any source
 *    distribution.
 */

#ifndef laquat_h
#define laquat_h

#include <memory.h>
#include "las.h"
#include "lav3.h"
#include "lam3.h"
#include "la_debug.h"
#include "la_config.h"

typedef struct laquat {
	/* private */
	las r;
	las i;
	las j;
	las k;
} laquat;

__la_inline__ void laquat_set(laquat *Q, las r, las i, las j, las k);
__la_inline__ void laquat_set_identity(laquat *Q);
__la_inline__ void laquat_copy(laquat *dest, laquat *src);

__la_inline__ las laquat_dot(laquat *Q);

/* returns: 0 on succes, 1 on errors */
__la_inline__ int laquat_normalize(laquat *Q);

/* dest = left_op <composed> right_op */
__la_inline__ void laquat_compose(laquat *dest, laquat *left_op, laquat *right_op);

__la_inline__ void laquat_iprcompose(laquat *dest, laquat *right_op);

/* rotate by V */
__la_inline__ void laquat_rotate(laquat *Q, lav3 *V, las k);

/* update by angular velocity */
__la_inline__ void laquat_addv3_scaled(laquat *Q, lav3 *V, las k);

/* get rotation matrix */
__la_inline__ void laquat_to_m3(laquat *Q, lam3 *M);

#include "laquat-impl.h"

#endif /* laquat_h */
