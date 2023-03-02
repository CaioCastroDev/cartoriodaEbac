#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de mem�ria	
#include <locale.h>	//biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastror os usuarios no sistema
{
	//inicio da cria��o de vari�vies/strings
	char arquivo[40];
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strings	
		
	setlocale (LC_ALL, "Portuguese"); // Definindo a linguagem
		
	printf("Digite o CPF a ser cadastrado: ");		
	scanf("%s", CPF); // %s refere-se a strings
		
	strcpy(arquivo,CPF); //Responsavel por copiar os valores das strings
		
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo criado e o "W" significa Escrever
	fprintf(file,"CPF: %s", CPF); //salva o valor da variavel
	fclose(file); //fecha o arquivo
		
	file = fopen (arquivo, "a"); //abre o arquivo criado e o "A" significa Atualizar
	fprintf(file,"\n"); //salva o valor na vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu nome: ");
	scanf("%s", nome);
		
	file = fopen(arquivo, "a"); //abre o arquivo criado e o "A" significa Atualizar
	fprintf(file,"Nome: %s", nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
		
	file = fopen (arquivo, "a"); //abre o arquivo criado e o "A" significa Atualizar
	fprintf(file,"\n"); //salva o valor da variavel
	fclose(file); //fecha o arquivo
		
	printf("Digite seu sobrenome: "); 
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo criado e o "A" significa Atualizar
	fprintf(file,"Sobrenome: %s", sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abre o arquivo criado e o "A" significa Atualizar
	fprintf(file,"\n"); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //abre o arquivo criado e o "A" significa Atualizar
	fprintf(file,"Cargo: %s", cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
		
	system("pause"); // trava na tela solicitada
					
}

int	consulta() //Fun��o respons�vel por consultar o CPF no banco de dados
{
	setlocale (LC_ALL, "Portuguese"); // Definindo a linguagem
	
	//inicio da cria��o das strings
	char CPF[40];
	char conteudo[200];	
	//final da cria��o da strings
			
	printf("Digite o CPF a ser consultado:");
	scanf("%s", CPF);
	
	FILE *file; // chama a fun��o arquivo 
	file = fopen (CPF, "r"); // abre o arquivo e o "R" significa Ler
	
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel abrir o arquivo, CPF n�o localizado\n ");
	}
	
	while	(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n");	
		printf("%s", conteudo);
		printf("\n\n");
	}		
		
	fclose(file);
		
	system("pause");
}

int deletar() //Fun��o respos�vel por deletar nomes do banco de dados
{
	char cpf[40];
		
	printf("Qual o CPF do usuario a ser deletado? \nCPF:");
	scanf("%s",cpf);

	remove(cpf);	

	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Esse CPF n�o foi localizado, tente novamente.\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //Definindo variaveis
	
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		system("cls");
		
		setlocale (LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
 		printf("Op��o: "); //Fim do menu
 	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar as telas 

		switch	(opcao) //chamada de fun��es
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		}
	}
}

