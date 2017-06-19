
/***************************DONKEY KONG ASCII**********************************

   **************************DESENVOLVIDO POR*******************************

                          Pedro Rodrigues de Lima
                                   &
                         Vitor Almeida de Carvalho


    *******************SINTAXE_DE_ORGANIZA��O_DE_C�DIGO*********************

    1-As �reas s�o delimitadas por cabe�alhos do tipo: //###NOME_DA_AREA###//
    2-O in�cio e termino de uma fun��o s�o delimitados por:
    //----------// (exceto se no come�o de uma �rea)
    3-Antes de cada fun��o ou metodo h� um breve coment�rio sobre a funcio-
    nalidade/ serventia de cada fun��o.
    4-Os nomes de vari�veis compostas tem o caractere _ indicando um espa�o.
    5-Vari�veis auxialiares devem definidas no inicio de uma fun��o para fa-
    cilitar a leitura;
    6-Utilizar nomes explicativos para vari�ves. Ex:int posicao_do_mario.
    Ex: variavel_com_nome_muito_grande

    ***************************ESTRUTURA_DO_C�DIGO**************************

    Este arquivo est� dividido de forma a agrupar em �reas, por similaridade,
    os trechos de c�digo. S�o as �reas:
        0-REFERENCIAS: Onde est�o alguns dados  �teis para a aelabora��o do
        c�digo.
        1-BIBILIOTECAS: Onde est�o listadas as bibliotecas utilizadas no de-
        senvolvimento do programa.
        2-DEFINI��ES: Onde est�o definidos as constantes utilizadas pelo pro-
        grama.
        3-STRUCTS- Onde est�o definidos todos os tipos criados para esse pro-
        jeto.
        4-SKETCHES DE FUN��ES:Onde est�o apresentadas todas as fun��es cria-
        das com tipo de parametros.
        5-MAIN:Onde est� o main do programa.
        6-FUN��ES:Onde est�o as fun��es e metodos criadas para o jogo.
        7-AREA DE DESENVOLVIMENTO: Onde est�o algumas rotinas teste, fun��es de
        debug e etc.

*******************************************************************************/

/*0-REFERENCIAS
Refer�ncia das cores da fun��o textcolor()
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

//######################2-DEFINI��ES:############################//

#define SCOREINC 1000  // Pontua��o Inicial
#define VIDAS 3        // N�mero de vidas inicial
#define NUMMAXOBJ 460  // Tamanho m�ximo de objetos poss�veis
#define Y_MAX 62       // Y max do prompt e x max do prompt
#define X_MAX 46
#define MAX_BARRIL 15
// c�digos internos
#define ERRO -1
#define NOVOJOGO 0
#define CONTINUARJOGO 1
#define SAIR 2
#define DERROTA 3
#define VITORIA 4
 // c�digo  das teclas
#define SPACEBAR 32
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define ENTER 13

// defini��es de coisas a desenvolver  e testes
#define XPDR 3
#define YPDR 2
#define GRAVIDADE 0.5 // numero de posi��es por time stamp
#define JUMPPOWER 3  //  velocidade/ impulso do pulo
#define TEMPO 100 //

//#define DEBUG  // tipo de defini��o muito �til que descobri
/* tudo que eu escrever  dentro de uma estrutura como
#ifdef DEBUG
c�digo vai aqui
#endif // DEBUG
s� roda enquanto esse cara estiver definido. Assim se comentar essa def aqui em cima
nenhum deles roda e n�o temos que tirar do c�digo nem nada. Dai fica muito �til para testes
*/
//######################3-STRUCTS############################//
    //Define estrutura central do programa.
typedef struct tipo_fase
{
    char tipo;
    int  coluna_inicial, linha_inicial;   // invertido
    float velocidade;
} TIPO_FASE;
//#######################STRUCT EM TESTE############################//
typedef struct CONTROLE{
    char tipo;
    int x;
    int y;
    int score_atual;
    int score_max;
    int vidas;
}CONTROLE;

typedef struct PARAMETROS{
    CONTROLE mario;
    CONTROLE princesa;
    CONTROLE donkey;
    CONTROLE barrilm[MAX_BARRIL];
    //int score_atual;
    //int score_max;
    //int vidas;
}PARAMETROS;
//#######################4-SKETCHES DE FUN��ES############################//


void hide_cursor(); // ensconde cursor, OK
int mainMenu(); // menu , OK
int setas(); // setas OK
void gotoxy(int,int); // mudar posica��o do cursor , OK
void textcolor(int);  // cor linda, OK
int lermapa(TIPO_FASE[]);  //ok
void formatprompt(); // j� esta OK

//         EM TESTE ou a fazer

/*Boas mano, tu  vai ver que tem muita coisa meio repetida nas fun��es de imprimir, se conseguir tenta optimizar isso
acredito tambem que devemos fazer duas gotoxy uma para coisas tipo texto setas e etc e outra para os objetos
qualquer d�vida me pede. tentei deixar o neg�io de impress�o pronto agr a jogabilidade � contigo heheh, pq essa semana
 vai ficar meio foda pra mim fazer algo */

void imprime_fase(TIPO_FASE[],int, CONTROLE*, CONTROLE*, CONTROLE*, CONTROLE[]); //ok
void move_mario(CONTROLE*); //a fazer
void imprime_tela_incial(); // ok
void imprime_instrucoes(); //ok
void imprime_mario(TIPO_FASE);// para imprimir o m�rio, mais ou menos
void imprime_donk1(TIPO_FASE); // para imprimir o donk1, mais ou menos
void imprime_donk2(TIPO_FASE); // para imprimir o donk 2, mais ou menos
void imprime_barrilm(TIPO_FASE); //para imprimir  mais ou menos
void imprime_barrile(TIPO_FASE);// para imprimir  mais ou menos
void imprime_princesa(TIPO_FASE);//para imprimir  mais ou menos
void imprime_escOK(TIPO_FASE);//mais ou menos
void imprime_escQ(TIPO_FASE);//  mais ou menos
void imprime_escFIM(TIPO_FASE);// mais ou menos
void imprime_rampadir(TIPO_FASE); // a fazer
void imprime_rampaesq(TIPO_FASE); // a fazer
void imprime_superficie(TIPO_FASE); // mais ou menos
void novo_jogo(TIPO_FASE*, CONTROLE*, CONTROLE*, CONTROLE*, CONTROLE[]);
void jogo(TIPO_FASE*, CONTROLE*, CONTROLE*, CONTROLE*, CONTROLE[]);
void vitoria(TIPO_FASE*, CONTROLE*, CONTROLE*, CONTROLE*, CONTROLE[]);
void derrota(TIPO_FASE*, CONTROLE*, CONTROLE*, CONTROLE*, CONTROLE[]);
int controle_menu(TIPO_FASE*, CONTROLE*, CONTROLE*, CONTROLE*, CONTROLE[]);
//void salva_jogo();
//void carrega_jogo();
//void carrega_mapa;


//######################5-MAIN############################//

int main()
{
    TIPO_FASE *vetorobjetos = malloc(sizeof(TIPO_FASE) * NUMMAXOBJ);  // inicializa��o do vetor de controle, aloca NUMMAXOBJ espa�os para TIPO_FASE, � igual a um vetor, mas declarado como ponteiro
    CONTROLE *mario = malloc(sizeof(CONTROLE));
    CONTROLE *princesa = malloc(sizeof(CONTROLE));
    CONTROLE *donkey = malloc(sizeof(CONTROLE));
    CONTROLE barrilm[MAX_BARRIL];
    controle_menu(vetorobjetos, mario, princesa, donkey, barrilm); // Fun��o que controla as op��es do menu principal
    return 0;
}
//######################6-FUN��ES OK############################//

int controle_menu(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[])
{
    int controle; //inicializa��o de variaveis de controle,score e indice do for de inicializa��o
    int indfor;
    for (indfor=0;indfor<NUMMAXOBJ;indfor++)// inicia vetor
        vetorobjetos[indfor].tipo='Z';
    controle=mainMenu();
    switch(controle)
    {
    case NOVOJOGO:
         novo_jogo(vetorobjetos, mario, princesa, donkey, barrilm); // SE QUISER TESTAR AS FUNCOES, VOU TIRAR DEPOIS: vitoria(vetorobjetos, mario); // derrota(vetorobjetos, mario);
         //jogo(vetorobjetos, mario);
         break;
    case CONTINUARJOGO:
         printf("A continuar");
         // A FAZER...carrega_jogo();
         // jogo(vetorobjetos, mario);
         break;
    case SAIR:
         return 0;
         break;
    }
}

int lermapa(TIPO_FASE arrayobj[])
{
    TIPO_FASE buffer;
    FILE *fase;
    int contador=0;

    fase=fopen("fase.bin","rb");
    if (!fase){
        printf("Erro ao carregar a fase, veja se o arquivo fase.bin existe");
    }
    else {
     while(!feof(fase)){
        fread(&buffer,sizeof(TIPO_FASE),1,fase);
            arrayobj[contador]=buffer;  // aqui de fato � feito o armazenamento de dados
            contador++;
            }
    }
    fclose(fase);
    return contador;
}

//-------------------------------------------------------------//

void hide_cursor() // Esconde o cursor default do prompt
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Esconde o Cursor do console
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

//-------------------------------------------------------------//

 void formatprompt() // Formata��o do prompt
{
    setlocale(LC_ALL, "Portuguese"); // L�ngua para portugu�s  //prompt em portugu�s para acentos e afins
    system("title Donkey Kong"); // Muda nome do prompt
    system("color 03");                             // Cor normal do prompt
    system("mode 60, 48");                           // Modo para n�o exceder o buffer
    SMALL_RECT WinRect = {0, 0, X_MAX, Y_MAX};       // Formata o tamanho do prompt
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, WinSize);

    hide_cursor();
}

//-------------------------------------------------------------//

void textcolor(int ForgC) // Fun��o para colorir o texto
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}


//-------------------------------------------------------------//

void gotoxy (int x, int y)
{
 COORD coord = {0, 0};
 coord.X =x; coord.Y = y+2; // X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//-------------------------------------------------------------//

int setas()  // Controle pelas setas direcionais
{
    int valor_seta; // Pode ser os valores definidos no cabe�alho

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

//-------------------------------------------------------------//

int mainMenu() // Menu principal do jogo
{
    formatprompt();  // seta tamanho e lingua
    int x =24 , y[] = {27, 31, 35,39};
    int contador = 0, sair = FALSE; // Coordenadas da seta, contador �ndice da seta, booleano sair para sair do menu
    system("cls"); // Limpa a tela
    textcolor(12); // Cor vermelha
    imprime_tela_incial();

    do // Faz ao menos uma vez
    {
        gotoxy(x, y[contador]); // Move o cursor para (x, y[contador])
        printf(">"); // Imprime a seta
        switch(setas())
        {
            case CIMA: if(contador != 0) // Caso o usu�rio aperte direcional para cima
                       { // Se o contador n�o estiver na primeira posi��o
                           gotoxy(x, y[contador]);
                           printf(" "); // Apaga a seta anterior
                           contador--; // Decrementa o contador
                       }
                       else if(contador == 0)
                            { // Se o contador estiver na primeira posi��o
                                gotoxy(x, y[contador]);
                                printf(" "); // Apaga a seta anterior
                                contador = 3; // Define contador como 2 (�ltima posi��o na tela)
                            }
                       break;

            case BAIXO: if(contador != 3) // Caso o usu�rio aperte direcional para baixo
                        { // Se o contador n�o estiver na �ltima posi��o
                           gotoxy(x, y[contador]);
                           printf(" "); // Apaga a seta anterior
                           contador++; // Incrementa o contador
                        }
                        else if(contador == 3)
                             { // Se o contador estiver na �ltima posi��o
                                 gotoxy(x, y[contador]);
                                 printf(" "); // Apaga a seta anterior
                                 contador = 0; // Define o contador como 0 (primeira posi��o na tela)
                             }
                        break;
            case SPACEBAR:
            case ENTER: if (contador==2){
                        imprime_instrucoes();
                        }
                        else {
                        sair = TRUE;
                        } // Se o usu�rio teclar ENTER, sai do loop
                        break;

            case ESC: if(contador != 3) // Se o usu�rio teclar ESC (No caso seria um atalho para sair do programa rapidamente)
                      { // Se o contador for diferente de 2
                          gotoxy(x, y[contador]);
                          printf(" ");
                          contador = 3; // Move a seta para a �ltima posi��o
                      }
                      else return SAIR;
                      break;
        }

        Beep(500, 40); // B E E P

    }while(!sair); // Enquanto "n�o sair"
    return contador;
}

//######################7-AREA DE DESENVOLVIMENTO############################//

void novo_jogo(TIPO_FASE *vetorobjetos, CONTROLE *parametros, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[])
{
    int num_objetos;
    system("cls");
    parametros->score_atual=SCOREINC;
    parametros->score_max=SCOREINC;
    parametros->vidas=VIDAS;
    num_objetos=lermapa(vetorobjetos);
    if(num_objetos==ERRO)
        printf("Erro na leitura do arquivo, reinicie o programa");
    else
    {
        imprime_fase(vetorobjetos,num_objetos,parametros, princesa, donkey, barrilm);
        gotoxy(0,-2);
        printf("VIDAS %d \n",parametros->vidas);
        printf("SCORE ATUAL/MAX: %d / %d",parametros->score_atual, parametros->score_max);
        system("pause");
    }
}

//-------------------------------------------------------------------------//
void jogo(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[]) // ver como fazer pra descobrir a posi��o do donk, barril e princesa
{

    int condition = 0;
    while(condition != DERROTA && condition != VITORIA)
    {
        move_mario(mario);
//        if((mario->x == /*X_DONK*/ && mario->y == /*Y_DONK*/) ||
//           (mario->x == /*X_BARRILMOVEL*/ && mario->y == /*Y_BARRILMOVEL*/)) // Se for igual ao X && Y de um || igual ao X && Y de outro (acho que tem que considerar a matriz toda e tal)
/*        {
            condition = DERROTA;
            if(mario->vidas == 0)
                derrota(vetorobjetos, mario, princesa, donkey, barrilm);
            else
                mario->vidas--;
        }*/
//        else if(mario->x == /*X_PRINCESA*/ && mario->y == /*Y_PRINCESA*/)
/*                 {
                    condition = VITORIA;
                    vitoria(vetorobjetos, mario);
                 }*/


    }

}
//-------------------------------------------------------------------------//

void vitoria(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[]) // Basicamente c�pia da fun��o imprime_tela_inicial();
{
    system("cls");
    textcolor(11);
    int c;
    FILE *vitoria;
    vitoria = fopen("vitoria.txt", "r"); // CRIAR TXT DE VITORIA
    if (vitoria) {
        while ((c = getc(vitoria)) != EOF)
            putchar(c);
        fclose(vitoria);
    }
    gotoxy(5, 15); // Achar posi��o boa
    printf("Pontua��o final: %d / Pontua��o m�xima: %d", mario->score_atual, mario->score_max);
    gotoxy(7, 17);
    printf("Pressione ESC para retornar ao menu. . .");
    if(getch()==ESC)
    {
        controle_menu(vetorobjetos, mario, princesa, donkey, barrilm); // Retorna � rotina de controle do menu
        Beep(500, 40);
    }
}

//-------------------------------------------------------------------------//

void derrota(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[]) // Basicamente igual � vitoria
{
    system("cls");
    textcolor(15);
    int c;
    FILE *derrota;
    derrota = fopen("derrota.txt", "r"); // CRIAR TXT DE DERROTA
    if (derrota) {
        while ((c = getc(derrota)) != EOF)
            putchar(c);
        fclose(derrota);
    }
    gotoxy(5, 15); // Achar posi��o boa
    printf("Pontua��o final: %d / Pontua��o m�xima: %d", mario->score_atual, mario->score_max);
    gotoxy(7, 17);
    printf("Pressione ESC para retornar ao menu. . .");
    if(getch()==ESC)
    {
        controle_menu(vetorobjetos, mario, princesa, donkey, barrilm);
        Beep(500, 40);
    }
}

//-------------------------------------------------------------------------//

void imprime_instrucoes(){
    system("cls");
    Beep(500, 40);
    textcolor(10);
    int c;
    FILE *info;
    info = fopen("menuinfo.txt", "r"); // agora se quiser trocar o menu � s� trocar aqui dai o c�digo fica menos polu�do.
                                    // al�m disso agr � so tu escrever num txt normal sem ter que por aspas ou \n ou \\ para imprimir barras :)
    if (info) {
        while ((c = getc(info)) != EOF)
            putchar(c);
        fclose(info);
    getch();
    }
    else {
        printf("Erro ao apresentar as intru��es, verifique a existencia do arquivo menuinfo.txt");
        printf("\nPressione qualquer tecla para retornar ao menu");
        getch();
    }
    imprime_tela_incial();
}

//-------------------------------------------------------------------------//

void imprime_tela_incial(){
    system("cls");
    textcolor(12);
    int c;
    FILE *menu;
    menu = fopen("menu.txt", "r"); // agora se quiser trocar o menu � s� trocar aqui dai o c�digo fica menos polu�do.
                                    // al�m disso agr � so tu escrever num txt normal sem ter que por aspas ou \n ou \\ para imprimir barras :)
    if (menu) {
        while ((c = getc(menu)) != EOF)
            putchar(c);
        fclose(menu);
    }
}

//-------------------------------------------------------------------------//

void move_mario(CONTROLE *mario){

   char key;
   int jumptime;
   float flagjump=0;
   int ciclos=-1;
   while(key!=ESC && key!= 'P'){  // Se uma dessas teclas for pressionada
   Sleep(TEMPO); // Delay
   if (kbhit()){
   key = toupper(getch());
    switch(key)
    {
    case 'A':// porumif aqui
              gotoxy(mario->x, mario->y);
              printf("   ");
              gotoxy(mario->x,(mario->y)+1);
              printf("   ");
              (mario->x)--;
              gotoxy(mario->x,mario->y);
              printf("_�_");
              gotoxy(mario->x,(mario->y)+1);
              printf("/H\\");
              hide_cursor();
              break;

    case 'D':// ifaqui
              gotoxy(mario->x, mario->y);
              printf("   ");
              gotoxy(mario->x,(mario->y)+1);
              printf("   ");
              (mario->x)++;
              gotoxy(mario->x,mario->y);
              printf("_�_");
              gotoxy(mario->x,(mario->y)+1);
              printf("/H\\");
              hide_cursor();
              break;

    case 'W': //if
              gotoxy(mario->x, mario->y);
              printf("   ");
              gotoxy(mario->x,(mario->y)+1);
              printf("   ");
              (mario->y)--;
              gotoxy(mario->x,mario->y);
              printf("_�_");
              gotoxy(mario->x,(mario->y)+1);
              printf("/H\\");
              hide_cursor();
              break;

    case 'S': gotoxy(mario->x, mario->y);
              printf("   ");
              gotoxy(mario->x,(mario->y)+1);
              printf("   ");
              (mario->y)++;
              gotoxy(mario->x,mario->y);
              printf("_�_");
              gotoxy(mario->x,(mario->y)+1);
              printf("/H\\");
              hide_cursor();
              break;

   /* case SPACEBAR :
                if(flagjump==0){
                flagjump=1;
                gotoxy(x, y);
                printf("   ");
                gotoxy(x,y+1);
                printf("   ");
                y--;
                gotoxy(x,y);
                printf("_?_");
                gotoxy(x,y+1);
                printf("/H\\");
                hide_cursor();
            }
            break;*/

    case ESC: gotoxy(10, 65);
        break;
    }

   }

  /*  if (flagjump>0){
        ciclos++;
        flagjump=JUMPPOWER-ciclos*GRAVIDADE;
        if (flagjump==0){
            ciclos=0;
            gotoxy(x, y);
            printf("   ");
            gotoxy(x,y+1);
            printf("   ");
            y++;
            gotoxy(x,y);
            printf("_?_");
            gotoxy(x,y+1);
            printf("/H\\");
            hide_cursor();
        }
    }*/
   }
}

//-------------------------------------------------------------//

void imprime_mario(TIPO_FASE mario){  // observa��o, n�o sei se n�o � melhor fazer como tu tava fazendo
    char M[YPDR][XPDR]={{'\\','�','/'},{'/','H','\\'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((mario.coluna_inicial)*3,(mario.linha_inicial)*2+i);
        for (j=0;j<3;j++){
            printf("%c", M[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_donk1(TIPO_FASE donk)
{
    char D[YPDR][XPDR]={{'}','�','{'},{'_','H','_'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((donk.coluna_inicial)*3,(donk.linha_inicial)*2+i);
        for (j=0;j<XPDR;j++){
            printf("%c", D[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_donk2(TIPO_FASE donk)
{
    char D[YPDR][XPDR]={{'\\','o','/'},{'/',' ','\\'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy(donk.coluna_inicial,donk.linha_inicial+i);
        for (j=0;j<XPDR;j++){
            printf("%c", D[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_princesa(TIPO_FASE prin)
{
    char P[YPDR][XPDR]={{'\\','o','/'},{'/','=','\\'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((prin.coluna_inicial)*3,(prin.linha_inicial)*2+i);
        for (j=0;j<XPDR;j++){
            printf("%c", P[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_superficie(TIPO_FASE superficie)
{
  char S[YPDR][XPDR]={{'X','X','X'},{'X','X','X'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((superficie.coluna_inicial)*3,((superficie.linha_inicial)*2+i));
        for (j=0;j<XPDR;j++){
           printf("%c", S[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_escFIM(TIPO_FASE escfim)
{
  char H[YPDR][XPDR]={{'|','X','|'},{'|','-','|'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((escfim.coluna_inicial)*3,((escfim.linha_inicial)*2+i));
        for (j=0;j<XPDR;j++){
           printf("%c", H[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_escOK(TIPO_FASE escboa){
 char E[YPDR][XPDR]={{'|','-','|'},{'|','-','|'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((escboa.coluna_inicial)*3,((escboa.linha_inicial)*2+i));
        for (j=0;j<XPDR;j++){
           printf("%c", E[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_escQ(TIPO_FASE escquebrada){
 char E[YPDR][XPDR]={{'|','-','|'},{' ','-','|'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((escquebrada.coluna_inicial)*3,((escquebrada.linha_inicial)*2+i));
        for (j=0;j<XPDR;j++){
           printf("%c", E[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_barrile(TIPO_FASE barrilparado){
 char B1[YPDR][XPDR]={{'/','^','\\'},{'\\','Z','/'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((barrilparado.coluna_inicial)*3,((barrilparado.linha_inicial)*2+i));
        for (j=0;j<3;j++){
           printf("%c", B1[i][j]);
        }
    }
}

//-------------------------------------------------------------//

void imprime_barrilm(TIPO_FASE barrilmovel){
 char B2[YPDR][XPDR]={{'/','^','\\'},{'\\',' ','/'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((barrilmovel.coluna_inicial)*3,((barrilmovel.linha_inicial)*2+i));
        for (j=0;j<XPDR;j++){
           printf("%c", B2[i][j]);
        }
    }
}

void imprime_rampadir(TIPO_FASE rdireita){
 char RD[YPDR][XPDR*2]={{' ',' ',' ','_','.','-'},{'_','.','-',' ',' ',' '}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((rdireita.coluna_inicial)*3,((rdireita.linha_inicial)*2+i));
        for (j=0;j<XPDR*2;j++){
           printf("%c", RD[i][j]);
        }
    }
}

void imprime_rampaesq(TIPO_FASE resquerda){
 char RD[YPDR][XPDR*2]={{'-','.','_',' ',' ',' '},{' ',' ',' ','-','.','_'}};
    int i,j;
    for (i=0;i<YPDR;i++){
            gotoxy((resquerda.coluna_inicial)*3,((resquerda.linha_inicial)*2+i));
        for (j=0;j<XPDR*2;j++){
           printf("%c", RD[i][j]);
        }
    }
}


//-------------------------------------------------------------//

void imprime_fase(TIPO_FASE paraimpressao[], int qtd_objetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[]){
    int i, j=0;
    #ifdef DEBUG
       FILE * vitor; // para analisar se a impress�o esta  correta
       fopen("vitor.csv","wt"); // gera um csv
       fprintf(vitor,"TIPO,COLUNA,LINHA,VELOCIDADE,\n");
    #endif // DEBUG
    textcolor(3);
    for (i=0;i<qtd_objetos;i++)
    {
    #ifdef DEBUG
       fprintf(vitor,"%c,",paraimpressao[i].tipo);
       fprintf(vitor,"%d,",paraimpressao[i].coluna_inicial);
       fprintf(vitor,"%d,",paraimpressao[i].linha_inicial);
       fprintf(vitor,"%0.f,\n",paraimpressao[i].velocidade);
       char c;
       c=getch( ); //espera tu teclar algo para a impress�o dai fica mais visual se ta fazendo certo
    #endif // DEBUG
    switch(paraimpressao[i].tipo){
            case 'M': imprime_mario(paraimpressao[i]);
                      mario->x = paraimpressao[i].linha_inicial;
                      mario->y = paraimpressao[i].coluna_inicial;
                      break;
            case 'P': imprime_princesa(paraimpressao[i]);
                      princesa->x = paraimpressao[i].linha_inicial;
                      princesa->y = paraimpressao[i].coluna_inicial;
                      break;
            case 'K': imprime_donk1(paraimpressao[i]);
                      donkey->x = paraimpressao[i].linha_inicial;
                      donkey->y = paraimpressao[i].coluna_inicial;
                break;
            case 'G': imprime_rampaesq(paraimpressao[i]);
                break;
            case 'F': imprime_rampadir(paraimpressao[i]);
                break;
            case 'S': imprime_superficie(paraimpressao[i]);
                break;
            case 'E': imprime_escOK(paraimpressao[i]);
                break;
            case 'Q':  imprime_escQ(paraimpressao[i]);
                 break;
            case 'H': imprime_escFIM(paraimpressao[i]);
                break;
            case 'B':if(paraimpressao[i].velocidade>0)  // barril que se mexe
                    {
                        imprime_barrilm(paraimpressao[i]);
                        barrilm[j].x = paraimpressao[i].linha_inicial;
                        barrilm[j].y = paraimpressao[i].coluna_inicial;
                        j++;
                    }
                     else
                       imprime_barrile(paraimpressao[i]);  // barril est�tico/ parado
                     break;
            }//*/
        }
        #ifdef DEBUG
            fclose(vitor);
        #endif // DEBUG
}


/* ############ CHANGELOG ############
Pedro, 18/06:
    - Cria��o da fun��o controle_menu(); para poder iniciar jogos novamente caso o usu�rio ganhe ou perda(Ver fun��es abaixo)
    - Cria��o da fun��o novo_jogo();
    - Cria��o de defines VITORIA, DERROTA;
    - Uso de ponteiros dentro da novo_jogo();
    - Troca de cores ao selecionar uma op��o (Menu vermelho, Instru��es verde claro, Jogo azul, Vitoria);
    - Cria��o da fun��o jogo(), mas deixei comentado porque tem que fazer a fun��o de mover o m�rio;
    - Cria��o da struct CONTROLE (Que tu tinha feito, aproveitei ela);
    - Cria��o da fun��o vitoria();
    - Cria��o da fun��o derrota();
    - Inclus�o de Beeps; MAIS VIR�O
    - Cria��o de vari�veis do tipo CONTROLE* para princesa, donkey e CONTROLE[] para os barris m�veis);
    - Cria��o do define MAX_BARRIL (N�mero m�ximo de barris m�veis na tela)
    - Cria��o da struct PARAMETROS ----- LER ISSO ---- -> Preciso saber o que tu acha de mover os scores e as vidas pro PARAMETROS, da� fica mais f�cil de passar os bagulhos por refer�ncia
      ----------------------------------------------------Se tu for ver, eu tive que colocar v�rias vezes (CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[])
     -----------------------------------------------------Ent�o seria conveniente ter uma struct PARAMETROS contendo essas vari�veis, tipo o que eu fiz l� em cima, mas preciso saber se tu acha
      ----------------------------------------------------Que isso vai dar certo, hahahaha
*/
