--Full Adder
--Half Adder + CIN
--2 bit Adder *
--[1+1 +cin]

library ieee;
use ieee.std_logic_1164.all;

entity full_adder is
	port(
		i1,i2: in std_logic;
		cin : in std_logic;
		sum,carry: out std_logic
	);
end entity;

--architecture full_adder_behv of full_adder is
--begin
--	full_adder_pr:process(i1,i2,cin)   --process(all) discarded in 2008
--	begin	
--		if i1='0' and i2='0' and cin='0' then
--			sum<='0';
--			carry<='0';
--		elsif (i1 or i2) ='0' or (i1 or cin) ='0' or (i2 or cin) ='0' then
--			sum<='1';
--			carry<='0';
--		elsif (( i1 and i2 ) and cin) ='1' then
--			sum<='1';
--			carry<='1';
--		else
--			sum<='0';
--			carry<='1';
--		end if;
--	end process;
--end full_adder_behv;
		
			

library ieee;
use ieee.std_logic_1164.all;

entity half_adder is
	port(
		sum_ha,carry_ha: out std_logic;	--different output ports
		i1_ha,i2_ha:in std_logic		--identical 2 input naming convention
	    );
end half_adder;

architecture half_adder_dtflo of half_adder is
	begin
		sum_ha<= i1_ha xor i2_ha;
		carry_ha <= i1_ha and i2_ha;
 end half_adder_dtflo;

architecture full_adder_stru of full_adder is
component half_adder is
	port(
		sum_ha,carry_ha: out std_logic;	--different output ports		--SAME NAME AS IN ENTITY
		i1_ha,i2_ha:in std_logic
	);
end component;
signal sum_0,carry_0,carry_1: std_logic;
begin
	HA1: half_adder port map( i1_ha=> i1, i2_ha=> i2, sum_ha=>sum_0, carry_ha=>carry_0);
	HA2: half_adder port map( i1_ha=> cin, i2_ha=>sum_0, sum_ha=>sum, carry_ha=>carry_1);
	carry<= (carry_0 or carry_1);
end full_adder_stru;



