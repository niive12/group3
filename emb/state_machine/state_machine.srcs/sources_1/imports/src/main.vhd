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
signal slow_clk          : std_logic;
signal button_pushed     : std_logic;

component slow_clock is
    Port (  
            clk          :  in  std_logic;
            ms_clk       : out  std_logic
    );
end component;

component debounce is
    Port (
            clk          : in  std_logic;
            btn          : in  std_logic;
            btn_pushed   : out std_logic
    );
end component;     

begin

millisec: slow_clock 
    port map(
            clk          => clk            ,
            ms_clk       => slow_clk
    );

btn_controller: debounce
    port map(
            clk          => slow_clk       ,
            btn          => btn            ,
            btn_pushed   => button_pushed
    );
    
main_state_machine: process(clk)
begin
if rising_edge(clk) then
    if main_state = off then
        if button_pushed = '1' then
            main_state <= led1;
            led <= (others => '0');
        end if;
    elsif main_state = led1 then
        if button_pushed = '1' then
            main_state <= led2;
            led <= "000001";
        end if;
    elsif main_state = led2 then
        if button_pushed = '1' then
            main_state <= led3;
            led <= "000010";
        end if;
    elsif main_state = led3 then
        if button_pushed = '1' then
            main_state <= led4;
            led <= "000100";
        end if;
    elsif main_state = led4 then
        if button_pushed = '1' then
            main_state <= led5;
            led <= "001000";
        end if;
    elsif main_state = led5 then
        if button_pushed = '1' then
            main_state <= led6;
            led <= "010000";
        end if;
    elsif main_state = led6 then
        if button_pushed = '1' then
            main_state <= led1;
            led <= "100000";
        end if;
    end if;
end if;
end process;
    
end Behavioral;
