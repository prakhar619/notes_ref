library IEEE;
use IEEE.std_logic_1164.all;
use work.combine_pack.all;

entity BCD_ADD_SUB is
    port(A, B : in std_logic_vector(3 downto 0);
        A_SBAR : in std_logic;
        Y : out std_logic_vector(7 downto 0);
        INVA : out std_logic;
        INVB : out std_logic);
end BCD_ADD_SUB;

architecture STRUCTURE of BCD_ADD_SUB is

signal A0,B0,S,M,SUM1,V,P : std_logic_vector(3 downto 0);
signal SUM,SUM2 : std_logic_vector (4 downto 0);
signal S0,I,J,N,M2 : std_logic;
signal Y0 : std_logic_vector (7 downto 0);

begin
    
    A1 : Converter_1 port map (A(3 downto 0),A0(3 downto 0),INVA);-- 84-2-1 to  bcd
    B1 : Converter_1 port map (B(3 downto 0),B0(3 downto 0),INVB);
    
    NOT0: NOT_1 port map(A_SBAR, S0);
    
    XOR0 : XOR_1 port map (B0(0),S0,S(0));
    XOR1 : XOR_1 port map (B0(1),S0,S(1));
    XOR2 : XOR_1 port map (B0(2),S0,S(2));
    XOR3 : XOR_1 port map (B0(3),S0,S(3));
    
    FB0 : adder_4_bit port map (A0,S,S0,SUM);
    
     U1 : AND_1 port map (SUM(3),SUM(2),P(0));
     U2 : AND_1 port map (SUM(3),SUM(1),P(1));
     U3 : OR_1 port map (P(0),P(1),P(2));
    
     V(0) <= '0';
     V(1) <= P(2);
     V(2) <= P(2);
     V(3) <= '0';
    
     M1 : MUX2_1_1 port map (A_SBAR,S0,A_SBAR,M2);
    
     FB1 : adder_4_bit port map (SUM(3 downto 0),V,M2,SUM2);

    Bbank:
    for i in 0 to 3 generate
        Y0(i) <= SUM2(i);
    end generate;
    
     Y0(4) <= SUM2(4);
     Y0(5) <= '0';
     Y0(6) <= '0';
     Y0(7) <= '0';
    
    
    A2 : Converter_2 port map (Y0(3 downto 0),Y(3 downto 0));-- bcd to xs3
    B2 : Converter_2 port map (Y0(7 downto 4),Y(7 downto 4));
    
end STRUCTURE;
