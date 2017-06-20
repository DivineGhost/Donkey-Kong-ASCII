/***************************DONKEY KONG ASCII**********************************
   **************************DESENVOLVIDO POR*******************************
                          Pedro Rodrigues de Lima
                                   &
                         Vitor Almeida de Carvalho
    *******************SINTAXE_DE_ORGANIZA��O_DE_C�DIGO*********************
    1-As �reas s�o delimitadas por cabe�alhos do tipo: //###NOME_DA_AREA###//
    2-Ap�s o sketch de cada fun��o h� um coment�rio sobre sua utilidade.
    3-Caso algum item necessite, haver� um coment�rio logo em seguida.
    4-Os nomes de vari�veis compostas tem o caractere '_' indicando um espa�o.
    5-Vari�veis auxialiares devem definidas no inicio de uma fun��o para fa-
    cilitar a leitura;
    6-Utilizar nomes explicativos para vari�ves. Ex:int posicao_do_mario.
    Ex: variavel_com_nome_muito_grande
    ***************************ESTRUTURA_DO_C�DIGO**************************
    Este arquivo est� dividido de forma a agrupar em �reas, por similaridade,
    os trechos de c�digo. S�o as �reas:
        0-REFERENCIAS: Onde est�o alguns dados  �teis para a elabora��o do
        c�digo.
        1-BIBILIOTECAS: Onde est�o listadas as bibliotecas utilizadas no de-
        senvolvimento do programa.
        2-DEFINI��ES: Onde est�o definidos as constantes utilizadas pelo pro-
        grama.
        3-STRUCTS- Onde est�o definidos todos os tipos criados para esse pro-
        jeto.
        4-SKETCHES DE FUN��ES:Onde est�o apresentadas todas as fun��es cria-
        das com tipo de parametros.
        5-MAIN: Onde est� o main do programa.
        6-FUN��ES: Onde est�o as fun��es/subrotinas criadas para o jogo.
*******************************************************************************/

/*0-REFERENCIAS
Refer�ncia das cores da fun��o text_color()
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
 // c�digo  das teclas
#define SPACEBAR 32
#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define ENTER 13
// testes
#define DELAY 100 // Tempo padr�o de delay

// #define DEBUG  //
/*
#ifdef DEBUG
codigo
#endif // DEBUG
*/
//######################3-STRUCTS############################//

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

typedef struct PARAMETROS{
    TIPO_FASE *vetor_objetos;
    TIPO_FASE *inc_mario;
    CONTROLE *mario;
    CONTROLE *princesa;
    CONTROLE *donkey;
    CONTROLE *barril_m;
    CONTROLE *barril_e;
    CONTROLE *superficie;
    CONTROLE *escada_topo;
    CONTROLE *escada_meio;
    CONTROLE *escada_quebrada;
    CONTROLE *rampa_direita;
    CONTROLE *rampa_esquerda;
    int score_atual;
    int score_max;
    int vidas;
    INDICES *indices;

}PARAMETROS;

//#######################4-SKETCHES DE FUN��ES############################//

void hide_cursor();                 // Esconde o cursor do prompt OK
int main_menu();                     // Menu principal, retorna a op��o selecionada pelo jogador
int setas();                        // Utiliza��o das setas direcionais do teclado OK
void gotoxy(int,int);               // Move o cursor do prompt para uma certa posi��o OK
void text_color(int);                // Muda a cor do texto do prompt de acordo com o c�digo de cores OK
int ler_mapa(TIPO_FASE[]);          // L� um arquivo fase.bin OK
void format_prompt();                // Formata o prompt: Define dimens�es e linguagem padr�o OK
void imprime_fase(PARAMETROS*,int); // Imprime o mapa OK
int move_mario(PARAMETROS*);        // Move o m�rio A FAZER
void apaga_mario(PARAMETROS*);      // Apaga a posi��o do m�rioOK
void posiciona_mario(PARAMETROS*);  // Imprime o m�rio OK
void imprime_tela_incial();         // Imprime a tela inicial (menu principal) OK
void imprime_instrucoes();          // Imprime a tela de instru��es OK
void imprime_mario(TIPO_FASE);      // MAIS OU MENOS
void imprime_donk1(TIPO_FASE);      // MAIS OU MENOS
void imprime_donk2(TIPO_FASE);      // MAIS OU MENOS
void imprime_barril_m(TIPO_FASE);    // MAIS OU MENOS
void imprime_barrile(TIPO_FASE);    // MAIS OU MENOS
void imprime_princesa(TIPO_FASE);   // MAIS OU MENOS
void imprime_escOK(TIPO_FASE);      // MAIS OU MENOS
void imprime_escQ(TIPO_FASE);       // MAIS OU MENOS
void imprime_escFIM(TIPO_FASE);     // MAIS OU MENOS
void imprime_rampadir(TIPO_FASE);   // MAIS OU MENOS
void imprime_rampaesq(TIPO_FASE);   // MAIS OU MENOS
void imprime_superficie(TIPO_FASE); // MAIS OU MENOS
void novo_jogo(PARAMETROS*);        // Come�a um jogo totalmente novo OK
void jogo(PARAMETROS*);             // Roda o jogo QUASE OK
void vitoria(PARAMETROS*);          // Imprime uma tela de vit�ria OK
void derrota(PARAMETROS*);          // Imprime uma tela de derrota OK
int controle_menu(PARAMETROS*);     // Controla a op��o selecionada pelo jogador OK
//void salva_jogo();
//void carrega_jogo();
//void pausa_jogo();
//void joga_barril();

//######################5-MAIN############################//

int main(){
    PARAMETROS *parametros = malloc(sizeof(PARAMETROS)); // Vari�vel ponteiro utilizada para tudo, junto da aloca��o de espa�o como declara��o do ponteiro
    parametros->mario = malloc(sizeof(CONTROLE));
    parametros->princesa = malloc(sizeof(CONTROLE));
    parametros->donkey = malloc(sizeof(CONTROLE));
    parametros->barril_m = malloc(sizeof(CONTROLE)* MAX_BARRIL_M);
    parametros->barril_e = malloc(sizeof(CONTROLE)* MAX_BARRIL_E);
    parametros->superficie = malloc(sizeof(CONTROLE)* MAX_SUPERFICIE);
    parametros->escada_topo = malloc(sizeof(CONTROLE)* MAX_ESCADA_TOPO);
    parametros->escada_meio = malloc(sizeof(CONTROLE)* MAX_ESCADA_MEIO);
    parametros->escada_quebrada = malloc(sizeof(CONTROLE)* MAX_ESCADA_QUEB);
    parametros->rampa_direita = malloc(sizeof(CONTROLE)* MAX_RAMPA_DIREITA);
    parametros->rampa_esquerda = malloc(sizeof(CONTROLE)* MAX_RAMPA_ESQUERDA);

    parametros->inc_mario = malloc(sizeof(TIPO_FASE));
    parametros->vetor_objetos = malloc(sizeof(TIPO_FASE)* MAX_OBJ);
    parametros->indices = malloc(sizeof(INDICES));
    parametros->indices->i_barril_m = 0;
    parametros->indices->i_barril_e = 0;
    parametros->indices->i_superficie = 0;
    parametros->indices->i_escada_topo = 0;
    parametros->indices->i_escada_meio = 0;
    parametros->indices->i_escada_quebrada = 0;
    parametros->indices->i_rampa_direita = 0;
    parametros->indices->i_rampa_esquerda = 0;

    controle_menu(parametros); // Fun��o que controla as op��es do menu principal

    return 0;
}
//######################6-FUN��ES############################//

int controle_menu(PARAMETROS *parametros){
    int controle;
    int indfor;
    for (indfor=0;indfor<MAX_OBJ;indfor++)
        parametros->vetor_objetos[indfor].tipo='Z';
    controle=main_menu();
    switch(controle)
    {
    case NOVOJOGO:
         novo_jogo(parametros);
         jogo(parametros);
         break;
    case CONTINUARJOGO:
         printf("A continuar");
         // A FAZER...carrega_jogo();
         // jogo();
         break;
    case SAIR:
         return 0;
         break;
    }
}

int ler_mapa(TIPO_FASE vetor_objetos[]){
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
            vetor_objetos[contador]=buffer;  // aqui de fato � feito o armazenamento de dados
            contador++;
            }
    }
    fclose(fase);
    return contador;
}

void hide_cursor(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Esconde o Cursor do console
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

 void format_prompt(){
    setlocale(LC_ALL, "Portuguese"); // L�ngua para portugu�s  //prompt em portugu�s para acentos e afins
    system("title Donkey Kong"); // Muda nome do prompt
    system("color 03");                             // Cor normal do prompt
    system("mode 60, 48");                           // Modo para n�o exceder o buffer
    SMALL_RECT WinRect = {0, 0, X_MAX, Y_MAX};       // Formata o tamanho do prompt
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, WinSize);

    hide_cursor();
}

void text_color(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void gotoxy (int x, int y){
 COORD coord = {0, 0};
 coord.X =x; coord.Y = y+2; // X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int setas(){
    int valor_seta; // Pode ser apenas os valores definidos no cabe�alho

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

int main_menu(){
    format_prompt();  // seta tamanho e lingua
    int x =24 , y[] = {27, 31, 35, 39};
    int contador = 0, sair = FALSE; // Coordenadas da seta, contador �ndice da seta, booleano sair para sair do menu
    system("cls"); // Limpa a tela
    text_color(12); // Cor vermelha
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

void apaga_mario(PARAMETROS *parametros){
    gotoxy(parametros->mario->y, parametros->mario->x);
    printf("   ");
    gotoxy(parametros->mario->y, parametros->mario->x+1);
    printf("   ");
}

void posiciona_mario(PARAMETROS *parametros){
    gotoxy(parametros->mario->y,parametros->mario->x);
    printf("\\�/");
    gotoxy(parametros->mario->y, (parametros->mario->x)+1);
    printf("/H\\");
    hide_cursor();
}

void novo_jogo(PARAMETROS *parametros){
    int num_objetos;
    system("cls");
    parametros->score_atual=SCORE_INICIAL;
    parametros->score_max=SCORE_INICIAL;
    parametros->vidas=VIDAS_INICIAIS;
    num_objetos=ler_mapa(parametros->vetor_objetos);
    if(num_objetos==ERRO)
        printf("Erro na leitura do arquivo, reinicie o programa");
    else
        imprime_fase(parametros,num_objetos);
}

void jogo(PARAMETROS *parametros){

    int condition = 0;
    while(condition != PAUSE && condition != VITORIA)
    {
        condition = move_mario(parametros);
        switch(condition)
        {
            case DERROTA: if(parametros->vidas == 0)
                            derrota(parametros);
                          else
                          {
                            (parametros->vidas)--;
                            apaga_mario(parametros);
                            imprime_fase(parametros, MAX_OBJ);
                          }
                          break;
            case VITORIA: vitoria(parametros);
                          break;
            case PAUSE: //salvar jogo();
                          controle_menu(parametros);
                          break;
        }
    }
}

void vitoria(PARAMETROS *parametros){
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
        controle_menu(parametros); // Retorna � rotina de controle do menu
        Beep(500, 40);
    }
}

void derrota(PARAMETROS *parametros){
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
    printf("Pressione ESC para retornar ao menu. . .");
    if(getch()==ESC)
    {
        controle_menu(parametros);
        Beep(500, 40);
    }
}

void imprime_instrucoes(){
    system("cls");
    Beep(500, 40);
    text_color(LIGHT_GREEN);
    int c;
    FILE *info;
    info = fopen("menuinfo.txt", "r");
    if (info) {
        while ((c = getc(info)) != EOF)
            putchar(c);
        fclose(info);
    getch();
    }
    else {
        system("cls");
        printf("Erro ao apresentar as intru��es, verifique a existencia do arquivo menuinfo.txt");
        printf("\nPressione qualquer tecla para retornar ao menu");
        getch();
    }
    imprime_tela_incial();
}

void imprime_tela_incial(){
    system("cls");
    text_color(LIGHT_RED);
    int c;
    FILE *menu;
    menu = fopen("menu.txt", "r");
    if (menu) {
        while ((c = getc(menu)) != EOF)
            putchar(c);
        fclose(menu);
    }
}

int move_mario(PARAMETROS *parametros){

    text_color(LIGHT_RED);
    char key;
    while(key!=ESC && key!= 'P'){  // Se uma dessas teclas for pressionada
    Sleep(DELAY); // Delay
    if (kbhit())
    {
        key = toupper(getch());
        switch(key)
        {
        case 'A': apaga_mario(parametros);
                  (parametros->mario->y)--;
                  posiciona_mario(parametros);
                  break;

        case 'D': apaga_mario(parametros);
                  (parametros->mario->y)++;
                  posiciona_mario(parametros);
                  break;

        case 'W': apaga_mario(parametros);
                  (parametros->mario->x)--;
                  posiciona_mario(parametros);
                  break;

        case 'S': apaga_mario(parametros);
                  (parametros->mario->x)++;
                  posiciona_mario(parametros);
                  break;

// case SPACEBAR:
        }

   }

    if(parametros->mario->x == parametros->donkey->x && parametros->mario->y == (parametros->donkey->y)+2)
        return DERROTA;
    else if(parametros->mario->x == (parametros->princesa->x) && parametros->mario->y == (parametros->princesa->y)-2)
        return VITORIA;
         //else if(coisa do barril)
   }
   return PAUSE;
}

void imprime_mario(TIPO_FASE mario){
    char M[Y_PDR][X_PDR]={{'\\','�','/'},{'/','H','\\'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((mario.coluna_inicial)*3,(mario.linha_inicial)*2+i);
        for (j=0;j<3;j++){
            printf("%c", M[i][j]);
        }
    }
}

void imprime_donk1(TIPO_FASE donk){
    char D[Y_PDR][X_PDR]={{'}','�','{'},{'_','H','_'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((donk.coluna_inicial)*3,(donk.linha_inicial)*2+i);
        for (j=0;j<X_PDR;j++){
            printf("%c", D[i][j]);
        }
    }
}

void imprime_donk2(TIPO_FASE donk){
    char D[Y_PDR][X_PDR]={{'\\','o','/'},{'/',' ','\\'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy(donk.coluna_inicial,donk.linha_inicial+i);
        for (j=0;j<X_PDR;j++){
            printf("%c", D[i][j]);
        }
    }
}

void imprime_princesa(TIPO_FASE prin){
    char P[Y_PDR][X_PDR]={{'\\','o','/'},{'/','=','\\'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((prin.coluna_inicial)*3,(prin.linha_inicial)*2+i);
        for (j=0;j<X_PDR;j++){
            printf("%c", P[i][j]);
        }
    }
}

void imprime_superficie(TIPO_FASE superficie){
  char S[Y_PDR][X_PDR]={{'X','X','X'},{'X','X','X'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((superficie.coluna_inicial)*3,((superficie.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
           printf("%c", S[i][j]);
        }
    }
}

void imprime_escFIM(TIPO_FASE escfim){
  char H[Y_PDR][X_PDR]={{'|','X','|'},{'|','-','|'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((escfim.coluna_inicial)*3,((escfim.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
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
           printf("%c", E[i][j]);
        }
    }
}

void imprime_escQ(TIPO_FASE escquebrada){
 char E[Y_PDR][X_PDR]={{'|','-','|'},{' ','-','|'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((escquebrada.coluna_inicial)*3,((escquebrada.linha_inicial)*2+i));
        for (j=0;j<X_PDR;j++){
           printf("%c", E[i][j]);
        }
    }
}

void imprime_barrile(TIPO_FASE barrilparado){
 char B1[Y_PDR][X_PDR]={{'/','^','\\'},{'\\','Z','/'}};
    int i,j;
    for (i=0;i<Y_PDR;i++){
            gotoxy((barrilparado.coluna_inicial)*3,((barrilparado.linha_inicial)*2+i));
        for (j=0;j<3;j++){
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
void imprime_fase(PARAMETROS *parametros, int qtd_objetos){ // CHECAR ESSA CONVERSAO
    int i, j=0;
    text_color(AQUA);
    for (i=0;i<qtd_objetos;i++)
    {
        switch(parametros->vetor_objetos[i].tipo)
        {
            case 'M': imprime_mario(parametros->vetor_objetos[i]);
                      parametros->mario->x = (parametros->vetor_objetos[i].linha_inicial)*2; // OBS: X = LINHA * 2, Y = COLUNA * 3 (x,y) s�o as coordenadas reais no prompt do C[0][0]
                      parametros->mario->y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      parametros->inc_mario->linha_inicial = parametros->mario->x; // Iniciais do mario, caso precise
                      parametros->inc_mario->coluna_inicial = parametros->mario->y;
                      break;
            case 'P': imprime_princesa(parametros->vetor_objetos[i]);
                      parametros->princesa->x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->princesa->y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      break;
            case 'K': imprime_donk1(parametros->vetor_objetos[i]);
                      parametros->donkey->x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->donkey->y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      break;
            case 'G': imprime_rampaesq(parametros->vetor_objetos[i]);
                      parametros->rampa_esquerda[parametros->indices->i_rampa_esquerda].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->rampa_esquerda[parametros->indices->i_rampa_esquerda].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      (parametros->indices->i_rampa_esquerda)++;
                      break;
            case 'F': imprime_rampadir(parametros->vetor_objetos[i]);
                      parametros->rampa_direita[parametros->indices->i_rampa_direita].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->rampa_direita[parametros->indices->i_rampa_direita].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      (parametros->indices->i_rampa_direita)++;
                      break;
            case 'S': imprime_superficie(parametros->vetor_objetos[i]);
                      parametros->superficie[parametros->indices->i_superficie].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->superficie[parametros->indices->i_superficie].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      (parametros->indices->i_superficie)++;
                      break;
            case 'Q': imprime_escQ(parametros->vetor_objetos[i]);
                      parametros->escada_quebrada[parametros->indices->i_escada_quebrada].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->escada_quebrada[parametros->indices->i_escada_quebrada].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      (parametros->indices->i_escada_quebrada)++;
                      break;
            case 'E': imprime_escOK(parametros->vetor_objetos[i]);
                      parametros->escada_meio[parametros->indices->i_escada_meio].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->escada_meio[parametros->indices->i_escada_meio].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      (parametros->indices->i_escada_meio)++;
                      break;
            case 'H': imprime_escFIM(parametros->vetor_objetos[i]);
                      parametros->escada_topo[parametros->indices->i_escada_topo].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                      parametros->escada_topo[parametros->indices->i_escada_topo].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                      (parametros->indices->i_escada_topo)++;
                      break;
            case 'B':if((parametros->vetor_objetos[i].velocidade)>0)  // barril que se mexe
                    {
                        imprime_barril_m(parametros->vetor_objetos[i]);
                        parametros->barril_m[parametros->indices->i_barril_m].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                        parametros->barril_m[parametros->indices->i_barril_m].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                        (parametros->indices->i_barril_m)++;
                    }
                     else
                     {
                        imprime_barrile(parametros->vetor_objetos[i]);  // barril est�tico
                        parametros->barril_e[parametros->indices->i_barril_e].x = (parametros->vetor_objetos[i].linha_inicial)*2;
                        parametros->barril_e[parametros->indices->i_barril_e].y = (parametros->vetor_objetos[i].coluna_inicial)*3;
                        (parametros->indices->i_barril_e)++;
                     }
                     break;
        }
    }
    gotoxy(0,-2);
    printf("VIDAS %d \n", parametros->vidas);
    printf("SCORE ATUAL/MAX: %d / %d",parametros->score_atual, parametros->score_max);


   /* Teste indices
    printf("%d\n", parametros->indices->i_escada_topo);
    printf("%d\n", parametros->indices->i_escada_meio);
    printf("%d\n", parametros->indices->i_escada_quebrada);
    printf("%d\n", parametros->indices->i_barril_e);
    printf("%d\n", parametros->indices->i_barril_m);
    printf("%d\n", parametros->indices->i_superficie);
    printf("%d\n", parametros->indices->i_rampa_direita);
    printf("%d", parametros->indices->i_rampa_esquerda);
    system("pause");*/
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

Pedro, 20/06
    - Cria��o da struct INDICES que cont�m o n�mero total de cada elemento na fase
    - Cria��o de vari�veis CONTROLE e uma vari�vel INDICES dentro da struct PARAMETROS
        -> Talvez seja melhor fazer um vetor de 8 posi��es e defines tipo IND_BARRIL_M 0 e adicionar 1 cada vez que encontrar

*/
