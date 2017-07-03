/***************************DONKEY KONG ASCII**********************************
   **************************DESENVOLVIDO POR*******************************
                          Pedro Rodrigues de Lima
                                   &
                         Vitor Almeida de Carvalho
    *******************SINTAXE_DE_ORGANIZAÇÃO_DE_CÓDIGO*********************
    1-As áreas são delimitadas por cabeçalhos do tipo: //###NOME_DA_AREA###//
    2-O início e termino de uma função são delimitados por:
    //----------// (exceto se no começo de uma área)
    3-Antes de cada função ou metodo há um breve comentário sobre a funcio-
    nalidade/ serventia de cada função.
    4-Os nomes de variáveis compostas tem o caractere _ indicando um espaço.
    5-Variáveis auxiliares devem ser definidas no inicio de uma função para fa-
    cilitar a leitura;
    6-Utilizar nomes explicativos para variáves. Ex:int posicao_do_mario.
    Ex: variavel_com_nome_muito_grande
    ***************************ESTRUTURA_DO_CÓDIGO**************************
    Este arquivo está dividido de forma a agrupar em áreas, por similaridade,
    os trechos de código. São as áreas:
        0-REFERENCIAS: Onde estão alguns dados  úteis para a aelaboração do
        código.
        1-BIBILIOTECAS: Onde estão listadas as bibliotecas utilizadas no de-
        senvolvimento do programa.
        2-DEFINIÇÕES: Onde estão definidos as constantes utilizadas pelo pro-
        grama.
        3-STRUCTS- Onde estão definidos todos os tipos criados para esse pro-
        jeto.
        4-SKETCHES DE FUNÇÕES:Onde estão apresentadas todas as funções cria-
        das com tipo de parametros.
        5-MAIN:Onde está o main do programa.
        6-FUNÇÕES:Onde estão as funções e metodos criadas para o jogo.
        7-AREA DE DESENVOLVIMENTO: Onde estão algumas rotinas teste, funções de
        debug e etc.
*******************************************************************************/

/*0-REFERENCIAS
Referência das cores da função textcolor()
0 = Black -----------  8 = Gray
1 = Blue ------------  9 = Light Blue
2 = Green ----------- 10 = Light Green
3 = Aqua ------------ 11 = Light Aqua
4 = Red ------------- 12 = Light Red
5 = Purple ---------- 13 = Light Purple
6 = Yellow ---------- 14 = Light Yellow
7 = White ----------- 15 = Bright White
*/
//######################1-BIBILIOTECAS############################//

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>

//######################2-DEFINIÇÕES:############################//

#define SCOREINC 1000  // Pontuação Inicial
#define VIDAS 3        // Número de vidas inicial
#define NUMMAXOBJ 460  // Tamanho máximo de objetos possíveis
#define Y_MAX 48       // Y max do prompt e x max do prompt
#define X_MAX 60
// códigos internos
#define ERRO -1
#define NOVOJOGO 0
#define CONTINUARJOGO 1
#define SAIR 3
// código  das teclas
#define SPACEBAR 32
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define ENTER 13

// definições de coisas a desenvolver  e testes

// definições de itens do jogo
#define SCORE_INICIAL 1000      // Pontuação Inicial
#define VIDAS_INICIAIS 3        // Número de vidas inicial
#define X_PDR 3                 // Tamanho X padrão para impressão
#define Y_PDR 2                 // Tamanho Y padrão para impressão
#define MAX_OBJ 460             // Numero máximo de objetos possíveis
#define MAX_BARRIL_M 10         // Número máximo de barris móveis simultaneamente na tela
#define MAX_BARRIL_E 20         // Número máximo de barris estaticos
#define MAX_SUPERFICIE 100      // Número máximo de superficies
#define MAX_ESCADA_TOPO 10      // Número máximo de fim da escada
#define MAX_ESCADA_MEIO 50      // Número máximo de escadas ok
#define MAX_ESCADA_QUEB 10      // Número máximo de escadas quebradas
#define MAX_RAMPA_DIREITA 20    // Número máximo de rampas para a direita
#define MAX_RAMPA_ESQUERDA 20   // Número máximo de rampas para a esquerda
#define X_MAX_ESPELHO 61
#define Y_MAX_ESPELHO 48
#define LINHAS_MAX 23  ////para save
#define COLUNAS_MAX 21 //para save

// cores da função text_color()
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15
// códigos internos
#define ERRO -1
#define NOVOJOGO 0
#define CONTINUARJOGO 1
#define SAIR 3
#define DERROTA 3
#define VITORIA 4
#define PAUSE 5
#define JOGANDO 9
#define TEMPO 10
#define JUMPPOWER 2
#define GRAVIDADE 50
#define VEL_MARIO 1
#define VEL_BARRIL 15
#define VEL_GERA_BARRIL 200
#define ATUALIZA_SCORE 10
#define DEBUG

#define PDIR 1
#define PESQ 2
#define PCIM 3
#define PBAI 4
//######################3-STRUCTS############################//
//Define estrutura central do programa.

typedef struct tipo_fase
{
    char tipo;
    int linha_inicial;
    int coluna_inicial;
    float velocidade;
} TIPO_FASE;

typedef struct CONTROLE  // apenas para passar a matriz como parametro
{
    char controle[Y_MAX_ESPELHO][X_MAX_ESPELHO];
    char save[LINHAS_MAX][COLUNAS_MAX];
} CONTROLE;


typedef struct JOGO
{
    TIPO_FASE vetor_objetos[MAX_OBJ];
    TIPO_FASE mario;
    CONTROLE espelho_fixo;
    CONTROLE espelho_movel;
    int mario_x_origem;
    int mario_y_origem;
    int coluna_donk;
    int linha_donk;
    int score_atual;
    int score_max;
    int vidas;
    int num_obj;
    TIPO_FASE barril_movel[MAX_BARRIL_M];
    int conta_barril;


} JOGO;
//#######################4-SKETCHES DE FUNÇÕES############################//

int mainMenu(); // menu , OK
int ler_bin(TIPO_FASE[]);  //ok
void formatprompt(); // já esta OK
void hide_cursor(); // ensconde cursor, OK
void gotoxy(int,int); // mudar posicação do cursor , OK
void text_color(int);  // cor linda, OK
int setas(); // setas OK
CONTROLE testa_queda(CONTROLE, int *, int *,int*,char*);
CONTROLE restaura_escada(int ,int ,int ,CONTROLE );
CONTROLE testa_cima(CONTROLE, int *, int *,int*,char*);
CONTROLE testa_direita(CONTROLE, int *, int *,int*,char*);
CONTROLE testa_esquerda(CONTROLE, int *, int *,int*,char*);
CONTROLE testa_baixo(CONTROLE, int *, int *,int*,char*);
void vitoria(JOGO );          // Imprime uma tela de vitória OK
void derrota(JOGO );          // Imprime uma tela de derrota OK
void imprime_fase(TIPO_FASE[],int,int); //ok
void imprime_tela_incial(); // ok
void imprime_instrucoes(); //ok
int move_mario(JOGO*,char);        // Move o mário A FAZER
void apaga(int,int );      // Apaga a posição do márioOK
void posiciona_mario(int, int);  // Imprime o mário OK
void imprime_mario(int, int);      // MAIS OU MENOS
void imprime_donk1(int, int);      // MAIS OU MENOS
void imprime_donk2(int, int);      // MAIS OU MENOS
void imprime_barril_m(int, int);    // MAIS OU MENOS
void imprime_barril_e(int, int);    // MAIS OU MENOS
void imprime_princesa(int, int);   // MAIS OU MENOS
void imprime_escOK(int, int);      // MAIS OU MENOS
void imprime_escQ(int, int);       // MAIS OU MENOS
void imprime_escFIM(int, int);     // MAIS OU MENOS
void imprime_rampadir(int, int);   // MAIS OU MENOS
void imprime_rampaesq(int, int);   // MAIS OU MENOS
void imprime_superficie(int, int); // MAIS OU MENOS // mais ou menos
JOGO novo_jogo(TIPO_FASE[],int); //a fazer
void jogo(JOGO);
CONTROLE mapeia_fase(JOGO*, int,int);
int tempo(clock_t,clock_t);
int testa_morte_queda(int,int,JOGO);
void salva_jogo(JOGO);
JOGO carrega_jogo();
JOGO carrega_mapa();
int testa_vit_ou_der(CONTROLE, int, int,char);
int controle_jogo(JOGO, TIPO_FASE []);
void gera_tipo_fase(CONTROLE,int *,JOGO *);
void cor_escadas(int);
void prepara_barril(JOGO*);
CONTROLE escreve_espelho(CONTROLE, int,int,char);
CONTROLE apaga_espelho(CONTROLE, int,int );
void joga_barril(JOGO*);
int move_barril(JOGO*,int );
CONTROLE testa_direita_barril(CONTROLE, int *, int *,int*,char*);
CONTROLE testa_esquerda_barril(CONTROLE, int *, int *,int*,char*);
int testa_baixo_barril(CONTROLE, int, int );
int testa_descida_barril(int);
CONTROLE desce_barril(CONTROLE, int *, int *,int*,char*);
int habilita_movimento(int, clock_t *, char );
int testar_fim(CONTROLE , int , int  );

//######################5-MAIN############################//

int main()
{
    TIPO_FASE vetorobjetos[NUMMAXOBJ];  // inicializa vetor que irá receber os dados do fase.bin
    JOGO controle_geral;  // inicialização do vetor de controle
    int controle;
    do
    {
        controle=controle_jogo(controle_geral, vetorobjetos);
    }
    while(controle!=SAIR);
    return 0;
}

int controle_jogo(JOGO controle_geral, TIPO_FASE vetorobjetos[])  // função recursiva multipla, eu chomo um cara que chma outro e que me chma
{
    int iOpcao,score_atual,score_max,indfor,num_objetos;//inicialização de variaveis de controle,score e indice do for de inicialização
    for (indfor=0; indfor<NUMMAXOBJ; indfor++) //  garante que não há lixo no campo tipo do TIPO_FASE
        vetorobjetos[indfor].tipo='Z';
    formatprompt(); // seta tamanho e lingua
    num_objetos=ler_bin(vetorobjetos); // chama leitura do binário, função que retorna o número de objetos do binário
    iOpcao=mainMenu(); // chama a rotina do menu principal, que retorna a opção selecionada pelo usuário.
    int flag_de_chamada;
    switch(iOpcao)  // teste da opção
    {
    case NOVOJOGO :
        controle_geral=novo_jogo(vetorobjetos,num_objetos);
        jogo(controle_geral);
        break;
    case CONTINUARJOGO :
        controle_geral=carrega_mapa();
        controle_geral=carrega_jogo(controle_geral);
        jogo(controle_geral);
        break;
    case SAIR:
        break;
    }
    return iOpcao;
}
//######################6-FUNÇÕES OK############################//

int mainMenu() // Menu principal do jogo
{
    int x =24, y[] = {27, 31, 35,39};   // coluna e linhas para exibir seta de opcao do menu
    int iIndicaOpcao = 0, saida = FALSE;    // contador índice da seta, booleano sair para sair do menu
    /* #ifdef DEBUG
    int i;
    for (i=1;i<61;i++){printf("%d",i%10);};
    #endif // DEBUG*/
    imprime_tela_incial();  // tela de apresentaçao do jogo

    do // Faz ao menos uma vez
    {
        gotoxy(x, y[iIndicaOpcao]); // Move o cursor para (x, y[opcao])
        printf(">"); // Imprime a seta
        switch(setas())
        {
        case CIMA:
            if(iIndicaOpcao != 0) // Caso o usuário aperte direcional para cima
            {
                // Se o opcao não estiver na primeira posição
                gotoxy(x, y[iIndicaOpcao]);
                printf(" "); // Apaga a seta anterior
                iIndicaOpcao--; // Decrementa o contador
            }
            else if(iIndicaOpcao == 0)
            {
                // Se o contador estiver na primeira posição
                gotoxy(x, y[iIndicaOpcao]);
                printf(" "); // Apaga a seta anterior
                iIndicaOpcao = 3; // Define contador como 2 (última posição na tela)
            }
            break;

        case BAIXO:
            if(iIndicaOpcao != 3) // Caso o usuário aperte direcional para baixo
            {
                // Se o contador não estiver na última posição
                gotoxy(x, y[iIndicaOpcao]);
                printf(" "); // Apaga a seta anterior
                iIndicaOpcao++; // Incrementa o contador
            }
            else if(iIndicaOpcao == 3)
            {
                // Se o contador estiver na última posição
                gotoxy(x, y[iIndicaOpcao]);
                printf(" "); // Apaga a seta anterior
                iIndicaOpcao = 0; // Define o contador como 0 (primeira posição na tela)
            }
            break;
        case SPACEBAR:
        case ENTER:
            if (iIndicaOpcao==2)
            {
                imprime_instrucoes();
            }
            else
            {
                saida = TRUE;
            } // Se o usuário teclar ENTER, sai do loop
            break;

        case ESC:
            if(iIndicaOpcao != 3) // Se o usuário teclar ESC (No caso seria um atalho para sair do programa rapidamente)
            {
                // Se o contador for diferente de 2
                gotoxy(x, y[iIndicaOpcao]);
                printf(" ");
                iIndicaOpcao = 3; // Move a seta para a última posição
            }
            else return SAIR;
            break;
        }

        Beep(500, 40); // B E E P

    }
    while(!saida);   // Enquanto "não sair"
    return iIndicaOpcao;
}

int ler_bin(TIPO_FASE arrayobj[])
{
    TIPO_FASE buffer;
    FILE *fase;
    int contador=0;

    fase=fopen("fase.bin","rb");
    if (!fase)
    {
        printf("Erro ao carregar a fase, veja se o arquivo fase.bin existe");
    }
    else
    {
        while(!feof(fase))
        {
            fread(&buffer,sizeof(TIPO_FASE),1,fase);
            arrayobj[contador]=buffer;  // aqui de fato é feito o armazenamento de dados
            contador++;
        }
    }
    fclose(fase);
    return contador;
}

void formatprompt()
{
    // Formatação do prompt
    setlocale(LC_ALL, "Portuguese"); // Língua para português  //prompt em português para acentos e afins
    system("title Donkey Kong"); // Muda nome do prompt
    system("color 0C");                             // Cor normal do prompt
    system("mode 60, 48");                           // Modo para não exceder o buffer
    SMALL_RECT WinRect = {0, 0, X_MAX, Y_MAX};       // Formata o tamanho do prompt
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, WinSize);

    hide_cursor();

}

JOGO novo_jogo(TIPO_FASE array_obj[],int limite)
{
    system("cls");
    JOGO geral;
    int i;
    for (i=0; i<limite; i++)geral.vetor_objetos[i]=array_obj[i];
    geral.vidas=VIDAS_INICIAIS;
    geral.score_atual=SCORE_INICIAL;
    geral.score_max=SCORE_INICIAL;
    geral.num_obj=limite;
    imprime_fase(array_obj,geral.num_obj,geral.vidas);
    geral.espelho_fixo=mapeia_fase(&geral,limite,NOVOJOGO);
    return geral;
}

int tempo(clock_t c0, clock_t c1)
{
    double runtime_diff_ms;
    runtime_diff_ms= ((c1 - c0)*100)/ (CLOCKS_PER_SEC);
    int retorno=(int)runtime_diff_ms;
    return retorno;
}

int habilita_movimento(int flag_teste, clock_t *relogio1 ,char atividade)
{
    int  iTempoAtividade, tempodecorrido;
    clock_t auxiliar =*relogio1;
    clock_t relogio2 ;  // pegue o relogio atual da maquina
    if (flag_teste!=TRUE)        // avaliar tempo se flag nao foi verdadeiro
    {
        relogio2      =clock();
        tempodecorrido=tempo(auxiliar,relogio2);
        // system("pause");
        switch(atividade)
        {
        case 'Z' :
            iTempoAtividade=GRAVIDADE;
            break;
        case 'V' :
            iTempoAtividade=VEL_GERA_BARRIL;
            break;
        case 'B' :
            iTempoAtividade=VEL_BARRIL;
            break;
        case 'M' :
            iTempoAtividade=VEL_MARIO;
            break;
        case 'Ç' :
            iTempoAtividade=ATUALIZA_SCORE;
            break;
        }
       //LIXOAAAAAAAAAAAAA printf("%d",tempodecorrido);
        if (tempodecorrido>=iTempoAtividade)   // se esgotou o tempo de espera dessa atividade, habilitar
        {
            flag_teste=TRUE;     // avisar que habilitou o teste passado
            *relogio1=relogio2;  // guardar a ultima hora em que testou

        }
    }
    return flag_teste;
}

void jogo(JOGO copia_controle)  //ok
{
    int condition = JOGANDO;  // inicia jogando
    int eh_valido=0;
    int flag_mario=TRUE;     // deixamos tudo com permissão logo de cara
    int flag_barril=TRUE;
    int flag_gravidade=TRUE;
    int flag_altera_score=TRUE;
    int flag_gera_barril=TRUE;
    clock_t tempo_mario=clock();         // inicializamos os tempos de todo mundo
    clock_t tempo_score=clock();
    clock_t tempo_barril=clock();
    clock_t tempo_gravidade=clock();
    clock_t tempo_gera_barril=clock();
    copia_controle.conta_barril=0; // inicializamos o contador dos barris
    int coord_x =copia_controle.mario.coluna_inicial;// auxiliar
    int coord_y =copia_controle.mario.linha_inicial; // auxiliar
    gotoxy(0,-1);
#ifdef DEBUG
    FILE *aa;
    int i,j;
    aa=fopen("pqmorro.txt","w");
    for (i=0; i<Y_MAX_ESPELHO; i++)
        for(j=0; j<X_MAX_ESPELHO; j++)
            fputc(copia_controle.espelho_fixo.controle[i][j],aa);
    fclose(aa);

#endif // DEBUG
    int indice_b;
    char key='z';
    char reposicao='t';
    int deixa_cair=0,barril_pronto=FALSE;
    printf("SCORE / SCORE MAX %d / %d", copia_controle.score_atual,copia_controle.score_max);
    int flag_pausa=0;
    while(condition != SAIR && condition != VITORIA && condition != DERROTA)
    {
        flag_altera_score= habilita_movimento(flag_altera_score,&tempo_score,'Ç' );
        flag_barril=habilita_movimento(flag_barril,&tempo_barril,'B' );
        flag_gravidade=habilita_movimento(flag_gravidade,&tempo_gravidade,'Z');
        flag_mario=habilita_movimento(flag_mario,&tempo_mario,'M' );
        flag_gera_barril=habilita_movimento(flag_gera_barril,&tempo_gera_barril,'V' ); // pq V, pq eu quis auehuauheauaehau


        if (flag_altera_score==TRUE)  // se pode alterar, adivinha , altera
        {
            copia_controle.score_atual=copia_controle.score_atual-10;  // perdeu tempo = perdeu pontos
            gotoxy(0,-1); // menos dois pois estamos sempre somando dois na função gotoxt para facilitar as impressões;
            printf("SCORE / SCORE MAX %4d / %4d", copia_controle.score_atual,copia_controle.score_max);
            flag_altera_score=FALSE;
        }

        if (flag_gera_barril==TRUE && copia_controle.conta_barril<MAX_BARRIL_M)
        {
            // se pode gerar ...
            if (!barril_pronto)  // se não preparou, prepare, senao jogue
            {
                prepara_barril(&copia_controle);
                barril_pronto=TRUE;              // barril sera jogado no proximo ciclo
            }
            else
            {
                joga_barril(&copia_controle);
                barril_pronto=FALSE;            //  fazer novo barril no proximo ciclo
            }
            flag_gera_barril=FALSE;  // liga espera de tempo para geração do proximo
        }

        if (flag_pausa==TRUE)   //acionado ao retornar da pausa ou
        {
            gotoxy(0,-1); // menos dois pois estamos sempre somando dois na função gotoxt para facilitar as impressões;
            printf("SCORE / SCORE MAX %4d / %4d", copia_controle.score_atual,copia_controle.score_max);
            flag_pausa=0;
        }

        if (flag_gravidade==TRUE)  //se podae msm atuar a gravidade (frase estranha);
        {
            coord_x=copia_controle.mario.coluna_inicial;
            coord_y=copia_controle.mario.linha_inicial;
            copia_controle.espelho_fixo=testa_queda((copia_controle.espelho_fixo),&coord_x,&coord_y,&eh_valido,&reposicao);
            if(eh_valido) //mario caindo
            {
                apaga((copia_controle.mario.coluna_inicial),(copia_controle.mario.linha_inicial));
                posiciona_mario(coord_x,coord_y);
                copia_controle.mario.coluna_inicial=coord_x;
                copia_controle.mario.linha_inicial=coord_y;
            }

            // printf("%d",copia_controle.conta_barril);
            //system("pause");
             condition=testa_morte_queda(coord_y,condition,copia_controle);  // atualiza condicao de jogo de acordo com o movimento da gravidade
             flag_gravidade=FALSE;
        }

        if (flag_mario==TRUE && kbhit()) // se pode mover, adivinha se move{
        {
            key=getch();                                // descubra a tecla escolhida
            condition=move_mario(&copia_controle,key);  // retorna situacao apos movimento
            flag_mario=FALSE;                           // ja moveu
        }

        if(flag_barril==TRUE && copia_controle.conta_barril>0)
        {
            if (copia_controle.conta_barril>0){
                for(indice_b=0;indice_b<=copia_controle.conta_barril-1;indice_b++)
                condition=move_barril(&copia_controle,indice_b);
            }
            flag_barril=FALSE;
        }
       // condition=testa_morte_queda(coord_y,condition,copia_controle);  // atualiza condicao de jogo de acordo com o movimento da gravidade
        switch(condition)
        {

        case JOGANDO:

            break;
        case DERROTA:
            if(copia_controle.vidas == 0)
            {
                derrota(copia_controle);
            }
            else
            {
                gotoxy(0,0);
                // copia_controle_jogo.vidas=vidas;
                (copia_controle.vidas)--;  // diminui uma vida
                gotoxy(0,0);
                apaga(coord_x,coord_y);
                imprime_fase(copia_controle.vetor_objetos, copia_controle.num_obj,copia_controle.vidas);
                copia_controle.mario.coluna_inicial= copia_controle.mario_x_origem;
                copia_controle.mario.linha_inicial= copia_controle.mario_y_origem;

                gotoxy(0,22);
                condition= JOGANDO;
               // flag_pausa=1;
                copia_controle.score_atual=copia_controle.score_atual-200;
                gotoxy(0,-1); // menos dois pois estamos sempre somando dois na função gotoxt para facilitar as impressões;
                printf("SCORE / SCORE MAX %4d / %4d", copia_controle.score_atual,copia_controle.score_max);
            }
            break;
        case VITORIA:
            vitoria(copia_controle);
            break;
        case PAUSE:
            condition=menu_pausa(copia_controle);
            system("cls");
            imprime_fase(copia_controle.vetor_objetos, copia_controle.num_obj,copia_controle.vidas);
            apaga(copia_controle.mario_x_origem,copia_controle.mario_y_origem); // para apagar a primeira posição do mario
            posiciona_mario(copia_controle.mario.coluna_inicial,copia_controle.mario.linha_inicial);// somente reaproveitamento do struct para guar as posições de jogo
           // flag_pausa=1;
            gotoxy(0,-1); // menos dois pois estamos sempre somando dois na função gotoxt para facilitar as impressões;
            printf("SCORE / SCORE MAX %4d / %4d", copia_controle.score_atual,copia_controle.score_max);
            break;
        }

    }

    return 0;
}

int testa_morte_queda(int y,int condition, JOGO teste)
{
    gotoxy(0,6);
    printf("%c",teste.espelho_fixo.controle[teste.mario.linha_inicial+Y_PDR][teste.mario.coluna_inicial]);
    // system("pause");
    if (y==44
            || teste.espelho_fixo.controle[teste.mario.linha_inicial+Y_PDR][teste.mario.coluna_inicial]== 'K'  //bateu no kong
            || teste.espelho_fixo.controle[teste.mario.linha_inicial+Y_PDR][teste.mario.coluna_inicial+1]== 'K'
            || teste.espelho_fixo.controle[teste.mario.linha_inicial+Y_PDR][teste.mario.coluna_inicial+2]== 'K'
            || teste.espelho_fixo.controle[teste.mario.linha_inicial+Y_PDR][teste.mario.coluna_inicial]== 'B'  // bateu no barril
            || teste.espelho_fixo.controle[teste.mario.linha_inicial+Y_PDR][teste.mario.coluna_inicial+1]== 'B'
            || teste.espelho_fixo.controle[teste.mario.linha_inicial+Y_PDR][teste.mario.coluna_inicial+2]== 'B')
    {
        return DERROTA; // MORTE
    }
    else return condition;
}

CONTROLE testa_cima(CONTROLE posicao, int *x, int *y,int *flag,char *restaura)
{
    int linha,coluna;
    coluna=*x;
    linha=*y;
    int bPodeSubir=FALSE;
    if (    (     posicao.controle[linha-1][coluna]   == 'E'   // todo corpo de escada acima de mim //  menos um pois é o centro do objeto , menos 1 pois quero ver se posso subir
               && posicao.controle[linha-1][coluna+1] == 'E'
               && posicao.controle[linha-1][coluna+2] == 'E'
            )  || posicao.controle[linha-1][coluna]   == 'H'   // topo de escada acima de mim (ainda estou subindo)
               || posicao.controle[linha+1][coluna]   == 'H')  // topo de escada nos meus pes (nao terminei de subir)
    {
           bPodeSubir=TRUE;
    }

    if (bPodeSubir) {
       *restaura=posicao.controle[linha-1][coluna];
        linha--;
        *x=coluna;
        *y=linha;
        *flag=1;  // movimento valido
    }
    else
        *flag=testar_fim(posicao,(coluna),linha-1);  // verifique o que esta acima
}

CONTROLE testa_baixo(CONTROLE posicao, int *x, int *y,int *flag,char *restaura)   //ok
{
    int linha,coluna;
    coluna=*x;
    linha=*y;
    int bPodeDescer=FALSE;
    if (   posicao.controle[linha+2][coluna]   == 'S'  // superficie nao autoriza descer
        || posicao.controle[linha+2][coluna+1] == 'S'
        || posicao.controle[linha+2][coluna+2] == 'S'
        || posicao.controle[linha+2][coluna]   == 'Q' // escada quebrada nao autoriza descer
        || posicao.controle[linha+2][coluna+1] == 'Q'
        || posicao.controle[linha+2][coluna+2] == 'Q'
        )
    {
        bPodeDescer=FALSE;
    }
    else if (    posicao.controle[linha+2][coluna]   == 'H'  // desce pelo topo de escada
              || posicao.controle[linha+2][coluna+1] == 'H'
              || posicao.controle[linha+2][coluna+2] == 'H'
              || posicao.controle[linha+2][coluna]   == 'E'  // desce pelo corpo de escada
              || posicao.controle[linha+2][coluna+1] == 'E'
              || posicao.controle[linha+2][coluna+2] == 'E')
    {
          bPodeDescer=TRUE;
    }
    if (bPodeDescer) {
        *restaura=posicao.controle[linha+2][coluna];
        linha++;
        *x=coluna;
        *y=linha;
        *flag=1;
    }
    else
        *flag=testar_fim(posicao,(coluna),linha+2);  // verifique o que esta abaixo
}

CONTROLE testa_direita(CONTROLE posicao, int *x, int *y, int *flag,char *restaura)  //ok
{
    int linha,coluna;
    coluna=*x;
    linha=*y;
    int bPodeMover=FALSE;
    if (   posicao.controle[linha+2][coluna]   == 'H'  // tem escada abaixo
        || posicao.controle[linha+2][coluna]   == 'S'  // tem superficie abaixo
        || posicao.controle[linha+2][coluna+1] == 'S'
        || posicao.controle[linha+2][coluna+2] == 'S'
        || posicao.controle[linha+2][coluna]   == 'F'  // tem rampa a direita para subir
        || posicao.controle[linha+2][coluna+2] == 'F'
        || posicao.controle[linha+2][coluna+1] == 'G')  // era 2
    {

        if  (  posicao.controle[linha][coluna+3]   == ' '
             &&posicao.controle[linha+1][coluna+3] == ' ')  // nada a minha direita
        {
            bPodeMover=TRUE;
        }
        else
        {
            if (posicao.controle[linha][coluna+3] == 'E'
                && posicao.controle[linha+1][coluna+3] == 'E')
            {
                *restaura='E';
                bPodeMover=TRUE;
            }
            else if (posicao.controle[linha+1][coluna+3] == 'F')   // rampa a direita subo
            {
                linha--;
                bPodeMover=TRUE;
            }
            else if (posicao.controle[linha+3][coluna+1] == 'G')   // rampa a esquerda desco
            {
                linha++;  //acho que eh mais
                bPodeMover=TRUE;
            }
        }

    }
    else if (posicao.controle[linha+3][coluna+1] == 'G'
             || posicao.controle[linha+3][coluna+1] == 'S'
             || posicao.controle[linha+3][coluna+1] == 'H'){
        if (posicao.controle[linha-1][coluna] !='E'){
        linha++;              // desce, aumentando a linha
        bPodeMover=TRUE;
        }     // pode mover
    }    // rampa dir

     if (bPodeMover)
        {
            coluna++;
            *x=coluna;
            *y=linha;
            *flag=1;
        }
        else
            *flag=testar_fim(posicao,(coluna+3),linha);  // verifique o que esta ao lado


}

CONTROLE testa_esquerda(CONTROLE posicao, int *x, int *y,int *flag,char *restaura)
{
    int linha,coluna;
    coluna=*x;
    linha=*y;
    int bPodeMover=FALSE;
    // primeiro veja se a esquerda não eh problema
    if (   posicao.controle[linha+3][coluna+2] == 'H'    // escada abaixo de mim, a esquerda
        || posicao.controle[linha+2][coluna  ] == 'S'    // superficie  // verifique se a esquerda existe uma estrutura que permite mover
        || posicao.controle[linha+2][coluna+2] == 'S'    // superficie
        || posicao.controle[linha+2][coluna  ] == 'G'    // rampa esq
        || posicao.controle[linha+2][coluna+2] == 'G'    // rampa esq
        || posicao.controle[linha+2][coluna+1] == 'F')    // rampa dir  ERA 2
    {

        if(posicao.controle[linha+1][coluna-1] == ' '
                &&posicao.controle[linha+1][coluna-1] == ' ')   // tudo limpo a esquerda
        {
            bPodeMover=TRUE;

        }
        else
        {
            if (posicao.controle[linha][coluna-1] == 'E'
               && posicao.controle[linha+1][coluna-1] == 'E')   // há uma escada a esquerda
            {
                *restaura='E';      // precisa restaurar o desenho
                bPodeMover=TRUE;    // pode mover
            }
            else if (posicao.controle[linha+1][coluna-1] == 'G')      // há uma rampa a esquerda, suba
            {
                linha--;              // suba, diminuindo a linha
                bPodeMover=TRUE;      // pode mover
            }
            else if (posicao.controle[linha+3][coluna-1] == 'F')      // há uma rampa a direita, desça
            {
                linha++;              // desce, aumentando a linha
                bPodeMover=TRUE;      // pode mover
            }
        }

    }
    else if (posicao.controle[linha+2][coluna+2] == 'F'){
        linha++;              // desce, aumentando a linha
        bPodeMover=TRUE;      // pode mover
    }    // rampa dir  ERA 2
    if (bPodeMover)
        {
            coluna--;    // vá para a esquerda
            *x=coluna;   // modifique as coordenadas do objeto
            *y=linha;    // modifique as coordenadas do objeto
            *flag=1;     // movimento deu certo
        }
    else
        *flag=testar_fim(posicao,(coluna-1),linha);
    return posicao;
}

int testa_vit_ou_der(CONTROLE posicao, int x, int y,char teste)
{
    int linha,coluna;
    coluna=x;
    linha=y;
    int flag_controle=0;
    if (posicao.controle[linha+Y_PDR][coluna]== teste // caso atinja  por cima
            ||  posicao.controle[linha+Y_PDR][coluna+1]== teste
            ||  posicao.controle[linha+Y_PDR][coluna+2]== teste
            ||  posicao.controle[linha][coluna]== teste // caso atinja pela esquerda
            ||  posicao.controle[linha+1][coluna]== teste
            ||  posicao.controle[linha][coluna+X_PDR]== teste // caso atinja pela direita
            ||  posicao.controle[linha+1][coluna+X_PDR]== teste
            ||  posicao.controle[linha-1][coluna]== teste // caso atinja   por baixo
            ||  posicao.controle[linha-1][coluna+1]== teste
            ||  posicao.controle[linha-1][coluna+2]== teste)
        flag_controle=TRUE;
    if (flag_controle)
    {
        switch(teste)
        {
        case 'K':
        case 'B':
            return DERROTA;
            break;
        case 'P':
            return VITORIA;
            break;
        }
    }
    else return JOGANDO;
}



int testar_fim(CONTROLE posicao, int coluna, int linha )
{
      int resultado[3];
      int retorno;
      resultado[0]=testa_vit_ou_der(posicao,coluna,linha,'B');  // bateu num barril
      resultado[1]=testa_vit_ou_der(posicao,coluna,linha,'K');  // bateu no kong
      resultado[2]=testa_vit_ou_der(posicao,coluna,linha,'P');  // bateu na princesa
      if (resultado[0]==JOGANDO && resultado[1]==JOGANDO && resultado[2]==JOGANDO) { // nao bateu em ninguem
          retorno=JOGANDO;  // prosseguir
         }
      else if (resultado[2]==VITORIA) {  // ganha se bateu na princesa
           retorno=VITORIA;
         }
      else retorno=DERROTA;
      return retorno;
 }

CONTROLE testa_queda(CONTROLE posicao, int *x, int *y,int *flag,char *restaura)
{

    int linha,coluna;
    coluna=*x;
    linha=*y;

    if (posicao.controle[linha+Y_PDR][coluna] ==' '
            && posicao.controle[linha+Y_PDR][coluna+1] ==' '
            && posicao.controle[linha+Y_PDR][coluna+2] ==' ')
    {
        *restaura=posicao.controle[linha-1][coluna];
        linha++;
        *x=coluna;
        *y=linha;
        *flag=1;
        printf("aaaa");
    }

    else *flag=0;
    return posicao;
}

//CONTROLE  pode_pulo((CONTROLE posicao, int *x, int *y,int *flag,char *restaura))

CONTROLE restaura_escada(int sentido,int x,int y,CONTROLE a)
{

    char teste;
    int testa=sentido;
    switch(testa)
    {
    case PCIM:
        if ((y%2)==1)   //ok
        {
            y=y+1;
            teste=a.save[y/2][x/3];
            if (teste=='E')
            {
                imprime_escOK(x,y);
                a=escreve_espelho(a,x,y,teste);
            }
            else if (teste=='H')
            {
                imprime_escFIM(x,y);
                a=escreve_espelho(a,x,y,teste);
            }
        }
        else
        {
            teste=a.save[(y+2)/2][x/3];
            if (teste=='E')
            {
                imprime_escOK(x,y+2);
                a=escreve_espelho(a,x,y+2,teste);
            }
            else if (teste=='H')
            {
                imprime_escFIM(x,y+2);
                a=escreve_espelho(a,x,y+2,teste);
            }
        }
        break ;
    case  PDIR:
        if(x%3==0)
        {
            teste=a.save[y/2][(x-3)/3];
            if (teste=='E')
            {
                imprime_escOK(x-3,y);
                a=escreve_espelho(a,x-3,y,teste);
            }
        }
        else if(x%3==1)
        {
            teste=a.save[y/2][(x-1)/3];
            if (teste=='E')
            {
                imprime_escOK(x-1,y);
                a=escreve_espelho(a,x-1,y,teste);
            }
        }
        else
        {
            teste=a.save[y/2][(x-2)/3];
            if (teste=='E')
            {
                imprime_escOK(x-2,y);
                a=escreve_espelho(a,x-2,y,teste);
            }
        }
        break;
    case PESQ:
        if(x%3==0)
        {
            teste=a.save[y/2][(x+3)/3];
            if (teste=='E')
            {
                imprime_escOK(x+3,y);
                a=escreve_espelho(a,x+3,y,teste);
            }
        }
        else if(x%3==1)
        {
            teste=a.save[y/2][(x+2)/3];
            if (teste=='E')
            {
                imprime_escOK(x+2,y);
                a=escreve_espelho(a,x+2,y,teste);
            }
        }
        else
        {
            teste=a.save[y/2][(x+1)/3];
            if (teste=='E')
            {
                imprime_escOK(x+1,y);
                a=escreve_espelho(a,x+1,y,teste);
            }
        }
        break;
    case PBAI:
        if ((y%2)==1)   //ok
        {
            y=y-1;
            teste=a.save[y/2][x/3];
            if (teste=='E')
            {
                imprime_escOK(x,y);
                a=escreve_espelho(a,x,y,teste);
            }
            else if (teste=='H')
            {
                imprime_escFIM(x,y);
                a=escreve_espelho(a,x,y,teste);
            }
        }
        else
        {
            teste=a.save[(y-2)/2][x/3];
            if (teste=='E')
            {
                imprime_escOK(x,y-2);
                a=escreve_espelho(a,x,y-2,teste);
            }
            else if (teste=='H')
            {
                imprime_escFIM(x,y-2);
                a=escreve_espelho(a,x,y-2,teste);
            }
            else if (teste=='Q')
            {
                imprime_escQ(x,y-2);
                a=escreve_espelho(a,x,y-2,teste);
            }
        }

        break;
    }
    return a;
}

int move_mario(JOGO *parametros, char key)
{
    int coord_x= parametros->mario.coluna_inicial;
    int coord_y= parametros->mario.linha_inicial;
    int eh_valido=0;
    char restaura_mapa='Z';
    clock_t inicial;
    //int barril=FALSE,cont_tempo=0;
    CONTROLE interno = parametros->espelho_fixo;
    text_color(LIGHT_RED);
    key = toupper(key);   // char case sempre maiuscula
    switch(key)
    {
    case 'A':
        interno=testa_esquerda(interno,&coord_x,&coord_y,&eh_valido,&restaura_mapa);
        gotoxy(0,1);
        switch(eh_valido)
        {
        case 1:  // PODE MOVER
            parametros->mario.velocidade=PESQ;
            apaga((parametros->mario.coluna_inicial),(parametros->mario.linha_inicial)); // apaga mario na tela

             parametros->espelho_fixo=restaura_escada(PESQ,coord_x,coord_y,parametros->espelho_fixo);  // restaura escada

            posiciona_mario(coord_x,coord_y);                                            // mostra mario na tela
            parametros->mario.coluna_inicial=coord_x;  // guarda nova coordenada mario
            parametros->mario.linha_inicial=coord_y;   // guarda nova coordenada mario
            break;
        case DERROTA:
        case VITORIA:
            return eh_valido;
            break;
//        case VITORIA:
//            return VITORIA;
//            break;
        }
        break;

    case 'D':
        interno=testa_direita(interno,&coord_x,&coord_y,&eh_valido,&restaura_mapa);
        switch(eh_valido)
        {
        case 1:
            apaga((parametros->mario.coluna_inicial),(parametros->mario.linha_inicial));

            parametros->espelho_fixo=restaura_escada(PDIR,coord_x,coord_y,parametros->espelho_fixo);

            posiciona_mario(coord_x,coord_y);
            parametros->mario.coluna_inicial=coord_x;
            parametros->mario.linha_inicial=coord_y;
            break;
        case DERROTA:
            return DERROTA;
            break;
        case VITORIA:
            return VITORIA;
            break;
        }
        break;

    case 'W':
        interno=testa_cima(interno,&coord_x,&coord_y,&eh_valido,&restaura_mapa);
        switch(eh_valido)
        {
        case 1:
            gotoxy(0,0);

            apaga((parametros->mario.coluna_inicial),(parametros->mario.linha_inicial));

            parametros->espelho_fixo=restaura_escada(PCIM,coord_x,coord_y,parametros->espelho_fixo);

            posiciona_mario(coord_x,coord_y);
            parametros->mario.coluna_inicial=coord_x;
            parametros->mario.linha_inicial=coord_y;
            break;
        case DERROTA:
            return DERROTA;
            break;
        case VITORIA:
            return VITORIA;
            break;
        }
        gotoxy(0,0);
        break;

    case 'S':
        interno=testa_baixo(interno,&coord_x,&coord_y,&eh_valido,&restaura_mapa);
        switch(eh_valido)
        {
        case 1:
            apaga((parametros->mario.coluna_inicial),(parametros->mario.linha_inicial));
            parametros->espelho_fixo=restaura_escada(PBAI,coord_x,coord_y,parametros->espelho_fixo);
            gotoxy(0,0);
            imprime_mario(coord_x,coord_y);
            parametros->mario.coluna_inicial=coord_x;
            parametros->mario.linha_inicial=coord_y;
            break;
        case DERROTA:
            return DERROTA;
            break;
        case VITORIA:
            return VITORIA;

            gotoxy(0,0);
        }
        break;
    case  'P':
        return PAUSE;
    case SPACEBAR:
        break;
    }

return JOGANDO;

}

void apaga(int x,int y)  //util a fu
{

    gotoxy(x, y);
    printf("   ");
    gotoxy(x, (y+1));
    printf("   ");
}

void posiciona_mario(int x,int y)  // pode vir a ser descontinuada
{
    text_color(LIGHT_RED);
    gotoxy(x,y);
    printf("\\ô/");
    gotoxy(x, (y)+1);
    printf("/H\\");
    hide_cursor();
}

void vitoria(JOGO parametros)
{
    system("cls");
    text_color(LIGHT_AQUA);
    int c;
    FILE *vitoria;
    vitoria = fopen("vitoria.txt", "r");
    if (vitoria)
    {
        while ((c = getc(vitoria)) != EOF)
            putchar(c);
        fclose(vitoria);
    }
    gotoxy(5, 15);
    printf("Pontuação final: %d / Pontuação máxima: %d", parametros.score_atual, parametros.score_max);
    gotoxy(7, 17);
    printf("Pressione ESC para retornar ao menu. . .");
    while(c != ESC)
    {
        if(kbhit())
        {
            c=getch();
            if(c==ESC)
            {
                Beep(500, 40);
            }
        }
    }
}

void derrota(JOGO parametros)
{
    system("cls");
    text_color(BRIGHT_WHITE);
    int c;
    FILE *derrota;
    derrota = fopen("derrota.txt", "r");
    if (derrota)
    {
        while ((c = getc(derrota)) != EOF)
            putchar(c);
        fclose(derrota);
    }
    gotoxy(5, 15);
    printf("Pontuação final: %d / Pontuação máxima: %d", parametros.score_atual, parametros.score_max);
    gotoxy(7, 17);
    printf("Pressione ESC para retornar ao menu. . .");
    while(c != ESC)
    {
        if(kbhit())
        {
            c=getch();
            if(c==ESC)
            {
                Beep(500, 40);
            }
        }
    }
}

void hide_cursor() // Esconde o cursor default do prompt
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Esconde o Cursor do console
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void text_color(int ForgC) // Função para colorir o texto
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

void gotoxy (int x, int y)
{
    COORD coord = {0, 0};
    coord.X =x;
    coord.Y = y+2; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int setas()  // Controle pelas setas direcionais
{
    int valor_seta; // Pode ser os valores definidos no cabeçalho

    do
        valor_seta = getch(); // Continua pegando caracteres
    while   (valor_seta != CIMA
             && valor_seta != BAIXO
             && valor_seta != ESQUERDA
             && valor_seta != DIREITA
             && valor_seta != ENTER
             && valor_seta != ESC
             && valor_seta != SPACEBAR);

    return valor_seta; // Manda para o main a seta lida
}

void imprime_instrucoes()
{
    system("cls");
    text_color(LIGHT_GREEN);
    int c;
    FILE *info;
    info = fopen("menuinfo.txt", "r"); // agora se quiser trocar o menu é só trocar aqui dai o código fica menos poluído.
    // além disso agr é so tu escrever num txt normal sem ter que por aspas ou \n ou \\ para imprimir barras :)
    if (info)
    {
        while ((c = getc(info)) != EOF)
            putchar(c);
        fclose(info);
        getch();
    }
    else
    {
        printf("Erro ao apresentar as intruções, verifique a existencia do arquivo menuinfo.txt");
        printf("\nPressione qualquer tecla para retornar ao menu");
        getch();
    }
    imprime_tela_incial();
}

void imprime_tela_incial()
{
    text_color(LIGHT_RED);
    system("cls");
    int c;
    FILE *menu;
    menu = fopen("menu.txt", "r");
    if (menu)
    {
        while ((c = getc(menu)) != EOF)
            putchar(c);
        fclose(menu);
    }
}

void imprime_mario(int x, int y)   // observação, não sei se não é melhor fazer como tu tava fazendo
{
    char M[Y_PDR][X_PDR]= {{'\\','ô','/'},{'/','H','\\'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            printf("%c", M[i][j]);
        }
    }
}

void imprime_donk1(int x, int y)
{
    char D[Y_PDR][X_PDR]= {{'}','ô','{'},{'_','H','_'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            text_color(YELLOW);
            printf("%c", D[i][j]);
        }
    }
}

void imprime_donk2(int x, int y)
{
    char D[Y_PDR][X_PDR]= {{'\\','o','/'},{'/',' ','\\'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            text_color(YELLOW);
            printf("%c", D[i][j]);
        }
    }
}

void imprime_princesa(int x, int y)
{
    //  '\o/'
    //  '/=\'

    char P[Y_PDR][X_PDR]= {{'\\','o','/'},{'/','=','\\'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            text_color(LIGHT_PURPLE);
            printf("%c", P[i][j]);
        }
    }
}

void imprime_superficie(int x, int y)
{
    char S[Y_PDR][X_PDR]= {{'X','X','X'},{'X','X','X'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            text_color(LIGHT_RED);
            printf("%c", S[i][j]);
        }
    }
}

void imprime_escFIM(int x, int y)
{
    char H[Y_PDR][X_PDR]= {{'|','X','|'},{'|','-','|'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            cor_escadas(j);
            printf("%c", H[i][j]);
        }
    }
}

void imprime_escOK(int x, int y)
{
    char E[Y_PDR][X_PDR]= {{'|','-','|'},{'|','-','|'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            cor_escadas(j);
            printf("%c", E[i][j]);
        }
    }
}

void imprime_escQ(int x, int y)
{

    char Q[Y_PDR][X_PDR]= {{'|','-','|'},{' ','-','|'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            cor_escadas(j);
            printf("%c", Q[i][j]);
        }
    }
}

void imprime_barril_e(int x, int y)
{
    char B1[Y_PDR][X_PDR]= {{'/','^','\\'},{'\\','Z','/'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            text_color(GRAY);
            printf("%c", B1[i][j]);
        }
    }
}

void imprime_barril_m(int x, int y)
{
    char B2[Y_PDR][X_PDR]= {{'/','^','\\'},{'\\',' ','/'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR; j++)
        {
            text_color(GRAY);
            printf("%c", B2[i][j]);
        }
    }
}

void imprime_rampadir(int x, int y)
{
    char RD[Y_PDR][X_PDR*2]= {{' ',' ',' ','_','.','-'},{'_','.','-',' ',' ',' '}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR*2; j++)
        {
            text_color(LIGHT_RED);
            printf("%c", RD[i][j]);
        }
    }
}

void imprime_rampaesq(int x, int y)
{
    char RD[Y_PDR][X_PDR*2]= {{'-','.','_',' ',' ',' '},{' ',' ',' ','-','.','_'}};
    int i,j;
    for (i=0; i<Y_PDR; i++)
    {
        gotoxy(x,y+i);
        for (j=0; j<X_PDR*2; j++)
        {
            text_color(LIGHT_RED);
            printf("%c", RD[i][j]);
        }
    }
}

void cor_escadas(int a)
{
    if (a==1)text_color(GRAY);
    else
    {
        text_color(RED);
    }
}

void imprime_fase(TIPO_FASE vetor_objetos[], int  qtd_objetos,int vidas)
{
    int i;
    int x,y;
    for (i=0; i<qtd_objetos; i++)
    {
        switch(vetor_objetos[i].tipo)
        {

        case 'M':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_mario(x,y);
            break;
        case 'P':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_princesa(  x,y);
            break;
        case 'K':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_donk1(  x,y);
            break; // sim era para ser D mas no bin ta K, ok né
        case 'G':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_rampaesq(  x,y);
            break;
        case 'F':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_rampadir(  x,y);
            break;
        case 'S':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_superficie(  x,y);
            break;
        case 'E':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_escOK(  x,y);
            break;
        case 'Q':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_escQ( x,y);
            break;
        case 'H':
            x=(vetor_objetos[i].coluna_inicial)*3;
            y=(vetor_objetos[i].linha_inicial)*2;
            imprime_escFIM( x,y);
            break;
        case 'B':
            if( vetor_objetos[i].velocidade>0)
            {
                x=(vetor_objetos[i].coluna_inicial)*3;
                y=(vetor_objetos[i].linha_inicial)*2;
                imprime_barril_m(x,y);
            }// barril que se mexe
            else
            {
                x=(vetor_objetos[i].coluna_inicial)*3;
                y=(vetor_objetos[i].linha_inicial)*2;
                imprime_barril_e(x,y);
            }
            break;
        }//

    }

    gotoxy(0,-2); // menos dois pois estamos sempre somando dois na função gotoxt para facilitar as impressões;
    printf("VIDAS %d \n", vidas);

    //    printf("SCORE ATUAL/MAX: %d / %d",paraimpressao->score_atual, paraimpressao->score_max);
}

void preenche_espelho(CONTROLE *mapa,int x,int y, char obj)
{
    int i,j;
    if ( obj == 'F' )
    {
        for (i=y; i<y+2; i++)
            for  (j=x; j<x+3; j++)
            {
                if (i==y)mapa -> controle[i][j+3] = obj;
                else mapa -> controle[i][j] = obj;
            }
    }
    else if ( obj =='G')
    {
        for (i=y; i<y+2; i++)
            for  (j=x; j<x+3; j++)
            {
                if (i==y+1)mapa -> controle[i][j+3] = obj;
                else mapa -> controle[i][j] = obj;
            }
    }
    else
    {
        for (i=y; i<y+2; i++)
            for (j=x; j<x+3; j++)
                mapa->controle[i][j]=obj;
    }

}

CONTROLE mapeia_fase(JOGO *mapadojogo,int qtd_objetos, int flag)
{
    int i, x, y,i_linha,i_coluna;
    int indice_bM=0;
    CONTROLE mapa;
    int in,jn;
    for (i_linha=0; i_linha<Y_MAX_ESPELHO; i_linha++)
    {
        for (i_coluna=0; i_coluna<X_MAX_ESPELHO; i_coluna++)
        {
            if (i_coluna==(X_MAX_ESPELHO-1))mapa.controle[i_linha][i_coluna]='\n';
            else
                mapa.controle[i_linha][i_coluna]=' ';
        }
    }
    for(in=0; in<LINHAS_MAX; in++)
    {
        for(jn=0; jn<COLUNAS_MAX; jn++)
        {
            mapa.save[in][jn]= ' ';
            if (jn== (COLUNAS_MAX-1))mapa.save[in][jn]='\n';
        }
    }
    //printf("%c", mapa.controle[14][23]); // ate aqui tudo certo
    mapadojogo->num_obj=qtd_objetos;
    for (i=0; i<qtd_objetos; i++)
    {
        switch(mapadojogo->vetor_objetos[i].tipo)
        {
        case 'M':
            y = (mapadojogo->vetor_objetos[i].linha_inicial); // OBS: X = LINHA * 2, Y = COLUNA * 3 (x,y) são as coordenadas reais no prompt do C[0][0]
            x = (mapadojogo->vetor_objetos[i].coluna_inicial);
            if (flag!=CONTINUARJOGO)
            {
                mapadojogo->mario.coluna_inicial=x*3;
                mapadojogo->mario.linha_inicial=y*2;
            }
            mapadojogo->mario_x_origem=x*3;
            mapadojogo->mario_y_origem=y*2;
            mapa.save[y][x]='M';
            //preenche_espelho(&mapa,x,y,'M');
            break;
        case 'P':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'P');
            mapa.save[y][x]='P';
            break;
        case 'K':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'K');
            mapa.save[y][x]='K';
            mapadojogo->coluna_donk=x*3;
            mapadojogo->linha_donk=y*2;
            break; // sim era para ser D mas no bin ta K, ok né
        case 'G':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'G');
            mapa.save[y][x]='G';
            break;
        case 'F':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'F');
            mapa.save[y][x]='F';
            break;
        case 'S':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'S');
            mapa.save[y][x]='S';
            break;
        case 'E':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'E');
            mapa.save[y][x]='E';
            break;
        case 'Q':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'Q');
            mapa.save[y][x]='Q';
            break;
        case 'H':
            y=(mapadojogo->vetor_objetos[i].linha_inicial);
            x=(mapadojogo->vetor_objetos[i].coluna_inicial);
            preenche_espelho(&mapa,x*3,y*2,'H');
            mapa.save[y][x]='H';
            break;
        case 'B':
            if(mapadojogo->vetor_objetos[i].velocidade!=0)
            {  // barris moveis
                y=(mapadojogo->vetor_objetos[i].linha_inicial);
                x=(mapadojogo->vetor_objetos[i].coluna_inicial);
                mapadojogo->barril_movel[indice_bM].coluna_inicial=x*3;
                mapadojogo->barril_movel[indice_bM].linha_inicial=y*2;
                mapadojogo->barril_movel[indice_bM].velocidade=mapadojogo->vetor_objetos[i].velocidade;
                indice_bM++;
                mapa.save[y][x]='O';
               // mapadojogo->conta_barril=indice_bM;
            }// barril que se mexe
            else
                {
                y=(mapadojogo->vetor_objetos[i].linha_inicial);
                x=(mapadojogo->vetor_objetos[i].coluna_inicial);
                preenche_espelho(&mapa,x*3,y*2,'B');
                mapa.save[y][x]='B';
                }
            break;
        }

    }

    return mapa;
}

void ler_menu_pausa()
{
    system("cls");
    Beep(500, 40);
    text_color(AQUA);
    int c;
    FILE *info;
    info = fopen("pausa.txt", "r");
    if (info)
    {
        while ((c = getc(info)) != EOF)
            putchar(c);
        fclose(info);
    }
    else
    {
        system("cls");
        printf("Erro ao apresentar as intruções, verifique a existencia do arquivo pausa.txt");
        printf("\nPressione qualquer tecla para retornar ao jogo");
        getch();
    }
}

int menu_pausa(JOGO copia_controle)
{
    system("cls");
    int x =19, y[] = {19, 21, 23};
    int contador = 0, sair = FALSE; // Coordenadas da seta, contador índice da seta, booleano sair para sair do menu
    // text_color(RED); // Cor vermelha
    ler_menu_pausa();
    int key;
    do // Faz ao menos uma vez
    {
        gotoxy(x, y[contador]); // Move o cursor para (x, y[contador])
        printf(">"); // Imprime a seta
        key=getch(); // Não sei como resolver isso
        switch(key)
        {

        case 's':
            if(contador!=0)
            {
                gotoxy(x, y[contador]); // Move o cursor para (x, y[contador])
                printf(" ");
                contador=0;
                Beep(500, 40);
            }
            else
                salva_jogo(copia_controle); // Salva o jogo e mantém na tela de pause
            break;

        case 'p':
            if(contador!=1)
            {
                gotoxy(x, y[contador]); // Move o cursor para (x, y[contador])
                printf(" ");
                contador=1;
                Beep(500, 40);
            }
            else
                return JOGANDO; // Retorna JOGANDO
            break;

        case ESC:
            if(contador!=2)
            {
                gotoxy(x, y[contador]); // Move o cursor para (x, y[contador])
                printf(" ");
                contador=2;
                Beep(500, 40);
            }
            else
            {
                salva_jogo(copia_controle);
                //controle_jogo(copia_controle, copia_controle.vetor_objetos);
                return SAIR;
            }
            break;

        }



    }
    while(!sair);  // Enquanto "não sair"
}

void salva_jogo(JOGO mapa)
{

    FILE *jogosalvo;
    char nome_save[40+5]; // Nome de até 40 caracteres + ".txt\0"
    int i,j;
    gotoxy(21, 29);
    printf("Nome do save: ");
    gotoxy(16, 31);
    fflush(stdin);
    gets(nome_save);
    strcat(nome_save, ".txt"); // Concatena o nome digitado ao tipo do arquivo
    jogosalvo=fopen(nome_save, "w");
    for(i=0; i<LINHAS_MAX; i++)
    {
        for(j=0; j<COLUNAS_MAX; j++)
        {
            fputc(mapa.espelho_fixo.save[i][j],jogosalvo);
        }
    }
    fprintf(jogosalvo,"%d#%d#%d#%d",mapa.mario.coluna_inicial,mapa.mario.linha_inicial,mapa.score_atual,mapa.vidas); // (COLUNA,LINHA),score_atual,vidas => (linha, coluna)
    fclose(jogosalvo);
    gotoxy(21, 35);
    printf("Jogo salvo!");
}

JOGO carrega_mapa()
{
    FILE *load;
    char nome_load[40+5];
    int i,j;  //para o for
    JOGO loadgame;// meu retorno
    char *ptr; // strtok
    int numobjetos;
    gotoxy(15,23);
    printf("Nome do arquivo (sem extensão): ");
    gotoxy(15, 25);
    fflush(stdin);
    gets(nome_load);
    strcat(nome_load, ".txt");
    load=fopen(nome_load, "r");
    char stringao[30];
    if(!load)
    {
        gotoxy(3, 27);
        printf("Erro na leitura, o arquivo não existe na pasta do jogo");
    }
    else
    {
        for(i=0; i<LINHAS_MAX; i++)
        {
            for(j=0; j<COLUNAS_MAX; j++)
            {
                loadgame.espelho_fixo.save[i][j]=getc(load);
            }

        }
        // o numero xe bites deslocados é igual a matriz pequena mais \n , ver o tamnanho de um arqiivo para confirmar, menos  linha FINAL
        fseek(load,0,SEEK_CUR);
        fgets(stringao,30,load);
        printf("%s",stringao);
        // salvo como COLUNA#LINHA#score_atual#vidas
        ptr=strtok(stringao,"#");
        loadgame.mario.coluna_inicial=atoi(ptr);
        ptr=strtok(NULL,"#");
        loadgame.mario.linha_inicial=atoi(ptr);
        ptr=strtok(NULL,"#");
        loadgame.score_atual=atoi(ptr);
        ptr=strtok(NULL,"#");
        loadgame.vidas=atoi(ptr);
    }
    loadgame.score_max=SCORE_INICIAL;
    gera_tipo_fase(loadgame.espelho_fixo,&numobjetos,&loadgame);
    loadgame.num_obj=numobjetos;
    return loadgame;
}

void gera_tipo_fase(CONTROLE para_analise,int *qtdobjetos,JOGO *loadgame)
{
    TIPO_FASE vetor[MAX_OBJ];
    int contador=0;
    int in,jn;
    for(in=0; in<LINHAS_MAX; in++)
    {
        for(jn=0; jn<(COLUNAS_MAX-1); jn++) // -1 pois há o \n
        {
            if (para_analise.save[in][jn]!= ' ')
            {
                vetor[contador].tipo=para_analise.save[in][jn];
                vetor[contador].coluna_inicial=jn;
                vetor[contador].linha_inicial=in;
                loadgame->vetor_objetos[contador]=vetor[contador];
                contador++;
            }

        }
    }
    *qtdobjetos=contador;

}

JOGO carrega_jogo(JOGO carregado)
{
    CONTROLE antigo=carregado.espelho_fixo;
    system("cls");
    imprime_fase(carregado.vetor_objetos,carregado.num_obj,carregado.vidas);
    antigo=mapeia_fase(&carregado,carregado.num_obj,CONTINUARJOGO);
    carregado.espelho_fixo=antigo;
    apaga(carregado.mario_x_origem,carregado.mario_y_origem);
    posiciona_mario(carregado.mario.coluna_inicial,carregado.mario.linha_inicial);
    return carregado;
}


CONTROLE escreve_espelho(CONTROLE espelho_fixo, int coord_x,int coord_y,char para_imprimir)
{

    int i,j;
    j=coord_x;
    i=coord_y;
    for (i=0; i<Y_PDR; i++)
        for(j=0; j<X_PDR; j++)
            espelho_fixo.controle[i+coord_y][j+coord_x]=para_imprimir;
    return espelho_fixo;

}

CONTROLE apaga_espelho(CONTROLE espelho_fixo, int coord_x,int coord_y)
{
    int i,j;
    j=coord_x;
    i=coord_y;
    for (i=0; i<Y_PDR; i++)
        for(j=0; j<X_PDR; j++)
            espelho_fixo.controle[i+coord_y][j+coord_x]=' ';
    return espelho_fixo;

}

void prepara_barril(JOGO *jogo)
{
    int coord_x,coord_y;
    coord_x=jogo->coluna_donk;
    coord_y=jogo->linha_donk-2;
    imprime_donk2(jogo->coluna_donk,jogo->linha_donk);  // anima donkey kong
    imprime_barril_m(coord_x,coord_y);                  // Acima do donkey kong
    jogo->espelho_fixo=escreve_espelho(jogo->espelho_fixo,coord_x,coord_y,'B');

}

void joga_barril(JOGO *jogo)  // Ponteiro pois vamos mapear os barris moveis
{
    int indice ;
    int coord_x,coord_y;
    jogo->conta_barril=jogo->conta_barril+1;   // mais um barril no jogo
    indice=jogo->conta_barril-1;
    coord_x=jogo->coluna_donk;
    coord_y=jogo->linha_donk-2;
    jogo->espelho_fixo=apaga_espelho(jogo->espelho_fixo,coord_x,coord_y);  // apaga o barril do kong no espelho
    apaga(jogo->coluna_donk,jogo->linha_donk);                             // apaga o kong para baixar os bracos
    apaga(coord_x,coord_y);                                                // apaga o barril do kong na tela
    coord_x=jogo->coluna_donk+3;                                           // barril inicia ao lado do kong
    coord_y=jogo->linha_donk;
    imprime_donk1(jogo->coluna_donk,jogo->linha_donk);                     // reimprime o kong
    imprime_barril_m(coord_x,coord_y);                                     // imprime o barril
    jogo->espelho_fixo=escreve_espelho(jogo->espelho_fixo,coord_x,coord_y,'B');   // registra o barril no espelho
    jogo->barril_movel[indice].coluna_inicial=coord_x;
    jogo->barril_movel[indice].linha_inicial=coord_y;
    jogo->barril_movel[indice].velocidade=PDIR;         // sai pra direita
    jogo->barril_movel[indice].tipo='B';

}

int move_barril(JOGO *jogo,int indice_barril)
{
    int coord_x,coord_y; //auxiliares;
    int aux_x,aux_y;// auxiliares das auxiliares
    int eh_valido=0;
    char apagado='z';
    int mariox=jogo->mario.coluna_inicial;
    int marioy=jogo->mario.linha_inicial;
#ifdef DEBUG
    int in,jn;
    FILE *aa,*bb;
#endif // DEBUG
    coord_x=jogo->barril_movel[indice_barril].coluna_inicial;
    coord_y=jogo->barril_movel[indice_barril].linha_inicial;
    aux_x=coord_x;
    aux_y=coord_y;
    if (coord_x!=jogo->coluna_donk && (jogo->linha_donk-2)!=coord_y){
        if ((int)(jogo->barril_movel[indice_barril].velocidade)==PDIR)
        {
            jogo->espelho_fixo=testa_direita_barril(jogo->espelho_fixo,&coord_x,&coord_y,&eh_valido,&apagado);
            if (eh_valido){ // espelho já é apagado se válido, e coordenadas já são alteradas
                apaga(aux_x,aux_y);
                jogo->barril_movel[indice_barril].coluna_inicial = coord_x; // alterando coordenadas no struct que  guarda tudo
                jogo->barril_movel[indice_barril].linha_inicial  = coord_y;
                jogo->espelho_fixo=restaura_escada(PDIR,coord_x,coord_y,jogo->espelho_fixo); //restaurando as escadas
                jogo->espelho_fixo=escreve_espelho(jogo->espelho_fixo,coord_x,coord_y,'B'); // colocando o barril de volta no mapa de analise e na tela de jogo
                imprime_barril_m(coord_x,coord_y);
                if ((coord_x+X_PDR)==jogo->mario.coluna_inicial && coord_y==jogo->mario.linha_inicial) // acertei  o mario num choque horizontal 100%
                     return DERROTA;
                else if ((coord_x+X_PDR)==jogo->mario.coluna_inicial && (coord_y+1)==jogo->mario.linha_inicial) // acertei mario num choque horizontal 50%
                     return DERROTA;
            }
            else // encontrei alguma outra coisa, mudo de direção
                     jogo->barril_movel[indice_barril].velocidade=PESQ;

        }
        else // estou indo para esquerda;
        {
            jogo->espelho_fixo=testa_esquerda_barril(jogo->espelho_fixo,&coord_x,&coord_y,&eh_valido,&apagado);
            if (eh_valido){ // espelho já é apagado se válido, e coordenadas já são alteradas
                apaga(aux_x,aux_y);
                jogo->barril_movel[indice_barril].coluna_inicial = coord_x; // alterando coordenadas no struct que  guarda tudo
                jogo->barril_movel[indice_barril].linha_inicial  = coord_y;
                jogo->espelho_fixo=restaura_escada(PESQ,coord_x,coord_y,jogo->espelho_fixo); //restaurando as escadas
                jogo->espelho_fixo=escreve_espelho(jogo->espelho_fixo,coord_x,coord_y,'B'); // colocando o barril de volta no mapa de analise e na tela de jogo
                imprime_barril_m(coord_x,coord_y);
                if ((coord_x-1)==jogo->mario.coluna_inicial && coord_y==jogo->mario.linha_inicial) // acertaria   o mario num choque horizontal 100%
                     return DERROTA;
                else if ((coord_x-1)==jogo->mario.coluna_inicial && (coord_y+1)==jogo->mario.linha_inicial) // acertaria mario num choque horizontal 50%
                     return DERROTA;
            }
            else {// encontrei alguma outra coisa, mudo de direção
                     jogo->barril_movel[indice_barril].velocidade=PDIR;
            }

        }
    }



#ifdef DEBUG
    aa=fopen("antesff.txt","w");
    for (in=0; in<Y_MAX_ESPELHO; in++)
        for(jn=0; jn<X_MAX_ESPELHO; jn++)
            fputc(jogo->espelho_fixo.controle[in][jn],aa);
    fclose(aa);
#endif // DEBUG
    return JOGANDO;
}

int testa_baixo_barril(CONTROLE posicao, int x, int y)   //ok
{
    int linha,coluna;
    coluna=x;
    linha=y;

    int resultado;
    int ind_resultado=-1;// para dar certo no do while e quando sair não dar ruim
    if (posicao.controle[linha+Y_PDR][coluna] == 'H'
            && posicao.controle[linha+Y_PDR][coluna+1] == 'H'
            && posicao.controle[linha+Y_PDR][coluna+2] == 'H')
    {
        resultado=1;

    }
    else
        resultado=0;
    return resultado;
}
CONTROLE desce_barril(CONTROLE posicao, int *x, int *y, int *flag,char *restaura)
{
    int linha,coluna;
    coluna=*x;
    linha=*y;
    if(posicao.controle[linha+Y_PDR][coluna] !='S')
    {
        posicao=apaga_espelho(posicao,coluna,linha);
        linha++;
        *restaura=posicao.controle[linha][coluna];
        *x=coluna;
        *y=linha;
        *flag=1;
    }
    return posicao;
}

CONTROLE testa_direita_barril(CONTROLE posicao, int *x, int *y, int *flag,char *restaura)  //ok
{
    int linha,coluna;
    coluna=*x;
    linha=*y;
    int bPodeMover=FALSE;
    gotoxy(12,12);
  //  printf("AQUI ***%c***",posicao.controle[linha][coluna+X_PDR+1]);
    //system("pause");
    if (posicao.controle[linha+2][coluna] == 'H'
            || posicao.controle[linha+2][coluna] == 'S'
            || posicao.controle[linha+2][coluna] == ' '

       )
    {
        if(posicao.controle[linha][coluna+X_PDR] == ' '
                &&posicao.controle[linha+1][coluna+X_PDR] == ' ')
        {
            bPodeMover=TRUE;

        }
        else
        {
            if (posicao.controle[linha][coluna+X_PDR] == 'E'
               || posicao.controle[linha][coluna+X_PDR] == 'E')
            {
                *restaura='E';
                bPodeMover=TRUE;
            }
            else if (posicao.controle[linha][coluna+X_PDR] == 'S')
                bPodeMover=FALSE;
        }
    }
    if (bPodeMover)
    {
        posicao=apaga_espelho(posicao,*x,*y);
        coluna++;
        *x=coluna;
        *y=linha;
        *flag=1;
    }
    return posicao;

}

CONTROLE testa_esquerda_barril(CONTROLE posicao, int *x, int *y,int *flag,char *restaura)
{
    int linha,coluna;
    coluna=*x;
    linha=*y;
    int bPodeMover=FALSE;
    gotoxy(12,12);
    printf("AQUI ***%c***",posicao.controle[linha][coluna+X_PDR+1]);
    //system("pause");
    if (posicao.controle[linha+2][coluna] == 'H'
            || posicao.controle[linha+2][coluna] == 'S'
            || posicao.controle[linha+2][coluna] == ' ')
    {
        if(posicao.controle[linha][coluna-1] == ' '
                &&posicao.controle[linha+1][coluna-1] == ' ')
        {
            bPodeMover=TRUE;

        }
        else
        {
            if (posicao.controle[linha][coluna-1] == 'E'
                || posicao.controle[linha+1][coluna-1] == 'E')
            {
                *restaura='E';
                bPodeMover=TRUE;
            }
            else if (posicao.controle[linha][coluna-1] == 'S')
                bPodeMover=0;
        }
    }
    if (bPodeMover)
    {
        posicao=apaga_espelho(posicao,*x,*y);
        coluna--;
        *x=coluna;
        *y=linha;
        *flag=1;
    }
    return posicao;

}

int testa_descida_barril(int flag)
{

    int seed=time(NULL);
    int max=4;
    int min=0;
    srand(seed);
    int descer=rand() % (max + 1 - min) + min;
    if (descer==1)
    {
        flag=1;
    }
    else flag=0;
    return flag;
}

/* ############ CHANGELOG ############
    ############ Legenda: ###########
         '-' : Mudança
        '->' : Subtópico da mudança
    '####=>' : Importante ler
    ########### ######### ###########
Pedro, 18/06:
    - Criação da função controle_menu(); para poder iniciar jogos novamente caso o usuário ganhe ou perda(Ver funções abaixo)
    - Criação da função novo_jogo();
    - Criação de defines VITORIA, DERROTA;
    - Uso de ponteiros dentro da novo_jogo();
    - Troca de cores ao selecionar uma opção (Menu vermelho, Instruções verde claro, Jogo azul, Vitoria);
    - Criação da função jogo(), mas deixei comentado porque tem que fazer a função de mover o mário;
    - Criação da struct CONTROLE (Que tu tinha feito, aproveitei ela);
    - Criação da função vitoria();
    - Criação da função derrota();
    - Inclusão de Beeps; MAIS VIRÃO
    - Criação de variáveis do tipo CONTROLE* para princesa, donkey e CONTROLE[] para os barris móveis);
    - Criação do define MAX_BARRIL (Número máximo de barris móveis na tela)
    - Criação da struct PARAMETROS
Pedro, 19/06:
    - Adaptação da função jogo();
    - Contador de vidas; (Tem que adaptar para os barris moveis ainda)
    - Implementação das telas de vitória e derrota;
    - Mudança na função de move_mario();
    - Criação do define PAUSE;
    - Implementação do PAUSE; (Tem que criar a função salvar_jogo() )
    - Adaptação de tudo para o struct PARAMETROS;
    - Criação da função apaga(); para deixar mais claro o código de mover
    - Criação da função posiciona_mario(); para deixar mais claro o código ----> Pode substituir a imprime_mario()
    - Criação de define paras as CORES;
    Ideias: - Fazer uma função que retorna 0 ou 1 para ver se as posições batem
            - Adicionar mais campos em PARAMETROS:
              -> Vetor superficie, vetor escada normal, vetor escada quebrada, vetor fim escada, vetor rampad, vetor rampae para controlar o movimento e usar a função acima
              -> OBS.: Declarar esses vetores como ponteiros e alocar memória para eles
              -> OBS2.: Vai precisar de um define de MAX para cada um dos vetores
           ###=> Será que é mesmo necessário usar matrizes nessas funções de impressão inicial?
            - Colocar cor diferente nas impressões (dentro de cada função imprimeX() colocar uma cor)
Vitor, 22/06
        - Criação menu pausa
        - Implementação das cores
        - Ciração da função cor_escadas e  e colocarção de algumas outras cores
        Considerações:
        ####=> Vamos mesmo usar so memalloc, será que o sor não vai xiar? Se quiser fiz uma versão que ta igual mas sem isso
        -> Podemos sim meter  as  cores nas coisas eheh, já fiz um pouco disso e  quanto ao posiciona mario no lugar  do imprime mario, até pode ser, so acho que fica um pouco mais chato
        pra colotir ele eheheh;
Vitor, 29/06
        - Criação da função void restaura_escada(int sentido,int x,int y,CONTROLE a)   #FINALMENTE
        - Criação da função void gera_tipo_fase que gera o array da impressão.
        - Adaptação das função de impresão de escada e etc para apenas receberem um inteiro d e outro de y
        - Adaptação do menu pausa para retornar ao jogo quando se  aperta continuar
        _ adapatação do carrega jogo e etc
        ####=> Carregamento ficou ok acho, dps só vamos ter que pensar nos barris
        ####=> Com o controle jogo, aquela função que tu chama no main ficamos com um arecursividade quase que infinita no jogo, pois se morremos, chamamos ela dnv
        dai não sei como corrigir, só por isso que não da pra dizer que só falta fazer a jogabilidade msm.
Pedro, 29/06
        - Criação das funções prepara_barril e joga_barril
            -> Tem que achar um tempo ideal para isso ainda
        - Tive uma ideia de como fazer os timestamp(contador com resto)
        - Ajeitei a "recursividade" do programa, agora depois das telas de derrota e vitória ele chama a função certinho(troquei o define de SAIR pra 3 por causa das instruções)
Vitor, 30/06
        - Criação das funções apaga_espelho(CONTROLE apaga_espelho(CONTROLE espelho_fixo, int coord_x,int coord_y))  &&
          escreve_escreve espelho.
        ->  Elas colocam e tiram os barris do mapa de fundo assim toda vez que o mario se move  já sabemos  se ele irá ou não morrer dessa forma.
        ####=> Teremos que ficar fazendo esse escreve e apaga toda a vez que movimentarmos os barris para o lado tambem
        -Modificações nas funções joga e prepara barril;
        ####=> Criação da função habilita_movimento {int habilita_movimento(int flag_teste, clock_t *relogio1, clock_t relogio2,char atividade)}, adaptando
        aquilo que tu tinha feito para o tempo etc.
        -> Em decorrencia disso já crie os #defines do jogo, e como é alterado o score com o passar do tempo e etc, essas alterações estão na função jogo;

*/


