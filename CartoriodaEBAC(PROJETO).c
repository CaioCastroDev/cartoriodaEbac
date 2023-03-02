#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória	
#include <locale.h>	//biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastror os usuarios no sistema
{
	//inicio da criação de variávies/strings
	char arquivo[40];
	char CPF[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strings	
		
	setlocale (LC_ALL, "Portuguese"); // Definindo a linguagem
		
	printf("Digite o CPF a ser cadastrado: ");		
	scanf("%s", CPF); // %s refere-se a strings
		
	strcpy(arquivo,CPF); //Responsavel por copiar os valores das strings
		
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo criado e o "W" significa Escrever
	fprintf(file,"CPF: %s", CPF); //salva o valor da variavel
	fclose(file); //fecha o arquivo
		
	file = fopen (arquivo, "a"); //abre o arquivo criado e o "A" significa Atualizar
	fprintf(file,"\n"); //salva o valor na variável
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

int	consulta() //Função responsável por consultar o CPF no banco de dados
{
	setlocale (LC_ALL, "Portuguese"); // Definindo a linguagem
	
	//inicio da criação das strings
	char CPF[40];
	char conteudo[200];	
	//final da criação da strings
			
	printf("Digite o CPF a ser consultado:");
	scanf("%s", CPF);
	
	FILE *file; // chama a função arquivo 
	file = fopen (CPF, "r"); // abre o arquivo e o "R" significa Ler
	
	
	if(file == NULL)
	{
		printf("\nNão foi possível abrir o arquivo, CPF não localizado\n ");
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

int deletar() //Função resposável por deletar nomes do banco de dados
{
	char cpf[40];
		
	printf("Qual o CPF do usuario a ser deletado? \nCPF:");
	scanf("%s",cpf);

	remove(cpf);	

	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Esse CPF não foi localizado, tente novamente.\n");
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
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
 		printf("Opção: "); //Fim do menu
 	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar as telas 

		switch	(opcao) //chamada de funções
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
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}
	}
}

