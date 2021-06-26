#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define TAM 100

typedef struct produto
{
	char nome[100];
	int id, qnt;
	float preco;

} produto;

void clear(){
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

void cadastro(produto* p, int i)
{
	clear();
	printf("Digite o codigo do produto: ");
	scanf("%d", &p[i].id);
	fflush(stdin);
	printf("Digite o nome do produto: ");
	gets(p[i].nome);
	fflush(stdin);
	printf("Digite o preco do produto: R$");
	scanf("%f", &p[i].preco);
	printf("Digite a quantidade em estoque: ");
	scanf("%d", &p[i].qnt);
	printf("\nProduto cadastrado com sucesso! Pressione qualquer tecla para continuar.");
	getch();
}

void cadastrados(produto* p, int i)
{
	clear();
	if(i == 0){
		printf("Nao ha produtos cadastrados. Pressione uma tecla para continuar.");
		getch();
		return;
	}
	for(int k = 0; k < i; k++){
		printf("Codigo %d  |  %s", p[k].id, p[k].nome);
		printf("  |  R$ %.2f  |  Em estoque: %d un.", p[k].preco, p[k].qnt);
		printf("\n-----------------------------------------------------------\n");
	}

	printf("Pressione uma tecla para continuar.");
	getch();

}

void alterar(produto* p, int i){
	int cod;
	bool flag = false;
	clear();
	printf("Digite o codigo do produto que deseja modificar o preco: ");
	scanf("%d", &cod);
	for(int k = 0; k < i; k++){
		if(cod == p[k].id){
			printf("\nPreco atual: R$%.2f.\nNovo preco: R$", p[k].preco);
			scanf("%f", &p[k].preco);
			flag = true;
		}
	}
	if(flag){
		printf("\nPreco alterado com sucesso! Pressione uma tecla para continuar.");
		getch();
		return;
	}
	else{
		printf("\nErro ao alterar o preco! Pressione 1 para tentar novamente ou 0 para voltar ao menu.");
		scanf("%d", cod);
		if(cod == 1) alterar(p, i);
		else return;
	}

}

void venda(produto* p, int i){
	int cod, qntd;
	float ent, troco, total;
	bool flag = false;
	clear();
	printf("Digite o codigo do produto a vender: ");
	scanf("%d", &cod);
	printf("Digite o numero de unidades: ");
	scanf("%d", &qntd);
	for(int k = 0; k < i; k++){
		if(cod == p[k].id){
			p[k].qnt = p[k].qnt - qntd;
			total = qntd * p[k].preco;
			flag = true;
		}
	}
	if(!flag){
		printf("\nProduto nao encontrado. Pressione uma tecla para continuar.");
		getch();
		return;
	}
	printf("\nValor total da venda: R$%.2f\nDinheiro entregue: R$", total);
	scanf("%f", &ent);
	troco = ent - total;
	printf("Troco: R$%.2f\n\nVenda realizada com sucesso! Pressione uma tecla para continuar.", troco);
	getch();
	return;
}

void reestoque(produto* p, int i){
	int cod, qntd;
	bool flag = false;
	clear();
	printf("Digite o codigo do produto: ");
	scanf("%d", &cod);
	printf("Digite a quantidade de unidades a serem colocadas no estoque: ");
	scanf("%d", &qntd);
	for(int k = 0; k < i; k++){
		if(cod == p[k].id){
			p[k].qnt = p[k].qnt + qntd;
			flag = true;
		}
	}
	if(flag){
		printf("\nInclusao realizada com sucesso! Pressione uma tecla para continuar.");
		getch();
		return;
	}
	else{
		printf("\nOcorreu um erro. Tente novamente! Pressione uma tecla para continuar.");
		getch();
		return;
	}
}

int main()
{
	produto p[TAM];
	int n = 1, i = 0;

	while (n != 0)
	{
		clear();
		printf("Digite um numero correspondente a opcao desejada!");
		printf("\n------------------------------------------\n");
		printf("1 - Cadastrar produto\n");
		printf("2 - Alterar preco\n");
		printf("3 - Visualizar produtos\n");
		printf("4 - Realizar venda\n");
		printf("5 - Reestoque de produto\n");
		printf("0 - Sair\n");
		printf("------------------------------------------\n");
		printf("Opcao: ");
		scanf("%d", &n);
		switch (n)
		{

		case 1:
			cadastro(p, i);
			i++;
			break;

		case 2:
			alterar(p, i);
			break;

		case 3:
			cadastrados(p, i);
			break;

		case 4: 
			venda(p, i);
			break;

		case 5: 
			reestoque(p, i);
			break;

		case 0:
			clear();
			printf("Ate logo! :D\n");
			break;
		}
	}
	return 0;
}
