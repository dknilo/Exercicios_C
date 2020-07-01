#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

//Declara��o de rotinas
char* PosicionaPalvra(char* string_1, char* string_2, int pos);

int main() {//Principal

	//Declara��o de variaveis
	char palavra_1[50] = { 0 }, palavra_2[50] = { 0 };
	int posicao, tam, contrl = 0;

	setlocale(LC_ALL, "portuguese"); //Setar portugu�s para localidade para imprimir caracteres com acentua��o

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

	do { // Abre loop para valida��o do valor digitado para posi��o

		// Solicita um valor para posi��o
		printf_s("Digite uma posi��o: ");
		scanf_s("%d", &posicao); // Salva valor

		if (posicao == 0) {
			//Se o valor digitado for zero, informa que � inv�lido e altera vari�vel de controle para 1
			printf_s("*** Posi��o deve ser maior que zero!!! ***\n");
			contrl = 1;
		}
		else {
			//Se o valor for diferente de zero, busca tamanho da primeira string
			tam = strnlen_s(palavra_1, 50);//fun��o strlen_s (da biblioteca string.h) determina o tamanho de uma string

			if (posicao > tam) {
				//Se o tamanho da posi��o informada for maior que o da primeira string, posi��o � inv�lida
				printf_s("*** Primeira palavra possui apenas %d posi��es, escolha novamente!!! *** \n", tam);
				contrl = 1;
			}
			else {
				//Se passou nas valida��es, seta vari�vel de controle para zero
				contrl = 0;
			}
		}

	} while (contrl == 1); //Mantem o loop enquanto vair�vel de controle for iguala zero

	printf_s("==========================================================\n\n");

	// Informa onde ir� posicionar as strings
	printf_s("Posicionando palavra 2 na %d� posi��o da palavra 1:\n\n", posicao);

	// Chama fun��o para posicionar strings passando como par�metro as 20 strings e a posi��o informada pelo usu�rio
	PosicionaPalvra(palavra_1, palavra_2, posicao);

	// Imprime resultado
	printf_s("==========================================================\n");
	printf_s("\t %s\n", palavra_1);
	printf_s("==========================================================\n\n");

	system("pause");
	return 0;

}

// Fun��o respons�vel por posicionar a segunda string na posi��o informada da primeira string
// Recebe por par�metro o endere�o da primeira e segunda string e a posi��o informada pelo usu�rio
char* PosicionaPalvra(char* string_1, char* string_2, int pos)
{
	//Declara��o de vari�veis
	int i = pos - 1; //Inicializa com a posi��o que dever� come�ar a imprimir a segunda string
	char concat[50] = { 0 };

	for (int j = 0; j < i; j++)
	{// Abre loop para carregar a parte da primeira string que aparece antes da posi��o passada por par�metro
		concat[j] = string_1[j];
	}

	concat[i] = '\0'; //Acrescentar finalizador da string

	for (int j = 0; string_2[j] != '\0'; ++j, ++i)
	{//Percorre toda a string_2, para concatena-la, a partir da posi��o passada por par�metro
		concat[i] = string_2[j];
	}

	concat[i] = '\0'; //Acrescentar finalizador da string

	for (int j = pos - 1; string_1[j] != '\0'; j++, i++)
	{//Loop para concatenar parte que sobrou da primeira string
		concat[i] = string_1[j];
	}

	concat[i] = '\0'; //Acrescentar finalizador da string

	//Busca tamanho da string concatenada
	i = strnlen_s(concat, 50); //fun��o strlen_s (da biblioteca string.h) determina o tamanho de uma string

	for (int j = 0; concat[j] != '\0'; j++)
	{//Abre loop para copiar string concatenada para array de retorno
		string_1[j] = concat[j];
	}

	string_1[i] = '\0'; //Acrescentar finalizador da string

	return string_1; // Retorna array concatenado

}
