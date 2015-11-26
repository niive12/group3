library IEEE;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity pid is
Port (
  duty 	      	: out STD_LOGIC_VECTOR(6 downto 0); --  Duty cycle 0 - 100 % if the value exceds 100 the motorcontroller will correct.
  dir         	: out STD_LOGIC;                    --  Direction for the H-bridge
  hall_sensor  	: in STD_LOGIC_VECTOR(2 downto 0);  --  Signal with the three hallsensors.
  clk        	: in STD_LOGIC
);
end pid;

architecture Behavioral of pid is
constant 	p : integer := 1;
constant 	i : integer := 0;
constant  	d : integer := 0;
constant    desired : integer := 1000;
signal  	vel : integer range 0 to 6000 := 0;
begin

vel_calculator:
process(clk)
variable count  : integer range 0 to 18000;
variable prev_0 : STD_LOGIC:= '0';
variable prev_1 : STD_LOGIC:= '0';
variable prev_2 : STD_LOGIC:= '0';
begin
if rising_edge(clk) then

end if;

end process;

controller:
process(clk)
variable delay            	: integer range 0 to 50000   	:= 0;                 -- 1 kHz = 1 ms = 50 000
variable vel_error      	: integer range -6000 to 6000 	:= 0;
variable prev_error       	: integer range -6000 to 6000  	:= 0;
variable accumulated_error 	: integer range -6000 to 6000  	:= 0;
variable error_change      	: integer range -6000 to 6000  	:= 0;
variable result           	: integer range -6000 to 6000 	:= 0;
begin
if rising_edge(clk) then
 if(delay = 50000) then
   delay := 0;
   vel_error := desired - vel;
   accumulated_error := accumulated_error + val_error;
   error_change := val_error - prev_error;
   result := p*val_error + i*accumulated_error + d*error_change;
   duty <= result/6000*100;
 else
   delay := delay + 1;
 end if;

end if;
end process;

end Behavioral;
