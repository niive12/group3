library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
--Comment for test
entity slow_clock is
    Port (  
            clk          :  in  std_logic;
            ms_clk       : out  std_logic
    );
end slow_clock;

architecture Behavioral of slow_clock is
signal slow_clk          : std_logic := '1';


begin
ms_clk <= slow_clk;
--20ns * 50000 = 1.000.000ns = 1ms => 25000
millisecond: process(clk)
	variable slow_down : integer range 0 to 25000 := 0;
begin
	if rising_edge(clk) then
		if slow_down = 25000 then
			slow_down := 0;
			slow_clk <= not slow_clk;
		else 
			slow_down := slow_down + 1;
		end if;
	end if;
end process;

end Behavioral;
