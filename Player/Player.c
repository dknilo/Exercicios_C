//Inclusão de bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Declaração de estrutura de dados heterogênea
struct MinhaLista
{
	char nome[100];
	char artista[100];
	char duracao[10];
	MinhaLista* next;
} *head = NULL, * tail = NULL;

//Declaração de rotinas do programa
void cabecalho();
void menu();
void incluirMusica();
void listarMusicas();

//Rotina principal
int main()
{
	//Declaração de variáveis
	int c, opcao;

	//Chama rotina para imprimir cabeçalho
	cabecalho();

	do //Inicia laço de repetição
	{
		//Chama rotina para imprimir menu
		menu();

		scanf_s("%d", &opcao);//Lê opção do menu selecionada

		while ((c = getchar()) != '\n' && c != EOF) {} // limpa cache

		switch (opcao) // Valida opção selecionada
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
			//Informa usuário que programa será encerrado
			printf_s("\n Player encerrado! \n");
			break;
		default:
			//Informa usuário escolha incorreta
			printf_s("Opcao invalida! Escolha novamente \n");
			break;
		}

	} while (opcao != 0); //Repete até usuário selecionar opção para encerrar programa

	printf_s("\n\n");
	printf(" BYE");
	printf_s("\n\n");

	//Encerra programa
	system("pause");
	return 0;

}

//Rotina responsável por imprimir cabeçalho na tela
void cabecalho() {

	//Limpa tela
	system("cls");

	//Imprime dados de cabeçalho
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

//Rotina responsável por imprimir menu na tela
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

//Rotina responsável por carregar novos dados informado pelo usuário na estrutura
void incluirMusica() {

	//Declaração de variáveis
	int c, opcao = 1;

	do //inicia laço de repetição
	{
		MinhaLista* playlist;
		playlist = (struct MinhaLista*)malloc(sizeof(struct MinhaLista));//Aloca espaço na memória para a estrutura

		if (opcao != 1) { //Quando opção selecionada for inválida, informar usuário
			printf_s("\n ### Opcao invalida! Escolha novamente ### \n");
		}
		else
		{
			//Chama rotina para imprimir cabeçalho
			cabecalho();
			printf_s("------------------------------------------------------------------\n");
			printf_s("---------------------- INCLUIR NOVA MUSICA -----------------------\n");
			printf_s("------------------------------------------------------------------\n");
			printf_s("\n");

			//Solicita dados de entrada para usuário e carrega na lista
			printf_s("Informe o nome da musica = ");
			fgets(playlist->nome, 100, stdin);

			printf_s("Informe o artista/banda da musica = ");
			fgets(playlist->artista, 100, stdin);

			printf_s("Informe a duracao da musica = ");
			fgets(playlist->duracao, 10, stdin);

			//Inicializa ponteiro para próximo registro com valor nulo
			playlist->next = NULL;

			if (head == NULL) { //Quando for o primeiro registro da lista
			//Grava registro como início e fim da fila
				head = playlist;
				tail = playlist;
			}
			else // Quando não for o primeiro registro da lista
			{ // Grava registro como fim da fila
				tail->next = playlist;
				tail = playlist;
			}

			//Informa que a inclusão foi bem sucedida
			printf_s("\n Musica incluida na lista!! \n");

		}

		//Imprime opções para continuar
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

//Rotina responsável por listar dados cadastrados
void listarMusicas() {

	//declaração de variáveis
	int indice = 1;

	MinhaLista* Playlist = head; // Inicializa fila com o primeiro registro

	//Chama rotina para imprimir cabeçalho
	cabecalho();

	printf_s("------------------------------------------------------------------\n");
	printf_s("----------------------- -LISTA DE MUSICAS ------------------------\n");
	printf_s("------------------------------------------------------------------\n");

	if (head == NULL) //Se a fila estiver vazia, informar usuário
		printf("\nPlayer vazio!!!\n\n");
	else
	{
		while (Playlist->next != NULL) { // Enquanto houver próximo registro na fila, mantem o laço de repetição
			//Imprime dados cadastrados na fila
			printf_s("------------------------------------------------------------------\n");
			printf_s(" Posicao = %d\n", indice);
			printf_s(" Musica = %s", Playlist->nome);
			printf_s(" Artista = %s", Playlist->artista);
			printf_s(" Duracao = %s", Playlist->duracao);
			printf_s("------------------------------------------------------------------\n");
			Playlist = Playlist->next; //incrementa fila para o próximo registro
			indice++; //incrementa variável de índice
		}

		//Imprime dados da última posição da fila
		printf_s("------------------------------------------------------------------\n");
		printf_s(" Posicao = %d\n", indice);
		printf_s(" Musica = %s", Playlist->nome);
		printf_s(" Artista = %s", Playlist->artista);
		printf_s(" Duracao = %s", Playlist->duracao);
		printf_s("------------------------------------------------------------------\n");

	}

	//Comando incluído para manter os dados na tela até usuário digitar qualquer tecla
	system("pause");

}