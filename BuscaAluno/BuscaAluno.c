//Inclusão de bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

//Declaração de estrutura de dados heterogênea
struct Alunos {
	char ru[20];
	char nome[100];
	char email[100];
	Alunos* next;
}*head = NULL, * tail = NULL;

//Declaração de rotinas do programa
void cabecalho();
void carregaAlunos(char buffer[100]);
void buscaAluno(int ru);

//Rotina principal
int main()
{
	//Declaração de variáveis
	int retorno;

	FILE* arq; // Variável alocada dinâmicamente para leitura do arquivo de texto
	char buffer[100], pesquisa[20];

	// Abre arquivo de texto
	retorno = fopen_s(&arq, "Alunos.txt", "r");

	if (retorno != 0) { //Se o arquivo não for encontrado, informar usuário
		printf_s("ERRO -> Arquivo não encontrado! \n");
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

	//Chama rotina para imprimir cabeçalho
	cabecalho();

	//Solicita ao usuário entrada de dados para pesquisa
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

//Rotina responsável por imprimir cabeçalho na tela
void cabecalho() {

	//Limpa tela
	system("cls");

	//Imprime dados de cabeçalho
	printf_s("#############################################################\n");
	printf_s("################### UNINTER - Alunos ########################\n");
	printf_s("#############################################################\n");
	printf_s("\n\n");

}

//Rotina responsável por carregar dados do arquivo de texto na estrutura
void carregaAlunos(char buffer[100]) {

	//Declaração de variáveis
	int i, j;

	Alunos* NovoAluno;
	NovoAluno = (struct Alunos*)malloc(sizeof(struct Alunos)); //Aloca espaço na memória para a estrutura

	//Efetua leitura da linha até encontrar o primeiro (;)
	for (i = 0; buffer[i] != ';'; i++) {
		//Grava dados na estrutura caracter por caracter
		NovoAluno->ru[i] = buffer[i];
	}

	//Inclui final da String
	NovoAluno->ru[i] = '\0';

	//Efetua leitura da linha até encontrar o próximo (;)
	for (++i, j = 0; buffer[i] != ';'; i++, j++) {
		//Grava dados na estrutura caracter por caracter
		NovoAluno->nome[j] = buffer[i];
	}

	//Inclui final da String
	NovoAluno->nome[j] = '\0';

	//Efetua leitura da linha até encontrar final da string
	for (++i, j = 0; buffer[i] != '\0'; i++, j++) {
		//Grava dados na estrutura caracter por caracter
		NovoAluno->email[j] = buffer[i];
	}

	//Inclui final da String
	NovoAluno->email[j] = '\0';

	//Inicializa ponteiro para próximo registro com valor nulo
	NovoAluno->next = NULL;

	if (head == NULL) { //Quando for o primeiro registro da lista
	//Grava registro como início e fim da fila
		head = NovoAluno;
		tail = NovoAluno;
	}
	else // Quando não for o primeiro registro da lista
	{ // Grava registro como fim da fila
		tail->next = NovoAluno;
		tail = NovoAluno;
	}

}

//Rotina responsável por efetuar a consulta dos registros
void buscaAluno(int ru) {

	//Declaração de variáveis
	Alunos* listaAluno = head; // Inicializa fila com o primeiro registro

	int achou = 0, valida;

	if (head == NULL) //Se a fila estiver vazia, informar usuário
		printf("\n Arquivo vazio!\n");
	else {
		while (achou == 0) { // Inicializa loop nos registros para efetuar a busca
		//Converte string para inteiro para efetuar a comparação
			valida = atoi(listaAluno->ru);
			if (ru == valida) { // Se o registro for localizado, altera variável de controle
				achou = 1;
			}
			else if (listaAluno->next == NULL) { // Se é o último registro da fila, altera variável de controle
				achou = 2;
			}
			else
			{ // Caso contrário, incrementa fila para o próximo registro
				listaAluno = listaAluno->next;
			}
		}

		if (achou == 1) { // Quando localizar o registro, imprimir na tela dados encontrados
			printf_s("==============================================================\n");
			printf_s(" Nome = %s\n", listaAluno->nome);
			printf_s(" E-mail = %s", listaAluno->email);
			printf_s("==============================================================\n");
		}
		else { // Quando não localizar o registro, informar usuário
			printf_s("==============================================================\n");
			printf_s(" ERRO => Aluno nao localizado! \n");
			printf_s("==============================================================\n");
		}
	}
}
