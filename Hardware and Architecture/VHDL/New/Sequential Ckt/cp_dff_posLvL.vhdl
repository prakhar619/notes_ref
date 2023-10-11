library ieee;
use ieee.std_logic_1164.all;

entity dLatch_posLvL is
    port(
            d_L,clk_L : in std_logic;
            q_L,q_inv_L : out std_logic
    );
end dLatch_posLvL;

architecture dLatch_posLvL_behv of dLatch_posLvL is
    begin
        dL_process: process(clk_L,d_L)
            begin
                    if clk_L == '1' then
                        q_L <= d_L;
                        end if;
            end process;
        q_inv_L <= not q_L;
    end architecture;
    
library ieee;
use ieee.std_logic_1164.all;


entity dff_posEdge is
    port(
            clrn,pren,d,clk, : in std_logic;
            q,q_inv : out std_logic
    );
end dff_posEdge;

architecture dff_posEdge_behv of dff_posEdge is
component dLatch_posLvL is
    port(
        d_L,clk_L : in std_logic;
        q_L,q_inv_L : out std_logic
    );
end component;
signal master_slave_link,temp_q : std_logic;
    begin
        master: dLatch_posLvL port map(d_L=>d, clk_L=> not clk, q_L=> master_slave_link);
        slave: dLatch_posLvL port map(d_L=>master_slave_link, clk_L=> clk, q_L=>temp_q);
       cp_process: process(clrn,pren)
        begin   
            if clrn == '0' then
                q <= '0';
            elsif pren == '0' then
                q <= '1';
            else
                q <= temp_q;
            end if;
        q_inv <= not q;
 end architecture;
    
