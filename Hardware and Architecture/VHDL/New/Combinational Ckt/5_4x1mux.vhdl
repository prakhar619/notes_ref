library ieee;
use ieee.std_logic_1164.all;

entity mux_4x1 is
	port(
		i0,i1,i2,i3: in std_logic;
		s0,s1: in std_logic;
		o: out std_logic
	);
end mux_4x1;

architecture mux_4x1_behv of mux_4x1 is
begin
	mux_4x1_pr: process(i0,i1,i2,i3,s0,s1)
	begin
		if s0='0' and s1='0' then
		o<=i0;
		elsif s0='1' and s1='0' then
		o<=i1;
		elsif s0='0' and s1='1' then
		o<=i2;
		elsif s0='1' and s1='1' then
		o<=i3;
		end if;
	end process;
end mux_4x1_behv;



