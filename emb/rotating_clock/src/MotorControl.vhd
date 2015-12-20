library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity MotorControl is
Port (
    pwm_out         : out std_logic;
                    
    duty            : in  std_logic_vector(6 downto 0); --  Duty cycle 0 - 100 % if the value exceds 100, chose 100 as max
    clk             : in  std_logic
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
