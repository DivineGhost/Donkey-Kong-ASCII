
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
    5-Variáveis auxialiares devem definidas no inicio de uma função para fa-
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
#define Y_MAX 62       // Y max do prompt e x max do prompt
#define X_MAX 46
#define MAX_BARRIL 15
// códigos internos
#define ERRO -1
#define NOVOJOGO 0
#define CONTINUARJOGO 1
#define SAIR 2
#define DERROTA 3
#define VITORIA 4
 // código  das teclas
#define SPACEBAR 32
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define ENTER 13

// definições de coisas a desenvolver  e testes
#define XPDR 3
#define YPDR 2
#define GRAVIDADE 0.5 // numero de posições por time stamp
#define JUMPPOWER 3  //  velocidade/ impulso do pulo
#define TEMPO 100 //

//#define DEBUG  // tipo de definição muito útil que descobri
/* tudo que eu escrever  dentro de uma estrutura como
#ifdef DEBUG
código vai aqui
#endif // DEBUG
só roda enquanto esse cara estiver definido. Assim se comentar essa def aqui em cima
nenhum deles roda e não temos que tirar do código nem nada. Dai fica muito útil para testes
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
//#######################4-SKETCHES DE FUNÇÕES############################//


void hide_cursor(); // ensconde cursor, OK
int mainMenu(); // menu , OK
int setas(); // setas OK
void gotoxy(int,int); // mudar posicação do cursor , OK
void textcolor(int);  // cor linda, OK
int lermapa(TIPO_FASE[]);  //ok
void formatprompt(); // já esta OK

//         EM TESTE ou a fazer

/*Boas mano, tu  vai ver que tem muita coisa meio repetida nas funções de imprimir, se conseguir tenta optimizar isso
acredito tambem que devemos fazer duas gotoxy uma para coisas tipo texto setas e etc e outra para os objetos
qualquer dúvida me pede. tentei deixar o negóio de impressão pronto agr a jogabilidade é contigo heheh, pq essa semana
 vai ficar meio foda pra mim fazer algo */

void imprime_fase(TIPO_FASE[],int, CONTROLE*, CONTROLE*, CONTROLE*, CONTROLE[]); //ok
void move_mario(CONTROLE*); //a fazer
void imprime_tela_incial(); // ok
void imprime_instrucoes(); //ok
void imprime_mario(TIPO_FASE);// para imprimir o mário, mais ou menos
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
    TIPO_FASE *vetorobjetos = malloc(sizeof(TIPO_FASE) * NUMMAXOBJ);  // inicialização do vetor de controle, aloca NUMMAXOBJ espaços para TIPO_FASE, é igual a um vetor, mas declarado como ponteiro
    CONTROLE *mario = malloc(sizeof(CONTROLE));
    CONTROLE *princesa = malloc(sizeof(CONTROLE));
    CONTROLE *donkey = malloc(sizeof(CONTROLE));
    CONTROLE barrilm[MAX_BARRIL];
    controle_menu(vetorobjetos, mario, princesa, donkey, barrilm); // Função que controla as opções do menu principal
    return 0;
}
//######################6-FUNÇÕES OK############################//

int controle_menu(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[])
{
    int controle; //inicialização de variaveis de controle,score e indice do for de inicialização
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
            arrayobj[contador]=buffer;  // aqui de fato é feito o armazenamento de dados
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

 void formatprompt() // Formatação do prompt
{
    setlocale(LC_ALL, "Portuguese"); // Língua para português  //prompt em português para acentos e afins
    system("title Donkey Kong"); // Muda nome do prompt
    system("color 03");                             // Cor normal do prompt
    system("mode 60, 48");                           // Modo para não exceder o buffer
    SMALL_RECT WinRect = {0, 0, X_MAX, Y_MAX};       // Formata o tamanho do prompt
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, WinSize);

    hide_cursor();
}

//-------------------------------------------------------------//

void textcolor(int ForgC) // Função para colorir o texto
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

//-------------------------------------------------------------//

int mainMenu() // Menu principal do jogo
{
    formatprompt();  // seta tamanho e lingua
    int x =24 , y[] = {27, 31, 35,39};
    int contador = 0, sair = FALSE; // Coordenadas da seta, contador índice da seta, booleano sair para sair do menu
    system("cls"); // Limpa a tela
    textcolor(12); // Cor vermelha
    imprime_tela_incial();

    do // Faz ao menos uma vez
    {
        gotoxy(x, y[contador]); // Move o cursor para (x, y[contador])
        printf(">"); // Imprime a seta
        switch(setas())
        {
            case CIMA: if(contador != 0) // Caso o usuário aperte direcional para cima
                       { // Se o contador não estiver na primeira posição
                           gotoxy(x, y[contador]);
                           printf(" "); // Apaga a seta anterior
                           contador--; // Decrementa o contador
                       }
                       else if(contador == 0)
                            { // Se o contador estiver na primeira posição
                                gotoxy(x, y[contador]);
                                printf(" "); // Apaga a seta anterior
                                contador = 3; // Define contador como 2 (última posição na tela)
                            }
                       break;

            case BAIXO: if(contador != 3) // Caso o usuário aperte direcional para baixo
                        { // Se o contador não estiver na última posição
                           gotoxy(x, y[contador]);
                           printf(" "); // Apaga a seta anterior
                           contador++; // Incrementa o contador
                        }
                        else if(contador == 3)
                             { // Se o contador estiver na última posição
                                 gotoxy(x, y[contador]);
                                 printf(" "); // Apaga a seta anterior
                                 contador = 0; // Define o contador como 0 (primeira posição na tela)
                             }
                        break;
            case SPACEBAR:
            case ENTER: if (contador==2){
                        imprime_instrucoes();
                        }
                        else {
                        sair = TRUE;
                        } // Se o usuário teclar ENTER, sai do loop
                        break;

            case ESC: if(contador != 3) // Se o usuário teclar ESC (No caso seria um atalho para sair do programa rapidamente)
                      { // Se o contador for diferente de 2
                          gotoxy(x, y[contador]);
                          printf(" ");
                          contador = 3; // Move a seta para a última posição
                      }
                      else return SAIR;
                      break;
        }

        Beep(500, 40); // B E E P

    }while(!sair); // Enquanto "não sair"
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
void jogo(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[]) // ver como fazer pra descobrir a posição do donk, barril e princesa
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

void vitoria(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[]) // Basicamente cópia da função imprime_tela_inicial();
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
    gotoxy(5, 15); // Achar posição boa
    printf("Pontuação final: %d / Pontuação máxima: %d", mario->score_atual, mario->score_max);
    gotoxy(7, 17);
    printf("Pressione ESC para retornar ao menu. . .");
    if(getch()==ESC)
    {
        controle_menu(vetorobjetos, mario, princesa, donkey, barrilm); // Retorna à rotina de controle do menu
        Beep(500, 40);
    }
}

//-------------------------------------------------------------------------//

void derrota(TIPO_FASE *vetorobjetos, CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[]) // Basicamente igual à vitoria
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
    gotoxy(5, 15); // Achar posição boa
    printf("Pontuação final: %d / Pontuação máxima: %d", mario->score_atual, mario->score_max);
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
    info = fopen("menuinfo.txt", "r"); // agora se quiser trocar o menu é só trocar aqui dai o código fica menos poluído.
                                    // além disso agr é so tu escrever num txt normal sem ter que por aspas ou \n ou \\ para imprimir barras :)
    if (info) {
        while ((c = getc(info)) != EOF)
            putchar(c);
        fclose(info);
    getch();
    }
    else {
        printf("Erro ao apresentar as intruções, verifique a existencia do arquivo menuinfo.txt");
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
    menu = fopen("menu.txt", "r"); // agora se quiser trocar o menu é só trocar aqui dai o código fica menos poluído.
                                    // além disso agr é so tu escrever num txt normal sem ter que por aspas ou \n ou \\ para imprimir barras :)
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
              printf("_Ô_");
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
              printf("_Ô_");
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
              printf("_Ô_");
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
              printf("_Ô_");
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

void imprime_mario(TIPO_FASE mario){  // observação, não sei se não é melhor fazer como tu tava fazendo
    char M[YPDR][XPDR]={{'\\','ô','/'},{'/','H','\\'}};
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
    char D[YPDR][XPDR]={{'}','ô','{'},{'_','H','_'}};
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
       FILE * vitor; // para analisar se a impressão esta  correta
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
       c=getch( ); //espera tu teclar algo para a impressão dai fica mais visual se ta fazendo certo
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
                       imprime_barrile(paraimpressao[i]);  // barril estático/ parado
                     break;
            }//*/
        }
        #ifdef DEBUG
            fclose(vitor);
        #endif // DEBUG
}


/* ############ CHANGELOG ############
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
    - Criação da struct PARAMETROS ----- LER ISSO ---- -> Preciso saber o que tu acha de mover os scores e as vidas pro PARAMETROS, daí fica mais fácil de passar os bagulhos por referência
      ----------------------------------------------------Se tu for ver, eu tive que colocar várias vezes (CONTROLE *mario, CONTROLE *princesa, CONTROLE *donkey, CONTROLE barrilm[])
     -----------------------------------------------------Então seria conveniente ter uma struct PARAMETROS contendo essas variáveis, tipo o que eu fiz lá em cima, mas preciso saber se tu acha
      ----------------------------------------------------Que isso vai dar certo, hahahaha
*/
