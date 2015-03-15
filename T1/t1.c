#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void le_alunos(int* matriculas_aluno, char nomes[][50], int *n){
	int mat;
	char c, nome[50];
	int i,linha = 0;
	FILE*f = fopen("alunos.txt","r");
	if(f == NULL){
	        printf("Não foi possível abrir o arquivo\n");
	}else{
	while(feof(f) == 0 ){
		if(fscanf(f,"%d",&mat) <= 0)
			break;
		i=0;
		c=fgetc(f);
		while(c != '\n'){
			nome[i] = c;
			i++;
			c=fgetc(f);
		}
		        nome[i]='\0';
		        matriculas_aluno[linha]= mat;
			strcpy(nomes[linha],nome);
			linha++;
	}
	        *n = linha;
	        fclose(f);
        }
}
