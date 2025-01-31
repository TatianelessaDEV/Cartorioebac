#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //bibliotecca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string

int registro() //função resposnsavel por cadastrar os usuarios no sistema 
{
    //inicio da criação de variaveis / string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variaveis / strig
    
    printf("Digite o CPF a ser cadastrado:  "); //coletando informação do usuarioo
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy (arquivo, cpf); //responsavel por criar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever 
    fprintf(file,cpf); // salvo o arquivo
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a"); //a atulaiza 
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:  ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("digite o sobrenome a ser cadastrado:  ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:  ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado:  ");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
       printf("Não foi possivel abrir o arquivo, não localizado!.\n");
   }
   
   while(fgets(conteudo, 200, file) != NULL)
{
    printf("\nEssas são as informações do usuaário:  ");
    printf("%s", conteudo);
    printf("\n\n");
}  

system("pause");

}


int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuario a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("o usuario não se encontra no sistema!. \n");
        system("pause");
        
    }
    
}



int main()
{
 int opcao=0; //Definindo as variaveis 
 int laco=1;
 
 for(laco=1;laco=1;)
 
 
 {
    
    
    system("cls");
 
 
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
    
    printf("### Cartório da EBAC###\n\n"); //inicio do menu
    printf("escolha a opção desejada do menu: \n\n");
    printf("\t1 - registrar nomes\n");
    printf("\t2 - consultar nomes\n");
    printf("\t3 - deletar nomes\n");
    printf("\t4 - sair do sistema\n\n");
    printf("Opção:");  //fim do menu
    
    scanf("%d" , &opcao); //armazenando a escolha do usuario
    
    system("cls"); //limpa
    
    
    switch(opcao)
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
        
        
        case 4:
        printf("obrigado por utilizar o sitema! \n");
        return 0; 
        break;
        
        
        default:
        printf("essa opção não esta disponivel\n");
        system("pause");
        break;
    }
    
    
    
    } //fim da seleção
    
 }