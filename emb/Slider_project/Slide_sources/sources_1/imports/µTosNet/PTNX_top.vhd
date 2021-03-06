-------------------------------------------------------------------------------
-- Platform:     SDU/TEK/Embedix Spartan-3 50AN experimentation board +
--                               Expansion board with: USB + Ethernet + VGA
-- Application:  Example Pseudo TosNet application (over USB UART)
--               Use serial port setting: 115200 bps 8N1
--==============+==========+===================================================
-- History:     | Anns = Anders Stengaard Sørensen | Sifa = Simon Falsig 
----------------+----------+---------------------------------------------------     
--  Date        | Author   | Action
----------------+----------+---------------------------------------------------
-- 2009_11_30   | Anss     | Created
--              |          |
-------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Here we define the I/O connections from the example
-- Since this is the top level, the connections all go to the outside world
entity PTNX_top is      -- PTNX = "Pseudo TosNet eXample"
Port (
	   clk			: in	STD_LOGIC;                       -- 50 MHz from onboard oscillator
	   XB_SERIAL_O   		: out	STD_LOGIC;                       -- Serial stream to PC
	   XB_SERIAL_I	   	: in	STD_LOGIC;                       -- Serial stream from PC
	   --brick_counter	: in STD_LOGIC_VECTOR(11 downto 0);
	   data_adc 		: in STD_LOGIC_VECTOR(9 downto 0);
	   threshold 		: out STD_LOGIC_VECTOR(29 downto 0)
	  );
end PTNX_top;

architecture Behavioral of PTNX_top is

-- Here we define the components we want to include in our design (there is only one)
-- The Port description is just copied from the components own source file
	COMPONENT PseudoTosNet_ctrl is
	Port (
		T_clk_50M							: STD_LOGIC;
		T_serial_out						: out STD_LOGIC;
		T_serial_in                   : in  STD_LOGIC;
		T_reg_ptr							: out std_logic_vector(2 downto 0);
		T_word_ptr							: out std_logic_vector(1 downto 0);
		T_data_to_mem						: in  std_logic_vector(31 downto 0);
		T_data_from_mem					: out std_logic_vector(31 downto 0);
		T_data_from_mem_latch			: out std_logic
		);
	END COMPONENT;

-- Here we define the signals used by the top level design
  signal clk_50M           : std_logic := '0';
  signal threshold_red  : STD_LOGIC_VECTOR(9 downto 0) := "00" & "1000" & "0000";
  signal threshold_green : STD_LOGIC_VECTOR(9 downto 0) := "00" & "1000" & "0000";
  signal threshold_blue : STD_LOGIC_VECTOR(9 downto 0) := "00" & "1000" & "0000";
  --signal bricks : STD_LOGIC_VECTOR(11 downto 0) := (others => '0');
  signal adc_data	: STD_LOGIC_VECTOR(9 downto 0);
    
-- Signals below is used to connect to the Pseudo TosNet Controller component  
  signal T_reg_ptr                 : std_logic_vector(2 downto 0);
  signal T_word_ptr                : std_logic_vector(1 downto 0);
  signal T_data_to_mem             : std_logic_vector(31 downto 0);
  signal T_data_from_mem           : std_logic_vector(31 downto 0);
  signal T_data_from_mem_latch     : std_logic;
	
begin

-- Here we instantiate the Pseudo TosNet Controller component, and connect it's ports to signals	
	PseudoTosNet_ctrlInst : PseudoTosNet_ctrl
	Port map (
	   T_clk_50M          => clk_50M,
		T_serial_out       => XB_SERIAL_O,
		T_serial_in        => XB_SERIAL_I,
		T_reg_ptr		     => T_reg_ptr,					
		T_word_ptr		     => T_word_ptr,									
		T_data_to_mem	     => T_data_to_mem,					
		T_data_from_mem	     => T_data_from_mem,						
		T_data_from_mem_latch => T_data_from_mem_latch						
		);

-- It's not necessary to transfer these ports to signals, we just think it makes the syntax nicer
-- to avoid referring to ports in the body of the code. The compiler will optimize identical signals away
clk_50M <= clk;
threshold <= threshold_red & threshold_green & threshold_blue;
adc_data <= data_adc;
--bricks <= brick_counter;
---------------------------------------------------------
-- Clocked process, to take data off the controller bus	
----------------------------------------------------------
  DatFromTosNet: 	
  process(clk_50M)
  begin -- process
    if (clk_50M'event and clk_50M='1' and T_data_from_mem_latch='1') then
	   case (T_reg_ptr & T_word_ptr) is                        -- The addresses are concatenated for compact code
		  when "00000" => 	threshold_red  	<= T_data_from_mem(9 downto 0);
		  when "00001" => 	threshold_green <= T_data_from_mem(9 downto 0);
		  when "00010" => 	threshold_blue 	<= T_data_from_mem(9 downto 0);
		  when others =>
		end case;
	 end if;
  end process;

----------------------------------------------------------
-- Unclocked process, to place data on the controller bus
----------------------------------------------------------
   DatToTosNet:
	process(T_reg_ptr,T_word_ptr)
	begin
		T_data_to_mem<="00000000000000000000000000000000";	-- default data
		case (T_reg_ptr & T_word_ptr) is                   -- The addresses are concatenated for compact code
		   -- Register 0, word 0-3 are hard coded to these values for test/demo purposes
			--when "00000" =>	T_data_to_mem <= "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & bricks(3 downto 0);	
			--when "00001" =>	T_data_to_mem <= "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & bricks(7 downto 4);	
			--when "00010" => T_data_to_mem <= "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & "0000" & bricks(11 downto 8);
         -- Register 1
			when "00100" =>	T_data_to_mem <=  "00" & "0000" & "0000" & "0000" & "0000" & "0000" & adc_data;
			when others =>
		end case;		
	end process;

end Behavioral;

