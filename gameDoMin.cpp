10
1010#ifndef CSL_H_INCLUDED1111111111
#define CSL_H_INCLUDED
#include <iostream>
#include<windows.h> // Su dung Sleep
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include<iomanip>
#include<ctime>// Ho tro rand , su dung srand
#include <cstdlib> // Dung rand();
//#define _WIN32_WINNT 0x0500
using namespace std;
inline void settitle(char *title);//dat tieu de chon console
inline void clrscr(void);//xoa mang hinh(fill space character full screen)
void gotoxy(int x,int y);//move cursor to x,y
char getcharxy(int x, int y);//lay ky tu tai vi tri chuot
int wherex();//lay vi tri toa do hien tai x cua con tro
int wherey();//lay vi tri toa do hien tai y cua con tro
void setcolor(WORD color);//dat mau cho chu tren console
void settextbgcolor(WORD color);//dat mau nen cua chu tren console
inline void setbgcolor(int color);//dat mau nen console
inline void resizecsl(int width, int height);//thay doi kich thuoc console window
inline void sprint(int x,int y, string st);//in xau st, tai toa do x,y
inline void cprint(int x,int y, char c);//in char c, tai toa do x,y
inline void clprint(int x,int y, char c, WORD color);//in c tai toa do xy voi mau color
inline void scprint(int x,int y, char *st,WORD tcolor,WORD bcolor);//in xau st vow mau chu tcolor va mau bgtext bcolor, tai toa do x,y
inline void iprint(int x,int y, int i);//in int i, tai toa do x,y
inline void fprint(int x,int y, float f);//in float f, tai toa do x,y
inline void clstext(int x,int y, char *s);//xoa doan text 's' da show tren console
inline void cloneprint(char x,char y,char num,char c,WORD color);//in xau toan ky tu 'c' voi so luong 'num' tai to do x,y va mau 'color'
inline string strclone(string st, int n);//nhan ban ky tu them nhieu lan
void fillscr(char c);//dien ky tu c vao nen screen(fill c charater full screen)
HWND WINAPI GetConsoleWindow(void);

void vaoGame();
void endGame(int Array[9][9]);
int soBomXungQuanh(int row,int col,int Array[9][9]);
void randomBom(int Array[9][9],int x[65],int y[65],int soBom);
void hoanTatArray(int Array[9][9]);
void inRaMang2Chieu(int ArrayHienThi[9][9]);
void updateManHinh(int row, int col ,int Array[9][9], int ArrayHienThi[9][9]);
int checkAHT(int ArrayHienThi[9][9],int soBom);
int soSanh2Mang(int Array[9][9],int ArrayHienThi[9][9]);
void khungGame(int k);

inline void settitle(char *title)
{
SetConsoleTitle(title);
}
inline void clrscr(void)
{
fillscr(' ');
}
inline void gotoxy(int x,int y)
{
HANDLE hConsoleOutput;
COORD Cursor_an_Pos = { x,y};
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
inline char getcharxy(int x, int y)
{
char c;
HANDLE hOut;
COORD Where;
DWORD NumRead;
hOut = GetStdHandle(STD_OUTPUT_HANDLE);
Where.X = x;
Where.Y = y;
ReadConsoleOutputCharacter(hOut,&c,1,Where,&NumRead);
return c;
}
inline int wherex()
{
CONSOLE_SCREEN_BUFFER_INFO csbi;
if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE ),&csbi)) return -1;
else return csbi.dwCursorPosition.X;
}
inline int wherey()
{
CONSOLE_SCREEN_BUFFER_INFO csbi;
if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE ),&csbi)) return -1;
else return csbi.dwCursorPosition.Y;
}
inline void setcolor(WORD color)
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

WORD wAttributes = screen_buffer_info.wAttributes;
color &= 0x000f;
wAttributes &= 0xfff0;
wAttributes |= color;

SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
inline void settextbgcolor(WORD color)
{
HANDLE hConsoleOutput;
hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
WORD wAttributes = screen_buffer_info.wAttributes;
color &= 0x000f;
color <<= 4;
wAttributes &= 0xff0f;
wAttributes |= color;
SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
inline void setbgcolor(int color)
{
settextbgcolor(color);
clrscr();
}
inline void resizecsl(int width, int height)
{
HWND console = GetConsoleWindow();
RECT r;
GetWindowRect(console, &r);
MoveWindow(console, r.left, r.top,width*15, height*15, TRUE);
}
inline void sprint(int x,int y, string st)
{
gotoxy(x,y);
cout<<st;
}
inline void cprint(int x,int y, char c)
{
gotoxy(x,y);
printf("%c",c);
}
inline void clprint(int x,int y, char c, WORD color)
{
gotoxy(x,y);
setcolor(color);
printf("%c",c);
}
inline void scprint(int x,int y, char *st,WORD tcolor,WORD bcolor)
{
gotoxy(x,y);
setcolor(tcolor);
settextbgcolor(bcolor);
printf("%s",st);
}
inline void iprint(int x,int y, int i)
{
gotoxy(x,y);
printf("%d",i);
}
inline void fprint(int x,int y, float f)
{
gotoxy(x,y);
printf("%f",f);
}
inline void clstext(int x,int y, char *s)
{
for(int i=strlen(s);i>=0;i--)//xoa cau tho cu in cau tho moi
{
cprint(x+i,y,32);
}
}
inline void cloneprint(char x,char y,char num,char c,WORD color)
{
for(char i=0;i<num;i++)
{
setcolor(color);
cprint(x+i,y,c);
}
}
inline void fillscr(char c)
{
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
HANDLE hConsoleOut;
COORD Home = {0,0};
DWORD dummy;
hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
FillConsoleOutputCharacter(hConsoleOut,c,csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
SetConsoleCursorPosition(hConsoleOut,Home);
}
string strclone(string st, int n)
{
string t="";
for(;n>0;n--)
{
t+=st;
}
return t;
}
#endif // CSL_H_INCLUDED
void vaoGame(){
cout <<" LUAT CHOI\n";
cout <<" Day la game do min co 8x8 co so bom tuy chon\n";
cout <<" Yeu cau nguoi choi phai mo toan bo cac o khong phai bom trong bang de co the WIN \n"<<" NHUNG O DA DANH DAU LA BOM THI KHONG THE THAY DOI \n";Sleep(5000);clrscr();
cout <<" GAME START";Sleep(3000);clrscr();
}
void endGame(int Array[9][9]){
cout <<" Ban da mo phai boom\n";
cout <<" Bang choi co gia tri nhu sau\n";Sleep(3000);
khungGame(20);
for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
        	gotoxy(42+j*4,24+i*2);
        	if (Array[i][j]==-1) cout << (char) 254 ;
            else cout<<Array[i][j];
        }
}
int soBomXungQuanh(int row,int col,int Array[9][9]){
int demSoBom=0;
if (Array[row-1-1][col-1-1]==-1 && row-1>0 && col-1>0) demSoBom++;
if (Array[row-1][col-1-1]==-1 && col-1>0) demSoBom++;
if (Array[row+1-1][col-1-1]==-1 && col-1>0 && row+1<=8) demSoBom++;
if (Array[row+1-1][col-1]==-1 && row+1<=8) demSoBom++;
if (Array[row+1-1][col+1-1]==-1 && row+1<=8 && col+1<=8) demSoBom++;
if (Array[row-1][col+1-1]==-1 && col+1<=8) demSoBom++;
if (Array[row-1-1][col+1-1]==-1 && row-1>0 && col+1<=8) demSoBom++;
if (Array[row-1-1][col-1]==-1 && row-1>0 ) demSoBom++;
return demSoBom;
}
void randomBom(int Array[9][9],int x[65],int y[65],int soBom){
int i;
srand(time(NULL));
x[0]=rand()%8;
y[0]=rand()%8;
Array[x[0]][y[0]]=-1;
for (i=1;i<soBom;i++) {
x[i]=rand()%8;
y[i]=rand()%8;
while ( Array[x[i]][y[i]]!=9 ) {
x[i]=rand()%8;
y[i]=rand()%8;
}
Array[x[i]][y[i]]=-1;
}
}
void hoanTatArray(int Array[9][9]){
int i,j;
for (i=0;i<=7;i++){
for ( j=0;j<=7;j++){
if (Array[i][j]!=-1) {
Array[i][j]=soBomXungQuanh(i+1,j+1,Array);
}
}
}
}
int checkAHT(int ArrayHienThi[9][9],int soBom){
int i,j,dem=0;
for (i=0;i<8;i++){
for (j=0;j<8;j++){
if (ArrayHienThi[i][j]>=0 && ArrayHienThi[i][j]<9) dem++;
if (dem==64-soBom) return 0;
else return 1;
}
}
}
void inRaMang2Chieu(int ArrayHienThi[9][9]){
int i,j;
for (i=0;i<=7;i++){
for ( j=0;j<=7;j++){
cout << ArrayHienThi[i][j]<<"\t";
}
cout <<"\n";
}
}
void updateManHinh(int row, int col ,int Array[9][9], int ArrayHienThi[9][9]){
int i,dem=0;

if (soBomXungQuanh(row,col,Array)==0) {
ArrayHienThi[row-1][col-1]=0;
if (col-1>0 && row-1 >0) {ArrayHienThi[row-1-1][col-1-1]=soBomXungQuanh(row-1,col-1,Array);}
if (row-1 >0) {ArrayHienThi[row-1-1][col-1]=soBomXungQuanh(row-1,col,Array);}
if (col+1<=8 && row-1 >0) {ArrayHienThi[row-1-1][col+1-1]=soBomXungQuanh(row-1,col+1,Array);}
if (col+1<=8 ) {ArrayHienThi[row-1][col+1-1]=soBomXungQuanh(row,col+1,Array);}
if (col+1<=8 && row+1<=8) {ArrayHienThi[row+1-1][col+1-1]=soBomXungQuanh(row+1,col+1,Array);}
if (row+1<=8 ) {ArrayHienThi[row+1-1][col-1]=soBomXungQuanh(row+1,col,Array);}
if (col-1>0 && row+1<=8) {ArrayHienThi[row+1-1][col-1-1]=soBomXungQuanh(row+1,col-1,Array);}
if (col-1>0 ) {ArrayHienThi[row-1][col-1-1]=soBomXungQuanh(row,col-1,Array);}
}
else {
ArrayHienThi[row-1][col-1]=soBomXungQuanh(row,col,Array);
}

khungGame(0);
for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
        	gotoxy(42+j*4,4+i*2);
        	if (ArrayHienThi[i][j]==9) cout <<" ";
        	else {if (ArrayHienThi[i][j]==-1) cout << (char) 254 ;
                  else cout<<ArrayHienThi[i][j];}
        }
}
int soSanh2Mang(int Array[9][9],int ArrayHienThi[9][9]){
int i,j;
for (i=0;i<8;i++){
for (j=0;j<8;j++){
if (Array[i][j]!=-1 && ArrayHienThi[i][j]!=Array[i][j]) return 0;
}
}
return 1;
}
void khungGame(int k)
{
	for(int i=0;i<=16;i++)
        for(int j=0;j<=32;j++)
        {
            if(i==0&&j==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(201);
            }
            else if(i==16&&j==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(200);
            }
            else if(i==0&&j==32)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(187);

            }
            else if(i==16&&j==32)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(188);
            }
            else if(i%2==0&&j==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(199);
            }
            else if(i%2==0&&j==32)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(182);
            }
            else if(i==0&&j%4==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(209);
            }
            else if(i==16&&j%4==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(207);
            }
            else if(i%2==0&&j%4==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(197);
            }
            else if(i==0||i==16)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(205);
            }
            else if(i%2==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(196);
            }
            else if(j==0||j==32)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(186);
            }
            else if(j%4==0)
            {
                gotoxy(j+40,i+3+k);
                cout<<char(179);
            }
        }
}

int main () {
int Array[9][9]={ {9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9} };
int ArrayHienThi[9][9]={ {9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9},
{9,9,9,9,9,9,9,9,9} };
int y[65],x[65];
int row,col,xyz,temp,rb,cb,soBom,i;
xyz=0;
//vaoGame();
cout <<"Nhap so bom [ So Bom toi thieu la 2 , toi da la 63 ] = ";
cin >> soBom;
clrscr();
randomBom(Array,x,y,soBom);
hoanTatArray(Array);
khungGame(0);
//inRaMang2Chieu(Array);
//inRaMang2Chieu(ArrayHienThi);
do { if (checkAHT(ArrayHienThi,soBom)==0 && soSanh2Mang(ArrayHienThi,Array)==1) { gotoxy(0,20);cout << " Dell the tin la Ban co the WIN ";break;}
if (checkAHT(ArrayHienThi,soBom)==0 && soSanh2Mang(ArrayHienThi,Array)!=1) { xyz++;break;}
// Ham check tra ve 0 neu tat ca cac gia tri khong phai bom da duoc mo , tra ve 1 neu chua
// Ham soSanh tra ve 1 neu 2 mang co gia tri khong phai bom nhu nhau , tra ve 0 neu no khac nhau
gotoxy(0,20);
cout << "Nhap vao vi tri Hang va Cot ma ban muon mo : ";
cin >> row >> col;
if ( Array[row-1][col-1]!=-1) {  clrscr();
updateManHinh(row,col,Array,ArrayHienThi);
gotoxy(0,20);
cout << "Ban co muon danh dau bom [Nhap 1:Co] [Nhap 0:Khong] : ";
cin >> temp ;
if (temp==1) {
cout << " So Bom ban muon danh dau trong luot nay la : ";
cin >> soBom;
for (i=1;i<=soBom;i++){
cout <<"Nhap vao vi tri Hang va Cot cua bom : ";
cin >> rb >> cb;
ArrayHienThi[rb-1][cb-1]=-1;
}}}
if (Array[row-1][col-1]==-1) xyz=xyz+1;
else { clrscr();
updateManHinh(row,col,Array,ArrayHienThi);}
}
while (xyz==0);
if (xyz!=0) endGame(Array);
return 0;
}
