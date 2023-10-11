library ieee;
use ieee.std_logic_1164.all;

use work.combine_pack.all;
entity sr_latch is  
port( S: in std_logic;
        R : in std_logic; 
        Q : buffer std_logic; 
        QN : out std_logic);  
        end sr_latch;

        architecture func_sr_latch of sr_latch is
            signal S1 : std_logic;
            begin  
                S1 <= S nand Q;
                Q <= R nand S1;
                
                QN <= not(Q);

                end func_sr_latch;