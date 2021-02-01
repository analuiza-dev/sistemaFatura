struct lista_de_clientes
{
    int num_cli;
    TCliente clientes[200];
};
typedef struct lista_de_clientes TListaDeClientes;

void insere_no_fim(TListaDeClientes *lis, TCliente cli)
{
    lis->clientes[lis->num_cli++] = cli;
}

void mostre_lista_de_clientes(TListaDeClientes lis)
{
    int i;
    for(i=0; i<lis.num_cli; i++)
        mostre_cliente(lis.clientes[i]);
        printf("\n");
}

int busca_pelo_codigo(TListaDeClientes lis, int cod)
{
    int i;
    for(i=0; i<lis.num_cli; i++)
        if(cod == lis.clientes[i].codigo)
            return i;
    return -1;
}

void busca_pelo_nome(TListaDeClientes lis)
{
    char nome[41];
    printf("Digite as letras iniciais do nome: ");
    fflush(stdin);
    gets(nome);
    int i, encontrou = 0;
    for(i=0; i<lis.num_cli; i++)
    {
        if(lis.clientes[i].nome == strstr(lis.clientes[i].nome, nome))
        {
            mostre_cliente(lis.clientes[i]);
            encontrou = 1;
        }
    }
    if(!encontrou)
        printf("\n  ** Nenhum cliente encontrado **\n");
}

void remove_do_indice(TListaDeClientes *lis, int ind)
{
    TCliente res = lis->clientes[ind];
    int i;
    for(i=ind; i<lis->num_cli-1; i++)
        lis->clientes[i] = lis->clientes[i+1];
    lis->num_cli--;
}







