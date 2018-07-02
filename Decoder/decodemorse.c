#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 255


char texto[N];
/*Faz a leitura do texto em morse que possui dentro do arquivo "codificado"
armazenado no vetor texto
*/
void leitura(){
	FILE *codi;
	int i;

	codi = fopen("codificado.txt","r");
	if(codi==NULL){
		printf("Programa Abortado. Erro na abertura do arquivo .txt");
	}
	fgets(texto,N,codi);
	
	fclose(codi);

	printf("\nCodigo Escrito no Arquivo\n> ");
	printf("%s", texto);

	printf("\n");
}
/*
Nessa função ele vai utilizar o vetor "compara" para armazenar o texto codificado em morse do vetor "texto" até o espaço.
Após armazenar o morse ate o espaço no vetor "compara", ele ira verificar qual elemento do vetor "compara" é igual ao elemento,
do vetor "morse", quando forem iguais ele imprime no arquivo "Decodificado" o caracter referente a posição do morse.
*/
void decodifica(){
	FILE *decodi;
	char c;
	char esp[2];
	int i,j,k;
	char compara[6];
	char *morse[]={[0]= ".-",[1]= "-...",[2]= "-.-.",[3]= "-..",[4]= ".",[5]= "..-.",
				  [6]= "--.",[7]= "....",[8]= "..",[9]= ".---",[10]= "-.-",[11]= ".-..",
				  [12]= "--",[13]= "-.",[14]= "---",[15]= ".--.",[16]= "--.-",[17]= ".-.",
				  [18]= "...",[19]= "-",[20]= "..-",[21]= "...-",[22]= ".--",[23]= "-..-",
				  [24]= "-.--",[25]= "--..",[26]= ".----",[27]= "..---",[28]= "...--",[29]= "....-",
				  [30]= ".....",[31]= "-....",[32]= "--...",[33]= "---..",[34]= "----.",[35]= "-----",[36]="/"};

	char *alfab[]={[0]="A",[1]="B",[2]="C",[3]="D",[4]="E",[5]="F",[6]="G",[7]="H",
					[8]="I",[9]="J",[10]="K",[11]="L",[12]="M",[13]="N",[14]="O",[15]="P",
					[16]="Q",[17]="R",[18]="S",[19]="T",[20]="U",[21]="V",[22]="W",[23]="X",
					[24]="Y",[25]="Z",[26]="1",[27]="2",[28]="3",[29]="4",[30]="5",[31]="6",[32]="7",
					[33]="8",[34]="9",[35]="0",[36]=" "};

	decodi = fopen("decodificado.txt","w");
	if(decodi==NULL){
		printf("Erro ao gravar no Arquivo!");
	}
	printf("Codigo Morse Decodificado\n> ");
	i=0;
	while(i<strlen(texto)){//Preenche o veto "Compara" com o conteudo do vetor "Texto" ate o espaço
		j=0;
		k=0;
		while(j<6){
			if(texto[i]==' '){
				compara[j]='\0';
				break;
			}
			if(texto[i]=='/'){
				compara[j]='/';
			}
			else{
				compara[j]=texto[i];
			}
			i++;
			j++;
		}
		i++;
		for(k=0 ; k<37; k++){//compara o conteudo de "Compara" com o "Morse", e grava no arquivo o caracter correspondente do vetor "Alfab"
			if(strcmp(compara,morse[k])==0){
				printf("%s", alfab[k]);//Imprimi na tela os caracteres 
				fprintf(decodi, "%s", alfab[k]);

			}
		}

	}
	printf("\n");
	fclose(decodi);
	printf("Arquivo Gravado com Sucesso!\n");
}

void main(){

	leitura();
	decodifica();
	
}