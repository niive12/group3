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
-- use button_type.ALL;

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
-- signal button_pushed     : btn_type;

-- to make it work with simulation-----------
constant btn_released    : std_logic_vector(1 downto 0) := "00"; 
constant long_press      : std_logic_vector(1 downto 0) := "01"; 
constant single_press    : std_logic_vector(1 downto 0) := "10"; 
constant double_press    : std_logic_vector(1 downto 0) := "11"; 
signal button_pushed     : std_logic_vector(1 downto 0);
----------------------------------------------


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
--             btn_pushed   : out btn_type
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
    
main_state_machine: process(clk)
begin
if rising_edge(clk) then
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
        led <= "000001";
        if button_pushed = single_press then
            main_state <= led2;
        end if;
    elsif main_state = led2 then
        led <= "000010";
        if button_pushed = single_press then
            main_state <= led3;
        end if;
    elsif main_state = led3 then
        led <= "000100";
        if button_pushed = single_press then
            main_state <= led4;
        end if;
    elsif main_state = led4 then
        led <= "001000";
        if button_pushed = single_press then
            main_state <= led5;
        end if;
    elsif main_state = led5 then
        led <= "010000";
        if button_pushed = single_press then
            main_state <= led6;
        end if;
    elsif main_state = led6 then
        led <= "100000";
        if button_pushed = single_press then
            main_state <= led1;
        end if;
    end if;
end if;
end process;
    
end Behavioral;
