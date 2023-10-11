library ieee;
use ieee.std_logic_1164.all;

entity srLatch is
    port(
            s,r : in std_logic;
            q,q_inv : out std_logic
    );
end srLatch;
--Truth  Table
-- s=1 and r=0 q=0  (set state)
-- s=0 and r=1 q=1  (reset state)
-- rest undefined state (1,1), (0,0)
architecture srLatch_behv of srLatch is
    begin
        dL_process: process(s,r)
            begin
                    if s == '1' and r=='0' then
                        q <= '0';
                    elsif s == '0' and r=='1' then
                        q <= '1';
                    else    
                        q <= 'x';
                        end if;
            end process;
        q_inv <= not q;
    end architecture;
    
