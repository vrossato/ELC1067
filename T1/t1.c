#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_alunos(int* matriculas_aluno, char nomes[][50], int* n){

	FILE *f = fopen("alunos.txt","r");

	if (f == NULL){
		printf("Erro ao abrir o arquivo alunos.txt");
            return;
	}

	int mat, con, linha = 0;
	char c, nome[50];

	while(feof(f) == 0 ){
		if(fscanf(f, "%d", &mat) <= 0)
            break;
		con = 0;
		c = fgetc(f);
		while(c != '\n' && feof(f) == 0){
			nome[con] = c;
			con++;
			c = fgetc(f);
		}
        nome[con] = '\0';
        matriculas_aluno[linha] = mat;
        strcpy(nomes[linha], nome);
        linha++;
	}
    *n = linha;
    fclose(f);
}

void ler_notas(float* medias){

    FILE *f = fopen("notas.txt", "r");

    if (f == NULL){
		printf("Erro ao abrir o arquivo notas.txt");
            return;
	}

    int con = 0, mat;
    float nota1, nota2;

    while(feof(f) == 0){
        if(fscanf(f, "%d" "%f" "%f\n", &mat, &nota1, &nota2) == 0)
            break;
        medias[con] = (nota1+nota2)/2;
        con++;
    }
    fclose(f);
}

void busca_aluno(char* nome, char nomes[][50], int n, float* medias){

    int con;
    for(con = 0; con < n; con++){
        if(strstr(nomes[con], nome)!= NULL){
            printf("%.2f %s\n", medias[con], nomes[con]);
        }
    }
}

int main(int argc, char** argv){

    int matriculas[50], n;
    char* nome;
    char nomes[50][50];
    float medias[50];

    nome = malloc(50* sizeof(char));

    if(argc > 1){
        strcpy(nome, argv[1]);
        printf("O Nome Solicitado em Comum eh: %s \n", nome);
    }

    ler_alunos(matriculas, nomes, &n);
    ler_notas(medias);
    busca_aluno(nome, nomes, n, medias);

    return 0;
}
