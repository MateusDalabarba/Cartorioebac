#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char idade[40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usuario
	scanf("%s", cpf); //% refere-se a sting
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das sting
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w");  //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo valore da variavel
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // "a" abre o arquivo para adi��o
	fprintf(file, ","); // virgula entre as inform��es
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel localizar o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //arquivo nulo
	{
		printf("usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
}
	

 

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�tio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
	
	
	    for(laco=1;laco=1;)
	    {   
	
	        system("cls");
	        
	        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	         
	        printf("### Cart�tio da EBAC ###\n\n"); // inicio do menu
	        printf("Escolha a op��o desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n\n");
		    printf("\t4 - Sair do sistema\n\n");	
	        printf("Op��o: "); //Fim do menu
	        
	        scanf("%d", &opcao); //armazenando a escolha do usu�rio
	        
	        system("cls"); //resposavel por limpoar a tela
	    
	        switch(opcao) //inicio da sele��o do menu
	        {
	    	    case 1:
	    	    registro(); //chama fun��es 
		        break;
		    
		        case 2:
		        consulta();
		        break;
		    
		        case 3:
		        deletar();
		        break;
		    
		        case 4:
		        printf("Obrigado por utilizar o sistema!\n");
		        return 0;
		        break;
		    
		        default:
		        printf("Essa op��o n�o est� disponivel!\n");
		        system("pause");
		        //fim da sele��o
		   }
	    
       }  
   }
   else
       printf("senha incorreta!");
       
}
