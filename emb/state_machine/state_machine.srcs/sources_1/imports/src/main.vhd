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
            system_red   : out  std_logic;
            system_yellow: out  std_logic;
            led          : out  std_logic_vector(5 downto 0)
    );
end main;

architecture Behavioral of main is

type main_state_t is (off, led1, led2, led3, led4, led5, led6); 
signal main_state        : main_state_t := off;
signal slow_clk          : std_logic;
signal button_pushed     : std_logic_vector(1 downto 0);

constant btn_released    : std_logic_vector(1 downto 0) := "00";
constant long_press      : std_logic_vector(1 downto 0) := "01";
constant single_press    : std_logic_vector(1 downto 0) := "10";
constant double_press    : std_logic_vector(1 downto 0) := "11";

signal reset_led         : std_logic := '0';
signal warn_led          : std_logic := '0';
component slow_clock is
    Port (  
            clk          :  in  std_logic;
            ms_clk       : out  std_logic
    );
end component;

component debounce is
    Port (
            clk          : in  std_logic;
            ms_clk       : in  std_logic;
            btn          : in  std_logic;
            btn_pushed   : out std_logic_vector(1 downto 0)
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
            clk          => clk            ,
            ms_clk       => slow_clk       ,
            btn          => btn            ,
            btn_pushed   => button_pushed
    );

system_red <= reset_led;
system_yellow <= warn_led;
    
main_state_machine: process(slow_clk)
begin
if rising_edge(slow_clk) then
    if button_pushed = long_press then
        reset_led <= not reset_led;
        main_state <= off;
    elsif button_pushed = double_press then
        warn_led <= not warn_led;
        main_state <= off;
    elsif main_state = off then
        led <= (others => '0');
        if button_pushed = single_press then
            main_state <= led1;
        end if;
    elsif main_state = led1 then
        if button_pushed = single_press then
            main_state <= led2;
            led <= "000001";
        end if;
    elsif main_state = led2 then
        if button_pushed = single_press then
            main_state <= led3;
            led <= "000010";
        end if;
    elsif main_state = led3 then
        if button_pushed = single_press then
            main_state <= led4;
            led <= "000100";
        end if;
    elsif main_state = led4 then
        if button_pushed = single_press then
            main_state <= led5;
            led <= "001000";
        end if;
    elsif main_state = led5 then
        if button_pushed = single_press then
            main_state <= led6;
            led <= "010000";
        end if;
    elsif main_state = led6 then
        if button_pushed = single_press then
            main_state <= led1;
            led <= "100000";
        end if;
    end if;
end if;
end process;
    
end Behavioral;
