#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

//definindo o tamanho máximo dos arrays.
#define MAX_ATENDIMENTOS 100
#define MAX_NOME 50
#define MAX_CPF 15

// struct Atendimento.
typedef struct {
    char nome[MAX_NOME];
    char cpf[MAX_CPF];
    int tipoAtendimento;
} Atendimento;

// função que valida o cpf.
bool validarCPF(const char *cpf) {
    
    while (*cpf) {
        if (!isdigit((unsigned char)*cpf)) {
            return false;  
        }
        cpf++;
    }
    return true;  
}
// função para validar o nome.
int validarNome(const char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i])) {
            return 0;  
        }
    }
    return 1;  
}

// Função que solicita o atendimento e guarda em um array de atendimentos.
void solicitarAtendimento(Atendimento atendimentos[], int *quantidadeAtendida) {
    //Verifica se o limite de atendimento foi excedido.
    if (*quantidadeAtendida >= MAX_ATENDIMENTOS) {
        printf("Limite máximo de atendimentos atingido.\n");
        return;


    }
    do{
    // obtendo dados do usuÃ¡rio (Nome ; CPF ; Tipo de atendimento).
    printf("Digite seu nome: ");
    scanf("%49s", atendimentos[*quantidadeAtendida].nome);
    // condicional que certifica que o nome do usuário possua apenas letras.
    if (!validarNome(atendimentos[*quantidadeAtendida].nome)) {
        printf("Nome inválido!\n");
    }
    } while (!validarNome(atendimentos[*quantidadeAtendida].nome));

    do {
        printf("Digite seu CPF: ");
        scanf("%14s", atendimentos[*quantidadeAtendida].cpf);
        // condicional que certifica que o usuário digite apenas números para a string CPF.
        if (!validarCPF(atendimentos[*quantidadeAtendida].cpf)) {
            printf("CPF inválido. Digite apenas números.\n");
        }
    } while (!validarCPF(atendimentos[*quantidadeAtendida].cpf));

    do {
        printf("1 - Abertura de conta.\n");
        printf("2 - Caixa.\n");
        printf("3 - Gerente Pessoa Física.\n");
        printf("4 - Gerente Pessoa Jurídica.\n");
        printf("Digite o tipo de atendimento que precisa: ");
        scanf("%d", &atendimentos[*quantidadeAtendida].tipoAtendimento);
        fflush(stdin);
        //condicional que certifica que o usuário escolha apenas as opções apresentadas.
        if (atendimentos[*quantidadeAtendida].tipoAtendimento < 1 || atendimentos[*quantidadeAtendida].tipoAtendimento > 4) {
            printf("Você digitou uma opção inválida. Escolha uma opção de 1 a 4.\n");
        }
    } while (atendimentos[*quantidadeAtendida].tipoAtendimento < 1 || atendimentos[*quantidadeAtendida].tipoAtendimento > 4);

    (*quantidadeAtendida)++;
}
//função que lista todos os atendimentos feitos até o momento.
void listarAtendimentosRegistrados(Atendimento atendimentos[], int quantidadeAtendida) {
    //verifica se possui algum atendimento até o momento.    
    if (quantidadeAtendida == 0) {
        printf("Não existem atendimentos registrados no momento.\n");
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
                printf("Tipo Atendimento: - %d - Gerente Pessoa Física.\n", atendimentos[i].tipoAtendimento);
                printf("===============================================\n\n");
                break;
            case 4:
                printf("Nome: %s\n", atendimentos[i].nome);
                printf("CPF: %s\n", atendimentos[i].cpf);
                printf("Tipo Atendimento - %d - Gerente Pessoa Jurídica.\n", atendimentos[i].tipoAtendimento);
                printf("===============================================\n\n");
                break;
        }
    }
}
// Função que lista atendimentos por setor.
void atendimentosPorSetor(Atendimento atendimentos[], int quantidadeAtendida) {
    // verifica se existe algum atendimento até o momento.    
    if (quantidadeAtendida == 0) {
        printf("Não existem atendimentos registrados no momento.\n");
        return;
    }

    int setor;
    //Apresenta as opções dos setores para que o usuário escolha um para ser listado.
    do {
        printf("Setor 1 - Abertura de conta.\n");
        printf("Setor 2 - Caixa.\n");
        printf("Setor 3 - Gerente Pessoa Física.\n");
        printf("Setor 4 - Gerente Pessoa Jurídica.\n");
        printf("Digite o setor que deseja listar os atendimentos: ");
        scanf("%d", &setor);
        fflush(stdin);
        //verifica se o usuário solicitou a listagem apenas com as opções apresentadas.
        if (setor < 1 || setor > 4) {
            printf("Você digitou um setor inexistente.\n\n");
        }

    } while (setor < 1 || setor > 4);

    int i;
    int encontrados = 0;  
    //Percorre o array de atendimentos e lista os atendimentos de acordo com o setor especificado pelo usuário.
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
                    printf("Tipo Atendimento: - %d - Gerente Pessoa Física.\n", atendimentos[i].tipoAtendimento);
                    printf("===============================================\n\n");
                    break;
                case 4:
                    printf("Nome: %s\n", atendimentos[i].nome);
                    printf("CPF: %s\n", atendimentos[i].cpf);
                    printf("Tipo Atendimento - %d - Gerente Pessoa Jurídica.\n", atendimentos[i].tipoAtendimento);
                    printf("===============================================\n\n");
                    break;
            }
            encontrados++;
        }
    }
    //Avisa ao usuário caso o setor escolhido nãoo possuir nenhuma solicitação de atendimento.
    if (encontrados == 0) {
        printf("Nenhum atendimento encontrado para o setor especificado.\n");
    }
}
// Função principal.
int main(void) {

    setlocale(LC_ALL, "Portuguese");

    //Variável que obtém a opção de escolha do menu.
    int opcaoUsuario;
    //parâmetros para utilizar as funções.
    Atendimento atendimentos[MAX_ATENDIMENTOS];
    int atendidos = 0;
    
    bool sair = false;

    do {
        // Apresenta o menu para que usuário escolha uma interação.
            printf("BEM VINDO AO SISTEMA DE ATENDIMENTO!\n");
            printf("1 - Solicitar atendimento.\n");
            printf("2 - Listar atendimentos registrados.\n");
            printf("3 - Listar atendimento por setor.\n");
            printf("4 - Sair.\n");
            printf("Digite uma opção do menu: ");
            scanf("%d", &opcaoUsuario);
            fflush(stdin);
           
        //chamada das funções de acordo com a opção digitada pelo usuario.
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
                    printf("Você digitou uma opção inválida.");
                    break;
        }

    } while (!sair);

    return 0;
}

