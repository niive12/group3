library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
library work;

package my_library is
    function get_rps(counter : integer) return integer;
end package;

package body my_library is
	function get_rps(counter: integer) return integer is
	-- 1/(counter*20/10^9)*3
	-- 10^9 / (counter * 20 * 3)
	-- 1666666 / counter
	-- we know the counter is below 66666 (25 rps) and above 416 rps (max speed of motor), 
-- 	   a fair assumption is that the speed is never above 108 rps, where the counter is 16000.
--        20             5 
--        |98765432109876|                                                                              
--        110010110111001101010 
--     00011111010000000 --min (10 8 rps)             
--     1000 0010 0011 010 10 --max (25  rps)          
	constant num    : std_logic_vector(20 downto 0) :=  "110010110111001101010";
	variable den    : std_logic_vector(17 downto 0) := (others => '0');
	variable rest   : std_logic_vector(17 downto 0) := (others => '0');
	variable ans    : std_logic_vector( 5 downto 0) := (others => '0');
	variable ReAns  : integer;
	variable i : integer := 0;
	begin
		den := std_logic_vector(to_unsigned(counter, 18));
		rest(14 downto 0) := num(20 downto 6);
        for i in 5 downto 0 loop
            rest := rest(17 downto 1) & num(i);
            if rest >= den then
                rest := std_logic_vector(unsigned(rest) - unsigned(den));
                ans(i) := '1';
            else
                ans(i) := '0';
            end if;
        end loop;
		ReAns := to_integer(unsigned(ans));
		return ReAns;
	end get_rps;

end package body;

