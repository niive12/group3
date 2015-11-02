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

use my_functions.ALL; --my functions

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
           
           threshold_container 	: in STD_LOGIC_VECTOR(31 downto 0);
           
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
constant data_size: INTEGER := 9;

signal red_data 		: STD_LOGIC_VECTOR(data_size downto 0);
signal blue_data		: STD_LOGIC_VECTOR(data_size downto 0);
signal green_data 		: STD_LOGIC_VECTOR(data_size downto 0);

-- constant zero_vector 	: STD_LOGIC_VECTOR(n - 1 downto 0) := (others => '0');
-- signal threshold_red 		: STD_LOGIC_VECTOR(data_size downto 0) := "00" & "1000" & "0000"; -- At the moment these are just arbitrary values
-- signal threshold_green	: STD_LOGIC_VECTOR(data_size downto 0)     := "00" & "1000" & "0000"; -- At the moment these are just arbitrary values
-- signal threshold_blue	 	: STD_LOGIC_VECTOR(data_size downto 0) := "00" & "1000" & "0000"; -- At the moment these are just arbitrary values

signal red_block_r   : STD_LOGIC_VECTOR(data_size downto 0) := "01" & "0000" & "0000";
signal red_block_g   : STD_LOGIC_VECTOR(data_size downto 0) := "00" & "0000" & "0000";
signal red_block_b   : STD_LOGIC_VECTOR(data_size downto 0) := "00" & "0000" & "0000";

signal green_block_r : STD_LOGIC_VECTOR(data_size downto 0) := "00" & "0000" & "0000";
signal green_block_g : STD_LOGIC_VECTOR(data_size downto 0) := "01" & "0000" & "0000";
signal green_block_b : STD_LOGIC_VECTOR(data_size downto 0) := "00" & "0000" & "0000";

signal blue_block_r  : STD_LOGIC_VECTOR(data_size downto 0) := "00" & "0000" & "0000";
signal blue_block_g  : STD_LOGIC_VECTOR(data_size downto 0) := "00" & "0000" & "0000";
signal blue_block_b  : STD_LOGIC_VECTOR(data_size downto 0) := "01" & "0000" & "0000";

signal no_block_r  : STD_LOGIC_VECTOR(data_size downto 0) := "01" & "0000" & "0000";
signal no_block_g  : STD_LOGIC_VECTOR(data_size downto 0) := "01" & "0000" & "0000";
signal no_block_b  : STD_LOGIC_VECTOR(data_size downto 0) := "01" & "0000" & "0000";

signal red_votes     : integer range 0 to 100 := 0;
signal green_votes   : integer range 0 to 100 := 0;
signal blue_votes    : integer range 0 to 100 := 0;
signal invalid_votes : integer range 0 to 100 := 0;

-- constant threshold_brick	: STD_LOGIC_VECTOR(9 downto 0) := "00" & "0010" & "0000"; -- Threshold for detecting bricks. At the moment these are just arbitrary values

constant head : STD_LOGIC_VECTOR(4 downto 0) := "11000";     --ADC configuration
begin
header <= head;

u_tos_net_handling: process(clk)
begin
if rising_edge(clk) then 
	case threshold_container(31 downto 30) is
	when "00" =>
	  red_block_r <= threshold_container(29 downto 20);
	  red_block_g <= threshold_container(19 downto 10);
	  red_block_b <= threshold_container(9 downto 0);
	when "01" =>
	  green_block_r <= threshold_container(29 downto 20);
	  green_block_g <= threshold_container(19 downto 10);
	  green_block_b <= threshold_container(9 downto 0);
	when "10" =>
	  blue_block_r <= threshold_container(29 downto 20);
	  blue_block_g <= threshold_container(19 downto 10);
	  blue_block_b <= threshold_container(9 downto 0);
	when others =>
	  no_block_r <= threshold_container(29 downto 20);
	  no_block_g <= threshold_container(19 downto 10);
	  no_block_b <= threshold_container(9 downto 0);
	end case;
	end if;
end process;

main_process:
process(clk)
variable sample_counter : INTEGER range 0 to n;
variable temp_red       : STD_LOGIC_VECTOR(9 downto 0) := "00" & "0000" & "0000";

variable err_red        : integer range 0 to 512 := 0;
variable err_green      : integer range 0 to 512 := 0;
variable err_blue       : integer range 0 to 512 := 0;
variable dist_red       : integer range 0 to 1536 := 0;
variable dist_green     : integer range 0 to 1536 := 0;
variable dist_blue      : integer range 0 to 1536 := 0;
variable dist_no        : integer range 0 to 1536 := 0;
variable vote           : std_logic_vector(1 downto 0) := "00";
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
	red_data <= sample_data;
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
	green_data <= sample_data;
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
	blue_data <= sample_data;
	led_state <= decider;
  end if;
  
  when decider => 
  start_sample <= '0';
  if sample_counter = n - 1 then
	sample_counter := 0;
	err_red   := abs_subtract(red_data  , red_block_r);
	err_green := abs_subtract(green_data, red_block_g);
	err_blue  := abs_subtract(blue_data , red_block_b);
	dist_red  := err_red + err_green;
	dist_red  := dist_red + err_blue;
	err_red   := abs_subtract(red_data  , green_block_r);
	err_green := abs_subtract(green_data, green_block_g);
	err_blue  := abs_subtract(blue_data , green_block_b);
	dist_green:= err_red + err_green;
	dist_green:= dist_green + err_blue;
	err_red   := abs_subtract(red_data  , blue_block_r);
	err_green := abs_subtract(green_data, blue_block_g);
	err_blue  := abs_subtract(blue_data , blue_block_b);
	dist_blue := err_red + err_green;
	dist_blue := dist_blue + err_blue;
	err_red   := abs_subtract(red_data  , no_block_r);
	err_green := abs_subtract(green_data, no_block_g);
	err_blue  := abs_subtract(blue_data , no_block_b);
	dist_no   := err_red + err_green;
	dist_no   := dist_no + err_blue;
	
	vote = minimum(dist_red, dist_green, dist_blue, dist_no);
	
	case vote is 
		when "00"   => red_votes     <= red_votes     + 1;
		when "01"   => green_votes   <= green_votes   + 1;
		when "10"   => blue_votes    <= blue_votes    + 1;
		when others => invalid_votes <= invalid_votes + 1;
	end case;
	
	detected = maximum(red_votes, green_votes, blue_votes, invalid_votes);
	
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
