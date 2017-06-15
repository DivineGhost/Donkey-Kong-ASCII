/*  Referência das cores da função textcolor()
0 = Black -----------  8 = Gray
1 = Blue ------------  9 = Light Blue
2 = Green ----------- 10 = Light Green
3 = Aqua ------------ 11 = Light Aqua
4 = Red ------------- 12 = Light Red
5 = Purple ---------- 13 = Light Purple
6 = Yellow ---------- 14 = Light Yellow
7 = White ----------- 15 = Bright White
*/

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <iostream>

#define Y_MAX 62
#define X_MAX 46

#define CIMA 72
#define BAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ESC 27
#define ENTER 13

void hide_cursor() // Esconde o cursor default do prompt
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // Esconde o Cursor do console
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void formatprompt() // Formatação do prompt
{
    system("color 03");                             // Cor normal do prompt
    system("mode 64, 40");                           // Modo para não exceder o buffer
    SMALL_RECT WinRect = {0, 0, X_MAX, Y_MAX};       // Formata o tamanho do prompt
    SMALL_RECT* WinSize = &WinRect;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);

    hide_cursor();
    setlocale(LC_ALL, "Portuguese"); //prompt em português para acentos e afins
}

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
    return;
}

void gotoxy(int x, int y)  // Move o cursor para (x, y)
{
  static HANDLE h = NULL;
  if(!h)
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = {x, y};
  SetConsoleCursorPosition(h,c);
}

int setas()  // Controle pelas setas direcionais
{
    int valor_seta; // Pode ser os valores definidos no cabeçalho

    do
        valor_seta = getch(); // Continua pegando caracteres
    while(valor_seta != CIMA && valor_seta != BAIXO && valor_seta != ESQUERDA && valor_seta != DIREITA && valor_seta != ENTER && valor_seta != ESC);

    return valor_seta; // Manda para o main a seta lida
}

/*  ACHAR UTILIDADE PRA ISSO
typedef struct TIPO_FASE
{
    char objeto;
    float velocidade;
    int linha_inicial;
    int coluna_inicial;
}TIPO_FASE;
*/
void mainMenu() // Menu principal do jogo
{
    int x = 14, y[] = {14, 18, 22}, contador = 0, sair = FALSE; // Coordenadas da seta, contador índice da seta, booleano sair para sair do menu
    system("cls"); // Limpa a tela
    textcolor(10); // Cor verde
    std::cout <<"  \n" // Impressão da tela inicial do jogo. Para imprimir '\' foi usado '\\'
              <<"  \n"
              <<"  \n"
              <<"  \n"
              <<"    _______        \n"
              <<"   |  ____ \\    \n"
              <<"   | |    \\ \\ \n"
              <<"   | |     | |  _____   __   _   _   _   _____  __     __       \n"
              <<"   | |     | | |  _  | |  \\ | | | | / / |  ___| \\ \\   / /   \n"
              <<"   | |     | | | | | | | | \\| | | |/ /  | |__    \\ \\_/ /   \n"
              <<"   | |     / | | | | | | |\\   | |   /   |  __|    \\   /    \n"
              <<"   | |____/ /  | |_| | | | \\  | | |\\ \\  | |___     | |   \n"
              <<"   |_______/   |_____| |_|  |_| |_| \\_\\ |_____|    |_|   \n"
              <<"  \n"
              <<"  \n"
              <<"                           M E N U  \n"
              <<"  \n"
              <<"  \n"
              <<"            --  Novo Jogo \n"
              <<"  \n"
              <<"  \n"
              <<"  \n"
              <<"            --  Continuar \n"
              <<"  \n"
              <<"  \n"
              <<"  \n"
              <<"            --  Sair \n"
              <<"  \n"
              <<"  \n"
              <<"  \n"
              <<"        __      ___    \n"
              <<"       |  |    /  /   \n"
              <<"       |  |   /  /   \n"
              <<"       |  |  /  /   \n"
              <<"       |  | /  /   \n"
              <<"       |  |/  /     _______   __    __   ________\n"
              <<"       |     /     |  ___  | |  \\  |  | |  ______|  \n"
              <<"       |     \\     | |   | | |   \\ |  | | |          \n"
              <<"       |  |\\  \\    | |   | | |    \\|  | | |  ____    \n"
              <<"       |  | \\  \\   | |   | | |  |\\ \\  | | | |__  |   \n"
              <<"       |  |  \\  \\  | |___| | |  | \\   | | |____| |     \n"
              <<"       |__|   \\__\\ |_______| |__|  \\__| |________|      \n"
              <<"  \n";

    do // Faz ao menos uma vez
    {
        gotoxy(x, y[contador]); // Move o cursor para (x, y[cont])
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
                                contador = 2; // Define contador como 2 (última posição na tela)
                            }
                       break;

            case BAIXO: if(contador != 2) // Caso o usuário aperte direcional para baixo
                        { // Se o contador não estiver na última posição
                           gotoxy(x, y[contador]);
                           printf(" "); // Apaga a seta anterior
                           contador++; // Incrementa o contador
                        }
                        else if(contador == 2)
                             { // Se o contador estiver na última posição
                                 gotoxy(x, y[contador]);
                                 printf(" "); // Apaga a seta anterior
                                 contador = 0; // Define o contador como 0 (primeira posição na tela)
                             }
                        break;

            case ENTER: sair = TRUE; // Se o usuário teclar ENTER, sai do loop
                        break;

            case ESC: if(contador != 2) // Se o usuário teclar ESC (No caso seria um atalho para sair do programa rapidamente)
                      { // Se o contador for diferente de 2
                          gotoxy(x, y[contador]);
                          printf(" ");
                          contador = 2; // Move a seta para a última posição
                          break;
                      }
        }

        Beep(500, 40); // B E E P

    }while(!sair); // Enquanto "não sair"
}

int main()
{
    system("title Donkey Kong"); // Muda o nome do programa na parte superior do prompt
    formatprompt();
    mainMenu();
    system("cls");
    system("pause>>null");
    std::cout <<" ______________________________________________________________\n"
              <<"|                                                     \\o/      |\n"
              <<"|                                                     /=\\      |\n"
              <<"|                             XXXXXX|X|XXXXXXXXXXXXXXXXXXXXXXXX|\n"
              <<"|                             XXXXXX|-|XXXXXXXXXXXXXXXXXXXXXXXX|\n"
              <<"|                                   |-|                        |\n"
              <<"|                                   |-|                        |\n"
              <<"|            /^\\/^\\}o{              |-|                        |\n"
              <<"|            \\z/\\z/_H_              |-|                        |\n"
              <<"|            XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|X|XXX    |\n"
              <<"|            XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|-|XXX    |\n"
              <<"|                                                    |-|       |\n"
              <<"|                                                    |-|       |\n"
              <<"|                                                    |-|       |\n"
              <<"|                                                    |-|       |\n"
              <<"|                               XXXXXX|X|XXXXXXXXXXXXXXX|X|XXX |\n"
              <<"|                               XXXXXX|-|XXXXXXXXXXXXXXX|-|XXX |\n"
              <<"|                                     |-|               |-|    |\n"
              <<"|                                     |-|                -|    |\n"
              <<"|                                     |-|                      |\n"
              <<"|                                     |-|                      |\n"
              <<"|            XXX|X|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|X|XXX       |\n"
              <<"|            XXX|-|XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|-|XXX       |\n"
              <<"|               |-|                               |-|          |\n"
              <<"|               |-|                               |-|          |\n"
              <<"|               |-|                               |-|          |\n"
              <<"|               |-|                                -|          |\n"
              <<"|               |-|                                            |\n"
              <<"|               |-|                                            |\n"
              <<"|       XXXXXXXXXXXXXXXXXX-._                                  |\n"
              <<"|       XXXXXXXXXXXXXXXXXX   -._                               |\n"
              <<"|                               -._                            |\n"
              <<"|                                  -._                         |\n"
              <<"|                                     XXXXXXXXXXXXXXXXXXXXXXXX |\n"
              <<"|                                     XXXXXXXXXXXXXXXXXXXXXXXX |\n"
              <<"|                                                       |-|    |\n"
              <<"|                                                       |-|    |\n"
              <<"|                                                       |-|    |\n"
              <<"|                                                       |-|    |\n"
              <<"|                                                       |-|XXX |\n"
              <<"|                                                       |-|XXX |\n"
              <<"|                                             _.-XXXXXXXXXXXXX |\n"
              <<"|                                          _.-   XXXXXXXXXXXXX |\n"
              <<"|                     _.-XXXXXXXXXXXXXXXXXX                    |\n"
              <<"|                  _.-	XXXXXXXXXXXXXXXXXX                     |\n"
              <<"|XXXXXXXXXXXXXXXXXX                                            |\n"
              <<"|XXXXXXXXXXXXXXXXXX                                            |\n"
              <<"|______________________________________________________________|\n";

    // '\\' Imprime '\'

    // T E S T E S  QUE FIZ SOBRE O MÁRIO, VOU REVER
    setlocale(LC_ALL, "Portuguese"); // Língua para português
    int x = 12,y = 43; // Coordenadas do mário
    int movement = 0;
    char k;
    while(1)
    {
    gotoxy(x,y);
    printf("_ф_");
    gotoxy(x,y+1);
    printf("/H\\");
    hide_cursor();

    mainMenu();
    system("pause>>null");
    k = toupper(getch());
    switch(k)
    {


    case 'A': gotoxy(x, y);
              printf("   ");
              gotoxy(x,y+1);
              printf("   ");
              x--;
              gotoxy(x,y);
              printf("_ф_");
              gotoxy(x,y+1);
              printf("/H\\");
              hide_cursor();
              break;

    case 'D': gotoxy(x, y);
              printf("   ");
              gotoxy(x,y+1);
              printf("   ");
              x++;
              gotoxy(x,y);
              printf("_ф_");
              gotoxy(x,y+1);
              printf("/H\\");
              hide_cursor();
              break;

    case 'W': gotoxy(x, y);
              printf("   ");
              gotoxy(x,y+1);
              printf("   ");
              y--;
              gotoxy(x,y);
              printf("_ф_");
              gotoxy(x,y+1);
              printf("/H\\");
              hide_cursor();
              break;

    case 'S': gotoxy(x, y);
              printf("   ");
              gotoxy(x,y+1);
              printf("   ");
              y++;
              gotoxy(x,y);
              printf("_ф_");
              gotoxy(x,y+1);
              printf("/H\\");
              hide_cursor();
              break;

    case 'ESC': gotoxy(10, 65);
              return 1;
    }
    }
    return 0;
}
