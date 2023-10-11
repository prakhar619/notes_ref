--2 4bit adder
--dependency on full adder and mypack package

library ieee;
use ieee.std_logic_1164.all;
use work.mypack.all;

entity nibble_adder is
	port(
		A,B: in std_logic_vector(3 downto 0);
		O: out std_logic_vector(3 downto 0);
		carry_out: out std_logic
	);
end entity;

architecture nibble_adder_stru of nibble_adder is
signal carry0,carry1,carry2: std_logic;
begin
FA0: full_adder port map (i1=>A(0),i2=>B(0),cin=>std_logic'('0'),sum=>O(0),carry=>carry0); --cin=>'0' should be valid but xilinx error as '0' can be boolean or std_logic etc...
FA1: full_adder port map (i1=>A(1),i2=>B(1),cin=>carry0,sum=>O(1),carry=>carry1);
FA2: full_adder port map (i1=>A(2),i2=>B(2),cin=>carry1,sum=>O(2),carry=>carry2);
FA3: full_adder port map (i1=>A(3),i2=>B(3),cin=>carry2,sum=>O(3),carry=>carry_out);
end architecture;