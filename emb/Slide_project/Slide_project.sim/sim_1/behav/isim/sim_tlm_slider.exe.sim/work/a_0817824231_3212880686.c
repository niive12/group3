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
static const char *ng0 = "/home/matthias/RobtekE15/EMB1/Slide_project/Slide_project.srcs/sources_1/imports/sources_1/imports/µTosNet/PTNX_top.vhd";
extern char *IEEE_P_2592010699;



static void work_a_0817824231_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(82, ng0);

LAB3:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 5880);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);

LAB2:    t8 = (t0 + 5736);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0817824231_3212880686_p_1(char *t0)
{
    char t4[16];
    char t10[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t11;
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

LAB0:    xsi_set_current_line(83, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t5 = ((IEEE_P_2592010699) + 4000);
    t6 = (t0 + 10760U);
    t7 = (t0 + 10776U);
    t1 = xsi_base_array_concat(t1, t4, t5, (char)97, t2, t6, (char)97, t3, t7, (char)101);
    t8 = (t0 + 2312U);
    t9 = *((char **)t8);
    t11 = ((IEEE_P_2592010699) + 4000);
    t12 = (t0 + 10792U);
    t8 = xsi_base_array_concat(t8, t10, t11, (char)97, t1, t4, (char)97, t9, t12, (char)101);
    t13 = (10U + 10U);
    t14 = (t13 + 10U);
    t15 = (30U != t14);
    if (t15 == 1)
        goto LAB5;

LAB6:    t16 = (t0 + 5944);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t8, 30U);
    xsi_driver_first_trans_fast_port(t16);

LAB2:    t21 = (t0 + 5752);
    *((int *)t21) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(30U, t14, 0);
    goto LAB6;

}

static void work_a_0817824231_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(84, ng0);

LAB3:    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 6008);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 10U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 5768);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0817824231_3212880686_p_3(char *t0)
{
    char t14[16];
    unsigned char t1;
    unsigned char t2;
    char *t3;
    unsigned char t4;
    char *t5;
    char *t6;
    unsigned char t7;
    unsigned char t8;
    char *t9;
    unsigned char t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t20;
    char *t21;
    int t23;
    char *t24;
    int t26;
    char *t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(92, ng0);
    t3 = (t0 + 1792U);
    t4 = xsi_signal_has_event(t3);
    if (t4 == 1)
        goto LAB8;

LAB9:    t2 = (unsigned char)0;

LAB10:    if (t2 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t3 = (t0 + 5784);
    *((int *)t3) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(93, ng0);
    t5 = (t0 + 2632U);
    t12 = *((char **)t5);
    t5 = (t0 + 2792U);
    t13 = *((char **)t5);
    t15 = ((IEEE_P_2592010699) + 4000);
    t16 = (t0 + 10824U);
    t17 = (t0 + 10840U);
    t5 = xsi_base_array_concat(t5, t14, t15, (char)97, t12, t16, (char)97, t13, t17, (char)101);
    t18 = (t0 + 11019);
    t20 = xsi_mem_cmp(t18, t5, 5U);
    if (t20 == 1)
        goto LAB12;

LAB16:    t21 = (t0 + 11024);
    t23 = xsi_mem_cmp(t21, t5, 5U);
    if (t23 == 1)
        goto LAB13;

LAB17:    t24 = (t0 + 11029);
    t26 = xsi_mem_cmp(t24, t5, 5U);
    if (t26 == 1)
        goto LAB14;

LAB18:
LAB15:
LAB11:    goto LAB3;

LAB5:    t5 = (t0 + 3272U);
    t9 = *((char **)t5);
    t10 = *((unsigned char *)t9);
    t11 = (t10 == (unsigned char)3);
    t1 = t11;
    goto LAB7;

LAB8:    t5 = (t0 + 1832U);
    t6 = *((char **)t5);
    t7 = *((unsigned char *)t6);
    t8 = (t7 == (unsigned char)3);
    t2 = t8;
    goto LAB10;

LAB12:    xsi_set_current_line(94, ng0);
    t27 = (t0 + 3112U);
    t28 = *((char **)t27);
    t29 = (31 - 9);
    t30 = (t29 * 1U);
    t31 = (0 + t30);
    t27 = (t28 + t31);
    t32 = (t0 + 6072);
    t33 = (t32 + 56U);
    t34 = *((char **)t33);
    t35 = (t34 + 56U);
    t36 = *((char **)t35);
    memcpy(t36, t27, 10U);
    xsi_driver_first_trans_fast(t32);
    goto LAB11;

LAB13:    xsi_set_current_line(95, ng0);
    t3 = (t0 + 3112U);
    t5 = *((char **)t3);
    t29 = (31 - 9);
    t30 = (t29 * 1U);
    t31 = (0 + t30);
    t3 = (t5 + t31);
    t6 = (t0 + 6136);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    t13 = (t12 + 56U);
    t15 = *((char **)t13);
    memcpy(t15, t3, 10U);
    xsi_driver_first_trans_fast(t6);
    goto LAB11;

LAB14:    xsi_set_current_line(96, ng0);
    t3 = (t0 + 3112U);
    t5 = *((char **)t3);
    t29 = (31 - 9);
    t30 = (t29 * 1U);
    t31 = (0 + t30);
    t3 = (t5 + t31);
    t6 = (t0 + 6200);
    t9 = (t6 + 56U);
    t12 = *((char **)t9);
    t13 = (t12 + 56U);
    t15 = *((char **)t13);
    memcpy(t15, t3, 10U);
    xsi_driver_first_trans_fast(t6);
    goto LAB11;

LAB19:;
}

static void work_a_0817824231_3212880686_p_4(char *t0)
{
    char t8[16];
    char t16[16];
    char t18[16];
    char t23[16];
    char t28[16];
    char t30[16];
    char t36[16];
    char t38[16];
    char t44[16];
    char t46[16];
    char t52[16];
    char t54[16];
    char t59[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int t10;
    char *t11;
    char *t13;
    char *t15;
    char *t17;
    char *t19;
    char *t20;
    int t21;
    unsigned int t22;
    char *t24;
    int t25;
    char *t27;
    char *t29;
    char *t31;
    char *t32;
    int t33;
    char *t35;
    char *t37;
    char *t39;
    char *t40;
    int t41;
    char *t43;
    char *t45;
    char *t47;
    char *t48;
    int t49;
    char *t51;
    char *t53;
    char *t55;
    char *t56;
    int t57;
    char *t58;
    char *t60;
    char *t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned char t67;
    char *t68;
    char *t69;
    char *t70;
    char *t71;
    char *t72;

LAB0:    xsi_set_current_line(108, ng0);
    t1 = (t0 + 11034);
    t3 = (t0 + 6264);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    memcpy(t7, t1, 32U);
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(109, ng0);
    t1 = (t0 + 2632U);
    t2 = *((char **)t1);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t4 = ((IEEE_P_2592010699) + 4000);
    t5 = (t0 + 10824U);
    t6 = (t0 + 10840U);
    t1 = xsi_base_array_concat(t1, t8, t4, (char)97, t2, t5, (char)97, t3, t6, (char)101);
    t7 = (t0 + 11066);
    t10 = xsi_mem_cmp(t7, t1, 5U);
    if (t10 == 1)
        goto LAB3;

LAB5:
LAB4:
LAB2:    t1 = (t0 + 5800);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(115, ng0);
    t11 = (t0 + 11071);
    t13 = (t0 + 11073);
    t17 = ((IEEE_P_2592010699) + 4000);
    t19 = (t18 + 0U);
    t20 = (t19 + 0U);
    *((int *)t20) = 0;
    t20 = (t19 + 4U);
    *((int *)t20) = 1;
    t20 = (t19 + 8U);
    *((int *)t20) = 1;
    t21 = (1 - 0);
    t22 = (t21 * 1);
    t22 = (t22 + 1);
    t20 = (t19 + 12U);
    *((unsigned int *)t20) = t22;
    t20 = (t23 + 0U);
    t24 = (t20 + 0U);
    *((int *)t24) = 0;
    t24 = (t20 + 4U);
    *((int *)t24) = 3;
    t24 = (t20 + 8U);
    *((int *)t24) = 1;
    t25 = (3 - 0);
    t22 = (t25 * 1);
    t22 = (t22 + 1);
    t24 = (t20 + 12U);
    *((unsigned int *)t24) = t22;
    t15 = xsi_base_array_concat(t15, t16, t17, (char)97, t11, t18, (char)97, t13, t23, (char)101);
    t24 = (t0 + 11077);
    t29 = ((IEEE_P_2592010699) + 4000);
    t31 = (t30 + 0U);
    t32 = (t31 + 0U);
    *((int *)t32) = 0;
    t32 = (t31 + 4U);
    *((int *)t32) = 3;
    t32 = (t31 + 8U);
    *((int *)t32) = 1;
    t33 = (3 - 0);
    t22 = (t33 * 1);
    t22 = (t22 + 1);
    t32 = (t31 + 12U);
    *((unsigned int *)t32) = t22;
    t27 = xsi_base_array_concat(t27, t28, t29, (char)97, t15, t16, (char)97, t24, t30, (char)101);
    t32 = (t0 + 11081);
    t37 = ((IEEE_P_2592010699) + 4000);
    t39 = (t38 + 0U);
    t40 = (t39 + 0U);
    *((int *)t40) = 0;
    t40 = (t39 + 4U);
    *((int *)t40) = 3;
    t40 = (t39 + 8U);
    *((int *)t40) = 1;
    t41 = (3 - 0);
    t22 = (t41 * 1);
    t22 = (t22 + 1);
    t40 = (t39 + 12U);
    *((unsigned int *)t40) = t22;
    t35 = xsi_base_array_concat(t35, t36, t37, (char)97, t27, t28, (char)97, t32, t38, (char)101);
    t40 = (t0 + 11085);
    t45 = ((IEEE_P_2592010699) + 4000);
    t47 = (t46 + 0U);
    t48 = (t47 + 0U);
    *((int *)t48) = 0;
    t48 = (t47 + 4U);
    *((int *)t48) = 3;
    t48 = (t47 + 8U);
    *((int *)t48) = 1;
    t49 = (3 - 0);
    t22 = (t49 * 1);
    t22 = (t22 + 1);
    t48 = (t47 + 12U);
    *((unsigned int *)t48) = t22;
    t43 = xsi_base_array_concat(t43, t44, t45, (char)97, t35, t36, (char)97, t40, t46, (char)101);
    t48 = (t0 + 11089);
    t53 = ((IEEE_P_2592010699) + 4000);
    t55 = (t54 + 0U);
    t56 = (t55 + 0U);
    *((int *)t56) = 0;
    t56 = (t55 + 4U);
    *((int *)t56) = 3;
    t56 = (t55 + 8U);
    *((int *)t56) = 1;
    t57 = (3 - 0);
    t22 = (t57 * 1);
    t22 = (t22 + 1);
    t56 = (t55 + 12U);
    *((unsigned int *)t56) = t22;
    t51 = xsi_base_array_concat(t51, t52, t53, (char)97, t43, t44, (char)97, t48, t54, (char)101);
    t56 = (t0 + 2472U);
    t58 = *((char **)t56);
    t60 = ((IEEE_P_2592010699) + 4000);
    t61 = (t0 + 10808U);
    t56 = xsi_base_array_concat(t56, t59, t60, (char)97, t51, t52, (char)97, t58, t61, (char)101);
    t22 = (2U + 4U);
    t62 = (t22 + 4U);
    t63 = (t62 + 4U);
    t64 = (t63 + 4U);
    t65 = (t64 + 4U);
    t66 = (t65 + 10U);
    t67 = (32U != t66);
    if (t67 == 1)
        goto LAB7;

LAB8:    t68 = (t0 + 6264);
    t69 = (t68 + 56U);
    t70 = *((char **)t69);
    t71 = (t70 + 56U);
    t72 = *((char **)t71);
    memcpy(t72, t56, 32U);
    xsi_driver_first_trans_fast(t68);
    goto LAB2;

LAB6:;
LAB7:    xsi_size_not_matching(32U, t66, 0);
    goto LAB8;

}


extern void work_a_0817824231_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0817824231_3212880686_p_0,(void *)work_a_0817824231_3212880686_p_1,(void *)work_a_0817824231_3212880686_p_2,(void *)work_a_0817824231_3212880686_p_3,(void *)work_a_0817824231_3212880686_p_4};
	xsi_register_didat("work_a_0817824231_3212880686", "isim/sim_tlm_slider.exe.sim/work/a_0817824231_3212880686.didat");
	xsi_register_executes(pe);
}
