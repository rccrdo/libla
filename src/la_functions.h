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

#ifndef la_functions_h
#define la_functions_h

#include <math.h>
#include "las.h"
#include "la_config.h"

__la_inline__ las la_sqrt(las v);
__la_inline__ las la_pow(las base, las exp);
__la_inline__ las la_abs(las v);
__la_inline__ int la_is_epsilon(las v);


__la_inline__ las la_sqrt(las v) {
#ifdef LA_FAST_SQRT
	/* sqrtf is much faster than sqrt and sqrtl both
	   on double and long double types */
	return sqrtf(v);
#else
#ifdef LA_SCALAR_FLOAT
	return sqrtf(v);
#elif defined(LA_SCALAR_DOUBLE)
	return sqrt(v);
#elif defined(LA_SCALAR_LONGDOUBLE)
	return sqrtl(v);
#endif
#endif
}

__la_inline__ las la_pow(las base, las exp) {
#ifdef LA_SCALAR_FLOAT
	return powf(base, exp);
#elif defined(LA_SCALAR_DOUBLE)
	return pow(base, exp);
#elif defined(LA_SCALAR_LONGDOUBLE)
	return powl(base, exp);
#endif
}


__la_inline__ las la_abs(las v) {
#ifdef LA_SCALAR_FLOAT
	return fabsf(v);
#elif defined(LA_SCALAR_DOUBLE)
	return fabs(v);
#elif defined(LA_SCALAR_LONGDOUBLE)
	return fabsl(v);
#endif
}

__la_inline__ int la_is_epsilon(las v) {
	return la_abs(v) <= LA_EPSILON;
}

#endif /* la_functions_h */
