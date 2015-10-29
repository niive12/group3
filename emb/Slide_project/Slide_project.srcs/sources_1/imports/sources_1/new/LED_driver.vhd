----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/07/2015 09:19:35 PM
-- Design Name: 
-- Module Name: LED_driver - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity LED_driver is
    Port (
           red_led 				: out STD_LOGIC;
           blue_led 			: out STD_LOGIC;
           green_led 			: out STD_LOGIC;
           
           detected 			: out STD_LOGIC_VECTOR(2 downto 0);
           
           threshold_container 	: in STD_LOGIC_VECTOR(29 downto 0);
           
           sample_data 			: in STD_LOGIC_VECTOR (9 downto 0);
           sample_done 			: in STD_LOGIC;
		   start_sample 		: out STD_LOGIC;
		   header 				: out STD_LOGIC_VECTOR(4 downto 0);
            
           clk				 	: in STD_LOGIC);
end LED_driver;

architecture Behavioral of LED_driver is
type led_state_t is (idle, decider, red, green, blue); 
signal led_state : led_state_t := idle;

signal sampling 	: STD_LOGIC := '0';
signal red_detected : STD_LOGIC;
signal blue_detected : STD_LOGIC;
signal green_detected : STD_LOGIC;

constant n : INTEGER := 4; --Number of samples. Has to be a power of 2 in order to divide
constant data_size: INTEGER := 10 + n - 1;

signal red_data 		: STD_LOGIC_VECTOR(data_size downto 0);
signal blue_data		: STD_LOGIC_VECTOR(data_size downto 0);
signal green_data 		: STD_LOGIC_VECTOR(data_size downto 0);

constant zero_vector 	: STD_LOGIC_VECTOR(n - 1 downto 0) := (others => '0');
signal threshold_red 		: STD_LOGIC_VECTOR(data_size downto 0) := zero_vector & "00" & "1000" & "0000"; -- At the moment these are just arbitrary values
signal threshold_green	: STD_LOGIC_VECTOR(data_size downto 0) := zero_vector & "00" & "1000" & "0000"; -- At the moment these are just arbitrary values
signal threshold_blue	 	: STD_LOGIC_VECTOR(data_size downto 0) := zero_vector & "00" & "1000" & "0000"; -- At the moment these are just arbitrary values

constant threshold_brick	: STD_LOGIC_VECTOR(9 downto 0) := "00" & "0010" & "0000"; -- Threshold for detecting bricks. At the moment these are just arbitrary values

constant head : STD_LOGIC_VECTOR(4 downto 0) := "11000";
begin
header <= head;
threshold_red 		<= zero_vector & threshold_container(29 downto 20);
threshold_green 	<= zero_vector & threshold_container(19 downto 10);
threshold_blue 		<= zero_vector & threshold_container(9 downto 0);

main_process:
process(clk)
variable sample_counter : INTEGER range 0 to n;
variable temp_red       : STD_LOGIC_VECTOR(9 downto 0) := "00" & "0000" & "0000";
begin
if rising_edge(clk) then
  case led_state is
  
  when idle =>                                       --Idle state is the start state of the state machine. This checks if a
  start_sample <= '0';                               --brick is present at the start of the ramp
  if sampling = '0' then                             
	start_sample <= '1';
	sampling <= '1';
	red_led <= '1';
  end if;
  if sample_done = '1' then
    red_led <='0';
	sampling <= '0';
	temp_red := sample_data;
	green_data <=  (others => '0');
	blue_data <=  (others => '0');
	if temp_red > threshold_brick then
	led_state <= red;
	red_data <= (others => '0');
	end if;
  end if;
  
  when red =>
  start_sample <= '0';
  if sampling = '0' then                           
	start_sample <= '1';
	sampling <= '1';
	red_led <= '1';
  end if;
  if sample_done = '1' then
	red_led <= '0';
	sampling <= '0';
	red_data <= STD_LOGIC_VECTOR(UNSIGNED(red_data) + UNSIGNED(sample_data));
	led_state <= green;
  end if;
  
  when green =>
  start_sample <= '0';
  if sampling = '0' then                           
	start_sample <= '1';
	sampling <= '1';
	green_led <= '1';
  end if;
  if sample_done = '1' then
	green_led <= '0';
	sampling <= '0';
	green_data <= STD_LOGIC_VECTOR(UNSIGNED(green_data) + UNSIGNED(sample_data));
	led_state <= blue;
  end if;
  
  when blue =>
  start_sample <= '0';
  if sampling = '0' then                           
	start_sample <= '1';
	sampling <= '1';
	blue_led <= '1';
  end if;
  if sample_done = '1' then
	blue_led <= '0';
	sampling <= '0';
	blue_data <= STD_LOGIC_VECTOR(UNSIGNED(blue_data) + UNSIGNED(sample_data));
	led_state <= decider;
  end if;
  
  when decider => 
  start_sample <= '0';
  if sample_counter = n - 1 then
	sample_counter := 0;
	red_data <= zero_vector & red_data(data_size downto n); --divide by 2^4 (16) -- should be 2^2 (4)
	green_data <= zero_vector & green_data(data_size downto n);
	blue_data <= zero_vector & blue_data(data_size downto n);
	if red_data > threshold_red then
	  red_detected <= '1';
	else
	  red_detected <= '0';
	end if;
	if green_data > threshold_green then
		green_detected <= '1';
	else 
	  green_detected <='0';
	end if;
	if blue_data > threshold_blue then
	  blue_detected <= '1';
	 else
		blue_detected <= '0';
	end if;
	led_state <= idle;
  else
	sample_counter := sample_counter + 1; --take one more sample
	led_state <= red;
  end if;
  
  when others =>
  led_state <= idle;
  
  end case;
  
  end if;
end process;
detected <= red_detected & green_detected & blue_detected;
end Behavioral;
