#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

typedef struct registro REGISTRO;
int status;
int registro;
int contador;

struct registro{
    char nome[30];
    char extensao[3];
    char ra[7];
    char matri[8];
};

void cabecalho();
void remover();
void removert();
void inputData();
void enfileirar();

main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    
	do{
	    cabecalho();
	    printf("1 - Inserir\n");
	    printf("2 - Remover\n");
	    printf("3 - Enfileirar\n");
	    printf("4 - Sair\n");
	    printf("5 - Remover todos\n");
	    printf("\nEscolha uma opção: ");
	    scanf("%d",&opcao);

	    switch(opcao){
	        case 1:
	            inputData();
	        break;
	
	        case 2:
	            remover();
	        break;
	
	        case 3:
	            enfileirar();
	        break;
	        
	        case 4:
	            printf("Obrigado pela sua colaboração\n");
	        	getch();
	        break;
	        
	        case 5:
				removert();	
	        break;
	
	        default:
		        printf("Opção inválida!\n");
		        getch();
	        break;
	    }
    }while(opcao != 4);
}

void cabecalho(){
	system("cls");
	printf("---------------------------------------------\n");
	printf("\t\tRegistro de Atividade\n");
	printf("---------------------------------------------\n\n");
	}
	
void inputData(){
    FILE* arquivo;
    REGISTRO ctt;

   arquivo = fopen("registro.txt", "ab");
   	if(arquivo == NULL){
    	printf("Arquivo não encontrado ou arquivo inexistente.\n\n");
   	}
	else{
	    do{
	    	if (contador <=5){
	    	cabecalho();
			fflush(stdin);
			printf("Digite o nome: ");
			gets(ctt.nome);

			fflush(stdin);
			printf("Digite a matricula: ");
			gets(ctt.matri);
			
			printf("Digite o RA: ");
			scanf("%d",&ctt.ra);
			        
			fflush(stdin);
			printf("Digite a extensão do arquivo: ");
			gets(ctt.extensao);
			
			fwrite(&ctt, sizeof(REGISTRO), 1, arquivo);
			
			}else{
				printf("Você já registrou 5 alunos.")
			}
			 
			printf("Deseja continuar(s/n)?");
			
	    }while(getche() == 's');	
    		
		fclose(arquivo);
   		getch();
   	}

}

void enfileirar(){
    FILE* arquivo;
    REGISTRO ctt;

   arquivo = fopen("registro.txt", "rb");

   cabecalho();
   if(arquivo == NULL){
    	printf("Arquivo não encontrado ou arquivo inexistente.\n\n");
   }
   else{
    	while(fread(&ctt, sizeof(REGISTRO), 1,arquivo) == 1){
	        printf("\tNome: %s\n",ctt.nome);
	        printf("\tMatricula: %s\n",ctt.matri);
	        printf("\tRA: %s\n",ctt.ra);
	        printf("\tExtensão do arquivo: %s\n",ctt.extensao);
	        printf("----------------------------------------------\n\n");
		}
	}
   fclose(arquivo);
   getch();
}

void remover(){

    FILE* arq;
    FILE* temp;
    REGISTRO ctt;
    char nome[30];

	arq = fopen("registro.txt","rb");
	temp = fopen("tmp.txt","wb");

    if(arq==NULL&&temp==NULL)
        {
	        printf("Arquivo não encontrado ou arquivo inexistente.\n");
	        getch();
        }
    else
    {
    
	cabecalho();
    fflush(stdin);
    printf("Digite o nome a deletar: ");
    gets(nome);

    while(fread(&ctt,sizeof(REGISTRO),1,arq)==1)
    {
        if(strcmp(nome,ctt.nome)==0)
        {
            printf("\tNome: %s\n",ctt.nome);
        	printf("\tMatricula: %s\n",ctt.matri);
        	printf("\tRA: %s\n",ctt.ra);
        	printf("\tExtensão do arquivo: %s\n",ctt.extensao);
            printf("-------------------------------------------------\n");
        }
        else
        {
            fwrite(&ctt,sizeof(REGISTRO),1,temp);//gravando os dados no arquivo temp
        }
    }
        fclose(arq);
        fclose(temp);
        fflush(stdin);
        printf("Deseja deletar (s/n)? ");
  	if(getche()=='s')
    {
        
        if(remove("registro.txt")==0&&rename("tmp.txt","registro.txt")==0)
            {
                printf("\nOperacao realizada com sucesso!");
            }
        else
            {
                remove("tmp.txt");
            }
    }
    fclose(temp);
    fclose(arq);
    getch();
 }
 
 }
 
void removert(){
    remove("registro.txt");
}
	


