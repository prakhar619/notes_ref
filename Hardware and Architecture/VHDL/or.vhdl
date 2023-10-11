--author:Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
entity or_1 is
    port(I0 , I1 : in std_logic;
    O0 : out std_logic);
    end or_1;
architecture func_or_1 of or_1 is
    begin
        O0 <= I0 or I1;
        end func_or_1;

            