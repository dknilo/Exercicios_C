//Inclus�o de bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Declara��o de estrutura de dados heterog�nea
struct MinhaLista
{
	char nome[100];
	char artista[100];
	char duracao[10];
	MinhaLista* next;
} *head = NULL, * tail = NULL;

//Declara��o de rotinas do programa
void cabecalho();
void menu();
void incluirMusica();
void listarMusicas();

//Rotina principal
int main()
{
	//Declara��o de vari�veis
	int c, opcao;

	//Chama rotina para imprimir cabe�alho
	cabecalho();

	do //Inicia la�o de repeti��o
	{
		//Chama rotina para imprimir menu
		menu();

		scanf_s("%d", &opcao);//L� op��o do menu selecionada

		while ((c = getchar()) != '\n' && c != EOF) {} // limpa cache

		switch (opcao) // Valida op��o selecionada
		{
		case 1:
			//Chama rotina para incluir novos dados
			incluirMusica();
			cabecalho();
			break;
		case 2:
			//Chama rotina para listar dados cadastrados
			listarMusicas();
			cabecalho();
			break;
		case 0:
			//Informa usu�rio que programa ser� encerrado
			printf_s("\n Player encerrado! \n");
			break;
		default:
			//Informa usu�rio escolha incorreta
			printf_s("Opcao invalida! Escolha novamente \n");
			break;
		}

	} while (opcao != 0); //Repete at� usu�rio selecionar op��o para encerrar programa

	printf_s("\n\n");
	printf(" BYE");
	printf_s("\n\n");

	//Encerra programa
	system("pause");
	return 0;

}

//Rotina respons�vel por imprimir cabe�alho na tela
void cabecalho() {

	//Limpa tela
	system("cls");

	//Imprime dados de cabe�alho
	printf_s("\n");
	printf_s("##################################################################\n");
	printf_s("##################################################################\n");
	printf_s("###                                                            ###\n");
	printf_s("### ######### ##          ###    ##     ## ######## ########   ###\n");
	printf_s("### ##     ## ##         ## ##    ##   ##  ##       ##    ##   ###\n");
	printf_s("### ##     ## ##        ##   ##    ## ##   ##       ##    ##   ###\n");
	printf_s("### ######### ##       ##     ##    ##     ######   ########   ###\n");
	printf_s("### ##        ##       #########    ##     ##       ## ##      ###\n");
	printf_s("### ##        ##       ##     ##    ##     ##       ##  ##     ###\n");
	printf_s("### ##        ##       ##     ##    ##     ##       ##   ##    ###\n");
	printf_s("### ##        ######## ##     ##    ##     ######## ##    ##   ###\n");
	printf_s("###                                                            ###\n");
	printf_s("##################################################################\n");
	printf_s("##################################################################\n");
	printf_s("\n");

}

//Rotina respons�vel por imprimir menu na tela
void menu() {

	//Imprime dados de menu
	printf_s("------------------------------------------------------------------\n");
	printf_s("------------------------------ MENU ------------------------------\n");
	printf_s("------------------------------------------------------------------\n");
	printf_s("1 - Incluir nova musica \n");
	printf_s("2 - Listar todas as musicas \n");
	printf_s("0 - Encerrar Player \n");
	printf_s("------------------------------------------------------------------\n");
	printf_s("------------------------------------------------------------------\n");
	printf_s("\n");
	printf_s("Escolha uma opcao do menu = ");

}

//Rotina respons�vel por carregar novos dados informado pelo usu�rio na estrutura
void incluirMusica() {

	//Declara��o de vari�veis
	int c, opcao = 1;

	do //inicia la�o de repeti��o
	{
		MinhaLista* playlist;
		playlist = (struct MinhaLista*)malloc(sizeof(struct MinhaLista));//Aloca espa�o na mem�ria para a estrutura

		if (opcao != 1) { //Quando op��o selecionada for inv�lida, informar usu�rio
			printf_s("\n ### Opcao invalida! Escolha novamente ### \n");
		}
		else
		{
			//Chama rotina para imprimir cabe�alho
			cabecalho();
			printf_s("------------------------------------------------------------------\n");
			printf_s("---------------------- INCLUIR NOVA MUSICA -----------------------\n");
			printf_s("------------------------------------------------------------------\n");
			printf_s("\n");

			//Solicita dados de entrada para usu�rio e carrega na lista
			printf_s("Informe o nome da musica = ");
			fgets(playlist->nome, 100, stdin);

			printf_s("Informe o artista/banda da musica = ");
			fgets(playlist->artista, 100, stdin);

			printf_s("Informe a duracao da musica = ");
			fgets(playlist->duracao, 10, stdin);

			//Inicializa ponteiro para pr�ximo registro com valor nulo
			playlist->next = NULL;

			if (head == NULL) { //Quando for o primeiro registro da lista
			//Grava registro como in�cio e fim da fila
				head = playlist;
				tail = playlist;
			}
			else // Quando n�o for o primeiro registro da lista
			{ // Grava registro como fim da fila
				tail->next = playlist;
				tail = playlist;
			}

			//Informa que a inclus�o foi bem sucedida
			printf_s("\n Musica incluida na lista!! \n");

		}

		//Imprime op��es para continuar
		printf_s("\n");
		printf_s("------------------------------------------------------------------\n");
		printf_s("1 - Incluir nova musica \n");
		printf_s("0 - Voltar para o Menu \n");
		printf_s("------------------------------------------------------------------\n");
		printf_s("\n");
		printf_s("Escolha uma opcao = ");
		scanf_s("%d", &opcao);

		while ((c = getchar()) != '\n' && c != EOF) {} // limpa cache

	} while (opcao != 0);

}

//Rotina respons�vel por listar dados cadastrados
void listarMusicas() {

	//declara��o de vari�veis
	int indice = 1;

	MinhaLista* Playlist = head; // Inicializa fila com o primeiro registro

	//Chama rotina para imprimir cabe�alho
	cabecalho();

	printf_s("------------------------------------------------------------------\n");
	printf_s("----------------------- -LISTA DE MUSICAS ------------------------\n");
	printf_s("------------------------------------------------------------------\n");

	if (head == NULL) //Se a fila estiver vazia, informar usu�rio
		printf("\nPlayer vazio!!!\n\n");
	else
	{
		while (Playlist->next != NULL) { // Enquanto houver pr�ximo registro na fila, mantem o la�o de repeti��o
			//Imprime dados cadastrados na fila
			printf_s("------------------------------------------------------------------\n");
			printf_s(" Posicao = %d\n", indice);
			printf_s(" Musica = %s", Playlist->nome);
			printf_s(" Artista = %s", Playlist->artista);
			printf_s(" Duracao = %s", Playlist->duracao);
			printf_s("------------------------------------------------------------------\n");
			Playlist = Playlist->next; //incrementa fila para o pr�ximo registro
			indice++; //incrementa vari�vel de �ndice
		}

		//Imprime dados da �ltima posi��o da fila
		printf_s("------------------------------------------------------------------\n");
		printf_s(" Posicao = %d\n", indice);
		printf_s(" Musica = %s", Playlist->nome);
		printf_s(" Artista = %s", Playlist->artista);
		printf_s(" Duracao = %s", Playlist->duracao);
		printf_s("------------------------------------------------------------------\n");

	}

	//Comando inclu�do para manter os dados na tela at� usu�rio digitar qualquer tecla
	system("pause");

}