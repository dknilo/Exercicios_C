#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Declaração de rotinas
int** AlocaMatriz(int n);
void CarregaMatriz(int** matriz, int n);
int ValidaDup(int** matriz, int n, int valor);
void ImprimeMatriz(int** matriz, int n);
int SomaLinha(int** matriz, int n);
int SomaColuna(int** matriz, int n);
int SomaDiagonalPrinc(int** matriz, int n);
int SomaDiagonalSec(int** matriz, int n);

int main() { //Principal

	setlocale(LC_ALL, "portuguese"); //Setar português para localidade para imprimir caracteres com acentuação

	//Declaração de variáveis
	int** mat, dim, linha = 0, coluna = 0, diagP = 0, diagS = 0;
	char c;

	printf_s("\n\n\n QUADRADO MÁGICO\n\n\n");

	do { // Abre loop para validar número digitado

		//Solicita número de dimensão da matriz para montar dinâmicamente
		printf_s("Informe a dimensão da matriz: \n");
		scanf_s("%d", &dim);

		//Limpa buffer do teclado
		while ((c = getchar()) != '\n' && c != EOF) {};

		if (dim == 0) { // Não aceita número zero para a dimensão
			printf_s("Dimensão da Matriz não pode ser zero.\n\n");
		}

	} while (dim == 0); // Mantem o loop enquanto usuário digitar zero

	// Aloca dinâmicamente a matriz passando como parâmetro o valor digitado para dimensão
	mat = AlocaMatriz(dim);

	// Chama rotina para carregar valores da matriz, passando como parâmetro a matriz e sua dimensão
	CarregaMatriz(mat, dim);
	printf_s("\n\nMatriz Digitada:\n");
	printf_s("===============================================\n");

	// Chama rotina para imprimir valores da matriz, passando como parâmetro a matriz e sua dimensão
	ImprimeMatriz(mat, dim);
	printf_s("===============================================\n");

	// Chama função que soma os valores de cada linha da matriz, passando como parâmetro a matriz e sua dimensão
	linha = SomaLinha(mat, dim);

	if (linha != -1) { // Se retorno for negativo, não precisa executar demais funções

		// Chama função que soma os valores de cada coluna da matriz, passando como parâmetro a matriz e sua dimensão
		coluna = SomaColuna(mat, dim);

		if (coluna != -1) {// Se retorno for negativo, não precisa executar demais funções
		// Chama função que soma os valores da diagonal principal da matriz, passando como parâmetro a matriz e sua dimensão
			diagP = SomaDiagonalPrinc(mat, dim);
			// Chama função que soma os valores da diagonal secundária da matriz, passando como parâmetro a matriz e sua dimensão
				diagS = SomaDiagonalSec(mat, dim);
		}
	}

	//Se o retorno das funções tiverem o mesmo valor, encontrou um Quadrado Mágico
	if ((linha == coluna) && (linha == diagP) && (linha == diagS)) {
		printf_s("Matriz é um Quadrado Mágico!!!\n\n");
	}
	else {
		printf_s("Matriz NÃO é um quadrado mágico.\n\n");
	}

	system("pause");
	return 0;

}

// Função responsável por efetuar a alocação de forma dinâmica da Matriz
// Recebe por parâmetro valor digitado para a dimensão que será criada a matriz
int** AlocaMatriz(int n) {

	//Declaração da variável que receverá por referência os valores da dimensão da matriz
	int** matriz;

	//Aloca dimensão das linhas da matriz
	matriz = (int**)calloc(n, sizeof(int*));

	for (int i = 0; i < n; i++) {// Abre loop com número das dimensões da Matriz
	//Aloca dimensão das colunas para cada linha da matriz
		matriz[i] = (int*)calloc(n, sizeof(int));
	}

	return (matriz); //Retorna Matriz alocada
}

/*Procedimento para carregar os valores da matriz
Recebe como parâmetros a Matriz por referência e sua dimensão
*/
void CarregaMatriz(int** matriz, int n) {

	//Declaração de variaveis
	int contrl = 0, contaZero = 0;
	char c;

	for (int i = 0; i < n; i++) { //Abre o loop de linhas
		for (int j = 0; j < n; j++) { //Abre o loop de colunas

			do { //Abre loop para validação dos valores digitados
				contrl = 0;

				//Solicita valores para carregar a matriz
				printf_s("Informe o valor para a posição %d,%d da matriz\n", i, j);
				scanf_s("%d", &matriz[i][j]);

				//Limpa buffer do teclado
				while ((c = getchar()) != '\n' && c != EOF) {};

				if (matriz[i][j] == 0) {
					//Se valor digitado for zero, incrementa contador
					contaZero++;
				}
				else {
					// Se não for zero, valida se valor digitado já existe na matriz
					contrl = ValidaDup(matriz, n, matriz[i][j]);
				}

				if ((contrl == 1) && matriz[i][j] != 0) {
					//Quando retorno da função for 1 e valor digitado for diferente de zero , significa que houve duplicidade
					printf_s("*** Valor já digitado, Matriz não pode conter valores repetidos ***\n");
					contrl = 1;
				}
				else if (contaZero > 1) {
					//Quando o valor digitado for zero e o contador for maior que 1, significa que houve duplicidade
					printf_s("*** Valor já digitado, Matriz não pode conter valores repetidos ***\n");
					contaZero = 1;
					contrl = 1;
				}
				else
				{ //Entre aqui quando não houver duplicidade
					contrl = 0;
				}

			} while (contrl == 1); //Mantem o loop enquanto vairável de controle for iguala 1
		}
	}
}

/*Função para validar duplicidades na Matriz
Recebe como parâmetros a Matriz por referência, sua dimensão e valor digitado
*/
int ValidaDup(int** matriz, int n, int valor) {

	//Declaração de variaveis
	int cont = 0;

	for (int i = 0; i < n; i++) { // Abre loop de linhas
		for (int j = 0; j < n; j++) { // Abre loop de colunas
			if (matriz[i][j] == valor) { //Quando localizar o valor do parâmetro, incrementa o contador
				cont++;
			}
		}
	}

	if (cont > 1) {//Se o contador for maior que 1, valor está duplicidado
		return 1; // Retorno 1 = tem duplicidade
	}
	else {
		return 0; // Retorno 0 = não tem duplicidade
	}
}

/*Procedimento para imprimir matriz digitada
Recebe como parâmetros a Matriz por referência e sua dimensão
*/
void ImprimeMatriz(int** matriz, int n) {

	for (int i = 0; i < n; i++) { //Abre loop de linhas
		for (int j = 0; j < n; j++) { // Abre loop de colunas
		//Imprime valor da posição da matriz
			printf_s("%d\t", matriz[i][j]);
		}
		printf_s("\n");
	}
}

/*Função para somar valores de cada linha da matriz
Recebe como parâmetros a Matriz por referência e sua dimensão
*/
int SomaLinha(int** matriz, int n) {

	//Declaração de variaveis
	int somaA = 0, somaB = 0;

	for (int i = 0; i < n; i++) {//Abre loop de linhas
		for (int j = 0; j < n; j++) {//Abre loop de colunas
			if (i == 0) {
				//Se loop estiver na primeira linha, soma na variável somaA
				somaA = somaA + matriz[i][j];
			}
			else {
				//Se não estiver na primeira linha, soma na variável somaB
				somaB = somaB + matriz[i][j];
			}
		}
		if (i != 0) { //Só faz a comparação depois de passar da primeira linha
			if (somaA != somaB) {
				//Quando valores das somas das linhas for diferente, seta a variável com valor negativo e para o loop
				somaA = -1;
				break;
			}
			//Zera variável antes de ir para próxima linha
			somaB = 0;
		}
	}

	/*Retorna valor obtido com a soma dos valores das linhas ou
	valor negativo quando houver diferença entre as linhas*/
	return somaA;
}

/*Função para somar valores de cada coluna da matriz
Recebe como parâmetros a Matriz por referência e sua dimensão
*/
int SomaColuna(int** matriz, int n) {

	//Declaração de variaveis
	int somaA = 0, somaB = 0;

	for (int i = 0; i < n; i++) {//Abre loop de colunas
		for (int j = 0; j < n; j++) {//Abre loop de linhas
			if (i == 0) {
				//Se loop estiver na primeira coluna, soma na variável somaA
				somaA = somaA + matriz[j][i];
			}
			else {
				//Se não estiver na primeira coluna, soma na variável somaB
				somaB = somaB + matriz[j][i];
			}
		}
		if (i != 0) {//Só faz a comparação depois de passar da primeira coluna
			if (somaA != somaB) {
				//Quando valores das somas das colunas for diferente, seta a variável com valor negativo e para o loop
				somaA = -1;
				break;
			}
			//Zera variável antes de ir para próxima coluna
			somaB = 0;
		}
	}

	/*Retorna valor obtido com a soma dos valores das colunas ou
	valor negativo quando houver diferença entre as colunas*/
	return somaA;
}

/*Função para somar valores da diagonal principal da matriz
Recebe como parâmetros a Matriz por referência e sua dimensão
*/
int SomaDiagonalPrinc(int** matriz, int n) {

	//Declaração de variaveis
	int soma = 0;

	for (int i = 0; i < n; i++) {//Abre loop de linhas
		for (int j = 0; j < n; j++) {//Abre loop de colunas
			if (i == j) {
				/*Quando posição da linha for igual posiçao da coluna, significa que está em uma posição
				da diagonal principal e soma o valor na variável */
				soma = soma + matriz[i][j];
			}
		}
	}

	//Retorna resultado da soma
	return soma;
}

/*Função para somar valores da diagonal secundária da matriz
Recebe como parâmetros a Matriz por referência e sua dimensão
*/
int SomaDiagonalSec(int** matriz, int n) {

	//Declaração de variaveis
	int soma = 0;

	for (int i = 0; i < n; i++) {//Abre loop de linhas
		for (int j = 0; j < n; j++) {//Abre loop de colunas
			if (i == n - 1 - j) {
				/*Quando posição da linha for igual a expressão = quantidade de colunas - 1 - número da coluna atual do
				loop
				significa que está em uma posição da diagonal secundária e soma o valor na variável */
				soma = soma + matriz[i][j];
			}
		}
	}

	//Retorna resultado da soma
	return soma;

}
