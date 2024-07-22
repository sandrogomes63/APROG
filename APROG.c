#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Trabalho de APROG - Grupo 1
       LOJA ONLINE

Elementos do grupo:

Ana Teixeira     - 1221110
Tiago de Azevedo - 1212059
Sandro Gomes     - 1221717

"O objetivo principal do trabalho prático é a construção de um programa escrito em linguagem C, que permita
auxiliar a gestão de clientes, produtos e compras."

// Estruturas de dados

ARTIGOS
Codigo dos Artigos
    Algarismo Inicial:  1 -> Calçado
                        2 -> Acessórios
                        3 -> Vestuário Inferior
                        4 -> Vestuário Superior
                        5 -> Conjuntos
                        6 -> Roupa Interior
    Segundo algarismo:  Categoria
    Terceiro algarismo: 0 -> Masculino
                        1 -> Feminino
                        2 -> Unissexo
*/

#define MAX_ARTS 68 //definição de 68 artigos pré-carregados
#define MAX_CLTS 20 //definição de 20 clientes pré-carregados
#define MAX_CMPS 100

////Vectores com os dados dos artigos para pré-carregamento
char desc_arts[MAX_ARTS][30] = {"Sapatos Masc. Classico","Sapatos Masc. Vela","Sapatos Fem. Salto","Sapatos Fem. Plataforma","Sapatos Fem. Raso",
"Sapatilhas Masc. Desporto","Sapatilhas Masc. Casual","Sapatilhas Fem. Desporto","Sapatilhas Fem. Casual","Botas Masc. Seguranca",
"Botas Masc. Casual","Botas Masc. Galochas","Chinelos Masc. Natação","Chinelos Masc. Havaianas","Chinelos Masc. Pantufas",
"Chinelos Masc. Crocks","Chinelos Masc. Quarto","Chinelos Fem. Natação","Chinelos Fem. Havaianas","Chinelos Fem. Pantufas",
"Chinelos Fem. Crocks","Chinelos Fem. Quarto","Brincos","Broche","Anel","Cinto","Colar","Relogio","Cachecol","Gorro","Luvas","Pulseira",
"Gravata","Botoes de Punho","Fitas Cabelo","Calcas Masc. Leggins","Calcas Masc. Ganga","Calcas Masc. Classicas","Calcas Masc. Bombazine",
"Calcas Fem. Leggins","Calcas Fem. Ganga","Calcas Fem. Classicas","Calcas Fem. Bombazine","Corcarios Masc","Corcarios Fem",
"Calcoes Masc","Calcoes Fem","Saia","T-Shirt","Camisola Termica","Camisola Hoodie","Camisola Sweat","Camisola Sem Manga","Camisa Masc.",
"Camisa Fem.","Quispo Masc.","Soretudo Masc.","Blazer Masc.","Quispo Fem.","Sobretudo Fem.","Blazer Fem.","Pijama Masc.","Pijama Fem.",
"Fato de Treino Masc.", "Fato de Treino Fem.","Meias","Boxers","Cuecas"};

int cod_arts[MAX_ARTS] = {1000, 1001, 1010, 1011, 1012, 1100, 1101, 1110, 1111, 1200, 1201, 1202, 1300, 1301, 1302, 1303, 1304, 1310,
1311, 1312, 1313, 1314, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 3000, 3001, 3002, 3003, 3010,
3011, 3012, 3013, 3100, 3110, 3200, 3210, 3300, 4000, 4120, 4121, 4220, 4320, 4400, 4410, 4500, 4501, 4502, 4510, 4511, 4512, 5000, 5010,
5100, 5110, 6020, 6021, 6022};

float preco_arts[MAX_ARTS] = {99.99, 76.99, 57.49, 41.90, 25.90, 80.90, 120, 67.5, 93.90, 54.90, 139.9, 47.9, 25.90, 32.90, 15.3, 20, 11.59,
21.90, 30.90, 12.3, 17, 10.59, 7.99, 12.9, 5, 18, 22.9, 173.9, 17.9, 13.5, 15, 21, 27.9, 13.9, 3.9, 23.90, 54, 72.50, 37.9, 32.90, 25,
55.30, 40, 25.90, 25.90, 27.49, 18.90, 24.90, 15.90, 9.99, 34.9, 35.9, 9.9, 44.9, 32.9, 159.49, 219.99, 129.49, 139.9, 169.9, 99.99, 12.9,
12.9, 34.49, 28.99, 5.99, 20.99, 12.99};


//Vectores com os dados dos clientes para pré-carregamento
char nome_cli[MAX_CLTS][50] = {"Joaquim Teixeira","Maria Silva","Fernanda Pinto","Andre Bastos","Andreia Costa","Jose Couto",
    "Artur Gomes","Helena Macedo","Acacio Guimaraes","Manuela Sampaio","Patricia Alves","Ana Gomes","Isaura Macedo","Henrique Bonifacio",
    "Rita Alexandrina","Maria Miguel","Afonso Chaves","Hugo Silveira","Anibal Pinto","Fatima Alves"};

char dataNasc_cli[MAX_CLTS][12] = {"12/01/1989","24/01/1975","03/09/1999","12/11/2001","31/03/1996","10/12/1994","24/02/1969","11/08/1966",
    "14/09/1988","25/01/2003","04/04/1996","10/08/2000","19/11/1946","22/06/1994","31/01/1993","22/03/1994","30/08/1997",
    "12/04/1994","31/01/1997","11/01/1993"};

char nif_cli[MAX_CLTS][10] = {"200145871","213659874","222121322","201524789","220365459","221555874","189032578","187965872","200365885","223255219","212365455",
    "223669851","188965221","222569478","222354899","221548595","222365245","221874989","222565989","221456951"};

char morada_cli[MAX_CLTS][50] = {"Rua Prof. Joaquim Alberto, N.122", "Av. Liberdade, Blc.6, 3*Direito", "Largo Afonso Henriques, N.23",
    "Rua Agostinho Bento, N.97","Rua da Cachada, N.322, 2*Esquerdo","Rua Lickfold Silva, N.22","Rua das Campas, N.37",
    "Av. Humberto Delgado, N.31","Rua Dr. Machado Matos, N.341", "Av. Fonseca Moreira, N.45","Rua de Santa Quiteria, N.87",
    "Av. Dr. Magalhaes Lemos, N.73, 1*Centro","Lugar das Campas, N.13","Rua da Espadilha, N.163","Rua das Tabuinhas, N.11, 2*Direito",
    "Rua de Sao Roque, N.34","Rua de Sao Joao N.12","Estrada do Rali, N.32","Largo do Assento, N.62","Rua da Escalhadoura, N.19"};

char cartaoCredito_cli[MAX_CLTS][20] = {"1234 4356 9861 9743","3254 2589 1587 3654","2589 7452 1254 3658","1278 4569 4587 2543",
    "4160 2221 3652 2589","3250 2587 9985 6512","4125 5896 5487 5236","3698 4587 1456 2159","3652 2555 8545 9961","2352 4458 5741 1259",
    "2365 8521 4596 3658","7852 2546 2235 9651","2322 3656 4512 2587","7851 2561 3294 1548","2458 3221 4452 9851","4585 2541 2226 3322",
    "5568 2543 2659 8795","4325 6528 3265 9562","2658 5985 5545 2225","3265 2655 2248 9995"};

char tipoCliente_cli[MAX_CLTS][20] = {"gold","normal","normal","gold","normal","normal","normal","gold","normal","normal","gold","normal",
    "gold","normal","normal","gold","normal","normal","gold","normal"};

int clt_elem=0, art_elem=0;

//Declaração das estruturas CLIENTE, ARTIGOS,
typedef struct
{
    char nome[50];
    char data_nasc[12];
    char nif[10];
    char morada[50];
    char cartao_credito[20];
    char tipo_cliente[20];
} CLIENTE;

typedef struct
{
    int codigo;
    char descricao[50];
    float preco;
} ARTIGO;

typedef struct
{
    int codigo_artigo[MAX_ARTS];
    char descricao[MAX_ARTS][50];
    float preco_ind[MAX_ARTS];
    int quantidade[MAX_ARTS];
    float preco_total;
} COMPRA;

//Funções
void precarregar_cliente(CLIENTE *cliente, int *n_clientes)
{
    for (int i = 0; i < MAX_CLTS; i++)
    {
        strcpy(cliente[*n_clientes].nome, nome_cli[i]);
        strcpy(cliente[*n_clientes].morada, morada_cli[i]);
        strcpy(cliente[*n_clientes].data_nasc, dataNasc_cli[i]);
        strcpy(cliente[*n_clientes].nif, nif_cli[i]);
        strcpy(cliente[*n_clientes].cartao_credito, cartaoCredito_cli[i]);
        strcpy(cliente[*n_clientes].tipo_cliente, tipoCliente_cli[i]);

        *n_clientes = *n_clientes + 1;
    }
}

int inserir_cliente(CLIENTE *cliente, int *n_clientes)
{
    int flgClt = 0;
    char nome_clt[50];
    char mor_clt[50];
    char nas_clt[12];
    char nif_clt[10];
    char card_clt[20];
    char tip_clt[10];

    printf("\n0 - Cancelar\n");
    printf("\nNumero de Contribuinte: ");
    scanf("%s", nif_clt);
    if (strcmp(nif_clt, "0") == 0) return 2;            //a função retorna 2 caso o utilizador insira 0
    if (strlen(nif_clt) != 9)                           // garante que o cliente só pode inserir 9 caractéres
    {
        printf("\nNumero de Contribuinte invalido!\n");
        return 1;
    }

    //impede a criação de clientes que já existam
    for (int i = 0; i < *n_clientes; i++)
    {
        if (strcmp(cliente[i].nif, nif_clt) == 0)
        {
            flgClt = 1;
            break;
        }
    }
    if (flgClt == 1) //verifica se o cliente já existe
    {
        printf("\nO NIF %s ja se encontra associado a um cliente!\nConfira o NIF inserido e volte a tentar.\n", nif_clt);
        return 1;
    }

    printf("Nome: ");
    scanf(" %[^\n]s", nome_clt);
    if (strcmp(nome_clt, "0") == 0) return 2;
    if (strlen(nome_clt) < 3)
    {
        printf("\nO nome do cliente e de preenchimento obrigatorio!\n");
        return 1;
    }

    printf("Morada: ");
    scanf(" %[^\n]s", mor_clt);
    if (strcmp(mor_clt, "0") == 0) return 2;
    if (strlen(mor_clt) < 5)
    {
        printf("\nA morada do cliente e de preenchimento obrigatorio!\n");
        return 1;
    }

    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", nas_clt);
    if (strcmp(nas_clt, "0") == 0) return 2;
    if (strlen(nas_clt) != 10)
    {
        printf("\nInsira a data de nascimento no formato indicado!\n");
        return 1;
    }

    printf("Cartao de Credito (XXXX XXXX XXXX XXXX): ");
    scanf(" %[^\n]s", card_clt);
    if (strcmp(card_clt, "0") == 0) return 2;
    if (strlen(card_clt) != 19)
    {
        printf("\nNumero de Cartao de Credito invalido!\nPor favor, verifique e volte a tentar.\n");
        return 1;
    }

    printf("Tipo de Cliente (normal/gold): ");
    scanf("%s", tip_clt);
    if (strcmp(tip_clt, "0") == 0) return 2;
    if (strcmp(tip_clt,"normal") != 0 && strcmp(tip_clt,"gold") != 0)           //experimentar partindo ao meio, ou com Else Ifs
    {
        printf("\nInserir um tipo de cliente valido (normal/gold).\n");
        return 1;
    }

    strcpy(cliente[*n_clientes].nome, nome_clt);
    strcpy(cliente[*n_clientes].morada, mor_clt);
    strcpy(cliente[*n_clientes].data_nasc, nas_clt);
    strcpy(cliente[*n_clientes].nif, nif_clt);
    strcpy(cliente[*n_clientes].cartao_credito, card_clt);
    strcpy(cliente[*n_clientes].tipo_cliente, tip_clt);

    *n_clientes = *n_clientes + 1;

    return 0;
}

int editar_cliente(CLIENTE *cliente, int *n_clientes)
{
    int clt_selec, flgClt = 0;
    char nif[10];
    char nome_clt[50];
    char mor_clt[50];
    char nas_clt[12];
    char num_clt[10];
    char card_clt[20];
    char tip_clt[20];

    printf("\n0 - Cancelar\n");
    printf("\nInsira o NIF do cliente que pretende editar: ");
    scanf("%s", nif);

    //Selecciona o cliente, caso exista
    for (int i = 0; i < *n_clientes; i++)
    {
        if (strcmp(cliente[i].nif, nif) == 0)
        {
            clt_selec = i;
            flgClt = 1;
            printf("\nCliente selecionado: %s\n", cliente[i].nome);
            break;
        }
    }
    if (flgClt == 0) {printf("\nO NIF %s nao se encontra associado a nenhum cliente.\nPor favor, confira o NIF inserido.\n", nif); return 1;}

    printf("Novo nome: ");
    scanf(" %[^\n]s", nome_clt);
    if (strcmp(nome_clt, "0") == 0) return 2;
    if (strlen(nome_clt) < 3)
    {
        printf("\nO nome do cliente e de preenchimento obrigatorio!\n");
        return 1;
    }

    printf("Nova morada: ");
    scanf(" %[^\n]s", mor_clt);
    if (strcmp(mor_clt, "0") == 0) return 2;
    if (strlen(mor_clt) < 5)
    {
        printf("\nA morada do cliente e de preenchimento obrigatorio!\n");
        return 1;
    }

    printf("Nova Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", nas_clt);
    if (strcmp(nas_clt, "0") == 0) return 2;
    if (strlen(nas_clt) != 10)
    {
        printf("\nInsira a Data de Nascimento no formato indicado!\n");
        return 1;
    }

    printf("Novo Numero de Contribuinte: ");
    scanf("%s", num_clt);
    if (strcmp(num_clt, "0") == 0) return 2;
    if (strlen(num_clt) != 9)
    {
        printf("\nNumero de Contribuinte invalido!\n");
        return 1;
    }

    printf("Novo Cartao de Credito (XXXX XXXX XXXX XXXX): ");
    scanf(" %[^\n]s", card_clt);
    if (strcmp(card_clt, "0") == 0) return 2;
    if (strlen(card_clt) != 19)
    {
        printf("\nNumero de Cartao de Credito invalido!\nPor favor, verifique e volte a tentar.\n");
        return 1;
    }

    printf("Novo Tipo de Cliente (normal/gold): ");
    scanf("%s", tip_clt);
    if (strcmp(tip_clt, "0") == 0) return 2;
    if (strcmp(tip_clt,"normal") != 0 && strcmp(tip_clt,"gold") != 0)
    {
        printf("\nInserir um tipo de cliente valido (normal/gold).\n");
        return 1;
    }

    strcpy(cliente[clt_selec].nome, nome_clt);
    strcpy(cliente[clt_selec].morada, mor_clt);
    strcpy(cliente[clt_selec].data_nasc, nas_clt);
    strcpy(cliente[clt_selec].nif, num_clt);
    strcpy(cliente[clt_selec].cartao_credito, card_clt);
    strcpy(cliente[clt_selec].tipo_cliente, tip_clt);

    return 0;
}

int eliminar_cliente(CLIENTE *cliente, int *n_clientes)
{
    int clt_selec, resp, flgClt = 0;
    char nif[10];

    printf("\n0 - Cancelar\n");
    printf("\nInsira o NIF do cliente que pretende eliminar: ");
    scanf("%s", nif);

    if (strcmp(nif, "0") == 0) return 2;
    for (int i = 0; i < *n_clientes; i++)
    {
        if (strcmp(cliente[i].nif, nif) == 0)
        {
            clt_selec = i;
            flgClt = 1;
            printf("\nCliente selecionado: %s\n", cliente[i].nome);
            printf("\nTem a certeza que pretende eliminar este registo?\n1 - Sim\n2 - Nao\n3 - Cancelar\n");
            scanf("%d", &resp);
            break;
        }
    }
    if (flgClt == 0) {printf("\nNao foi encontrado nenhum cliente com o NIF inserido!\nPor favor, verifique.\n"); return 1;}

    if (resp == 1)
    {
        strcpy(cliente[clt_selec].nome, "");
        strcpy(cliente[clt_selec].morada, "");
        strcpy(cliente[clt_selec].data_nasc, "");
        strcpy(cliente[clt_selec].nif, "");
        strcpy(cliente[clt_selec].cartao_credito, "");
        strcpy(cliente[clt_selec].tipo_cliente, "");

        for (int i = clt_selec; i < (MAX_CLTS-1); i++)
        {
            strcpy(cliente[i].nome, cliente[i+1].nome);
            strcpy(cliente[i].morada, cliente[i+1].morada);
            strcpy(cliente[i].data_nasc, cliente[i+1].data_nasc);
            strcpy(cliente[i].nif, cliente[i+1].nif);
            strcpy(cliente[i].cartao_credito, cliente[i+1].cartao_credito);
            strcpy(cliente[i].tipo_cliente, cliente[i+1].tipo_cliente);
        }
        clt_elem+=1;
    }
    else if (resp == 2)
    {
        return 1;
    }
    else if (resp == 3) return 2;

    printf("\nO cliente com o NIF %s foi eliminado com sucesso!\n", nif);
    return 0;
}

void precarregar_artigos(ARTIGO *artigo, int *n_artigos)
{
    for (int i = 0; i < MAX_ARTS; i++)
    {
        artigo[*n_artigos].codigo = cod_arts[i];
        //printf("CODIGO: %d\n", cod_arts[0]);
        strcpy(artigo[*n_artigos].descricao, desc_arts[i]);
        artigo[*n_artigos].preco = preco_arts[i];

        *n_artigos = *n_artigos + 1;
    }
}

int inserir_artigo(ARTIGO *artigo, int *n_artigos)
{
    int cod, cont = 0, flgArtigo = 0;
    char desc[50];
    float preco;

    printf("\n0 - Cancelar\n");
    printf("\nCodigo do Artigo: ");
    scanf("%d", &cod);
    int num = cod;
    if (cod == 0) return 2;         //cancela a tarefa ao inserir 0

    //verificação da quantidade de digitos obrigatórios para o código de artigo
    do
    {
        cont++;
        num /= 10;
    } while(num != 0);
    if (cont < 4 || cont > 4)
    {
        printf("\nO codigo do artigo e de preenchimento obrigatorio e deve obedecer a seguinte codificacao:\n");
        printf("\nAlgarismo Inicial: \t1 -> Calcado\n"
                        "\t\t\t2 -> Acessorios\n"
                        "\t\t\t3 -> Vestuario Inferior\n"
                        "\t\t\t4 -> Vestuario Superior\n"
                        "\t\t\t5 -> Conjuntos\n"
                        "\t\t\t6 -> Roupa Interior\n"
    "Segundo algarismo:  \tCategoria\n"
    "Terceiro algarismo: \t0 -> Masculino\n"
                        "\t\t\t1 -> Feminino\n"
                        "\t\t\t2 -> Unissexo\n");
        return 1;
    }

    //impede criar artigos que já existam
    for (int i = 0; i < *n_artigos; i++)
    {
        if (artigo[i].codigo == cod)
        {
            flgArtigo = 1;
            break;
        }
    }
    if (flgArtigo == 1) //verifica se o artigo existe
    {
        printf("\nO artigo %d ja se encontra criado!\nConfira o codigo inserido e volte a tentar.\n", cod);
        return 1;
    }

    printf("Descricao: ");
    scanf(" %[^\n]s", desc); //artigo[*n_artigos].descricao);
    if (strcmp(desc, "0") == 0) return 2;
    if (strlen(desc) < 4)
    {
        printf("\nA descricao do artigo e de preenchimento obrigatorio:\n");
        return 1;
    }

    printf("Preco Unitario: ");
    scanf("%f", &preco);
    if (preco == 0.00) return 2;
    /*if (preco < 1.00)
    {
        printf("\nO preco do artigo e de preenchimento obrigatorio:\n");
        return 1;
    }*/

    artigo[*n_artigos].codigo = cod;
    strcpy(artigo[*n_artigos].descricao, desc);
    artigo[*n_artigos].preco = preco;

    *n_artigos = *n_artigos + 1;

    return 0;
}

int editar_artigo(ARTIGO *artigo, int *n_artigos)
{
    int cod, flgArtigo = 0, art_selec;
    char desc[50];
    float preco;

    printf("\n0 - Cancelar\n");
    printf("\nInsira o codigo do artigo que pretende editar: ");
    scanf("%d", &cod);
    if (cod == 0.00) return 2;

     //impede criar artigos que já existam
    for (int i = 0; i < *n_artigos; i++)
    {
        if (artigo[i].codigo == cod)
        {
            art_selec = i;
            flgArtigo = 1;
            printf("\nArtigo selecionado: %s\n", artigo[i].descricao);
            break;
        }
    }
    if (flgArtigo == 0) //verifica se o artigo não existe
    {
        printf("\nO artigo %d nao se encontra criado!\nConfira o codigo inserido e volte a tentar.\n", cod);
        return 1;
    }

    printf("Nova descricao: ");
    scanf(" %[^\n]s", desc); //artigo[*n_artigos].descricao);
    if (strcmp(desc, "0") == 0) return 2;
    if (strlen(desc) < 4)
    {
        printf("\nA descricao do artigo e de preenchimento obrigatorio:\n");
        return 1;
    }

    printf("Novo preco Unitario: ");
    scanf("%f", &preco);
    if (preco == 0.00) return 2;

    artigo[art_selec].codigo = cod;
    strcpy(artigo[art_selec].descricao, desc);
    artigo[art_selec].preco = preco;

    return 0;
}

int eliminar_artigo(ARTIGO *artigo, int *n_artigos)
{
    int cod, flgArtigo = 0, art_selec, resp;

    printf("\n0 - Cancelar\n");
    printf("\nInsira o codigo do artigo que pretende eliminar: ");
    scanf("%d", &cod);
    if (cod == 0.00) return 2;

    //percorre a lista de artigos
    for (int i = 0; i < *n_artigos; i++)
    {
        if (artigo[i].codigo == cod)
        {
            art_selec = i;
            flgArtigo = 1;
            printf("\nArtigo selecionado: %s\n", artigo[i].descricao);
            printf("\nTem a certeza que pretende eliminar este registo?\n1 - Sim\n2 - Nao\n3 - Cancelar\n");
            scanf("%d", &resp);
            break;
        }
    }
    //verifica se o artigo não existe
    if (flgArtigo == 0)
    {
        printf("\nO artigo %d nao se encontra criado!\nConfira o codigo inserido e volte a tentar.\n", cod);
        return 1;
    }

    if (resp == 1)
    {
        artigo[art_selec].codigo = 0;
        strcpy(artigo[art_selec].descricao, "");
        artigo[art_selec].preco = 0;

        for (int i = art_selec; i < (MAX_ARTS-1); i++)
        {
            artigo[i].codigo = artigo[i+1].codigo;
            strcpy(artigo[i].descricao, artigo[i+1].descricao);
            artigo[i].preco = artigo[i+1].preco;
        }
        art_elem+=1;
    }
    else if (resp == 2)
    {
        return 1;
    }
    else if (resp == 3) return 2;

    return 0;
}

void listar_clientes(CLIENTE *cliente, int n_clientes)
{
    for (int i = 0; i < (n_clientes - clt_elem); i++)
    {
        printf("\nNome:\t\t\t %-50s", cliente[i].nome);
        printf("\nMorada:\t\t\t %-50s", cliente[i].morada);
        printf("\nData de Nascimento:\t %-20s", cliente[i].data_nasc);
        printf("\nNumero de Contribuinte:\t %-30s", cliente[i].nif);
        printf("\nCartao de Credito:\t %-30s", cliente[i].cartao_credito);
        printf("\nTipo de Cliente:\t %-20s\n", cliente[i].tipo_cliente);
    }
}

void listar_artigos(ARTIGO *artigo, int n_artigos)
{
    printf("CODIGO\t DESCRICAO\t\t\t PRECO(uni/par)\n");
    for (int i = 0; i < (n_artigos - art_elem); i++)
    {
        printf("\n%6d\t %-25s\t %10.2f", artigo[i].codigo, artigo[i].descricao, artigo[i].preco);
    }
}

int checkout(CLIENTE *cliente, ARTIGO *artigo, COMPRA *compra, int n_clientes, int n_artigos)
{
    char nif[10];
    int codigo_artigo, quantidade;
    int art_selec, clt_selec;
    int input;
    int flgArtigo = 0;
    int cat;
    //Contador de artigos
    int k = 0;

    compra->preco_total = 0;                //repõe o valor das compras a cada vez que corre a função

    printf("\n0 - Cancelar\n");
    //Seleciona o cliente
    printf("\nNumero de Contribuinte: ");
    scanf("%s", nif);
    if (strcmp(nif, "0") == 0) return 2;
    if (strlen(nif) != 9)
    {
        printf("\nNumero de Contribuinte invalido!\n");
        return 1;
    }

    for (int i = 0; i < n_clientes; i++)
    {
        if (strcmp(cliente[i].nif, nif) == 0)
        {
            clt_selec = i;
            printf("\nCliente selecionado: %s\n", cliente[i].nome);
            break;
        }
    }

    //Seleciona os artigos
    while(1)
    {
        if (k == MAX_ARTS)
        {
            printf("\nCarrinho cheio! Deve terminar o checkout.");
            break;
        }
        printf("\n0 - Cancelar\n");
        printf("\nCodigo do Artigo %d: ", k + 1);
        scanf("%d", &codigo_artigo);
        if (codigo_artigo == 0) return 2;
        for (int i = 0; i < n_artigos; i++)
        {
            if (artigo[i].codigo == codigo_artigo)
            {
                art_selec = i;
                printf("\nArtigo selecionado: %s\n", artigo[i].descricao);
                printf("Preco: %.2f Euros\n", artigo[i].preco);
                flgArtigo = 1;
                break;
            }
        }
        if (flgArtigo == 0) //verifica se o artigo não existe
        {
            printf("\nArtigo nao disponivel!\nConfira o codigo inserido e volte a tentar.\n");
            continue;
        }
        flgArtigo = 0;

        //Seleciona a quantidade
        printf("\nQuantidade: ");
        scanf("%d", &quantidade);

        //Atualiza a compra
        compra->codigo_artigo[k] = codigo_artigo;
        strcpy(compra->descricao[k], artigo[art_selec].descricao);
        compra->quantidade[k] = quantidade;
        compra->preco_ind[k] = artigo[art_selec].preco;
        compra->preco_total += artigo[art_selec].preco * quantidade;
        k++;

        printf("\nPrima:\n1 - Sair\n2 - Terminar compra\n3 - Continuar a comprar\n");
        setbuf(stdout, NULL);
        scanf("%d", &input);
        if (input == 1)
            return 0;
        else if (input == 2)
            break;
        else if (input == 3)
            continue;
    }

    // Apresentação do detalhe da compra
    printf("\n**************************************************************\n");
    printf("*********************Detalhe da compra:***********************\n");
    printf("CODIGO\t DESCRICAO\t\t\t QTD.\t PRECO(uni/par)\n");
    for (int i = 0; i < k; i++)
    {
        printf("\n%6d\t %-25s\t %d\t %10.2f", compra->codigo_artigo[i], compra->descricao[i], compra->quantidade[i], compra->preco_ind[i]);
    }
    printf("\n**************************************************************\n");

    // Apresentação dos artigos sugeridos
    printf("\nArtigos sugeridos com base na compra:\n\n");
    printf("CODIGO\t DESCRICAO\t\t\t PRECO(uni/par)\n");

    for (int i = 0; i < 2; i++)
    {
        cat = compra->codigo_artigo[i] / 1000;
        if (cat == 1)
        {
            printf("\n%6d\t %-25s\t %10.2f", artigo[10+i].codigo, artigo[10+i].descricao, artigo[10+i].preco);
        }
        if (cat == 2)
        {
            printf("\n%6d\t %-25s\t %10.2f", artigo[28+i].codigo, artigo[28+i].descricao, artigo[28+i].preco);
        }
        if (cat == 3)
        {
            printf("\n%6d\t %-25s\t %10.2f", artigo[41+i].codigo, artigo[41+i].descricao, artigo[41+i].preco);
        }
        if (cat == 4)
        {
            printf("\n%6d\t %-25s\t %10.2f", artigo[54+i].codigo, artigo[54+i].descricao, artigo[54+i].preco);
        }
        if (cat == 5)
        {
            printf("\n%6d\t %-25s\t %10.2f", artigo[62+i].codigo, artigo[62+i].descricao, artigo[62+i].preco);
        }
        if (cat == 6)
        {
            printf("\n%6d\t %-25s\t %10.2f", artigo[65+i].codigo, artigo[65+i].descricao, artigo[65+i].preco);
        }
    }

    printf("\n**************************************************************\n");

    // Apresentação dos portes
    printf("\nPortes: ");
    if (strcmp(cliente[clt_selec].tipo_cliente, "gold") == 0)
    {
        printf("Gratuitos\n");
    }
    else if (compra->preco_total > 100)
    {
        printf("Gratuitos\n");
    }
    else
    {
        compra->preco_total += 20;
        printf("20 euros\n");
    }

    printf("\nPreco Total: %.2f Euros\n\n", compra->preco_total);
    printf("**************************************************************\n");
    printf("**************************************************************\n");
    printf("**                 OBRIGADO E ATE BREVE!                    **\n");
    printf("**************************************************************\n");
    printf("**************************************************************\n");

    return 0;
}

//Função principal
int main()
{
    int opcao, n_clientes = 0, n_artigos = 0, resultado = 0;
    CLIENTE cliente[MAX_CLTS];
    ARTIGO artigo[MAX_ARTS];
    COMPRA compra[MAX_CMPS];

    precarregar_cliente(cliente, &n_clientes);
    precarregar_artigos(artigo, &n_artigos);

    printf("*************************\n");
    printf("*                       *\n");
    printf("*       VEST&SIGA       *\n");
    printf("*                       *\n");
    printf("*************************\n");

    do
    {
        //Menu de opções principal
aqui:   printf("\n\n* MENU PRINCIPAL *");

        printf("\n\nEscolha uma opcao: ");
        printf("\n1 - Gestao de clientes");
        printf("\n2 - Gestao de artigos");
        printf("\n3 - Listar clientes");
        printf("\n4 - Listar artigos");
        printf("\n5 - Comprar");
        printf("\n6 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                //Menu de gestão de clientes
                printf("\n** GESTAO DE CLIENTES **");
                printf("\n\nEscolha uma accao: ");
                printf("\n1 - Adicionar");
                printf("\n2 - Editar");
                printf("\n3 - Eliminar");
                printf("\n4 - Retroceder\n");
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 1:
                        opcao = 0;
                        resultado = inserir_cliente(cliente, &n_clientes);
                        if (resultado == 0)
                        {
                            printf("\nCliente inserido com sucesso!\n");
                        }
                        else if (resultado == 1)
                        {
                            do
                            {
                                printf("\nCliente NAO inserido!\n");
                                resultado = inserir_cliente(cliente, &n_clientes);
                            } while (resultado == 1);
                        }
                        else if (resultado == 2) {printf("\nInsercao cancelada!\n\n");}
                        break;
                    case 2:
                        opcao = 0;
                        resultado = editar_cliente(cliente, &n_clientes);
                        if (resultado == 0)
                        {
                            printf("\nCliente editado com sucesso!\n");
                        }
                        else if (resultado == 1)
                        {
                            do
                            {
                                printf("\nCliente NAO editado!\n");
                                resultado = editar_cliente(cliente, &n_clientes);
                            } while (resultado == 1);
                        }
                        else if (resultado == 2) {printf("\nEdicao cancelada!\n\n");}
                        break;
                    case 3:
                        opcao = 0;
                        resultado = eliminar_cliente(cliente, &n_clientes);
                        if (resultado == 0)
                        {
                            printf("\nCliente eliminado com sucesso!\n");
                        }
                        else if (resultado == 1)
                        {
                            do
                            {
                                printf("\nCliente NAO eliminado!\n");
                                resultado = eliminar_cliente(cliente, &n_clientes);
                            } while (resultado == 1);
                        }
                        else if (resultado == 2) {printf("\nEliminacao cancelada!\n\n");}
                        break;
                    case 4:
                        opcao = 0;
                        goto aqui;
                    default:
                        printf("\nOpcao invalida!\n");
                        break;
                }
                break;
            case 2:
                //Menu de gestão de artigos
                printf("\n** GESTAO DE ARTIGOS **");
                printf("\n\nEscolha uma accao: ");
                printf("\n1 - Adicionar");
                printf("\n2 - Editar");
                printf("\n3 - Eliminar");
                printf("\n4 - Retroceder\n");
                scanf("%d", &opcao);

                switch (opcao)
                {
                    case 1:
                        opcao = 0;
                        resultado = inserir_artigo(artigo, &n_artigos);
                        if (resultado == 0)
                        {
                            printf("\nArtigo inserido com sucesso!\n");
                        }
                        else if (resultado == 1)
                        {
                            do
                            {
                                printf("\nArtigo NAO inserido!\n");
                                resultado = inserir_artigo(artigo, &n_artigos);
                            } while (resultado == 1);
                        }
                        else if (resultado == 2) {printf("\nInsercao cancelada!\n\n");}
                        break;
                    case 2:
                        opcao = 0;
                        resultado = editar_artigo(artigo, &n_artigos);
                        if (resultado == 0)
                        {
                            printf("\nArtigo editado com sucesso!\n");
                        }
                        else if (resultado == 1)
                        {
                            do
                            {
                                printf("\nArtigo NAO editado!\n");
                                resultado = editar_artigo(artigo, &n_artigos);
                            } while (resultado == 1);
                        }
                        else if (resultado == 2) {printf("\nEdicao cancelada!\n\n");}
                        break;
                    case 3:
                        opcao = 0;
                        resultado = eliminar_artigo(artigo, &n_artigos);
                        if (resultado == 0)
                        {
                            printf("\nArtigo eliminado com sucesso!\n");
                        }
                        else if (resultado == 1)
                        {
                            do
                            {
                                printf("\nArtigo NAO eliminado!\n");
                                resultado = eliminar_artigo(artigo, &n_artigos);
                            } while (resultado == 1);
                        }
                        else if (resultado == 2) {printf("\nEliminacao cancelada!\n\n");}
                        break;
                    case 4:
                        opcao = 0;
                        goto aqui;
                    default:
                        printf("\nOpcao invalida!\n");
                        break;
                }
                break;
            case 3:
                listar_clientes(cliente, n_clientes);
                break;
            case 4:
                listar_artigos(artigo, n_artigos);
                break;
            case 5:
                opcao = 0;
                resultado = checkout(cliente, artigo, compra, n_clientes, n_artigos);
                if (resultado == 1)
                {
                    printf("\nCompra cancelada!\n\n");
                }
                break;
            case 6:
                printf("\nAte a proxima!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}
