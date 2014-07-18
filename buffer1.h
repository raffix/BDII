//gcc (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3
//Buffer1.c : v1.0 (version 1.0)
//git version 1.7.9.5

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUMP 512 //512 paginas no buffer
#define SIZE 1024 //tamanho de 1024
#define ATRIBUTOS 30 //tamanho maximo de atributos

struct vt{
	int tam;
	char tipo;
	char nome[50];
}; // Estrutura armazena as caracteristicas de cada atributo
typedef struct vt estru;

struct BUFFER{
    int dirtybit;
    int pincount;
    int numbytes;
    int numRegs;
    char data[SIZE];
}; //Estrutura do buffer
typedef struct BUFFER buffer;

union c_int
{
	int  num;
	char cnum[sizeof(int)];
};//union para o tipo inteiro

union c_double
{
	double numd;
	char   cnumd[sizeof(double)];
};//union para o tipo double

union dados{

    char palavra[50];
    double valord;
    int valori;
    char c;

};

int tamanho;//tamanho de uma tupla
estru vr[ATRIBUTOS];//Armazena a estrutura de cada atributo (max 30 atributos)
int att; //numero de atributos
union dados dataTupla;

/**Funcao que define as strings da estrutura como vazias

* @param: tam (tamanho da string)

* @return: sem retorno

*/
void strVazia(int tam);

/**Funcao que seta o valor inicial do buffer como vazio

* @param: p (ponteiro do tipo buffer)

* @return: sem retorno

*/
void inicializaBuffer(buffer *p); // coloca valores default
void orgOnBuffer(int next,buffer *b,char *tuple); //Organiza as tuplas no buffer

/** Funcao que busca uma tupla no buffer e imprime ela na tela

* @param: b (buffer) , page (numero da pagina), tuple (numero que indica qual é a tupla que deseja ser
* mostrada

* @return: -1 caso ocorra algum erro ou 0 caso ocorra tudo certo

*/
int printBuffer(buffer *b, int page, int tuple); // imprime uma tupla
void cpyvar(char *tuple,char *vd,int init,int tam); ////copiar valores tipo double e int para a string
int cpytuple(buffer *b,char *tuple,FILE *p);  //copia do arquivo tupla por tupla
int bufferpool(buffer *b, char *arqMeta, char *arqDados); //lê o metadado e os dados e prepara para copia-los para o buffer
void concatString(char *string1, char *string2, int pos); //Junta duas strings
int cpytoBuffer(buffer *b,char *tuple); //Copia uma tupla para o buffer

/** Funcao que aloca um vetor de char de tamanho definido

* @param: fn (ponteiro do tipo char)

* @return: fn (retorna um vetor alocado do tipo char)

*/
char *aloca(char *fn); //Aloca um vetor

/** Funcao que procura no dicionario se uma determinada tabela existe

* @param: tablename (nome da tabela a ser procurada)

* @return: -2 (caso nao encontre o arquivo de dicionarios), -1 (caso nao encontre a tabela no dicionario e o
* id da tabela caso encontre

*/
int seekFiles(char *tableName);//Localiza qual o ID da tabela, para abrir os arquivos corretos.

//Funções para criação de tabelas

/** Função que cria os arquivos de metadados e dados caso estes nao existam para uma determinada tabela,
* onde recebe um nome de uma tabela, grava ela no dicionario e recebe um valor de identificacao. Esse valor
* de identficação é gravado nos nomes dos arquivos de meta e data do respectivo arquivo

* @author: Leonardo Belinski, Raffael Rossi

* @param: tableName - nome da tabela solicitada pelo usuário

* @return: id - caso ocorra tudo certo, sem nenhuma falha, retorna o id do cadastro no dicionário de dados
* para aquela tabela

*/
int insertTable(char *tableName);


/** Funcao que converte um caracter numérica em uma string de 6 dígitos

* @author: Raffael Rossi

* @param: value - (valor numérico a ser convertido), e uma string (string que recebe o vetor de cacteres
* convertidos

* @return: string do valor convertido

*/
void convert(int value, char * string);

/** Funcao que cria as strings cujo valor sera utilizado como nome dos arquivos de dados e metadados das
* tabelas, recebendo um valor menor que 999999 e transformando em uma string de 6 caracteres

* @author: Leonardo Belinski, Raffael Rossi

* @param: archive (string que receberá o nome final do arquivo), value (string que contem o numero da tabela no
* dicionario de dados) e type (valor que identifica qual o tipo de arquivo - meta(1) ou data(2))

* @return: string archive, com o nome completo do arquivo conforme seu tipo

*/
void cria_string(char * archive, char * value,int type); // 0 para data e qualquer outro valor para meta

/** Funcao que insere as informações de metadados de uma tabela no respectivo arquivo dela

* @author: Leonardo Belinski, Raffael Rossi

* @param: tableName (nome do arquivo de metadados), start (marcador de inicio) e end (marcador de fim),
* utilizados para se orientar no arquivo

* @return: retorno o id do arquivo no dicionario

*/
int insertMeta(char * tableName,int start,int end); //Insere os metadados no arquivo. start e end são as posições no global estru

/** Funcao que grava os dados de uma respectiva tabela em seu arquivo de dados

* @author: Leonardo Belinski, Raffael Rossi

* @param: dataTupla (vetor que contem a informacao), nomeTabela (nome da tabela que deseja se gravas as
* informacoes, inicio (marca o inicio das informacoes do vetor meta) e fim (marca o fim das informacoes do
* vetor meta)

* @return: sem retorno

*/
void escreve_dados(union dados *dataTupla, char *nomeTabela, int inicio, int fim);

/** Funcao para teste da escrita no arquivo de dados da tabela

* @author: Leonardo Belinski, Raffael Rossi

* @param: sem parametros

* @return: sem retorno

*/
void funcao_teste();