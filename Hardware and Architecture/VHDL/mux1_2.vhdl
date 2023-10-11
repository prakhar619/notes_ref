--author:Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;

entity mux1_2_1 is
    port (I0,I_0 : in std_logic;
    O0,O1 : out std_logic);
    end mux1_2_1;

    architecture func_mux1_2_1 of mux1_2_1 is 
    signal S0 : std_logic;
    begin
        U0 : and_1 port map (I0,I_0,O1);
        U1 : not_1 port map (I_0,S0);
        U2 : and_1 port map (S0,I0,O0);
        end func_mux1_2_1;
        