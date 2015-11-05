----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/22/2015 11:16:14 AM
-- Design Name: 
-- Module Name: tlmslider - Behavioral
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

entity tlmslider is
    Port ( 
		   MISO             	: in STD_LOGIC;           
           MOSI             	: out STD_LOGIC;
           CS               	: out STD_LOGIC;
           SCLK             	: out STD_LOGIC;
           
           pwm_out 				: out STD_LOGIC;

           red_out 				: out STD_LOGIC;
           blue_out 			: out STD_LOGIC;
           green_out 			: out STD_LOGIC;
		   
		   Serial_in			: in STD_LOGIC;
		   Serial_out 			: out STD_LOGIC;
		   
           clk              	: in STD_LOGIC --system clock
           );
end tlmslider;

architecture Behavioral of tlmslider is
COMPONENT spi_module
    Port ( 
           --SPI wires
           MISO             : in STD_LOGIC;           
           MOSI             : out STD_LOGIC;
           CS               : out STD_LOGIC;
           SCLK             : out STD_LOGIC;
                      
           -- For communication with controller
           data_in          : in STD_LOGIC_VECTOR(5 downto 0); -- Data from controller to be sent to ADC
           data_in_ready    : in  STD_LOGIC; -- Signal to pull chip select low
           
           data_out         : out STD_LOGIC_VECTOR(9 downto 0); -- Data recieved from the ADC to be sent to controller
           data_out_ready   : out STD_LOGIC; -- Signal to the controller that a whole package is received 
           
           clk              : in STD_LOGIC --system clock
           );
end COMPONENT;

COMPONENT MotorControl
Port (
  pwm_out 			: out STD_LOGIC;
  
  colours_detected 	: in STD_LOGIC_VECTOR(2 downto 0); --  RED & GREEN & BLUE
  clk				: in STD_LOGIC
);
end COMPONENT;

COMPONENT PTNX_top
Port (
	   clk				: in	STD_LOGIC;                       -- 50 MHz from onboard oscillator
	   XB_SERIAL_O   	: out	STD_LOGIC;                       -- Serial stream to PC
	   XB_SERIAL_I	   	: in	STD_LOGIC;                       -- Serial stream from PC
	   color_val 		: in STD_LOGIC_VECTOR(31 downto 0);
	   threshold 		: out STD_LOGIC_VECTOR(31 downto 0)
	  );
end COMPONENT;

COMPONENT LED_driver
    Port (
           red_led 				: out STD_LOGIC;
           blue_led 			: out STD_LOGIC;
           green_led 			: out STD_LOGIC;
           
           detected 			: out STD_LOGIC_VECTOR(2 downto 0);
           
           threshold_container 	: in STD_LOGIC_VECTOR(31 downto 0);
           color_val            : out STD_LOGIC_VECTOR(31 downto 0);
           
           sample_data 			: in STD_LOGIC_VECTOR (9 downto 0);
           sample_done 			: in STD_LOGIC;
		   start_sample 		: out STD_LOGIC;
		   header 				: out STD_LOGIC_VECTOR(5 downto 0);
            
           clk				 	: in STD_LOGIC);
end COMPONENT;

signal detected : STD_LOGIC_VECTOR(2 downto 0);
signal sample_data : STD_LOGIC_VECTOR(9 downto 0):= (others => '0');
signal header : STD_LOGIC_VECTOR(5 downto 0);
signal start_sample : STD_LOGIC;
signal sample_done : STD_LOGIC;
signal color_val : STD_LOGIC_VECTOR(31 downto 0);

signal threshold : STD_LOGIC_VECTOR(31 downto 0);

begin

driver : LED_driver port map (
		 clk =>clk,
		 red_led => red_out,
		 blue_led => blue_out,
		 green_led => green_out,
		 detected => detected,
		 threshold_container => threshold,
		 color_val => color_val,
		 sample_data => sample_data,
		 sample_done => sample_done,
		 header => header,
		 start_sample => start_sample
		 );
	
controller : MotorControl port map(
		 clk => clk,
		 pwm_out => pwm_out,
		 colours_detected => detected
		 );

spi : spi_module port map(
		 MOSI => MOSI,
		 MISO => MISO,
		 CS => CS,
		 SCLK => SCLK,
		 clk => clk,
		 data_in_ready => start_sample,
		 data_out_ready => sample_done,
		 data_out => sample_data,
		 data_in => header
	);
	
tosnet : PTNX_top port map(
  clk 			=> clk,
  XB_SERIAL_I 	=> Serial_in,
  XB_SERIAL_O 	=> Serial_out,
  threshold 	=> threshold,
  color_val 	=> color_val
);
end Behavioral;
