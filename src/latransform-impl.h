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

__la_inline__ void latransform_set_pos(latransform *T, lav3 *V) {
	la_debug(T && V);
	lav3_copy(&T->pos, V);
}

__la_inline__ void latransform_set_orientation(latransform *T, laquat* Q) {
	la_debug(T && Q);
	laquat_to_m3(Q, &T->orient);
}

__la_inline__ void latransform_set_orientation_and_pos(latransform *T, laquat* Q, lav3 *V) {
	la_debug(T && Q && V);
	lav3_copy(&T->pos, V);
	laquat_to_m3(Q, &T->orient);
}

__la_inline__ void latransform_copy(latransform *dest, latransform *src) {
	la_debug(dest && src);
	memcpy(dest, src, sizeof(latransform));
}

__la_inline__ void latransform_rotate_only(latransform *T, lav3 *dest, lav3 *src) {
	la_debug(T && dest && src);
	lam3_rmul_v3(dest, &T->orient, src);
}

__la_inline__ void latransform_invrotate_only(latransform *T, lav3 *dest, lav3 *src) {
	la_debug(T && dest && src);
	/* rotation matrices are orthogonal: orient^-1 = orient^T */
	lam3_lmul_v3(dest, src, &T->orient);
}

__la_inline__ void latransform_transform(latransform *T, lav3 *dest, lav3 *src) {
	la_debug( T && dest && src);
	latransform_rotate_only(T, dest, src);
	lav3_ipadd(dest, &T->pos);
}

__la_inline__ void latransform_invtransform(latransform *T, lav3 *dest, lav3 *src) {
	lav3 temp;
	la_debug(T && dest && src);
	lav3_sub(&temp, src, &T->pos);
	latransform_invrotate_only(T, dest, &temp);
}

