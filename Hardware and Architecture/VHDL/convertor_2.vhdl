--author : Prakhar Gupta  2103126---
library IEEE;
use IEEE.std_logic_1164.all;
use work.combine_pack.all;

entity converter_2 is
	port(   I0 : in std_logic_vector(3 downto 0);
			O0 : out std_logic_vector(3 downto 0));
end converter_2 ;

architecture func_converter_2 of converter_2 IS
	signal S_0 : std_logic_vector(6 downto 0);
begin
A0: not_1 port map (I0(0),O0(0));
A1: and_1 port map (I0(0),I0(1),S_0(0));
A2: or_1 port map (I0(0),I0(1),S_0(1));
A3: not_1 port map (I0(2),S_0(2));

A4: not_1 port map (S_0(1),S_0(3));

A5: or_1 port map (S_0(0),S_0(3),O0(1));
A6: and_1 port map (S_0(3),I0(2),S_0(4));
A7: and_1 port map (S_0(1),S_0(2),S_0(5));
A8: and_1 port map (S_0(1),I0(2),S_0(6));

A9: or_1 port map (S_0(4),S_0(5),O0(2));
A10: or_1 port map (S_0(6),I0(3),O0(3));

END func_converter_2;