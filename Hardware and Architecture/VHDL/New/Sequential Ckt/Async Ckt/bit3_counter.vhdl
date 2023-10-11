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
            d_d,clk_d : in std_logic;
            q_d,q_inv_d : out std_logic
    );
end dff_posEdge;

architecture dff_posEdge_behv of dff_posEdge is
component dLatch_posLvL is
    port(
        d_L,clk_L : in std_logic;
        q_L,q_inv_L : out std_logic
    );
end component;
signal master_slave_link : std_logic;
    begin
        master: dLatch_posLvL port map(d_L=>d_d, clk_L=> not clk_d, q_L=> master_slave_link);
        slave: dLatch_posLvL port map(d_L=>master_slave_link, clk_L=> clk_d, q_L=>q_d);
        q_inv_d <= not q_d;
 end architecture;
    
entity bit1_counter is
    port(
        clk: in std_logic;
        clk_out: out std_logic_vector
    );
    end entity;

architecture bit1_counter_struct of bit1_counter is 
component dff_posEdge is
    port(
        d_d,clk_d : in std_logic;
        q_d,q_inv_d : out std_logic
);
end component;
signal internal_con:std_logic_vector(2 downto 0);
signal q: std_logic_vector(2 downto 0);
begin
    dff_0: dff_posEdge port map(d_d=>internal_con[0],clk_d=>clk,    q_d=>q[0],q_inv_d=>internal_con[0]);
    dff_1: dff_negEdge port map(d_d=>internal_con[1],clk_d=>q[0],   q_d=>q[1],q_inv_d=>internal_con[1]);
    dff_2: dff_negEdge port map(d_d=>internal_con[2],clk_d=>q[1],   q_d=>q[2],q_inv_d=>internal_con[2]);
    clk_out<= q[2];
    end architecture;