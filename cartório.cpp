#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char idade[40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuario
	scanf("%s", cpf); //% refere-se a sting
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das sting
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w");  //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo valore da variavel
	fclose(file); // fecha o arquivo 
	
	file = fopen(arquivo, "a"); // "a" abre o arquivo para adição
	fprintf(file, ","); // virgula entre as informções
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
		printf("Não foi possivel localizar o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuario: ");
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
		printf("usuário não se encontra no sistema!. \n");
		system("pause");
	}
}
	

 

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	    
	    printf("### Cartótio da EBAC ###\n\n"); // inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");	
	    printf("Opção: "); //Fim do menu
	    
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	    
	    system("cls"); //resposavel por limpoar a tela
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chama funções 
		    break;
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default:
		    printf("Essa opção não está disponivel!\n");
		    system("pause");
		    //fim da seleção
		}
	    
	    
    }  
}
