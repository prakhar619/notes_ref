--author   Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;
entity fulladder_1 is 
    port(I0,I1,I2 : in std_logic;
        O0,O1 : out std_logic);
        end fulladder_1;

architecture func_fulladder_1 of fulladder_1 is 
    signal S0,S1,S2 : std_logic;
    begin 
    U0: halfadder_1 port map (I0,I1,S0,S1);
    U1: halfadder_1 port map (I2,S0,O0,S2);
    U2: or_1 port map (S1,S2,O1);
    end func_fulladder_1;

