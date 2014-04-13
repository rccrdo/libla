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

#ifndef lam4_h
#define lam4_h

#include <memory.h>
#include "las.h"
#include "la_debug.h"
#include "la_config.h"

typedef struct lam4 {
	/* private */
	/* ! (0,0)=data[0], (0,3)=data[3], ... , (3,3)=data[15] */
	las data[16];
} lam4;

#define M4_00(x)  x->data[0]
#define M4_01(x)  x->data[1]
#define M4_02(x)  x->data[2]
#define M4_03(x)  x->data[3]
#define M4_10(x)  x->data[4]
#define M4_11(x)  x->data[5]
#define M4_12(x)  x->data[6]
#define M4_13(x)  x->data[7]
#define M4_20(x)  x->data[8]
#define M4_21(x)  x->data[9]
#define M4_22(x)  x->data[10]
#define M4_23(x)  x->data[11]
#define M4_30(x)  x->data[12]
#define M4_31(x)  x->data[13]
#define M4_32(x)  x->data[14]
#define M4_33(x)  x->data[15]

__la_inline__ void lam4_set(lam4 *M, las m00, las m01, las m02, las m03,
			    las m10, las m11, las m12, las m13,
			    las m20, las m21, las m22, las m23,
			    las m30, las m31, las m32, las m33);

__la_inline__ void lam4_copy(lam4 *dest, lam4 *src);
__la_inline__ las lam4_get_at(lam4 *M, int row, int col);
__la_inline__ void lam4_set_at(lam4 *M, int row, int col, las k);

/* dest = src + op */
__la_inline__ void lam4_add(lam4 *dest, lam4 *src, lam4 *op);

/* M = M + op */
__la_inline__ void lam4_ipadd(lam4 *M, lam4 *op);

/* dest = src - op */
__la_inline__ void lam4_sub(lam4 *dest, lam4 *src, lam4 *op);

/* M = M - op */
__la_inline__ void lam4_ipsub(lam4 *M, lam4 *op);

/* dest = src*k */
__la_inline__ void lam4_smul(lam4 *dest, lam4 *src, las k);

/* M = M*k */
__la_inline__ void lam4_ipsmul(lam4 *M, las k);

/* dest = src*(1/k) */
__la_inline__ void lam4_sdiv(lam4 *dest, lam4 *src, las k);

/* M = M*(1/k) */
__la_inline__ void lam4_ipsdiv(lam4 *M, las k);

#include "lam4-impl.h"

#endif /* lam4_h */
