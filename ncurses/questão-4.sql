-- 4 - Implemente uma procedure PL/SQL chamada remover_produto_vencido. Esta procedure recebe o código de um produto e remove o mesmo do banco, caso ele esteja vencido (use como referência a data atual do sistema). 

CREATE OR REPLACE PROCEDURE remover_produto_vencido (
    p_produto IN INTEGER
) IS
    v_produto_existe INTEGER;
    v_validade DATE;
BEGIN
    -- Verifica se o produto existe
    SELECT count(*) INTO v_produto_existe
    FROM produto WHERE codigo = p_produto;

    IF v_produto_existe = 0 THEN
        dbms_output.put_line('Produto não existe no banco.');
        RETURN;
    END IF;

    IF v_produto_existe > 1 THEN
        dbms_output.put_line('Mais de um produto com mesmo codigo.');
        RETURN;
    END IF;
    
    -- Resgata a data de validade do produto
    SELECT data_validade INTO v_validade
    FROM produto WHERE codigo = p_produto;

    IF v_validade >= SYSDATE THEN
        dbms_output.put_line('Produto não está vencido. Data de validade: ' || TO_CHAR(v_data_validade, 'DD/MM/YYYY'));
        RETURN;
    END IF;

     DELETE FROM fotos_produto WHERE codigo_produto = p_produto;
    
    -- Remove do estoque dos centros de distribuição
    DELETE FROM prod_estocado_cent_dist WHERE codigo_produto = p_produto;
    
    -- Remove dos fornecedores
    DELETE FROM fornecedor_fornece_produto WHERE codigo_produto = p_produto;
    
    -- Remove dos carrinhos
    DELETE FROM carrinho_tem_produto WHERE codigo_produto = p_produto;
    
    -- Remove das compras
    DELETE FROM compra_possui_produto WHERE codigo_produto = p_produto;
    
    -- Remove das avaliações
    DELETE FROM compra_avalia_produto WHERE codigo_produto = p_produto;
    
    -- Finalmente remove o produto
    DELETE FROM produto WHERE codigo = p_codigo_produto;

    COMMIT;
END;