#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "auxiliares.h"
#include "data.h"
#include "cliente.h"
#include "lista_de_clientes.h"
#include "fatura.h"
#include "lista_de_faturas.h"

int menu_principal()
{
    system("cls");
    caracteres(66, '='); printf("\n");
    printf("                        SISTEMA DE COBRAN%cAS", 128);  printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Clientes\n");
    printf("  2 - Faturas\n");
    printf("  3 - Emiss%co de Relat%crios\n", 198, 162);
    printf("  4 - Pagamentos\n");
    printf("  ----------------------\n");
    printf("  0 - Sair do Aplicativo\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int submenu_cliente()
{
    caracteres(66, '='); printf("\n");
    printc("Clientes",66); printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Inserir novos clientes\n");
    printf("  2 - Alterar dados de um cliente\n");
    printf("  3 - Excluir um cliente\n");
    printf("  4 - Buscar clientes\n");
    printf("  5 - Listar clientes\n");
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int submenu_altera()
{
    system("cls");
    caracteres(66, '='); printf("\n");
    printc("Altera\x87\xc6o de Dados de Clientes", 66); printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Nome\n");
    printf("  2 - CPF\n");
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int submenu_emissao_fatura()
{
    caracteres(66, '='); printf("\n");
    printc("Emissao de Dados da Fatura",66); printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Faturas em aberto \n");
    printf("  2 - Pesquisar faturas em aberto de um cliente\n");
    printf("  3 - Pesquisar historico de faturas de um cliente\n");
    printf("  4 - Faturas em aberto ha mais de trinta dias \n");
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}
int submenu_emissao_cliente()
{
    caracteres(66, '='); printf("\n");
    printc("Emissao de Dados da Fatura",66); printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Clientes com faturas em aberto \n");
    printf("  2 - Pesquisar faturas em aberto de um cliente\n");
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}
int submenu_busca()
{
    system("cls");
    caracteres(66, '='); printf("\n");
    printc("Busca de Clientes", 66); printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Pelo nome\n");
    printf("  2 - Pelo c%cdigo\n", 162);
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

void cabecalho()
{
    printf("  ------ ---------------------------- -------------- \n");
    printf("  C%cdigo            Nome                    CPF       \n",162);
    printf("  ------ ---------------------------- -------------- \n");
}



void digitor(int *digito)
{
    *digito %=11;
    *digito = 11 - *digito;
    if(*digito>9)
        *digito = 0;

}

int tonumber(char *x)
{
    return ((int)*x)-48;
}

void validar_cpf(char *c)
{
    bool valido = false;
    while(!valido)
    {
        char cpf[100];
        int digito = 0;
        printf("    Digite seu CPF: ");
        scanf("%s",cpf);
        if(cpf[11]!='\0')
        {
            printf("    *** CPF invalido ***\n");
        }
        else
        {
            for(int i=1; i<=9; i++)
                digito += tonumber(&cpf[i-1])*(11-i);
            printf("\n");
            digitor(&digito);
            if(tonumber(&cpf[9])==digito)
            {
                digito = 0;
                for(int i=0; i<=9; i++)
                    digito += tonumber(&cpf[i])*(11-i);
                digitor(&digito);
                if(tonumber(&cpf[10])==digito)
                {
                    for(int i=0; i<11; i++)
                    {
                        c[i] = cpf[i];
                    }
                    printf("    *** CPF VALIDADO *** \n");
                    valido = true;

                }
                else
                    printf("    *** CPF invalido *** \n");

            }
            else
                printf("    *** CPF invalido *** \n");
        }
    }
}

int submenu_fatura()
{
    caracteres(66, '=');
    printf("\n");
    printc("Faturas", 66);
    printf("\n");
    caracteres(66, '=');
    printf("\n");
    printf("  1 - Inserir nova fatura\n");
    printf("  2 - Alterar dados de uma fatura\n");
    printf("  3 - Excluir uma fatura\n");
    printf("  4 - Buscar fatura pelo c%cdigo\n", 162);
    printf("  5 - Listar faturas pelo c%cdigo\n", 162);
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int submenu_relatorio()
{
    caracteres(66, '=');
    printf("\n");
    printf("                        Emiss%co Relatorios", 198);
    printf("\n");
    caracteres(66, '=');
    printf("\n");
    printf("  1 - Faturas \n");
    printf("  2 - Clientes\n");
    printf("  3 - Pagamentos\n");
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int main()
{
    FILE *fp;

    int cod_asc[256];
    fp = fopen("ascii_blo_not.arq", "rb");
    fread(cod_asc, sizeof(int), 256, fp);
    fclose(fp);

    char nome[41];
    char cpfAltera[12];
    srand(time(NULL));
    TListaDeClientes lis_cli;
    TListaDeFaturas lis_fat;
    TFatura fat;
    lis_fat.num_fat = 0;
    lis_cli.num_cli = 0;
    int cod, rb,ind;
    unsigned ult_cod, ult_cod_fat;
    int alterado = 0;
    TCliente cli;
    int i;
    for(i=0; i<20; i++)
        insere_no_fim(&lis_cli, gere_cliente(i+1));
    ult_cod = 20;

    for(i=0; i<50; i++)
        insere_na_lista(&lis_fat, gere_fatura(i+1));
    ult_cod_fat = 50;
    fp = fopen("clientes.arq", "rb");
    fread(&ult_cod, sizeof(int), 1, fp);
    fread(&lis_cli.num_cli, sizeof(int), 1, fp);
    fread(lis_cli.clientes, sizeof(TCliente), lis_cli.num_cli, fp);
    fclose(fp);

    fp = fopen("faturas.arq", "rb");
    fwrite(&ult_cod_fat, sizeof(int), 1, fp);
    fwrite(&lis_fat.num_fat, sizeof(unsigned), 1, fp);
    fwrite(lis_fat.faturas, sizeof(TFatura), lis_fat.num_fat, fp);
    fclose(fp);

    char op, op2;
    while(1)
    {
        op = menu_principal();
        if (op == '0')
        {
            if(alterado)
            {
                printf("  Arquivo alterado. Deseja salvar as altera%c%ces? (S/N): ",135,228);
                fflush(stdin);
                op2 = toupper(getchar());
                while(op2 != 'S' && op2 != 'N')
                {
                    printf("  Favor digitar S ou N: ");
                    fflush(stdin);
                    op2 = toupper(getchar());
                }
                if(op2 == 'S')
                {
                    fp = fopen("clientes.arq", "wb");
                    fwrite(&ult_cod, sizeof(int), 1, fp);
                    fwrite(&lis_cli.num_cli, sizeof(int), 1, fp);
                    fwrite(lis_cli.clientes, sizeof(TCliente), lis_cli.num_cli, fp);
                    fclose(fp);

                    fp = fopen("faturas.arq", "wb");
                    fwrite(&ult_cod_fat, sizeof(int), 1, fp);
                    fwrite(&lis_fat.num_fat, sizeof(unsigned), 1, fp);
                    fwrite(lis_fat.faturas, sizeof(TFatura), lis_fat.num_fat, fp);
                    fclose(fp);
                    printf("\n  ** Dados salvos **\n");
                }
                else
                    printf("\n  ** Dados descartados\n");
            }
            printf("\n  ** Fim do aplicativo **");
            sleep(3);
            break;
        }
        switch(op)
        {
            case '1':
                while(1)
                {
                    op2 = submenu_cliente();
                    if (op2 == '0')
                    {
                        break;
                    }
                    switch(op2)
                    {
                        case '1':
                            caracteres(66, '-'); printf("\n");
                            printc("Inserir Clientes",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            printf("    Nome: ");
                            fflush(stdin);
                            gets(cli.nome);
                            validar_cpf(cli.cpf);
                            cli.codigo = ult_cod;
                            ult_cod++;
                            insere_no_fim(&lis_cli, cli);
                            alterado = 1;
                            break;
                        case '2':
                            while(1)
                            {
                                op2 = submenu_altera();
                                if (op2 == '0')
                                {
                                    break;
                                }
                                switch(op2)
                                {
                                    case '1':
                                        caracteres(66, '-');
                                        printf("\n");
                                        printc("Altera\x87\xc6o de Nome",66);
                                        printf("\n");
                                        caracteres(66, '-');
                                        printf("\n");
                                        printf("C%cdigo: ", 162);
                                        fflush(stdin);
                                        scanf("%u", &cod);
                                        ind = busca_pelo_codigo(lis_cli, cod);
                                        if(ind < 0)
                                            printf("\n Codigo inexistente\n");
                                        else
                                        {
                                            printf("Nome atual: %s\n", lis_cli.clientes[ind].nome);
                                            printf("Nome alterado: ");
                                            fflush(stdin);
                                            gets(nome);
                                            printf("\n  Confirma a altera%c%co? (S/N): ", 135, 198);
                                            fflush(stdin);
                                            op2 = toupper(getchar());
                                            while(op2 != 'S' && op2 != 'N')
                                            {
                                                printf("  Favor digitar S ou N: ");
                                                fflush(stdin);
                                                op2 = toupper(getchar());
                                            }
                                            if(op2 == 'S')
                                            {
                                                strcpy(lis_cli.clientes[ind].nome, nome);
                                                alterado = 1;
                                                printf("\n  ** Altera%c%co realizada\n",135,198);
                                            }
                                            else
                                                printf("\n  ** Altera%c%co descartada\n",135,198);
                                            sleep(3);
                                        }
                                        break;
                                    case '2':
                                        caracteres(66, '-');
                                        printf("\n");
                                        printc("Altera\x87\xc6o de CPF",66);
                                        printf("\n");
                                        caracteres(66, '-');
                                        printf("\n");
                                        printf("C%cdigo: ", 162);
                                        fflush(stdin);
                                        scanf("%u", &cod);
                                        ind = busca_pelo_codigo(lis_cli, cod);
                                        if(ind < 0)
                                            printf("\n Codigo inexistente\n");
                                        else
                                        {
                                            printf("CPF atual:") ;
                                            mostre_cpf(lis_cli.clientes[ind].cpf);
                                            validar_cpf(lis_cli.clientes[ind].cpf);

                                            sleep(3);
                                        }
                                        break;
                                    default:
                                        printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                                }
                            }
                            break;
                        case '3':
                            caracteres(66, '-');printf("\n");
                            printc("Excluir um cliente",66);printf("\n");
                            caracteres(66, '-');printf("\n");
                            printf("    C%cdigo: ",162);
                            fflush(stdin);
                            scanf("%u", &cod);
                            ind = busca_pelo_codigo(lis_cli, cod);
                            if(ind < 0)
                            {
                                printf("\n  *** Codigo inexistente ***\n");
                                system("pause");
                            }
                            else
                            {
                                remove_do_indice(&lis_cli, ind);
                                alterado = 1;
                                printf("\n  *** O cliente foi excluido com sucesso ***\n");
                                system("pause");
                            }
                            break;
                        case '4':
                            op2 = submenu_busca();
                            if (op2 == '0')
                            {
                                break;
                            }
                            switch(op2)
                            {
                                case '1':
                                    caracteres(66, '-'); printf("\n");
                                    printc("Busca Cliente pelo Nome",66); printf("\n");
                                    caracteres(66, '-'); printf("\n");
                                    busca_pelo_nome(lis_cli);
                                    printf("\n");
                                    system("pause");
                                    break;
                                case '2':
                                    caracteres(66, '-'); printf("\n");
                                    printc("Buscar Cliente pelo C\xa2 \bdigo",66);printf("\n");
                                    caracteres(66, '-'); printf("\n");
                                    printf("C%cdigo: ", 162);
                                    cod = le_inteiro();
                                    ind = busca_pelo_codigo(lis_cli, cod);
                                    if(ind < 0)
                                        printf("\n  ** C%cdigo inexistente **\n",162);
                                    else{
                                        mostre_cliente(lis_cli.clientes[ind]);
                                        printf("\n");
                                        }
                                    system("pause");
                                    break;
                                }
                            break;
                        case '5':
                            caracteres(66, '-'); printf("\n");
                            printc("Listar",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            cabecalho();
                            mostre_lista_de_clientes(lis_cli);
                            system("pause");
                            break;

                        default:
                            printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                            system("pause");
                    }
                }
                break;
        case '2':
             while(1)
            {
                op2 = submenu_fatura();
                if (op2 == '0')
                {
                    break;
                }
                switch(op2)
                {
                case '1':
                    caracteres(66, '-');
                    printf("\n");
                    printf("Inserir Novo Fatura");
                    printf("\n");
                    caracteres(66, '-');
                    printf("\n");
                    printf("(nao esta pronto): ");
                    fflush(stdin);
//                    gets(cli.nome);
//                    valida_cpf(cli.cpf);
//                    cli.codigo = ult_cod + 1;
//                    ult_cod++;
//                    insere_no_fim_la(&lis_cli, cli);
                    break;
                case '2':
                    while(1)
                    {
                        op2 = submenu_altera();
                        if (op2 == '0')
                        {
                            break;
                        }
                        switch(op2)
                        {
                        case '1':
                            caracteres(66, '-');
                            printf("\n");
                            printc("Altera\x87\xc6o do Cliente",66);
                            printf("\n");
                            caracteres(66, '-');
                            printf("\n");
                            printf("C%cdigo: ", 162);
                            scanf("%u", &cod);
                            ind = busca_fatura_pelo_codigo(lis_fat, cod);
                             if(ind < 0)
                                printf("\n Codigo inexistente\n");
                            else
                            {
                               // criar metodo
                            }
                            break;
                        case '2':
                            caracteres(66, '-');
                            printf("\n");
                            printc("Altera\x87\xc6o da Data de Vencimento",66);
                            printf("\n");
                            caracteres(66, '-');
                            printf("\n");
                            printf("C%cdigo: ", 162);
                            scanf("%u", &cod);
//                            ind = busca_cliente_pelo_codigo(lis_cli, cod);
//                             if(ind < 0)
//                                printf("\n Codigo inexistente\n");
//                            else
//                            {
//                                // criar metodo
//                            }
                            break;
                        default:
                            printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                        }
                    }
                    break;
                case '3':
                    caracteres(66, '-');
                    printf("\n");
                    printf("Excluir uma fatura");
                    printf("\n");
                    caracteres(66, '-');
                    printf("\n");
                    printf("C%cdigo: ");
                    scanf("%u", &cod);
                    ind = busca_fatura_pelo_codigo(lis_fat, cod);
                    if(ind < 0)
                        printf("\n Codigo inexistente\n");
                    else
                    {
                        remove_da_lista(&lis_fat, ind);
                    }
                    break;
                case '4':
                    caracteres(66, '-');
                    printf("\n");
                    printc("Buscar Fatura pelo C\xa2 \bdigo",66);
                    printf("\n");
                    caracteres(66, '-');
                    printf("\n");
                    printf("C%cdigo: ", 162);
                    cod = le_inteiro();
                    ind = busca_fatura_pelo_codigo(lis_fat, cod);
                    if(ind < 0)
                       printf("\n  ** C%cdigo inexistente **\n",162);
                    else
                    {
                       int cod_cli;
                       cod_cli = lis_fat.faturas[ind].cliente;
                       mostre_fatura(lis_fat.faturas[ind], lis_cli.clientes[ind]);
                       printf("\n");
                    }
                    break;
                case '5':
                    caracteres(66, '-');
                    printf("\n");
                    printf("               Listar Faturas pelo Codigo");
                    printf("\n");
                    caracteres(66, '-');
                    printf("\n");
                    qsort(lis_fat.faturas, lis_fat.num_fat, sizeof(TFatura),
                          compare_numero);
                    mostre_lista_de_faturas(lis_fat, lis_cli);
                    printf("\n");
                    break;
                default:
                    printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                }
            }
            break;
        case '3':
            while(1)
            {
                op2 = submenu_relatorio();
                if (op2 == '0')
                {
                    break;
                }
                switch(op2)
                {
                case '1':
                    while(1)
                    {
                        op2 = submenu_emissao_fatura();
                        if (op2 == '0')
                        {
                            break;
                        }
                        switch(op2)
                        {
                        case '1':
                            caracteres(66, '-');
                            printf("\n");
                            printf("               Listar Faturas em Aberto");
                            printf("\n");
                            caracteres(66, '-');
                            printf("\n");

                            qsort(lis_fat.faturas, lis_fat.num_fat, sizeof(TFatura),
                                  compare_numero);
                            mostre_lista_de_faturas_abertas(lis_fat, lis_cli);
                            printf("\n");
                            break;
                        case '2':
                            caracteres(66, '-');
                            printf("\n");
                            printc("Buscar Faturas em Aberto pelo C\xa2 \bdigo do Cliente",66);
                            printf("\n");
                            caracteres(66, '-');
                            printf("\n");
                            printf("C%cdigo do Cliente: ", 162);
                            cod = le_inteiro();
                            ind = busca_pelo_codigo(lis_cli, cod);
                            if(ind < 0)
                               printf("\n  ** C%cdigo inexistente **\n",162);
                            else
                            {
                               printf("\n");
                               mostre_lista_de_faturas_aberta_cliente(lis_fat, lis_cli.clientes[ind]);
                               printf("\n");
                            }
                            break;
                        case '3':
                            caracteres(66, '-');
                            printf("\n");
                            printc("Buscar histórico de faturas pelo C\xa2 \bdigo do Cliente",66);
                            printf("\n");
                            caracteres(66, '-');
                            printf("\n");
                            printf("C%cdigo do Cliente: ", 162);
                            cod = le_inteiro();
                            ind = busca_pelo_codigo(lis_cli, cod);
                            if(ind < 0)
                               printf("\n  ** C%cdigo inexistente **\n",162);
                            else
                            {
                               printf("\n");
                               mostre_lista_de_faturas_aberta_cliente(lis_fat, lis_cli.clientes[ind]);
                               printf("\n");
                            }
                            break;
                        case '4':
                            caracteres(66, '-');
                            printf("\n");
                            printc("Listar Faturas em Aberto pelo C\xa2 \bdigo ha mais de trinta dias",66);
                            printf("\n");
                            caracteres(66, '-');
                            printf("\n");
                            printf("C%cdigo do Cliente: ", 162);
                            cod = le_inteiro();
                            ind = busca_pelo_codigo(lis_cli, cod);
                            if(ind < 0)
                               printf("\n  ** C%cdigo inexistente **\n",162);
                            else
                            {
                               printf("\n");
                               mostre_lista_de_faturas_aberta_cliente(lis_fat, lis_cli.clientes[ind]);
                               printf("\n");
                            }
                            break;
                                default:
                                    printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                                }
                            }
                    break;
                case '2':
                    while(1)
                    {
                        op2 = submenu_emissao_cliente();
                        if (op2 == '0')
                        {
                            break;
                        }
                        switch(op2)
                        {
                        case '1':
                            caracteres(72, '-');
                            printf("\n");
                            printf("               Listar Clientes com faturas em aberto");
                            printf("\n");
                            caracteres(72, '-');
                            printf("\n");
                            qsort(lis_fat.faturas, lis_fat.num_fat, sizeof(TFatura),
                                  compare_numero);
                            mostre_lista_de_clientes_abertas(lis_fat, lis_cli);
                            printf("\n");
                            break;
                        case '2':
                            caracteres(66, '-');
                            printf("\n");
                            printc("Altera\x87\xc6o da Data de Vencimento",66);
                            printf("\n");
                            caracteres(66, '-');
                            printf("\n");
                            printf("C%cdigo do Cliente: ", 162);
                            cod = le_inteiro();
                            ind = busca_pelo_codigo(lis_cli, cod);
                            if(ind < 0)
                               printf("\n  ** C%cdigo inexistente **\n",162);
                            else
                            {
                            qsort(lis_fat.faturas, lis_fat.num_fat, sizeof(TFatura),
                                  compare_numero);
                            //busca_cliente_aberta(lis_fat, lis_cli.clientes[ind]);
                            printf("\n");
                            }

                            break;
                        default:
                            printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                        }
                    }
                    break;
                case '3':
                    caracteres(66, '-');
                    printf("\n");
                    printf("Excluir uma fatura");
                    printf("\n");
                    caracteres(66, '-');
                    printf("\n");
                    printf("C%cdigo: ");
                    scanf("%u", &cod);
                    ind = busca_fatura_pelo_codigo(lis_fat, cod);
                    if(ind < 0)
                        printf("\n Codigo inexistente\n");
                    else
                    {
                        remove_da_lista(&lis_fat, ind);
                    }
                    break;
                case '4':
                    caracteres(66, '-');
                    printf("\n");
                    printc("Buscar Fatura pelo C\xa2 \bdigo",66);
                    printf("\n");
                    caracteres(66, '-');
                    printf("\n");
                    printf("C%cdigo: ", 162);
                    cod = le_inteiro();
                    ind = busca_fatura_pelo_codigo(lis_fat, cod);
                    if(ind < 0)
                       printf("\n  ** C%cdigo inexistente **\n",162);
                    else
                    {
                       int cod_cli;
                       cod_cli = lis_fat.faturas[ind].cliente;
                       mostre_fatura(lis_fat.faturas[ind], lis_cli.clientes[ind]);
                       printf("\n");
                    }
                    break;
                case '5':
                    caracteres(66, '-');
                    printf("\n");
                    printf("               Listar Faturas pelo Codigo");
                    printf("\n");
                    caracteres(66, '-');
                    printf("\n");
                    qsort(lis_fat.faturas, lis_fat.num_fat, sizeof(TFatura),
                          compare_numero);
                    mostre_lista_de_faturas(lis_fat, lis_cli);
                    printf("\n");
                    break;
                default:
                    printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                }
            }
            break;
        case '4':
            caracteres(66, '-');
            printf("\n");
            printc("T\xa1tulo da Op\x87\xc6o 4", 66);
            printf("\n");
            caracteres(66, '-');
            printf("\n");
            // Insira seu código aqui
            break;
        default:
            printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
            system("pause");
        }
    }
    return 0;
}
