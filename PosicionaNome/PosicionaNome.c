#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//Declaração de rotinas
char* PosicionaPalvra(char* string_1, char* string_2, int pos);

int main() {//Principal

	//Declaração de variaveis
	char palavra_1[50] = { 0 }, palavra_2[50] = { 0 };
	int posicao, tam, contrl = 0;

	setlocale(LC_ALL, "portuguese"); //Setar português para localidade para imprimir caracteres com acentuação

	printf_s("//////////////////////////////////////////////////////////\n");
	printf_s("//////////////////// POSICIONA STRING ////////////////////\n");
	printf_s("//////////////////////////////////////////////////////////\n");
	printf_s("\n\n");
	printf_s("==========================================================\n");

	printf_s("Digite a primeira palavra: "); // Solicita primeira string
	gets_s(palavra_1,50); // Grava string no array
	printf_s("==========================================================\n");

	printf_s("Digite a segunda palavra: "); // Solicita segunda strung
	gets_s(palavra_2,50); // Grava string no array
	printf_s("==========================================================\n");

	do { // Abre loop para validação do valor digitado para posição

		// Solicita um valor para posição
		printf_s("Digite uma posição: ");
		scanf_s("%d", &posicao); // Salva valor

		if (posicao == 0) {
			//Se o valor digitado for zero, informa que é inválido e altera variável de controle para 1
			printf_s("*** Posição deve ser maior que zero!!! ***\n");
			contrl = 1;
		}
		else {
			//Se o valor for diferente de zero, busca tamanho da primeira string
			tam = strnlen_s(palavra_1, 50);//função strlen_s (da biblioteca string.h) determina o tamanho de uma string

			if (posicao > tam) {
				//Se o tamanho da posição informada for maior que o da primeira string, posição é inválida
				printf_s("*** Primeira palavra possui apenas %d posições, escolha novamente!!! *** \n", tam);
				contrl = 1;
			}
			else {
				//Se passou nas validações, seta variável de controle para zero
				contrl = 0;
			}
		}

	} while (contrl == 1); //Mantem o loop enquanto vairável de controle for iguala zero

	printf_s("==========================================================\n\n");

	// Informa onde irá posicionar as strings
	printf_s("Posicionando palavra 2 na %dª posição da palavra 1:\n\n", posicao);

	// Chama função para posicionar strings passando como parâmetro as 20 strings e a posição informada pelo usuário
	PosicionaPalvra(palavra_1, palavra_2, posicao);

	// Imprime resultado
	printf_s("==========================================================\n");
	printf_s("\t %s\n", palavra_1);
	printf_s("==========================================================\n\n");

	system("pause");
	return 0;

}

// Função responsável por posicionar a segunda string na posição informada da primeira string
// Recebe por parâmetro o endereço da primeira e segunda string e a posição informada pelo usuário
char* PosicionaPalvra(char* string_1, char* string_2, int pos)
{
	//Declaração de variáveis
	int i = pos - 1; //Inicializa com a posição que deverá começar a imprimir a segunda string
	char concat[50] = { 0 };

	for (int j = 0; j < i; j++)
	{// Abre loop para carregar a parte da primeira string que aparece antes da posição passada por parâmetro
		concat[j] = string_1[j];
	}

	concat[i] = '\0'; //Acrescentar finalizador da string

	for (int j = 0; string_2[j] != '\0'; ++j, ++i)
	{//Percorre toda a string_2, para concatena-la, a partir da posição passada por parâmetro
		concat[i] = string_2[j];
	}

	concat[i] = '\0'; //Acrescentar finalizador da string

	for (int j = pos - 1; string_1[j] != '\0'; j++, i++)
	{//Loop para concatenar parte que sobrou da primeira string
		concat[i] = string_1[j];
	}

	concat[i] = '\0'; //Acrescentar finalizador da string

	//Busca tamanho da string concatenada
	i = strnlen_s(concat, 50); //função strlen_s (da biblioteca string.h) determina o tamanho de uma string

	for (int j = 0; concat[j] != '\0'; j++)
	{//Abre loop para copiar string concatenada para array de retorno
		string_1[j] = concat[j];
	}

	string_1[i] = '\0'; //Acrescentar finalizador da string

	return string_1; // Retorna array concatenado

}
