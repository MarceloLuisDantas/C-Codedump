-- 3 - Crie uma procedure PL/SQL chamada adicionar_produto_estoque, que receba o código de um produto e o código de um centro de distribuição e adicione 50 unidades desse produto ao estoque no centro de distribuição. Caso o estoque não esteja zerado, a quantidade deve ser atualizada, adicionando mais 50 unidades à quantidade existente.

CREATE OR REPLACE PROCEDURE adicionar_produto_estoque (
    p_codigo_produto IN INTEGER,
    p_codigo_distribuicao IN INTEGER 
) IS
    v_estoque INTEGER;
    v_distribuidora_existe INTEGER;
    v_produto_existe INTEGER;
    v_distribuidora_distribui INTEGER;  
BEGIN
    -- Verifica se a distribuidora existe
    SELECT count(*) INTO v_distribuidora_existe FROM centro_de_distribuicao 
    WHERE codigo = p_codigo_distribuicao;

    -- Verificando se distribuidora existe, e se não ha inconsistencia no banco
    IF v_distribuidora_existe = 0 THEN
        dbms_output.put_line('Distribuidora não existe.'); 
        RETURN;
    END IF;

    IF v_distribuidora_existe > 1 THEN
        dbms_output.put_line('Mais de uma instância da mesma distribuidora no banco.');                
        RETURN
    END IF;
   
    -- Verifica se o produto existe, e se não ha inconsistencia no banco
    SELECT count(*) INTO v_produto_existe FROM produto 
    WHERE codigo = p_codigo_produto;

    IF v_produto_existe = 0 THEN
        dbms_output.put_line('Produto não existe no banco.'); 
        RETURN;
    END IF;

    IF v_produto_existe > 1 THEN
        dbms_output.put_line('Mais de uma instância do mesmo código no banco.');                
        RETURN;
    END IF;

    -- Verifica se a distribuidora distribui o produto
    SELECT count(*) INTO v_distribuidora_distribui FROM prod_estocado_cent_dist
    WHERE codigo_centro_distribuicao = p_codigo_distribuicao
        AND codigo_produto = p_codigo_produto;

    IF v_distribuidora_distribui = 0 THEN 
        dbms_output.put_line('Distribuidora não distribui o produto.');                
        RETURN;
    END IF;
    
    IF v_distribuidora_distribui > 1 THEN 
        dbms_output.put_line('Mais de uma instância da distribuidora e produto no banco.');    
        RETURN
    END IF;
    
    -- Realiza a verificação do estoque
    SELECT quantidade INTO v_estoque FROM prod_estocado_cent_dist
    WHERE codigo_centro_distribuicao = p_codigo_distribuicao
        AND codigo_produto = p_codigo_produto;

    -- Adiciona 50 ao estoque
    v_estoque := v_estoque + 50;
    UPDATE prod_estocado_cent_dist SET quantidade = v_estoque
    WHERE codigo_centro_distribuicao = p_codigo_distribuicao
        AND codigo_produto = p_codigo_produto;

    dbms_output.put_line('Produto atualizado. Estoque atual: ' || v_estoque);                
    COMMIT;
END;
