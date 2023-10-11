library ieee;
use ieee.std_logic_1164.all;

entity mux_16x4 is
	port(
		A,B,C,D: in std_logic_vector(3 downto 0);
		s0,s1: in std_logic;
		O: out std_logic_vector(3 downto 0)
	);
end mux_16x4;

architecture mux_16x4_behv of mux_16x4 is
begin
	mux_16x4_pr: process(A,B,C,D,s0,s1)
	begin
		if s0='0' and s1='0' then
		O<=A;
		elsif s0='1' and s1='0' then
		O<=B;
		elsif s0='0' and s1='1' then
		O<=C;
		elsif s0='1' and s1='1' then 
		O<=D;
		end if;
	end process;
end mux_16x4_behv;

		
