--author:Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;

entity mux1_4_1 is
    port(I0 : in std_logic;
    S : in std_logic_vector(1 downto 0);
    O : out std_logic_vector(3 downto 0));
    end mux1_4_1;

    architecture func_mux1_4_1 of mux1_4_1 is
    
        signal S0,S1 : std_logic;
    begin
        U0 : mux1_2_1 port map (I0,S(0),S0,S1);
        U1 : mux1_2_1 port map (S0,S(1),O(0),O(1));
        U2 : mux1_2_1 port map (S1,S(1),O(2),O(3));
    end func_mux1_4_1 ; 