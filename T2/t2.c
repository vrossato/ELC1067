#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_alunos(int* matriculas_aluno, char** nomes, int* n){

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
        nomes[linha] = (char*) malloc((strlen(nome)+1) * sizeof(char));
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

void busca_aluno(char* nome, char** nomes, int n, float* medias){

    int con;
    for(con = 0; con < n; con++){
        if(strstr(nomes[con], nome)!= NULL){
            printf("%.2f %s\n", medias[con], nomes[con]);
        }
    }
}

int main(int argc, char** argv){

    int* matriculas, *n;
    char* nome;
    char** nomes;
    float* medias;

    nome = (char*) malloc(50* sizeof(char));
    if(nome == NULL){
        printf("\nErro na alocacao de memoria do nome.\n");
        exit(1);
    }

    medias = (float*) malloc(50* sizeof(float));
    if(medias == NULL){
        printf("\nErro na alocacao de memoria de medias.\n");
        exit(1);
    }

    matriculas = (int*)malloc(50* sizeof(int));
    if(matriculas == NULL ){
        printf("\nErro na alocacao de memoria de matriculas.\n");
        exit(1);
    }
    nomes = (char**) malloc(50* sizeof(char*));
    if(nomes == NULL){
        printf("\nErro na alocacao de memoria de nomes.\n");
        exit(1);
    }

    if(argc > 1){
        nome = argv[1];
        printf("O Nome Solicitado em Comum eh: %s \n", nome);
    }

    ler_alunos(matriculas, nomes, &n);
    ler_notas(medias);
    busca_aluno(nome, nomes, n, medias);

    free(nome);
    free(matriculas);
    free(medias);
    free(nomes);

    return 0;
}
