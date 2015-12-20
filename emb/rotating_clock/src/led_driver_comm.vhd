library IEEE;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity led_driver_comm is
Port (
    s_clk           : out std_logic; -- serial clock.
    s_out           : out std_logic; -- signal.
    latch           : out std_logic; -- latch signal to signal end of signal.
                    
    data            : in  std_logic_vector(31 downto 0);
                    
    send_complete   : out std_logic; -- signal to indicate that a transaction is complete.
    start_data      : in  std_logic;  -- signal to indicate that transaction should start
                    
    clk             : in  std_logic                     
);
end led_driver_comm;

architecture Behavioral of led_driver_comm is
signal serial_clk : STD_LOGIC := '0';
signal test_out_1 : STD_LOGIC := '0';
signal test_out_2 : STD_LOGIC := '0';
signal test_out_3 : STD_LOGIC := '0';
signal n_id : STD_LOGIC := '1';

begin

clock_process:
process(clk)
variable counter : integer range 1 to 200 :=1 ; -- Max 25 MHz. With 200, it gives a period time of 8 µs = 125 kHz
begin
if rising_edge(clk) then
  if counter = 200 then
	serial_clk <= not serial_clk;
	counter := 1;
  else
	counter := counter + 1;
  end if;
end if;
end process;

s_clk <= serial_clk; -- Set signal out to the wire

data_process:
process(serial_clk)
variable counter : integer range 0 to 32;
begin
  if rising_edge(serial_clk) then
	if start_data = n_id then
	  if counter = 32 then
	  	n_id <= not n_id;
	  	latch <= '1';
	  else
		s_out <= data(counter);	
		counter := counter + 1;
	  end if;
	end if;
  end if;
end process;

send_complete <= n_id;
end Behavioral;
