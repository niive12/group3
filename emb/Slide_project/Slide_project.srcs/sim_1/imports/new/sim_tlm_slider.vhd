----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/22/2015 08:56:17 PM
-- Design Name: 
-- Module Name: sim_tlm_slider - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity sim_tlm_slider is
end sim_tlm_slider;

architecture Behavioral of sim_tlm_slider is
COMPONENT tlmslider 
    Port ( 
		   MISO             	: in STD_LOGIC;           
           MOSI             	: out STD_LOGIC;
           CS               	: out STD_LOGIC;
           SCLK             	: out STD_LOGIC;
           
           pwm_out 				: out STD_LOGIC;

           Serial_in			: in STD_LOGIC;
		   Serial_out 			: out STD_LOGIC;
		   
           red_out 				: out STD_LOGIC;
           blue_out 			: out STD_LOGIC;
           green_out 			: out STD_LOGIC;
                
           clk              	: in STD_LOGIC --system clock
           );
end COMPONENT;
signal MISO			: STD_LOGIC;
signal MOSI			: STD_LOGIC;
signal CS			: STD_LOGIC;
signal SCLK			: STD_LOGIC;
signal pwm_out 		: STD_LOGIC;
signal red_led		: STD_LOGIC;
signal Serial_in	: STD_LOGIC;
signal Serial_out	: STD_LOGIC;
signal blue_led		: STD_LOGIC;
signal green_led	: STD_LOGIC;
signal clk 			: STD_LOGIC;
begin

uut: tlmslider port map(
	  MISO => MISO,
	  MOSI => MOSI,
	  CS => CS,
	  SCLK => SCLK,
	  pwm_out => pwm_out,
	  red_out=> red_led,
	  blue_out => blue_led,
	  green_out	=> green_led,
	  Serial_in => Serial_in,
	  Serial_out => Serial_out,
	  clk => clk
	  );

clock_process: process
begin
    clk <= '0';
    wait for 10 ns;
    clk <= '1';
    wait for 10 ns;
end process;

stimuli_process : process
begin
    
	wait for 7*280ns;
	MISO <= '1';
	wait for 280 ns;
	MISO <= '0';
	wait for 560 ns;
	MISO <= '1';
	wait for 280 ns;
	MISO <= '0';
	wait for 2*280 ns;
	MISO <= '1';
	wait;
end process;
end Behavioral;
