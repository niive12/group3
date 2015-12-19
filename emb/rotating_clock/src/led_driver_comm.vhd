library IEEE;

use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity led_driver_comm is
Port (
  s_clk  		: out STD_LOGIC; -- Serial clock.
  s_out        	: out STD_LOGIC; -- Signal.
  latch        	: out STD_LOGIC; -- Latch signal to signal end of signal.
  
  t_out       	: out STD_LOGIC_VECTOR(2 downto 0);
  data         	: in STD_LOGIC_VECTOR(31 downto 0);
  
  send_complete : out STD_LOGIC; -- Signal to indicate that a transaction is complete.
  start_data  	: in STD_LOGIC;  -- Signal to indicate that transaction should start
  
  clk        	: in STD_LOGIC
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

test_process_one:
process(clk)
variable counter : integer range 1 to 200 :=1 ; -- Max 25 MHz. With 200, it gives a period time of 8 µs = 125 kHz
begin
if rising_edge(clk) then
  if counter = 200 then
	test_out_1 <= not test_out_1;
	counter := 1;
  else
	counter := counter + 1;
  end if;
end if;
end process;

test_process_two:
process(clk)
variable counter : integer range 1 to 50 :=1 ; -- Max 25 MHz. With 50, it gives a period time of 2 µs = 500 kHz
begin
if rising_edge(clk) then
  if counter = 50 then
	test_out_2 <= not test_out_2;
	counter := 1;
  else
	counter := counter + 1;
  end if;
end if;
end process;

test_process_three: -- Only for testing purpose.
process(clk)
variable counter : integer range 1 to 100 :=1 ; -- Max 25 MHz. With 100, it gives a period time of 4 µs = 250 kHz
begin
if rising_edge(clk) then
  if counter = 100 then
	test_out_3 <= not test_out_3;
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

t_out <= test_out_1 & test_out_2 & test_out_3;

send_complete <= n_id;
end Behavioral;
