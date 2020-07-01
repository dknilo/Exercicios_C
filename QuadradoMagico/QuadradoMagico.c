#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

//Declara��o de rotinas
int** AlocaMatriz(int n);
void CarregaMatriz(int** matriz, int n);
int ValidaDup(int** matriz, int n, int valor);
void ImprimeMatriz(int** matriz, int n);
int SomaLinha(int** matriz, int n);
int SomaColuna(int** matriz, int n);
int SomaDiagonalPrinc(int** matriz, int n);
int SomaDiagonalSec(int** matriz, int n);

int main() { //Principal

	setlocale(LC_ALL, "portuguese"); //Setar portugu�s para localidade para imprimir caracteres com acentua��o

	//Declara��o de vari�veis
	int** mat, dim, linha = 0, coluna = 0, diagP = 0, diagS = 0;
	char c;

	printf_s("\n\n\n QUADRADO M�GICO\n\n\n");

	do { // Abre loop para validar n�mero digitado

		//Solicita n�mero de dimens�o da matriz para montar din�micamente
		printf_s("Informe a dimens�o da matriz: \n");
		scanf_s("%d", &dim);

		//Limpa buffer do teclado
		while ((c = getchar()) != '\n' && c != EOF) {};

		if (dim == 0) { // N�o aceita n�mero zero para a dimens�o
			printf_s("Dimens�o da Matriz n�o pode ser zero.\n\n");
		}

	} while (dim == 0); // Mantem o loop enquanto usu�rio digitar zero

	// Aloca din�micamente a matriz passando como par�metro o valor digitado para dimens�o
	mat = AlocaMatriz(dim);

	// Chama rotina para carregar valores da matriz, passando como par�metro a matriz e sua dimens�o
	CarregaMatriz(mat, dim);
	printf_s("\n\nMatriz Digitada:\n");
	printf_s("===============================================\n");

	// Chama rotina para imprimir valores da matriz, passando como par�metro a matriz e sua dimens�o
	ImprimeMatriz(mat, dim);
	printf_s("===============================================\n");

	// Chama fun��o que soma os valores de cada linha da matriz, passando como par�metro a matriz e sua dimens�o
	linha = SomaLinha(mat, dim);

	if (linha != -1) { // Se retorno for negativo, n�o precisa executar demais fun��es

		// Chama fun��o que soma os valores de cada coluna da matriz, passando como par�metro a matriz e sua dimens�o
		coluna = SomaColuna(mat, dim);

		if (coluna != -1) {// Se retorno for negativo, n�o precisa executar demais fun��es
		// Chama fun��o que soma os valores da diagonal principal da matriz, passando como par�metro a matriz e sua dimens�o
			diagP = SomaDiagonalPrinc(mat, dim);
			// Chama fun��o que soma os valores da diagonal secund�ria da matriz, passando como par�metro a matriz e sua dimens�o
				diagS = SomaDiagonalSec(mat, dim);
		}
	}

	//Se o retorno das fun��es tiverem o mesmo valor, encontrou um Quadrado M�gico
	if ((linha == coluna) && (linha == diagP) && (linha == diagS)) {
		printf_s("Matriz � um Quadrado M�gico!!!\n\n");
	}
	else {
		printf_s("Matriz N�O � um quadrado m�gico.\n\n");
	}

	system("pause");
	return 0;

}

// Fun��o respons�vel por efetuar a aloca��o de forma din�mica da Matriz
// Recebe por par�metro valor digitado para a dimens�o que ser� criada a matriz
int** AlocaMatriz(int n) {

	//Declara��o da vari�vel que recever� por refer�ncia os valores da dimens�o da matriz
	int** matriz;

	//Aloca dimens�o das linhas da matriz
	matriz = (int**)calloc(n, sizeof(int*));

	for (int i = 0; i < n; i++) {// Abre loop com n�mero das dimens�es da Matriz
	//Aloca dimens�o das colunas para cada linha da matriz
		matriz[i] = (int*)calloc(n, sizeof(int));
	}

	return (matriz); //Retorna Matriz alocada
}

/*Procedimento para carregar os valores da matriz
Recebe como par�metros a Matriz por refer�ncia e sua dimens�o
*/
void CarregaMatriz(int** matriz, int n) {

	//Declara��o de variaveis
	int contrl = 0, contaZero = 0;
	char c;

	for (int i = 0; i < n; i++) { //Abre o loop de linhas
		for (int j = 0; j < n; j++) { //Abre o loop de colunas

			do { //Abre loop para valida��o dos valores digitados
				contrl = 0;

				//Solicita valores para carregar a matriz
				printf_s("Informe o valor para a posi��o %d,%d da matriz\n", i, j);
				scanf_s("%d", &matriz[i][j]);

				//Limpa buffer do teclado
				while ((c = getchar()) != '\n' && c != EOF) {};

				if (matriz[i][j] == 0) {
					//Se valor digitado for zero, incrementa contador
					contaZero++;
				}
				else {
					// Se n�o for zero, valida se valor digitado j� existe na matriz
					contrl = ValidaDup(matriz, n, matriz[i][j]);
				}

				if ((contrl == 1) && matriz[i][j] != 0) {
					//Quando retorno da fun��o for 1 e valor digitado for diferente de zero , significa que houve duplicidade
					printf_s("*** Valor j� digitado, Matriz n�o pode conter valores repetidos ***\n");
					contrl = 1;
				}
				else if (contaZero > 1) {
					//Quando o valor digitado for zero e o contador for maior que 1, significa que houve duplicidade
					printf_s("*** Valor j� digitado, Matriz n�o pode conter valores repetidos ***\n");
					contaZero = 1;
					contrl = 1;
				}
				else
				{ //Entre aqui quando n�o houver duplicidade
					contrl = 0;
				}

			} while (contrl == 1); //Mantem o loop enquanto vair�vel de controle for iguala 1
		}
	}
}

/*Fun��o para validar duplicidades na Matriz
Recebe como par�metros a Matriz por refer�ncia, sua dimens�o e valor digitado
*/
int ValidaDup(int** matriz, int n, int valor) {

	//Declara��o de variaveis
	int cont = 0;

	for (int i = 0; i < n; i++) { // Abre loop de linhas
		for (int j = 0; j < n; j++) { // Abre loop de colunas
			if (matriz[i][j] == valor) { //Quando localizar o valor do par�metro, incrementa o contador
				cont++;
			}
		}
	}

	if (cont > 1) {//Se o contador for maior que 1, valor est� duplicidado
		return 1; // Retorno 1 = tem duplicidade
	}
	else {
		return 0; // Retorno 0 = n�o tem duplicidade
	}
}

/*Procedimento para imprimir matriz digitada
Recebe como par�metros a Matriz por refer�ncia e sua dimens�o
*/
void ImprimeMatriz(int** matriz, int n) {

	for (int i = 0; i < n; i++) { //Abre loop de linhas
		for (int j = 0; j < n; j++) { // Abre loop de colunas
		//Imprime valor da posi��o da matriz
			printf_s("%d\t", matriz[i][j]);
		}
		printf_s("\n");
	}
}

/*Fun��o para somar valores de cada linha da matriz
Recebe como par�metros a Matriz por refer�ncia e sua dimens�o
*/
int SomaLinha(int** matriz, int n) {

	//Declara��o de variaveis
	int somaA = 0, somaB = 0;

	for (int i = 0; i < n; i++) {//Abre loop de linhas
		for (int j = 0; j < n; j++) {//Abre loop de colunas
			if (i == 0) {
				//Se loop estiver na primeira linha, soma na vari�vel somaA
				somaA = somaA + matriz[i][j];
			}
			else {
				//Se n�o estiver na primeira linha, soma na vari�vel somaB
				somaB = somaB + matriz[i][j];
			}
		}
		if (i != 0) { //S� faz a compara��o depois de passar da primeira linha
			if (somaA != somaB) {
				//Quando valores das somas das linhas for diferente, seta a vari�vel com valor negativo e para o loop
				somaA = -1;
				break;
			}
			//Zera vari�vel antes de ir para pr�xima linha
			somaB = 0;
		}
	}

	/*Retorna valor obtido com a soma dos valores das linhas ou
	valor negativo quando houver diferen�a entre as linhas*/
	return somaA;
}

/*Fun��o para somar valores de cada coluna da matriz
Recebe como par�metros a Matriz por refer�ncia e sua dimens�o
*/
int SomaColuna(int** matriz, int n) {

	//Declara��o de variaveis
	int somaA = 0, somaB = 0;

	for (int i = 0; i < n; i++) {//Abre loop de colunas
		for (int j = 0; j < n; j++) {//Abre loop de linhas
			if (i == 0) {
				//Se loop estiver na primeira coluna, soma na vari�vel somaA
				somaA = somaA + matriz[j][i];
			}
			else {
				//Se n�o estiver na primeira coluna, soma na vari�vel somaB
				somaB = somaB + matriz[j][i];
			}
		}
		if (i != 0) {//S� faz a compara��o depois de passar da primeira coluna
			if (somaA != somaB) {
				//Quando valores das somas das colunas for diferente, seta a vari�vel com valor negativo e para o loop
				somaA = -1;
				break;
			}
			//Zera vari�vel antes de ir para pr�xima coluna
			somaB = 0;
		}
	}

	/*Retorna valor obtido com a soma dos valores das colunas ou
	valor negativo quando houver diferen�a entre as colunas*/
	return somaA;
}

/*Fun��o para somar valores da diagonal principal da matriz
Recebe como par�metros a Matriz por refer�ncia e sua dimens�o
*/
int SomaDiagonalPrinc(int** matriz, int n) {

	//Declara��o de variaveis
	int soma = 0;

	for (int i = 0; i < n; i++) {//Abre loop de linhas
		for (int j = 0; j < n; j++) {//Abre loop de colunas
			if (i == j) {
				/*Quando posi��o da linha for igual posi�ao da coluna, significa que est� em uma posi��o
				da diagonal principal e soma o valor na vari�vel */
				soma = soma + matriz[i][j];
			}
		}
	}

	//Retorna resultado da soma
	return soma;
}

/*Fun��o para somar valores da diagonal secund�ria da matriz
Recebe como par�metros a Matriz por refer�ncia e sua dimens�o
*/
int SomaDiagonalSec(int** matriz, int n) {

	//Declara��o de variaveis
	int soma = 0;

	for (int i = 0; i < n; i++) {//Abre loop de linhas
		for (int j = 0; j < n; j++) {//Abre loop de colunas
			if (i == n - 1 - j) {
				/*Quando posi��o da linha for igual a express�o = quantidade de colunas - 1 - n�mero da coluna atual do
				loop
				significa que est� em uma posi��o da diagonal secund�ria e soma o valor na vari�vel */
				soma = soma + matriz[i][j];
			}
		}
	}

	//Retorna resultado da soma
	return soma;

}
