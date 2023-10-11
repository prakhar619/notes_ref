library ieee;
use ieee.std_logic_1164.all;

entity dLatch_negLvL is
    port(
            d,clk : in std_logic;
            q,q_inv : out std_logic
    );
end dLatch_negLvL;

architecture dLatch_negLvL_behv of dLatch_negLvL is
    begin
        dL_process: process(clk,d)
            begin
                    if clk == '0' then
                        q <= d;
                        end if;
            end process;
        q_inv <= not q;
    end architecture;
    
