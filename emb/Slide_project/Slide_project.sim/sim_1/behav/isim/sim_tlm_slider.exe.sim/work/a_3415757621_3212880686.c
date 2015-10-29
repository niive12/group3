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
static const char *ng0 = "/home/matthias/RobtekE15/EMB1/Slide_project/Slide_project.srcs/sources_1/imports/sources_1/new/spi_module.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1006216973935652998_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );


static void work_a_3415757621_3212880686_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    int t9;
    unsigned char t10;
    char *t11;
    char *t12;
    int t13;

LAB0:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 2272U);
    t3 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t2, 0U, 0U);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 5808);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(66, ng0);
    t4 = (t0 + 3408U);
    t8 = *((char **)t4);
    t9 = *((int *)t8);
    t10 = (t9 == 6);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 3408U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t13 = (t9 + 1);
    t2 = (t0 + 3408U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    *((int *)t2) = t13;

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 2632U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(67, ng0);
    t4 = (t0 + 3408U);
    t11 = *((char **)t4);
    t4 = (t11 + 0);
    *((int *)t4) = 0;
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t1 = *((unsigned char *)t4);
    t3 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t1);
    t2 = (t0 + 5936);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = t3;
    xsi_driver_first_trans_fast(t2);
    goto LAB9;

}

static void work_a_3415757621_3212880686_p_1(char *t0)
{
    char t15[16];
    char t16[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t17;
    char *t18;
    char *t19;
    int t20;
    unsigned char t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 2432U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(99, ng0);
    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t9 = (t2 == (unsigned char)3);
    if (t9 != 0)
        goto LAB15;

LAB17:
LAB16:    t1 = (t0 + 5824);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(83, ng0);
    t3 = (t0 + 2792U);
    t4 = *((char **)t3);
    t5 = (4 - 4);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t3 = (t4 + t8);
    t9 = *((unsigned char *)t3);
    t10 = (t0 + 6000);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = t9;
    xsi_driver_first_trans_fast_port(t10);
    xsi_set_current_line(84, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t6 = (4 - 3);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t3 + t8);
    t10 = ((IEEE_P_2592010699) + 4000);
    t11 = (t16 + 0U);
    t12 = (t11 + 0U);
    *((int *)t12) = 3;
    t12 = (t11 + 4U);
    *((int *)t12) = 0;
    t12 = (t11 + 8U);
    *((int *)t12) = -1;
    t5 = (0 - 3);
    t17 = (t5 * -1);
    t17 = (t17 + 1);
    t12 = (t11 + 12U);
    *((unsigned int *)t12) = t17;
    t4 = xsi_base_array_concat(t4, t15, t10, (char)97, t1, t16, (char)99, (unsigned char)2, (char)101);
    t17 = (4U + 1U);
    t2 = (5U != t17);
    if (t2 == 1)
        goto LAB5;

LAB6:    t12 = (t0 + 6064);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t18 = (t14 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t4, 5U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(85, ng0);
    t1 = (t0 + 3528U);
    t3 = *((char **)t1);
    t5 = *((int *)t3);
    t2 = (t5 > 6);
    if (t2 != 0)
        goto LAB7;

LAB9:
LAB8:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 3528U);
    t3 = *((char **)t1);
    t5 = *((int *)t3);
    t2 = (t5 == 17);
    if (t2 != 0)
        goto LAB12;

LAB14:    xsi_set_current_line(96, ng0);
    t1 = (t0 + 3528U);
    t3 = *((char **)t1);
    t5 = *((int *)t3);
    t20 = (t5 + 1);
    t1 = (t0 + 3528U);
    t4 = *((char **)t1);
    t1 = (t4 + 0);
    *((int *)t1) = t20;

LAB13:    goto LAB3;

LAB5:    xsi_size_not_matching(5U, t17, 0);
    goto LAB6;

LAB7:    xsi_set_current_line(86, ng0);
    t1 = (t0 + 2952U);
    t4 = *((char **)t1);
    t6 = (9 - 8);
    t7 = (t6 * 1U);
    t8 = (0 + t7);
    t1 = (t4 + t8);
    t10 = (t0 + 1032U);
    t11 = *((char **)t10);
    t9 = *((unsigned char *)t11);
    t12 = ((IEEE_P_2592010699) + 4000);
    t13 = (t16 + 0U);
    t14 = (t13 + 0U);
    *((int *)t14) = 8;
    t14 = (t13 + 4U);
    *((int *)t14) = 0;
    t14 = (t13 + 8U);
    *((int *)t14) = -1;
    t20 = (0 - 8);
    t17 = (t20 * -1);
    t17 = (t17 + 1);
    t14 = (t13 + 12U);
    *((unsigned int *)t14) = t17;
    t10 = xsi_base_array_concat(t10, t15, t12, (char)97, t1, t16, (char)99, t9, (char)101);
    t17 = (9U + 1U);
    t21 = (10U != t17);
    if (t21 == 1)
        goto LAB10;

LAB11:    t14 = (t0 + 6128);
    t18 = (t14 + 56U);
    t19 = *((char **)t18);
    t22 = (t19 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t10, 10U);
    xsi_driver_first_trans_fast(t14);
    goto LAB8;

LAB10:    xsi_size_not_matching(10U, t17, 0);
    goto LAB11;

LAB12:    xsi_set_current_line(89, ng0);
    t1 = (t0 + 6192);
    t4 = (t1 + 56U);
    t10 = *((char **)t4);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    *((unsigned char *)t12) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(90, ng0);
    t1 = (t0 + 2952U);
    t3 = *((char **)t1);
    t1 = (t0 + 6256);
    t4 = (t1 + 56U);
    t10 = *((char **)t4);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 10U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(91, ng0);
    t1 = (t0 + 3648U);
    t3 = *((char **)t1);
    t1 = (t0 + 10976U);
    t4 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t15, t3, t1, 1);
    t10 = (t0 + 3648U);
    t11 = *((char **)t10);
    t10 = (t11 + 0);
    t12 = (t15 + 12U);
    t6 = *((unsigned int *)t12);
    t7 = (1U * t6);
    memcpy(t10, t4, t7);
    xsi_set_current_line(92, ng0);
    t1 = (t0 + 3648U);
    t3 = *((char **)t1);
    t1 = (t0 + 6320);
    t4 = (t1 + 56U);
    t10 = *((char **)t4);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 2U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(93, ng0);
    t1 = (t0 + 3528U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    *((int *)t1) = 0;
    xsi_set_current_line(94, ng0);
    t1 = (t0 + 6384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB13;

LAB15:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t1 = (t0 + 6064);
    t10 = (t1 + 56U);
    t11 = *((char **)t10);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t4, 5U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(101, ng0);
    t1 = (t0 + 6192);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(102, ng0);
    t1 = (t0 + 6384);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t10 = (t4 + 56U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB16;

}

static void work_a_3415757621_3212880686_p_2(char *t0)
{
    char t9[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned int t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;

LAB0:    xsi_set_current_line(110, ng0);
    t1 = (t0 + 2272U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5840);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(111, ng0);
    t3 = (t0 + 3112U);
    t4 = *((char **)t3);
    t3 = (t0 + 3768U);
    t5 = *((char **)t3);
    t6 = 1;
    if (2U == 2U)
        goto LAB8;

LAB9:    t6 = 0;

LAB10:    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(115, ng0);
    t1 = (t0 + 6448);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t8 = *((char **)t5);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(112, ng0);
    t10 = (t0 + 3768U);
    t11 = *((char **)t10);
    t10 = (t0 + 10992U);
    t12 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t9, t11, t10, 1);
    t13 = (t0 + 3768U);
    t14 = *((char **)t13);
    t13 = (t14 + 0);
    t15 = (t9 + 12U);
    t16 = *((unsigned int *)t15);
    t17 = (1U * t16);
    memcpy(t13, t12, t17);
    xsi_set_current_line(113, ng0);
    t1 = (t0 + 6448);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t8 = *((char **)t5);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
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

}

static void work_a_3415757621_3212880686_p_3(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(120, ng0);

LAB3:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 6512);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 5856);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3415757621_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3415757621_3212880686_p_0,(void *)work_a_3415757621_3212880686_p_1,(void *)work_a_3415757621_3212880686_p_2,(void *)work_a_3415757621_3212880686_p_3};
	xsi_register_didat("work_a_3415757621_3212880686", "isim/sim_tlm_slider.exe.sim/work/a_3415757621_3212880686.didat");
	xsi_register_executes(pe);
}
