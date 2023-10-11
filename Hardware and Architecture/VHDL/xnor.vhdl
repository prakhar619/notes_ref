--author:Prakhar Gupta (2103126)

library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;
entity xnor_1 is    
    port (I0,I1:in std_logic;
    O0: out std_logic);
    end xnor_1;

architecture func_xnor_1 of xnor_1 is
    signal S0,S1,S2,S3,S4 : std_logic;
    begin   
        U0 : not_1 port map (I0,S0);
        U1 : not_1 port map (I1,S1);
        U2 : and_1 port map (I0,S1,S2);
        U3 : and_1 port map (I1,S0,S3);
        U4 : or_1 port map (S2,S3,S4);
        U5 : not_1 port map (S4,O0);
    end func_xnor_1;
            