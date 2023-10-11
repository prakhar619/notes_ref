library ieee;
use ieee.std_logic_1164.all;

entity encoder_4x2 is
	port(
		i: in std_logic_vector(3 downto 0);
		o0,o1: out std_logic
	);
end entity;

architecture encoder_4x2_behv of encoder_4x2 is
begin
	encoder_4x2_pr:process(i)
	begin
		if i="0001" then
		o0<='0';
		o1<='0';
		elsif i="0010" then
		o0<='1';
		o1<='0';
		elsif i="0100" then
		o0<='0';
		o1<='1';
		elsif i="1000" then
		o0<='1';
		o1<='1';
		end if;
	end process;
end architecture;