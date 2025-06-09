/*
 * emu_tc_programming.cpp
 *
 *  Created on: Jan 13, 2017
 *
 *  Created on: Oct 26, 2024
 *      Author: Oscar Rodriguez Polo
 */

/****************************************************************************
 *
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   as published by the Free Software Foundation; either version 2
 *   of the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307,USA.
 *
 *
 ****************************************************************************/



#include <public/emu_hw_timecode_drv_v1.h>
#include <public/emu_sc_channel_drv_v1.h>
#include <public/emu_gss_v1.h>

//TODO Complete FT_UAH_PHOTSAT_SERV_129_0010
//#define FT_UAH_PHOTSAT_SERV_129_0010

#ifdef FT_UAH_PHOTSAT_SERV_129_0010

#define FT_UAH_PHOTSAT_SERV_129_0010_step0 (OBT_AFTER_POWER_ON +10)
#define FT_UAH_PHOTSAT_SERV_129_0010_step1 (OBT_AFTER_POWER_ON +20)

EmuGSS_TCProgram3_5 prog_FT_UAH_PHOTSAT_SERV_129_0010_step0(FT_UAH_PHOTSAT_SERV_129_0010_step0,
"FT_UAH_PHOTSAT_SERV_129_0010 step 0, Enable SID 20 ", 20);
EmuGSS_TCProgram129_1 prog_FT_UAH_PHOTSAT_SERV_129_0010_step1(FT_UAH_PHOTSAT_SERV_129_0010_step1,
"FT_UAH_PHOTSAT_SERV_129_0010 step 1, definimos los parametros para 4 imagenes actitud pitch=150 yaw=180",
150, 180 , 4);


#endif

//TODO Complete FT_UAH_PHOTSAT_SERV_129_FDIR_0020
#define FT_UAH_PHOTSAT_SERV_129_0020

#ifdef FT_UAH_PHOTSAT_SERV_129_0020

#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step0 (OBT_AFTER_POWER_ON + 10)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step1 (OBT_AFTER_POWER_ON + 20)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step2 (OBT_AFTER_POWER_ON + 30)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step3 (OBT_AFTER_POWER_ON + 40)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step4 (OBT_AFTER_POWER_ON + 50)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step5 (OBT_AFTER_POWER_ON + 60)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step6 (OBT_AFTER_POWER_ON + 70)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step7 (OBT_AFTER_POWER_ON + 80)
#define FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step8 (OBT_AFTER_POWER_ON + 90)
EmuGSS_TCProgram3_5 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step0(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step0,
"FT_UAH_PHOTSAT_SERV_129_0010 step 0, Habilita SID 20 ", 20);
EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_1(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step1,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_1, Config PMODID 0 for monitoring PID 13",
0, 13, 2, 1, 0xFFFF, 0, 0x4003);
EmuGSS_TCProgram12_5_Value_UINT8 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_2(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step2,
"FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_2, Config PMODID 1 for monitoring PID 14",
1, 14, 2, 1, 0xFFFF, 0, 0x4003);
EmuGSS_TCProgram12_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_3(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step3,
"FT_UAH_ASW_Monitoring_0130 step 3, Enable Monitoring PMODID 0", 0);
EmuGSS_TCProgram12_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_4(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step4,
"FT_UAH_ASW_Monitoring_0130 step 4, Enable Monitoring PMODID 1", 1);
EmuGSS_TCProgram19_1_Action_129_3 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_5(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step5,
"FT_UAH_ASW_Event_Action_0130 step 5, La acción del EvID 0x4003 es el reset",
0x4003);
EmuGSS_TCProgram19_4 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_6(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step6,
"FT_UAH_ASW_Event_Action_0130 step 6, Habilita la acción del EvID 0x4003",
0x4003);
EmuGSS_TCProgram129_2 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_7(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step7,
"FT_UAH_ASW_Event_Action_0130 step 7, Configura kp=ki=kd=0,5",
0.5, 0.5, 0.5);
EmuGSS_TCProgram129_1 prog_FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step_8(FT_UAH_PHOTSAT_SERV_129_FDIR_0020_step8,
"FT_UAH_PHOTSAT_SERV_129_0010 step 8, pedir 1 imagen con estos parametros con actitud pitch=1800 yaw=1800",
1800, 1800 , 1);
#endif
