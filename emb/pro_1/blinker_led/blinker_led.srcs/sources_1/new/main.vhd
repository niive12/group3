---------------------------------------------------------------------------------
---- Platform: SDU/TEK/Embedix Spartan-3 50AN experimentation board
-----------------------------+----------+----------------------------------------
---- History:
-- Date
-- | Author
-- | Action
---- Created:
-- 2009_11_20
-- | Anss
-- | Created
---------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
entity Blinkled is
Port (
-- The order of declarations are not important to the compiler, but as humans,
-- we like a certain order so we can read and understand the code easily:
-- First we declare signals to/from onboard components
EXTCLK_I
 : in STD_LOGIC;
 -- From the 50MHz clock generator
LED1_O
 : out STD_LOGIC;
 -- To the yellow LED
LED2_O
 : out STD_LOGIC
 -- To the red LED
-- Then we declare signals to the xxx board
-- ... but there are none (yet)
);
end Blinkled;
architecture Behavioral of Blinkled is
signal divider : STD_LOGIC_VECTOR (25 downto 0):= "00000000000000000000000000";
begin
  LED1_O <= divider(24); -- connect bit 24 to LED1
  LED2_O <= divider(25); -- connect bit 25 to LED2
  ClockDivide:
  process (EXTCLK_I) -- this process defines the counter,
  -- that counts the rising edges of extclk
  begin -- process
      if(EXTCLK_I'event and EXTCLK_I ='1') then
      divider <= divider + '1';
      end if;
  end process;
end Behavioral;
