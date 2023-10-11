---author Prakhar Gupta 2103126
library ieee;
use ieee.std_logic_1164.all;

use work.combine_pack.all;

entity d_latch is 
    port(D: in std_logic;
        clk: in std_logic;
        q : buffer std_logic;
        qn : out std_logic);
    end d_latch;

    architecture func_d_latch of d_latch is
        begin   
            process (d,clk)
            begin   
                if clk = '1' then
                        q<=D;
                        end if;
                        end process;
                qn <= not q;
        end func_d_latch;