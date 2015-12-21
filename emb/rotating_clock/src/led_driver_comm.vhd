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
    start_data      : in  std_logic_vector(1 downto 0);  -- signal to indicate that transaction should start
                    
    clk             : in  std_logic                     
);
end led_driver_comm;

architecture Behavioral of led_driver_comm is
signal serial_clk : STD_LOGIC := '0';
signal n_id : std_logic_vector(1 downto 0) := "01";

begin

s_clk <= serial_clk; -- Set signal out to the wire

data_process: process(clk)
variable serial_cnt : integer range 1 to 400 :=1 ; -- Max 25 MHz. With 200, it gives a period time of 8 µs = 125 kHz
variable counter : integer range 0 to 33;
variable send_state : std_logic := '0';
variable t_data : std_logic_vector(31 downto 0) := (others => '0');
begin
    if rising_edge(clk) then
        if send_state = '0' then
            send_complete <= '1';
            if start_data = n_id then
                send_complete <= '0';
                send_state := '1';
                t_data := data;
            end if;
        else 
            if serial_cnt = 400 then
                serial_cnt := 1;
                serial_clk <= not serial_clk;
                if counter = 32 then
                    latch <= '1';
                    counter := counter + 1;
                elsif counter = 33 then
                    counter := 0;
                    n_id <= std_logic_vector(unsigned(n_id) +1);
                    latch <= '0';
                    send_complete <= '1';
                else
                    s_out <= data(counter);	
                    counter := counter + 1;
                end if;
            elsif serial_cnt = 200 then
                serial_clk <= not serial_clk;
                serial_cnt := serial_cnt + 1;
            else
                serial_cnt := serial_cnt + 1;
            end if;
        end if;
  end if;
end process;

end Behavioral;
