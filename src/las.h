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

#ifndef las_h
#define las_h

#ifdef LA_SCALAR_FLOAT
#define las float
#elif defined(LA_SCALAR_DOUBLE)
#define las double 
#elif defined(LA_SCALAR_LONGDOUBLE)
#define las long double
#else
#error "Neither of LA_SCALAR_FLOAT or LA_SCALAR_DOUBLE or LA_SCALAR_LONGDOUBLE defined. Please specify the type to use"
#endif

#define LA_EPSILON 0.000001

#endif /* las_h */

