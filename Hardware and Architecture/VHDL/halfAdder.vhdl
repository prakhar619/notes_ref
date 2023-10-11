-- author Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;
entity halfadder_1 is 
    port (I0,I1 : in std_logic;
            O,C0 : out std_logic);
            end halfadder_1;
    
architecture func_halfadder_1 of halfadder_1 is 
    begin   
        U0 : xor_1 port map (I0,I1,O);
        U1 : and_1 port map (I0,I1,C0);
    end func_halfadder_1 ;