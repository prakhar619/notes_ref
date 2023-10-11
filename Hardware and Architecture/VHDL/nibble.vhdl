--author Prakhar Gupta 2103126
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;

entity Adder_4_bit is
    port( I,J: in std_logic_vector(3 downto 0);
        C : in std_logic;
        O : out std_logic_vector(4 downto 0));
        end Adder_4_bit;

architecture func_adder_4_bit of adder_4_bit is
        signal C0,C1,C2 : std_logic;
        begin 
        U1 : fulladder_1 port map (I(0),J(0),C,O(0),C0);
        U2 : fulladder_1 port map (I(1),J(1),C0,O(1),C1);
        U3 : fulladder_1 port map (I(2),J(2),C1,O(2),C2);
        U4 : fulladder_1 port map (I(3),J(3),C2,O(3),O(4));
        end func_adder_4_bit;