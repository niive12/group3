----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/20/2015 11:41:49 AM
-- Design Name: 
-- Module Name: MotorControl - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MotorControl is
Port (
  pwm_out        	: out STD_LOGIC;
  
  duty 	         	: in STD_LOGIC_VECTOR(6 downto 0); --  Duty cycle 0 - 100 % if the value exceds 100, chose 100 as max
  clk            	: in STD_LOGIC
);
end MotorControl;

architecture Behavioral of MotorControl is
  signal pwm_value : integer range 0 to 12500; -- value to be counted up to before pwm_out goes low
begin

pwm_value_calculator:
process(clk)
variable temp_val : integer range 0 to 100;
begin
if rising_edge(clk) then
  if duty > "1100100" then
	temp_val := 100;
  else 
	temp_value := to_integer(unsigned(duty));
  end if;
  pwm_value <= temp_val*125;
end if;
end process;

pwm_generator:
process(clk)
variable pwm_counter : integer range 0 to 12500;
begin
if rising_edge(clk) then
  if pwm_counter = 12500 then
	pwm_counter := 0;
  else
	pwm_counter := pwm_counter + 1;
  end if;
  if pwm_counter < pwm_value then
	pwm_out <= '1';
  else
	pwm_out <= '0';
  end if;
end if;
end process;

end Behavioral;
