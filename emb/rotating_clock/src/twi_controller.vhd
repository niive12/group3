
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_unsigned.all;

entity twi_controller IS
  PORT(
    clk       	: IN	STD_LOGIC;                     --system clock
    reset_n   	: OUT 	STD_LOGIC;                    --active low reset
    ena       	: OUT 	STD_LOGIC;                    --latch in command
    addr      	: OUT 	STD_LOGIC_VECTOR(6 DOWNTO 0); --address of target slave
    rw        	: OUT	STD_LOGIC;                    --'0' is write, '1' is read
    data_wr   	: OUT	STD_LOGIC_VECTOR(7 DOWNTO 0); --data to write to slave
    busy      	: IN	STD_LOGIC);                   --indicates transaction in progress
    led_config 	: IN 	STD_LOGIC_VECTOR(15 downto 0) -- LED configuration to be send to IO extender
END twi_controller;

architecture Behavioral of twi_controller IS
constant address           	: STD_LOGIC_VECTOR(6 downto 0) :=  "1000000";  --0x40 Constant Slave address
constant output_control_1 	: STD_LOGIC_VECTOR(7 downto 0) := "00000010";  --0x02 Control for each diode
constant output_control_2 	: STD_LOGIC_VECTOR(7 downto 0) := "00000011";  --0x03 Control for each diode
constant general_control_1 	: STD_LOGIC_VECTOR(7 downto 0) := "00000110";  --0x06 Needed for initialization of IO extender
constant general_control_2 	: STD_LOGIC_VECTOR(7 downto 0) := "00000111";  --0x07 Needed for initialization of IO extender
signal initialized       	: STD_LOGIC := '0';

BEGIN 

control_process:
process(clk)
variable busy_counter 	:= integer range 0 to 4 := 0;
variable prev_busy   	:= STD_LOGIC := '1';
begin
if rising_edge(clk) then
  if (busy = '0') and (prev_busy = '1') then
	busy_counter := busy_counter + 1;
  end if;
  if initialized = '0' then                          -- If the LED board has not been initialized it should set up the IO extenders
	if busy_counter = 1 then
	  data_wr <= general_control_1;                  -- General control register address
	elsif busy_counter = 3 then
	  data_wr <= general_control_2;
	else
	  data_wr <= (others => '0');                    -- Set general control to 0 for output
	end if;
	if busy_counter = 4 then                         -- If 3 busy signals has been recevied, the initialization is done.
	  initiialized <= '1';
	  busy_counter := 0;
	end if;
  else
	if busy_counter = 0 then
	  data_wr <= output_control_1;
	elsif busy_counter = 1 then
	  data_wr <= led_config(7 downto 0);
	elsif busy_counter = 2 then
	  data_wr <= output_control_2;
	else
	  data_wr <= led_config(15 downto 8);
	  busy_counter := 0;
	end if;
  end if;
  
end if;
end process;

rw <= '0';
addr <= address;
END Behavioral;
