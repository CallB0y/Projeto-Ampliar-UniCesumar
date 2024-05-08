/*
    Fa�a uma calculadora com as 4 opera��es b�sicas.
    Cada opera��es deve ser uma subrotina.
    Voc� deve informar ao usu�rio as opera��es para cada opera��o.
    Se ele escolher a op��o 0, o programa dever� ser encerrado.
*/

#include <stdio.h>
#include <locale.h>

int num1, num2;

void entradaDados () {
    printf("Informe um n�mero: ");
    scanf("%d", &num1);
    printf("Informe um n�mero: ");
    scanf("%d", &num2);
}

int soma () {
    entradaDados();
    return num1 + num2;
}

int subtracao () {
    entradaDados();
    return num1 - num2;
}

int multiplicacao () {
    entradaDados();
    return num1 * num2;
}

int divisao () {
    entradaDados();
    return num1 / num2;
}

int main () {
    setlocale (LC_ALL, "Portuguese");

    int opc, resultado;

    do {
        printf("Escolha uma opera��o: \n");
        printf("1. Soma\n");
        printf("2. Substra��o\n");
        printf("3. Multiplica��o\n");
        printf("4. Divis�o\n");
        printf("0. Sair\n");
        scanf("%d", &opc);        

        switch(opc) {
            case 1:
                resultado = soma();
                break;
            case 2:
                resultado = subtracao();
                break;    
            case 3:
                resultado = multiplicacao();
                break;
            case 4:
                resultado = divisao();
                break;
            case 0:
                printf("Encerrando...");
                break;
            default: 
                printf("Op��o inv�lida");
                break;
        }

        printf("Resultado: %d\n", resultado);

    }while(opc != 0);

    return 0;    
}