--author:Prakhar Gupta (2103126)
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;
entity mux4_1_1 is
    port( I : in std_logic_vector(3 downto 0);
    S : in std_logic_vector(1 downto 0);
    O0 : out std_logic);
    end mux4_1_1;

    architecture func_mux4_1_1 of mux4_1_1 is
    signal S0,S1: std_logic;
    begin
        U0: mux2_1_1 port map (I(0),I(1),S(0),S0);
        U1: mux2_1_1 port map ( I(2) , I(3) , S(0), S1);
        U2 : mux2_1_1 port map(S0,S1,S(1),O0);
        end func_mux4_1_1;