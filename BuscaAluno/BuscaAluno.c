//Inclus�o de bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

//Declara��o de estrutura de dados heterog�nea
struct Alunos {
	char ru[20];
	char nome[100];
	char email[100];
	Alunos* next;
}*head = NULL, * tail = NULL;

//Declara��o de rotinas do programa
void cabecalho();
void carregaAlunos(char buffer[100]);
void buscaAluno(int ru);

//Rotina principal
int main()
{
	//Declara��o de vari�veis
	int retorno;

	FILE* arq; // Vari�vel alocada din�micamente para leitura do arquivo de texto
	char buffer[100], pesquisa[20];

	// Abre arquivo de texto
	retorno = fopen_s(&arq, "Alunos.txt", "r");

	if (retorno != 0) { //Se o arquivo n�o for encontrado, informar usu�rio
		printf_s("ERRO -> Arquivo n�o encontrado! \n");
	}
	else
	{// Para leitura do arquivo, percorre todas as linhas preenchidas
		while (fgets(buffer, 100, arq) != NULL) {
			//chama rotina para carregar dados do arquivo na estrutura
			carregaAlunos(buffer);
		}
		//fechando o arquivo
		fclose(arq);
	}

	//Chama rotina para imprimir cabe�alho
	cabecalho();

	//Solicita ao usu�rio entrada de dados para pesquisa
	printf_s("==============================================================\n");
	printf_s("Digite o RU do Aluno: ");
	fgets(pesquisa, 100, stdin);

	printf_s("==============================================================\n");
	//Chama rotina para efetuar consulta, convertendo dado de entrada de string para inteiro
	buscaAluno(atoi(pesquisa));

	//Encerra programa
	system("pause");
	return 0;

}

//Rotina respons�vel por imprimir cabe�alho na tela
void cabecalho() {

	//Limpa tela
	system("cls");

	//Imprime dados de cabe�alho
	printf_s("#############################################################\n");
	printf_s("################### UNINTER - Alunos ########################\n");
	printf_s("#############################################################\n");
	printf_s("\n\n");

}

//Rotina respons�vel por carregar dados do arquivo de texto na estrutura
void carregaAlunos(char buffer[100]) {

	//Declara��o de vari�veis
	int i, j;

	Alunos* NovoAluno;
	NovoAluno = (struct Alunos*)malloc(sizeof(struct Alunos)); //Aloca espa�o na mem�ria para a estrutura

	//Efetua leitura da linha at� encontrar o primeiro (;)
	for (i = 0; buffer[i] != ';'; i++) {
		//Grava dados na estrutura caracter por caracter
		NovoAluno->ru[i] = buffer[i];
	}

	//Inclui final da String
	NovoAluno->ru[i] = '\0';

	//Efetua leitura da linha at� encontrar o pr�ximo (;)
	for (++i, j = 0; buffer[i] != ';'; i++, j++) {
		//Grava dados na estrutura caracter por caracter
		NovoAluno->nome[j] = buffer[i];
	}

	//Inclui final da String
	NovoAluno->nome[j] = '\0';

	//Efetua leitura da linha at� encontrar final da string
	for (++i, j = 0; buffer[i] != '\0'; i++, j++) {
		//Grava dados na estrutura caracter por caracter
		NovoAluno->email[j] = buffer[i];
	}

	//Inclui final da String
	NovoAluno->email[j] = '\0';

	//Inicializa ponteiro para pr�ximo registro com valor nulo
	NovoAluno->next = NULL;

	if (head == NULL) { //Quando for o primeiro registro da lista
	//Grava registro como in�cio e fim da fila
		head = NovoAluno;
		tail = NovoAluno;
	}
	else // Quando n�o for o primeiro registro da lista
	{ // Grava registro como fim da fila
		tail->next = NovoAluno;
		tail = NovoAluno;
	}

}

//Rotina respons�vel por efetuar a consulta dos registros
void buscaAluno(int ru) {

	//Declara��o de vari�veis
	Alunos* listaAluno = head; // Inicializa fila com o primeiro registro

	int achou = 0, valida;

	if (head == NULL) //Se a fila estiver vazia, informar usu�rio
		printf("\n Arquivo vazio!\n");
	else {
		while (achou == 0) { // Inicializa loop nos registros para efetuar a busca
		//Converte string para inteiro para efetuar a compara��o
			valida = atoi(listaAluno->ru);
			if (ru == valida) { // Se o registro for localizado, altera vari�vel de controle
				achou = 1;
			}
			else if (listaAluno->next == NULL) { // Se � o �ltimo registro da fila, altera vari�vel de controle
				achou = 2;
			}
			else
			{ // Caso contr�rio, incrementa fila para o pr�ximo registro
				listaAluno = listaAluno->next;
			}
		}

		if (achou == 1) { // Quando localizar o registro, imprimir na tela dados encontrados
			printf_s("==============================================================\n");
			printf_s(" Nome = %s\n", listaAluno->nome);
			printf_s(" E-mail = %s", listaAluno->email);
			printf_s("==============================================================\n");
		}
		else { // Quando n�o localizar o registro, informar usu�rio
			printf_s("==============================================================\n");
			printf_s(" ERRO => Aluno nao localizado! \n");
			printf_s("==============================================================\n");
		}
	}
}
