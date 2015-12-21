library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity display_control is
Port (
-- input from clock
    minute          : in  integer range 0 to 60;
    second          : in  integer range 0 to 60;
    hour            : in  integer range 0 to 12;
    
    -- reading the encoders to reset positions to make sure the watch doesn't drift.
    encoder         : in  std_logic_vector(2 downto 0);
    
    -- led_driver_comm
    led_driver_rdy  : in  std_logic;
    send_data       : out std_logic_vector(1 downto 0);
    data            : out std_logic_vector(31 downto 0);
                    
    clk             : in  std_logic
);
-- attribute period: string;
-- attribute period of clk : signal is "20 ns";
end display_control;

architecture Behavioral of display_control is
    constant time_divider      : integer := 27777; -- 50*10^6 HZ /(30 rps * 60 divisions)
    constant watch_detail      : std_logic_vector(31 downto 0) := "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & "0111";
    constant watch_noon_detail : std_logic_vector(31 downto 0) := "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & "0011" & "1111";
    constant watch_hand_hour   : std_logic_vector(31 downto 0) := "1111" & "1111" & "1111" & "1111" & "0000" & "0000" & "0000" & "0000";
    constant watch_hand_min    : std_logic_vector(31 downto 0) := "1111" & "1111" & "1111" & "1111" & "1111" & "1111" & "0000" & "0000";
    constant watch_hand_sec    : std_logic_vector(31 downto 0) := "1111" & "1111" & "1111" & "1111" & "1111" & "1111" & "1111" & "1111";
    signal   rising_encoder    : std_logic_vector(2 downto 0)  := "000";
    signal   send_led_data     : std_logic_vector(1 downto 0)  := "00";
    signal   sig_position      : integer range 0 to 59 := 0;
begin

send_data <= send_led_data;

encoder_debounce: process(clk)
    variable last_encoder      : std_logic_vector(2 downto 0) := "000";
begin
    if rising_edge(clk) then
        if    encoder(0) = '1' AND last_encoder(0) = '0' then
            rising_encoder <= "001";
        elsif encoder(1) = '1' AND last_encoder(1) = '0' then
            rising_encoder <= "010";
        elsif encoder(2) = '1' AND last_encoder(2) = '0' then
            rising_encoder <= "100";
        else
            rising_encoder <= "000";
        end if;
        last_encoder := encoder;
    end if;
end process;

clock_state_machine: process(clk)
	variable position     : integer range 0 to 59 := 0;
	variable time_counter : integer range 0 to time_divider := 0;
	variable detail_cnt   : integer range 1 to 5 := 1;
	variable data_out     : std_logic_vector(31 downto 0);
	variable t_encoder    : std_logic_vector(2 downto 0) := "000";
	variable h_pos        : integer range 0 to 12 := 0;
begin
    if rising_edge(clk) then
        if rising_encoder /= "000" then
            t_encoder := rising_encoder;
        end if;
        if time_counter = time_divider then
            time_counter := 0;
            if position = 59 then
                position := 0; 
            else
                position := position + 1;
            end if;
            
            data_out := (others => '0'); 
            
            -- every 5th second should have a watch detail so it looks like a clock
            if detail_cnt = 5 then
                detail_cnt := 1;
                data_out := data_out OR watch_detail;
                h_pos := h_pos + 1;
                if h_pos = hour then
                    data_out := data_out OR watch_hand_hour;
                end if;
            else 
                detail_cnt := detail_cnt + 1;
            end if;
            
            -- encoders "reset" the timer to keep timing.
            if t_encoder(0) = '1' then
                t_encoder := "000";
                position := 0; 
                h_pos := 0;
                data_out := data_out OR watch_noon_detail;
                detail_cnt := 1;
            elsif t_encoder(1) = '1' then
                t_encoder := "000";
                position := 20;
                h_pos := 4;
            elsif t_encoder(2) = '1' then
                t_encoder := "000";
                position := 40;
                h_pos := 8;
            end if;
            
            -- add hands of the clock 
            -- long hands overshadows the shorter so no reason to check them
            if position = second then
                data_out := data_out OR watch_hand_sec;
            elsif position = minute then
                data_out := data_out OR watch_hand_min;
            end if;
            sig_position <= position;
            -- send the data to the led driver
            if led_driver_rdy = '1' then
                data <= data_out;
                send_led_data <= std_logic_vector(unsigned(send_led_data)+1);
            end if;
        else
            time_counter := time_counter + 1;
        end if;
    end if;
end process;
end Behavioral;