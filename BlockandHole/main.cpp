#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

char** matriz(int n, int m){
    char** x= new char*[n];
    for(int i=0; i<n; i++){
        x[i]= new char[m];
    }
    return x;
}
char** leer (istream& is, int n, int m){
   char** x = matriz(n,m);
   char a;
   for(int i = 0; i <n; i++){
        for(int j = 0; j<m; j++){
            is>>a;
            x[i][j]=a;
        }
}
  return x;
}
int* leer2 (istream& is){
    int* a = new int[2];
    int x;
    for(int i = 0; i<2; i++){
      is>>x;
      a[i]=x;
    }
    return a;
}
ostream& escribir(char* a, ostream& os, int n){
    for(int i = 0; i<n; i++){
          os<<a[i];
          os<<',';
    }
    return os;
}
char** creartableroinicial(int n, int m){
char** x= matriz(n,m);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
            x[i][j]='*';
    }
}
return x;
}
void imprimirtablero(char** x, char**x1, int n, int m, bool gano) {
cout<<"          "<<char(201);
for (int i= 0; i<m+26; i++){
    cout<<char(205);
}
cout<<char(187)<<endl;
cout<<"          "<<char(186);
for(int i= 0; i<m+26;i++){
    cout<<" ";
}
cout<<char(186)<<endl;
for(int i=0;i<n;i++){
        cout<<"          "<<char(186)<<"             ";
    for(int j=0;j<m;j++){
    	if(!gano && x1[i][j]=='g' && x[i][j]== 'C'){
    		x[i][j]='g';
    	}
    cout<<x[i][j];
  }
cout<<"             "<<char(186)<<endl;
}
cout<<"          "<<char(186);
for(int bi= 0; bi<m+26;bi++){
    cout<<" ";
}
cout<<char(186)<<endl;
cout<<"          "<<char(200);
for (int i= 0; i<m+26; i++){
    cout<<char(205);
}
cout<<char(188)<<endl;
}
bool mov3 (char** x, int p, int* pos){
    cout<<"A1"<<endl;
bool f = false;
if ((x[pos[0]+1][pos[1]] == 'C')||(x[pos[0]-1][pos[1]] == 'C')){
        cout<<"A2"<<endl;
    if (p==1 || p==2){
        f = true;
    }else{
    f = false;
    }
}
else if ((x[pos[0]][pos[1]+1] == 'C')||(x[pos[0]][pos[1]-1] == 'C')){
    cout<<"A3"<<endl;
    if (p==3 || p==4){
        f = true;
    }else{
    f = false;
    }
}
return f;
}
bool mov2 (char** x, int p, int cx, int cy, int n, int m){
bool f = false;
if (cx==n-1){
    if (p==3 || p==4){
        f = true;
    }else{
    f = false;
    }
}
else if (x[cx+1][cy] == 'C'){
    if (p==1 || p==2){
        f = true;
    }else{
    f = false;
    }
}
else if (x[cx][cy+1] == 'C'){
    if (p==3 || p==4){
        f = true;
    }else{
    f = false;
    }
}
return f;
}
int* posicionCubo (char**x, int n, int m){
int* pos = new int [2];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(x[i][j]=='C'){
        pos[0]=i;
        pos[1]=j;
        i =n;
        j=m;
     }
 }
}
return pos;
}
int* selecentro (char**t,int x, int y, int p, int n, int m){
int* centro = new int [2];
if(x==n-1){
    if (p==1 || p==2 || p==3){
        centro[0]= x;
        centro[1]= y;
    }else{
        centro[0]= x;
        centro[1]= y+1;
    }
}
else if (t[x+1][y] == 'C'){
    if (p==2 || p==3 || p==4){
        centro[0] = x;
        centro[1] = y;
    }else{
        centro[0] = x+1;
        centro[1] = y;
    }
}
else if (t[x][y+1] == 'C'){
    if (p==1 || p==2 || p==3){
        centro[0]= x;
        centro[1]= y;
    }else{
        centro[0]= x;
        centro[1]= y+1;
    }
}
return centro;
}
int* cuerpocubo (char**t, int n, int m, int* centro){
int* cuerpo = new int [2];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(t[i][j]=='C'){
       if((centro[0]!=i || centro[1]!=j)){
            cuerpo[0]=i;
            cuerpo[1]=j;
       }
     }
 }
}
return cuerpo;
}
int* movimientoVertical(char** t, int x, int y, int n, int m, bool pc, char jugada){
    t[x][y]='*';
    int* Mov = new int [5];
    char a;
    bool valido = false;
    int p = 0;
    int x1, y1, x2,y2;
while (!valido){
if(pc){
switch(jugada){
    case 'b':
    a = char(80);
    break;
    case 'a':
    a = char(72);
    break;
    case 'i':
    a = char(75);
    break;
    case 'd':
    a = char(77);
    break;
}
}else{
a=getch();
}
x1 =x;
y1 =y;
x2 = x;
y2 = y;
switch (a)
	{
   case char(80):    //abajo
    p =1;
    x1++;
    x2 = x1+1;
   break;
   case char(72):   //arriba
    p =2;
    x1--;
    x2 = x1-1;
   break;
   case char(75):   //izquierda
    p = 3;
    y1--;
    y2 = y1-1;
   break;
   case char(77):   //derecha
    p =4;
    y1++;
    y2 = y1+1;
   break;
   default:
   x1 = -100;
   break;
   }
if(x1 == -100){
    valido = false;
    cout<<"Repite"<<endl;
}
else{
if(!((((x1>=0 && x1<n) && (y1>=0 && y1<m)))&&((x2>=0 && x2<n) && (y2>=0 && y2<m)))){
cout<<" ######      ###    ##     ## ########"<<endl;
cout<<"##    ##    ## ##   ###   ### ##"<<endl;
cout<<"##         ##   ##  #### #### ##"<<endl;
cout<<"##   #### ##     ## ## ### ## ######"<<endl;
cout<<"##    ##  ######### ##     ## ##"<<endl;
cout<<"##    ##  ##     ## ##     ## ##"<<endl;
cout<<" ######   ##     ## ##     ## ########"<<endl;
cout<<"                     #######  ##     ## ######## ########"<<endl;
cout<<"                    ##     ## ##     ## ##       ##     ##"<<endl;
cout<<"                    ##     ## ##     ## ##       ##     ##"<<endl;
cout<<"                    ##     ## ##     ## ######   ########"<<endl;
cout<<"                    ##     ##  ##   ##  ##       ##   ##"<<endl;
cout<<"                    ##     ##   ## ##   ##       ##    ##"<<endl;
cout<<"                     #######     ###    ######## ##     ##"<<endl;
    system("pause");
    exit(0);
}else{
valido = true;
}
}
}
Mov[0]=x1;
Mov[1]=y1;
Mov[2]=x2;
Mov[3]=y2;
Mov[4]=p;
return Mov;
}
int* movimientoHorizontal (char** t, int x, int y, int n, int m, bool pc, char jugada){
    int* Mov = new int [5];
    int* centro = new int[2];
    char a;
    bool valido = false;
    int p = 0;
    int x1, y1, x2,y2;
    bool f= false;
while (!valido){
if(pc){
switch(jugada){
    case 'b':
    a = char(80);
    break;
    case 'a':
    a = char(72);
    break;
    case 'i':
    a = char(75);
    break;
    case 'd':
    a = char(77);
    break;
}
}else{
a=getch();
}
x1 =x;
y1 =y;
x2 = x;
y2 = y;
switch (a){
   case char(80):    //abajo
   p =1;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
   if (f){
    x1 = x1+1;
   }else{
    x1= x1+1;
    x2 = x1;
   }
   break;
   case char(72):   //arriba
   p = 2;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
   if (f){
    x1--;
   }else{
    x1--;
    x2 = x1;
   }
   break;
   case char(75):   //izquierda
   p = 3;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
    if (f){
    y1 = y1-1;
   }else{
    y1= y1-1;
    y2 = y1;
   }
   break;
   case char(77):   //derecha
   p = 4;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
   if (f){
    y1++;
   }else{
    y1++;
    y2 = y1;
   }
   break;
   default:
   x1 = -100;
   break;
   }
if(x1 == -100){
    valido = false;
    cout<<"Repetir"<<endl;
}
else{
if(!((((x1>=0 && x1<n) && (y1>=0 && y1<m)))&&((x2>=0 && x2<n) && (y2>=0 && y2<m)))){
cout<<" ######      ###    ##     ## ########"<<endl;
cout<<"##    ##    ## ##   ###   ### ##"<<endl;
cout<<"##         ##   ##  #### #### ##"<<endl;
cout<<"##   #### ##     ## ## ### ## ######"<<endl;
cout<<"##    ##  ######### ##     ## ##"<<endl;
cout<<"##    ##  ##     ## ##     ## ##"<<endl;
cout<<" ######   ##     ## ##     ## ########"<<endl;
cout<<"                     #######  ##     ## ######## ########"<<endl;
cout<<"                    ##     ## ##     ## ##       ##     ##"<<endl;
cout<<"                    ##     ## ##     ## ##       ##     ##"<<endl;
cout<<"                    ##     ## ##     ## ######   ########"<<endl;
cout<<"                    ##     ##  ##   ##  ##       ##   ##"<<endl;
cout<<"                    ##     ##   ## ##   ##       ##    ##"<<endl;
cout<<"                     #######     ###    ######## ##     ##"<<endl;
    system("pause");
    exit(0);
}else{
if (f){
    x2 =-1;
    y2 =-1;
}
valido = true;
}
}
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(t[i][j]=='C'){
        t[i][j]='*';
     }
 }
}
Mov[0]=x1;
Mov[1]=y1;
Mov[2]=x2;
Mov[3]=y2;
Mov[4]= p;
return Mov;
}
int* movimientoVerticalpc(char** t, char**t1, int x, int y, int n, int m){
    t[x][y]='*';
    int* Mov = new int [5];
    int a;
    bool valido = false;
    int p = 0;
    int x1, y1, x2,y2;
while (!valido){
a = rand()%4;
x1 =x;
y1 =y;
x2 = x;
y2 = y;
switch (a)
	{
   case 0:    //abajo
    p =1;
    x1++;
    x2 = x1+1;
   break;
   case 1:   //arriba
    p =2;
    x1--;
    x2 = x1-1;
   break;
   case 2:   //izquierda
    p = 3;
    y1--;
    y2 = y1-1;
   break;
   case 3:   //derecha
    p =4;
    y1++;
    y2 = y1+1;
   break;
   default:
   x1 = -100;
   break;
   }
if(x1 == -100){
    valido = false;
}
else{
if(!((((x1>=0 && x1<n) && (y1>=0 && y1<m)))&&((x2>=0 && x2<n) && (y2>=0 && y2<m)))){
valido = false;
}else{
 char** t2;
 t2 = creartableroinicial(n,m);
 for(int ai=0;ai<n;ai++){
 for(int aj=0;aj<m;aj++){
  t2[ai][aj]= t1[ai][aj];
 }}
 t2[x1][y1]='C';
 t2[x2][y2]='C';
 for(int h=0;h<n;h++){
 for(int k=0;k<m;k++){
 if(t1[h][k]=='-' && t2[h][k]=='C'){
        valido= false;
        h =n;
        k =m;
        }
 else{
    valido = true;
 }}}
}
}
}
Mov[0]=x1;
Mov[1]=y1;
Mov[2]=x2;
Mov[3]=y2;
Mov[4]=p;
return Mov;
}
int* movimientoHorizontalpc (char** t, char**t1, int x, int y, int n, int m){
    int* Mov = new int [5];
    int* centro = new int[2];
    int a;
    bool valido = false;
    int p = 0;
    int x1, y1, x2,y2;
    bool f= false;
while (!valido){
a = rand()%4;
x1 =x;
y1 =y;
x2 = x;
y2 = y;
switch (a){
   case 0:    //abajo
   p =1;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
   if (f){
    x1 = x1+1;
   }else{
    x1= x1+1;
    x2 = x1;
   }
   break;
   case 1:   //arriba
   p = 2;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
   if (f){
    x1--;
   }else{
    x1--;
    x2 = x1;
   }
   break;
   case 2:   //izquierda
   p = 3;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
    if (f){
    y1 = y1-1;
   }else{
    y1= y1-1;
    y2 = y1;
   }
   break;
   case 3:   //derecha
   p = 4;
   centro = selecentro(t,x,y,p,n,m);
   x1 = centro[0];
   x2 = cuerpocubo(t,n,m,centro)[0];
   y1 = centro[1];
   y2 = cuerpocubo(t,n,m,centro)[1];
   f = mov2(t,p,x,y,n,m);
   if (f){
    y1++;
   }else{
    y1++;
    y2 = y1;
   }
   break;
   default:
   x1 = -100;
   break;
   }
if(x1 == -100){
valido = false;
}
else{
if(!((((x1>=0 && x1<n) && (y1>=0 && y1<m)))&&((x2>=0 && x2<n) && (y2>=0 && y2<m)))){
valido = false;
}else{
if (f){
    x2 =-1;
    y2 =-1;
 char** t2;
 t2 = creartableroinicial(n,m);
 for(int ai=0;ai<n;ai++){
 for(int aj=0;aj<m;aj++){
  t2[ai][aj]= t1[ai][aj];
 }}
 t2[x1][y1]='C';
 for(int h=0;h<n;h++){
 for(int k=0;k<m;k++){
 if(t1[h][k]=='-' && t2[h][k]=='C'){
        valido= false;
        h =n;
        k =m;
        }
 else{
    valido = true;
 }}}
}else{
 char** t2;
 t2 = creartableroinicial(n,m);
 for(int ai=0;ai<n;ai++){
 for(int aj=0;aj<m;aj++){
  t2[ai][aj]= t1[ai][aj];
 }}
 t2[x1][y1]='C';
 t2[x2][y2]='C';
 for(int h=0;h<n;h++){
 for(int k=0;k<m;k++){
 if(t1[h][k]=='-' && t2[h][k]=='C'){
        valido= false;
        h =n;
        k =m;
        }
 else{
    valido = true;
 }}}
}
}
}
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(t[i][j]=='C'){
        t[i][j]='*';
     }
 }
}
Mov[0]=x1;
Mov[1]=y1;
Mov[2]=x2;
Mov[3]=y2;
Mov[4]= p;
return Mov;
}
bool estado(char**x, int n, int m){
    int a = 0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
    if (x[i][j]== 'C'){
        a++;
    }
  }
}
if (a>1){
    return false;
}else{
return true;
}
}
bool logica(char**x, char** x1, int n, int m,int*meta){
bool est = estado(x,n,m);
int* posicion = new int [2];
bool ganar = false;
posicion = posicionCubo(x,n,m);
if(est &&(posicion[0] == meta[0]) &&(posicion[1]== meta[1])){
     ganar = true;
cout<<"              ######      ###    ##    ##  #######"<<endl;
cout<<"             ##    ##    ## ##   ###   ## ##     ##"<<endl;
cout<<"             ##         ##   ##  ####  ## ##     ##"<<endl;
cout<<"             ##   #### ##     ## ## ## ## ##     ##"<<endl;
cout<<"             ##    ##  ######### ##  #### ##     ##"<<endl;
cout<<"             ##    ##  ##     ## ##   ### ##     ##"<<endl;
cout<<"              ######   ##     ## ##    ##  #######"<<endl;
system("pause");
system("cls");
}
else{
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     if(x1[i][j]=='-' && x[i][j]=='C'){
cout<<" ######      ###    ##     ## ########"<<endl;
cout<<"##    ##    ## ##   ###   ### ##"<<endl;
cout<<"##         ##   ##  #### #### ##"<<endl;
cout<<"##   #### ##     ## ## ### ## ######"<<endl;
cout<<"##    ##  ######### ##     ## ##"<<endl;
cout<<"##    ##  ##     ## ##     ## ##"<<endl;
cout<<" ######   ##     ## ##     ## ########"<<endl;
cout<<"                     #######  ##     ## ######## ########"<<endl;
cout<<"                    ##     ## ##     ## ##       ##     ##"<<endl;
cout<<"                    ##     ## ##     ## ##       ##     ##"<<endl;
cout<<"                    ##     ## ##     ## ######   ########"<<endl;
cout<<"                    ##     ##  ##   ##  ##       ##   ##"<<endl;
cout<<"                    ##     ##   ## ##   ##       ##    ##"<<endl;
cout<<"                     #######     ###    ######## ##     ##"<<endl;
        system("pause");
        exit(0);
       }}}
}
return ganar;
}
int* Meta (char**x, int n, int m){
int* meta = new int[2];
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(x[i][j]=='g'){
        meta[0] =i;
        meta[1]= j;
        i =n;
        j=m;
     }
 }
}
return meta;
}
char* jugadaexitos(int* x, int c){
char* jugadaexitosa = new char [c];
for (int i = 0; i<c; i++){
    switch (x[i]){
    case 1:
    jugadaexitosa[i]='b';
    break;
    case 2:
    jugadaexitosa[i]='a';
    break;
    case 3:
    jugadaexitosa[i]='i';
    break;
    case 4:
    jugadaexitosa[i]='d';
    break;
    }
}
return jugadaexitosa;
}
char* jugar (){
ifstream ifs("escenario.txt");
ofstream ofs("jugada_exitosa.txt");
char** t;
char** t1;
int* mov = new int [5];
int* pos = new int [2];
int* meta = new int [2];
int* jugadaexitosaint = new int [100];
int x;
int y;
bool est;
bool gano = false;
int* a = new int[2];
a = leer2(ifs);
int n = a[0] - 0;
int m = a[1] - 0;
t = leer(ifs,n,m);
t1 = creartableroinicial(n,m);
imprimirtablero(t,t1,n,m,gano);
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  t1[i][j]= t[i][j];
  if(t[i][j]=='i'){
    t[i][j]='C';
  }
 }}
meta = Meta(t,n,m);
int v = 0;
while(!gano){
pos = posicionCubo(t,n,m);
x = pos[0];
y = pos[1];
est = estado(t,n,m);
if(est){
mov = movimientoVertical(t,x,y,n,m,false,'0');
system("cls");
t[mov[0]][mov[1]] = 'C';
t[mov[2]][mov[3]] = 'C';
}else{
mov = movimientoHorizontal(t,x,y,n,m, false,'0');
system("cls");
if(mov[2]==-1){
    t[mov[0]][mov[1]] = 'C';
}
else{
t[mov[0]][mov[1]] = 'C';
t[mov[2]][mov[3]] = 'C';
}
}
jugadaexitosaint[v] = mov[4];
v++;
gano = logica(t,t1,n,m, meta);
imprimirtablero(t,t1,n,m,gano);
}
char* jugadaexitosachar = new char[v];
jugadaexitosachar = jugadaexitos(jugadaexitosaint,v);
escribir(jugadaexitosachar,ofs,v);
return jugadaexitosachar;
}
void repetirpc(char* movex){
ifstream ifs("escenario.txt");
char** t;
char** t1;
int* mov = new int [5];
int* pos = new int [2];
int* meta = new int [2];
int* jugadaexitosaint = new int [100];
int x;
int y;
bool est;
bool gano = false;
int* a = new int[2];
a = leer2(ifs);
int n = a[0] - 0;
int m = a[1] - 0;
t = leer(ifs,n,m);
t1 = creartableroinicial(n,m);
imprimirtablero(t,t1,n,m,gano);
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  t1[i][j]= t[i][j];
  if(t[i][j]=='i'){
    t[i][j]='C';
  }
 }}
meta = Meta(t,n,m);
int v = 0;
while(!gano){
system("pause");
pos = posicionCubo(t,n,m);
x = pos[0];
y = pos[1];
est = estado(t,n,m);
if(est){
mov = movimientoVertical(t,x,y,n,m,true,movex[v]);
system("cls");
t[mov[0]][mov[1]] = 'C';
t[mov[2]][mov[3]] = 'C';
}else{
mov = movimientoHorizontal(t,x,y,n,m, true,movex[v]);
system("cls");
if(mov[2]==-1){
    t[mov[0]][mov[1]] = 'C';
}
else{
t[mov[0]][mov[1]] = 'C';
t[mov[2]][mov[3]] = 'C';
}
}
v++;
gano = logica(t,t1,n,m, meta);
imprimirtablero(t,t1,n,m,gano);
}

}
void jugarpc (){
ifstream ifs("escenario.txt");
char** t;
char** t1;
int* mov = new int [5];
int* pos = new int [2];
int* meta = new int [2];
int x;
int y;
bool est;
bool gano = false;
int* a = new int[2];
a = leer2(ifs);
int n = a[0] - 0;
int m = a[1] - 0;
t1 = leer(ifs,n,m);
t = creartableroinicial(n,m);
 for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  t[i][j]= t1[i][j];
  if(t1[i][j]=='i'){
    t[i][j]='C';
  }
 }}
imprimirtablero(t,t1,n,m,gano);
meta = Meta(t,n,m);
while(!gano){
system("pause");
pos = posicionCubo(t,n,m);
x = pos[0];
y = pos[1];
est = estado(t,n,m);
if(est){
mov = movimientoVerticalpc(t,t1,x,y,n,m);
system("cls");
t[mov[0]][mov[1]] = 'C';
t[mov[2]][mov[3]] = 'C';
}else{
mov = movimientoHorizontalpc(t,t1,x,y,n,m);
system("cls");
if(mov[2]==-1){
    t[mov[0]][mov[1]] = 'C';
}
else{
t[mov[0]][mov[1]] = 'C';
t[mov[2]][mov[3]] = 'C';
}
}
gano = logica(t,t1,n,m, meta);
imprimirtablero(t,t1,n,m,gano);
}
}
void dibujarmenu(int a){
    if (a==0){
cout<<"          "<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
cout<<"          "<<char(186)<<"                                  "<<char(186)<<endl;
cout<<"          "<<char(186)<<"           BLOCK & HOLE           "<<char(186)<<endl;
cout<<"          "<<char(186)<<"                                  "<<char(186)<<endl;
cout<<"          "<<char(186)<<"        1. JUGAR PERSONA          "<<char(186)<<endl;
cout<<"          "<<char(186)<<"        2.   JUGAR PC             "<<char(186)<<endl;
cout<<"          "<<char(186)<<"        0.     SALIR              "<<char(186)<<endl;
cout<<"          "<<char(186)<<"                                  "<<char(186)<<endl;
cout<<"          "<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl;
    }
 else{
cout<<"          "<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187)<<endl;
cout<<"          "<<char(186)<<"                                  "<<char(186)<<endl;
cout<<"          "<<char(186)<<"           BLOCK & HOLE           "<<char(186)<<endl;
cout<<"          "<<char(186)<<"                                  "<<char(186)<<endl;
cout<<"          "<<char(186)<<"       1. REPETIR JUGADA          "<<char(186)<<endl;
cout<<"          "<<char(186)<<"       0.   REGRESAR              "<<char(186)<<endl;
cout<<"          "<<char(186)<<"                                  "<<char(186)<<endl;
cout<<"          "<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)
<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188)<<endl;

 }
}
void menu(){
    char a;
    char b;
    char* x;
bool valido = false;
bool validito = false;
while(!valido){
system("cls");
dibujarmenu(0);
cin>>a;
switch(a){
case '1':
system("cls");
x = jugar();
    while(!validito){
    system("cls");
    dibujarmenu(1);
    cin>>b;
    switch(b){
    case '1':
     system("cls");
     repetirpc(x);
    break;
    case '0':
        validito = true;
        break;
    }}
break;
case '2':
system("cls");
 jugarpc();
break;
case '0':
system("cls");
    valido = true;
break;
}
}
}

int main(){
menu();
}
