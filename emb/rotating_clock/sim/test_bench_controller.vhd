library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

----------------------------------------------------------------------------------------------
----------------------------Simulate this module for at least 301 ms--------------------------
----------------------------------------------------------------------------------------------
entity sim_motorcontrol is
end sim_motorcontrol;


architecture Behavioral of sim_motorcontrol is
COMPONENT rotating_clock
PORT(
    SCLK            : out std_logic;
    S_DATA          : out std_logic;
    LATCH           : out std_logic;
    PWM             : out std_logic;
    Encoders        : in  std_logic_vector(2 downto 0); 
    CLK             : in  std_logic
);
end COMPONENT;

signal led_clk          : STD_LOGIC;
signal led_data         : STD_LOGIC;
signal led_latch        : STD_LOGIC;
signal pwm_out          : STD_LOGIC;
signal encoders         : STD_LOGIC_VECTOR(2 downto 0) := "000";
signal clk              : STD_LOGIC;

begin
test_bench: rotating_clock port map(
    SCLK     => led_clk,
    S_DATA   => led_data,
    LATCH    => led_latch,
    PWM      => pwm_out,
    Encoders => encoders,
    CLK      => clk
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
	encoders <= "000";
	wait for 10 ns;
	encoders <= "001";
	wait for 210 ns;
	encoders <= "000";
	wait for 11111000 ns;
	encoders <= "010";
	wait for 210 ns;
	encoders <= "000";
	wait for 11111000 ns;
	encoders <= "100";
	wait for 210 ns;
	encoders <= "000";
	wait for 11110990 ns;
end process;
end Behavioral;
