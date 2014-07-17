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

int tamanho;//tamanho de uma tupla
estru vr[ATRIBUTOS];//Armazena a estrutura de cada atributo (max 30 atributos)
int att; //numero de atributos

void strVazia(int tam);  //define as strings da estrutura como vazia
void inicializaBuffer(buffer *p); // coloca valores default
void orgOnBuffer(int next,buffer *b,char *tuple); //Organiza as tuplas no buffer
int printBuffer(buffer *b, int page, int tuple); // imprime uma tupla
void cpyvar(char *tuple,char *vd,int init,int tam); ////copiar valores tipo double e int para a string
int cpytuple(buffer *b,char *tuple,FILE *p);  //copia do arquivo tupla por tupla
int bufferpool(buffer *b, char *arqMeta, char *arqDados); //lê o metadado e os dados e prepara para copia-los para o buffer
void concatString(char *string1, char *string2, int pos); //Junta duas strings 
int cpytoBuffer(buffer *b,char *tuple); //Copia uma tupla para o buffer
char *aloca(char *fn); //Aloca um vetor
int seekFiles(char *tableName);//Localiza qual o ID da tabela, para abrir os arquivos corretos.

//Funções para criação de tabelas

int insertTable(char *tableName); //Cria arquivos de dados e metadados 
void convert(int value, char * string); //Converte inteiro menor que 999999 para uma string de tamanho 6