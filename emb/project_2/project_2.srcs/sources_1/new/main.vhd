----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/15/2015 10:43:38 AM
-- Design Name: 
-- Module Name: main - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity main is
    Port (  
            clk          :  in  std_logic;
            btn          :  in  std_logic;
            led          : out  std_logic_vector(5 downto 0)
    );
end main;

architecture Behavioral of main is

type main_state_t is (off, led1, led2, led3, led4, led5, led6); 
signal main_state        : main_state_t := off;
type btn_state_t is (pressed, released);
signal btn_state         : btn_state_t := released;
signal button_pushed     : std_logic;
signal slow_clk          : std_logic;
signal button_event      : std_logic := '0';
        
    component debounce is
    Port (
            clk          : in  std_logic;
            btn          : in  std_logic;
            pushed       : out std_logic
    );
    end component;     
begin
    
btn_controller: debounce
    port map(
            clk          => slow_clk       ,
            btn          => btn            ,
            pushed       => button_pushed
    );
    
--20ns * 50 = 1.000ns = 1ms => 25
millisecond: process(clk)
	variable slow_down : integer range 0 to 25 := 0;
begin
	if rising_edge(clk) then
		if slow_down = 25 then
			slow_down := 0;
			slow_clk <= not slow_clk;
		else 
			slow_down := slow_down + 1;
		end if;
	end if;
end process;

button_state_machine: process(clk, button_pushed)
begin
if rising_edge(clk) then
    if btn_state = pressed then
        button_event <= '0';
        if button_pushed = '0' then
            btn_state <= released;
        end if;
    elsif btn_state = released then
        if button_pushed = '1' then
            button_event <= '1';
            btn_state <= pressed;
        end if;
    end if;
end if;
end process;

main_state_machine: process(clk, button_event)
begin
if rising_edge(clk) then
    if main_state = off then
        if button_event = '1' then
            main_state <= led1;
        end if;
    elsif main_state = led1 then
        if button_event = '1' then
            main_state <= led2;
        end if;
    elsif main_state = led2 then
        if button_event = '1' then
            main_state <= led3;
        end if;
    elsif main_state = led3 then
        if button_event = '1' then
            main_state <= led4;
        end if;
    elsif main_state = led4 then
        if button_event = '1' then
            main_state <= led5;
        end if;
    elsif main_state = led5 then
        if button_event = '1' then
            main_state <= led6;
        end if;
    elsif main_state = led6 then
        if button_event = '1' then
            main_state <= led1;
        end if;
    end if;
end if;
end process;
    
end Behavioral;
