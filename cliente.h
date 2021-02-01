struct cliente
{
    unsigned codigo;
    char nome[41];
    char cpf[12];
};
typedef struct cliente TCliente;

TCliente* alocar_cliente()
{ //como eu aloco na lista de clientes???
     TCliente *cliente;
     cliente = (TCliente*) malloc (sizeof(TCliente));
    return cliente;
}

void gere_nome(char *n)
{
    int ps, ss;
    char nomes[][16] = {"Aline", "Ana", "Beatriz", "Bernardo", "Bruno", "Camila", "Carlos", "Cec\xa1lia",
             "Davi", "Eduardo", "Felipe", "Francisco", "Gabriel", "G\x82rson", "Heitor", "Henrique",
             "Ingrid", "Isabela", "J\xa3lia", "Larissa", "Laura", "Leonardo", "Lorena", "Marcelo",
             "M\xa0rcia", "Marcos", "Mariana", "Milena", "Patr\xa1\x63ia", "Pedro", "Priscila", "Renato",
             "Ricardo", "Rodrigo", "Ronaldo", "Samuel", "S\x82rgio", "Sofia", "Tiago", "Vin\xa1\x63ius"};
    char sobres[][16] = {"Abreu", "Albuquerque", "Almeida", "Alencar", "Alves", "Amaral", "Amorim",
                  "Andrade", "Antunes", "Arantes", "Ara\xa3jo", "Arruda", "Azevedo", "Barros",
                  "Bastos", "Batista", "Bezerra", "Brand\xc6o", "Brito", "Cabral", "Campos",
                  "Cardoso", "Carneiro", "Carvalho", "Castro", "Cavalcante", "Chagas", "Chaves",
                  "Correia", "Costa", "Cruz", "Dantas", "Diniz", "Duarte", "Esteves", "Fagundes",
                  "Fernandes", "Ferraz", "Ferreira", "Figueiredo", "Fonseca", "Franco", "Freire",
                  "Freitas", "Furtado", "Gomes", "Gon\x87\x61lves", "Guedes", "Guerra", "Guimar\xc6\x65s",
                  "Liberato", "Marinho", "Marques", "Martins", "Medeiros", "Melo", "Menezes",
                  "Monteiro", "Montenegro", "Moraes", "Moreira", "Moura", "Nogueira", "Noronha",
                  "Novaes", "Oliveira", "Pereira", "Pinto", "Resende", "Ribeiro", "Rios",
                  "Sampaio", "Santana", "Santos", "Torres", "Trindade", "Vasconcelos", "Vargas"};
    strcpy(n,nomes[rand()%40]);
    strcat(n, " ");
    ps = rand()%78;
    ss = rand()%78;
    while(ps == ss)
        ss = rand()%78;
    strcat(n, sobres[ps]);
    strcat(n, " ");
    strcat(n, sobres[ss]);
}

void gere_cpf(char *cp) {
    int *cpf, multiplica[11], somador[11], res, mod, valDigito,  i;

    cpf = (int*) malloc(sizeof(int) * 11);
    for(i = 0; i < 9; i++) {
        cpf[i] = rand() % 10;
    }
    for(i = 0; i < 9; i++) {
        multiplica[i] = 10 - i;
    }
    for(i = 0; i < 9; i++) {
        somador[i] = cpf[i] * multiplica[i];
    }
    res = 0;
    for(i = 0; i < 9; i++) {
        res += somador[i];
    }
    mod = res % 11;
    if(mod < 2) {
        valDigito = 0;
    } else {
        valDigito = 11 - mod;
    }
    cpf[9] = valDigito;

    for(i = 0; i < 10; i++) {
        multiplica[i] = 11 - i;
    }
    for(i = 0; i < 10; i++) {
        somador[i] = cpf[i] * multiplica[i];
    }
    res = 0;
    for(i = 0; i < 10; i++) {
        res += somador[i];
    }
    mod = res % 11;

    if(mod < 2) {
        valDigito = 0;
    } else {
        valDigito = 11 - mod;
    }
    cpf[10] = valDigito;

    for(int i=0;i<11;i++){
        cp[i] = '0' + cpf[i];
    }
}

TCliente gere_cliente(int cod)
{
    TCliente cli;
    cli.codigo = cod;
    gere_nome(cli.nome);
    gere_cpf(cli.cpf);
    return cli;
}


void mostre_cliente(TCliente cli)
{
    cli.nome[28] = '\0';
    printf("  %06u %-28s", cli.codigo, cli.nome, cli.cpf);
    mostre_cpf(cli.cpf);
}

void mostre_cpf(char *cp){
    printf(" ");
    for(int i = 0; i<11; i++){
        printf("%c", cp[i]);        if(i==2 || i == 5){
            printf(".");
        }
        if(i == 8){
            printf("-");
        }
        if(i == 10){
            printf("\n");
        }
    }
}

int compara_codigo(const void *a, const void *b)
{
    TCliente *aa = (TCliente *) a;
    TCliente *ab = (TCliente *) b;
    return aa->codigo - ab->codigo;
}

int compara_nome(const void *a, const void *b)
{
    TCliente *aa = (TCliente *) a;
    TCliente *ab = (TCliente *) b;
    return strcmp(aa->nome, ab->nome);
}











