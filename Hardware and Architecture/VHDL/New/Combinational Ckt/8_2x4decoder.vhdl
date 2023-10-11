library ieee;
use ieee.std_logic_1164.all;

entity decoder_2x4 is
	port(
		i0,i1:in std_logic;
		E_n: in std_logic;
		Y: out std_logic_vector(3 downto 0)
	);
end entity;

architecture decoder_2x4_behv of decoder_2x4 is
begin
	decoder_2x4_pr:process(i0,i1,E_n)
	begin
		if E_n='0' then
		Y<= "0000";
		elsif E_n='1' then
			if   i1='0' and i0='0' then
			Y<= "0001";
			elsif i1='0' and i0='1' then
			Y<= "0010";
			elsif i1='1' and i0='0' then
			Y<= "0100";
			elsif i1='1' and i0='1' then
			Y<= "1000";
			end if;
		end if;
	end process;
end architecture;
			