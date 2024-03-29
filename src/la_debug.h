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

#ifndef la_debug_h
#define la_debug_h


#ifdef LA_DEBUG
#ifndef NDEBUG
#include <assert.h>
#else
#undef NDEBUG
#include <assert.h>
/* restore NDEBUG as it was */
#define NDEBUG
#endif

/* use a macro so that assert can output
 * the correct file/line of where it triggered */
#define la_debug(x) assert(x)  
#else /* !LA_DEBUG */
#define la_debug(x)
#endif

#endif /* la_debug_h */

