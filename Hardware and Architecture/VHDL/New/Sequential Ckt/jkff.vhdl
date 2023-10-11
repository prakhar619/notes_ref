entity jkff is
    port(
        j,k,clk: in std_logic;
        q,q_inv: out std_logic;
    );
end entity;

architecture jkff_behv of jkff is
    begin 
        set_preset_pr: process(s,r,clk)
        begin
            if rising_edge(clk)
                if  j=='0' and k=='1' then
                    q<='0';
                elsif j =='1' and k=='0' then
                    q<='1';
                elsif j=='1' and k=='1' then
                    q<= not q;
                end if;
            end if;
            end process;
             q_inv <= q;
            end architecture;