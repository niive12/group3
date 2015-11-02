library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity sim_led_driver is
end sim_led_driver;

architecture Behavioral of sim_led_driver is
COMPONENT LED_driver
PORT(
		   red_led 				: out STD_LOGIC;
           blue_led 			: out STD_LOGIC;
           green_led 			: out STD_LOGIC;
           
           detected 			: out STD_LOGIC_VECTOR(2 downto 0);
           sample_data 			: in STD_LOGIC_VECTOR (9 downto 0);
           sample_done 			: in STD_LOGIC;
		   start_sample 		: out STD_LOGIC;
            
           clk				 	: in STD_LOGIC);
end COMPONENT; 

signal red_led		: STD_LOGIC;
signal blue_led		: STD_LOGIC;
signal green_led	: STD_LOGIC;
signal sample_data 	: STD_LOGIC_VECTOR(9 downto 0);
signal sample_done	: STD_LOGIC;
signal start_sample	: STD_LOGIC;
signal clk			: STD_LOGIC;
signal detected 	: STD_LOGIC_VECTOR(2 downto 0);

begin
uut: LED_driver port map(
  red_led => red_led,
  blue_led => blue_led,
  green_led => green_led,
  sample_done => sample_done,
  sample_data => sample_data,
  start_sample => start_sample,
  detected => detected,
  clk => clk
  );
  
                  
clock_process: process
begin
    clk <= '0';
    wait for 10 ns;
    clk <= '1';
    wait for 10 ns;
end process;

stimuli: process
begin
wait for 20 ns;
sample_data <= "1001001111";
wait for 1 us;
sample_done <= '1'; -- sample for start
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "0000000000";
wait for 20 ns;
sample_done <= '1'; -- sample for red
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "1001001111";
wait for 20 ns;
sample_done <= '1'; -- sample for green
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_done <= '1'; -- sample for blue
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "0000000000";
wait for 20 ns;
sample_done <= '1'; -- sample for red
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "1001001111";
wait for 20 ns;
sample_done <= '1'; -- sample for green
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_done <= '1'; -- sample for blue
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "0000000000";
wait for 20 ns;
sample_done <= '1'; -- sample for red
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "1001001111";
wait for 20 ns;
sample_done <= '1'; -- sample for green
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_done <= '1'; -- sample for blue
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "0000000000";
wait for 20 ns;
sample_done <= '1'; -- sample for red
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_data <= "1001001111";
wait for 20 ns;
sample_done <= '1'; -- sample for green
wait for 20 ns;
sample_done <= '0';
wait for 1 us;
sample_done <= '1'; -- sample for blue
wait for 20 ns;
sample_done <= '0';
wait for 1 us;

end process;
end Behavioral;
