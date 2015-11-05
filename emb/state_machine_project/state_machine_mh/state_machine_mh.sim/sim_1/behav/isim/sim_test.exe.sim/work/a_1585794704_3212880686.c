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
static const char *ng0 = "/home/matthias/RobtekE15/EMB1/group3/emb/state_machine_mh/state_machine_mh.srcs/sources_1/imports/src/debounce.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1006216973935652998_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1585794704_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(40, ng0);

LAB3:    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 6176);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 2U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 6048);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1585794704_3212880686_p_1(char *t0)
{
    char t16[16];
    char t17[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    int t18;
    unsigned int t19;
    char *t20;

LAB0:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6064);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(45, ng0);
    t3 = (t0 + 1832U);
    t4 = *((char **)t3);
    t3 = (t0 + 2928U);
    t5 = *((char **)t3);
    t6 = 1;
    if (4U == 4U)
        goto LAB8;

LAB9:    t6 = 0;

LAB10:    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t1 = (t0 + 3048U);
    t4 = *((char **)t1);
    t2 = 1;
    if (4U == 4U)
        goto LAB16;

LAB17:    t2 = 0;

LAB18:    if (t2 != 0)
        goto LAB14;

LAB15:
LAB6:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t7 = (3 - 2);
    t14 = (t7 * 1U);
    t15 = (0 + t14);
    t1 = (t3 + t15);
    t4 = (t0 + 1352U);
    t5 = *((char **)t4);
    t2 = *((unsigned char *)t5);
    t8 = ((IEEE_P_2592010699) + 4000);
    t9 = (t17 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 2;
    t10 = (t9 + 4U);
    *((int *)t10) = 0;
    t10 = (t9 + 8U);
    *((int *)t10) = -1;
    t18 = (0 - 2);
    t19 = (t18 * -1);
    t19 = (t19 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t19;
    t4 = xsi_base_array_concat(t4, t16, t8, (char)97, t1, t17, (char)99, t2, (char)101);
    t19 = (3U + 1U);
    t6 = (4U != t19);
    if (t6 == 1)
        goto LAB22;

LAB23:    t10 = (t0 + 6304);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t20 = *((char **)t13);
    memcpy(t20, t4, 4U);
    xsi_driver_first_trans_fast(t10);
    goto LAB3;

LAB5:    xsi_set_current_line(46, ng0);
    t9 = (t0 + 6240);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t9);
    goto LAB6;

LAB8:    t7 = 0;

LAB11:    if (t7 < 4U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t3 = (t4 + t7);
    t8 = (t5 + t7);
    if (*((unsigned char *)t3) != *((unsigned char *)t8))
        goto LAB9;

LAB13:    t7 = (t7 + 1);
    goto LAB11;

LAB14:    xsi_set_current_line(48, ng0);
    t8 = (t0 + 6240);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast(t8);
    goto LAB6;

LAB16:    t7 = 0;

LAB19:    if (t7 < 4U)
        goto LAB20;
    else
        goto LAB18;

LAB20:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB17;

LAB21:    t7 = (t7 + 1);
    goto LAB19;

LAB22:    xsi_size_not_matching(4U, t19, 0);
    goto LAB23;

}

static void work_a_1585794704_3212880686_p_2(char *t0)
{
    char t12[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned int t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    int t18;

LAB0:    xsi_set_current_line(59, ng0);
    t1 = (t0 + 1152U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6080);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(60, ng0);
    t3 = (t0 + 3768U);
    t4 = *((char **)t3);
    t3 = (t0 + 2312U);
    t5 = *((char **)t3);
    t6 = 1;
    if (2U == 2U)
        goto LAB8;

LAB9:    t6 = 0;

LAB10:    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    xsi_set_current_line(63, ng0);
    t1 = (t0 + 3888U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 0);
    if (t2 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(71, ng0);
    t1 = (t0 + 3648U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 0);
    if (t2 != 0)
        goto LAB26;

LAB28:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 3648U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t18 = (t11 - 1);
    t1 = (t0 + 3648U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    *((int *)t1) = t18;

LAB27:
LAB15:    goto LAB3;

LAB5:    xsi_set_current_line(61, ng0);
    t9 = (t0 + 3888U);
    t10 = *((char **)t9);
    t9 = (t10 + 0);
    *((int *)t9) = 0;
    goto LAB6;

LAB8:    t7 = 0;

LAB11:    if (t7 < 2U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t3 = (t4 + t7);
    t8 = (t5 + t7);
    if (*((unsigned char *)t3) != *((unsigned char *)t8))
        goto LAB9;

LAB13:    t7 = (t7 + 1);
    goto LAB11;

LAB14:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 6368);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(65, ng0);
    t1 = (t0 + 3768U);
    t3 = *((char **)t1);
    t1 = (t0 + 2312U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB20;

LAB21:    t2 = 0;

LAB22:    if (t2 != 0)
        goto LAB17;

LAB19:
LAB18:    goto LAB15;

LAB17:    xsi_set_current_line(66, ng0);
    t8 = (t0 + 3768U);
    t9 = *((char **)t8);
    t8 = (t0 + 12000U);
    t10 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t12, t9, t8, 1);
    t13 = (t0 + 3768U);
    t14 = *((char **)t13);
    t13 = (t14 + 0);
    t15 = (t12 + 12U);
    t16 = *((unsigned int *)t15);
    t17 = (1U * t16);
    memcpy(t13, t10, t17);
    xsi_set_current_line(67, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t1 = (t0 + 3648U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    *((int *)t1) = t11;
    xsi_set_current_line(68, ng0);
    t1 = (t0 + 3888U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    *((int *)t1) = 1;
    goto LAB18;

LAB20:    t7 = 0;

LAB23:    if (t7 < 2U)
        goto LAB24;
    else
        goto LAB22;

LAB24:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB21;

LAB25:    t7 = (t7 + 1);
    goto LAB23;

LAB26:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 6368);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(73, ng0);
    t1 = (t0 + 3888U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    *((int *)t1) = 0;
    goto LAB27;

}

static void work_a_1585794704_3212880686_p_3(char *t0)
{
    char t12[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t13;
    unsigned int t14;
    unsigned char t15;

LAB0:    xsi_set_current_line(84, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6096);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(85, ng0);
    t3 = (t0 + 1672U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)1);
    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)0);
    if (t5 != 0)
        goto LAB11;

LAB12:    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB19;

LAB20:    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB27;

LAB28:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(86, ng0);
    t3 = (t0 + 3168U);
    t7 = *((char **)t3);
    t3 = (t0 + 6432);
    t8 = (t3 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t7, 2U);
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(87, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 6496);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(89, ng0);
    t1 = (t0 + 4008U);
    t3 = *((char **)t1);
    t1 = (t0 + 12032U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t12, t3, t1, 1);
    t7 = (t0 + 4008U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    t9 = (t12 + 12U);
    t13 = *((unsigned int *)t9);
    t14 = (1U * t13);
    memcpy(t7, t4, t14);
    xsi_set_current_line(90, ng0);
    t1 = (t0 + 4008U);
    t3 = *((char **)t1);
    t1 = (t0 + 6560);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(91, ng0);
    t1 = (t0 + 6624);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 500;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

LAB11:    xsi_set_current_line(94, ng0);
    t1 = (t0 + 2632U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t15 = (t6 == (unsigned char)3);
    if (t15 != 0)
        goto LAB13;

LAB15:
LAB14:    xsi_set_current_line(98, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB16;

LAB18:
LAB17:    goto LAB6;

LAB13:    xsi_set_current_line(95, ng0);
    t1 = (t0 + 3288U);
    t7 = *((char **)t1);
    t1 = (t0 + 6432);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t7, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(96, ng0);
    t1 = (t0 + 6496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB14;

LAB16:    xsi_set_current_line(99, ng0);
    t1 = (t0 + 3408U);
    t4 = *((char **)t1);
    t1 = (t0 + 6432);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(100, ng0);
    t1 = (t0 + 6496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(101, ng0);
    t1 = (t0 + 4008U);
    t3 = *((char **)t1);
    t1 = (t0 + 12032U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t12, t3, t1, 1);
    t7 = (t0 + 4008U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    t9 = (t12 + 12U);
    t13 = *((unsigned int *)t9);
    t14 = (1U * t13);
    memcpy(t7, t4, t14);
    xsi_set_current_line(102, ng0);
    t1 = (t0 + 4008U);
    t3 = *((char **)t1);
    t1 = (t0 + 6560);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(103, ng0);
    t1 = (t0 + 6624);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 127;
    xsi_driver_first_trans_fast(t1);
    goto LAB17;

LAB19:    xsi_set_current_line(106, ng0);
    t1 = (t0 + 3168U);
    t4 = *((char **)t1);
    t1 = (t0 + 6432);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(107, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB21;

LAB23:
LAB22:    xsi_set_current_line(110, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB24;

LAB26:
LAB25:    goto LAB6;

LAB21:    xsi_set_current_line(108, ng0);
    t1 = (t0 + 6496);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB22;

LAB24:    xsi_set_current_line(111, ng0);
    t1 = (t0 + 3528U);
    t4 = *((char **)t1);
    t1 = (t0 + 6432);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(112, ng0);
    t1 = (t0 + 6496);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB25;

LAB27:    xsi_set_current_line(115, ng0);
    t1 = (t0 + 3168U);
    t4 = *((char **)t1);
    t1 = (t0 + 6432);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t4, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB29;

LAB31:
LAB30:    goto LAB6;

LAB29:    xsi_set_current_line(117, ng0);
    t1 = (t0 + 6496);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(118, ng0);
    t1 = (t0 + 3168U);
    t3 = *((char **)t1);
    t1 = (t0 + 6432);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 2U);
    xsi_driver_first_trans_fast(t1);
    goto LAB30;

}


extern void work_a_1585794704_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1585794704_3212880686_p_0,(void *)work_a_1585794704_3212880686_p_1,(void *)work_a_1585794704_3212880686_p_2,(void *)work_a_1585794704_3212880686_p_3};
	xsi_register_didat("work_a_1585794704_3212880686", "isim/sim_test.exe.sim/work/a_1585794704_3212880686.didat");
	xsi_register_executes(pe);
}
