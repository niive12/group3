library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity debounce is
    Port (
            clk          : in  std_logic;
            btn          : in  std_logic;
            pushed       : out std_logic
    );
end debounce;     

architecture Behavioral of debounce is

constant complete_empty  : std_logic_vector(3 downto 0) := (others => '0');
constant complete_full   : std_logic_vector(3 downto 0) := (others => '1');
signal continuity_vector : std_logic_vector(3 downto 0) := (others => '0');
signal btn_status        : std_logic := '0';

begin 
pushed <= btn_status;
continuity_check: process(clk)
begin
if rising_edge(clk) then
    if continuity_vector = complete_empty then
        btn_status <= '1';
    elsif continuity_vector = complete_full then
        btn_status <= '0';
    end if;
    continuity_vector <= continuity_vector(2 downto 0) & btn;
end if;

end process;

end Behavioral;
