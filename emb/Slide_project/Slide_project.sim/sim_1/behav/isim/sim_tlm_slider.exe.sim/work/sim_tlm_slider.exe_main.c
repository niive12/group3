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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *STD_TEXTIO;
char *IEEE_P_2592010699;
char *STD_STANDARD;
char *IEEE_P_3499444699;
char *IEEE_P_3620187407;
char *UNISIM_P_0947159679;
char *IEEE_P_3564397177;
char *IEEE_P_1242562249;
char *UNISIM_P_3222816464;
char *IEEE_P_2717149903;
char *IEEE_P_1367372525;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    work_m_16541823861846354283_2073120511_init();
    ieee_p_2592010699_init();
    ieee_p_1242562249_init();
    ieee_p_3499444699_init();
    ieee_p_3620187407_init();
    work_a_2541078164_3212880686_init();
    work_a_2761853765_3212880686_init();
    work_a_3415757621_3212880686_init();
    unisim_p_0947159679_init();
    std_textio_init();
    ieee_p_3564397177_init();
    xilinxcorelib_a_2001352570_3212880686_init();
    xilinxcorelib_a_0837435367_3212880686_init();
    work_a_0178679499_3324905210_init();
    ieee_p_2717149903_init();
    ieee_p_1367372525_init();
    unisim_p_3222816464_init();
    unisim_a_0350208134_1521797606_init();
    unisim_a_1398595224_1990404599_init();
    unisim_a_3519694068_2693788048_init();
    unisim_a_3444408037_3676810390_init();
    unisim_a_2447198262_3676810390_init();
    unisim_a_2363982922_3676810390_init();
    unisim_a_3333324666_3676810390_init();
    unisim_a_3064295332_3676810390_init();
    unisim_a_3705309847_3676810390_init();
    unisim_a_2531160992_3676810390_init();
    unisim_a_1347458946_3676810390_init();
    unisim_a_0198283990_3676810390_init();
    unisim_a_3679869664_3731405331_init();
    unisim_a_2829587188_3731405331_init();
    unisim_a_2737004232_3731405331_init();
    unisim_a_3435466905_3731405331_init();
    unisim_a_3822252837_3752513572_init();
    work_a_1061777954_2111220564_init();
    unisim_a_0868425105_1864968857_init();
    unisim_a_1646226234_1266530935_init();
    unisim_a_3484885994_2523279426_init();
    unisim_a_1941169844_3118875749_init();
    work_a_0616549169_2111220564_init();
    work_a_0768645600_0622287258_init();
    unisim_a_3163574381_0086195937_init();
    unisim_a_2233298088_0124092600_init();
    unisim_a_0936227941_2005071195_init();
    unisim_a_3702704980_1602505438_init();
    work_a_0844563045_2111220564_init();
    work_a_0550431143_0622287258_init();
    work_a_3776182124_3212880686_init();
    work_a_3398383504_3212880686_init();
    work_a_0817824231_3212880686_init();
    work_a_3943075478_3212880686_init();
    work_a_0751541614_3212880686_init();


    xsi_register_tops("work_a_0751541614_3212880686");
    xsi_register_tops("work_m_16541823861846354283_2073120511");

    STD_TEXTIO = xsi_get_engine_memory("std_textio");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_3499444699 = xsi_get_engine_memory("ieee_p_3499444699");
    IEEE_P_3620187407 = xsi_get_engine_memory("ieee_p_3620187407");
    UNISIM_P_0947159679 = xsi_get_engine_memory("unisim_p_0947159679");
    IEEE_P_3564397177 = xsi_get_engine_memory("ieee_p_3564397177");
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    UNISIM_P_3222816464 = xsi_get_engine_memory("unisim_p_3222816464");
    IEEE_P_2717149903 = xsi_get_engine_memory("ieee_p_2717149903");
    IEEE_P_1367372525 = xsi_get_engine_memory("ieee_p_1367372525");

    return xsi_run_simulation(argc, argv);

}
