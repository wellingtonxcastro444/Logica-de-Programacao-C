#include <stdio.h>

int main() {
    //Declaração de array para controle de estoque e vendas.
    char produto [10][20] = {"celular", "capa", "carregador", "smartwatch", "headset", "mouse", "teclado", "monitor", "mesa", "PS5"};
    float valor [10] = {1500.00, 75.00, 120.00, 239.00, 210.00, 290.00, 329.00, 1800.00, 549.00, 2800.00};
    int estoque [10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // Variáveis para controlar o valor final e a contagem de itens vendidos.
    float valor_da_nota =0;
    int quantidade =0;        
    int registro =0; // Contador de quantos produtos foram comprados com sucesso.
    int opcao =1;
    int confirmar =0;

    printf("\n---LOJA SPORTZONE---\n");
    printf("\n");
    printf("DESEJA ENTRAR NA LOJA?\n(1 SIM / 0 NÃO)\n");
    scanf("%d", &opcao);

    //inicio do loop da loja com a função while até que selecione 0.
    while (opcao != 0){
        printf("\n---BEM-VINDO (a) A SPORTZONE---\n");
        printf("\n");
        printf("NOSSO MENU:\n 1-CELULAR\n 2-CAPA\n 3-CARREGADOR\n 4-SMARTWATCH\n 5-HEADSET\n 6-MOUSE\n 7-TECLADO\n 8-MONITOR\n 9-MESA\n 10-PS5\n");
        scanf("%d", &opcao);
        
        // Validação para garantir que o usuário escolheu uma opção válida do menu.
        if (opcao >=1 && opcao<=10){
            // Ajuste de índice: como o array começa em 0 mas o menu em 1, subtraímos 1.
            int i =opcao -1;
            
            // Só permite a venda se o produto ainda estiver disponível no estoque.
            if (estoque[i] >0){
                printf("PRODUTO SELECIONADO: %s\nVALOR: %.2f\nESTOQUE DISPONIVEL: %d\n", produto[i], valor[i], estoque[i]);
                printf("QUANTAS UNIDADES VOCÊ IRÁ COMPRAR?\n");
                scanf("%d", &quantidade);
                
                // Verifica se a quantidade solicitada não ultrapassa o que temos na prateleira
                if (quantidade <= estoque[i]){
                    printf("DESEJA COMPRAR ESSE PRODUTO?\n(1 SIM / 0 NÃO)\n");
                    scanf("%d", &confirmar);


                    if (confirmar==1){
                        // Calcula o total acumulado e atualiza a baixa no estoque.
                        valor_da_nota = valor_da_nota + (valor[i] * quantidade);
                        registro ++;
                        estoque[i] = estoque[i] - quantidade;
                        printf("VENDA CONFIRMADA!\n");        
                        printf("PRODUTO: %s\nVALOR: R$%.2f\n", produto[i], valor[i]);
                        printf("ESTOQUE RESTANTE: %d\n", estoque [i]);
                        printf("UNIDADES COMPRADAS: %d\n", quantidade);
                        printf("VALOR DO SEU CARRINHO: R$ %.2f\n", valor_da_nota);
                        printf("DESEJA PERMANECER NA LOJA?\n");
                        scanf("%d", &opcao);
                    } else {
                        printf("VENDA CANCELADA!\nVOLTANDO AO MENU!");
                    }
                } else {
                    printf("QUANTIDADE EXCEDE O NUMERO DO ESTOQUE!\n");
                }
            } else {
                printf("PRODUTO SEM ESTOQUE DISPONIVEL NO MOMENTO!\nVOLTANDO AO MENU!\n");
            }
        } else if (opcao != 0) {
            printf("OPÇÃO INVALIDA! ESCOLHA DE 1 - 10\n");
        }   
    } 
    // Fechamento da nota e resumo final da operação.  
    printf("\n--- NOTA DE COMPRA ---\n");
    printf("TOTAL DE ITENS: %d\n", registro);
    printf("VALOR TOTAL DA NOTA: R$ %.2f\n", valor_da_nota);
    printf("--------------------\n");
    printf("Obrigado por comprar na SPORTZONE!\n");

    return 0;          
}