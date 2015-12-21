library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity clock is
Port (
    minute          : out integer range 0 to 60;
    second          : out integer range 0 to 60;
    hour            : out integer range 0 to 12;
                    
    clk             : in  std_logic
);
end clock;

architecture Behavioral of clock is
  signal clk_1s : std_logic := '0'; --to be counted up to delay for one second.
begin

second_interval: process(clk)
	variable delay : integer range 0 to 25000000 := 0;
begin
	if rising_edge(clk) then
		if delay = 25000000 then
			delay := 0;
			clk_1s <= not clk_1s;
		else
			delay := delay + 1;
		end if;
	end if;
end process;

clock_counter: process(clk_1s)
	variable t_min  : integer range 0 to 60 := 1;
	variable t_sec  : integer range 0 to 60 := 3;
	variable t_hour : integer range 0 to 12 := 1;
begin
	if rising_edge(clk_1s) then
		if t_sec = 59 then
			t_sec := 0;
			if t_min = 59 then
				t_min := 0;
				if t_hour = 11 then
					t_hour := 0;
				else
					t_hour := t_hour + 1;
				end if;
			else
				t_min := t_min + 1;
			end if;
		else
			t_sec := t_sec + 1;
		end if;
		second <= t_sec;
		minute <= t_min;
		hour   <= t_hour;
	end if;
end process;	
end Behavioral;