#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
	int id;
	char nome[50];
	float nota;
}Aluno;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	FILE *arquivo = fopen("alunos.bin","wb");
	if(arquivo == NULL){
		printf("Error ao abrir o arquivo!\n");
		return 1;
	}
	Aluno aluno1 = {1,"João", 8.5};
	fwrite(&aluno1,sizeof(Aluno),1,arquivo);
	fclose(arquivo);
	
	arquivo = fopen("alunos.bin","rb");
	if(arquivo == NULL){
		printf("Error ao abrir o arquivo!\n");
		return 1;
	}
	
	fread(&aluno1,sizeof(Aluno),1,arquivo);
	printf("Nome: %s\nNota: %.1f\nID: %d",aluno1.nome,aluno1.nota,aluno1.id);
	fclose(arquivo);
	
	return 0;
}
