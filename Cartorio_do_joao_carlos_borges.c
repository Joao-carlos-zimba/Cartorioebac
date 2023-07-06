#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de alica��o de espa�o em mem�ria
#include <locale.h> //biblioteca de alica��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese");
	//inicio cria��o de var�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de var�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a salvar string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,"\nCPF: ");
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o aqrquivo e atualizando ele com "\nNome: " 
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	getchar(); //limpa o caractere de nova linha pendente no buffer
	fgets(nome, sizeof(nome), stdin); //l� uma linha interia, incluindo espa�os em branco
	nome[strcspn(nome,"\n")]='\0'; //remove a nova linha do final do nome
		
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(sobrenome, sizeof(sobrenome),stdin); //l� uma linha interia, incluindo espa�os em branco
	sobrenome[strcspn(sobrenome,"\n")]='\0'; //remove a nova linha do final do sobrenome
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	
	printf("\nParab�ns, CPF cadastrado com sucesso!\n\n");
	
	system("pause");
}

int consulta() //fun��o consultar nomes
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nCPF n�o localizado no nosso banco de dados.\n");
	}
	
	printf("\nEssas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n");
	}
	
	system("pause");
	
}	

int delete() //fun��o deletar arquivos
{
	char cpf[40];
	
	printf("Qual CPF voc� deseja deletar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //abrindo arquivo
	
	if(file == NULL)
	{
		fclose(file);
		printf("Este CPF n�o se encontra no nosso banco de dados! \n");
		system("pause");
	}
	
	else if(file != NULL)
	{
		fclose(file);
		printf("\nCPF removido com sucesso do sistema. \n");
		system("pause");
		remove (cpf);
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n"); 
		printf("Op��o: ");// Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
	
		switch(opcao) //Incio da sele��o do menu
		{
			case 1:
			registro(); //chamadad de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			delete();		
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel! Escolha dentro das op��es sugeridas.\n");
			system("pause");
			break;		
		}	//fim da sele��o
	}
}
