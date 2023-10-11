entity srff is
    port(
        s,r,clk: in std_logic;
        q,q_inv: out std_logic;
    );
end entity;

architecture srff_behv of srff is
    begin 
        set_preset_pr: process(s,r,clk)
        begin
            if rising_edge(clk)
                if  s=='0' and r=='1' then
                    q<='0';
                elsif s=='1' and r=='0' then
                    q<='1';
                elsif s=='1' and r=='1' then
                    q<='x';
                end if;
            end if;
            end process;
             q_inv <= not q;
            end architecture;