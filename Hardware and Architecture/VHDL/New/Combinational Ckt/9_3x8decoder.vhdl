library ieee;
use ieee.std_logic_1164.all;

entity decoder_3x8 is
	port(
		i:in std_logic_vector(2 downto 0);
		E_n: in std_logic;
		O: out std_logic_vector(7 downto 0)
	);
end entity;

architecture decoder_3x8_behv of decoder_3x8 is
begin
	decoder_3x8_pr:process(i,E_n)
	begin
		if E_n = '0' then
		O<="00000000";
		elsif E_n = '1' then
			if i(0) ='0' and i(1) ='0' and i(2)='0' then
			O<= "00000001";
			elsif i="001" then
			O<= "00000010";
			elsif i="010" then
			O<= "00000100";
			elsif i="011" then
			O<= "00001000";
			elsif i="100" then
			O<= "00010000";
			elsif i="101" then
			O<= "00100000";
			elsif i="110" then
			O<= "01000000";
			elsif i="111" then
			O<= "10000000";
			end if;
		end if;
	end process;
end architecture;
