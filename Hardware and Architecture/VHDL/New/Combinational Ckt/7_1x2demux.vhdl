library ieee;
use ieee.std_logic_1164.all;

entity demux_1x2 is
	port(
		i: in std_logic;
		s: in std_logic;
		o0,o1: out std_logic
	);
end demux_1x2;

architecture demux_1x2_behv of demux_1x2 is
begin
	demux_1x2_pr: process(i,s)
	begin
		if s='0' then
		o0<= i;
		o1<='0'
		elsif s='1' then
		o1<= i;
		o0<='0'
		end if;
	end process;
end architecture;