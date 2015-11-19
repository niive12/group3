--------------------------------------------------------------------------------
--
--   FileName:         i2c_master.vhd
--   Dependencies:     none
--   Design Software:  Quartus II 64-bit Version 13.1 Build 162 SJ Full Version
--
--   HDL CODE IS PROVIDED "AS IS."  DIGI-KEY EXPRESSLY DISCLAIMS ANY
--   WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
--   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
--   PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL DIGI-KEY
--   BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
--   DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF
--   PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
--   BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
--   ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS.
--
--   Version History
--   Version 1.0 11/01/2012 Scott Larson
--     Initial Public Release
--   Version 2.0 06/20/2014 Scott Larson
--     Added ability to interface with different slaves in the same transaction
--     Corrected ack_error bug where ack_error went 'Z' instead of '1' on error
--     Corrected timing of when ack_error signal clears
--   Version 2.1 10/21/2014 Scott Larson
--     Replaced gated clock with clock enable
--     Adjusted timing of SCL during start and stop conditions
--   Version 2.2 02/05/2015 Scott Larson
--     Corrected small SDA glitch introduced in version 2.1
-- 
--------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

entity twi_controller IS
  PORT(
    clk       : IN     STD_LOGIC;                    --system clock
    reset_n   : OUT     STD_LOGIC;                    --active low reset
    ena       : OUT     STD_LOGIC;                    --latch in command
    addr      : OUT     STD_LOGIC_VECTOR(6 DOWNTO 0); --address of target slave
    rw        : OUT     STD_LOGIC;                    --'0' is write, '1' is read
    data_wr   : OUT     STD_LOGIC_VECTOR(7 DOWNTO 0); --data to write to slave
    busy      : IN    STD_LOGIC);                    --indicates transaction in progress
END twi_controller;

architecture Behavioral of twi_controller IS
constant address           	: STD_LOGIC_VECTOR(6 downto 0) :=  "1000000";  --0x40 Constant Slave address
constant output_control_1 	: STD_LOGIC_VECTOR(7 downto 0) := "00000010";  --0x02 Control for each diode
constant output_control_2 	: STD_LOGIC_VECTOR(7 downto 0) := "00000011";  --0x03 Control for each diode
constant general_control_1 	: STD_LOGIC_VECTOR(7 downto 0) := "00000110";  --0x06 Needed for initialization of IO extender
constant general_control_2 	: STD_LOGIC_VECTOR(7 downto 0) := "00000111";  --0x07 Needed for initialization of IO extender

BEGIN 



END Behavioral;
