----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/06/2015 10:44:51 PM
-- Design Name: 
-- Module Name: sim_datatoadc - Behavioral
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

entity sim_datatoadc is

end sim_datatoadc;

architecture Behavioral of sim_datatoadc is
COMPONENT spi_module 
PORT(
		   MISO             : in STD_LOGIC;           
           MOSI             : out STD_LOGIC;
           CS               : out STD_LOGIC;
           SCLK             : out STD_LOGIC;
           
           -- For communication with controller
           data_in          : in STD_LOGIC_VECTOR(4 downto 0); -- Data from controller to be sent to ADC
           data_in_ready    : in  STD_LOGIC; -- Signal to pull chip select low
           
           data_out         : out STD_LOGIC_VECTOR(9 downto 0); -- Data recieved from the ADC to be sent to controller
           data_out_ready   : out STD_LOGIC; -- Signal to the controller that a whole package is received 
           
           clk              : in STD_LOGIC --system clock
           );
end COMPONENT;

signal MISO : STD_LOGIC;
signal MOSI : STD_LOGIC;
signal CS 	: STD_LOGIC;
signal SCLK : STD_LOGIC;
signal data_in : STD_LOGIC_VECTOR(4 downto 0);
signal data_in_ready : STD_LOGIC;
signal data_out : STD_LOGIC_VECTOR(9 downto 0);
signal data_out_ready : STD_LOGIC;

signal clk : STD_LOGIC;

begin

uut: spi_module port map(
  MISO => MISO,
  MOSI => MOSI,
  CS => CS,
  SCLK => SCLK,
  data_in => data_in,
  data_in_ready => data_in_ready,
  data_out => data_out,
  data_out_ready => data_out_ready,
  clk => clk
  );
  
                  
clock_process: process
begin
    clk <= '0';
    wait for 10 ns;
    clk <= '1';
    wait for 10 ns;
end process;

stimuli_process:
process
begin
	wait for 1 us;
	data_in <= "00000";
	data_in_ready <= '0';
	wait for 1 us;
	data_in <= "11001";
	data_in_ready <= '1';
	wait for 10 ns;
	data_in_ready <= '0';
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
	wait for 10 us;
	data_in <= "11010";
	data_in_ready <= '1';
	wait for 10 ns;
	data_in_ready <= '0';
	wait;
end process;
end Behavioral;
