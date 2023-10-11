entity tff is
    port(
        t,clk: in std_logic;
        q: inout std_logic;
        q_inv : out std_logic
    );
end entity;

architecture tff_behv of tff is
    begin 
        tff_pr : process(t,clk,q)
        begin
            if rising_edge(clk) and t='1' then
                q<= not q;
            else 
                q<= q;
                end if;
        end process;
        q_inv <= not  q;
            end architecture;