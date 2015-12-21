library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
library work;
use work.my_library.ALL;

entity pid is
Port (
    duty            : out std_logic_vector(6 downto 0); --  duty cycle 0 - 100 % if the value exceds 100 the motorcontroller will correct.
    encoder         : in  std_logic_vector(2 downto 0); --  signal with the three hallsensors.
    clk             : in  std_logic
);
attribute period: string;
attribute period of clk : signal is "200 ns";
end pid;

architecture Behavioral of pid is
constant min_duty_cycle   : std_logic_vector(6 downto 0) := std_logic_vector(to_unsigned(30,7));          
constant max_duty_cycle   : std_logic_vector(6 downto 0) := std_logic_vector(to_unsigned(90,7));          

constant 	p : integer := 1;
constant 	i : integer := 1;
constant  	d : integer := 0;
constant    desired : integer := 30;
signal  	vel : integer range 0 to 45 := 0;
signal    	ramp_up : std_logic := '0';
signal     	control_out : std_logic_vector(6 downto 0) := (others => '0');
signal     	ramp_up_out : std_logic_vector(6 downto 0) := (others => '0');
signal sig_counter           : integer range 0 to 67000;
signal sig_counter_v           : std_logic_vector(16 downto 0) := (others => '0');

begin

encoder_debounce: process(clk)
    variable last_encoder      : std_logic_vector(2 downto 0) := "000";
    variable counter           : integer range 0 to 67000;
begin
    if rising_edge(clk) then
        if counter = 66666 then
            counter := 0;
            last_encoder := (others => '0');
            ramp_up <= '1';
            vel <= 25;
        elsif encoder(0) = '1' AND last_encoder(0) = '0' then
        sig_counter <= counter;
        sig_counter_v <= std_logic_vector(to_unsigned(counter, 17));
            vel <= get_rps(counter); 
            ramp_up <= '0';
            counter := 0;
            last_encoder(0) := '1';
        elsif encoder(1) = '1' AND last_encoder(1) = '0' then
        sig_counter <= counter;
        sig_counter_v <= std_logic_vector(to_unsigned(counter, 17));
            vel <= get_rps(counter);
            ramp_up <= '0';
            counter := 0;
            last_encoder(1) := '1';
        elsif encoder(2) = '1' AND last_encoder(2) = '0' then
        sig_counter <= counter;
        sig_counter_v <= std_logic_vector(to_unsigned(counter, 17));
            vel <= get_rps(counter);
            ramp_up <= '0';
            counter := 0;
            last_encoder(2) := '1';
        else
            counter := counter + 1;
            last_encoder := (others => '0');
        end if;
    end if;
end process;

controller: process(clk)
variable delay            	: integer range 0 to 5000      := 0;                 -- 1 kHz = 1 ms = 50 000
variable vel_error      	: integer range -10 to 10      := 0;
variable prev_error       	: integer range -10 to 10      := 0;
variable accumulated_error 	: integer range -10 to 10      := 0;
variable error_change      	: integer range -10 to 10      := 0;
variable result           	: integer range -10 to 10      := 0;
variable new_duty_cycle     : std_logic_vector(6 downto 0) := (others => '0');
variable old_duty_cycle     : std_logic_vector(6 downto 0) := (others => '0');

begin
if rising_edge(clk) then
    if(delay = 5000) then
        delay := 0;
        
        old_duty_cycle := control_out;
        vel_error := desired - vel;
        accumulated_error := accumulated_error + vel_error;
        error_change := vel_error - prev_error;
        result := p*vel_error + i*accumulated_error + d*error_change;
        prev_error := vel_error;
        if old_duty_cycle >= min_duty_cycle AND old_duty_cycle < max_duty_cycle then
            new_duty_cycle := std_logic_vector(unsigned(old_duty_cycle) + result) ;
        elsif old_duty_cycle < min_duty_cycle then
            new_duty_cycle :=  min_duty_cycle;
        elsif old_duty_cycle >= max_duty_cycle then
            new_duty_cycle :=   std_logic_vector(unsigned(max_duty_cycle) - 1);
        end if;
        
        if ramp_up = '0' then
            control_out <= new_duty_cycle;
        else
            control_out <= (others => '0');
        end if;
    else
        delay := delay + 1;
    end if;
end if;
end process;

ramp_up_process: process(clk)
variable delay            	: integer range 0 to 5000000   	:= 0;                 --1 sec
variable integrator  	: integer range 0 to 100;
begin
if rising_edge(clk) then
  if delay = 5000000  then
	delay := 0;
	if ramp_up = '1' then
	  ramp_up_out <= std_logic_vector(unsigned(ramp_up_out) + 10);
	else
	  ramp_up_out <= "0000000";
	end if;
  else
   delay := delay + 1;
  end if;
end if;
end process;

duty <= control_out OR ramp_up_out;
end Behavioral;
