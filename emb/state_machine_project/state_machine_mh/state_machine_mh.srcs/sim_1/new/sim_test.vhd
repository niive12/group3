----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/17/2015 09:20:59 AM
-- Design Name: 
-- Module Name: sim_testbench - Behavioral
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

entity sim_test is

end sim_test;

architecture Behavioral of sim_test is     

COMPONENT main
PORT(
            clk          :  in  std_logic;
            btn          :  in  std_logic;
            system_red   : out  std_logic;
            system_yellow: out  std_logic;
            led          : out  std_logic_vector(5 downto 0)
            );
end COMPONENT;

signal      clk          :  std_logic:= '0';
signal      btn          :  std_logic:='0';
signal      led          :  std_logic_vector(5 downto 0);
signal      doublepress    :  std_logic:='0';
signal      longpress :  std_logic:='0';

begin

uut: main PORT MAP (clk,btn,doublepress,longpress,led
            );
                
clock_process: process
begin
    clk <= '0';
          wait for 10 ns;
    clk <= '1';
    wait for 10 ns;
end process;


stim_proc: process
begin

btn <= '1';

wait for  10 ms;
btn <= '0';
wait for 20 ms;
btn <= '1';
wait for 150 ms;
btn <= '0'; 
wait for 10 ms;
btn <= '1';
wait for 150 ms;
btn <='0';
wait for 10 ms;
btn <='1';
wait for 10 ms;
btn <='0';
wait for 10 ms;
btn <='1'; 
wait;
end process;
 
end Behavioral;
