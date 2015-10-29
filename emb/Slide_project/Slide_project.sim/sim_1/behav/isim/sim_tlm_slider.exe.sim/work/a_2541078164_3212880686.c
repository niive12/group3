/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/matthias/RobtekE15/EMB1/Slide_project/Slide_project.srcs/sources_1/imports/sources_1/new/LED_driver.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1701011461141717515_1035706684(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_2541078164_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;

LAB0:    xsi_set_current_line(77, ng0);

LAB3:    t1 = (t0 + 5008U);
    t2 = *((char **)t1);
    t1 = (t0 + 7928);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 5U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:
LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2541078164_3212880686_p_1(char *t0)
{
    char t8[16];
    char t11[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    int t14;
    unsigned int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(78, ng0);

LAB3:    t1 = (t0 + 4768U);
    t2 = *((char **)t1);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t4 = (29 - 29);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t3 + t6);
    t9 = ((IEEE_P_2592010699) + 4000);
    t10 = (t0 + 15104U);
    t12 = (t11 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 29;
    t13 = (t12 + 4U);
    *((int *)t13) = 20;
    t13 = (t12 + 8U);
    *((int *)t13) = -1;
    t14 = (20 - 29);
    t15 = (t14 * -1);
    t15 = (t15 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t15;
    t7 = xsi_base_array_concat(t7, t8, t9, (char)97, t2, t10, (char)97, t1, t11, (char)101);
    t15 = (4U + 10U);
    t16 = (14U != t15);
    if (t16 == 1)
        goto LAB5;

LAB6:    t13 = (t0 + 7992);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t7, 14U);
    xsi_driver_first_trans_fast(t13);

LAB2:    t21 = (t0 + 7784);
    *((int *)t21) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(14U, t15, 0);
    goto LAB6;

}

static void work_a_2541078164_3212880686_p_2(char *t0)
{
    char t8[16];
    char t11[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    int t14;
    unsigned int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(79, ng0);

LAB3:    t1 = (t0 + 4768U);
    t2 = *((char **)t1);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t4 = (29 - 19);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t3 + t6);
    t9 = ((IEEE_P_2592010699) + 4000);
    t10 = (t0 + 15104U);
    t12 = (t11 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 19;
    t13 = (t12 + 4U);
    *((int *)t13) = 10;
    t13 = (t12 + 8U);
    *((int *)t13) = -1;
    t14 = (10 - 19);
    t15 = (t14 * -1);
    t15 = (t15 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t15;
    t7 = xsi_base_array_concat(t7, t8, t9, (char)97, t2, t10, (char)97, t1, t11, (char)101);
    t15 = (4U + 10U);
    t16 = (14U != t15);
    if (t16 == 1)
        goto LAB5;

LAB6:    t13 = (t0 + 8056);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t7, 14U);
    xsi_driver_first_trans_fast(t13);

LAB2:    t21 = (t0 + 7800);
    *((int *)t21) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(14U, t15, 0);
    goto LAB6;

}

static void work_a_2541078164_3212880686_p_3(char *t0)
{
    char t8[16];
    char t11[16];
    char *t1;
    char *t2;
    char *t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    int t14;
    unsigned int t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(80, ng0);

LAB3:    t1 = (t0 + 4768U);
    t2 = *((char **)t1);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t4 = (29 - 9);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t3 + t6);
    t9 = ((IEEE_P_2592010699) + 4000);
    t10 = (t0 + 15104U);
    t12 = (t11 + 0U);
    t13 = (t12 + 0U);
    *((int *)t13) = 9;
    t13 = (t12 + 4U);
    *((int *)t13) = 0;
    t13 = (t12 + 8U);
    *((int *)t13) = -1;
    t14 = (0 - 9);
    t15 = (t14 * -1);
    t15 = (t15 + 1);
    t13 = (t12 + 12U);
    *((unsigned int *)t13) = t15;
    t7 = xsi_base_array_concat(t7, t8, t9, (char)97, t2, t10, (char)97, t1, t11, (char)101);
    t15 = (4U + 10U);
    t16 = (14U != t15);
    if (t16 == 1)
        goto LAB5;

LAB6:    t13 = (t0 + 8120);
    t17 = (t13 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t7, 14U);
    xsi_driver_first_trans_fast(t13);

LAB2:    t21 = (t0 + 7816);
    *((int *)t21) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(14U, t15, 0);
    goto LAB6;

}

static void work_a_2541078164_3212880686_p_4(char *t0)
{
    char t11[16];
    char t20[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t12;
    char *t13;
    int t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t21;
    char *t22;
    char *t23;
    char *t24;
    static char *nl0[] = {&&LAB6, &&LAB10, &&LAB7, &&LAB8, &&LAB9};

LAB0:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 2432U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 7832);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(88, ng0);
    t3 = (t0 + 2632U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t3 = (char *)((nl0) + t5);
    goto **((char **)t3);

LAB5:    goto LAB3;

LAB6:    xsi_set_current_line(91, ng0);
    t6 = (t0 + 8184);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(92, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB12;

LAB14:
LAB13:    xsi_set_current_line(97, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB15;

LAB17:
LAB16:    goto LAB5;

LAB7:    xsi_set_current_line(110, ng0);
    t1 = (t0 + 8184);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(111, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB21;

LAB23:
LAB22:    xsi_set_current_line(116, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB24;

LAB26:
LAB25:    goto LAB5;

LAB8:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 8184);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(125, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB27;

LAB29:
LAB28:    xsi_set_current_line(130, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB30;

LAB32:
LAB31:    goto LAB5;

LAB9:    xsi_set_current_line(138, ng0);
    t1 = (t0 + 8184);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(139, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB33;

LAB35:
LAB34:    xsi_set_current_line(144, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB36;

LAB38:
LAB37:    goto LAB5;

LAB10:    xsi_set_current_line(152, ng0);
    t1 = (t0 + 8184);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(153, ng0);
    t1 = (t0 + 5128U);
    t3 = *((char **)t1);
    t14 = *((int *)t3);
    t1 = (t0 + 4528U);
    t4 = *((char **)t1);
    t15 = *((int *)t4);
    t16 = (t15 - 1);
    t2 = (t14 == t16);
    if (t2 != 0)
        goto LAB39;

LAB41:    xsi_set_current_line(175, ng0);
    t1 = (t0 + 5128U);
    t3 = *((char **)t1);
    t14 = *((int *)t3);
    t15 = (t14 + 1);
    t1 = (t0 + 5128U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    *((int *)t1) = t15;
    xsi_set_current_line(176, ng0);
    t1 = (t0 + 8504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB40:    goto LAB5;

LAB11:    xsi_set_current_line(180, ng0);
    t1 = (t0 + 8504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB5;

LAB12:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 8184);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(94, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(95, ng0);
    t1 = (t0 + 8312);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB13;

LAB15:    xsi_set_current_line(98, ng0);
    t1 = (t0 + 8312);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(99, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(100, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 5248U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    memcpy(t1, t3, 10U);
    xsi_set_current_line(101, ng0);
    t1 = xsi_get_transient_memory(14U);
    memset(t1, 0, 14U);
    t3 = t1;
    memset(t3, (unsigned char)2, 14U);
    t4 = (t0 + 8376);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 14U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(102, ng0);
    t1 = xsi_get_transient_memory(14U);
    memset(t1, 0, 14U);
    t3 = t1;
    memset(t3, (unsigned char)2, 14U);
    t4 = (t0 + 8440);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 14U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(103, ng0);
    t1 = (t0 + 5248U);
    t3 = *((char **)t1);
    t1 = (t0 + 4888U);
    t4 = *((char **)t1);
    t1 = ((IEEE_P_2592010699) + 4000);
    t2 = xsi_vhdl_greater(t1, t3, 10U, t4, 10U);
    if (t2 != 0)
        goto LAB18;

LAB20:
LAB19:    goto LAB16;

LAB18:    xsi_set_current_line(104, ng0);
    t6 = (t0 + 8504);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(105, ng0);
    t1 = xsi_get_transient_memory(14U);
    memset(t1, 0, 14U);
    t3 = t1;
    memset(t3, (unsigned char)2, 14U);
    t4 = (t0 + 8568);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 14U);
    xsi_driver_first_trans_fast(t4);
    goto LAB19;

LAB21:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 8184);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(113, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(114, ng0);
    t1 = (t0 + 8312);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB22;

LAB24:    xsi_set_current_line(117, ng0);
    t1 = (t0 + 8312);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(118, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(119, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t1 = (t0 + 15056U);
    t4 = (t0 + 1832U);
    t6 = *((char **)t4);
    t4 = (t0 + 15024U);
    t7 = ieee_p_1242562249_sub_1701011461141717515_1035706684(IEEE_P_1242562249, t11, t3, t1, t6, t4);
    t8 = (t0 + 8568);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t7, 14U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(120, ng0);
    t1 = (t0 + 8504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB25;

LAB27:    xsi_set_current_line(126, ng0);
    t1 = (t0 + 8184);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(127, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(128, ng0);
    t1 = (t0 + 8632);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB28;

LAB30:    xsi_set_current_line(131, ng0);
    t1 = (t0 + 8632);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(132, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(133, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t1 = (t0 + 15088U);
    t4 = (t0 + 1832U);
    t6 = *((char **)t4);
    t4 = (t0 + 15024U);
    t7 = ieee_p_1242562249_sub_1701011461141717515_1035706684(IEEE_P_1242562249, t11, t3, t1, t6, t4);
    t8 = (t0 + 8376);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t7, 14U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(134, ng0);
    t1 = (t0 + 8504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB31;

LAB33:    xsi_set_current_line(140, ng0);
    t1 = (t0 + 8184);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(141, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(142, ng0);
    t1 = (t0 + 8696);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB34;

LAB36:    xsi_set_current_line(145, ng0);
    t1 = (t0 + 8696);
    t4 = (t1 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(146, ng0);
    t1 = (t0 + 8248);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(147, ng0);
    t1 = (t0 + 3592U);
    t3 = *((char **)t1);
    t1 = (t0 + 15072U);
    t4 = (t0 + 1832U);
    t6 = *((char **)t4);
    t4 = (t0 + 15024U);
    t7 = ieee_p_1242562249_sub_1701011461141717515_1035706684(IEEE_P_1242562249, t11, t3, t1, t6, t4);
    t8 = (t0 + 8440);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t12 = (t10 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t7, 14U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(148, ng0);
    t1 = (t0 + 8504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB37;

LAB39:    xsi_set_current_line(154, ng0);
    t1 = (t0 + 5128U);
    t6 = *((char **)t1);
    t1 = (t6 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(155, ng0);
    t1 = (t0 + 4768U);
    t3 = *((char **)t1);
    t1 = (t0 + 3432U);
    t4 = *((char **)t1);
    t1 = (t0 + 4648U);
    t6 = *((char **)t1);
    t14 = *((int *)t6);
    t17 = (13 - t14);
    t18 = (t17 * 1U);
    t19 = (0 + t18);
    t1 = (t4 + t19);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t0 + 15104U);
    t10 = (t20 + 0U);
    t12 = (t10 + 0U);
    *((int *)t12) = 13;
    t12 = (t10 + 4U);
    *((int *)t12) = 4;
    t12 = (t10 + 8U);
    *((int *)t12) = -1;
    t15 = (4 - 13);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t12 = (t10 + 12U);
    *((unsigned int *)t12) = t21;
    t7 = xsi_base_array_concat(t7, t11, t8, (char)97, t3, t9, (char)97, t1, t20, (char)101);
    t21 = (4U + 10U);
    t2 = (14U != t21);
    if (t2 == 1)
        goto LAB42;

LAB43:    t12 = (t0 + 8568);
    t13 = (t12 + 56U);
    t22 = *((char **)t13);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t7, 14U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(156, ng0);
    t1 = (t0 + 4768U);
    t3 = *((char **)t1);
    t1 = (t0 + 3752U);
    t4 = *((char **)t1);
    t1 = (t0 + 4648U);
    t6 = *((char **)t1);
    t14 = *((int *)t6);
    t17 = (13 - t14);
    t18 = (t17 * 1U);
    t19 = (0 + t18);
    t1 = (t4 + t19);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t0 + 15104U);
    t10 = (t20 + 0U);
    t12 = (t10 + 0U);
    *((int *)t12) = 13;
    t12 = (t10 + 4U);
    *((int *)t12) = 4;
    t12 = (t10 + 8U);
    *((int *)t12) = -1;
    t15 = (4 - 13);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t12 = (t10 + 12U);
    *((unsigned int *)t12) = t21;
    t7 = xsi_base_array_concat(t7, t11, t8, (char)97, t3, t9, (char)97, t1, t20, (char)101);
    t21 = (4U + 10U);
    t2 = (14U != t21);
    if (t2 == 1)
        goto LAB44;

LAB45:    t12 = (t0 + 8376);
    t13 = (t12 + 56U);
    t22 = *((char **)t13);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t7, 14U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(157, ng0);
    t1 = (t0 + 4768U);
    t3 = *((char **)t1);
    t1 = (t0 + 3592U);
    t4 = *((char **)t1);
    t1 = (t0 + 4648U);
    t6 = *((char **)t1);
    t14 = *((int *)t6);
    t17 = (13 - t14);
    t18 = (t17 * 1U);
    t19 = (0 + t18);
    t1 = (t4 + t19);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t0 + 15104U);
    t10 = (t20 + 0U);
    t12 = (t10 + 0U);
    *((int *)t12) = 13;
    t12 = (t10 + 4U);
    *((int *)t12) = 4;
    t12 = (t10 + 8U);
    *((int *)t12) = -1;
    t15 = (4 - 13);
    t21 = (t15 * -1);
    t21 = (t21 + 1);
    t12 = (t10 + 12U);
    *((unsigned int *)t12) = t21;
    t7 = xsi_base_array_concat(t7, t11, t8, (char)97, t3, t9, (char)97, t1, t20, (char)101);
    t21 = (4U + 10U);
    t2 = (14U != t21);
    if (t2 == 1)
        goto LAB46;

LAB47:    t12 = (t0 + 8440);
    t13 = (t12 + 56U);
    t22 = *((char **)t13);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t7, 14U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(158, ng0);
    t1 = (t0 + 3432U);
    t3 = *((char **)t1);
    t1 = (t0 + 3912U);
    t4 = *((char **)t1);
    t1 = ((IEEE_P_2592010699) + 4000);
    t2 = xsi_vhdl_greater(t1, t3, 14U, t4, 14U);
    if (t2 != 0)
        goto LAB48;

LAB50:    xsi_set_current_line(161, ng0);
    t1 = (t0 + 8760);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB49:    xsi_set_current_line(163, ng0);
    t1 = (t0 + 3752U);
    t3 = *((char **)t1);
    t1 = (t0 + 4072U);
    t4 = *((char **)t1);
    t1 = ((IEEE_P_2592010699) + 4000);
    t2 = xsi_vhdl_greater(t1, t3, 14U, t4, 14U);
    if (t2 != 0)
        goto LAB51;

LAB53:    xsi_set_current_line(166, ng0);
    t1 = (t0 + 8824);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB52:    xsi_set_current_line(168, ng0);
    t1 = (t0 + 3592U);
    t3 = *((char **)t1);
    t1 = (t0 + 4232U);
    t4 = *((char **)t1);
    t1 = ((IEEE_P_2592010699) + 4000);
    t2 = xsi_vhdl_greater(t1, t3, 14U, t4, 14U);
    if (t2 != 0)
        goto LAB54;

LAB56:    xsi_set_current_line(171, ng0);
    t1 = (t0 + 8888);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB55:    xsi_set_current_line(173, ng0);
    t1 = (t0 + 8504);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB40;

LAB42:    xsi_size_not_matching(14U, t21, 0);
    goto LAB43;

LAB44:    xsi_size_not_matching(14U, t21, 0);
    goto LAB45;

LAB46:    xsi_size_not_matching(14U, t21, 0);
    goto LAB47;

LAB48:    xsi_set_current_line(159, ng0);
    t6 = (t0 + 8760);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t6);
    goto LAB49;

LAB51:    xsi_set_current_line(164, ng0);
    t6 = (t0 + 8824);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t6);
    goto LAB52;

LAB54:    xsi_set_current_line(169, ng0);
    t6 = (t0 + 8888);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t6);
    goto LAB55;

}

static void work_a_2541078164_3212880686_p_5(char *t0)
{
    char t6[16];
    char t11[16];
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    unsigned char t5;
    char *t7;
    char *t8;
    char *t9;
    unsigned char t10;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(186, ng0);

LAB3:    t1 = (t0 + 2952U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3272U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t7 = ((IEEE_P_2592010699) + 4000);
    t1 = xsi_base_array_concat(t1, t6, t7, (char)99, t3, (char)99, t5, (char)101);
    t8 = (t0 + 3112U);
    t9 = *((char **)t8);
    t10 = *((unsigned char *)t9);
    t12 = ((IEEE_P_2592010699) + 4000);
    t8 = xsi_base_array_concat(t8, t11, t12, (char)97, t1, t6, (char)99, t10, (char)101);
    t13 = (1U + 1U);
    t14 = (t13 + 1U);
    t15 = (3U != t14);
    if (t15 == 1)
        goto LAB5;

LAB6:    t16 = (t0 + 8952);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t8, 3U);
    xsi_driver_first_trans_fast_port(t16);

LAB2:    t21 = (t0 + 7848);
    *((int *)t21) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(3U, t14, 0);
    goto LAB6;

}


extern void work_a_2541078164_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2541078164_3212880686_p_0,(void *)work_a_2541078164_3212880686_p_1,(void *)work_a_2541078164_3212880686_p_2,(void *)work_a_2541078164_3212880686_p_3,(void *)work_a_2541078164_3212880686_p_4,(void *)work_a_2541078164_3212880686_p_5};
	xsi_register_didat("work_a_2541078164_3212880686", "isim/sim_tlm_slider.exe.sim/work/a_2541078164_3212880686.didat");
	xsi_register_executes(pe);
}
