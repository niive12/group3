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
static const char *ng0 = "/home/matthias/RobtekE15/EMB1/group3/emb/state_machine_mh/state_machine_mh.srcs/sources_1/imports/src/main.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_374109322130769762_503743352(char *, unsigned char );


static void work_a_1774854872_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(88, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 5032);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 4920);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1774854872_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(89, ng0);

LAB3:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 5096);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 4936);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1774854872_3212880686_p_2(char *t0)
{
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
    unsigned char t11;
    unsigned char t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4952);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(94, ng0);
    t3 = (t0 + 2152U);
    t4 = *((char **)t3);
    t3 = (t0 + 2888U);
    t5 = *((char **)t3);
    t6 = 1;
    if (2U == 2U)
        goto LAB8;

LAB9:    t6 = 0;

LAB10:    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3128U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB16;

LAB17:    t2 = 0;

LAB18:    if (t2 != 0)
        goto LAB14;

LAB15:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = (t2 == (unsigned char)0);
    if (t6 != 0)
        goto LAB22;

LAB23:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = (t2 == (unsigned char)1);
    if (t6 != 0)
        goto LAB33;

LAB34:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = (t2 == (unsigned char)2);
    if (t6 != 0)
        goto LAB44;

LAB45:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = (t2 == (unsigned char)3);
    if (t6 != 0)
        goto LAB55;

LAB56:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = (t2 == (unsigned char)4);
    if (t6 != 0)
        goto LAB66;

LAB67:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = (t2 == (unsigned char)5);
    if (t6 != 0)
        goto LAB77;

LAB78:    t1 = (t0 + 1832U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t6 = (t2 == (unsigned char)6);
    if (t6 != 0)
        goto LAB88;

LAB89:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(95, ng0);
    t9 = (t0 + 2312U);
    t10 = *((char **)t9);
    t11 = *((unsigned char *)t10);
    t12 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t11);
    t9 = (t0 + 5160);
    t13 = (t9 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = t12;
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(96, ng0);
    t1 = (t0 + 5224);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t8 = *((char **)t5);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
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

LAB14:    xsi_set_current_line(98, ng0);
    t8 = (t0 + 2472U);
    t9 = *((char **)t8);
    t6 = *((unsigned char *)t9);
    t11 = ieee_p_2592010699_sub_374109322130769762_503743352(IEEE_P_2592010699, t6);
    t8 = (t0 + 5288);
    t10 = (t8 + 56U);
    t13 = *((char **)t10);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    *((unsigned char *)t15) = t11;
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(99, ng0);
    t1 = (t0 + 5224);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t8 = *((char **)t5);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB16:    t7 = 0;

LAB19:    if (t7 < 2U)
        goto LAB20;
    else
        goto LAB18;

LAB20:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB17;

LAB21:    t7 = (t7 + 1);
    goto LAB19;

LAB22:    xsi_set_current_line(101, ng0);
    t1 = xsi_get_transient_memory(6U);
    memset(t1, 0, 6U);
    t4 = t1;
    memset(t4, (unsigned char)2, 6U);
    t5 = (t0 + 5352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t1, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(102, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3008U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB27;

LAB28:    t2 = 0;

LAB29:    if (t2 != 0)
        goto LAB24;

LAB26:
LAB25:    goto LAB6;

LAB24:    xsi_set_current_line(103, ng0);
    t8 = (t0 + 5224);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)1;
    xsi_driver_first_trans_fast(t8);
    goto LAB25;

LAB27:    t7 = 0;

LAB30:    if (t7 < 2U)
        goto LAB31;
    else
        goto LAB29;

LAB31:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB28;

LAB32:    t7 = (t7 + 1);
    goto LAB30;

LAB33:    xsi_set_current_line(106, ng0);
    t1 = (t0 + 9600);
    t5 = (t0 + 5352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t1, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(107, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3008U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB38;

LAB39:    t2 = 0;

LAB40:    if (t2 != 0)
        goto LAB35;

LAB37:
LAB36:    goto LAB6;

LAB35:    xsi_set_current_line(108, ng0);
    t8 = (t0 + 5224);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)2;
    xsi_driver_first_trans_fast(t8);
    goto LAB36;

LAB38:    t7 = 0;

LAB41:    if (t7 < 2U)
        goto LAB42;
    else
        goto LAB40;

LAB42:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB39;

LAB43:    t7 = (t7 + 1);
    goto LAB41;

LAB44:    xsi_set_current_line(111, ng0);
    t1 = (t0 + 9606);
    t5 = (t0 + 5352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t1, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(112, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3008U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB49;

LAB50:    t2 = 0;

LAB51:    if (t2 != 0)
        goto LAB46;

LAB48:
LAB47:    goto LAB6;

LAB46:    xsi_set_current_line(113, ng0);
    t8 = (t0 + 5224);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)3;
    xsi_driver_first_trans_fast(t8);
    goto LAB47;

LAB49:    t7 = 0;

LAB52:    if (t7 < 2U)
        goto LAB53;
    else
        goto LAB51;

LAB53:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB50;

LAB54:    t7 = (t7 + 1);
    goto LAB52;

LAB55:    xsi_set_current_line(116, ng0);
    t1 = (t0 + 9612);
    t5 = (t0 + 5352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t1, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3008U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB60;

LAB61:    t2 = 0;

LAB62:    if (t2 != 0)
        goto LAB57;

LAB59:
LAB58:    goto LAB6;

LAB57:    xsi_set_current_line(118, ng0);
    t8 = (t0 + 5224);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)4;
    xsi_driver_first_trans_fast(t8);
    goto LAB58;

LAB60:    t7 = 0;

LAB63:    if (t7 < 2U)
        goto LAB64;
    else
        goto LAB62;

LAB64:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB61;

LAB65:    t7 = (t7 + 1);
    goto LAB63;

LAB66:    xsi_set_current_line(121, ng0);
    t1 = (t0 + 9618);
    t5 = (t0 + 5352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t1, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(122, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3008U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB71;

LAB72:    t2 = 0;

LAB73:    if (t2 != 0)
        goto LAB68;

LAB70:
LAB69:    goto LAB6;

LAB68:    xsi_set_current_line(123, ng0);
    t8 = (t0 + 5224);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)5;
    xsi_driver_first_trans_fast(t8);
    goto LAB69;

LAB71:    t7 = 0;

LAB74:    if (t7 < 2U)
        goto LAB75;
    else
        goto LAB73;

LAB75:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB72;

LAB76:    t7 = (t7 + 1);
    goto LAB74;

LAB77:    xsi_set_current_line(126, ng0);
    t1 = (t0 + 9624);
    t5 = (t0 + 5352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t1, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(127, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3008U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB82;

LAB83:    t2 = 0;

LAB84:    if (t2 != 0)
        goto LAB79;

LAB81:
LAB80:    goto LAB6;

LAB79:    xsi_set_current_line(128, ng0);
    t8 = (t0 + 5224);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)6;
    xsi_driver_first_trans_fast(t8);
    goto LAB80;

LAB82:    t7 = 0;

LAB85:    if (t7 < 2U)
        goto LAB86;
    else
        goto LAB84;

LAB86:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB83;

LAB87:    t7 = (t7 + 1);
    goto LAB85;

LAB88:    xsi_set_current_line(131, ng0);
    t1 = (t0 + 9630);
    t5 = (t0 + 5352);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t13 = *((char **)t10);
    memcpy(t13, t1, 6U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(132, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t1 = (t0 + 3008U);
    t4 = *((char **)t1);
    t2 = 1;
    if (2U == 2U)
        goto LAB93;

LAB94:    t2 = 0;

LAB95:    if (t2 != 0)
        goto LAB90;

LAB92:
LAB91:    goto LAB6;

LAB90:    xsi_set_current_line(133, ng0);
    t8 = (t0 + 5224);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t13 = (t10 + 56U);
    t14 = *((char **)t13);
    *((unsigned char *)t14) = (unsigned char)1;
    xsi_driver_first_trans_fast(t8);
    goto LAB91;

LAB93:    t7 = 0;

LAB96:    if (t7 < 2U)
        goto LAB97;
    else
        goto LAB95;

LAB97:    t1 = (t3 + t7);
    t5 = (t4 + t7);
    if (*((unsigned char *)t1) != *((unsigned char *)t5))
        goto LAB94;

LAB98:    t7 = (t7 + 1);
    goto LAB96;

}


extern void work_a_1774854872_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1774854872_3212880686_p_0,(void *)work_a_1774854872_3212880686_p_1,(void *)work_a_1774854872_3212880686_p_2};
	xsi_register_didat("work_a_1774854872_3212880686", "isim/sim_test.exe.sim/work/a_1774854872_3212880686.didat");
	xsi_register_executes(pe);
}
