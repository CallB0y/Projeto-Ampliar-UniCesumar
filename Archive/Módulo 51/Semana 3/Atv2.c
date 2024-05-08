/*
    Desenvolva um programa que verifica se uma senha fornecida pelo usu�rio atende 
    aos crit�rios de seguran�a:
    
    - Comprimento m�nimo de 8 caracteres
    - Presen�a de caracteres especiais
    - Se possu� letras mai�sculas e min�sculas
    - Se tem n�mero

    Informe se � v�lida ou inv�lida.

    Dica: pesquise pelas bibliotecas string.h e ctype.h
*/

#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    char senha[100];
    int tem_maiuscula = 0, tem_minuscula = 0, tem_numero = 0, tem_especial = 0;
    int comprimento = 0;
    int i;

    printf("Digite a senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    // Verificando o comprimento m�nimo
    comprimento = strlen(senha);
    if (comprimento < 8) {
        printf("Senha inv�lida: deve ter pelo menos 8 caracteres.\n");
        return 0;
    }

    // Verificando a presen�a de letras mai�sculas, min�sculas, n�meros e caracteres especiais
    for (i = 0; senha[i] != '\0'; i++) {
        if (isupper(senha[i])) {
            tem_maiuscula = 1;
        }
        if (islower(senha[i])) {
            tem_minuscula = 1;
        }
        if (isdigit(senha[i])) {
            tem_numero = 1;
        }
        if (!isalnum(senha[i])) {
            tem_especial = 1;
        }
    }

    // Verificando todas as condi��es
    if (tem_maiuscula && tem_minuscula && tem_numero && tem_especial) {
        printf("Senha v�lida.\n");
    } else {
        printf("Senha inv�lida: deve conter pelo menos uma letra mai�scula, uma letra min�scula, um n�mero e um caractere especial.\n");
    }

    return 0;
}