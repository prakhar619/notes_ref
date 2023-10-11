LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

USE work.combine_pack.ALL;

ENTITY  converter_1 IS
	port(I : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		  O : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
		  INV : OUT STD_LOGIC);
END converter_1;

ARCHITECTURE STRUCTURE OF  converter_1 IS
SIGNAL SN : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL S : STD_LOGIC_VECTOR(14 DOWNTO 0);

BEGIN 
O(0) <= I(0);
U0 :  xor_1 port map (I(0),I(1),O(1));
U1 :  NOT_1 port map(I(0),SN(0));
U2 :  NOT_1 port map(I(1),SN(1));
U3 :  NOT_1 port map(I(2),SN(2));
U4:  and_1 port map (I(0),SN(2),S(0));
U5 :  and_1 port map(I(1),SN(2),S(1));
U6 :  and_1 port map(SN(0),SN(1),S(2));
U7 :  and_1 port map(S(2),I(2),S(3));
U8 :  or_1 port map(S(0),S(1),S(4));
U9 :  or_1 port map(S(4),S(3),O(2));
U10 :  and_1 port map(S(2),I(3),S(5));
U11 :  and_1 port map(I(2),I(3),S(6));
U12 :  or_1 port map(S(5),S(6),O(3));
U13 :  NOT_1 port map(I(3),SN(3));
U14 : and_1 port map(SN(3),SN(2),S(7));
U15 : and_1 port map(S(7),I(0),S(8));
U16 : and_1 port map(S(7),I(1),S(9));
U17 : and_1 port map(I(3),I(2),S(10));
U18 : and_1 port map(S(10),SN(1),S(11));
U19 : and_1 port map(S(10),SN(0),S(12));
U20 : or_1 port map(S(8),S(9),S(13));
U21 : or_1 port map(S(11),S(12),S(14));
U22 : or_1 port map(S(13),S(14),INV);


END STRUCTURE;