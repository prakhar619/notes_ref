---author Prakhar Gupta 2103126
library ieee;
use ieee.std_logic_1164.all;

use work.combine_pack.all;

entity neg_d_latch is 
    port(D: in std_logic;
        clkn: in std_logic;
        q : buffer std_logic;
        qn : out std_logic);
    end neg_d_latch;

    architecture func_d_latch of neg_d_latch is
        signal S : std_logic;
        begin  
            process (d,clkn)
            begin   
                if clkn = '0' then
                        q <= D;
                        end if;
                        end process;
                qn <= not q;
        end func_d_latch;