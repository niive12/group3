library IEEE;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity pid is
Port (
  duty 	      	: out STD_LOGIC_VECTOR(6 downto 0); --  Duty cycle 0 - 100 % if the value exceds 100 the motorcontroller will correct.
  encoder   	: in STD_LOGIC_VECTOR(2 downto 0);  --  Signal with the three hallsensors.
  clk        	: in STD_LOGIC
);
end pid;

architecture Behavioral of pid is
constant 	p : integer := 1;
constant 	i : integer := 0;
constant  	d : integer := 0;
constant    desired : integer := 1000;
signal  	vel : integer range 0 to 6000 := 0;
signal    	ramp_up : std_logic := '0';
signal     	control_out : std_logic_vector(6 downto 0);
signal     	ramp_up_out : std_logic_vector(6 downto 0);
begin

encoder_debounce: process(clk)
    variable last_encoder      : std_logic_vector(2 downto 0) := "000";
    variable counter           : integer range 0 to 18000;
begin
    if rising_edge(clk) then
	  if counter = 18000 then
		encoder := 0;
		ramp_up <= '1';
		vel <= 0;
	  elsif encoder(0) = '1' AND last_encoder(0) = '0' then
		vel <= 1/(counter*20/1000000000)*3;
		ramp_up <= '0';
		counter := 0;
		last_encoder(0) <= '1';
	  elsif encoder(1) = '1' AND last_encoder(1) = '0' then
		vel <= 1/(counter*20/1000000000)*3;
		ramp_up <= '0';
		counter := 0;
		last_encoder(1) <= '1';
	  elsif encoder(2) = '1' AND last_encoder(2) = '0' then
		vel <= 1/(counter*20/1000000000)*3;
		ramp_up <= '0';
		counter := 0;
		last_encoder(2) <= '1';
	  else
		counter := counter + 1;
		last_encoder <= "000";
	  end if;
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
	controller <= result;
 else
   delay := delay + 1;
 end if;

end if;
end process;

ramp_up_process:
process(clk)
variable delay            	: integer range 0 to 50000000   	:= 0;                 --1 sec
variable integrator  	: integer range 0 to 100;
begin
if rising_edge(clk) then
  if(delay = 50000000) then
	delay := 0;
	if ramp_up = 1 then
	  ramp_up_out <= ramp_up_out + "0001010";
	else
	  ramp_up_out <= "0000000";
	end if;
  else
   delay := delay + 1;
  end if;
end if;
end process;

duty <= control_out + ramp_up_out;
end Behavioral;
