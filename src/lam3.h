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

#ifndef lam3_h
#define lam3_h

#include <memory.h>
#include "las.h"
#include "lav3.h"
#include "la_debug.h"
#include "la_config.h"

typedef struct lam3 {
	/* private */
	/* ! (0,0)=data[0], (0,2)=data[2], ... , (2,2)=data[8] */
	las data[9];
} lam3;

#define M3_00(x)  x->data[0]
#define M3_01(x)  x->data[1]
#define M3_02(x)  x->data[2]
#define M3_10(x)  x->data[3]
#define M3_11(x)  x->data[4]
#define M3_12(x)  x->data[5]
#define M3_20(x)  x->data[6]
#define M3_21(x)  x->data[7]
#define M3_22(x)  x->data[8]

__la_inline__ void lam3_set(lam3 *M, las m00, las m01, las m02,
			    las m10, las m11, las m12,
			    las m20, las m21, las m22);

/* M = I */
__la_inline__ void lam3_set_identity(lam3 *M);
__la_inline__ void lam3_copy(lam3 *dest, const lam3 *src);

/* return-value = M(row,col) */
__la_inline__ las lam3_get_at(lam3 *M, int row, int col);

/* M(row,col) = k */
__la_inline__ void lam3_set_at(lam3 *M, int row, int col, las k);

/* dest = src + op */
__la_inline__ void lam3_add(lam3 *dest, const lam3 *src, const lam3 *op);

/* M = M + op */
__la_inline__ void lam3_ipadd(lam3 *M, const lam3 *op);

/* dest = src - op */
__la_inline__ void lam3_sub(lam3 *dest, const lam3 *src, const lam3 *op);

/* M = M - op */
__la_inline__ void lam3_ipsub(lam3 *M, const lam3 *op);

/* dest = src*k */
__la_inline__ void lam3_smul(lam3 *dest, const lam3 *src, las k);

/* M = M*k */
__la_inline__ void lam3_ipsmul(lam3 *M, las k);

/* dest = src*op */
__la_inline__ void lam3_rmul_m3(lam3 *dest, const lam3 *src, const lam3 *op);

/* dest = M*src */
__la_inline__ void lam3_rmul_v3(lav3 *dest, const lam3 *M, const lav3 *src);

/* dest = src*M */
__la_inline__ void lam3_lmul_v3(lav3 *dest, const lav3 *src, const lam3 *M);

/* dest = src*(1/k) */
__la_inline__ void lam3_div(lam3 *dest, const lam3 *src, las k);

/* M = M*(1/k) */
__la_inline__ void lam3_ipdiv(lam3 *M, las k);

__la_inline__ las lam3_det(const lam3 *M);

/* dest = src^-1 */
__la_inline__ void lam3_get_inverse(lam3 *dest, const lam3* src);

/* M = M^-1 */
__la_inline__ void lam3_invert(lam3 *M);

/* dest = src^T */
__la_inline__ void lam3_get_transpose(lam3 *dest, const lam3* src);

/* M = M^T */
__la_inline__ void lam3_transpose(lam3 *M);

#include "lam3-impl.h"

#endif /* lam3_h */

