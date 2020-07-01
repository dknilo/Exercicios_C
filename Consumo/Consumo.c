#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Definir valor do Kilowatt
#define custoKW 1.75;

//Declaração de rotinas
void Menu();
void CadastraConsumidor(int* num_conta, int* total_cons, float* val_total);
int ValidaDuplicidade(int* num_conta, int conta, int cont);
void ListarConsumidor(int* num_conta, int* total_cons, float* val_total);
void MaiorConsumo(int* num_conta, int* total_cons, float* val_total);
void MenorConsumo(int* num_conta, int* total_cons, float* val_total);
void MediaConsumo(int* num_conta, int* total_cons, float* val_total);
void ConsumoAcima(int* num_conta, int* total_cons, float* val_total);

int main() { //Principal

	setlocale(LC_ALL, "Portuguese"); //Setar português para localidade para imprimir caracteres com acentuação

	//Declaração de variáveis e vetores
	int opcao, contrl = 1, num_conta[150] = { 0 }, total_cons[150] = { 0 };
	float val_total[150] = { 0 };
	char c;

	//Abre loop para manter execução até usuário solicitar a interrupção
	while (contrl != 0) {

		//Chama rotina para apresentar Menu
		Menu();

		//Guarda na variável opção digitada pelo usuário
		scanf_s("%d", &opcao);

		//Limpa buffer do teclado
		while ((c = getchar()) != '\n' && c != EOF) {};

		switch (opcao) //Compara opção informada no menu e seleciona a rotina especifica
		{
		case 1:
			/* Quando opção 1 for selecionada, chama rotina para cadastro
			de consumidores passando os vetores de parâmetros */
			printf_s("Opção selecionada = CADASTRAR CONSUMIDOR \n\n");
			CadastraConsumidor(num_conta, total_cons, val_total);
			break;
		case 2:
			/* Quando opção 2 for selecionada, chama rotina para listar
			consumidores cadastrados, passando os vetores de parâmetros */
			printf_s("Opção selecionada = LISTAR CADASTROS \n\n");
			ListarConsumidor(num_conta, total_cons, val_total);
			break;
		case 3:
			/* Quando opção 3 for selecionada, chama rotina para informar
			consumidor de maior consumo, passando os vetores de parâmetros */
			printf_s("Opção selecionada = MAIOR CONSUMO \n\n");
			MaiorConsumo(num_conta, total_cons, val_total);
			break;
		case 4:
			/* Quando opção 4 for selecionada, chama rotina para informar
			consumidor de menor consumo, passando os vetores de parâmetros */
			printf_s("Opção selecionada = MENOR CONSUMO \n\n");
			MenorConsumo(num_conta, total_cons, val_total);
			break;
		case 5:
			/* Quando opção 5 for selecionada, chama rotina para informar
			média de consumo da cidade, passando os vetores de parâmetros */
			printf_s("Opção selecionada = MÉDIA DA CIDADE \n\n");
			MediaConsumo(num_conta, total_cons, val_total);
			break;
		case 6:
			/* Quando opção 6 for selecionada, chama rotina para informar
			quantidade de consumidores que ultrapassaram 170KW de consumo,
			passando os vetores de parâmetros */
			printf_s("Opção selecionada = CONSUMO ACIMA DE 170KW \n\n");
			ConsumoAcima(num_conta, total_cons, val_total);
			break;
		case 0:
			/* Quando opção 0 for selecionada, informa que programa foi
			finalizado e seta variável de controle para sair do loop */
			printf_s("PROGRAMA FINALIADO COM SUCESSO \n\n");
			contrl = 0;
			break;
		default:
			/* Quando qualquer outra opção for digitada, informa usuário
			que a opção é inválida */
			printf_s("OPÇÃO INVÁLIDA \n\n");
			break;
		}
	}

	system("pause");
	return 0;

}

void Menu() {
	
	//Imprime as opções de Menu
	printf_s("##############################################\n");
	printf_s("##############################################\n");
	printf_s("#                    MENU                    #\n");
	printf_s("##############################################\n");
	printf_s("##############################################\n");
	printf_s("# 1 - CADASTRAR CONSUMIDOR                   #\n");
	printf_s("# 2 - LISTAR CADASTROS                       #\n");
	printf_s("# 3 - MAIOR CONSUMO                          #\n");
	printf_s("# 4 - MENOR CONSUMO                          #\n");
	printf_s("# 5 - MÉDIA DA CIDADE                        #\n");
	printf_s("# 6 - CONSUMO ACIMA DE 170KW                 #\n");
	printf_s("# 0 - FINALIZAR PROGRAMA                     #\n");
	printf_s("##############################################\n");
	printf_s("##############################################\n");
	printf_s("\n\n");
	printf_s("Informe uma opção do Menu: \n");

}

//Procedimento para cadastrar consumidores, recebe como parâmetro os vetores por referência
void CadastraConsumidor(int* num_conta, int* total_cons, float* val_total) {

	//Declaração de variáveis
	int i, limite = 0, dup = 0;
	char c;

	//Abre loop para percorrer todo o vetor e localizar posição vaga
	for (i = 0; i < 150; i++) {

		if (num_conta[i] == 0) {
			//Quando encontrar posição vaga, sai do loop
			break;
		}
		if (i == 149) {
			/* Se não encontrou nenhuma posição vaga, informa usuário e
			seta variável para barrar o cadastro*/
			printf_s("Limite de cadastros atingido!!! Não é possível efetuar novo cadastro!\n\n");
			limite = 1;
		}

	}

	if (limite == 0) { // Se há posição vaga no vetor para o cadastro

		do { // Abre loop para validação do cadastro da conta

			//Solicita número da conta para cadastro
			printf_s("Informe o número da conta do consumidor: \n");
			scanf_s("%d", &num_conta[i]);

			//Limpa buffer do teclado
			while ((c = getchar()) != '\n' && c != EOF) {};

			if (num_conta[i] == 0) { //Não é permitido número de conta igual a zero
				printf_s("*** Número da conta não pode ser zero ***\n");
			}
			else {
				/* Chama rotina para validar duplicidades, não será permitido cadastrar
				duas contas iguais. Passado por parâmetro o vetor de contas cadastradas,
				o número da conta a ser validada e sua posição no vetor */
				dup = ValidaDuplicidade(num_conta, num_conta[i], i);
				if (dup == 1) { // Se localizou duplicidade, informa usuário que cadastro não será aceito
					printf_s("*** Número de conta já cadastrado, informe outro número ***\n");
				}
			}

			/* Mantem o loop enquanto número da conta informada for igual a zero
			ou houver duplicidade */
		} while ((num_conta[i] == 0) || (dup == 1));

		do { // Abre loop para validação do cadastro do consumo

			//Solicita número de consumo para cadastro
			printf_s("Informe o total de KW consumido no mês: \n");
			scanf_s("%d", &total_cons[i]);

			//Limpa buffer do teclado
			while ((c = getchar()) != '\n' && c != EOF) {};

			if (total_cons[i] == 0) { //Não é permitido número de consumo igual a zero
				printf_s("*** Total consumido não pode ser zero ***\n");
			}

			// Mantem o loop enquanto número de consumo informado for igual a zero
		} while (total_cons[i] == 0);

		/* Calcula total a pagar para o consumidor cadastrado efetuando
		a multiplicação do valor do Kilowatt definido no início do programa
		com o total consumido que foi informado. Valores são convertidos
		para real e salvos no vetor de valor total*/

		val_total[i] = (float)total_cons[i] * custoKW;

		//Informa usuário que cadastro foi finalizado
		printf_s("Total a pagar R$%.2f\n", val_total[i]);
		printf_s("Cadastro efetuado com sucesso!!!\n\n");

	}
}

//Função para validar duplicidades no cadastro de contas, recebe como parâmetro os vetores por referência
int ValidaDuplicidade(int* num_conta, int conta, int cont) {

	//Declaração de variáveis
	int achou = 0;

	//Abre loop para percorrer todo o vetor e localizar as contas cadastradas
	for (int i = 0; i < 150; i++) {

		//Compara se a conta cadastrada já existe, excluindo a sua posição do vetor
		if ((num_conta[i] == conta) && (i != cont)) {
			//Se achou duplicidade, seta variável de controle e para o loop
			achou = 1;
			break;
		}
	}

	/* Retorno:
	0 - Sem duplicidade
	1 - Com duplicidade */
	return achou;

}

//Procedimento para listar consumidores, recebe como parâmetro os vetores por referência
void ListarConsumidor(int* num_conta, int* total_cons, float* val_total) {

	printf_s("Cosumidores:\n");

	//Abre loop para percorrer todo o vetor e localizar as contas cadastradas
	for (int i = 0; i < 150; i++) {

		if (num_conta[i] != 0) {
			//Imprime todas as contas armazenadas no vetor que são diferente de zero
			printf_s("=========================================\n");
			printf_s("Conta do Consumidor = %d\n", num_conta[i]);
			printf_s("Consumo em KW = %d\n", total_cons[i]);
			printf_s("Total a pagar R$%.2f\n", val_total[i]);
		}
	}

	printf_s("=========================================\n");
}

//Procedimento para imprimir consumidor com maior consumo, recebe como parâmetro os vetores por referência
void MaiorConsumo(int* num_conta, int* total_cons, float* val_total) {

	//Declaração de variáveis
	int cont = 0, maior = 0;

	printf_s("Cosumidor com maior consumo no mês:\n");

	//Abre loop para percorrer todo o vetor e localizar as contas cadastradas
	for (int i = 0; i < 150; i++) {

		if (num_conta[i] != 0) { //Percorre o vetor e localiza as contas cadastradas(diferente de zero)
			if (maior == 0) {
				/* Se variável estiver zerada, não é necessário comparação
				guarda valor de consumo e posição do vetor */
				maior = total_cons[i];
				cont = i;
			}
			else if (total_cons[i] > maior) {
				/* Se valor do consumo do vetor for maior que o guardado na variável
				guarda valor de consumo e posição do vetor */
				maior = total_cons[i];
				cont = i;
			}
		}
	}

	printf_s("=========================================\n");

	if (maior == 0) {
		// Se variável permanecer zerada, informar que não há contas cadastradas
		printf_s("Não há contas cadastradas!!!\n");
	}
	else {
		// Imprime dados do consumidor gravado na posição que retornou na comparação do loop
		printf_s("Conta do Consumidor = %d\n", num_conta[cont]);
		printf_s("Consumo em KW = %d\n", total_cons[cont]);
		printf_s("Total a pagar R$%.2f\n", val_total[cont]);
	}

	printf_s("=========================================\n\n");

}

//Procedimento para imprimir consumidor com menor consumo, recebe como parâmetro os vetores por referência
void MenorConsumo(int* num_conta, int* total_cons, float* val_total) {

	//Declaração de variáveis
	int cont = 0, menor = 0;

	printf_s("Cosumidor com menor consumo no mês:\n");

	//Abre loop para percorrer todo o vetor e localizar as contas cadastradas
	for (int i = 0; i < 150; i++) {

		if (num_conta[i] != 0) { //Percorre o vetor e localiza as contas cadastradas(diferente de zero)
			if (menor == 0) {
				/* Se variável estiver zerada, não é necessário comparação
				guarda valor de consumo e posição do vetor */
				menor = total_cons[i];
				cont = i;
			}
			else if (total_cons[i] < menor) {
				/* Se valor do consumo do vetor for menor que o guardado na variável
				guarda valor de consumo e posição do vetor */
				menor = total_cons[i];
				cont = i;
			}
		}
	}

	printf_s("=========================================\n");

	if (menor == 0) {
		// Se variável permanecer zerada, informar que não há contas cadastradas
		printf_s("Não há contas cadastradas!!!\n");
	}
	else {
		// Imprime dados do consumidor gravado na posição que retornou na comparação do loop
		printf_s("Conta do Consumidor = %d\n", num_conta[cont]);
		printf_s("Consumo em KW = %d\n", total_cons[cont]);
		printf_s("Total a pagar R$%.2f\n", val_total[cont]);
	}

	printf_s("=========================================\n\n");

}

//Procedimento para imprimir média de consumo, recebe como parâmetro os vetores por referência
void MediaConsumo(int* num_conta, int* total_cons, float* val_total) {

	//Declaração de variáveis
	int total = 0, cont = 0;
	float valor = 0, media, mediaValor;

	printf_s("Média de consumo/mês da cidade:\n");

	//Abre loop para percorrer todo o vetor e localizar as contas cadastradas
	for (int i = 0; i < 150; i++) {

		if (num_conta[i] != 0) { //Percorre o vetor e localiza as contas cadastradas(diferente de zero)
		// Soma valores nas variáveis
			total = total + total_cons[i];
			valor = valor + val_total[i];
			cont++;
		}
	}

	// Calcula média de total consumido e valor
	media = (float)total / (float)cont;
	mediaValor = valor / (float)cont;

	printf_s("=========================================\n");

	if (cont == 0) {
		// Se variável permanecer zerada, informar que não há contas cadastradas
		printf_s("Não há contas cadastradas!!!\n");
	}
	else {
		// Imprime resultado das médias calculadas
		printf_s("Total de consumidores = %d\n", cont);
		printf_s("Média de consumo em KW = %.2f\n", media);
		printf_s("Média de consumo em valor = R$%.2f\n", mediaValor);
	}

	printf_s("=========================================\n\n");

}

//Procedimento para imprimir consumos acima de 170KW, recebe como parâmetro os vetores por referência
void ConsumoAcima(int* num_conta, int* total_cons, float* val_total) {

	//Declaração de variáveis
	int cont = 0;

	printf_s("Consumos acima de 170KW:\n");
	printf_s("=========================================\n");

	//Abre loop para percorrer todo o vetor e localizar as contas cadastradas
	for (int i = 0; i < 150; i++) {

		if (num_conta[i] != 0) { //Percorre o vetor e localiza as contas cadastradas(diferente de zero)
			if (total_cons[i] > 170) {
				//Imprime dados de contas com consumo acima de 170
				printf_s("Conta do Consumidor = %d\n", num_conta[i]);
				printf_s("Consumo em KW = %d\n", total_cons[i]);
				printf_s("Total a pagar R$%.2f\n", val_total[i]);
				printf_s("=========================================\n\n");
				//Incrementa contador
				cont++;
			}
		}
	}

	if (cont == 0) {
		// Se variável permanecer zerada, informar que não há contas cadastradas
		printf_s("Não há contas cadastradas!!!\n");
		printf_s("=========================================\n\n");
	}
	else {
		// Informa quantidade de contas localizadas com consumo acima de 170KW
		printf_s("=========================================\n");
		printf_s("Quantidade de consumos acima de 170KW: %d\n\n", cont);
		printf_s("=========================================\n");
	}

}
