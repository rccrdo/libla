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

__la_inline__ void lav3_set(lav3 *V, las x, las y, las z) {
	la_debug(V);
	V->x = x;
	V->y = y;
	V->z = z;
}

__la_inline__ void lav3_set_zero(lav3 *V) {
	la_debug(V);
	V->x = 0.;
	V->y = 0.;
	V->z = 0.;  
}

__la_inline__ void lav3_copy(lav3 *dest, const lav3 *src) {
	la_debug(dest && src);
	memcpy(dest, src, sizeof(lav3));
}

__la_inline__ void lav3_add(lav3 *dest, const lav3 *src, const lav3 *op) {
	la_debug(dest && src && op);
	dest->x = src->x + op->x;
	dest->y = src->y + op->y;
	dest->z = src->z + op->z;
}

__la_inline__ void lav3_add_scaled(lav3 *dest,
                                   const lav3 *src,
                                   const lav3 *op,
                                   las k) {
	la_debug(dest && src && op);
	dest->x = src->x + op->x*k;
	dest->y = src->y + op->y*k;
	dest->z = src->z + op->z*k;
}

__la_inline__ void lav3_ipadd(lav3 *V, const lav3 *op) {
	la_debug(V && op);
	V->x += op->x;
	V->y += op->y;
	V->z += op->z;
}

__la_inline__ void lav3_ipadd_scaled(lav3 *V, const lav3 *op, las k) {
	la_debug(V && op);
	V->x += op->x*k;
	V->y += op->y*k;
	V->z += op->z*k;
}

__la_inline__ void lav3_sub(lav3 *dest, const lav3 *src, const lav3 *op) {
	la_debug(dest && src && op);
	dest->x = src->x - op->x;
	dest->y = src->y - op->y;
	dest->z = src->z - op->z;
}

__la_inline__ void lav3_ipsub(lav3 *V, const lav3 *op) {
	la_debug(V && op);
	V->x -= op->x;
	V->y -= op->y;
	V->z -= op->z;
}

__la_inline__ void lav3_smul(lav3 *dest, const lav3 *src, las k) {
	la_debug(dest && src);
	dest->x = src->x * k;
	dest->y = src->y * k;
	dest->z = src->z * k;
}

__la_inline__ void lav3_ipsmul(lav3 *V, las k) {
	la_debug(V);
	V->x *= k;
	V->y *= k;
	V->z *= k;
}

__la_inline__ void lav3_sdiv(lav3 *dest, const lav3 *src, las k) {
	la_debug(dest && src && k!=0.);
#ifdef LAV3_FAST_DIV
	/* division is slow, multiply for 1./k instead */
	lav3_smul(dest, src, ((las)1.)/k);
#else
	dest->x = src->x / k;
	dest->y = src->y / k;
	dest->z = src->z / k;
#endif
}

__la_inline__ void lav3_ipsdiv(lav3 *V, las k) {
	la_debug(V && (k!=0.));
#ifdef LAV3_FAST_DIV
	/* division is slow, multiply for 1./k instead */
	lav3_ipsmul(V, ((las)1.)/k);
#else
	V->x /= k;
	V->y /= k;
	V->z /= k;
#endif
}

__la_inline__ las lav3_dot(const lav3 *V, const lav3 *U) {
	la_debug(V && U);
	return (V->x*U->x + V->y*U->y + V->z*U->z);
}

__la_inline__ las lav3_norm(const lav3 *V) {
	la_debug(V);
	las dot = lav3_dot(V,V);
	return la_sqrt(dot);
}

__la_inline__ int lav3_normalize(lav3 *V) {
	la_debug(V);
	las norm = lav3_norm(V);
	if (norm == 0.)
		return 1;
	lav3_ipsdiv(V, norm);
	return 0;
}

__la_inline__ void lav3_cross(lav3 *dest, const lav3 *V, const lav3 *U) {
	la_debug(dest && V && U && dest!=V && dest!=U);
	dest->x = V->y*U->z - V->z*U->y;
	dest->y = V->z*U->x - V->x*U->z;
	dest->z = V->x*U->y - V->y*U->x;
}
