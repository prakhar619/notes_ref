--author:Prakhar Gupta (2103126)

library ieee;
use ieee.std_logic_1164.all;

entity not_1 is
    port(I0 : in std_logic;
    O0 : out std_logic);
    end not_1;

    architecture func_not_1 of not_1 is
        begin 
        O0 <= not(I0);
        end func_not_1;

        