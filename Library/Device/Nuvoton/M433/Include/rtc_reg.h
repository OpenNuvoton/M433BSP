/**************************************************************************//**
 * @file     rtc_reg.h
 * @version  V1.00
 * @brief    RTC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2017-2020 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __RTC_REG_H__
#define __RTC_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
  @{
*/

/**
    @addtogroup RTC Real Time Clock Controller(RTC)
    Memory Mapped Structure for RTC Controller
@{ */

typedef struct
{


    /**
     * @var RTC_T::INIT
     * Offset: 0x00  RTC Initiation Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |INIT_ACTIVE|RTC Active Status (Read Only)
     * |        |          |0 = RTC is at reset state.
     * |        |          |1 = RTC is at normal active state.
     * |[31:1]  |INIT      |RTC Initiation (Write Only)
     * |        |          |When RTC block is powered on, RTC is at reset state
     * |        |          |User has to write a number (0xa5eb1357) to INIT to make RTC leaving reset state
     * |        |          |Once the INIT is written as 0xa5eb1357, the RTC will be in un-reset state permanently.
     * |        |          |The INIT is a write-only field and read value will be always 0.
     * @var RTC_T::RWEN
     * Offset: 0x04  RTC Access Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[16]    |RWENF     |RTC Register Access Enable Flag (Read Only)
     * |        |          |0 = RTC register read/write Disabled.
     * |        |          |1 = RTC register read/write Enabled.
     * |        |          |Note: RWENF will be mask to 0 during RTCBUSY is 1, and first turn on RTCCKEN (CLK_APBCLK[1]) also.
     * |[24]    |RTCBUSY   |RTC Write Busy Flag
     * |        |          |This bit indicates RTC registers are writable or not.
     * |        |          |0: RTC registers are writable.
     * |        |          |1: RTC registers can't write, RTC under Busy Status.
     * |        |          |Note: RTCBUSY flag will be set when execute write RTC register command exceed 6 times within 1120 PCLK cycles.
     * @var RTC_T::FREQADJ
     * Offset: 0x08  RTC Frequency Compensation Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[21:0]  |FREQADJ   |Frequency Compensation Register
     * |        |          |User must to get actual LXT frequency for RTC application.
     * |        |          |FCR = 0x200000 * (32768 / LXT frequency).
     * |        |          |Note: This formula is suitable only when RTC clock source is from LXT, RTCSEL (CLK_CLKSEL3[8]) is 0.
     * |[5:0]   |FRACTION  |Fraction Part
     * |        |          |Formula: FRACTION = (fraction part of detected value) X 64.
     * |        |          |Note: Digit in FCR must be expressed as hexadecimal number.
     * |[12:8]  |INTEGER   |Integer Part
     * |        |          |00000 = Integer part of detected value is 32752.
     * |        |          |00001 = Integer part of detected value is 32753.
     * |        |          |00010 = Integer part of detected value is 32754.
     * |        |          |00011 = Integer part of detected value is 32755.
     * |        |          |00100 = Integer part of detected value is 32756.
     * |        |          |00101 = Integer part of detected value is 32757.
     * |        |          |00110 = Integer part of detected value is 32758.
     * |        |          |00111 = Integer part of detected value is 32759.
     * |        |          |01000 = Integer part of detected value is 32760.
     * |        |          |01001 = Integer part of detected value is 32761.
     * |        |          |01010 = Integer part of detected value is 32762.
     * |        |          |01011 = Integer part of detected value is 32763.
     * |        |          |01100 = Integer part of detected value is 32764.
     * |        |          |01101 = Integer part of detected value is 32765.
     * |        |          |01110 = Integer part of detected value is 32766.
     * |        |          |01111 = Integer part of detected value is 32767.
     * |        |          |10000 = Integer part of detected value is 32768.
     * |        |          |10001 = Integer part of detected value is 32769.
     * |        |          |10010 = Integer part of detected value is 32770.
     * |        |          |10011 = Integer part of detected value is 32771.
     * |        |          |10100 = Integer part of detected value is 32772.
     * |        |          |10101 = Integer part of detected value is 32773.
     * |        |          |10110 = Integer part of detected value is 32774.
     * |        |          |10111 = Integer part of detected value is 32775.
     * |        |          |11000 = Integer part of detected value is 32776.
     * |        |          |11001 = Integer part of detected value is 32777.
     * |        |          |11010 = Integer part of detected value is 32778.
     * |        |          |11011 = Integer part of detected value is 32779.
     * |        |          |11100 = Integer part of detected value is 32780.
     * |        |          |11101 = Integer part of detected value is 32781.
     * |        |          |11110 = Integer part of detected value is 32782.
     * |        |          |11111 = Integer part of detected value is 32783.
     * |[31]    |FCR_BUSY  |Frequency Compensation Register Write Operation Busy (Read Only)
     * |        |          |0 = The new register write operation is acceptable.
     * |        |          |1 = The last write operation is in progress and new register write operation prohibited.
     * |        |          |Note: This bit is only used when DYN_COMP_EN(RTC_CLKFMT[16]) enabled.
     * @var RTC_T::TIME
     * Offset: 0x0C  RTC Time Loading Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |SEC       |1-Sec Time Digit (0~9)
     * |[6:4]   |TENSEC    |10-Sec Time Digit (0~5)
     * |[11:8]  |MIN       |1-Min Time Digit (0~9)
     * |[14:12] |TENMIN    |10-Min Time Digit (0~5)
     * |[19:16] |HR        |1-Hour Time Digit (0~9)
     * |[21:20] |TENHR     |10-Hour Time Digit (0~2)
     * |        |          |When RTC runs as 12-hour time scale mode, RTC_TIME[21] (the high bit of TENHR[1:0]) means AM/PM indication
     * |        |          |(If RTC_TIME[21] is 1, it indicates PM time message).
     * @var RTC_T::CAL
     * Offset: 0x10  RTC Calendar Loading Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |DAY       |1-Day Calendar Digit (0~9)
     * |[5:4]   |TENDAY    |10-Day Calendar Digit (0~3)
     * |[11:8]  |MON       |1-Month Calendar Digit (0~9)
     * |[12]    |TENMON    |10-Month Calendar Digit (0~1)
     * |[19:16] |YEAR      |1-Year Calendar Digit (0~9)
     * |[23:20] |TENYEAR   |10-Year Calendar Digit (0~9)
     * @var RTC_T::CLKFMT
     * Offset: 0x14  RTC Time Scale Selection Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |24HEN     |24-hour / 12-hour Time Scale Selection
     * |        |          |Indicates that RTC_TIME and RTC_TALM are in 24-hour time scale or 12-hour time scale
     * |        |          |0 = 12-hour time scale with AM and PM indication selected.
     * |        |          |1 = 24-hour time scale selected.
     * @var RTC_T::WEEKDAY
     * Offset: 0x18  RTC Day of the Week Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2:0]   |WEEKDAY   |Day of the Week Register
     * |        |          |000 = Sunday.
     * |        |          |001 = Monday.
     * |        |          |010 = Tuesday.
     * |        |          |011 = Wednesday.
     * |        |          |100 = Thursday.
     * |        |          |101 = Friday.
     * |        |          |110 = Saturday.
     * |        |          |111 = Reserved.
     * @var RTC_T::TALM
     * Offset: 0x1C  RTC Time Alarm Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |SEC       |1-Sec Time Digit of Alarm Setting (0~9)
     * |[6:4]   |TENSEC    |10-Sec Time Digit of Alarm Setting (0~5)
     * |[11:8]  |MIN       |1-Min Time Digit of Alarm Setting (0~9)
     * |[14:12] |TENMIN    |10-Min Time Digit of Alarm Setting (0~5)
     * |[19:16] |HR        |1-Hour Time Digit of Alarm Setting (0~9)
     * |[21:20] |TENHR     |10-Hour Time Digit of Alarm Setting (0~2)
     * |        |          |When RTC runs as 12-hour time scale mode, RTC_TIME[21] (the high bit of TENHR[1:0]) means AM/PM indication
     * |        |          |(If RTC_TIME[21] is 1, it indicates PM time message).
     * @var RTC_T::CALM
     * Offset: 0x20  RTC Calendar Alarm Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |DAY       |1-Day Calendar Digit of Alarm Setting (0~9)
     * |[5:4]   |TENDAY    |10-Day Calendar Digit of Alarm Setting (0~3)
     * |[11:8]  |MON       |1-Month Calendar Digit of Alarm Setting (0~9)
     * |[12]    |TENMON    |10-Month Calendar Digit of Alarm Setting (0~1)
     * |[19:16] |YEAR      |1-Year Calendar Digit of Alarm Setting (0~9)
     * |[23:20] |TENYEAR   |10-Year Calendar Digit of Alarm Setting (0~9)
     * @var RTC_T::LEAPYEAR
     * Offset: 0x24  RTC Leap Year Indicator Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |LEAPYEAR  |Leap Year Indication Register (Read Only)
     * |        |          |0 = This year is not a leap year.
     * |        |          |1 = This year is leap year.
     * @var RTC_T::INTEN
     * Offset: 0x28  RTC Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALMIEN    |Alarm Interrupt Enable Bit
     * |        |          |Set ALMIEN to 1 can also enable chip wake-up function when RTC alarm interrupt event is generated.
     * |        |          |0 = RTC Alarm interrupt Disabled.
     * |        |          |1 = RTC Alarm interrupt Enabled.
     * |[1]     |TICKIEN   |Time Tick Interrupt Enable Bit
     * |        |          |Set TICKIEN to 1 can also enable chip wake-up function when RTC tick interrupt event is generated.
     * |        |          |0 = RTC Time Tick interrupt Disabled.
     * |        |          |1 = RTC Time Tick interrupt Enabled.
     * @var RTC_T::INTSTS
     * Offset: 0x2C  RTC Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALMIF     |RTC Alarm Interrupt Flag
     * |        |          |0 = Alarm condition is not matched.
     * |        |          |1 = Alarm condition is matched.
     * |        |          |Note: Write 1 to clear this bit.
     * |[1]     |TICKIF    |RTC Time Tick Interrupt Flag
     * |        |          |0 = Tick condition does not occur.
     * |        |          |1 = Tick condition occur.
     * |        |          |Note: Write 1 to clear this bit.
     * @var RTC_T::TICK
     * Offset: 0x30  RTC Time Tick Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2:0]   |TICK      |Time Tick Register
     * |        |          |These bits are used to select RTC time tick period for Periodic Time Tick Interrupt request.
     * |        |          |000 = Time tick is 1 second.
     * |        |          |001 = Time tick is 1/2 second.
     * |        |          |010 = Time tick is 1/4 second.
     * |        |          |011 = Time tick is 1/8 second.
     * |        |          |100 = Time tick is 1/16 second.
     * |        |          |101 = Time tick is 1/32 second.
     * |        |          |110 = Time tick is 1/64 second.
     * |        |          |111 = Time tick is 1/128 second.
     * |        |          |Note: This register can be read back after the RTC register access enable bit RWENF (RTC_RWEN[16]) is active.
     * @var RTC_T::TAMSK
     * Offset: 0x34  RTC Time Alarm Mask Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |MSEC      |Mask 1-Sec Time Digit of Alarm Setting (0~9)
     * |[1]     |MTENSEC   |Mask 10-Sec Time Digit of Alarm Setting (0~5)
     * |[2]     |MMIN      |Mask 1-Min Time Digit of Alarm Setting (0~9)
     * |[3]     |MTENMIN   |Mask 10-Min Time Digit of Alarm Setting (0~5)
     * |[4]     |MHR       |Mask 1-Hour Time Digit of Alarm Setting (0~9)
     * |[5]     |MTENHR    |Mask 10-Hour Time Digit of Alarm Setting (0~2)
     * @var RTC_T::CAMSK
     * Offset: 0x38  RTC Calendar Alarm Mask Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |MDAY      |Mask 1-Day Calendar Digit of Alarm Setting (0~9)
     * |[1]     |MTENDAY   |Mask 10-Day Calendar Digit of Alarm Setting (0~3)
     * |[2]     |MMON      |Mask 1-Month Calendar Digit of Alarm Setting (0~9)
     * |[3]     |MTENMON   |Mask 10-Month Calendar Digit of Alarm Setting (0~1)
     * |[4]     |MYEAR     |Mask 1-Year Calendar Digit of Alarm Setting (0~9)
     * |[5]     |MTENYEAR  |Mask 10-Year Calendar Digit of Alarm Setting (0~9)
     * @var RTC_T::SPRCTL
     * Offset: 0x3C  RTC Spare Functional Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2]     |SPRRWEN   |Spare Register Enable Bit
     * |        |          |0 = Spare register is Disabled.
     * |        |          |1 = Spare register is Enabled.
     * |        |          |Note: When spare register is disabled, RTC_SPR0 ~ RTC_SPR19 cannot be accessed.
     * |[5]     |SPRCSTS   |SPR Clear Flag
     * |        |          |This bit indicates if the RTC_SPR0 ~RTC_SPR19 content is cleared when specify tamper event is detected.
     * |        |          |0 = Spare register content is not cleared.
     * |        |          |1 = Spare register content is cleared.
     * |        |          |Writes 1 to clear this bit.
     * |        |          |Note: This bit keep 1 when RTC_INTSTS[13:8] not equal zero.
     * @var RTC_T::SPR[20]
     * Offset: 0x40 ~ 0x8C  RTC Spare Register 0 ~ 19
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |SPARE     |Spare Register
     * |        |          |This field is used to store back-up information defined by user.
     * |        |          |This field will be cleared by hardware automatically once a tamper pin event is detected.
     * |        |          |Before storing back-up information in to RTC_SPRx register,
     * |        |          |user should check REWNF (RTC_RWEN[16]) is enabled.
     * @var RTC_T::LXTCTL
     * Offset: 0x100  RTC 32.768 kHz Oscillator Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2:1]   |GAIN      |Oscillator Gain Option
     * |        |          |User can select oscillator gain according to crystal external loading and operating temperature range
     * |        |          |The larger gain value corresponding to stronger driving capability and higher power consumption.
     * |        |          |00 = L0 mode.
     * |        |          |01 = L1 mode.
     * |        |          |10 = L2 mode.
     * |        |          |11 = L3 mode.
     * @var RTC_T::GPIOCTL0
     * Offset: 0x104  RTC GPIO Control 0 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |OPMODE0   |IO Operation Mode
     * |        |          |00 = PF.4 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.4 is output push pull mode.
     * |        |          |10 = PF.4 is open drain mode.
     * |        |          |11 = PF.4 is quasi-bidirectional mode with internal pull up.
     * |[2]     |DOUT0     |IO Output Data
     * |        |          |0 = PF.4 output low.
     * |        |          |1 = PF.4 output high.
     * |[3]     |CTLSEL0   |IO Pin State Backup Selection
     * |        |          |When low speed 32 kHz oscillator is disabled, PF.4 pin (X32KO pin) can be used as GPIO function
     * |        |          |User can program CTLSEL0 to decide PF.4 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL0 control register.
     * |        |          |0 = PF.4 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL0 = 1 when system power is turned off.
     * |        |          |1 = PF.4 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.4 pin function and I/O status are controlled by OPMODE0[1:0] and DOUT0 after CTLSEL0 is set to 1.
     * |        |          |Note: CTLSEL0 will automatically be set by hardware to 1 when system power is off and INIT[0] (RTC_INIT[0]) is 1.
     * |[5:4]   |PUSEL0    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.4 I/O pull-up or pull-down.
     * |        |          |00 = PF.4 pull-up and pull-up disable.
     * |        |          |01 = PF.4 pull-down enable.
     * |        |          |10 = PF.4 pull-up enable.
     * |        |          |11 = PF.4 pull-up and pull-up disable.
     * |        |          |Note:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE0 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE0 set as input tri-state mode.
     * |[9:8]   |OPMODE1   |IO Operation Mode
     * |        |          |00 = PF.5 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.5 is output push pull mode.
     * |        |          |10 = PF.5 is open drain mode.
     * |        |          |11 = PF.5 is quasi-bidirectional mode with internal pull up.
     * |[10]    |DOUT1     |IO Output Data
     * |        |          |0 = PF.5 output low.
     * |        |          |1 = PF.5 output high.
     * |[11]    |CTLSEL1   |IO Pin State Backup Selection
     * |        |          |When low speed 32 kHz oscillator is disabled, PF.5 pin (X32KI pin) can be used as GPIO function
     * |        |          |User can program CTLSEL1 to decide PF.5 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL0 control register.
     * |        |          |0 = PF.5 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL1 = 1 when system power is turned off.
     * |        |          |1 = PF.5 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.5 pin function and I/O status are controlled by OPMODE1[1:0] and DOUT1 after CTLSEL1 is set to 1.
     * |        |          |Note: CTLSEL1 will automatically be set by hardware to 1 when system power is off and INIT[0] (RTC_INIT[0]) is 1.
     * |[13:12] |PUSEL1    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.5 I/O pull-up or pull-down.
     * |        |          |00 = PF.5 pull-up and pull-up disable.
     * |        |          |01 = PF.5 pull-down enable.
     * |        |          |10 = PF.5 pull-up enable.
     * |        |          |11 = PF.5 pull-up and pull-up disable.
     * |        |          |Note:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE1 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE1 set as input tri-state mode.
     * |[17:16] |OPMODE2   |IO Operation Mode
     * |        |          |00 = PF.6 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.6 is output push pull mode.
     * |        |          |10 = PF.6 is open drain mode.
     * |        |          |11 = PF.6 is quasi-bidirectional mode with internal pull up.
     * |[18]    |DOUT2     |IO Output Data
     * |        |          |0 = PF.6 output low.
     * |        |          |1 = PF.6 output high.
     * |[19]    |CTLSEL2   |IO Pin State Backup Selection
     * |        |          |When TAMP0EN is disabled, PF.6 pin (TAMPER0 pin) can be used as GPIO function
     * |        |          |User can program CTLSEL2 to decide PF.6 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL0 control register.
     * |        |          |0 = PF.6 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL2 = 1 when system power is turned off.
     * |        |          |1 = PF.6 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.6 pin function and I/O status are controlled by OPMODE2[1:0] and DOUT2 after CTLSEL2 is set to 1.
     * |        |          |Note: CTLSEL2 will automatically be set by hardware to 1 when system power is off and INIT[0] (RTC_INIT[0]) is 1.
     * |[21:20] |PUSEL2    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.6 I/O pull-up or pull-down.
     * |        |          |00 = PF.6 pull-up and pull-up disable.
     * |        |          |01 = PF.6 pull-down enable.
     * |        |          |10 = PF.6 pull-up enable.
     * |        |          |11 = PF.6 pull-up and pull-up disable.
     * |        |          |Note1:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE2 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE2 set as input tri-state mode.
     * |[25:24] |OPMODE3   |IO Operation Mode
     * |        |          |00 = PF.7 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.7 is output push pull mode.
     * |        |          |10 = PF.7 is open drain mode.
     * |        |          |11 = PF.7 is quasi-bidirectional mode.
     * |[26]    |DOUT3     |IO Output Data
     * |        |          |0 = PF.7 output low.
     * |        |          |1 = PF.7 output high.
     * |[27]    |CTLSEL3   |IO Pin State Backup Selection
     * |        |          |When TAMP1EN is disabled, PF.7 pin (TAMPER1 pin) can be used as GPIO function
     * |        |          |User can program CTLSEL3 to decide PF.7 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL0 control register.
     * |        |          |0 = PF.7 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL3 = 1 when system power is turned off.
     * |        |          |1 = PF.7 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.7 pin function and I/O status are controlled by OPMODE3[1:0] and DOUT3 after CTLSEL3 is set to 1.
     * |        |          |Note: CTLSEL3 will automatically be set by hardware to 1 when system power is off and RTC_INIT[0] (RTC Active Status) is 1.
     * |[29:28] |PUSEL3    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.7 I/O pull-up or pull-down.
     * |        |          |00 = PF.7 pull-up and pull-down disable.
     * |        |          |01 = PF.7 pull-down enable.
     * |        |          |10 = PF.7 pull-up enable.
     * |        |          |11 = PF.7 pull-up and pull-down disable.
     * |        |          |Note:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE3 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE3 set as input tri-state mode.
     * @var RTC_T::GPIOCTL1
     * Offset: 0x108  RTC GPIO Control 1 Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |OPMODE4   |IO Operation Mode
     * |        |          |00 = PF.8 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.8 is output push pull mode.
     * |        |          |10 = PF.8 is open drain mode.
     * |        |          |11 = PF.8 is quasi-bidirectional mode.
     * |[2]     |DOUT4     |IO Output Data
     * |        |          |0 = PF.8 output low.
     * |        |          |1 = PF.8 output high.
     * |[3]     |CTLSEL4   |IO Pin State Backup Selection
     * |        |          |When TAMP2EN is disabled, PF.8 pin (TAMPER2 pin) can be used as GPIO function
     * |        |          |User can program CTLSEL4 to decide PF.8 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL1 control register.
     * |        |          |0 = PF.8 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL4 = 1 when system power is turned off.
     * |        |          |1 = PF.8 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.8 pin function and I/O status are controlled by OPMODE4[1:0] and DOUT4 after CTLSEL4 is set to 1.
     * |        |          |Note: CTLSEL4 will automatically be set by hardware to 1 when system power is off and RTC_INIT[0] (RTC Active Status) is 1.
     * |[5:4]   |PUSEL4    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.8 I/O pull-up or pull-down.
     * |        |          |00 = PF.8 pull-up and pull-down disable.
     * |        |          |01 = PF.8 pull-down enable.
     * |        |          |10 = PF.8 pull-up enable.
     * |        |          |11 = PF.8 pull-up and pull-down disable.
     * |        |          |Note:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE4 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE4 set as input tri-state mode.
     * |[9:8]   |OPMODE5   |IO Operation Mode
     * |        |          |00 = PF.9 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.9 is output push pull mode.
     * |        |          |10 = PF.9 is open drain mode.
     * |        |          |11 = PF.9 is quasi-bidirectional mode.
     * |[10]    |DOUT5     |IO Output Data
     * |        |          |0 = PF.9 output low.
     * |        |          |1 = PF.9 output high.
     * |[11]    |CTLSEL5   |IO Pin State Backup Selection
     * |        |          |When TAMP3EN is disabled, PF.9 pin (TAMPER3 pin) can be used as GPIO function
     * |        |          |User can program CTLSEL5 to decide PF.9 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL1 control register.
     * |        |          |0 = PF.9 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL5 = 1 when system power is turned off.
     * |        |          |1 = PF.9 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.9 pin function and I/O status are controlled by OPMODE5[1:0] and DOUT5 after CTLSEL5 is set to 1.
     * |        |          |Note: CTLSEL5 will automatically be set by hardware to 1 when system power is off and INIT[0] (RTC_INIT[0]) is 1.
     * |[13:12] |PUSEL5    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.9 I/O pull-up or pull-down.
     * |        |          |00 = PF.9 pull-up and pull-down disable.
     * |        |          |01 = PF.9 pull-down enable.
     * |        |          |10 = PF.9 pull-up enable.
     * |        |          |11 = PF.9 pull-up and pull-down disable.
     * |        |          |Note:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE5 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE5 set as input tri-state mode.
     * |[17:16] |OPMODE6   |IO Operation Mode
     * |        |          |00 = PF.10 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.10 is output push pull mode.
     * |        |          |10 = PF.10 is open drain mode.
     * |        |          |11 = PF.10 is quasi-bidirectional mode.
     * |[18]    |DOUT6     |IO Output Data
     * |        |          |0 = PF.10 output low.
     * |        |          |1 = PF.10 output high.
     * |[19]    |CTLSEL6   |IO Pin State Backup Selection
     * |        |          |When TAMP4EN is disabled, PF.10 pin (TAMPER4 pin) can be used as GPIO function
     * |        |          |User can program CTLSEL6 to decide PF.10 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL1 control register.
     * |        |          |0 = PF.10 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL6 = 1 when system power is turned off.
     * |        |          |1 = PF.10 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.10 pin function and I/O status are controlled by OPMODE6[1:0] and DOUT6 after CTLSEL6 is set to 1.
     * |        |          |Note: CTLSEL6 will automatically be set by hardware to 1 when system power is off and INIT[0] (RTC_INIT[0]) is 1.
     * |[21:20] |PUSEL6    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.10 I/O pull-up or pull-down.
     * |        |          |00 = PF.10 pull-up and pull-down disable.
     * |        |          |01 = PF.10 pull-down enable.
     * |        |          |10 = PF.10 pull-up enable.
     * |        |          |11 = PF.10 pull-up and pull-down disable.
     * |        |          |Note:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE6 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE6 set as input tri-state mode.
     * |[25:24] |OPMODE7   |IO Operation Mode
     * |        |          |00 = PF.11 is input only mode, without pull-up resistor.
     * |        |          |01 = PF.11 is output push pull mode.
     * |        |          |10 = PF.11 is open drain mode.
     * |        |          |11 = PF.11 is quasi-bidirectional mode.
     * |[26]    |DOUT7     |IO Output Data
     * |        |          |0 = PF.11 output low.
     * |        |          |1 = PF.11 output high.
     * |[27]    |CTLSEL7   |IO Pin State Backup Selection
     * |        |          |When TAMP5EN is disabled, PF.11 pin (TAMPER5 pin) can be used as GPIO function
     * |        |          |User can program CTLSEL7 to decide PF.11 I/O function is controlled by system power domain GPIO module or
     * |        |          |VBAT power domain RTC_GPIOCTL1 control register.
     * |        |          |0 = PF.11 pin I/O function is controlled by GPIO module.
     * |        |          |Hardware auto becomes CTLSEL7 = 1 when system power is turned off.
     * |        |          |1 = PF.11 pin I/O function is controlled by VBAT power domain.
     * |        |          |PF.11 pin function and I/O status are controlled by OPMODE7[1:0] and DOUT7 after CTLSEL7 is set to 1.
     * |        |          |Note: CTLSEL7 will automatically be set by hardware to 1 when system power is off and INIT[0] (RTC_INIT[0]) is 1.
     * |[29:28] |PUSEL7    |IO Pull-up and Pull-down Enable
     * |        |          |Determine PF.11 I/O pull-up or pull-down.
     * |        |          |00 = PF.11 pull-up and pull-down disable.
     * |        |          |01 = PF.11 pull-down enable.
     * |        |          |10 = PF.11 pull-up enable.
     * |        |          |11 = PF.11 pull-up and pull-down disable.
     * |        |          |Note:
     * |        |          |Basically, the pull-up control and pull-down control has following behavior limitation.
     * |        |          |The independent pull-up control register only valid when OPMODE7 set as input tri-state and open-drain mode.
     * |        |          |The independent pull-down control register only valid when OPMODE7 set as input tri-state mode.
      */
    __IO uint32_t INIT;                  /*!< [0x0000] RTC Initiation Register                                          */
    __IO uint32_t RWEN;                  /*!< [0x0004] RTC Access Enable Register                                       */
    __IO uint32_t FREQADJ;               /*!< [0x0008] RTC Frequency Compensation Register                              */
    __IO uint32_t TIME;                  /*!< [0x000c] RTC Time Loading Register                                        */
    __IO uint32_t CAL;                   /*!< [0x0010] RTC Calendar Loading Register                                    */
    __IO uint32_t CLKFMT;                /*!< [0x0014] RTC Time Scale Selection Register                                */
    __IO uint32_t WEEKDAY;               /*!< [0x0018] RTC Day of the Week Register                                     */
    __IO uint32_t TALM;                  /*!< [0x001c] RTC Time Alarm Register                                          */
    __IO uint32_t CALM;                  /*!< [0x0020] RTC Calendar Alarm Register                                      */
    __I  uint32_t LEAPYEAR;              /*!< [0x0024] RTC Leap Year Indicator Register                                 */
    __IO uint32_t INTEN;                 /*!< [0x0028] RTC Interrupt Enable Register                                    */
    __IO uint32_t INTSTS;                /*!< [0x002c] RTC Interrupt Status Register                                    */
    __IO uint32_t TICK;                  /*!< [0x0030] RTC Time Tick Register                                           */
    __IO uint32_t TAMSK;                 /*!< [0x0034] RTC Time Alarm Mask Register                                     */
    __IO uint32_t CAMSK;                 /*!< [0x0038] RTC Calendar Alarm Mask Register                                 */
    /// @cond HIDDEN_SYMBOLS
    __I  uint32_t RESERVE0[28];
    /// @endcond //HIDDEN_SYMBOLS
    __IO uint32_t LXTCTL;                /*!< [0x0100] RTC 32.768 kHz Oscillator Control Register                       */
    __IO uint32_t GPIOCTL0;              /*!< [0x0104] RTC GPIO Control 0 Register                                      */
    __IO uint32_t GPIOCTL1;              /*!< [0x0108] RTC GPIO Control 1 Register                                      */

} RTC_T;

/**
    @addtogroup RTC_CONST RTC Bit Field Definition
    Constant Definitions for RTC Controller
@{ */

#define RTC_INIT_ACTIVE_Pos         (0)                                               /*!< RTC_T::INIT: INIT_ACTIVE Position      */
#define RTC_INIT_ACTIVE_Msk         (0x1ul << RTC_INIT_ACTIVE_Pos)               /*!< RTC_T::INIT: INIT_ACTIVE Mask          */

#define RTC_INIT_INIT_Pos                (1)                                               /*!< RTC_T::INIT: INIT Position             */
#define RTC_INIT_INIT_Msk                (0x7ffffffful << RTC_INIT_INIT_Pos)               /*!< RTC_T::INIT: INIT Mask                 */

#define RTC_RWEN_RWENF_Pos               (16)                                              /*!< RTC_T::RWEN: RWENF Position            */
#define RTC_RWEN_RWENF_Msk               (0x1ul << RTC_RWEN_RWENF_Pos)                     /*!< RTC_T::RWEN: RWENF Mask                */

#define RTC_RWEN_RTCBUSY_Pos             (24)                                              /*!< RTC_T::RWEN: RTCBUSY Position          */
#define RTC_RWEN_RTCBUSY_Msk             (0x1ul << RTC_RWEN_RTCBUSY_Pos)                   /*!< RTC_T::RWEN: RTCBUSY Mask              */

#define RTC_FREQADJ_FREQADJ_Pos          (0)                                               /*!< RTC_T::FREQADJ: FREQADJ Position       */
#define RTC_FREQADJ_FREQADJ_Msk          (0x3ffffful << RTC_FREQADJ_FREQADJ_Pos)           /*!< RTC_T::FREQADJ: FREQADJ Mask           */

#define RTC_FREQADJ_FRACTION_Pos         (0)                                               /*!< RTC_T::FREQADJ: FRACTION Position      */
#define RTC_FREQADJ_FRACTION_Msk         (0x3ful << RTC_FREQADJ_FRACTION_Pos)              /*!< RTC_T::FREQADJ: FRACTION Mask          */

#define RTC_FREQADJ_INTEGER_Pos          (8)                                               /*!< RTC_T::FREQADJ: INTEGER Position       */
#define RTC_FREQADJ_INTEGER_Msk          (0x1ful << RTC_FREQADJ_INTEGER_Pos)               /*!< RTC_T::FREQADJ: INTEGER Mask           */

#define RTC_FREQADJ_FCR_BUSY_Pos         (31)                                              /*!< RTC_T::FREQADJ: FCR_BUSY Position      */
#define RTC_FREQADJ_FCR_BUSY_Msk         (0x1ul << RTC_FREQADJ_FCR_BUSY_Pos)               /*!< RTC_T::FREQADJ: FCR_BUSY Mask          */

#define RTC_TIME_SEC_Pos                 (0)                                               /*!< RTC_T::TIME: SEC Position              */
#define RTC_TIME_SEC_Msk                 (0xful << RTC_TIME_SEC_Pos)                       /*!< RTC_T::TIME: SEC Mask                  */

#define RTC_TIME_TENSEC_Pos              (4)                                               /*!< RTC_T::TIME: TENSEC Position           */
#define RTC_TIME_TENSEC_Msk              (0x7ul << RTC_TIME_TENSEC_Pos)                    /*!< RTC_T::TIME: TENSEC Mask               */

#define RTC_TIME_MIN_Pos                 (8)                                               /*!< RTC_T::TIME: MIN Position              */
#define RTC_TIME_MIN_Msk                 (0xful << RTC_TIME_MIN_Pos)                       /*!< RTC_T::TIME: MIN Mask                  */

#define RTC_TIME_TENMIN_Pos              (12)                                              /*!< RTC_T::TIME: TENMIN Position           */
#define RTC_TIME_TENMIN_Msk              (0x7ul << RTC_TIME_TENMIN_Pos)                    /*!< RTC_T::TIME: TENMIN Mask               */

#define RTC_TIME_HR_Pos                  (16)                                              /*!< RTC_T::TIME: HR Position               */
#define RTC_TIME_HR_Msk                  (0xful << RTC_TIME_HR_Pos)                        /*!< RTC_T::TIME: HR Mask                   */

#define RTC_TIME_TENHR_Pos               (20)                                              /*!< RTC_T::TIME: TENHR Position            */
#define RTC_TIME_TENHR_Msk               (0x3ul << RTC_TIME_TENHR_Pos)                     /*!< RTC_T::TIME: TENHR Mask                */

#define RTC_CAL_DAY_Pos                  (0)                                               /*!< RTC_T::CAL: DAY Position               */
#define RTC_CAL_DAY_Msk                  (0xful << RTC_CAL_DAY_Pos)                        /*!< RTC_T::CAL: DAY Mask                   */

#define RTC_CAL_TENDAY_Pos               (4)                                               /*!< RTC_T::CAL: TENDAY Position            */
#define RTC_CAL_TENDAY_Msk               (0x3ul << RTC_CAL_TENDAY_Pos)                     /*!< RTC_T::CAL: TENDAY Mask                */

#define RTC_CAL_MON_Pos                  (8)                                               /*!< RTC_T::CAL: MON Position               */
#define RTC_CAL_MON_Msk                  (0xful << RTC_CAL_MON_Pos)                        /*!< RTC_T::CAL: MON Mask                   */

#define RTC_CAL_TENMON_Pos               (12)                                              /*!< RTC_T::CAL: TENMON Position            */
#define RTC_CAL_TENMON_Msk               (0x1ul << RTC_CAL_TENMON_Pos)                     /*!< RTC_T::CAL: TENMON Mask                */

#define RTC_CAL_YEAR_Pos                 (16)                                              /*!< RTC_T::CAL: YEAR Position              */
#define RTC_CAL_YEAR_Msk                 (0xful << RTC_CAL_YEAR_Pos)                       /*!< RTC_T::CAL: YEAR Mask                  */

#define RTC_CAL_TENYEAR_Pos              (20)                                              /*!< RTC_T::CAL: TENYEAR Position           */
#define RTC_CAL_TENYEAR_Msk              (0xful << RTC_CAL_TENYEAR_Pos)                    /*!< RTC_T::CAL: TENYEAR Mask               */

#define RTC_CLKFMT_24HEN_Pos             (0)                                               /*!< RTC_T::CLKFMT: 24HEN Position          */
#define RTC_CLKFMT_24HEN_Msk             (0x1ul << RTC_CLKFMT_24HEN_Pos)                   /*!< RTC_T::CLKFMT: 24HEN Mask              */

#define RTC_WEEKDAY_WEEKDAY_Pos          (0)                                               /*!< RTC_T::WEEKDAY: WEEKDAY Position       */
#define RTC_WEEKDAY_WEEKDAY_Msk          (0x7ul << RTC_WEEKDAY_WEEKDAY_Pos)                /*!< RTC_T::WEEKDAY: WEEKDAY Mask           */

#define RTC_TALM_SEC_Pos                 (0)                                               /*!< RTC_T::TALM: SEC Position              */
#define RTC_TALM_SEC_Msk                 (0xful << RTC_TALM_SEC_Pos)                       /*!< RTC_T::TALM: SEC Mask                  */

#define RTC_TALM_TENSEC_Pos              (4)                                               /*!< RTC_T::TALM: TENSEC Position           */
#define RTC_TALM_TENSEC_Msk              (0x7ul << RTC_TALM_TENSEC_Pos)                    /*!< RTC_T::TALM: TENSEC Mask               */

#define RTC_TALM_MIN_Pos                 (8)                                               /*!< RTC_T::TALM: MIN Position              */
#define RTC_TALM_MIN_Msk                 (0xful << RTC_TALM_MIN_Pos)                       /*!< RTC_T::TALM: MIN Mask                  */

#define RTC_TALM_TENMIN_Pos              (12)                                              /*!< RTC_T::TALM: TENMIN Position           */
#define RTC_TALM_TENMIN_Msk              (0x7ul << RTC_TALM_TENMIN_Pos)                    /*!< RTC_T::TALM: TENMIN Mask               */

#define RTC_TALM_HR_Pos                  (16)                                              /*!< RTC_T::TALM: HR Position               */
#define RTC_TALM_HR_Msk                  (0xful << RTC_TALM_HR_Pos)                        /*!< RTC_T::TALM: HR Mask                   */

#define RTC_TALM_TENHR_Pos               (20)                                              /*!< RTC_T::TALM: TENHR Position            */
#define RTC_TALM_TENHR_Msk               (0x3ul << RTC_TALM_TENHR_Pos)                     /*!< RTC_T::TALM: TENHR Mask                */

#define RTC_CALM_DAY_Pos                 (0)                                               /*!< RTC_T::CALM: DAY Position              */
#define RTC_CALM_DAY_Msk                 (0xful << RTC_CALM_DAY_Pos)                       /*!< RTC_T::CALM: DAY Mask                  */

#define RTC_CALM_TENDAY_Pos              (4)                                               /*!< RTC_T::CALM: TENDAY Position           */
#define RTC_CALM_TENDAY_Msk              (0x3ul << RTC_CALM_TENDAY_Pos)                    /*!< RTC_T::CALM: TENDAY Mask               */

#define RTC_CALM_MON_Pos                 (8)                                               /*!< RTC_T::CALM: MON Position              */
#define RTC_CALM_MON_Msk                 (0xful << RTC_CALM_MON_Pos)                       /*!< RTC_T::CALM: MON Mask                  */

#define RTC_CALM_TENMON_Pos              (12)                                              /*!< RTC_T::CALM: TENMON Position           */
#define RTC_CALM_TENMON_Msk              (0x1ul << RTC_CALM_TENMON_Pos)                    /*!< RTC_T::CALM: TENMON Mask               */

#define RTC_CALM_YEAR_Pos                (16)                                              /*!< RTC_T::CALM: YEAR Position             */
#define RTC_CALM_YEAR_Msk                (0xful << RTC_CALM_YEAR_Pos)                      /*!< RTC_T::CALM: YEAR Mask                 */

#define RTC_CALM_TENYEAR_Pos             (20)                                              /*!< RTC_T::CALM: TENYEAR Position          */
#define RTC_CALM_TENYEAR_Msk             (0xful << RTC_CALM_TENYEAR_Pos)                   /*!< RTC_T::CALM: TENYEAR Mask              */

#define RTC_LEAPYEAR_LEAPYEAR_Pos        (0)                                               /*!< RTC_T::LEAPYEAR: LEAPYEAR Position     */
#define RTC_LEAPYEAR_LEAPYEAR_Msk        (0x1ul << RTC_LEAPYEAR_LEAPYEAR_Pos)              /*!< RTC_T::LEAPYEAR: LEAPYEAR Mask         */

#define RTC_INTEN_ALMIEN_Pos             (0)                                               /*!< RTC_T::INTEN: ALMIEN Position          */
#define RTC_INTEN_ALMIEN_Msk             (0x1ul << RTC_INTEN_ALMIEN_Pos)                   /*!< RTC_T::INTEN: ALMIEN Mask              */

#define RTC_INTEN_TICKIEN_Pos            (1)                                               /*!< RTC_T::INTEN: TICKIEN Position         */
#define RTC_INTEN_TICKIEN_Msk            (0x1ul << RTC_INTEN_TICKIEN_Pos)                  /*!< RTC_T::INTEN: TICKIEN Mask             */

#define RTC_INTSTS_ALMIF_Pos             (0)                                               /*!< RTC_T::INTSTS: ALMIF Position          */
#define RTC_INTSTS_ALMIF_Msk             (0x1ul << RTC_INTSTS_ALMIF_Pos)                   /*!< RTC_T::INTSTS: ALMIF Mask              */

#define RTC_INTSTS_TICKIF_Pos            (1)                                               /*!< RTC_T::INTSTS: TICKIF Position         */
#define RTC_INTSTS_TICKIF_Msk            (0x1ul << RTC_INTSTS_TICKIF_Pos)                  /*!< RTC_T::INTSTS: TICKIF Mask             */

#define RTC_TICK_TICK_Pos                (0)                                               /*!< RTC_T::TICK: TICK Position             */
#define RTC_TICK_TICK_Msk                (0x7ul << RTC_TICK_TICK_Pos)                      /*!< RTC_T::TICK: TICK Mask                 */

#define RTC_TAMSK_MSEC_Pos               (0)                                               /*!< RTC_T::TAMSK: MSEC Position            */
#define RTC_TAMSK_MSEC_Msk               (0x1ul << RTC_TAMSK_MSEC_Pos)                     /*!< RTC_T::TAMSK: MSEC Mask                */

#define RTC_TAMSK_MTENSEC_Pos            (1)                                               /*!< RTC_T::TAMSK: MTENSEC Position         */
#define RTC_TAMSK_MTENSEC_Msk            (0x1ul << RTC_TAMSK_MTENSEC_Pos)                  /*!< RTC_T::TAMSK: MTENSEC Mask             */

#define RTC_TAMSK_MMIN_Pos               (2)                                               /*!< RTC_T::TAMSK: MMIN Position            */
#define RTC_TAMSK_MMIN_Msk               (0x1ul << RTC_TAMSK_MMIN_Pos)                     /*!< RTC_T::TAMSK: MMIN Mask                */

#define RTC_TAMSK_MTENMIN_Pos            (3)                                               /*!< RTC_T::TAMSK: MTENMIN Position         */
#define RTC_TAMSK_MTENMIN_Msk            (0x1ul << RTC_TAMSK_MTENMIN_Pos)                  /*!< RTC_T::TAMSK: MTENMIN Mask             */

#define RTC_TAMSK_MHR_Pos                (4)                                               /*!< RTC_T::TAMSK: MHR Position             */
#define RTC_TAMSK_MHR_Msk                (0x1ul << RTC_TAMSK_MHR_Pos)                      /*!< RTC_T::TAMSK: MHR Mask                 */

#define RTC_TAMSK_MTENHR_Pos             (5)                                               /*!< RTC_T::TAMSK: MTENHR Position          */
#define RTC_TAMSK_MTENHR_Msk             (0x1ul << RTC_TAMSK_MTENHR_Pos)                   /*!< RTC_T::TAMSK: MTENHR Mask              */

#define RTC_CAMSK_MDAY_Pos               (0)                                               /*!< RTC_T::CAMSK: MDAY Position            */
#define RTC_CAMSK_MDAY_Msk               (0x1ul << RTC_CAMSK_MDAY_Pos)                     /*!< RTC_T::CAMSK: MDAY Mask                */

#define RTC_CAMSK_MTENDAY_Pos            (1)                                               /*!< RTC_T::CAMSK: MTENDAY Position         */
#define RTC_CAMSK_MTENDAY_Msk            (0x1ul << RTC_CAMSK_MTENDAY_Pos)                  /*!< RTC_T::CAMSK: MTENDAY Mask             */

#define RTC_CAMSK_MMON_Pos               (2)                                               /*!< RTC_T::CAMSK: MMON Position            */
#define RTC_CAMSK_MMON_Msk               (0x1ul << RTC_CAMSK_MMON_Pos)                     /*!< RTC_T::CAMSK: MMON Mask                */

#define RTC_CAMSK_MTENMON_Pos            (3)                                               /*!< RTC_T::CAMSK: MTENMON Position         */
#define RTC_CAMSK_MTENMON_Msk            (0x1ul << RTC_CAMSK_MTENMON_Pos)                  /*!< RTC_T::CAMSK: MTENMON Mask             */

#define RTC_CAMSK_MYEAR_Pos              (4)                                               /*!< RTC_T::CAMSK: MYEAR Position           */
#define RTC_CAMSK_MYEAR_Msk              (0x1ul << RTC_CAMSK_MYEAR_Pos)                    /*!< RTC_T::CAMSK: MYEAR Mask               */

#define RTC_CAMSK_MTENYEAR_Pos           (5)                                               /*!< RTC_T::CAMSK: MTENYEAR Position        */
#define RTC_CAMSK_MTENYEAR_Msk           (0x1ul << RTC_CAMSK_MTENYEAR_Pos)                 /*!< RTC_T::CAMSK: MTENYEAR Mask            */

#define RTC_LXTCTL_GAIN_Pos              (1)                                               /*!< RTC_T::LXTCTL: GAIN Position           */
#define RTC_LXTCTL_GAIN_Msk              (0x3ul << RTC_LXTCTL_GAIN_Pos)                    /*!< RTC_T::LXTCTL: GAIN Mask               */

#define RTC_GPIOCTL0_OPMODE0_Pos         (0)                                               /*!< RTC_T::GPIOCTL0: OPMODE0 Position      */
#define RTC_GPIOCTL0_OPMODE0_Msk         (0x3ul << RTC_GPIOCTL0_OPMODE0_Pos)               /*!< RTC_T::GPIOCTL0: OPMODE0 Mask          */

#define RTC_GPIOCTL0_DOUT0_Pos           (2)                                               /*!< RTC_T::GPIOCTL0: DOUT0 Position        */
#define RTC_GPIOCTL0_DOUT0_Msk           (0x1ul << RTC_GPIOCTL0_DOUT0_Pos)                 /*!< RTC_T::GPIOCTL0: DOUT0 Mask            */

#define RTC_GPIOCTL0_CTLSEL0_Pos         (3)                                               /*!< RTC_T::GPIOCTL0: CTLSEL0 Position      */
#define RTC_GPIOCTL0_CTLSEL0_Msk         (0x1ul << RTC_GPIOCTL0_CTLSEL0_Pos)               /*!< RTC_T::GPIOCTL0: CTLSEL0 Mask          */

#define RTC_GPIOCTL0_PUSEL0_Pos          (4)                                               /*!< RTC_T::GPIOCTL0: PUSEL0 Position       */
#define RTC_GPIOCTL0_PUSEL0_Msk          (0x3ul << RTC_GPIOCTL0_PUSEL0_Pos)                /*!< RTC_T::GPIOCTL0: PUSEL0 Mask           */

#define RTC_GPIOCTL0_OPMODE1_Pos         (8)                                               /*!< RTC_T::GPIOCTL0: OPMODE1 Position      */
#define RTC_GPIOCTL0_OPMODE1_Msk         (0x3ul << RTC_GPIOCTL0_OPMODE1_Pos)               /*!< RTC_T::GPIOCTL0: OPMODE1 Mask          */

#define RTC_GPIOCTL0_DOUT1_Pos           (10)                                              /*!< RTC_T::GPIOCTL0: DOUT1 Position        */
#define RTC_GPIOCTL0_DOUT1_Msk           (0x1ul << RTC_GPIOCTL0_DOUT1_Pos)                 /*!< RTC_T::GPIOCTL0: DOUT1 Mask            */

#define RTC_GPIOCTL0_CTLSEL1_Pos         (11)                                              /*!< RTC_T::GPIOCTL0: CTLSEL1 Position      */
#define RTC_GPIOCTL0_CTLSEL1_Msk         (0x1ul << RTC_GPIOCTL0_CTLSEL1_Pos)               /*!< RTC_T::GPIOCTL0: CTLSEL1 Mask          */

#define RTC_GPIOCTL0_PUSEL1_Pos          (12)                                              /*!< RTC_T::GPIOCTL0: PUSEL1 Position       */
#define RTC_GPIOCTL0_PUSEL1_Msk          (0x3ul << RTC_GPIOCTL0_PUSEL1_Pos)                /*!< RTC_T::GPIOCTL0: PUSEL1 Mask           */

#define RTC_GPIOCTL0_OPMODE2_Pos         (16)                                              /*!< RTC_T::GPIOCTL0: OPMODE2 Position      */
#define RTC_GPIOCTL0_OPMODE2_Msk         (0x3ul << RTC_GPIOCTL0_OPMODE2_Pos)               /*!< RTC_T::GPIOCTL0: OPMODE2 Mask          */

#define RTC_GPIOCTL0_DOUT2_Pos           (18)                                              /*!< RTC_T::GPIOCTL0: DOUT2 Position        */
#define RTC_GPIOCTL0_DOUT2_Msk           (0x1ul << RTC_GPIOCTL0_DOUT2_Pos)                 /*!< RTC_T::GPIOCTL0: DOUT2 Mask            */

#define RTC_GPIOCTL0_CTLSEL2_Pos         (19)                                              /*!< RTC_T::GPIOCTL0: CTLSEL2 Position      */
#define RTC_GPIOCTL0_CTLSEL2_Msk         (0x1ul << RTC_GPIOCTL0_CTLSEL2_Pos)               /*!< RTC_T::GPIOCTL0: CTLSEL2 Mask          */

#define RTC_GPIOCTL0_PUSEL2_Pos          (20)                                              /*!< RTC_T::GPIOCTL0: PUSEL2 Position       */
#define RTC_GPIOCTL0_PUSEL2_Msk          (0x3ul << RTC_GPIOCTL0_PUSEL2_Pos)                /*!< RTC_T::GPIOCTL0: PUSEL2 Mask           */

#define RTC_GPIOCTL0_OPMODE3_Pos         (24)                                              /*!< RTC_T::GPIOCTL0: OPMODE3 Position      */
#define RTC_GPIOCTL0_OPMODE3_Msk         (0x3ul << RTC_GPIOCTL0_OPMODE3_Pos)               /*!< RTC_T::GPIOCTL0: OPMODE3 Mask          */

#define RTC_GPIOCTL0_DOUT3_Pos           (26)                                              /*!< RTC_T::GPIOCTL0: DOUT3 Position        */
#define RTC_GPIOCTL0_DOUT3_Msk           (0x1ul << RTC_GPIOCTL0_DOUT3_Pos)                 /*!< RTC_T::GPIOCTL0: DOUT3 Mask            */

#define RTC_GPIOCTL0_CTLSEL3_Pos         (27)                                              /*!< RTC_T::GPIOCTL0: CTLSEL3 Position      */
#define RTC_GPIOCTL0_CTLSEL3_Msk         (0x1ul << RTC_GPIOCTL0_CTLSEL3_Pos)               /*!< RTC_T::GPIOCTL0: CTLSEL3 Mask          */

#define RTC_GPIOCTL0_PUSEL3_Pos          (28)                                              /*!< RTC_T::GPIOCTL0: PUSEL3 Position       */
#define RTC_GPIOCTL0_PUSEL3_Msk          (0x3ul << RTC_GPIOCTL0_PUSEL3_Pos)                /*!< RTC_T::GPIOCTL0: PUSEL3 Mask           */

#define RTC_GPIOCTL1_OPMODE4_Pos         (0)                                               /*!< RTC_T::GPIOCTL1: OPMODE4 Position      */
#define RTC_GPIOCTL1_OPMODE4_Msk         (0x3ul << RTC_GPIOCTL1_OPMODE4_Pos)               /*!< RTC_T::GPIOCTL1: OPMODE4 Mask          */

#define RTC_GPIOCTL1_DOUT4_Pos           (2)                                               /*!< RTC_T::GPIOCTL1: DOUT4 Position        */
#define RTC_GPIOCTL1_DOUT4_Msk           (0x1ul << RTC_GPIOCTL1_DOUT4_Pos)                 /*!< RTC_T::GPIOCTL1: DOUT4 Mask            */

#define RTC_GPIOCTL1_CTLSEL4_Pos         (3)                                               /*!< RTC_T::GPIOCTL1: CTLSEL4 Position      */
#define RTC_GPIOCTL1_CTLSEL4_Msk         (0x1ul << RTC_GPIOCTL1_CTLSEL4_Pos)               /*!< RTC_T::GPIOCTL1: CTLSEL4 Mask          */

#define RTC_GPIOCTL1_PUSEL4_Pos          (4)                                               /*!< RTC_T::GPIOCTL1: PUSEL4 Position       */
#define RTC_GPIOCTL1_PUSEL4_Msk          (0x3ul << RTC_GPIOCTL1_PUSEL4_Pos)                /*!< RTC_T::GPIOCTL1: PUSEL4 Mask           */

#define RTC_GPIOCTL1_OPMODE5_Pos         (8)                                               /*!< RTC_T::GPIOCTL1: OPMODE5 Position      */
#define RTC_GPIOCTL1_OPMODE5_Msk         (0x3ul << RTC_GPIOCTL1_OPMODE5_Pos)               /*!< RTC_T::GPIOCTL1: OPMODE5 Mask          */

#define RTC_GPIOCTL1_DOUT5_Pos           (10)                                              /*!< RTC_T::GPIOCTL1: DOUT5 Position        */
#define RTC_GPIOCTL1_DOUT5_Msk           (0x1ul << RTC_GPIOCTL1_DOUT5_Pos)                 /*!< RTC_T::GPIOCTL1: DOUT5 Mask            */

#define RTC_GPIOCTL1_CTLSEL5_Pos         (11)                                              /*!< RTC_T::GPIOCTL1: CTLSEL5 Position      */
#define RTC_GPIOCTL1_CTLSEL5_Msk         (0x1ul << RTC_GPIOCTL1_CTLSEL5_Pos)               /*!< RTC_T::GPIOCTL1: CTLSEL5 Mask          */

#define RTC_GPIOCTL1_PUSEL5_Pos          (12)                                              /*!< RTC_T::GPIOCTL1: PUSEL5 Position       */
#define RTC_GPIOCTL1_PUSEL5_Msk          (0x3ul << RTC_GPIOCTL1_PUSEL5_Pos)                /*!< RTC_T::GPIOCTL1: PUSEL5 Mask           */

#define RTC_GPIOCTL1_OPMODE6_Pos         (16)                                              /*!< RTC_T::GPIOCTL1: OPMODE6 Position      */
#define RTC_GPIOCTL1_OPMODE6_Msk         (0x3ul << RTC_GPIOCTL1_OPMODE6_Pos)               /*!< RTC_T::GPIOCTL1: OPMODE6 Mask          */

#define RTC_GPIOCTL1_DOUT6_Pos           (18)                                              /*!< RTC_T::GPIOCTL1: DOUT6 Position        */
#define RTC_GPIOCTL1_DOUT6_Msk           (0x1ul << RTC_GPIOCTL1_DOUT6_Pos)                 /*!< RTC_T::GPIOCTL1: DOUT6 Mask            */

#define RTC_GPIOCTL1_CTLSEL6_Pos         (19)                                              /*!< RTC_T::GPIOCTL1: CTLSEL6 Position      */
#define RTC_GPIOCTL1_CTLSEL6_Msk         (0x1ul << RTC_GPIOCTL1_CTLSEL6_Pos)               /*!< RTC_T::GPIOCTL1: CTLSEL6 Mask          */

#define RTC_GPIOCTL1_PUSEL6_Pos          (20)                                              /*!< RTC_T::GPIOCTL1: PUSEL6 Position       */
#define RTC_GPIOCTL1_PUSEL6_Msk          (0x3ul << RTC_GPIOCTL1_PUSEL6_Pos)                /*!< RTC_T::GPIOCTL1: PUSEL6 Mask           */

#define RTC_GPIOCTL1_OPMODE7_Pos         (24)                                              /*!< RTC_T::GPIOCTL1: OPMODE7 Position      */
#define RTC_GPIOCTL1_OPMODE7_Msk         (0x3ul << RTC_GPIOCTL1_OPMODE7_Pos)               /*!< RTC_T::GPIOCTL1: OPMODE7 Mask          */

#define RTC_GPIOCTL1_DOUT7_Pos           (26)                                              /*!< RTC_T::GPIOCTL1: DOUT7 Position        */
#define RTC_GPIOCTL1_DOUT7_Msk           (0x1ul << RTC_GPIOCTL1_DOUT7_Pos)                 /*!< RTC_T::GPIOCTL1: DOUT7 Mask            */

#define RTC_GPIOCTL1_CTLSEL7_Pos         (27)                                              /*!< RTC_T::GPIOCTL1: CTLSEL7 Position      */
#define RTC_GPIOCTL1_CTLSEL7_Msk         (0x1ul << RTC_GPIOCTL1_CTLSEL7_Pos)               /*!< RTC_T::GPIOCTL1: CTLSEL7 Mask          */

#define RTC_GPIOCTL1_PUSEL7_Pos          (28)                                              /*!< RTC_T::GPIOCTL1: PUSEL7 Position       */
#define RTC_GPIOCTL1_PUSEL7_Msk          (0x3ul << RTC_GPIOCTL1_PUSEL7_Pos)                /*!< RTC_T::GPIOCTL1: PUSEL7 Mask           */

/**@}*/ /* RTC_CONST */
/**@}*/ /* end of RTC register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __RTC_REG_H__ */
