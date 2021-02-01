
struct lista_de_faturas
{
    int num_fat;
    TFatura faturas[200];
};
typedef struct lista_de_faturas TListaDeFaturas;

void insere_na_lista(TListaDeFaturas *lis, TFatura fat)
{
    lis->faturas[lis->num_fat++] = fat;
}

void mostre_lista_de_faturas(TListaDeFaturas lis, TListaDeClientes lis_cli)
{
    int i, cod;
    TCliente cli;
    for(i=0; i<lis.num_fat; i++){
        cod = busca_pelo_codigo(lis_cli, lis.faturas[i].cliente);
        cli = lis_cli.clientes[cod];
        mostre_fatura(lis.faturas[i], cli);
    }
       printf("\n");
}
void mostre_lista_de_faturas_abertas(TListaDeFaturas lis, TListaDeClientes lis_cli)
{
    int i, cod;
    TCliente cli;
    for(i=0; i<lis.num_fat; i++){
        cod = busca_pelo_codigo(lis_cli, lis.faturas[i].cliente);
        cli = lis_cli.clientes[cod];
        if(lis.faturas[i].valor_pago == 0){
            mostre_fatura(lis.faturas[i], cli);
        }
    }
       printf("\n");
}
void mostre_lista_de_faturas_aberta_cliente(TListaDeFaturas lis, TCliente cli)
{
    int i;
    for(i=0; i<lis.num_fat; i++){
        if(lis.faturas[i].valor_pago == 0 && lis.faturas[i].cliente == cli.codigo){
            mostre_fatura(lis.faturas[i], cli);
        }
    }
       printf("\n");
}

int busca_fatura_pelo_codigo(TListaDeFaturas lis, int cod)
{
    int i;
    for(i=0; i<lis.num_fat; i++)
        if(cod == lis.faturas[i].numero)
            return i;
    return -1;
}

void remove_da_lista(TListaDeFaturas *lis, int ind)
{
    TFatura res = lis->faturas[ind];
    int i;
    for(i=ind; i<lis->num_fat-1; i++)
        lis->faturas[i] = lis->faturas[i+1];
    lis->num_fat--;
}

void mostre_lista_de_clientes_abertas(TListaDeFaturas lis, TListaDeClientes lis_cli)
{
    int i, cod;
    TCliente cli;
    for(i=0; i<lis.num_fat; i++){
        cod = busca_pelo_codigo(lis_cli, lis.faturas[i].cliente);
        cli = lis_cli.clientes[cod];
        if(lis.faturas[i].valor_pago == 0){
            printf(" Fatura: %06u |",lis.faturas[i].numero);
            mostre_cliente(cli);
            printf("\n");
        }
    }
       printf("\n");
}

