---author Prakhar gupta 2103126
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;
entity Multiplier_4_bit is
    port (I,J : in std_logic_vector(3 downto 0);
    O:out std_logic_vector(7 downto 0));
    end Multiplier_4_bit;

    architecture func_multiplier_4_bit of Multiplier_4_bit is
        Signal C : std_logic;
        Signal S0,S1,S2 : std_logic_vector(4 downto 0);
        Signal and1_1,and1_2,and2,and3 : std_logic_vector(3 downto 0);

        begin
        U1: and_1 port map (I(0),J(0),and1_1(0));
        U2: and_1 port map (I(1),J(0),and1_1(1));
        U3: and_1 port map (I(2),J(0),and1_1(2));
        U4: and_1 port map (I(3),J(0),and1_1(3));

        U5: and_1 port map (I(0),J(1),and1_2(0));
        U6: and_1 port map (I(1),J(1),and1_2(1));
        U7: and_1 port map (I(2),J(1),and1_2(2));
        U8: and_1 port map (I(3),J(1),and1_2(3));

        U9: Adder_4_bit port map(('0',and1_1(3),and1_1(2),and1_1(1)),and1_2,'0',S0);

        U10: and_1 port map (I(0),J(2),and2(0));
        U11: and_1 port map (I(1),J(2),and2(1));
        U12: and_1 port map (I(2),J(2),and2(2));
        U13: and_1 port map (I(3),J(2),and2(3));

        U14: Adder_4_bit port map ((S0(4),S0(3),S0(2),S0(1)),and2,'0',S1);

        U15: and_1 port map (I(0),J(3),and3(0));
        U16: and_1 port map (I(1),J(3),and3(1));
        U17: and_1 port map (I(2),J(3),and3(2));
        U18: and_1 port map (I(3),J(3),and3(3));

        U19: Adder_4_bit port map ((S1(4),S1(3),S1(2),S1(1)),and3,'0',S2);

        O(0) <= and1_1(0);
        O(1) <= S0(0);
        O(2) <= S1(0);
        O(3) <= S2(0);
        O(4) <= S2(1);
        O(5) <= S2(2);
        O(6) <= S2(3);
        O(7) <= S2(4);

        end func_multiplier_4_bit;
       
    


            