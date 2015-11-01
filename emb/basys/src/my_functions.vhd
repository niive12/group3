library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
library work;

package my_functions is
    function abs_subtract ( a, b : std_logic_vector(9 downto 0) ) return integer; 
    function minimum      ( a, b, c, d : integer ) return std_logic_vector; --returns a block (ie "00" = red, "01" = green, "11" = invalid
    function maximum      ( a, b, c, d : integer ) return std_logic_vector; --returns a block (ie "00" = red, "01" = green, "11" = invalid
end package;

package body my_functions is
    function abs_subtract( a, b : std_logic_vector(9 downto 0) ) return integer is
        variable result : integer range 0 to 512 := 0;
        begin
            if a > b then
                result := to_integer(unsigned(a) - unsigned(b));
            else
                result := to_integer(unsigned(b) - unsigned(a));
            end if;
            return result;
        end abs_subtract;
        
    function minimum( a, b, c, d : integer ) return std_logic_vector is --min among distances
        variable result : std_logic_vector(1 downto 0) := "00";
        variable minima : integer range 0 to 3069 := 3069;
        begin
            if a < minima then
                minima := a;
                result := "00";
            end if;
            if b < minima then
                minima := b;
                result := "01";
            end if;
            if c < minima then
                minima := c;
                result := "10";
            end if;
--             if d < minima then
--                 minima := d;
--                 result := "11";
--             end if;
            return result;
        end minimum;
        
    function maximum( a, b, c, d : integer ) return std_logic_vector is --max among votes
        variable result : std_logic_vector(2 downto 0) := "111";
        variable maxima : integer range 0 to 150 := 0;
        begin
            if a >= maxima then
                maxima := a;
                result := "001";
            end if;
            if b > maxima then
                maxima := b;
                result := "010";
            end if;
            if c > maxima then
                maxima := c;
                result := "100";
            end if;
            if d > maxima then
                maxima := d;
                result := "111";
            end if;
            return result;
        end maximum;
        
end package body;