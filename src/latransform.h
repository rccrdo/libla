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

#ifndef latransform_h
#define latransform_h

#include <memory.h>
#include "las.h"
#include "lav3.h"
#include "lam3.h"
#include "laquat.h"
#include "la_debug.h"
#include "la_config.h"

typedef struct latransform {
	/* private */
	lam3 orient;
	lav3 pos;
} latransform;

__la_inline__ void latransform_set_pos(latransform *T, lav3* V);
__la_inline__ void latransform_set_orientation(latransform *T, laquat* Q);
__la_inline__ void latransform_set_orientation_and_pos(latransform *T, laquat* Q, lav3 *V);

__la_inline__ void latransform_copy(latransform *dest, latransform *src);

__la_inline__ void latransform_rotate_only(latransform *T, lav3 *dest, lav3 *src);
__la_inline__ void latransform_invrotate_only(latransform *T, lav3 *dest, lav3 *src);

__la_inline__ void latransform_transform(latransform *T, lav3 *dest, lav3 *src);
__la_inline__ void latransform_invtransform(latransform *T, lav3 *dest, lav3 *src);

#include "latransform-impl.h"

#endif /* latransform_h */
