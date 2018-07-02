#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 255
#define X 37

char texto[N];
/*Faz a leitura do texto que possui dentro do arquivo "decodificado"
armazenado no vetor texto
*/
void leitura(){ 
	FILE *decodi;
	int i;

	decodi = fopen("decodificado.txt","r");
	if(decodi==NULL){
		printf("Programa Abortado. Erro na abertura do arquivo .txt");
	}
	fgets(texto,N,decodi);

	fclose(decodi);

	printf("\nTexto Escrito no Arquivo\n> ");
	printf("%s", texto);
	
	printf("\n");
}
/*Utilizando um vetor onde cada posição é um simbolo em Morse, essa função recebe o char em alguma posição, 
compara com a lista de char no Switch/Case e escreve dentro do arquivo "Codificado" o morse referente a posição
do vetor de "Morse"
*/
void codifica(){
	FILE *codi;
	int i,c;
	char *cod[X]={[0]= ".- ",[1]= "-... ",[2]= "-.-. ",[3]= "-.. ",[4]= ". ",[5]= "..-. ",
				  [6]= "--. ",[7]= ".... ",[8]= ".. ",[9]= ".--- ",[10]= "-.- ",[11]= ".-.. ",
				  [12]= "-- ",[13]= "-. ",[14]= "--- ",[15]= ".--. ",[16]= "--.- ",[17]= ".-. ",
				  [18]= "... ",[19]= "- ",[20]= "..- ",[21]= "...- ",[22]= ".-- ",[23]= "-..- ",
				  [24]= "-.-- ",[25]= "--..",[26]= ".---- ",[27]= "..--- ",[28]= "...-- ",[29]= "....- ",
				  [30]= "..... ",[31]= "-.... ",[32]= "--... ",[33]= "---.. ",[34]= "----. ",[35]= "----- ",[36]="/ "};

	codi = fopen("codificado.txt","w");
	if(codi==NULL){
		printf("Erro ao gravar o Cod. Morse!");
	}

	for(i=0 ; i<strlen(texto) ; i++){//Faz a Comparação do char no Arquivo com o Switch/Case ate o fim do texto (strlen)
		switch(texto[i]){
			case 'A': 
				fprintf(codi, "%s", cod[0]);
				break;
			case 'B': 
				fprintf(codi, "%s", cod[1]);
				break;
			case 'C': 
				fprintf(codi, "%s", cod[2]);
				break;
			case 'D': 
				fprintf(codi, "%s", cod[3]);
				break;
			case 'E': 
				fprintf(codi, "%s", cod[4]);
				break;
			case 'F': 
				fprintf(codi, "%s", cod[5]);
				break;
			case 'G': 
				fprintf(codi, "%s", cod[6]);
				break;
			case 'H': 
				fprintf(codi, "%s", cod[7]);
				break;
			case 'I': 
				fprintf(codi, "%s", cod[8]);
				break;
			case 'J': 
				fprintf(codi, "%s", cod[9]);
				break;
			case 'K': 
				fprintf(codi, "%s", cod[10]);
				break;
			case 'L': 
				fprintf(codi, "%s", cod[11]);
				break;
			case 'M': 
				fprintf(codi, "%s", cod[12]);
				break;
			case 'N': 
				fprintf(codi, "%s", cod[13]);
				break;
			case 'O': 
				fprintf(codi, "%s", cod[14]);
				break;
			case 'P': 
				fprintf(codi, "%s", cod[15]);
				break;
			case 'Q': 
				fprintf(codi, "%s", cod[16]);
				break;
			case 'R': 
				fprintf(codi, "%s", cod[17]);
				break;
			case 'S': 
				fprintf(codi, "%s", cod[18]);
				break;
			case 'T': 
				fprintf(codi, "%s", cod[19]);
				break;
			case 'U': 
				fprintf(codi, "%s", cod[20]);
				break;
			case 'V': 
				fprintf(codi, "%s", cod[21]);
				break;
			case 'W': 
				fprintf(codi, "%s", cod[22]);
				break;
			case 'X': 
				fprintf(codi, "%s", cod[23]);
				break;
			case 'Y': 
				fprintf(codi, "%s", cod[24]);
				break;
			case 'Z': 
				fprintf(codi, "%s", cod[25]);
				break;
			case '1':
				fprintf(codi, "%s", cod[26]);
				break;
			case '2':
				fprintf(codi, "%s", cod[27]);
				break;
			case '3':
				fprintf(codi, "%s", cod[28]);
				break;
			case '4':
				fprintf(codi, "%s", cod[29]);
				break;
			case '5':
				fprintf(codi, "%s", cod[30]);
				break;
			case '6':
				fprintf(codi, "%s", cod[31]);
				break;
			case '7':
				fprintf(codi, "%s", cod[32]);
				break;
			case '8':
				fprintf(codi, "%s", cod[33]);
				break;
			case '9':
				fprintf(codi, "%s", cod[34]);
				break;
			case '0':
				fprintf(codi, "%s", cod[35]);
				break;
			case ' ':
				fprintf(codi, "%s", cod[36]);
				break;
		}
	}

	fclose(codi);

	codi=fopen("codificado.txt","r");
	printf("Texto Codificado em Morse\n> ");
	do{//Pega o Caracter armazenado no arquivo "Codificado" e imprimi na tela
		c=getc(codi);
		if(c==EOF){
			break;
		}
		printf("%c" , c);
	}
	while(c!=EOF);

	fclose(codi);

	printf("\n\nArquivo Gravado Com Sucesso!\n");

}

void main(){
	leitura();
	codifica();
}