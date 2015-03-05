#include <stdio.h>

void main (void) {
	
	FILE* f;
	int matricula;
	char nome [100];

	printf ("informe a matricula");
	scanf ("%d", &matricula);
	
	printf ("nome");
	scanf("%s", nome);
	f = fopen ("saida.txt", "w");
	fprintf(f, "%d %s\n", matricula, nome);
	fclose(f);
}
