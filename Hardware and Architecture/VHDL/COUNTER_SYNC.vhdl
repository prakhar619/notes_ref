-- Author: Prakhar Gupta

library IEEE;
use IEEE.std_logic_1164.all;
use work.combine_pack.all;

entity COUNTER_SYNC is 									
	port(CLK : in std_logic; 						
		RSTN : in std_logic; 			
		UP_DN : in std_logic; 	
		LDN : in std_logic; 					
 		E : in std_logic; 				
		D : in std_logic_vector(3 downto 0); 		
 		Q : inout std_logic_vector(3 downto 0)); 		

end COUNTER_SYNC;
architecture func of COUNTER_SYNC is

signal QN : std_logic_vector(3 downto 0);
signal CLK_D,INV_UP, INV_DN  : std_logic;
signal QD : std_logic_vector( 3 downto 0);

signal Q_UD, C, QE_XOR, LDN_MUX, R0, R9 ,RSTN_MUX : std_logic_vector( 3 downto 0);

begin
R0 <= '0' & '0' & '0' & '0';
R9 <= '1' & '0' & '0' & '1';

U4 : CLK_DVD port map (CLK, RSTN, CLK_D);

F0 : for i in 0 to 3 generate
begin
	U0 : pos_d_flipflop port map (RSTN_MUX(i), CLK_D, '1', '1', QD(i), QN(i));
end generate;

P1 : process (QD,UP_DN)
begin
Q_UD(0) <= (QN(0) and (not UP_DN)) or (QD(0) and UP_DN);
Q_UD(1) <= (QN(1) and (not UP_DN)) or (QD(1) and UP_DN);
Q_UD(2) <= (QN(2) and (not UP_DN)) or (QD(2) and UP_DN);
Q_UD(3) <= (QN(3) and (not UP_DN)) or (QD(3) and UP_DN);
	
end process;

P4  : process (Q_UD,E)
begin
    C(0) <= Q_UD(0) and E;
    C(1) <= Q_UD(1) and C(0);
    C(2) <= Q_UD(2) and C(1);
    C(3) <= Q_UD(3) and C(2);
    
end process;

P2 : process (C, QD)
begin
QE_XOR(0) <= E xor QD(0);
QE_XOR(1) <= C(0) xor QD(1);
QE_XOR(2) <= C(1) xor QD(2);
QE_XOR(3) <= C(2) xor QD(3);
end process;


P3 : process (D, QE_XOR)
begin

	LDN_MUX(0) <= (D(0) and (not LDN)) or (QE_XOR(0) and LDN);
	LDN_MUX(1) <= (D(1) and (not LDN)) or (QE_XOR(1) and LDN);
    	LDN_MUX(2) <= (D(2) and (not LDN)) or (QE_XOR(2) and LDN);
    	LDN_MUX(3) <= (D(3) and (not LDN)) or (QE_XOR(3) and LDN);
	
	
end process;

P5 : process (LDN_MUX, RSTN, QD)
begin
    INV_UP <= QD(3) and (QD(1) or QD(2) or QD(0));
    INV_DN <= (QD(3) and (QD(1) or QD(2))) or (not (QD(0) or QD(1) or QD(2) or QD(3)));
    
    if (UP_DN = '1') then
        if (RSTN = '0' or INV_UP = '1') then
            RSTN_MUX <= R0;
        else 
            RSTN_MUX <= LDN_MUX;
        end if;
    else 
        if (RSTN = '0' or INV_DN = '1') then
            RSTN_MUX <= R9;
        else
            RSTN_MUX <= LDN_MUX;
            
        end if;
    end if;
end process;



F3 : for i in 0 to 3 generate
    Q(i) <= QD(i);
end generate;

end func;