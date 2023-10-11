--Package example

--Package header
library ieee;
use ieee.std_logic_1164.all;
package mypack is
	
	component full_adder is
		port(
			i1,i2: in std_logic;
			cin : in std_logic;
			sum,carry: out std_logic
		);
	end component;

end package mypack;


--Package body optional to add architecture if file not attached
-- package body mypack is

--end package body mypack;