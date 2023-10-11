library ieee;
use ieee.std_logic_1164.all;

entity dLatch_posLvL is
    port(
            d,clk : in std_logic;
            q,q_inv : out std_logic
    );
end dLatch_posLvL;

architecture dLatch_posLvL_behv of dLatch_posLvL is
    begin
        dL_process: process(clk,d)
            begin
                    if clk == '1' then
                        q <= d;
                        end if;
            end process;
        q_inv <= not q;
    end architecture;

