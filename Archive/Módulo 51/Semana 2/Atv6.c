/*
    Escreva um c�digo que exiba na tela um menu com as op��es:

    1. Somar 2 numeros
    2. Multiplicar 2 numeros
    3. Encerrar

    O programa s� poder� ser finalizado quando o usu�rio escolher a op��o 3
*/

#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");
    float n1, n2, resultado;
    int opcao;

    do {
        printf("Escolha uma op��o: \n1. Somar 2 numeros\n2. Multiplicar 2 numeros\n3. Encerrar\n");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {
            printf("Insira o primeiro n�mero: ");
            scanf("%f", &n1);
            printf("Insira o segundo n�mero: ");
            scanf("%f", &n2);
        }

        switch (opcao)
        {
            case 1:
                resultado = n1 + n2;    
                printf("Resultado: %.2f\n", resultado);    
                break;
            case 2:   
                resultado = n1 * n2;
                printf("Resultado: %.2f\n", resultado);
                break;    
            case 3:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("Op��o Inv�lida\n");
                break;
        }        
    } while (opcao != 3);

    return 0;
}