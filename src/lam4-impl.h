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

__la_inline__ void lam4_set(lam4 *M, las m00, las m01, las m02, las m03,
                            las m10, las m11, las m12, las m13,
                            las m20, las m21, las m22, las m23,
                            las m30, las m31, las m32, las m33) {
	la_debug(M);
	M->data[0]  = m00;
	M->data[1]  = m01;
	M->data[2]  = m02;
	M->data[3]  = m03;
	M->data[4]  = m10;
	M->data[5]  = m11;
	M->data[6]  = m12;
	M->data[7]  = m13;
	M->data[8]  = m20;
	M->data[9]  = m21;
	M->data[10] = m22;
	M->data[11] = m23;
	M->data[12] = m30;
	M->data[13] = m31;
	M->data[14] = m32;
	M->data[15] = m33;
}

__la_inline__  void lam4_copy(lam4 *dest, lam4 *src) {
	la_debug(dest && src);
	memcpy(dest->data, src->data, sizeof(lam4));
}

__la_inline__ las lam4_get_at(lam4 *M, int row, int col) {
	la_debug(M && (row>=0) && (row<=3) && (col>=0) && (col<=3));
	return M->data[row*4 + col];
}

__la_inline__ void lam4_set_at(lam4 *M, int row, int col, las k) {
	la_debug(M && (row>=0) && (row<=3) && (col>=0) && (col<=3));
	M->data[row*4 + col] = k;
}

__la_inline__ void lam4_add(lam4 *dest, lam4 *src, lam4 *op) {
	la_debug(dest && src && op);
	dest->data[0] = src->data[0] + op->data[0];
	dest->data[1] = src->data[1] + op->data[1];
	dest->data[2] = src->data[2] + op->data[2];
	dest->data[3] = src->data[3] + op->data[3];
	dest->data[4] = src->data[4] + op->data[4];
	dest->data[5] = src->data[5] + op->data[5];
	dest->data[6] = src->data[6] + op->data[6];
	dest->data[7] = src->data[7] + op->data[7];
	dest->data[8] = src->data[8] + op->data[8];
	dest->data[9] = src->data[9] + op->data[9];
	dest->data[10] = src->data[10] + op->data[10];
	dest->data[11] = src->data[11] + op->data[11];
	dest->data[12] = src->data[12] + op->data[12];
	dest->data[13] = src->data[13] + op->data[13];
	dest->data[14] = src->data[14] + op->data[14];
	dest->data[15] = src->data[15] + op->data[15];
}

__la_inline__ void lam4_ipadd(lam4 *M, lam4 *op) {
	la_debug(M && op);
	M->data[0] += op->data[0];
	M->data[1] += op->data[1];
	M->data[2] += op->data[2];
	M->data[3] += op->data[3];
	M->data[4] += op->data[4];
	M->data[5] += op->data[5];
	M->data[6] += op->data[6];
	M->data[7] += op->data[7];
	M->data[8] += op->data[8];
	M->data[9] += op->data[9];
	M->data[10] += op->data[10];
	M->data[11] += op->data[11];
	M->data[12] += op->data[12];
	M->data[13] += op->data[13];
	M->data[14] += op->data[14];
	M->data[15] += op->data[15];
}

__la_inline__ void lam4_sub(lam4 *dest, lam4 *src, lam4 *op) {
	la_debug(dest && src && op);
	dest->data[0] = src->data[0] - op->data[0];
	dest->data[1] = src->data[1] - op->data[1];
	dest->data[2] = src->data[2] - op->data[2];
	dest->data[3] = src->data[3] - op->data[3];
	dest->data[4] = src->data[4] - op->data[4];
	dest->data[5] = src->data[5] - op->data[5];
	dest->data[6] = src->data[6] - op->data[6];
	dest->data[7] = src->data[7] - op->data[7];
	dest->data[8] = src->data[8] - op->data[8];
	dest->data[9] = src->data[9] - op->data[9];
	dest->data[10] = src->data[10] - op->data[10];
	dest->data[11] = src->data[11] - op->data[11];
	dest->data[12] = src->data[12] - op->data[12];
	dest->data[13] = src->data[13] - op->data[13];
	dest->data[14] = src->data[14] - op->data[14];
	dest->data[15] = src->data[15] - op->data[15];
}

__la_inline__ void lam4_ipsub(lam4 *M, lam4 *op) {
	la_debug(M && op);
	M->data[0] -= op->data[0];
	M->data[1] -= op->data[1];
	M->data[2] -= op->data[2];
	M->data[3] -= op->data[3];
	M->data[4] -= op->data[4];
	M->data[5] -= op->data[5];
	M->data[6] -= op->data[6];
	M->data[7] -= op->data[7];
	M->data[8] -= op->data[8];
	M->data[9] -= op->data[9];
	M->data[10] -= op->data[10];
	M->data[11] -= op->data[11];
	M->data[12] -= op->data[12];
	M->data[13] -= op->data[13];
	M->data[14] -= op->data[14];
	M->data[15] -= op->data[15];
}

__la_inline__ void lam4_smul(lam4 *dest, lam4 *src, las k) {
	la_debug(dest && src);
	dest->data[0] = src->data[0] * k;
	dest->data[1] = src->data[1] * k; 
	dest->data[2] = src->data[2] * k; 
	dest->data[3] = src->data[3] * k; 
	dest->data[4] = src->data[4] * k; 
	dest->data[5] = src->data[5] * k; 
	dest->data[6] = src->data[6] * k; 
	dest->data[7] = src->data[7] * k; 
	dest->data[8] = src->data[8] * k;
	dest->data[9] = src->data[9] * k;
	dest->data[10] = src->data[10] * k;
	dest->data[11] = src->data[11] * k; 
	dest->data[12] = src->data[12] * k; 
	dest->data[13] = src->data[13] * k; 
	dest->data[14] = src->data[14] * k; 
	dest->data[15] = src->data[15] * k; 
}

__la_inline__ void lam4_ipsmul(lam4 *M, las k) {
	la_debug(M);
	M->data[0] *= k;
	M->data[1] *= k;
	M->data[2] *= k;
	M->data[3] *= k;
	M->data[4] *= k;
	M->data[5] *= k;
	M->data[6] *= k;
	M->data[7] *= k;
	M->data[8] *= k;
	M->data[9] *= k;
	M->data[10] *= k;
	M->data[11] *= k;
	M->data[12] *= k;
	M->data[13] *= k;
	M->data[14] *= k;
	M->data[15] *= k;
}

__la_inline__ void lam4_sdiv(lam4 *dest, lam4 *src, las k) {
	la_debug(dest && src && k!=0.);
#ifdef LAM4_FAST_DIV
	/* division is slow, multiply for 1./k instead */
	las invk = 1./k;
	lam4_smul(dest, src, invk);
#else
	dest->data[0] = src->data[0] / k;
	dest->data[1] = src->data[1] / k; 
	dest->data[2] = src->data[2] / k; 
	dest->data[3] = src->data[3] / k; 
	dest->data[4] = src->data[4] / k; 
	dest->data[5] = src->data[5] / k; 
	dest->data[6] = src->data[6] / k; 
	dest->data[7] = src->data[7] / k; 
	dest->data[8] = src->data[8] / k;
	dest->data[9] = src->data[9] / k;
	dest->data[10] = src->data[10] / k;
	dest->data[11] = src->data[11] / k; 
	dest->data[12] = src->data[12] / k; 
	dest->data[13] = src->data[13] / k; 
	dest->data[14] = src->data[14] / k; 
	dest->data[15] = src->data[15] / k; 
#endif
}

__la_inline__ void lam4_ipsdiv(lam4 *M, las k) {
	la_debug(M && k!=0.);
#ifdef LAM4_FAST_DIV
	/* division is slow, multiply for 1./k instead */
	lam4_ipsmul(M, 1./k);
#else
	M->data[0] /= k;
	M->data[1] /= k;
	M->data[2] /= k;
	M->data[3] /= k;
	M->data[4] /= k;
	M->data[5] /= k;
	M->data[6] /= k;
	M->data[7] /= k;
	M->data[8] /= k;
	M->data[9] /= k;
	M->data[10] /= k;
	M->data[11] /= k;
	M->data[12] /= k;
	M->data[13] /= k;
	M->data[14] /= k;
	M->data[15] /= k;
#endif
}

