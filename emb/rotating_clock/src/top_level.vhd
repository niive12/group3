library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity rotating_clock is
    SCLK            : out std_logic;
    S_DATA          : out std_logic;
    LATCH           : out std_logic;
    PWM             : out std_logic;
    Encoders        : out std_logic_vector(2 downto 0);
        
    CLK             : in  std_logic
);
end rotating_clock;
Port ( 

architecture Behavioral of rotating_clock is
component clock
Port (
    minute          : out integer range 0 to 60;
    second          : out integer range 0 to 60;
    hour            : out integer range 0 to 12;
                    
    clk             : in  std_logic
);
end component;

component display_control
Port (
    -- input from clock
    minute          : in  integer range 0 to 60;
    second          : in  integer range 0 to 60;
    hour            : in  integer range 0 to 12;
    
    -- reading the encoders to reset positions to make sure the watch doesn't drift.
    encoder         : in  std_logic_vector(2 downto 0);
    
    -- led_driver_comm
    led_driver_rdy  : in  std_logic;
    send_data       : out std_logic;
    data            : out std_logic_vector(31 downto 0);
                    
    clk             : in  std_logic
);
end component;

component led_driver_comm
Port (
    s_clk           : out std_logic; -- serial clock.
    s_out           : out std_logic; -- signal.
    latch           : out std_logic; -- latch signal to signal end of signal.
                    
    data            : in  std_logic_vector(31 downto 0);
                    
    send_complete   : out std_logic; -- signal to indicate that a transaction is complete.
    start_data      : in  std_logic;  -- signal to indicate that transaction should start
                    
    clk             : in  std_logic                     
);
end component;

component MotorControl
Port (
    pwm_out         : out std_logic;
                    
    duty            : in  std_logic_vector(6 downto 0); --  Duty cycle 0 - 100 % if the value exceds 100, chose 100 as max
    clk             : in  std_logic
);
end component;

component pid
Port (
    duty            : out std_logic_vector(6 downto 0); --  duty cycle 0 - 100 % if the value exceds 100 the motorcontroller will correct.
    encoder         : in  std_logic_vector(2 downto 0); --  signal with the three hallsensors.
    clk             : in  std_logic
);
end component;

signal duty_cycle   : std_logic_vector(6 downto 0);
signal serial_send  : std_logic;
signal serial_ready : std_logic;
signal serial_data  : std_logic_vector(31 downto 0);

signal time_h       : integer range 0 to 12;
signal time_m       : integer range 0 to 60;
signal time_s       : integer range 0 to 60;

begin

clock_ : clock port map (
    hour            =>   time_h       ,
    minute          =>   time_m       ,
    second          =>   time_s       ,
    clk             =>   CLK
);


dp_ : display_control port map (
    hour            =>   time_h       ,
    minute          =>   time_m       ,
    second          =>   time_s       ,
    encoder         =>   Encoders     ,
    data            =>   serial_data  ,
    led_driver_rdy  =>   serial_ready ,
    send_data       =>   serial_send  ,
    clk             =>   CLK
);

led_driver_ : led_driver_comm port map (
    s_clk           =>   SCLK,
    s_out           =>   S_DATA,
    latch           =>   LATCH,
    data            =>   serial_data  ,
    send_complete   =>   serial_ready ,
    start_data      =>   serial_send  ,
    clk             =>   CLK
);

mot_control_ : MotorControl port map (
    pwm_out         =>   PWM          ,
    duty            =>   duty_cycle   ,
    clk             =>   CLK
);

motor_pid : pid port map (
    duty            =>   duty_cycle   ,
    encoder         =>   Encoders     , 
    clk             =>   CLK
);

end Behavioral;
