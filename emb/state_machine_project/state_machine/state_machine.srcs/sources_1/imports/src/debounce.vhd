library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
-- use button_type.ALL;

entity debounce is
    Port (
            clk          : in  std_logic;
            ms_clk       : in  std_logic;
            btn          : in  std_logic;
--             btn_pushed   : out btn_type
            btn_pushed   : out std_logic_vector(1 downto 0)
    );
end debounce;     

architecture Behavioral of debounce is

type btn_state_t is (pressed, ready,semi_released,released);
signal btn_state         : btn_state_t := ready;

constant complete_empty  : std_logic_vector(3 downto 0) := (others => '0');
constant complete_full   : std_logic_vector(3 downto 0) := (others => '1');
signal continuity_vector : std_logic_vector(3 downto 0) := (others => '1');
signal btn_status        : std_logic := '0';
-- signal button_event      : btn_type;

-- to make it work with simulation-----------
constant btn_released    : std_logic_vector(1 downto 0) := "00"; 
constant long_press      : std_logic_vector(1 downto 0) := "01"; 
constant single_press    : std_logic_vector(1 downto 0) := "10"; 
constant double_press    : std_logic_vector(1 downto 0) := "11"; 
signal button_event      : std_logic_vector(1 downto 0);
----------------------------------------------

signal count_id          : std_logic_vector(1 downto 0) := "00";
signal set_delay         : integer range 0 to 1000 := 1;
signal timeout           : std_logic := '0';
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

delay: process(ms_clk)
    variable delay : integer range 0 to 1000 := 0;
    variable next_id : std_logic_vector(1 downto 0) := "10";
    variable delay_state : integer range 0 to 1 := 0;
begin
if rising_edge(ms_clk) then
    if next_id = count_id then
        delay_state := 0;
    end if;
    if delay_state = 0 then
        timeout <= '0';
        if next_id = count_id then
            next_id := std_logic_vector(unsigned(next_id)+1);
            delay := set_delay;
            delay_state := 1;
        end if;
    else 
        if delay = 0 then
            timeout <= '1';
            delay_state := 0;
        else
            delay := delay - 1;
        end if;
    end if;
end if;
end process;

button_state_machine: process(clk)
    variable timer_id : std_logic_vector(1 downto 0) := "00";
begin
if rising_edge(clk) then
    if btn_state = ready then
        button_event <= btn_released;
        if btn_status = '1' then
            btn_state <= pressed;
            timer_id := std_logic_vector(unsigned(timer_id)+1);
            count_id <= timer_id;
            set_delay <= 500;
        end if;
    elsif btn_state = pressed then
        if timeout = '1' then
            button_event <= long_press;
            btn_state <= released; 
        end if;
        if btn_status = '0' then
            button_event <= single_press;
            btn_state <= semi_released;
            timer_id := std_logic_vector(unsigned(timer_id)+1);
            count_id <= timer_id;
            set_delay <= 127;
        end if;
    elsif btn_state = semi_released then
        button_event <= btn_released;
        if timeout = '1' then
            btn_state <= ready;
        end if;
        if btn_status = '1' then 
            button_event <= double_press;
            btn_state <= released;
        end if;
    elsif btn_state = released then
        button_event <= btn_released;
        if btn_status = '0' then
            btn_state <= ready;
            button_event <= btn_released;
        end if;
    end if;
end if;
end process;

end Behavioral;
