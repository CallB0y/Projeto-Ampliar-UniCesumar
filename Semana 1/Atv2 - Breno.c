#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    float salario, imposto;
    
    printf("Informe o salario: ");
    scanf("%f", &salario);
    system("cls");
    
    imposto = salario * 0.15;
    printf("O valor a pagar � de: %.2f", imposto );
    
    return 0;
}
