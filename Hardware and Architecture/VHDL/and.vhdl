--author:Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
entity and_1 is
    port (I0,I1 : in std_logic; 
    O0 : out std_logic);
    end and_1;
    
architecture func_and_1 of and_1 is 
    begin   
    O0 <= I0 and I1;
    end func_and_1;

