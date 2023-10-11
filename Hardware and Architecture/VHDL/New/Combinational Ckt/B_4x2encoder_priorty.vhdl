library ieee;
use ieee.std_logic_1164.all;

entity priortyEncoder_4x2 is
	port(
		i: in std_logic_vector(3 downto 0);
		z: out std_logic;
		o0,o1: out std_logic
	);
end entity;

architecture priortyEncoder_4x2_behv of priortyEncoder_4x2 is
begin
	priortyEncoder_4x2_pr:process(i)
	begin
		if i="0000" then
		z <= '0';
		elsif i(3)='1' then
		o0<='1';
		o1<='1';
		z <= '1';
		elsif i(2)='1' then
		o0<='0';
		o1<='1';
		z <= '1';
		elsif i(1)='1' then
		o0<='1';
		o1<='0';
		z <= '1';
		elsif i(0)='1' then
		o0<='0';
		o1<='0';
		z <= '1';
		end if;
	end process;
end architecture;