library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
package button_type is
    type btn_type is (btn_released,long_press,single_press,double_press);
end package;