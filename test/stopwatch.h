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

#ifndef stopwatch_h
#define stopwatch_h

#include <sys/time.h>
#include <stdio.h>
#include <assert.h>

typedef struct stopwatch {
	struct timeval time;
} stopwatch;

inline void stopwatch_start(stopwatch* sw);
inline void stopwatch_stop(stopwatch* sw);
inline void stopwatch_print(stopwatch* sw);

void stopwatch_start(stopwatch* sw) {
	assert(sw);
	gettimeofday(&sw->time, NULL);
}

void stopwatch_stop(stopwatch* sw) {
	struct timeval stop_time;
	assert(sw);
	gettimeofday(&stop_time, NULL);
	timersub(&stop_time, &sw->time, &sw->time);
}

void stopwatch_print(stopwatch* sw) {
	assert(sw);

	printf("%u.", (unsigned int)sw->time.tv_sec);
	if (sw->time.tv_usec<10)
		printf("00000");
	else if (sw->time.tv_usec<100)
		printf("0000");
	else if (sw->time.tv_usec<1000)
		printf("000");
	else if (sw->time.tv_usec<10000)
		printf("00");
	else if (sw->time.tv_usec<100000)
		printf("0");
	printf("%u", (unsigned int)sw->time.tv_usec);
}

#endif /* stopwatch_h */

