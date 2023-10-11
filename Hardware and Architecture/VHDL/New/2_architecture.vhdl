library ieee;
use ieee.std_logic_1164.all;

--architecture namee of entityy is
-- signal temp: integer := 1;
-- constant load : boolean := true;
-- type states is (s1,s2,s3,s4);			--type used to either create user defined data type or array of existing data types
		--type usr_data is (a,b,c,d,e);
		--type int_arr is array(3 downto 0) of integer;
		--type std_vec is array(3 downto 0) of std_logic;
		--type memArray is array(0 to 63) of std_logic_vector(7 downto 0)	(64*8)
	
	-- <component declarations>
	-- <Subtype declarations>
		-- subtype add_int is integer range 0 to 15;
		-- subtype statee is states range a to d;
	-- <function declaration>
	-- <signal and data declaration>
	-- <Attribute declarations>
	-- <Subprogram declarations>
	-- <Subprogram body>
-- begin
	-- <process statement>
	-- <concurrent procedural calls>
	-- <concurrent signal assignment>
	-- <component instantiation statement>
	-- <generate statements>
-- end;

entity half_adder is
	port(	
		a,b:in std_logic;
		carry_out,sum:out std_logic
	    );
	end half_adder;
	
-- Architecture Modelling Styles 	1. Dataflow Style	2. Behavioral Style (process)	3. Structural Style (component)

-- Dataflow Style Modelling
architecture dataflow_hlf_add of half_adder is
	begin
		sum<= a xor b;
		carry_out<= a and b;
	end dataflow_hlf_add;
	--ALTERNATE OPTION TO END
		--end architecture dataflow_hlf_add;
		--end architecture;
		--end;
	
	--Directly implies Gate lvl implementation
	--concurrent


-- Behavioral Style Modelling
architecture behav_hlf_add of half_adder is
	begin 
		ha:process(a,b)	--a,b are sensitivity list	--any change in signal in process's sensitivity list cause the process to be executed
			begin
				if a = '1' then
					sum<= not b;
					carry_out<= b;
				else
					sum<= b;
					carry_out<='0';
				end if;
			end process ha;		--end ha wont work
	end behav_hlf_add;
	--consists of one or more process statement
	--Most abstract style
	--sequential process block but concurrent processes

--Structural Style Modelling	
architecture struct_hlf_add of half_adder is
	component xor_gate is
		port(	i1,i2: in std_logic;
			o1: out std_logic);
		end component;
	component and_gate is
		port( 	i1,i2: in std_logic;
			o1: out std_logic
		    );
		end component;
	begin
		u1: xor_gate port map( i1 => a, i2 => b, o1 => sum);
		u2: and_gate port map( i1 => a, i2 => b, o1 => carry_out);
		
		--Positional Association
		-- u2: and_gate(a,b,carry_out);
		
	end struct_hlf_add
	--interconnected components

--FUNDAMENTALS
	--Constants
	--Signals
	--Signals Assignments
	--Operators
	--Processes
	--Variables
	--Sequentials Statement
	--User-defined types

--Objects
	--Constants	
	--Variables
	--Signals  

entity sample_ent is
	port(i1,i2: in std_logic; o1: out std_logic);
	end sample_ent;
	


--Signal Declaration for array type
--sig: std_logic_vector(3 downto 0);
-- sig<= "0001";



architecture sample_arch of sample_ent is
	signal sig1: std_logic;		--signal name_signal: <data_types>
	signal sig2: std_logic_vector(7 downto 0) 	
	constant con1: integer:= 8;	--constant name_constant: <data_type>:= <value>
	begin
		sig1<='1';
		sig2<="10010101";
		sig2<= x"AD";
		sig2(3 downto 0)<= x"D";
		sig2(5)<= '1';
		
		sig2<= 6x"0f";		--6bit width hexadecimal 001111
		sig2<= 6x"Xf";		--6bit width hexadecimal XX1111
		sig2<= 6Sx"f";		--6bit width hexadecimal signed  11 1111
		sig2<= 6Ux"f";		--6bit width hexadecimal unsigned 00 1111
		sig2<= 6sb"11";		--6bit width signed binary 1111 11
		sig2<= 6uO"7";		--6bit width unsigned octal 000 111
		
	
	
--ieee library: std_logic_1164,numeric_std
	--std_logic
			--'1' high
			--'0' low
			--'x' unknown
			--'Z' tri-state		(not z)
			--'-' Dont care
			--'H' weak high
			--'L' weak low
			--'W' weak unknown
			
	end sample_arch;


		
--Concurrent Signal Assignment
	--Simple Signal Assignment
	--Conditional Signal Assignment
	--Selected Signal Assignment
	
	
--Simple Signal	Assignment
entity sample_ent1 is
	port( i1,i2: in std_logic; o1:out std_logic);
	end sample_ent1;

architecture sample_arch1 of sample_ent1 is
	signal sig: std_logic;
	begin
		sig<= i1 or (i1 and i2);
		o1<= not sig;		--Signal Delay		o1<= not sig after 10ns; or o1<= transport not sig after 10ns;
	end sample_arch1;








--DISCARDED
--Selected Signal Assignment
entity sample_ent2 is
	port( i1,i2: in std_logic; o1:out std_logic);
	end sample_ent1;

architecture sample_arch2 of sample_ent2 is
	signal sig: std_logic;
	begin
		with i1 select
		o1 <= '0' when '0','0' when '1','1' when others;
	end sample_arch2;

--DISCARDED
--Condictional Signal Assignment
entity sample_ent3 is
	port( i1,i2: in std_logic; o1:out std_logic);
	end sample_ent1;

architecture sample_arch3 of sample_ent3 is
	signal sig: std_logic;
	begin
		o1 <= '0' when (i1 = '1' and i2 = '1') else '1' when (i1 = '0' or i2 = '0') else '1';
	end sample_arch3;










--Data Types
	--Scalar Types
		--Integer		(32 bit default)	signal sig: integer 0 to 4; (4 bit)	signal sig: integer -1 to MAXX;	(signed + range defined on constant)
			--positive	(1 to ...)
			--natural	(0 to ...)
		--Floating Point
		--Enumeration
		--Physical
		--Boolean	(true or false)
		--Bit		('0' or '1')
		--character
		--string
		--time		(ps,us,ns,ms,sec,min,hr)
		--real
	--Composite Types
		--Array
		--Record
		
	--std_logic_1164
		--std_logic
			--'0' and '1'		sig_stdLogic <= '1';
			--'1' high
			--'0' low
			--'x' unknown
			--'Z' tri-state		(not z)
			--'-' Dont care
			--'H' weak high
			--'L' weak low
			--'W' weak unknown
		--std_logic_vector
			--arrays of '0' and '1'	
	
		
--Operators
	--Logical Operators
		--and
		--or
		--nand
		--nor
		--xor
		--xnor
		--not
	--Relational Operators
		--=
		--/=	(not equal to)
		-->
		--<
		--<=
		-->=
	--Arithmetic Operators
		--+
		---
		--*
		--/
		--&	(concatenation)
		--mod
		--abs
		--rem
		--**	(exponent)
	--Shift Operators
		--Sll
		--Srl
		--Sla
		--Sra
		--Rol
		--Ror
		
--Order of Precedence Arithmetic (abs > mult_div > & > plus_minus) > Shift Op > Relational > Logical (nand nor xor xnor > not or and)


--Assignment
-- x := true;		x <= sig_vector(5)	(only single bit accessed)
-- y(3 downto 0) := 



--PROCESS
architecture behav_hlf_add of half_adder is
	begin 
		--ha:process(all)
		ha:process(a,b)	--a,b are sensitivity list	--any change in signal in process's sensitivity list cause the process to be executed
			begin	--process statement are infinitely executed unless broken by sensitivity list or wait statements
				if a = '1' then
					sum<= not b;
					carry_out<= b;
				else
					sum<= b;
					carry_out<='0';
				end if;
			end process ha;
	end behav_hlf_add;
	
architecture behav_hlf_add of half_adder is
	begin 
		ha:process			
			begin	
				variable var: integer:= 10;
				--variables are defined inside process
				--no delay in variable updation
				--signals are update at end of process
				if a = '1' then
					sum<= not b;
					carry_out<= b;
				else
					sum<= b;
					carry_out<='0';
				end if;
			wait on(a,b);
			--process cannot have both wait and sensitivity list
			end process ha;
	end behav_hlf_add;
	
--value updation in process happens only when process end;
	--process(a,b)
	-- c <= a and b
	-- o1 <= not c		(here c is not new c, rather old c)
	--end process
	
	--process(a,b)
	--c <= a and b
	--end process
	--process(c)
	-- o1 <= not c		(correct way)
	--end process


--Sequential Statement;

-- if <condition> then
	-- statements
	-- elsif <condition> then
	-- statements
	-- else
	-- statements
	-- end if;

-- case sele is
	-- when "00" => o1 <= "11" ;
	-- statements
	-- when others => <expression>;
	-- end case;

--Looping 
	--while <condition> loop
			--statement
		--end loop;
	
	--for <identifier> in <range> loop
			--statement
			--next or exit
		--end loop;
	
	--loop_infi_1 loop
			--statement
			--exit loop_infi_1 when <condition>;
		--end loop
		
--WAIT
	--Pause execution statement until satisfier
	
	--wait on a,b	(until signal event occurs)
	--wait until (int < 100)	(boolean expr)
	--wait for 20 ns;		(time)
	--wait until (a = '1') for 5ns;
	


--Simulation cycle: initailize signal -> execute all processes -> advance time -> execute sensitive process -> update signal -> advance time -> execute sensitive process ...



