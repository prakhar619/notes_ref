--author:Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;
entity mux2_1_1 is
    port (I0,I1,I_0 : in std_logic;
        O0 : out std_logic);
        end mux2_1_1;

        architecture func_mux2_1_1 of mux2_1_1 is
            signal S0,S1,S2 : std_logic;
            begin
                U0 : and_1 port map (I1,I_0,S0);
                U1 : not_1 port map (I_0,S1);
                U2 : and_1 port map (I0,S1,S2);
                U3 : or_1 port map (S0,S2,O0);
                end func_mux2_1_1;
        
