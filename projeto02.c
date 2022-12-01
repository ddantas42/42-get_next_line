#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Imprimir resultados
int print_results(int resultado, int random, int count, int tentativas[10])
{
	int n;

	if (resultado == 1)
		printf("\nParabéns! Acertou! (%d) :D\nNúmero de tentativas: %d/10\nSuas tentativas: [ %d", random, count, tentativas[0]);
	if (resultado == 0)
		printf("\nNão conseguiste acertar no valor %d :(\nNúmero de tentativas: %d/10\nSuas tentativas: [ %d", random, count, tentativas[0]);
	
	n = 1;
	while (tentativas[n] >= 0 && tentativas[n] <= 100 && (n <= count - 1))
		printf(" %d", tentativas[n++]);
	printf(" ]\n\n");
	printf("A voltar ao menu principal...\n\n");
	return (0);
}

int option1(int check_scan)
{
	int random;
	int count;
	int tentativas[10];
	int user_input;


// Introdução ao jogo
	printf("\n|| Bem-vindo ao Adivinhe o Número! ||\n");
	sleep(2);
	printf("\nInstruções:\n 1. Adivinhe um numero de 0 a 100 (inclusive)\n 2. Têm 10 tentativas.\n 3. Cada tentativa, têm uma dica se o número é maior ou menos do que o seu palpite.\n\n");
	sleep(3);
	
	srand(time(0));
	random = rand() % 101;

	if (!random) // Protecao caso o random nao seja valido
	{
		printf("\n\nErro a gerar o numero. Reiniciado programa...\n\n");
		return(0);
	}

	printf("Número gerado com sucesso! Boa sorte e divirta-se!\n");
	sleep(2);

	count = 1;
	while (count <= 10)
	{
		printf("\nTentativa nº %d/10\nSeu palpite: ", count);
loop_1:
		check_scan = scanf("%d", &user_input);
		while (check_scan != 1)
		{
				printf("\nInput Inválido!\n");
				scanf("%*[^\n]");
				sleep(1);
				printf("Insira o seu palpite novamente:");
				goto loop_1;
		}

		if (user_input > 100 || user_input < 0)
		{
			printf("\nO número têm de estar entre 0 e 100! Tente novamente\n");
			sleep(1);
			continue;
		}
		
		tentativas[count - 1] = user_input;

		if (user_input == random)
			return (print_results(1, random, count, tentativas));
		else if (user_input > random)
			printf("\nO seu palpite está acima do valor. Tente de novo!\n");
		else if (user_input < random)
			printf("\nO seu palpite está abaixo do valor. Tente de novo!\n");
		
		sleep(1);
		count++;
	}
	return (print_results(0,random, count - 1, tentativas));
}

int option2(int check_scan)
{
	int matriz[3][3];
	int linha;
	int coluna;
	int soma;

	printf("\n|| Bem-vindo a Desenhar matrizes quadráticas! ||\n");
	sleep(2);
	printf("\nInstruções:\n 1. Digite todos os números da matriz nas posições indicadas.\n\n");
	sleep(2);

	// Criacao da matriz
	linha = 0;
	while (linha < 3)
	{
		coluna = 0;
		while (coluna < 3)
		{
			printf("\nInsire o número da Linha %d Coluna %d: ", linha + 1 , coluna + 1);
	loop_2:
			check_scan = scanf("%d", &matriz[linha][coluna]);
			while (check_scan != 1)
			{
				printf("\nInput Inválido!");
				scanf("%*[^\n]");
				sleep(1);
				printf("\nInsira uma opção válida (linha: %d coluna: %d): ", linha + 1, coluna + 1);
				goto loop_2;
			}
			sleep(1);
			coluna++;
		}
		linha++;
	}

	// Imprimir matrix
	printf("\nA matrix foi criada com sucesso!\n");
	sleep(2);
	linha = 0;
	while (linha < 3)
	{
		printf("| %d %d %d |\n", matriz[linha][0], matriz[linha][1], matriz[linha][2]);
		linha++;
	}
	sleep(1);
	soma = matriz[1][1] + matriz[2][2] + matriz[3][3] + matriz[1][2] + matriz[1][3] + matriz[2][3];
	printf("A soma dos números acima da diagonal é: %d\n", soma);
	
	sleep(1);
	soma = matriz[1][1] + matriz[2][2] + matriz[3][3] + matriz[2][1] + matriz[3][1] + matriz[3][2];
	printf("A soma dos números abaixo da diagonal é: %d\n", soma);
	
	printf("A voltar ao menu principal...\n\n");
	return (0);
}

int main()
{
	int check_scan;
	int option;

inicio:
// imprimir informações 
	printf("-----------------------------------------------------------------------------------\n");
	printf("Projeto 1 de programação, escolha o que deseja fazer:\n");
	sleep(2);
	printf("(1) Adivinhar o número\n(2) Desenhar matrizes quadráticas\n(3) Sair do programa\nOpção: ");

	while (1)
	{

loop_main:

		check_scan = scanf("%d", &option);		
		while (check_scan != 1)
		{
			printf("\nInput Inválido! Escolha um número entre 1 a 3.");
			scanf("%*[^\n]");
			sleep(1);
			printf("\nInsira uma opção válida: ");
			goto loop_main;
		}
		if (option <= 3 && option >= 1)
			break;
		printf("\nEscolha um número entre 1 a 3!\nOpção: ");
	}
// Options selection
	switch (option)
	{
		case 1:
		{
			option1(check_scan);
			sleep(5);
			goto inicio;
		}
		case 2:
		{
			option2(check_scan);
			sleep(5);
			goto inicio;
		}
		case 3:
			break;
	}

	printf("\n\nPrograma encerrando...\n\n");
	sleep(2);

	return (0);
}	