---author Prakhar Gupta
library ieee;
use ieee.std_logic_1164.all;

use work.combine_pack.all;

entity neg_d_flipflop is 
    port(D: in std_logic;
        clk : in std_logic;
        clrn : in std_logic;
        pren : in std_logic;
        q : buffer std_logic;
        qn : out std_logic);

        end neg_d_flipflop;

        architecture func_d_flipflop of neg_d_flipflop is 
        begin
            process(clrn,pren,clk)
            begin
    
                if clrn = '0' then
                    q <= '0';
                    elsif pren = '0' then
                    q<= '1';
                    elsif clk'event and clk = '0' then
                        q <= d;
                        end if;
                        end process;
                        qn <= not q;
                        end func_d_flipflop;
