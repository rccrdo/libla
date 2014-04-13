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

__la_inline__ void laquat_set(laquat *Q, las r, las i, las j, las k) {
	la_debug(Q);
	Q->r = r;
	Q->i = i;
	Q->j = j;
	Q->k = k;
}

__la_inline__ void laquat_set_identity(laquat *Q) {
	la_debug(Q);
	Q->r = 1.;
	Q->i = 0.;
	Q->j = 0.;
	Q->k = 0.;
}

__la_inline__ void laquat_copy(laquat *dest, laquat *src) {
	la_debug(dest && src);
	memcpy(dest, src, sizeof(laquat));
}

__la_inline__ las laquat_dot(laquat *Q) {
	la_debug(Q);
	return Q->r*Q->r + Q->i*Q->i + Q->j*Q->j + Q->k*Q->k;
}

__la_inline__ int laquat_normalize(laquat *Q) {
	la_debug(Q);
	las dot;
	las inv_norm;

	dot = laquat_dot(Q);
	if (dot == 0.) {
		return 1;
	}
	inv_norm = 1./la_sqrt(dot);
	Q->r *= inv_norm;
	Q->i *= inv_norm;
	Q->j *= inv_norm;
	Q->k *= inv_norm;
	return 0;
}

__la_inline__ void laquat_compose(laquat *dest, laquat *left_op, laquat *right_op) {
	la_debug(dest && left_op && right_op);
	dest->r = left_op->r*right_op->r - left_op->i*right_op->i - left_op->j*right_op->j - left_op->k*right_op->k;
	dest->i = left_op->r*right_op->i + left_op->i*right_op->r + left_op->j*right_op->k - left_op->k*right_op->j;
	dest->j = left_op->r*right_op->j + left_op->j*right_op->r + left_op->k*right_op->i - left_op->i*right_op->k;
	dest->k = left_op->r*right_op->k + left_op->k*right_op->r + left_op->i*right_op->j - left_op->j*right_op->i;
}

__la_inline__ void laquat_iprcompose(laquat *Q, laquat *right_op) {
	la_debug(Q && right_op);
	las Qr, Qi, Qj, Qk;
	Qr = Q->r;
	Qi = Q->i;
	Qj = Q->j;
	Qk = Q->k;
	Q->r = Qr*right_op->r - Qi*right_op->i - Qj*right_op->j - Qk*right_op->k;
	Q->i = Qr*right_op->i + Qi*right_op->r + Qj*right_op->k - Qk*right_op->j;
	Q->j = Qr*right_op->j + Qj*right_op->r + Qk*right_op->i - Qi*right_op->k;
	Q->k = Qr*right_op->k + Qk*right_op->r + Qi*right_op->j - Qj*right_op->i;
}

__la_inline__ void laquat_rotate(laquat *Q, lav3 *V, las k) {
	laquat t;
	la_debug(Q && V);

	t.r = 0.;
	t.i = V->x*k;
	t.j = V->y*k;
	t.k = V->z*k;
	laquat_iprcompose(Q, &t);
}

__la_inline__ void laquat_addv3_scaled(laquat *Q, lav3 *V, las k) {
	laquat temp;
	la_debug(Q && V);
	temp.r = 0.;
	temp.i = V->x*k;
	temp.j = V->y*k;
	temp.k = V->z*k;
	laquat_iprcompose(&temp, Q);
	Q->r += 0.5*temp.r;
	Q->i += 0.5*temp.i;
	Q->j += 0.5*temp.j;
	Q->k += 0.5*temp.k;
}

__la_inline__ void laquat_to_m3(laquat *Q, lam3 *M) {
	la_debug(Q && M);
	M->data[0] = 1. - 2.*(Q->j*Q->j + Q->k*Q->k);
	M->data[1] = 2.*(Q->i*Q->j + Q->r*Q->k);
	M->data[2] = 2.*(Q->i*Q->k - Q->r*Q->j);
	M->data[3] = 2.*(Q->i*Q->j - Q->r*Q->k);
	M->data[4] = 1. - 2.*(Q->i*Q->i + Q->k*Q->k);
	M->data[5] = 2.*(Q->j*Q->k + Q->r*Q->i);
	M->data[6] = 2.*(Q->i*Q->k + Q->r*Q->j);
	M->data[7] = 2.*(Q->j*Q->k - Q->r*Q->i);
	M->data[8] = 1. - 2.*(Q->i*Q->i + Q->j*Q->j);
}

