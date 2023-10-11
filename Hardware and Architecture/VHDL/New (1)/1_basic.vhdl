-- Very High Speed Integration Circuit HDL
-- IEEE standard HDL

-- Uses	1.Hardware Describtion 2. Modeling 3. Synthesis 4.Simulation

--# Some simulated code cannot be synthesised
--Case Insensitive Language


-- Basic Elements of VHDL	1. Entity	2. Architecture		3. Configuration	4. Package
-- 1. Entity: Outside view like PORT, GENERICS (time delay)
-- 2. Architecture: Inside view like connections
-- 3. Configuration: 




library ieee;			--library standard or library ieee, altera
use ieee.std_logic_1164.all;

package half_adder_pack is
	entity half_adder(a,b :in std_logic; carry_out,sum :out std_logic);
	end half_adder_pack;

package body half_adder_pack is

entity half_adder is
	generic(
			--define default values of signals here
			--time, bus_size, 
	
		);
	port(	
		a,b:in std_logic;
		carry_out,sum:out std_logic
		--CLASS: Actually SIGNAL a,b:in std_logic	(signal is assumed and therefore optional)
		--MODE:in,out,inout,buffer
		
		--Syntax: <class> object_name : <mode> <type>;
	    );
	end half_adder;
	--ALTERNATE OPTION TO END
		-- end;
		-- end half_adder;
		-- end entity;
		-- end entity half_adder;
		
	
--Entity can have multiple architectures
--Architecture statement execute concurrently

architecture dataflow_hlf_add of half_adder is
	begin
		sum<= a xor b;
		carry_out<= a and b;
	end dataflow_hlf_add;


end package half_adder_pack;
	
		
		
		
