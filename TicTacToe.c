#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// variabel global
int system();
char mat[3][3];
const char player_1 = 'X';
const char player_2 = 'O';
const char bot = 'O';
int mode = 1;

// fungsi
int halaman_awal();
void papan();
void reset_papan();
int cek_kosong();
void gerak_player_1();
void gerak_player_2();
int gerak_bot();
char cek_menang();
int cetak_menang();
void waitFor();

COORD c = {0,0};

void gotoxy(int x, int y){
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c );
}


int main(){
    restartpoint:
    MainMenu();
    char pemenang = '.';
    char z;
    reset_papan();
    if(mode == 0){
        system("cls");
        return 0 ;
    }

    if(mode == 1){
         system("cls");
          reset_papan();
        while(pemenang =='.' && cek_kosong() != 0)
        {
            papan();
            gerak_player_1();
            pemenang = cek_menang();
            if(pemenang == 'X' || cek_kosong() == 0)
            {
                break;
            }
            papan();
            gerak_bot();
            pemenang = cek_menang();
            if(pemenang == 'O' || cek_kosong() == 0)
            {
                break;
            }

        }
        papan();
        if(pemenang == player_1)
        {
            printf("\nPLAYER 1 WIN !");
        }
        else if(pemenang == player_2)
        {
            printf("\nBOT WIN !");
        }
        else
        {
            printf("\nDRAW !");
        }
        z = getch();
        if(z == 13){
            system("cls");
            goto restartpoint;
        }

}
    if(mode == 2){
         reset_papan();
        while(pemenang == '.' && cek_kosong() != 0)
    {
        papan();
        gerak_player_1();
        pemenang = cek_menang();
        if(pemenang == 'X' || cek_kosong() == 0)
        {
            break;
        }
        papan();
        gerak_player_2();
        pemenang = cek_menang();
        if(pemenang == 'O' || cek_kosong() == 0)
        {
            break;
        }
    }
    papan();
    cetak_menang(pemenang);
     z = getch();
        if(z == 13){
            system("cls");
            goto restartpoint;
        }
}

    if(mode == 3){
        system("cls");
        return 0;
    }
    }


void papan()
{
    system("cls");
    printf("%c %c %c\n", mat[0][0], mat[0][1], mat[0][2]);
    printf("%c %c %c\n", mat[1][0], mat[1][1], mat[1][2]);
    printf("%c %c %c\n", mat[2][0], mat[2][1], mat[2][2]);
}
void reset_papan()
{
    for(int i =0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mat[i][j]='.';
        }
    }
}
// untuk mengecek banyak bagian array yang kosong
int cek_kosong()
{
    int kosong = 9;
    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            if(mat[i][j] != '.')
            {
                kosong--;
            }
        }
    }
    return kosong;
}
// sebagai fungsi gerak pemain 1
void gerak_player_1()
{
    int baris;
    int kolom;
    do
    {
        printf("\nPlayer 1 input row and column : ");
        scanf("%d %d", &baris, &kolom);
        if(mat[baris][kolom] != '.')
        {
            printf("error\n");
        }
        else
        {
            mat[baris][kolom] = player_1;
            if(mat[baris][kolom] <= mat[3][3]){
                printf("error");
            }
            break;
        }
    }while(mat[baris][kolom]!= '.');
    }

// sebagai fungsi gerak pemain 2
void gerak_player_2()
{
    int baris;
    int kolom;
    do
    {
        printf("\nPlayer 2 input row and column : ");
        scanf("%d %d", &baris, &kolom);
        if(mat[baris][kolom] != '.')
        {
            printf("error");
        }
        else
        {
            mat[baris][kolom] = player_2;
        if(mat[baris][kolom] <= mat[3][3])
        {
                printf("error");
        }
        break;
        }
    }while(mat[baris][kolom] != '.');
}
// sebagai fungsi gerak bot
int gerak_bot()
{
    srand(time(0));
    int baris,kolom;
    if(cek_kosong() != 0)
    {
        do
        {
            baris = rand()%3;
            kolom = rand()%3;
        }
        while(mat[baris][kolom] != '.');

        mat[baris][kolom] = bot;
    }

}
// untuk mengecek apakah urutan tanda memenuhi untuk menang
char cek_menang()
{
    //baris
    for(int i = 0;i<3;i++)
    {
        if(mat[i][0]==mat[i][1] && mat[i][0] == mat[i][2])
        {
            return mat[i][0];
        }
    }
    //kolom
    for(int i = 0;i<3;i++)
    {
        if(mat[0][i]==mat[1][i] && mat[0][i] == mat[2][i])
        {
            return mat[0][i];
        }
    }
    //diagonal
    if(mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2])
    {
        return mat[0][0];
    }
    else if(mat[0][2] == mat[1][1] && mat[0][2] == mat[2][0])
    {
        return mat[0][2];
    }

    return '.';
}
// untuk menampilkan pemenang
int cetak_menang(win)
{
    if(win == player_1)
    {
        printf("\nPLAYER 1 WIN !");
    }
    else if(win == player_2)
    {
        printf("\nPLAYER 2 WIN !");
    }
    else
    {
        printf("\nDRAW !");
    }
}
void waitFor (unsigned int secs) {
unsigned int retTime = time(0) + secs;
while (time(0) < retTime);
}
int MainMenu()
{
    char z;
    int status = 1;
    if(status == 1){
        gotoxy(0,1);
        printf("TICTACTOE");
        gotoxy(0,2);
        printf("-----------");
        gotoxy(0,4);
        printf("-> player 1 vs bot");
        gotoxy(0,5);
        printf("   player 1 vs player 2");
        gotoxy(0,6);
        printf("   exit");
    }
        z = 1;

        while(z != 27){
            z = getch();
            if(z == 13){
                system("cls");
                return;
            }
            if(z == -32){
                z = getch();
                if(z == 72){
                    status--;
                    if(status == 0){
                        status = 1;
                    } 
                    if(status == 1){
                        system("cls");
                        gotoxy(0,1);
                        printf("TICTACTOE");
                        gotoxy(0,2);
                        printf("-----------");
                        gotoxy(0,4);
                        printf("-> player 1 vs bot");
                        gotoxy(0,5);
                        printf("   player 1 vs player 2");
                        gotoxy(0,6);
                        printf("   exit");
                        z = getch();
                        mode = 1;
                        if(z == 13){
                            system("cls");
                            return;

                        }
                        
                    
                    } 
                    if(status == 2){
                        system("cls");
                        gotoxy(0,1);
                        printf("TICTACTOE");
                        gotoxy(0,2);
                        printf("-----------");
                        gotoxy(0,4);
                        printf("   player 1 vs bot");
                        gotoxy(0,5);
                        printf("-> player 1 vs player 2");
                        gotoxy(0,6);
                        printf("   exit");
                        z = getch();
                        mode = 2;
                        if(z == 13){
                            system("cls");
                            return;
                        }
                    } 
                    if(status == 3){
                        system("cls");
                        gotoxy(0,1);
                        printf("TICTACTOE");
                        gotoxy(0,2);
                        printf("-----------");
                        gotoxy(0,4);
                        printf("   player 1 vs bot");
                        gotoxy(0,5);
                        printf("   player 1 vs player 2");
                        gotoxy(0,6);
                        printf("-> exit");

                        z = getch();
                        mode  = 3;
                        if(z == 13){
                            system("cls");
                            return ;
                        }
                    } 
                }
                if(z == 80){
                    status++;
                    if(status == 2){
                         system("cls");
                        gotoxy(0,1);
                        printf("TICTACTOE");
                        gotoxy(0,2);
                        printf("-----------");
                        gotoxy(0,4);
                        printf("   player 1 vs bot");
                        gotoxy(0,5);
                        printf("-> player 1 vs player 2");
                        gotoxy(0,6);
                        printf("   exit");
                        z = getch();
                        mode = 2;
                        if(z == 13){
                            system("cls");
                            return ;
                        }
                    }
                    if(status == 3){
                        system("cls");
                        gotoxy(0,1);
                        printf("TICTACTOE");
                        gotoxy(0,2);
                        printf("-----------");
                        gotoxy(0,4);
                        printf("   player 1 vs bot");
                        gotoxy(0,5);
                        printf("   player 1 vs player 2");
                        gotoxy(0,6);
                        printf("-> exit");

                        z = getch();
                        mode = 3;
                        if(z == 13){
                            system("cls");
                            return;
                            
                    }
                    }
                }
            }
        }

    }


