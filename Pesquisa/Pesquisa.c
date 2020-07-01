#include<stdio.h>
#include<stdlib.h>

//Declaração de rotinas
void Cabecalho();
char ValidaResposta(int num_quest);

int main() { //Principal

	//Declaração de variáveis
	char sexo, aprova;
	int total_resp = 0, total_masc = 0, total_fem = 0, total_sim = 0, total_nao = 0;
	float perc_masc, perc_fem;

	//Chamada de rotina para montar Cabeçalho
	Cabecalho();

	//Início do loop para armazenar respostas
	do {
		total_resp++; //Incrementa contador

		printf_s("***********************************************************\n");
		printf_s("Entrevista numero = %d", total_resp);//Informa número da entrevista
		printf_s("\n\n");

		//Guarda retorno da função na variável
		sexo = ValidaResposta(1);

		if (sexo == 'M') {
			//Se a primeira resposta foi masculino, incrementa contador masculino
			total_masc++;
		}
		else {
			//Se a primeira resposta não foi masculino, incrementa contador feminino
			total_fem++;
		}

		printf_s("\n");

		//Guarda retorno da função na variável
		aprova = ValidaResposta(2);

		if (aprova == 'S') {
			//Se a segunda resposta foi sim, incrementa contador sim
			total_sim++;
		}
		else {
			//Se a segunda resposta não foi sim, incrementa contador não
			total_nao++;
		}

		printf_s("\n");
		printf_s("***********************************************************\n");
		printf_s("\n\n");

	} while (total_resp < 150); //Enquanto total de entrevistas não atingir 150, mantem o loop

	//Efetua o cálculo de percentagem convertendo todos os valores para real
	perc_masc = (((float)total_masc * 100) / (float)total_resp);
	perc_fem = (((float)total_fem * 100) / (float)total_resp);

	//Imprime resultados da pesquisa//
	printf_s("***********************************************************\n");
	printf_s("Total de Participantes = %d\n", total_resp);
	printf_s("Total de Respostas Sim = %d\n", total_sim);
	printf_s("Total de Respostas Nao = %d\n", total_nao);
	printf_s("Percentagem de pessoas do sexo masculino = %.2f \n", perc_masc);
	printf_s("Percentagem de pessoas do sexo feminino = %.2f \n", perc_fem);
	printf_s("***********************************************************\n");

	system("pause");
	return 0;

}

void Cabecalho() {

	//Imprime Cabeçalho
	printf_s("***********************************************************\n");
	printf_s("***********************************************************\n");
	printf_s("********************PESQUISA DE MERCADO********************\n");
	printf_s("***********************************************************\n");
	printf_s("***********************************************************\n");
	printf_s("\n");

}

char ValidaResposta(int num_quest) { //Função recebe um parâmetro para identificar a pergunta

	char resposta, c;
	int sair = 0;

	if (num_quest == 1) { //Se parâmetro for 1, imprime a primeira pergunta

		//Imprime primeira pergunta
		printf_s("Digite seu sexo (M/F): \n");
		scanf_s("%c", &resposta, 1);

		//Limpa buffer do teclado
		while ((c = getchar()) != '\n' && c != EOF) {};

		do { //Abre loop para validar resposta

			if (resposta == 'M' || resposta == 'F') {
				/*Se a resposta for masculino OU feminino
				altera variável de controle para 1*/
				sair = 1;
			}
			else {
				/*Se a resposta não estiver entre as esperadas
				repete a pergunta*/
				printf_s("\n");
				printf_s("### Resposta invalida ###");
				printf_s("\n");
				printf_s("Digite seu sexo (M/F): \n");
				scanf_s("%c", &resposta, 1);
				while ((c = getchar()) != '\n' && c != EOF) {};
			}

		} while (sair == 0);//Enquanto variável de controle for 0(zero), mantem o loop

		return resposta; //Retorna resposta obtida para o programa principal

	}
	else { //Se parâmetro não for 1, imprime a segunda pergunta

		//Imprime primeira pergunta
		printf_s("Gostou do produto (S/N): \n");
		scanf_s("%c", &resposta, 1);

		//Limpa buffer do teclado
		while ((c = getchar()) != '\n' && c != EOF) {};

		do { //Abre loop para validar resposta

			if (resposta == 'S' || resposta == 'N') {
				/*Se a resposta for sim OU não
				altera variável de controle para 1*/
				sair = 1;
			}
			else {
				/*Se a resposta não estiver entre as esperadas
				repete a pergunta*/
				printf_s("\n");
				printf_s("### Resposta invalida ###");
				printf_s("\n");
				printf_s("Gostou do produto (S/N): \n");
				scanf_s("%c", &resposta, 1);
				while ((c = getchar()) != '\n' && c != EOF) {};
			}

		} while (sair == 0); //Enquanto variável de controle for 0(zero), mantem o loop

		return resposta; //Retorna resposta obtida para o programa principal

	}

}
