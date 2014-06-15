
Bufferpool :

 	Número de páginas definidos : 512 , tamanho 1024;
	

Estruturas:

    A struct vt representa um dado composto por : Nome,tipo e tamanho.
    A struct buffer representa uma página do buffer.Contém : dirtybit, pincount, numbytes,numregs e data.
	numbytes : número de bytes na página.
	numregs : número de registros na página.
	 data : Os dados em si.
 	dirtybit,pincount : controle de processo.
 
    As unios c_int e c_double representam um dado em formato int e double respectivamente.


Funções:


void strVazia(int tam) : Recebe um inteiro como parâmetro, sendo o tamanho da estrutura. Inicialização do campo nome.

void inicializaBuffer(buffer *p) : buffer *p (ponteiro do tipo buffer). Inicialização do Buffer.

void orgOnBuffer(int next,buffer *b,char *tuple) : int next ( inteiro, define a partir de qual posição no vetor
será alterado), buffer *b (ponteiro do bufferpool) e char *tuple ( ponteiro para a string da tupla ). A função 
organiza no bufferpool os dados da string tuple.

void cpyvar(char *tuple,char *vd,int init,int tam) : char *vd (string que representa o tamanho do dado a ser copiado). O
valor que está em *vd será copiado para tuple, de acordo com o seu tamanho. Ex: um inteiro, será copiado 4bytes.

void concatString(char *string1, char *string2, int pos) : Recebe como parâmetro duas string e um inteiro pos(representa 
a posição inicial do vetor).Função semelhante à strcat(), ela concatena as strings a partir de uma posição pos, passada por
parâmetro.


char *aloca(char *fn) : recebe uma string como parâmetro. A função aloca espaço, e retorna o endereço
para o chamador.

int cpytuple(buffer *b,char *tuple,FILE *p) : recebe buffer *b (bufferpool), uma tupla e um arquivo. A função lê o arquivo
onde estão as tuplas. Os dados lidos são colocados na string tuple. A função retorna zero, caso não houver nenhum erro.

int printBuffer(buffer *b, int page, int tuple) : int page ( número da pagina ), tuple ( número da tupla ). Imprime na tela
uma tupla, de acordo com os parâmetros page e tuple. A função retorna zero, caso não houver nenhum erro.

int bufferpool(buffer *b, char *arqMeta,char *arqDados) : recebe duas strings como parâmetro, char *arqMeta representa
um arquivo de metadados e char *arqDados representa arquivo de dados. A função lê o arquivo de metadados, e depois, lê o
arquivo de dados. Retorna zero, caso não houver erro.

int cpytoBuffer(buffer *b,char *tuple) : A função procura no bufferpool uma página livre, e inicia o processo de copia. Não
é tratado o caso de : Buffer cheio. Retorna zero, caso não houver erro.

Para o funcionamento do programa as funções void inicializaBuffer(buffer *p) e int bufferpool(buffer *b, char *arqMeta,char *arqDados),
devem ser chamadas na main.





Novo estruturamento dos arquivos de dicionario de dados:

#fs_dictionary.dat
--------------------------------
NUMBEROFTABLES (INT) 4 //No início do arquivo
TABLENAME (STRING) 50 BYTES | TABLEID (INT) 4 BYTES //No resto do arquivo deverá ter uma linha nesse formato para cada tabela do banco de dados

#fs_metafile{CONSTNUMBER}.dat
CONTINUA MESMA ESTRUTURA DO META.DAT

#fs_datafile{CONSTNUMBER}.dat
CONTINUA MESMA ESTRUTURA DO DATA.DAT

OBS: {CONSTNUMBER} se refere ao número que cada tabela tem perante o dicionário de dados.

Testes:

Para testar o programa, utilize o comando ./main <nome da tabela>
Estão disponíveis duas tabelas para teste.
teste1
teste2
OBS: As duas tabelas são semelhantes, mas não identicas.
