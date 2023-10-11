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
        Signal O : std_logic_vector(7 downto 1);

        begin
        
        for i in 0 to 3 generate
            U1: and_1 port map (I(i),J(0),and1_1(i));
        end generate;

        for i in 0 to 3 generate
            U2: and_1 port map (I(i),J(1),and1_2(i));
            end generate;
        
        U9: Adder_4_bit port map(('0',and1_1(3),and1_1(2),and1_1(1)),and1_2,'0',S0);

        for j in 0 to 3 generate
        U3: and_1 port map (I(j),J(2),and2(j));
            end generate;

        U14: Adder_4_bit port map ((S0(4),S0(3),S0(2),S0(1)),and2,'0',S1);

        for k in 0 to 3 generate
        U4: and_1 port map (I(k),J(3),and3(k));
        end generate;
        
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
       
    

        


        


        

        
           



        
            