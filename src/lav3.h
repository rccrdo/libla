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

#ifndef lav3_h
#define lav3_h

#include <memory.h>
#include "las.h"
#include "la_functions.h"
#include "la_debug.h"
#include "la_config.h"

typedef struct lav3 {
	/* public */
	las x;
	las y;
	las z;
#ifdef LAV3_PADDING
	las w;
#endif
} lav3;


__la_inline__ void lav3_set(lav3 *V, las x, las y, las z);

/* V = (0.,0.,0.) */
__la_inline__ void lav3_set_zero(lav3 *V);

__la_inline__ void lav3_copy(lav3 *dest, const lav3 *src);

/* dest = src + op */
__la_inline__ void lav3_add(lav3 *dest, const lav3 *src, const lav3 *op);

/* dest = src + op*k */
__la_inline__ void lav3_add_scaled(lav3 *dest,
                                   const lav3 *src,
                                   const lav3 *op,
                                   las k);

/* V = V + op */
__la_inline__ void lav3_ipadd(lav3 *V, const lav3 *op);

/* V = V + op*k */
__la_inline__ void lav3_ipadd_scaled(lav3 *V, const lav3 *op, las k);

/* dest = src - op */
__la_inline__ void lav3_sub(lav3 *dest, const lav3 *src, const lav3 *op);

/* V = V - op */
__la_inline__ void lav3_ipsub(lav3 *V, const lav3 *op);

/* dest = src*k */
__la_inline__ void lav3_smul(lav3 *dest, const lav3 *src, las k);

/* V = V*k */
__la_inline__ void lav3_ipsmul(lav3 *V, las k);

/* dest = src/k */
__la_inline__ void lav3_sdiv(lav3 *dest, const lav3 *src, las k);

/* V = V/k */
__la_inline__ void lav3_ipsdiv(lav3 *V, las k);

/* dot product between vectors V and U
   ! V & U should represent coordinates with
   respect to the same orthonormal basis of R^3 */
__la_inline__ las lav3_dot(const lav3 *V, const lav3 *U);

__la_inline__ las lav3_norm(const lav3 *V);

/* returns: 0 on success, 1 on error */
__la_inline__ int lav3_normalize(lav3 *V);

/* dest = V X U */
__la_inline__ void lav3_cross(lav3 *dest, const lav3 *V, const lav3 *U);

#include "lav3-impl.h"

#endif /* lav3_h */

