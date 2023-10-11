--author : Prakhar Gupta  2103126---
library IEEE;
use IEEE.std_logic_1164.all;
use work.combine_pack.all;

entity bcd_ssd is
    port(X : in std_logic_vector(3 downto 0);
        Y : out std_logic_vector(6 downto 0);
        F : out std_logic);
end bcd_ssd;

architecture func_bcd_ssd of bcd_ssd is

signal S : std_logic_vector(16 downto 0);
signal N : std_logic_vector(3 downto 0);

begin
    
    N1 : NOT_1 port map (X(3),N(0));   
    N2 : NOT_1 port map (X(2),N(1));   
    N3 : NOT_1 port map (X(1),N(2));   
    N4 : NOT_1 port map (X(0),N(3));   
    
    a1 : AND_1 port map (N(2),N(3),S(0));
    a2 : AND_1 port map (X(2),S(0),S(1));
    a3 : AND_1 port map (N(0),N(1),S(2));
    a4 : AND_1 port map (N(2),X(0),S(3));
    a5 : AND_1 port map (S(2),S(3),S(4));
    a6 : OR_1 port map (S(1),S(4),Y(6));
    
    b1 : XOR_1 port map (X(1),X(0),S(5));
    b2 : AND_1 port map (X(2),S(5),Y(5));
    
    c1 : AND_1 port map (N(1),X(1),S(6));
    c2 : AND_1 port map (S(6),N(3),Y(4));
    
    d1 : AND_1 port map (X(2),X(1),S(7));
    d2 : AND_1 port map (S(7),X(0),S(8));
    d3 : OR_1 port map (S(1),S(4),S(14));
    d4 : OR_1 port map (S(14),S(8),Y(3));
    
    e1 : AND_1 port map (X(1),X(0),S(9));
    e2 : OR_1 port map (S(1),S(9),S(10));
    e3 : OR_1 port map (S(10),S(3),Y(2));
    
    f1 : OR_1 port map (X(1),X(0),S(11));
    f2 : AND_1 port map (S(2),S(11),S(12));
    f3 : OR_1 port map (S(9),S(12),Y(1));
    
    g1 : AND_1 port map (S(2),N(2),S(13));
    g2 : OR_1 port map (S(8),S(13),Y(0));
    
    In1 : AND_1 port map (X(3),X(2),S(15));
    In2 : AND_1 port map (X(3),X(1),S(16));
    In3 : OR_1 port map (S(15),S(16),F);
    
end func_bcd_ssd;