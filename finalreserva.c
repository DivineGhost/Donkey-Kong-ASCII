
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
// c�digos internos
#define ERRO -1
#define NOVOJOGO 0
#define CONTINUARJOGO 1
#define SAIR 2
 // c�digo  das teclas
#define SPACEBAR 32
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define ENTER 13

// defini��es de coisas a desenvolver  e testes

// defini��es de itens do jogo
#define SCORE_INICIAL 1000      // Pontua��o Inicial
#define VIDAS_INICIAIS 3        // N�mero de vidas inicial
#define Y_MAX 62                // Y m�ximo do prompt
#define X_MAX 46                // X m�ximo do prompt
#define X_PDR 3                 // Tamanho X padr�o para impress�o
#define Y_PDR 2                 // Tamanho Y padr�o para impress�o
#define MAX_OBJ 460             // Numero m�ximo de objetos poss�veis
#define MAX_BARRIL_M 20         // N�mero m�ximo de barris m�veis simultaneamente na tela
#define MAX_BARRIL_E 20         // N�mero m�ximo de barris estaticos
#define MAX_SUPERFICIE 100      // N�mero m�ximo de superficies
#define MAX_ESCADA_TOPO 10      // N�mero m�ximo de fim da escada
#define MAX_ESCADA_MEIO 50      // N�mero m�ximo de escadas ok
#define MAX_ESCADA_QUEB 10      // N�mero m�ximo de escadas quebradas
#define MAX_RAMPA_DIREITA 20    // N�mero m�ximo de rampas para a direita
#define MAX_RAMPA_ESQUERDA 20   // N�mero m�ximo de rampas para a esquerda
// cores da fun��o text_color()
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
// c�digos internos
#define ERRO -1
#define NOVOJOGO 0
#define CONTINUARJOGO 1
#define SAIR 2
#define DERROTA 3
#define VITORIA 4
#define PAUSE 5
#define JOGANDO 9
#define TEMPO 10
#define JUMPPOWER 2
#define GRAVIDADE 30
#define DELAY 100
//######################3-STRUCTS############################//
    //Define estrutura central do programa.

typedef struct tipo_fase{
    char tipo;
    int linha_inicial;
    int coluna_inicial;
    float velocidade;
} TIPO_FASE;

typedef struct CONTROLE{
    int x;
    int y;
}CONTROLE;

typedef struct INDICES{
    int i_barril_e;
    int i_barril_m;
    int i_superficie;
    int i_escada_topo;
    int i_escada_meio;
    int i_escada_quebrada;
    int i_rampa_direita;
    int i_rampa_esquerda;
}INDICES;

typedef struct JOGO{
    TIPO_FASE vetor_objetos[MAX_OBJ];
    TIPO_FASE inc_mario;
    CONTROLE mario;
    CONTROLE princesa;
    CONTROLE donkey;
    CONTROLE barril_m[MAX_BARRIL_M];
    CONTROLE barril_e[MAX_BARRIL_E];
    CONTROLE superficie[MAX_SUPERFICIE];
    CONTROLE escada_topo[MAX_ESCADA_TOPO];
    CONTROLE escada_meio[MAX_ESCADA_MEIO];
    CONTROLE escada_quebrada[MAX_ESCADA_QUEB];
    CONTROLE rampa_direita[MAX_RAMPA_DIREITA];
    CONTROLE rampa_esquerda[MAX_RAMPA_ESQUERDA];
    int score_atual;
    int score_max;
    int vidas;
    INDICES indices;
    int num_obj;

}JOGO;
//#######################4-SKETCHES DE FUN��ES############################//


void hide_cursor(); // ensconde cursor, OK
int mainMenu(); // menu , OK
int setas(); // setas OK
void gotoxy(int,int); // mudar posica��o do cursor , OK
void text_color(int);  // cor linda, OK
int lermapa(TIPO_FASE[]);  //ok
void formatprompt(); // j� esta OK
void vitoria(JOGO *);          // Imprime uma tela de vit�ria OK
void derrota(JOGO *);          // Imprime uma tela de derrota OK
void imprime_fase(TIPO_FASE[],int,int); //ok
void imprime_tela_incial(); // ok
void imprime_instrucoes(); //ok
int move_mario(JOGO*);        // Move o m�rio A FAZER
void apaga_mario(JOGO*);      // Apaga a posi��o do m�rioOK
void posiciona_mario(JOGO*);  // Imprime o m�rio OK
void imprime_mario(TIPO_FASE);      // MAIS OU MENOS
void imprime_donk1(TIPO_FASE);      // MAIS OU MENOS
void imprime_donk2(TIPO_FASE);      // MAIS OU MENOS
void imprime_barril_m(TIPO_FASE);    // MAIS OU MENOS
void imprime_barril_e(TIPO_FASE);    // MAIS OU MENOS
void imprime_princesa(TIPO_FASE);   // MAIS OU MENOS
void imprime_escOK(TIPO_FASE);      // MAIS OU MENOS
void imprime_escQ(TIPO_FASE);       // MAIS OU MENOS
void imprime_escFIM(TIPO_FASE);     // MAIS OU MENOS
void imprime_rampadir(TIPO_FASE);   // MAIS OU MENOS
void imprime_rampaesq(TIPO_FASE);   // MAIS OU MENOS
void imprime_superficie(TIPO_FASE); // MAIS OU MENOS // mais ou menos
JOGO novo_jogo(TIPO_FASE[],int); //a fazer
int jogo(JOGO);
mapeia_fase(JOGO*, int, int);
//void carrega_jogo () a fazer
//void carrega_mapa;


//######################5-MAIN############################//

int main()
{

    TIPO_FASE vetorobjetos[NUMMAXOBJ];
    JOGO controle_geral;  // inicializa��o do vetor de controle
    int controle,score_atual,score_max,indfor,num_objetos;//inicializa��o de variaveis de controle,score e indice do for de inicializa��o
    for (indfor=0;indfor<NUMMAXOBJ;indfor++)// inicia vetor
        vetorobjetos[indfor].tipo='Z';
    formatprompt(); // seta tamanho e lingua
    num_objetos=lermapa(vetorobjetos);
    controle=mainMenu();
    switch(controle){
    case NOVOJOGO :controle_geral=novo_jogo(vetorobjetos,num_objetos);
                   jogo(controle_geral);
        break;
    case CONTINUARJOGO : //carrega_jogo();
                         //jogo();
        // aqui entraria o carrega_jogo();
        // depois a fun��o jogo;
        break;
    case SAIR: return 0;
        break;
        }
    return 0;
}
//######################6-FUN��ES OK############################//
JOGO novo_jogo(TIPO_FASE array_obj[],int limite){
    system("cls");
    JOGO tabela;
    int i;
    for (i=0;i<limite;i++)tabela.vetor_objetos[i]=array_obj[i];
    tabela.indices.i_barril_e=0;
    tabela.indices.i_barril_m=0;
    tabela.indices.i_escada_meio=0;
    tabela.indices.i_escada_quebrada=0;
    tabela.indices.i_escada_topo=0;
    tabela.indices.i_rampa_direita=0;
    tabela.indices.i_rampa_esquerda=0;
    tabela.indices.i_superficie=0;
    tabela.vidas=VIDAS_INICIAIS;
    tabela.score_atual=SCORE_INICIAL;
    tabela.score_max=SCORE_INICIAL;
    imprime_fase(array_obj,limite,tabela.vidas);
    mapeia_fase(&tabela,limite,tabela.vidas);
    return tabela;

}

int jogo(JOGO copia_controle_jogo){
    int condition = 0;
    int vidas;
    vidas= copia_controle_jogo.vidas;
   while(condition != SAIR && condition != VITORIA && condition != DERROTA)
   {

        condition = move_mario(&copia_controle_jogo);
       switch(condition)
   {

            case JOGANDO: gotoxy(0,0);

                            break;
            case DERROTA:   if(copia_controle_jogo.vidas == 0){
                            derrota(&copia_controle_jogo);
                            }
                          else
                            {
                            gotoxy(0,0);
                            vidas--;
                            system("pause");
                            copia_controle_jogo.vidas=vidas;
                            gotoxy(0,0);
                            apaga_mario(&copia_controle_jogo);
                            imprime_fase(&copia_controle_jogo, copia_controle_jogo.num_obj,copia_controle_jogo.vidas);
                            copia_controle_jogo.mario.x= copia_controle_jogo.inc_mario.coluna_inicial;
                            copia_controle_jogo.mario.y= copia_controle_jogo.inc_mario.linha_inicial;
                            imprime_fase(copia_controle_jogo.vetor_objetos, copia_controle_jogo.num_obj, vidas);
                             gotoxy(0,22);
                    printf("VAlor cpc  x%d\n",copia_controle_jogo.mario.x);
                     printf("VAlor cpc y %d\n",copia_controle_jogo.mario.y);
                            condition= JOGANDO;
                          }
                          break;
            case VITORIA: vitoria(&copia_controle_jogo);
                          break;
            case PAUSE: condition=menu_pausa();

                          break;
        }
     }
}

    void apaga_mario(JOGO *parametros){

    gotoxy(parametros->mario.x, parametros->mario.y);
    printf("   ");
    gotoxy(parametros->mario.x, (parametros->mario.y)+1);
    printf("   ");
}

void posiciona_mario(JOGO *parametros){

    gotoxy(parametros->mario.x,parametros->mario.y);
    printf("\\�/");
    gotoxy(parametros->mario.x, (parametros->mario.y)+1);
    printf("/H\\");
    hide_cursor();
}

int move_mario(JOGO *parametros){

    text_color(LIGHT_RED);
    char key;
    if (kbhit()){
        key=getch();
            key = toupper(key);
            switch(key)
            {
            case 'A': apaga_mario(parametros);
                      (parametros->mario.x)--;
                      posiciona_mario(parametros);
                        gotoxy(0,20);
                    printf("VAlor do ponteiro parametros x%d\n",parametros->mario.x);
                     printf("VAlor do ponteiro parametros  y %d\n",parametros->mario.y);
                      break;

            case 'D': apaga_mario(parametros);
                      (parametros->mario.x)++;
                      posiciona_mario(parametros);
                        gotoxy(0,20);
                    printf("VAlor do ponteiro parametros x%d\n",parametros->mario.x);
                     printf("VAlor do ponteiro parametros  y %d\n",parametros->mario.y);
                      break;

            case 'W': apaga_mario(parametros);
                      (parametros->mario.y)--;
                      posiciona_mario(parametros);
                        gotoxy(0,20);
                    printf("VAlor do ponteiro parametros x%d\n",parametros->mario.x);
                     printf("VAlor do ponteiro parametros  y %d\n",parametros->mario.y);
                      break;

            case 'S': apaga_mario(parametros);
                      (parametros->mario.y)++;
                      posiciona_mario(parametros);
                        gotoxy(0,20);
                    printf("VAlor do ponteiro parametros x%d\n",parametros->mario.x);
                     printf("VAlor do ponteiro parametros  y %d\n",parametros->mario.y);
                      break;
            case  'P': return PAUSE;
    // case SPACEBAR:
            }
       }
    if(parametros->mario.x == parametros->donkey.x && parametros->mario.y == (parametros->donkey.y))
        return DERROTA;
    else if(parametros->mario.x == (parametros->princesa.x) && parametros->mario.y == (parametros->princesa.y))
        return VITORIA;
   else
   return JOGANDO;

}

void vitoria(JOGO *parametros){
    system("cls");
    text_color(LIGHT_AQUA);
    int c;
    FILE *vitoria;
    vitoria = fopen("vitoria.txt", "r");
    if (vitoria) {
        while ((c = getc(vitoria)) != EOF)
            putchar(c);
        fclose(vitoria);
    }
    gotoxy(5, 15);
    printf("Pontua��o final: %d / Pontua��o m�xima: %d", parametros->score_atual, parametros->score_max);
    gotoxy(7, 17);
    printf("Pressione ESC para retornar ao menu. . .");
    if(getch()==ESC)
    {
        //controle_menu(parametros); // Retorna � rotina de controle do menu
        Beep(500, 40);
    }
}

void derrota(JOGO *parametros){
    system("cls");
    text_color(BRIGHT_WHITE);
    int c;
    FILE *derrota;
    derrota = fopen("derrota.txt", "r");
    if (derrota) {
        while ((c = getc(derrota)) != EOF)
            putchar(c);
        fclose(derrota);
    }
    gotoxy(5, 15);
    printf("Pontua��o final: %d / Pontua��o m�xima: %d", parametros->score_atual, parametros->score_max);
    gotoxy(7, 17);
   // printf("Pressione ESC para retornar ao menu. . .");
   // if(getch()==ESC)
    //{
     //   controle_menu(parametros);
       // Beep(500, 40);
    //}
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

 void formatprompt()
{ // Formata��o do prompt
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

void text_color(int ForgC) // Fun��o para colorir o texto
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
    int x =24 , y[] = {27, 31, 35,39};  // o valor real � mais dois esses valores de y
    // � que  devido ao fato de que as coordenadas lidas no arquivo.bin da fase
    // s�o os valores da matriz 23,20 (ver enunciado trabalho final);
    // assim tem que somar dois na fun��o gotoxy para deixar as duas linhas de sobra  para imprimir o score
    // se quiser podemos fazer uma separada para o menu e ficar� mais claro.
    // lembrando que a coordenada x,y tem as posi��es trocadas da matriz que � (y,x).
    int contador = 0, sair = FALSE; // Coordenadas da seta, contador �ndice da seta, booleano sair para sair do menu
    system("cls"); // Limpa a tela
    text_color(12); // Cor vermelha
    #ifdef DEBUG
    int i;
    for (i=1;i<61;i++){printf("%d",i%10);};
    #endif // DEBUG
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

void imprime_instrucoes(){
    system("cls");
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
void imprime_tela_incial(){
    system("cls");
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

//-------------------------------------------------------------//

void imprime_mario(TIPO_FASE mario){  // observa��o, n�o sei se n�o � melhor fazer como tu tava fazendo
    char M[Y_PDR][X_PDR]={{'\\','�','/'},{'/','H','\\'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((mario.coluna_inicial)*3,(mario.linha_inicial)*2+i);
        for (j=0;j<X_PDR;j++){
            printf("%c", M[i][j]);
        }
    }
}

void imprime_donk1(TIPO_FASE donk)
{
    char D[Y_PDR][X_PDR]={{'}','�','{'},{'_','H','_'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((donk.coluna_inicial)*3,(donk.linha_inicial)*2+i);
        for (j=0;j<X_PDR;j++){
            text_color(YELLOW);
            printf("%c", D[i][j]);
        }
    }
}

void imprime_donk2(TIPO_FASE donk)
{
  char D[Y_PDR][X_PDR]={{'\\','o','/'},{'/',' ','\\'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy(donk.coluna_inicial,donk.linha_inicial+i);
        for (j=0;j<X_PDR;j++){
            text_color(YELLOW);
            printf("%c", D[i][j]);
        }
    }
}

void imprime_princesa(TIPO_FASE prin)
{
  //  '\o/'
  //  '/=\'

  char P[Y_PDR][X_PDR]={{'\\','o','/'},{'/','=','\\'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((prin.coluna_inicial)*3,(prin.linha_inicial)*2+i);
        for (j=0;j<X_PDR;j++){
            text_color(LIGHT_PURPLE);
            printf("%c", P[i][j]);
        }
    }
}

void imprime_superficie(TIPO_FASE superficie)
{
  char S[Y_PDR][X_PDR]={{'X','X','X'},{'X','X','X'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((superficie.coluna_inicial)*3,((superficie.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
           text_color(LIGHT_RED);
           printf("%c", S[i][j]);
        }
    }
}

void imprime_escFIM(TIPO_FASE escfim)
{
  char H[Y_PDR][X_PDR]={{'|','X','|'},{'|','-','|'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((escfim.coluna_inicial)*3,((escfim.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
         cor_escadas(j);
         printf("%c", H[i][j]);
        }
    }
}

void imprime_escOK(TIPO_FASE escboa){
 char E[Y_PDR][X_PDR]={{'|','-','|'},{'|','-','|'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((escboa.coluna_inicial)*3,((escboa.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
            cor_escadas(j);
           printf("%c", E[i][j]);
        }
    }
}

void imprime_escQ(TIPO_FASE escquebrada){

 char Q[Y_PDR][X_PDR]={{'|','-','|'},{' ','-','|'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((escquebrada.coluna_inicial)*3,((escquebrada.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
        cor_escadas(j);
         printf("%c", Q[i][j]);
        }
    }
}

void imprime_barril_e(TIPO_FASE barrilparado){
 char B1[Y_PDR][X_PDR]={{'/','^','\\'},{'\\','Z','/'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((barrilparado.coluna_inicial)*3,((barrilparado.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
           text_color(GRAY);
           printf("%c", B1[i][j]);
        }
    }
}

void imprime_barril_m(TIPO_FASE barrilmovel){
 char B2[Y_PDR][X_PDR]={{'/','^','\\'},{'\\',' ','/'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((barrilmovel.coluna_inicial)*3,((barrilmovel.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
           text_color(GRAY);
           printf("%c", B2[i][j]);
        }
    }
}

void imprime_rampadir(TIPO_FASE rdireita){
 char RD[Y_PDR][X_PDR*2]={{' ',' ',' ','_','.','-'},{'_','.','-',' ',' ',' '}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((rdireita.coluna_inicial)*3,((rdireita.linha_inicial)*2+i));
        for (j=0;j<X_PDR*2;j++){
           printf("%c", RD[i][j]);
        }
    }
}

void imprime_rampaesq(TIPO_FASE resquerda){
 char RD[Y_PDR][X_PDR*2]={{'-','.','_',' ',' ',' '},{' ',' ',' ','-','.','_'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((resquerda.coluna_inicial)*3,((resquerda.linha_inicial)*2+i));
        for (j=0;j<X_PDR*2;j++){
           printf("%c", RD[i][j]);
        }
    }
}

void cor_escadas(int a){
 if (a==1)text_color(GRAY);
 else {
  text_color(RED);
    }
}
//-------------------------------------------------------------//

void imprime_fase(TIPO_FASE vetor_objetos[], int  qtd_objetos,int vidas){
    int i;
    for (i=0;i<qtd_objetos;i++)
    {
    switch(vetor_objetos[i].tipo){


            case 'M': imprime_mario(vetor_objetos[i]);
                break;
            case 'P': imprime_princesa( vetor_objetos[i]);
                break;
            case 'K': imprime_donk1( vetor_objetos[i]);
                break; // sim era para ser D mas no bin ta K, ok n�
            case 'G': imprime_rampaesq( vetor_objetos[i]);
                break;
            case 'F': imprime_rampadir( vetor_objetos[i]);
                break;
            case 'S': imprime_superficie( vetor_objetos[i]);
                break;
            case 'E': imprime_escOK( vetor_objetos[i]);
                break;
            case 'Q':  imprime_escQ( vetor_objetos[i]);
                 break;
            case 'H':  imprime_escFIM( vetor_objetos[i]);
                break;
            case 'B':if( vetor_objetos[i].velocidade>0){
                        imprime_barril_m( vetor_objetos[i]);
                        }// barril que se mexe
                     else
                       imprime_barril_e( vetor_objetos[i]);
                        break;
            }//

        }

    gotoxy(0,-2);
    printf("VIDAS %d \n", vidas);
//    printf("SCORE ATUAL/MAX: %d / %d",paraimpressao->score_atual, paraimpressao->score_max);
}

mapeia_fase(JOGO *mapadojogo,int qtd_objetos,int vidas_jogador){
  int i;
    mapadojogo->num_obj=qtd_objetos;
    for (i=0;i<qtd_objetos;i++)
    {
    switch(mapadojogo->vetor_objetos[i].tipo){


            case 'M': mapadojogo->mario.y = (mapadojogo->vetor_objetos[i].linha_inicial)*2; // OBS: X = LINHA * 2, Y = COLUNA * 3 (x,y) s�o as coordenadas reais no prompt do C[0][0]
                      mapadojogo->mario.x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      mapadojogo->inc_mario.coluna_inicial=(mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      mapadojogo->inc_mario.linha_inicial=(mapadojogo->vetor_objetos[i].linha_inicial)*2;
                break;
            case 'P': mapadojogo->princesa.y = (mapadojogo->vetor_objetos[i].linha_inicial)*2; // OBS: X = LINHA * 2, Y = COLUNA * 3 (x,y) s�o as coordenadas reais no prompt do C[0][0]
                      mapadojogo->princesa.x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                break;
            case 'K': mapadojogo->donkey.y = (mapadojogo->vetor_objetos[i].linha_inicial)*2; // OBS: X = LINHA * 2, Y = COLUNA * 3 (x,y) s�o as coordenadas reais no prompt do C[0][0]
                      mapadojogo->donkey.x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                break; // sim era para ser D mas no bin ta K, ok n�
            case 'G': mapadojogo->rampa_esquerda[mapadojogo->indices.i_rampa_esquerda].y = (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                      mapadojogo->rampa_esquerda[mapadojogo->indices.i_rampa_esquerda].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      (mapadojogo->indices.i_rampa_esquerda)++;
                break;
            case 'F': mapadojogo->rampa_direita[mapadojogo->indices.i_rampa_direita].y= (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                      mapadojogo->rampa_direita[mapadojogo->indices.i_rampa_direita].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      (mapadojogo->indices.i_rampa_direita)++;
                break;
            case 'S': mapadojogo->superficie[mapadojogo->indices.i_superficie].y = (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                      mapadojogo->superficie[mapadojogo->indices.i_superficie].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      (mapadojogo->indices.i_superficie)++;
                break;
            case 'E': mapadojogo->escada_meio[mapadojogo->indices.i_escada_meio].y = (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                      mapadojogo->escada_meio[mapadojogo->indices.i_escada_meio].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      (mapadojogo->indices.i_escada_meio)++;
                break;
            case 'Q': mapadojogo->escada_quebrada[mapadojogo->indices.i_escada_quebrada].y = (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                      mapadojogo->escada_quebrada[mapadojogo->indices.i_escada_quebrada].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      (mapadojogo->indices.i_escada_quebrada)++;
                 break;
            case 'H':  mapadojogo->escada_topo[mapadojogo->indices.i_escada_topo].y = (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                      mapadojogo->escada_topo[mapadojogo->indices.i_escada_topo].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                      (mapadojogo->indices.i_escada_topo)++;
                break;
            case 'B':if(mapadojogo->vetor_objetos[i].velocidade>0){
                        mapadojogo->barril_m[mapadojogo->indices.i_barril_m].y = (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                        mapadojogo->barril_m[mapadojogo->indices.i_barril_m].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                        (mapadojogo->indices.i_barril_m)++;
                        }// barril que se mexe
                     else
                        mapadojogo->barril_e[mapadojogo->indices.i_barril_e].y = (mapadojogo->vetor_objetos[i].linha_inicial)*2;
                        mapadojogo->barril_e[mapadojogo->indices.i_barril_e].x = (mapadojogo->vetor_objetos[i].coluna_inicial)*3;
                        (mapadojogo->indices.i_barril_e)++; // barril est�tico/ parado
                        break;
            }//

        }

    gotoxy(0,-2);
    printf("VIDAS %d \n", vidas_jogador);
    printf("SCORE ATUAL/MAX: %d / %d",mapadojogo->score_atual, mapadojogo->score_max);
}
void ler_menu_pausa(){
    system("cls");
    Beep(500, 40);
    text_color(AQUA);
    int c;
    FILE *info;
    info = fopen("pausa.txt", "r");
    if (info) {
        while ((c = getc(info)) != EOF)
            putchar(c);
        fclose(info);
    }
    else {
        system("cls");
        printf("Erro ao apresentar as intru��es, verifique a existencia do arquivo pausa.txt");
        printf("\nPressione qualquer tecla para retornar ao jogo");
        getch();
    }
}

int menu_pausa(){
    system("cls");
    int x =19 , y[] = {19, 21, 23};
    int contador = 0, sair = FALSE; // Coordenadas da seta, contador �ndice da seta, booleano sair para sair do menu
   // text_color(RED); // Cor vermelha
    ler_menu_pausa();
    int key;
    do // Faz ao menos uma vez
    {
        gotoxy(x, y[contador]); // Move o cursor para (x, y[contador])
        printf(">"); // Imprime a seta
        key=getch();
        switch(key)
        {
            case 'p': sair=TRUE;
                    contador=0;
            case 's'://salva jgo
                    break;
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
                                contador = 2; // Define contador como 2 (�ltima posi��o na tela)
                            }
                       break;

            case BAIXO: if(contador != 2) // Caso o usu�rio aperte direcional para baixo
                        { // Se o contador n�o estiver na �ltima posi��o
                           gotoxy(x, y[contador]);
                           printf(" "); // Apaga a seta anterior
                           contador++; // Incrementa o contador
                        }
                        else if(contador == 2)
                             { // Se o contador estiver na �ltima posi��o
                                 gotoxy(x, y[contador]);
                                 printf(" "); // Apaga a seta anterior
                                 contador = 0; // Define o contador como 0 (primeira posi��o na tela)
                             }
                        break;
            case SPACEBAR:
            case ENTER: if (contador==2){
                        }
                        else {
                        sair = TRUE;
                        return SAIR;
                        } // Se o usu�rio teclar ENTER, sai do loop
                        break;

            case ESC: return SAIR;
                      break;
        }

        Beep(500, 40); // B E E P

    }while(!sair); // Enquanto "n�o sair"
    return contador;
}


/* ############ CHANGELOG ############
    ############ Legenda: ###########

         '-' : Mudan�a
        '->' : Subt�pico da mudan�a
    '####=>' : Importante ler
    ########### ######### ###########

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
    - Cria��o da struct PARAMETROS

Pedro, 19/06:
    - Adapta��o da fun��o jogo();
    - Contador de vidas; (Tem que adaptar para os barris moveis ainda)
    - Implementa��o das telas de vit�ria e derrota;
    - Mudan�a na fun��o de move_mario();
    - Cria��o do define PAUSE;
    - Implementa��o do PAUSE; (Tem que criar a fun��o salvar_jogo() )
    - Adapta��o de tudo para o struct PARAMETROS;
    - Cria��o da fun��o apaga_mario(); para deixar mais claro o c�digo de mover
    - Cria��o da fun��o posiciona_mario(); para deixar mais claro o c�digo ----> Pode substituir a imprime_mario()
    - Cria��o de define paras as CORES;

    Ideias: - Fazer uma fun��o que retorna 0 ou 1 para ver se as posi��es batem
            - Adicionar mais campos em PARAMETROS:
              -> Vetor superficie, vetor escada normal, vetor escada quebrada, vetor fim escada, vetor rampad, vetor rampae para controlar o movimento e usar a fun��o acima
              -> OBS.: Declarar esses vetores como ponteiros e alocar mem�ria para eles
              -> OBS2.: Vai precisar de um define de MAX para cada um dos vetores
           ###=> Ser� que � mesmo necess�rio usar matrizes nessas fun��es de impress�o inicial?
            - Colocar cor diferente nas impress�es (dentro de cada fun��o imprimeX() colocar uma cor)
Vitor, 22/06
        - Cria��o menu pausa
        - Implementa��o das cores
        - Cira��o da fun��o cor_escadas e  e colocar��o de algumas outras cores

        Considera��es:
        ####=> Vamos mesmo usar so memalloc, ser� que o sor n�o vai xiar? Se quiser fiz uma vers�o que ta igual mas sem isso
        -> Podemos sim meter  as  cores nas coisas eheh, j� fiz um pouco disso e  quanto ao posiciona mario no lugar  do imprime mario, at� pode ser, so acho que fica um pouco mais chato
        pra colotir ele eheheh;
        */
