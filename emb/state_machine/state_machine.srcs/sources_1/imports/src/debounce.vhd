library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity debounce is
    Port (
            clk          : in  std_logic;
            ms_clk       : in  std_logic;
            btn          : in  std_logic;
            btn_pushed   : out std_logic_vector(1 downto 0)
    );
end debounce;     

architecture Behavioral of debounce is

type btn_state_t is (pressed, released,semi_released,double_press);
signal btn_state         : btn_state_t := released;


constant btn_released    : std_logic_vector(1 downto 0) := "00";
constant long_press      : std_logic_vector(1 downto 0) := "01";
constant single_press    : std_logic_vector(1 downto 0) := "10";
constant dbl_press       : std_logic_vector(1 downto 0) := "11";

constant complete_empty  : std_logic_vector(3 downto 0) := (others => '0');
constant complete_full   : std_logic_vector(3 downto 0) := (others => '1');
signal continuity_vector : std_logic_vector(3 downto 0) := (others => '0');
signal btn_status        : std_logic := '0';
signal button_event      : std_logic_vector(1 downto 0) := btn_released ;
begin 

btn_pushed <= button_event;

continuity_check: process(ms_clk)
begin
if rising_edge(ms_clk) then
    if continuity_vector = complete_empty then
        btn_status <= '1';
    elsif continuity_vector = complete_full then
        btn_status <= '0';
    end if;
    continuity_vector <= continuity_vector(2 downto 0) & btn;
end if;
end process;

-- button_state_machine: process(ms_clk)
-- begin
-- if rising_edge(ms_clk) then
--     if btn_state = pressed then
--         button_event <= '0';
--         if btn_status = '0' then
--             btn_state <= released;
--         end if;
--     elsif btn_state = released then
--         if btn_status = '1' then
--             button_event <= '1';
--             btn_state <= pressed;
--         end if;
--     end if;
-- end if;
-- end process;

button_state_machine: process(ms_clk)
variable set_delay : integer range 0 to 1000 := 0;
begin
if rising_edge(ms_clk) then
    if btn_state = released then
        button_event <= btn_released;
        if btn_status = '1' then
            btn_state <= pressed;
            set_delay := 500;
        end if;
    elsif btn_state = pressed then
        set_delay := set_delay - 1;
        if set_delay = 0 then
            button_event <= long_press;
            btn_state <= released;
        end if;
        if btn_status = '0' then
            button_event <= single_press;
            btn_state <= semi_released;
            set_delay := 500;
        end if;
    elsif btn_state = semi_released then
        button_event <= btn_released;
        set_delay := set_delay - 1;
        if set_delay = 0 then
            btn_state <= released;
        end if;
        if btn_status = '1' then 
            button_event <= dbl_press;
            btn_state <= double_press;
        end if;
    elsif btn_state = double_press then
        button_event <= btn_released;
        if btn_status = '0' then
            btn_state <= released;
            button_event <= btn_released;
        end if;
    end if;
end if;
end process;



end Behavioral;
