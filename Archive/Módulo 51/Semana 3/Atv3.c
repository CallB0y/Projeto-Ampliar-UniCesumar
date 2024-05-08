/*
    Crie um programa que gere uma senha aleat�ria para o usu�rio. O usu�rio deve escolher se:
    
    - a senha dever� ter letras mai�sculas e min�sculas ou n�o
    - se dever� conter n�meros ou n�o
    - se dever� contar simbolos ou n�o
    - quantidade de caracteres.

    Dica: pesquise as bibliotecas time.h e stdlib.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    int tem_maiusculas, tem_minusculas, tem_numeros, tem_simbolos;
    int tamanho, i;
    char caracteres[95]; // 95 � o total de caracteres imprim�veis na tabela ASCII

    setlocale(LC_ALL, "Portuguese");

    // Inicializando o array de caracteres imprim�veis
    for (i = 0; i < 95; i++) {
        caracteres[i] = i + 32;
    }

    printf("Informe quantos caracteres quer na senha: ");
    scanf("%d", &tamanho);

    printf("Digite 1 se deseja incluir letras mai�sculas, 0 caso contr�rio: ");
    scanf("%d", &tem_maiusculas);

    printf("Digite 1 se deseja incluir letras min�sculas, 0 caso contr�rio: ");
    scanf("%d", &tem_minusculas);

    printf("Digite 1 se deseja incluir n�meros, 0 caso contr�rio: ");
    scanf("%d", &tem_numeros);

    printf("Digite 1 se deseja incluir s�mbolos, 0 caso contr�rio: ");
    scanf("%d", &tem_simbolos);

    // Verificando se pelo menos um tipo de caractere foi escolhido
    if (!(tem_maiusculas || tem_minusculas || tem_numeros || tem_simbolos)) {
        printf("Pelo menos um tipo de caractere deve ser inclu�do na senha.\n");
        return 1;
    }

    srand(time(NULL));

    printf("Sua senha aleat�ria �: ");
    for (i = 0; i < tamanho; i++) {
        char c;
        do {
            c = caracteres[rand() % 95];
        } while ((!tem_maiusculas && c >= 'A' && c <= 'Z') ||
                 (!tem_minusculas && c >= 'a' && c <= 'z') ||
                 (!tem_numeros && c >= '0' && c <= '9') ||
                 (!tem_simbolos && !(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z') && !(c >= '0' && c <= '9')));
        printf("%c", c);
    }
    printf("\n");

    return 0;
}