#include"buffer1.h"

int main(int argc, char *argv[]){
	if(argc < 2)
	{
		printf("Informe como parametro o nome da tabela desejada\n");
		return 1;
	}
	char nomeTabela[50];
	sprintf(nomeTabela,"%s",argv[1]);
	buffer *bufpool=NULL; //variavel do tipo buffer ( por default tera valor NULL)
	bufpool=(buffer*)malloc(sizeof(buffer)*NUMP); //Aloca bufferpool com o Tamanho da constante NUMP
	inicializaBuffer(bufpool);//os valores da estrutura sao inicializados 
	int fileIndex = seekFiles(nomeTabela);//Procura indice para abrir os arquivos da tabela
	printf("\n ID main %d \n",fileIndex);
	if(fileIndex==-1){
		fileIndex=insertTable(nomeTabela);
	}
	if(fileIndex < 0)
	{
		if(fileIndex == -1)
			printf("Tabela '%s' nao encontrada no dicionario de dados\n",nomeTabela);
		else if(fileIndex == -2)
			printf("O arquivo de dicionario de dados 'fs_dictionary.dat' nao foi encontrado\n");
	}
	else
	{
		char strMeta[50],strData[50];
		sprintf(strMeta, "fs_metafile%d.dat",fileIndex);
		sprintf(strData, "fs_datafile%d.dat",fileIndex);
		bufferpool(bufpool,strMeta,strData);//Chama bufferpool com os arquivos devidos de metadados e dados
		//O código abaixo imprime as 8 primeiras páginas do buffer apenas para teste
		int i;
		for(i = 0; i < 8; i++)
			printBuffer(bufpool,0,i);
	}	
	return 0;
}
