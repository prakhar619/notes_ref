--author:Prakhar Gupta (2103126)

library ieee;
use ieee.std_logic_1164.all;

package combine_pack is 

component not_1 is 
    port(I0 : in std_logic;
    O0 : out std_logic);
    end component;

component or_1 is 
    port(I0,I1 : in std_logic;
    O0: out std_logic);
    end component; 

component and_1 is 
    port(I0,I1:in std_logic;
    O0:out std_logic);
    end component;

component xor_1 is 
    port(I0,I1:in std_logic;
    O0 : out std_logic);
    end component;
component xnor_1 is
    port (I0,I1:in std_logic;
    O0: out std_logic);
    end component;
    
component halfadder_1 is 
port (I0,I1 : in std_logic;
O,C0 : out std_logic);
    end component; 

component fulladder_1 is 
port(I0,I1,I2 : in std_logic;
O0,O1 : out std_logic);
    end component;

component mux2_1_1 is
    port(I0,I1,I_0 : in std_logic;
    O0 : out std_logic);
    end component;

component mux4_1_1 is
    port(I : in std_logic_vector(3 downto 0);
    S : in std_logic_vector(1 downto 0);
    O0 : out std_logic);
    end component;

component mux1_2_1 is 
    port(I0,I_0 : in std_logic;
    O0,O1 : out std_logic);
    end component;

component mux1_4_1 is 
    port(I0 : in std_logic;
    S : in std_logic_vector(1 downto 0);
    O : out std_logic_vector(3 downto 0));
    end component ;

component Adder_4_bit is
    port( I,J: in std_logic_vector(3 downto 0);
    C : in std_logic;
    O : out std_logic_vector(4 downto 0));
    end component;

component converter_2 is
	port(   I0 : in std_logic_vector(3 downto 0);
			O0 : out std_logic_vector(3 downto 0));
end component ;

component converter_1 IS
port(I : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      O : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
      INV : OUT STD_LOGIC);
end component;

component pos_d_flipflop is 
    port(D: in std_logic;
        clk : in std_logic;
        clrn : in std_logic;
        pren : in std_logic;
        q : buffer std_logic;
        qn : out std_logic);
    end component;

component CLK_DVD is
            port(CLK_IN : in std_logic;
                 RSTN : in std_logic;
                 CLK_OUT : out std_logic);         
        end component;
    end combine_pack;
