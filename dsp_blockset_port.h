/** @file dspb_blockset_port.h
 *
 * @author Falk Kyburz
 * @brief Digital signal processing block set portability layer. Modify to
 * maximize performance on target architecture.
 *
 */

#ifndef DSP_BLOCKSET_PORT_H
#define DSP_BLOCKSET_PORT_H

/*==============================================================================
 INCLUDES
 =============================================================================*/
#include <stdint.h>
#include <math.h>

/*==============================================================================
 TYPES
 =============================================================================*/
/** Standard 32 bit float type */
typedef float float32_t;

/*==============================================================================
 DEFINES
 =============================================================================*/

/* Floating point functions with intrinsics on MCU. */
#if defined(_WIN32) || defined(_WIN64)

/** Floating point minimum function macro */
#define dspb_minf(x, y) fminf((x), (y))
/** Floating point maximum function macro */
#define dspb_maxf(x, y) fmaxf((x), (y))
/** Floating point maximum function macro */
#define dspb_absf(x) fabsf((x))
/** Floating point division */
#define dspb_divf(x, y) ((x) / (y))
/** Sine function macro */
#define dspb_sinf(x) sinf((x))
/** Sine function macro PU */
#define dspb_sinpuf(x) sinf((x) * 0.15915494309f)
/** Cosine function macro */
#define dspb_cosf(x) cosf((x))
/** Cosine function macro PU */
#define dspb_cospuf(x) cosf((x) * 0.15915494309f)
/** Square root function */
#define dspb_sqrtf(x) sqrtf((x))
/* Specific intrinsics for C28x */
#elif defined(__TMS320C2000__)
#define dspb_minf(x, y) __fmin((x), (y))
#define dspb_maxf(x, y) __fmax((x), (y))
#define dspb_absf(x, y) fabsf((x), (y))
#define dspb_divf(x, y) __divf32((x), (y))
#define dspb_sinf(x) __sin((x))
#define dspb_sinpuf(x) __sinpuf32((x))
#define dspb_cosf(x) __cos((x))
#define dspb_cospuf(x) __cospuf32((x))
#define dspb_sqrtf(x) __sqrt((x))
#elif defined(__TMS320C28XX_CLA__)
/* Specific intrinsics for CLA */

#elif defined(__arm__)
/* Specific intrinsics for ARM */

#endif

#endif /* DSP_BLOCKSET_PORT_H */

/*
 * @copyright
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <https://unlicense.org>
 */
