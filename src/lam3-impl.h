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

__la_inline__ void lam3_set(lam3 *M, las m00, las m01, las m02,
			    las m10, las m11, las m12,
			    las m20, las m21, las m22) {
	la_debug(M);
	M->data[0] = m00;
	M->data[1] = m01;
	M->data[2] = m02;
	M->data[3] = m10;
	M->data[4] = m11;
	M->data[5] = m12;
	M->data[6] = m20;
	M->data[7] = m21;
	M->data[8] = m22;
}                              

__la_inline__ void lam3_set_identity(lam3 *M) {
	lam3_set(M, 1., 0., 0.,
		 0., 1., 0.,
		 0., 0., 1.);
}

__la_inline__ void lam3_copy(lam3 *dest, const lam3 *src) {
	la_debug(dest && src);
	memcpy(dest->data, src->data, sizeof(lam3));
}

__la_inline__ las lam3_get_at(lam3 *M, int row, int col) {
	la_debug(M && (row>=0) && (row<=2) && (col>=0) && (col<=2));
	return M->data[row*3 + col];
}

__la_inline__ void lam3_set_at(lam3 *M, int row, int col, las k) {
	la_debug(M && (row>=0) && (row<=2) && (col>=0) && (col<=2));
	M->data[row*3 + col] = k;
}

__la_inline__ void lam3_add(lam3 *dest, const lam3 *src, const lam3 *op) {
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
}

__la_inline__ void lam3_ipadd(lam3 *M, const lam3 *op) {
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
}

__la_inline__ void lam3_sub(lam3 *dest, const lam3 *src, const lam3 *op) {
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
}

__la_inline__ void lam3_ipsub(lam3 *M, const lam3 *op) {
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
}

__la_inline__ void lam3_smul(lam3 *dest, const lam3 *src, las k) {
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
}

__la_inline__ void lam3_ipsmul(lam3 *M, las k) {
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
}

__la_inline__ void lam3_rmul_m3(lam3 *dest, const lam3 *src, const lam3 *op) {
	la_debug(dest && src && op);
	M3_00(dest) = M3_00(src)*M3_00(op) +
                M3_01(src)*M3_10(op) +
                M3_02(src)*M3_20(op);
	M3_01(dest) = M3_00(src)*M3_01(op) +
                M3_01(src)*M3_11(op) +
                M3_02(src)*M3_21(op);
	M3_02(dest) = M3_00(src)*M3_02(op) +
                M3_01(src)*M3_12(op) +
                M3_02(src)*M3_22(op);

	M3_10(dest) = M3_10(src)*M3_00(op) +
                M3_11(src)*M3_10(op) +
                M3_12(src)*M3_20(op);
	M3_11(dest) = M3_10(src)*M3_01(op) +
                M3_11(src)*M3_11(op) +
                M3_12(src)*M3_21(op);
	M3_12(dest) = M3_10(src)*M3_02(op) +
                M3_11(src)*M3_12(op) +
                M3_12(src)*M3_22(op);

	M3_20(dest) = M3_20(src)*M3_00(op) +
                M3_21(src)*M3_10(op) +
                M3_22(src)*M3_20(op);
	M3_21(dest) = M3_20(src)*M3_01(op) +
                M3_21(src)*M3_11(op) +
                M3_22(src)*M3_21(op);
	M3_22(dest) = M3_20(src)*M3_02(op) +
                M3_21(src)*M3_12(op) +
                M3_22(src)*M3_22(op);
}

__la_inline__ void lam3_rmul_v3(lav3 *dest, const lam3 *M, const lav3 *src) {
	la_debug(dest && M && src);
	dest->x = M3_00(M)*src->x +
		M3_01(M)*src->y +
		M3_02(M)*src->z;

	dest->y = M3_10(M)*src->x +
		M3_11(M)*src->y +
		M3_12(M)*src->z;

	dest->z = M3_20(M)*src->x +
		M3_21(M)*src->y +
		M3_22(M)*src->z;
}

__la_inline__ void lam3_lmul_v3(lav3 *dest, const lav3 *src, const lam3 *M) {
	la_debug(dest && src && M);

	dest->x = src->x*M->data[0] +
		src->y*M->data[3] +
		src->z*M->data[6];

	dest->y = src->x*M->data[1] +
		src->y*M->data[4] +
		src->z*M->data[7];

	dest->y = src->x*M->data[2] +
		src->y*M->data[5] +
		src->z*M->data[8];
}

__la_inline__ void lam3_div(lam3 *dest, const lam3 *src, las k) {
	la_debug(dest && src && k!=0.);
#ifdef LAM3_FAST_DIV
	/* division is slow, multiply for 1./k instead */
	las invk = 1./k;
	lam3_smul(dest, src, invk);
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
#endif
}

__la_inline__ void lam3_ipdiv(lam3 *M, las k) {
	la_debug(M && k!=0.);
#ifdef LAM3_FAST_DIV
	/* division is slow, multiply for 1./k instead */
	lam3_ipsmul(M, 1./k);
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
#endif
}

__la_inline__ las lam3_det(const lam3 *M) {
	la_debug(M);
	las det = M3_00(M)*(M3_11(M)*M3_22(M) - M3_12(M)*M3_21(M)) +
		M3_01(M)*(M3_12(M)*M3_20(M) - M3_10(M)*M3_22(M)) +
		M3_02(M)*(M3_10(M)*M3_21(M) - M3_11(M)*M3_20(M));
	return det;
}

__la_inline__ void lam3_get_inverse(lam3 *dest, const lam3* src) {
	las det;
	las inv_det;
	la_debug(dest && src);

	det = lam3_det(src);
	la_debug(det);

	inv_det = 1./det;
	dest->data[0] = inv_det*(src->data[4]*src->data[8] - src->data[5]*src->data[7]);
	dest->data[1] = inv_det*(src->data[2]*src->data[7] - src->data[1]*src->data[8]);
	dest->data[2] = inv_det*(src->data[1]*src->data[5] - src->data[2]*src->data[4]);
	dest->data[3] = inv_det*(src->data[5]*src->data[6] - src->data[3]*src->data[8]);
	dest->data[4] = inv_det*(src->data[0]*src->data[8] - src->data[2]*src->data[6]);
	dest->data[5] = inv_det*(src->data[2]*src->data[3] - src->data[0]*src->data[5]);
	dest->data[6] = inv_det*(src->data[3]*src->data[7] - src->data[4]*src->data[6]);
	dest->data[7] = inv_det*(src->data[1]*src->data[6] - src->data[0]*src->data[7]);
	dest->data[8] = inv_det*(src->data[0]*src->data[4] - src->data[1]*src->data[3]);
}

__la_inline__ void lam3_invert(lam3 *M) {
	las det;
	las inv_det;
	las k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
	las k11, k12, k13, k14, k15, k16, k17, k18;
	la_debug(M);

	det = lam3_det(M);
	la_debug(det);
	inv_det = 1./det;

	k1 = M->data[4]*M->data[8];
	k2 = -M->data[5]*M->data[7];
	k3 = M->data[2]*M->data[7];
	k4 = -M->data[1]*M->data[8];
	k5 = M->data[1]*M->data[5];
	k6 = -M->data[2]*M->data[4];
	k7 = M->data[5]*M->data[6];
	k8 = -M->data[3]*M->data[8];
	k9 = M->data[0]*M->data[8];
	k10 = -M->data[2]*M->data[6];
	k11 = M->data[2]*M->data[3];
	k12 = -M->data[0]*M->data[5];
	k13 = M->data[3]*M->data[7];
	k14 = -M->data[4]*M->data[6];
	k15 = M->data[1]*M->data[6];
	k16 = -M->data[0]*M->data[7];
	k17 = M->data[0]*M->data[4];
	k18 = -M->data[1]*M->data[3];

	M->data[0] = inv_det*(k1 + k2);
	M->data[1] = inv_det*(k3 + k4);
	M->data[2] = inv_det*(k5 + k6);
	M->data[3] = inv_det*(k7 + k8);
	M->data[4] = inv_det*(k9 + k10);
	M->data[5] = inv_det*(k11 + k12);
	M->data[6] = inv_det*(k13 + k14);
	M->data[7] = inv_det*(k15 + k16);
	M->data[8] = inv_det*(k17 + k18);
}

__la_inline__ void lam3_get_transpose(lam3 *dest, const lam3* src) {
	la_debug(dest && src);
	dest->data[0] = src->data[0];
	dest->data[1] = src->data[3];
	dest->data[2] = src->data[6];
	dest->data[3] = src->data[1];
	dest->data[4] = src->data[4];
	dest->data[5] = src->data[7];
	dest->data[6] = src->data[2];
	dest->data[7] = src->data[5];
	dest->data[8] = src->data[8];
}

__la_inline__ void lam3_transpose(lam3 *M) {
	las temp;
	la_debug(M);

	temp = M3_01(M);
	M3_01(M) = M3_10(M);
	M3_10(M) = temp;

	temp = M3_02(M);
	M3_02(M) = M3_20(M);
	M3_20(M) = temp;

	temp = M3_12(M);
	M3_12(M) = M3_21(M);
	M3_21(M) = temp;
}

