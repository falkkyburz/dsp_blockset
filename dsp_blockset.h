/** @file dsp_blockset.h
 *
 * @author Falk Kyburz
 * @brief Floating point digital signal processing blockset (single header).
 *
 */

#ifndef DSP_BLOCKSET_H
#define DSP_BLOCKSET_H

/*==============================================================================
 INCLUDES
 =============================================================================*/
#include <stdint.h>
#include <stddef.h>
#include <math.h>

#include "dsp_blockset_port.h"

/*==============================================================================
 FLOAT MATH CONSTANTS
 =============================================================================*/

/** Float literal holding PI. */
#define DSPB_PI_F (3.14159265358f)
/** Float literal holding PI/2. */
#define DSPB_PI_2_F (1.57079632679f)
/** Float literal holding PI/4. */
#define DSPB_PI_4_F (0.78539816339f)
/** Float literal holding 2*PI. */
#define DSPB_2_PI_F (6.28318530718f)
/** Float literal holding 1/(2*PI). */
#define DSPB_2_PI_INV_F (0.15915494309f)
/** Float literal holding 2*PI/3. */
#define DSPB_2_PI_3_F (2.09439510239f)
/** Float literal holding 4*PI/3. */
#define DSPB_4_PI_3_F (4.18879020478f)
/** Float literal holding sqrt(2). */
#define DSPB_SQRT2_F (1.41421356237f)
/** Float literal holding 1/sqrt(2). */
#define DSPB_1_SQRT2_F (0.70710678118f)
/** Float literal holding absolute zero Kelvin in degrees. */
#define DSPB_ABS_ZERO_F (-273.15f)

/*==============================================================================
 MATH BLOCKS
 =============================================================================*/

/** Add function struct. */
typedef struct dspb_add_tag
{
    float32_t *pf32_in0;
    float32_t *pf32_in1;
    float32_t f32_out;
} dspb_add_t;

/**
 * @brief Add function macro.
 * @param s_data Block data struct.
 */
#define DSPB_ADD(s_data) \
    (s_data).f32_out = *(s_data).pf32_in0 + *(s_data).pf32_in1

/** Subtract function struct. */
typedef struct dspb_sub_tag
{
    float32_t *pf32_in0;
    float32_t *pf32_in1;
    float32_t f32_out;
} dspb_sub_t;

/**
 * @brief Subtraction function macro.
 * @param s_data Block data struct.
 */
#define DSPB_SUB(s_data) \
    (s_data).f32_out = *(s_data).pf32_in0 - *(s_data).pf32_in1

/** Product function struct. */
typedef struct dspb_prod_tag
{
    float32_t *pf32_in0;
    float32_t *pf32_in1;
    float32_t f32_out;
} dspb_prod_t;

/**
 * @brief Product function macro.
 * @param s_data Block data struct.
 */
#define DSPB_PROD(s_data) \
    (s_data).f32_out = *(s_data).pf32_in0 * (*(s_data).pf32_in1)

/** Division function struct. */
typedef struct dspb_div_tag
{
    float32_t f32_min;
    float32_t *pf32_in0;
    float32_t *pf32_in1;
    float32_t f32_out;
} dspb_div_t;

/**
 * @brief Division function macro.
 * @param s_data Block data struct.
 */
#define DSPB_DIV(s_data) \
    (s_data).f32_out =    \
        *(s_data).pf32_in0 / dspb_maxf((s_data).f32_min, *(s_data).pf32_in1)

/*==============================================================================
 DEFINES
 =============================================================================*/

/*==============================================================================
 PUBLIC FUNCTIONS
 =============================================================================*/

#endif /* DSPB_BLOCKSET_H */

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
