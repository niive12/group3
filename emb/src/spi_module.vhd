----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/06/2015 08:18:55 PM
-- Design Name: 
-- Module Name: spi_module - Behavioral
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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity spi_module is
    Port ( 
           --SPI wires
           MISO             : in STD_LOGIC;           
           MOSI             : out STD_LOGIC;
           CS               : out STD_LOGIC;
           SCLK             : out STD_LOGIC;
                      
           -- For communication with controller
           data_in          : in STD_LOGIC_VECTOR(4 downto 0); -- Data from controller to be sent to ADC
           data_in_ready    : in  STD_LOGIC; -- Signal to pull chip select low
           
           data_out         : out STD_LOGIC_VECTOR(9 downto 0); -- Data recieved from the ADC to be sent to controller
           data_out_ready   : out STD_LOGIC; -- Signal to the controller that a whole package is received 
           
           clk              : in STD_LOGIC --system clock
           );
end spi_module;

architecture Behavioral of spi_module is
signal slow_clk          : std_logic := '1';
signal clock_enable		 : std_logic := '0';
signal pack 			 : std_logic_vector(4 downto 0) := "00000";
signal data_from_adc	 : std_logic_vector(9 downto 0) := "0000000000";
begin

spi_clk: --Generate the spi clock signal
process(clk)
variable counter : integer range 0 to 6 := 0; -- 14 * 20 ns = 280 ns which gives 3.571 MHz clk
begin
  if rising_edge(clk) AND (clock_enable = '1') then
    if counter = 6 then
        counter := 0;
        slow_clk <= not slow_clk;
    else
        counter := counter + 1;
    end if;
  end if;
end process;


--Process to read the package from controller once per state shift in controller
dataprocess:
process(clk,data_in_ready,slow_clk)
variable counter : integer range 0 to 17 := 0;
begin
  if data_in_ready = '1' then
	pack <= data_in;
	clock_enable <= '1';
  elsif rising_edge(slow_clk) then
	data_out_ready <= '0';
	CS <= '0';
	MOSI <= pack(4);
	pack <= pack(3 downto 0) & '0';
	if counter > 6 then
	data_from_adc <= data_from_adc(8 downto 0) & MISO;
	end if;
	if counter = 17 then 
	  clock_enable <= '0';
	  data_out <= data_from_adc;
	  data_out_ready <='1';
	  counter := 0;
	  CS <= '1';
	else
	  counter := counter + 1;
	end if;
  end if;
end process;

SCLK <= slow_clk;

end Behavioral;
