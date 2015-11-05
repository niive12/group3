library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

----------------------------------------------------------------------------------------------
----------------------------Simulate this module for at least 301 ms--------------------------
----------------------------------------------------------------------------------------------

entity sim_motorcontrol is
end sim_motorcontrol;

architecture Behavioral of sim_motorcontrol is
COMPONENT MotorControl
PORT(
	pwm_out          	: out STD_LOGIC;
	colours_detected 	: in STD_LOGIC_VECTOR(2 downto 0);
	clk              	: in STD_LOGIC
);
end COMPONENT;

signal pwm_out          : STD_LOGIC;
signal colours_detected : STD_LOGIC_VECTOR(2 downto 0);
signal clk              : STD_LOGIC;

begin
uut: MotorControl port map(
	pwm_out => pwm_out,
	colours_detected => colours_detected,
	clk => clk
);



clock_process: process
begin
	clk <= '0';
	wait for 10 ns;
	clk <= '1';
	wait for 10 ns;
end process;


stimuli: process
begin
	colours_detected <= "000";
	wait for 10 ns;
	colours_detected <= "100";
	wait for 100 ms;
	colours_detected <= "000";
	wait for 100 ms;
	colours_detected <= "001";
	wait for 100  ms;
	colours_detected <= "000";
	wait;
end process;
end Behavioral;
