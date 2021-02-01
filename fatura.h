struct fatura
{
    unsigned numero;
    unsigned cliente;
    TData vencimento;
    TData pagamento;
    float valor_nominal;
    float valor_pago;
};
typedef struct fatura TFatura;

TFatura gere_fatura(int num)
{
    TListaDeClientes lis_cli;
    TFatura fat;
    fat.numero = num;
    int n = 1+ rand()%20;
    fat.cliente = n;
    fat.vencimento = gere_data();
    float r2 = 1350;
    fat.valor_nominal = r2;
    fat.valor_pago = 0.0;
    return fat;
}

void mostre_fatura(TFatura fat, TCliente cli)
{
    caracteres(78, '=');printf("\n");
    printf("  Fatura %06u                                       Vencimento:", fat.numero);
    mostre_data(fat.vencimento);
    printf("\n");
    printf("  --------------------------------------------------------------------------\n");
    printf("\n ");
    printf("  Cliente: %-28s (%06u)        CPF",  cli.nome , cli.codigo);
    mostre_cpf(cli.cpf);
    printf("\n");
    printf("                                                      Valor a pagar: %.2f \n", fat.valor_nominal);
    printf("                                                      Valor pago: %.2f", fat.valor_pago);
    printf("\n");
    caracteres(78, '='); printf("\n");
    printf("\n");
}
int compare_numero(const void *a, const void *b)
{
    TFatura *pa = (TFatura *) a;
    TFatura *pb = (TFatura *) b;
    return pa->numero - pb->numero;
}

