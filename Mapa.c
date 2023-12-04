#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//definindo o tamanho m�ximo dos arrays.
#define MAX_ATENDIMENTOS 100
#define MAX_NOME 50
#define MAX_CPF 15

// struct Atendimento.
typedef struct {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    int tipoAtendimento;
} Atendimento;

// fun��o que valida o cpf.
bool validarCPF(const char *cpf) {
    
    while (*cpf) {
        if (!isdigit((unsigned char)*cpf)) {
            return false;  
        }
        cpf++;
    }
    return true;  
}
// fun��o para validar o nome.
int validarNome(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;  
        }
    }
    return 1;  
}

// Fun��o que solicita o atendimento e guarda em um array de atendimentos.
void solicitarAtendimento(Atendimento atendimentos[], int *quantidadeAtendida) {
    //Verifica se o limite de atendimento foi excedido.
    if (*quantidadeAtendida >= MAX_ATENDIMENTOS) {
        printf("Limite m�ximo de atendimentos atingido.\n");
        return;


    }
    do{
    // obtendo dados do usuário (Nome ; CPF ; Tipo de atendimento).
    printf("Digite seu nome: ");
    scanf("%49s", atendimentos[*quantidadeAtendida].nome);
    // condicional que certifica que o nome do usu�rio possua apenas letras.
    if (!validarNome(atendimentos[*quantidadeAtendida].nome)) {
        printf("Nome inv�lido!\n");
    }
    } while (!validarNome(atendimentos[*quantidadeAtendida].nome));

    do {
        printf("Digite seu CPF: ");
        scanf("%14s", atendimentos[*quantidadeAtendida].cpf);
        // condicional que certifica que o usu�rio digite apenas n�meros para a string CPF.
        if (!validarCPF(atendimentos[*quantidadeAtendida].cpf)) {
            printf("CPF inv�lido. Digite apenas n�meros.\n");
        }
    } while (!validarCPF(atendimentos[*quantidadeAtendida].cpf));

    do {
        printf("1 - Abertura de conta.\n");
        printf("2 - Caixa.\n");
        printf("3 - Gerente Pessoa F�sica.\n");
        printf("4 - Gerente Pessoa Jur�dica.\n");
        printf("Digite o tipo de atendimento que precisa: ");
        scanf("%d", &atendimentos[*quantidadeAtendida].tipoAtendimento);
        fflush(stdin);
        //condicional que certifica que o usu�rio escolha apenas as op��es apresentadas.
        if (atendimentos[*quantidadeAtendida].tipoAtendimento < 1 || atendimentos[*quantidadeAtendida].tipoAtendimento > 4) {
            printf("Voc� digitou uma op��o inv�lida. Escolha uma op��o de 1 a 4.\n");
        }
    } while (atendimentos[*quantidadeAtendida].tipoAtendimento < 1 || atendimentos[*quantidadeAtendida].tipoAtendimento > 4);

    (*quantidadeAtendida)++;
}
//fun��o que lista todos os atendimentos feitos at� o momento.
void listarAtendimentosRegistrados(Atendimento atendimentos[], int quantidadeAtendida) {
    //verifica se possui algum atendimento at� o momento.    
    if (quantidadeAtendida == 0) {
        printf("N�o existem atendimentos registrados no momento.\n");
        return;
    }
    // percorrendo o array de atendimentos e listando os atendimentos de acordo com cada tipo de atendimento.    
    for (int i = 0; i < quantidadeAtendida; i++) {
        switch (atendimentos[i].tipoAtendimento) {
            case 1:
                printf("Nome: %s\n", atendimentos[i].nome);
                printf("CPF: %s\n", atendimentos[i].cpf);
                printf("Tipo Atendimento - %d - Abertura de conta.\n", atendimentos[i].tipoAtendimento);
                printf("===============================================\n\n");
                break;
            case 2:
                printf("Nome: %s\n", atendimentos[i].nome);
                printf("CPF: %s\n", atendimentos[i].cpf);
                printf("Tipo Atendimento - %d - Caixa.\n", atendimentos[i].tipoAtendimento);
                printf("===============================================\n\n");
                break;
            case 3:
                printf("Nome: %s\n", atendimentos[i].nome);
                printf("CPF: %s\n", atendimentos[i].cpf);
                printf("Tipo Atendimento: - %d - Gerente Pessoa F�sica.\n", atendimentos[i].tipoAtendimento);
                printf("===============================================\n\n");
                break;
            case 4:
                printf("Nome: %s\n", atendimentos[i].nome);
                printf("CPF: %s\n", atendimentos[i].cpf);
                printf("Tipo Atendimento - %d - Gerente Pessoa Jur�dica.\n", atendimentos[i].tipoAtendimento);
                printf("===============================================\n\n");
                break;
        }
    }
}
// Fun��o que lista atendimentos por setor.
void atendimentosPorSetor(Atendimento atendimentos[], int quantidadeAtendida) {
    // verifica se existe algum atendimento at� o momento.    
    if (quantidadeAtendida == 0) {
        printf("N�o existem atendimentos registrados no momento.\n");
        return;
    }

    int setor;
    //Apresenta as op��es dos setores para que o usu�rio escolha um para ser listado.
    do {
        printf("Setor 1 - Abertura de conta.\n");
        printf("Setor 2 - Caixa.\n");
        printf("Setor 3 - Gerente Pessoa F�sica.\n");
        printf("Setor 4 - Gerente Pessoa Jur�dica.\n");
        printf("Digite o setor que deseja listar os atendimentos: ");
        scanf("%d", &setor);
        fflush(stdin);
        //verifica se o usu�rio solicitou a listagem apenas com as op��es apresentadas.
        if (setor < 1 || setor > 4) {
            printf("Voc� digitou um setor inexistente.\n\n");
        }

    } while (setor < 1 || setor > 4);

    int i;
    int encontrados = 0;  
    //Percorre o array de atendimentos e lista os atendimentos de acordo com o setor especificado pelo usu�rio.
    for (i = 0; i < quantidadeAtendida; i++) {
        if (atendimentos[i].tipoAtendimento == setor) {
            switch (setor) {
                case 1:
                    printf("Nome: %s\n", atendimentos[i].nome);
                    printf("CPF: %s\n", atendimentos[i].cpf);
                    printf("Tipo Atendimento - %d - Abertura de conta.\n", atendimentos[i].tipoAtendimento);
                    printf("===============================================\n\n");
                    break;
                case 2:
                    printf("Nome: %s\n", atendimentos[i].nome);
                    printf("CPF: %s\n", atendimentos[i].cpf);
                    printf("Tipo Atendimento - %d - Caixa.\n", atendimentos[i].tipoAtendimento);
                    printf("===============================================\n\n");
                    break;
                case 3:
                    printf("Nome: %s\n", atendimentos[i].nome);
                    printf("CPF: %s\n", atendimentos[i].cpf);
                    printf("Tipo Atendimento: - %d - Gerente Pessoa F�sica.\n", atendimentos[i].tipoAtendimento);
                    printf("===============================================\n\n");
                    break;
                case 4:
                    printf("Nome: %s\n", atendimentos[i].nome);
                    printf("CPF: %s\n", atendimentos[i].cpf);
                    printf("Tipo Atendimento - %d - Gerente Pessoa Jur�dica.\n", atendimentos[i].tipoAtendimento);
                    printf("===============================================\n\n");
                    break;
            }
            encontrados++;
        }
    }
    //Avisa ao usu�rio caso o setor escolhido n�oo possuir nenhuma solicita��o de atendimento.
    if (encontrados == 0) {
        printf("Nenhum atendimento encontrado para o setor especificado.\n");
    }
}
// Fun��o principal.
int main(void) {

    setlocale(LC_ALL, "Portuguese");

    //Vari�vel que obt�m a op��o de escolha do menu.
    int opcaoUsuario;
    //par�metros para utilizar as fun��es.
    Atendimento atendimentos[MAX_ATENDIMENTOS];
    int atendidos = 0;
    
    bool sair = false;

    do {
        // Apresenta o menu para que usu�rio escolha uma intera��o.
            printf("BEM VINDO AO SISTEMA DE ATENDIMENTO!\n");
            printf("1 - Solicitar atendimento.\n");
            printf("2 - Listar atendimentos registrados.\n");
            printf("3 - Listar atendimento por setor.\n");
            printf("4 - Sair.\n");
            printf("Digite uma op��o do menu: ");
            scanf("%d", &opcaoUsuario);
            fflush(stdin);
           
        //chamada das fun��es de acordo com a op��o digitada pelo usuario.
        switch (opcaoUsuario) {
            case 1:
                solicitarAtendimento(atendimentos, &atendidos);
                break;
            case 2:
                listarAtendimentosRegistrados(atendimentos, atendidos);
                break;
            case 3:
                atendimentosPorSetor(atendimentos, atendidos);
                break;
            case 4:
                printf("Saindo do sistema...\n");
                sair = true;
                break;
            
            default: 
                    printf("Voc� digitou uma op��o inv�lida.");
                    break;
        }

    } while (!sair);

    return 0;
}

