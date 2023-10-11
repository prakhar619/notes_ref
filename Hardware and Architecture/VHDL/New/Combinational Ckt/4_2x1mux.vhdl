--Mux 2x1

library ieee;
use ieee.std_logic_1164.all;

entity mux_2x1 is
	port(
		i0,i1: in std_logic;
		s: in std_logic;
		o: out std_logic
	);
end mux_2x1;

architecture mux_2x1_behv of mux_2x1 is
begin	
	mux_2x1_pr:process(i0,i1,s)
	begin
		if s='0' then
		o<=i0;
		elsif s='1' then 
		o<=i1;
		end if;
	end process;
end mux_2x1_behv;
