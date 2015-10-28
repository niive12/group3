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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MotorControl is
Port (
  pwm_out 			: out STD_LOGIC;
  
  colours_detected 	: in STD_LOGIC_VECTOR(2 downto 0); --  RED & GREEN & BLUE
  clk				: in STD_LOGIC
);
end MotorControl;

architecture Behavioral of MotorControl is
  signal pwm_value : integer range 0 to 40; -- value to be counted up to before pwm_out goes low
  signal slow_clk  : STD_LOGIC := '0';
begin

scaled_down_clk: -- generate clock with period of 0.5 ms
process(clk)
  variable counter : integer range 0 to 12500 := 0; -- 25000*20 ns = 500 µs = 0.5 ms = slow_clk.period 
begin
if rising_edge(clk)  then
  if counter = 12500 then
	counter := 0;
	slow_clk <= not slow_clk;
  else
	counter := counter + 1;
	end if;
end if;

end process;


pwm_generator:
process(slow_clk)
  variable pwm_counter : integer range 0 to 40; -- the period of the PWM signal should be 20 ms so pwm.period = 20*slow_clk.period = 20 ms 
begin
if rising_edge(slow_clk) then
  if pwm_counter = 40 then
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

statemachine: -- In the beginning one the cases of RED and BLUE will be addressed
process(clk)
begin
if(rising_edge(clk)) then
  if colours_detected = "100" then
	pwm_value <= 2; -- Left (1.35 ms)
  elsif colours_detected = "001" then
	pwm_value <= 4; -- Right (1.65 ms)
  else
	pwm_value <= 3; -- Center (1.5 ms) 
  end if;
end if;
end process;

end Behavioral;
