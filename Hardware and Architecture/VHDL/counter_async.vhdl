---Prakhar Gupta 2103126
library IEEE;
use ieee.std_logic_1164.all ;
use work.combine_pack.all;

entity COUNTER_ASYNC is -- Entity declaration
port(CLK : in std_logic; -- Clock input of the counter
     RSTN : in std_logic; -- Active low reset input of the counter
     Q : out std_logic_vector(3 downto 0)); -- Output state of the counter
end COUNTER_ASYNC ;

architecture Functionality of COUNTER_ASYNC is


     SIGNAL QN : STD_LOGIC_VECTOR(3 DOWNTO 0);
     SIGNAL CLK_OUT : STD_LOGIC;
     BEGIN
     
     
     U1 : CLK_DVD port map(CLK,RSTN,CLK_OUT);
     U2 : pos_d_flipflop port map(D => QN(0),CLRN => RSTN,PREN => '1',CLK => CLK_OUT, Q => Q(0),QN => QN(0));
     U3 : pos_d_flipflop port map(D => QN(1),CLRN => RSTN,PREN => '1',CLK => QN(0), Q => Q(1),QN => QN(1));
     U4 : pos_d_flipflop port map(D => QN(2),CLRN => RSTN,PREN => '1',CLK => QN(1), Q => Q(2),QN => QN(2));
     U5 : pos_d_flipflop port map(D => QN(3),CLRN => RSTN,PREN => '1',CLK => QN(2), Q => Q(3),QN => QN(3));
end Functionality;