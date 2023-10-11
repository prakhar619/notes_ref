---Prakhar Gupta 2103126
library IEEE;
use IEEE.std_logic_1164.all;

entity CLK_DVD is

    port(CLK_IN : in std_logic;
         RSTN : in std_logic;
         CLK_OUT : out std_logic);
            
end entity;
-- Input clock
-- Active low reset
-- Output clock
architecture FUNCTIONALITY of CLK_DVD is
    signal CNT : integer := 1;
    signal TEMP : std_logic := '0';
begin
    process(CLK_IN, RSTN)
    begin
        if (RSTN = '0') then
            CNT <= 1;
            TEMP <= '0';
        elsif (CLK_IN'event and CLK_IN = '1') then
            CNT <= CNT+1;
            if (CNT = 50000000) then
                TEMP <= not TEMP;
                CNT <= 1;
            end if;
        end if;
        CLK_OUT <= TEMP;
    end process;
end Functionality;