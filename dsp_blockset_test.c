/** @file dsp_blockset_test.c
 *
 * @author Falk Kyburz
 * @brief Tests for dsp block set.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "utest.h"

#include "dsp_blockset.h"

/*==============================================================================
 HELPER FUNCTIONS
 =============================================================================*/

/*==============================================================================
 TEST FUNCTIONS
 =============================================================================*/

UTEST(dspb, add)
{
    float32_t f32_in0 = 0.0f;
    float32_t f32_in1 = 1.0f;
    float32_t f32_in2 = 2.0f;
    dspb_add_t add0 = {.pf32_in0 = &f32_in0, .pf32_in1 = &f32_in1, .f32_out = 0.0f};
    dspb_add_t add1 = {.pf32_in0 = &f32_in2, .pf32_in1 = &add0.f32_out, .f32_out = 0.0f};
    DSPB_ADD(add0);
    DSPB_ADD(add1);
    EXPECT_EQ(add0.f32_out, 1.0f);
    EXPECT_EQ(add1.f32_out, 3.0f);
}

UTEST(dspb, sub)
{
    float32_t f32_in0 = 0.0f;
    float32_t f32_in1 = 1.0f;
    float32_t f32_in2 = 2.0f;
    dspb_sub_t sub0 = {.pf32_in0 = &f32_in0, .pf32_in1 = &f32_in1, .f32_out = 0.0f};
    dspb_sub_t sub1 = {.pf32_in0 = &f32_in2, .pf32_in1 = &sub0.f32_out, .f32_out = 0.0f};
    DSPB_SUB(sub0);
    DSPB_SUB(sub1);
    EXPECT_EQ(sub0.f32_out, -1.0f);
    EXPECT_EQ(sub1.f32_out, 3.0f);
}

UTEST(dspb, prod)
{
    float32_t f32_in0 = 0.5f;
    float32_t f32_in1 = 1.0f;
    float32_t f32_in2 = 2.0f;
    dspb_prod_t prod0 = {.pf32_in0 = &f32_in0, .pf32_in1 = &f32_in1, .f32_out = 0.0f};
    dspb_prod_t prod1 = {.pf32_in0 = &f32_in2, .pf32_in1 = &prod0.f32_out, .f32_out = 0.0f};
    DSPB_PROD(prod0);
    DSPB_PROD(prod1);
    EXPECT_EQ(prod0.f32_out, 0.5f);
    EXPECT_EQ(prod1.f32_out, 1.0f);
}

UTEST(dspb, div)
{
    float32_t f32_in0 = 1.0f;
    float32_t f32_in1 = 0.0f;
    float32_t f32_in2 = 2.0f;
    dspb_div_t div0 = {.f32_min = 0.5f, .pf32_in0 = &f32_in0, .pf32_in1 = &f32_in1, .f32_out = 0.0f};
    dspb_div_t div1 = {.f32_min = 0.5f, .pf32_in0 = &f32_in2, .pf32_in1 = &div0.f32_out, .f32_out = 0.0f};
    DSPB_DIV(div0);
    DSPB_DIV(div1);
    EXPECT_EQ(div0.f32_out, 2.0f);
    EXPECT_EQ(div1.f32_out, 1.0f);
}

/*==============================================================================
 TEST MAIN
 =============================================================================*/

UTEST_MAIN();
