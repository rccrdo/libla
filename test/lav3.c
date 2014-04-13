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

/* 
 * This file won't build because of missing defines.
 * It is used by the libla-test script. To run a test use the test script !
 */

#include "la.h"
#include "stopwatch.h"


static void test_reset_vectors(lav3 *V, lav3 *U) {
	las xx = 1.456;
	las xy = 0.123;
	las xz = 1.0;
	las yx = 48948949489.;
	las yy = 0.416516;
	las yz = 0.;
	if (V != NULL)
		lav3_set(V, xx, xy, xz);
	if (U != NULL)
		lav3_set(U, yx, yy, yz);
}


static void print_las(las v) {
#ifdef LA_SCALAR_FLOAT
	printf("%f", v);
#elif defined(LA_SCALAR_DOUBLE)
	printf("%f", v);
#elif defined(LA_SCALAR_LONGDOUBLE)
	printf("%Lf", v);
#endif
}

static void print_lav3_tuple(lav3 *V) {
#ifdef LA_SCALAR_FLOAT
	printf("(%f,%f,%f)", V->x, V->y, V->z);
#elif defined(LA_SCALAR_DOUBLE)
	printf("(%f,%f,%f)", V->x, V->y, V->z);
#elif defined(LA_SCALAR_LONGDOUBLE)
	printf("(%Lf,%Lf,%Lf)", V->x, V->y, V->z);
#endif
}

static void test_lav3_dot(unsigned int count) {
	lav3 V1;
	lav3 V2;
	las dot_res;
	int i;
	stopwatch watch;
	dot_res = 0.;
	printf("    {'id' : 'lav3_dot',\n");
	test_reset_vectors(&V1, &V2);
	printf("     'count' : %d,\n", count); 
	printf("     'V1' : "); print_lav3_tuple(&V1); printf(",\n");
	printf("     'V2' : "); print_lav3_tuple(&V2); printf(",\n");
	stopwatch_start(&watch);
	for (i=0; i<count; i++)
		dot_res += lav3_dot(&V1,&V2);
	stopwatch_stop(&watch);
	printf("     'result_dot' : "); print_las(dot_res); printf(",\n");
	printf("     'time' : "); stopwatch_print(&watch); printf("\n    },\n");
}

static void test_lav3_ipsmul(unsigned int count) {
	lav3 V;
	las k;
	int i;
	stopwatch watch;
	test_reset_vectors(&V, NULL);
	k = 0.999999;
	printf("    {'id' : 'lav3_ipsmul',\n");
	printf("     'count' : %d,\n", count); 
	printf("     'V' : "); print_lav3_tuple(&V); printf(",\n");
	printf("     'k' : "); print_las(k); printf(",\n");
	stopwatch_start(&watch);
	for (i=0; i<count; i++)
		lav3_ipsmul(&V, k);
	stopwatch_stop(&watch);
	printf("     'result_V' : "); print_lav3_tuple(&V); printf(",\n");
	printf("     'time' : "); stopwatch_print(&watch); printf("\n    },\n");
}

static void test_lav3_normalize(unsigned int count) {
	lav3 V;
	las k;
	int i;
	stopwatch watch;
	test_reset_vectors(&V, NULL);
	printf("    {'id' : 'lav3_normalize',\n");
	printf("     'count' : %d,\n", count); 
	printf("     'V' : "); print_lav3_tuple(&V); printf(",\n");
	stopwatch_start(&watch);
	for (i=0; i<count; i++)
		lav3_normalize(&V);
	stopwatch_stop(&watch);
	printf("     'result_V' "); print_lav3_tuple(&V); printf(",\n");
	printf("     'time' : "); stopwatch_print(&watch); printf("\n    },\n");
}

int main() {
	unsigned int count;
	printf("{'test': 'lav3',\n");
	printf(" 'sizeof(lav3)': %lu,\n", sizeof(lav3));
	printf(" 'list' : [\n");

	if (TEST_LAV3_DOT)
		test_lav3_dot(TEST_LAV3_DOT);

	if (TEST_LAV3_IPSMUL)
		test_lav3_ipsmul(TEST_LAV3_IPSMUL);

	if (TEST_LAV3_NORMALIZE)
		test_lav3_normalize(TEST_LAV3_NORMALIZE);

	printf(" ]\n}\n");
	return 0;
}
