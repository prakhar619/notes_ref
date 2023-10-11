--2 bit Adder
--[1+1] bit Adder
--Half Adder


library ieee;
use ieee.std_logic_1164.all;

entity half_adder is
	port(
		sum,carry: out std_logic;	--different output ports
		i1,i2:in std_logic		--identical 2 input naming convention
	    );
end half_adder;

--architecture half_adder_dtflo of half_adder is
--	begin
--		sum<= i1 xor i2;
--		carry <= i1 and i2;
-- end half_adder_dtflo;


--architecture half_adder_behv of half_adder is
--	begin
--	half_adder_pr:process(i1,i2)
--	begin 
--		if i1 = '0' then
--			sum<= not i2
--			carry<= i2
--		else
--			carry<= '0';
--			sum<= i2;
--		end if;
--	end process;
--		end half_adder_behv;


library ieee;
use ieee.std_logic_1164.all;

entity xor_gate is
	port(
		i1_x,i2_x: in std_logic;
		o1_x : out std_logic
	);
	end xor_gate;

architecture xor_gate_dtflo of xor_gate is
	begin
		o1_x <= i1_x xor i2_x;
	end xor_gate_dtflo;

library ieee;
use ieee.std_logic_1164.all;

entity and_gate is		--entity declaration compulsory  --either import from package or declare inside same file
	port(
		i1_a,i2_a: in std_logic;
		o1_a: out std_logic
	);
	end and_gate;

architecture and_gate_dtflo of and_gate is
	begin
		o1_a <= i1_a and i2_a;
	end and_gate_dtflo;



architecture half_adder_stru of half_adder is 
component xor_gate is
	port(
			i1_x,i2_x : in std_logic;
			o1_x : out std_logic
	);
	end component;
component and_gate is
	port(
		i1_a,i2_a : in std_logic;
		o1_a : out std_logic
	);
	end component;
			begin
				pm1: xor_gate port map( i1_x=> i1,i2_x=>i2,o1_x=>sum);
				pm2: and_gate port map( i1_a=> i1,i2_a=>i2,o1_a=>carry);
	end half_adder_stru;



