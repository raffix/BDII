#include"buffer1.h"

int main(){

	
	
	buffer *bufpool=NULL; //variavel do tipo buffer ( por default tera valor NULL)
	bufpool=(buffer*)malloc(sizeof(buffer)*NUMP); //Aloca bufferpool com o Tamanho da constante NUMP
	inicializaBuffer(bufpool);//os valores da estrutura sao inicializados 
	bufferpool(bufpool,"meta.dat","data.dat"); 
	if(printBuffer(bufpool,0,8)!=0)//pagina zero, tupla 3
		puts("ERRo");
	
	return 0;
}
