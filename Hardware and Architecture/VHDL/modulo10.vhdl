--- Prakhar Gupta 2103126
library ieee;
use ieee.std_logic_1164.all;
use work.combine_pack.all;

entity modulo_10 is 
    port (clk : in std_logic;
    rstn : in std_logic;
    q : inout std_logic_vector (3 downto 0));

    end modulo_10;

    architecture functionality of modulo_10 is
        signal qn: std_logic_vector(3 downto 0);
        signal s : std_logic_vector(3 downto 0);
        signal cn, clk_out, rst, : std_logic;

        begin 
            U1: not_1 port map(rstn,rst);
            U2: and_1 port map(q(3),q(2),s(0));
            U3: and_1 port map(q(3),q(1),s(1));
            U4: or_1 port map(s(0),s(1),s(2));
            U5 : not_1 port map(s(2),s(3));    
            U7: or_1 port map(s(3),rst,cn);
            
            U6 : CLK_DVD port map(clk,rstn,clk_out);
            U7 : pos_d_flipflop port map(D => qn(0),clrn => cn,pren => '1',clk => clk_out, q => q(0),qn => qn(0));
            U8 : pos_d_flipflop port map(D => qn(1),clrn => cn,pren => '1',clk => qn(0), q => q(1),qn => qn(1));
            U9 : pos_d_flipflop port map(D => qn(2),clrn => cn,pren => '1',clk => qn(1), q => q(2),qn => qn(2));
            U10 : pos_d_flipflop port map(D => qn(3),clrn => cn,pren => '1',clk => qn(2), q => q(3),qn => qn(3));
            
    end functionality;