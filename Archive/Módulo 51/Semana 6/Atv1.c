/*
    Escreva um c�igo que cadastre at� 100 clientes e at� 100 produtos. No sistema o usu�rio deve poder:

    - Cadastrar o cliente (C�digo, Nome, idade, saldo)
    - Cadastrar produto (c�digo do produto, descri��o do produto, valor do produto, qtd)
    - Cadastrar uma venda de um produto pra um cliente (pelo c�digo do cliente e c�digo do produto).
    - Listar todas as vendas
    - Listar todas os clientes

    - Use subrotinas e ponteiros onde julgar necess�rio

    Cadastro de venda:
    - Recebe o c�digo do cliente e valida se o cliente existe
    - Recebe o c�digo do produto e valida se o produto existe
    - Recebe a quantidade de produto da venda e valida se existe em estoque
    - Calcula o total da Venda
    - Valida se o cliente tem saldo pra finalizar a compra
    - Abate o valor da venda no saldo do cliente e a quantidade vendida no estoque do produto

    
    Exerc�cio desenvolvido utilizando o Live Share do VSCode.
    C�digo escrito, em sua maioria, pelos alunos.
    
*/

#include <stdio.h>
#include <string.h>   
#include <locale.h>
#include <stdlib.h>

typedef struct {
    char nome[120];
    int cod;
    int idade;
    float saldo;
} cadCliente;

typedef struct {
    int codigo;
    char desc[30];
    float valor;
    int qtd;
} cadProduto;

typedef struct {
    int codClient, codProduto, qtdProduto;
    float valorVenda;
} cadVenda;

int menu();
void cadastroCliente(cadCliente *ptr);
void cadastroProduto(cadProduto *ptl);
void cadastroVenda(cadVenda *venda, cadProduto *produtos, cadCliente *clientes, int *qtdVendas);
void listarClientes(cadCliente *clientes, int qtdCliente);
void listarVendas(cadVenda *vendas, int qtdVendas);

int main () {
    setlocale(LC_ALL, "Portuguese");  //ASCII
    
    cadCliente cliente[100];
    cadProduto produto[100];
    cadVenda vendas[1000];

    int qtdCliente = 0, qtdProduto = 0, qtdVendas = 0;
    int opc;

    do {
        opc = menu();        
        switch (opc) {
            case 1:
                if (qtdCliente < 100) {
                    cadastroCliente(&cliente[qtdCliente]);
                    qtdCliente++;
                } else {
                    printf("Limite de cadastros excedido!");
                }
                break;
            case 2:
                if(qtdProduto < 100) {
                    cadastroProduto(&produto[qtdProduto]);
                    qtdProduto++;
                } else {
                    printf("Limite de cadastros excedido!");
                }
                break;
            case 3:
                if(qtdVendas < 1000){
                    cadastroVenda(&vendas[qtdVendas], produto, cliente, &qtdVendas);
                }
                break;
            case 4:
                listarVendas(vendas, qtdVendas);
                break;
            case 5:
                listarClientes(cliente, qtdCliente);
                break;
            case 6:
                printf("Encerrando... ");
                system("pause");
                system("cls");
                return 0;
            default:
                printf("Op��o inv�lida!");
                break;
        }
    } while(1);
}

int validarCliente(int codigo, cadCliente *clientes) {
    for (int i = 0; i < 100; i++) {
        if (clientes[i].cod == codigo) {
            return i;
        }
    }
    return -1;
}

int validarProduto(int codigo, cadProduto *produtos) {
    for (int i = 0; i < 100; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void cadastroVenda(cadVenda *venda, cadProduto *produtos, cadCliente *clientes, int *qtdVendas) {
    int codigoCliente, codigoProduto, qtdProduto;
    float totalVenda = 0;

    printf("Informe o c�digo do cliente: ");
    scanf("%d", &codigoCliente);
    getchar();
    system("cls");

    int indiceCliente = validarCliente(codigoCliente, clientes);
    if (indiceCliente == -1) {
        printf("Cliente n�o encontrado!\n");
        system("pause");
        system("cls");
        return;
    }

    printf("Informe o c�digo do produto: ");
    scanf("%d", &codigoProduto);
    getchar();
    system("cls");

    int indiceProduto = validarProduto(codigoProduto, produtos);
    if (indiceProduto == -1) {
        printf("Produto n�o encontrado!\n");
        system("pause");
        system("cls");
        return;
    }

    printf("Informe a quantidade de produtos vendidos: ");
    scanf("%d", &qtdProduto);
    getchar();
    system("cls");

    if (qtdProduto > produtos[indiceProduto].qtd) {
        printf("Quantidade de produto insuficiente em estoque!\nDispon�vel: %d", produtos[indiceProduto].qtd);
        system("pause");
        system("cls");
        return;
    }

    totalVenda = produtos[indiceProduto].valor * qtdProduto;

    if (totalVenda > clientes[indiceCliente].saldo) {
        printf("Saldo insuficiente para finalizar a compra!\nSaldo atual: R$%2.f", clientes[indiceCliente].saldo);
        system("pause");
        system("cls");
        return;
    }

    clientes[indiceCliente].saldo -= totalVenda;
    produtos[indiceProduto].qtd -= qtdProduto;

    venda->codClient = codigoCliente;
    venda->codProduto = codigoProduto;
    venda->qtdProduto = qtdProduto;
    venda->valorVenda = totalVenda;
    (*qtdVendas)++;

    printf("Venda cadastrada com sucesso!\n");
    system("pause");
    system("cls");
}

void cadastroProduto(cadProduto *ptl){
   
    printf("Informe o codigo: \n");
    scanf("%d", &ptl->codigo);
    getchar();
    system("cls");
    
    printf("Descri��o do produto: \n");
    fgets(ptl->desc, sizeof(ptl->desc), stdin);
    ptl->desc[strcspn(ptl->desc, "\n")] = '\0';
    getchar();
    system("cls");

    printf("Valor do produto: \n");
    scanf("%f", &ptl->valor);
    getchar();
    system("cls");    

    printf("Quantidade de produtos: \n");
    scanf("%d", &ptl->qtd);
    getchar();
    system("cls");
}

void cadastroCliente (cadCliente *ptr) { 
    
    printf("Informe o c�digo: \n");     
    scanf("%d", &ptr->cod);
    getchar();
    system("cls");

    printf("Informe o nome: \n"); 
    fgets(ptr->nome, sizeof(ptr->nome), stdin);
    ptr->nome[strcspn(ptr->nome, "\n")] = '\0';
    getchar();
    system("cls");

    printf("Informe a idade: \n");
    scanf("%d", &ptr->idade);
    getchar();
    system("cls");

    printf("Informe o Saldo: \n");
    scanf("%f", &ptr->saldo);
    getchar();
    system("cls");
}

void listarClientes(cadCliente *clientes, int qtdCliente){
    if(qtdCliente == 0){
        printf("Nenhum cliente encontrado!!!\n");
    } else{
        for (int i = 0; i < qtdCliente; i++){
            printf("Cliente %d: Codigo %d, Nome: %s Idade %d, Saldo: %.2f\n", i+1, clientes[i].cod, clientes[i].nome, clientes[i].idade, clientes[i].saldo);
            printf("_____________________________________________________________________________");            
        }
        system("pause");
        system("cls");
    }
}

void listarVendas(cadVenda *vendas, int qtdvendas){
    if(qtdvendas == 0){
        printf("Nenhuma venda registrada\n");
    } else{
        for (int i = 0; i < qtdvendas; i++){
            printf("C�digo do Cliente: %d\nC�digo do produto: %d\nQuantidade:%d\nValor da venda:%.2f\n", vendas[i].codClient ,vendas[i].codProduto, vendas[i].qtdProduto, vendas[i].valorVenda);
            printf("_____________________________________________________________________________");    
        }
        system("pause");
        system("cls");   
    }
}

int menu(){
    int opc;

    printf("Escolha uma op��oo:\n");
    printf("1. Cadastrar cliente \n2. Cadastrar produto \n3. Cadastrar uma venda\n");
    printf("4. Listar venda \n5. Listar todos clientes \n6. Sair\n");
    scanf("%d", &opc);
    getchar();
    system("cls");
    
    return opc;
}