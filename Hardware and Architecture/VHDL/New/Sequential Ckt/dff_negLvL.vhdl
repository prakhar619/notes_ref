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


entity dff_negEdge is
    port(
            d,clk : in std_logic;
            q,q_inv : out std_logic
    );
end dff_negEdge;

architecture dff_negEdge_behv of dff_negEdge is
component dLatch_posLvL is
    port(
        d_L,clk_L : in std_logic;
        q_L,q_inv_L : out std_logic
    );
end component;
signal master_slave_link : std_logic;
    begin
        master: dLatch_posLvL port map(d_L=>d, clk_L=>  clk, q_L=> master_slave_link);
        slave: dLatch_posLvL port map(d_L=>master_slave_link, clk_L=>not clk, q_L=>q);
        q_inv <= not q;
    end architecture;
    
