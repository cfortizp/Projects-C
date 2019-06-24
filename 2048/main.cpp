#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

string** matriz(int n, int m){
    string** x= new string*[n];
    for(int i=0; i<n; i++){
        x[i]= new string[m];
    }
    return x;
}
string** creartableroinicial(int n){
string** x= matriz(n,n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
            x[i][j]=" ";
    }
}
return x;
}
bool vacio(int a, int b, string** x){
bool y = true;
if(x[a][b] == " "){
    y = false;
}else{
y = true;
}
return y;
}
int digitos(int a,int n){
    if(a<10){
        return n;
    }else{
        return digitos(a/10,n+1);
    }
}
int maximonumero(string**x,int n){
int maximo = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(vacio(i,j,x)){
                 if(maximo<atoi(x[i][j].c_str())){
                    maximo = atoi(x[i][j].c_str());
                 }
            }
        }
    }
maximo = digitos(maximo,1);
return maximo;
}
int numeromax (string**x,int i,int j){
int maximo = 0;
maximo = atoi(x[i][j].c_str());
maximo = digitos(maximo,1);
return maximo;
}
void imprimirtablero(string** x, int n){
cout<<endl;
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    int maxim = maximonumero(x,n);
    int maxi = numeromax(x,i,j);
    cout<<"|";
    if(maxi == maxim){
    if(maxim%2==0){
        for(int h = 0; h<5;h++){
        cout<<" ";
    }
        cout<<x[i][j];
        for(int h = 0; h<4;h++){
        cout<<" ";
    }}else{
        for(int h = 0; h<4+maxim-2;h++){
        cout<<" ";
    }
        cout<<x[i][j];
        for(int h = 0; h<4+maxim-2;h++){
        cout<<" ";
        }
  }}
  else{
        for(int h = 0; h<4;h++){
        cout<<" ";
    }
        cout<<x[i][j];
    if(maxi%2==0){

        for(int h = 0; h<3;h++){
        cout<<" ";
    }}else{
     for(int h = 0; h<4;h++){
        cout<<" ";
     }

    }
  }
  }

cout<<"|"<<endl;
}
}
string** aleatorio (string** x, int n,int h){
srand(h);
int f = rand()%n;
int c = rand()%n;
bool t = vacio(f,c,x);
while (t){
   f = rand()%n;
   c = rand()%n;
   t = vacio(f,c,x);
}
string* numero = new string [2];
numero[0] = "2";
numero[1] = "4";
int p = rand()%2;
x[f][c]= numero[p];
return x;
}
string** mover(int n, string** x, int a){
int j, i,h;
int idef = -1;
int jdef = -1;
switch(a){
case 0: //Movimiento Abajo
for(j = 0; j<n;j++){
    i = n-1;
    while(i>=0){
    if(vacio(i,j,x)){
        for(h = i+1; h<n;h++){
            if(!vacio(h,j,x)){
                idef = h;
                jdef = j;
            }
        }
        if(idef!=-1){
           x[idef][jdef] = x[i][j];
           x[i][j]=" ";
           idef = -1;
           jdef = -1;
        }

    }
    i--;
}}
break;
case 1: //Movimietno Arriba
for(j = 0; j<n;j++){
    i = 0;
    while(i<n){
    if(vacio(i,j,x)){
        for(h = i-1; h>=0;h--){
            if(!vacio(h,j,x)){
                idef = h;
                jdef = j;
            }
        }
        if(idef!=-1){
           x[idef][jdef] = x[i][j];
           x[i][j]=" ";
           idef = -1;
           jdef = -1;
        }

    }
    i++;
}}
break;
case 2: //Movimiento Izquierda
for(i = 0; i<n;i++){
    j = 0;
    while(j<n){
    if(vacio(i,j,x)){
        for(h = j-1; h>=0;h--){
            if(!vacio(i,h,x)){
                idef = i;
                jdef = h;
            }
        }
        if(idef!=-1){
           x[idef][jdef] = x[i][j];
           x[i][j]=" ";
           idef = -1;
           jdef = -1;
        }

    }
    j++;
}}
break;
case 3: //Movimiento Derecha
for(i = 0; i<n;i++){
    j = n-1;
    while(j>=0){
    if(vacio(i,j,x)){
        for(h = j+1; h<n;h++){
            if(!vacio(i,h,x)){
                idef = i;
                jdef = h;
            }
        }
        if(idef!=-1){
           x[idef][jdef] = x[i][j];
           x[i][j]=" ";
           idef = -1;
           jdef = -1;
        }

    }
    j--;
}}
break;
}
return x;
}
string** igual(int n, string**x, int a){
int j, i;
bool h;
switch(a){
case 0: //Abajo
for(j = 0; j<n;j++){
    i = n-1;
    while(i>0){
    h = false;
    if(((x[i][j]).compare(x[i-1][j])==0)&&(vacio(i,j,x))){
        h = true;
    stringstream newf;
    int g = atoi(x[i][j].c_str())+atoi(x[i-1][j].c_str());
    newf << g ;
    x[i][j] = newf.str();
    x[i-1][j] = " ";
    }
    if(h){
        i = i-2;
    }else{
            i--;
    }
}}
break;
case 1: //Arriba
for(j = 0; j<n;j++){
    i = 0;
    while(i<n-1){
    h = false;
    if(((x[i][j]).compare(x[i+1][j])==0)&&(vacio(i,j,x))){
        h = true;
    stringstream newf;
    int g = atoi(x[i][j].c_str())+atoi(x[i+1][j].c_str());
    newf << g ;
    x[i][j] = newf.str();
    x[i+1][j] = " ";
    }
    if(h){
        i = i+2;
    }else{
            i++;
    }
}}
break;
case 2: //Izquierda
for(i = 0; i<n;i++){
    j = 0;
    while(j<n-1){
    h = false;
    if(((x[i][j]).compare(x[i][j+1])==0)&&(vacio(i,j,x))){
        h = true;
    stringstream newf;
    int g = atoi(x[i][j].c_str())+atoi(x[i][j+1].c_str());
    newf << g ;
    x[i][j] = newf.str();
    x[i][j+1] = " ";
    }
    if(h){
        j = j+2;
    }else{
            j++;
    }
}}
break;
case 3:
for(i = 0; i<n;i++){
    j = n-1;
    while(j>0){
    h = false;
    if(((x[i][j]).compare(x[i][j-1])==0)&&(vacio(i,j,x))){
        h = true;
    stringstream newf;
    int g = atoi(x[i][j].c_str())+atoi(x[i][j-1].c_str());
    newf << g ;
    x[i][j] = newf.str();
    x[i][j-1] = " ";
    }
    if(h){
        j = j-2;
    }else{
            j--;
    }
}}
break;
}
return x;
}
bool validar_movimiento (int a, string** x, int n){
bool valido = false;
switch(a){
    case 0: //Abajo
    for(int j = 0; j<n;j++){
        for(int i = n-2; i>=0; i--){
            if(vacio(i,j,x)){
                if(!vacio(i+1,j,x)|| ((x[i][j]).compare(x[i+1][j])==0)){
                    valido = true;
                    i = -1;
                    j = n;
            }}
        }
    }
    break;
    case 1: //Arriba
     for(int j = 0; j<n;j++){
        for(int i = 1; i<n; i++){
            if(vacio(i,j,x)){
                if(!vacio(i-1,j,x)||((x[i][j]).compare(x[i-1][j])==0)){
                    valido = true;
                    i = n;
                    j = n;
            }}
        }
    }
    break;
    case 2: // Izquierda
     for(int i = 0; i<n;i++){
        for(int j = 1; j<n; j++){
            if(vacio(i,j,x)){
                if(!vacio(i,j-1,x)||((x[i][j]).compare(x[i][j-1])==0)){
                    valido = true;
                    i = n;
                    j = n;
            }}
        }
    }
    break;
    case 3: // Derecha
    for(int i = 0; i<n;i++){
        for(int j = n-2; j>=0; j--){
            if(vacio(i,j,x)){
                if(!vacio(i,j+1,x)||((x[i][j]).compare(x[i][j+1])==0)){
                    valido = true;
                    i = n;
                    j = -1;
            }}
        }
    }
    break;
}
return valido;
}
bool perdio(string**x,int n){
     if(!validar_movimiento(0,x,n)&&!validar_movimiento(1,x,n)
       &&!validar_movimiento(2,x,n)&& !validar_movimiento(3,x,n)){
        return false;
       }else{
       return true;
       }
}
int seleccion(char a){
switch(a){
   case char(80):    //abajo
    return 0;
   break;
   case char(72):   //arriba
    return 1;
   break;
   case char(75):   //izquierda
    return 2;
   break;
   case char(77):   //derecha
    return 3;
   break;
   default:
     return -1;
   break;
}
}
void logica(int a, string** x, int n){
switch(a){
   case 0:    //abajo
    mover(n,x,a);
    igual(n,x,a);
    mover(n,x,a);
   break;
   case 1:   //arriba
    mover(n,x,a);
    igual(n,x,a);
    mover(n,x,a);
   break;
   case 2:   //izquierda
    mover(n,x,a);
    igual(n,x,a);
    mover(n,x,a);
   break;
   case 3:   //derecha
    mover(n,x,a);
    igual(n,x,a);
    mover(n,x,a);
   break;
}
}
bool valgano (string** x, int n){
bool  valido = false;
for(int i = 0; i<n; i++){
    for(int j = 0;j<n;j++){
        if((x[i][j]).compare("2048")==0){
            valido = true;
        }
    }
}
return valido;
}
void empezar(int n){
string** x;
x =creartableroinicial(n);
imprimirtablero(x,n);
bool j = true;
int i = 0;
int h = 0;
while(j){
system("cls");
imprimirtablero(aleatorio(x,n,i),n);
if (valgano(x,n)&&h==0){
    h++;
    char l ='a';
    while(l!='s'&&l!='S'&&l!='n'&&l!='N'){
    system("cls");
    cout<<"                              ¿DESEA SEGUIR JUGANDO?"<<endl;
    cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
    cout<<"             o             S => Si             N => No            o"<<endl;
    cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
    cin>>l;
    }
    if (l!='s'&&l!='S'){
            h = 3;
    j = false;
    }
}else{
j = perdio(x,n);
bool valido = false;
while(!valido&&perdio(x,n)){
char a;
a = getch();
a = getch();
int b = seleccion(a);
if(b !=-1 && validar_movimiento(b,x,n)){
    logica(b,x,n);
    valido = true;
}
}
}
i++;
}

if(h==3){
cout<<endl;
cout<<"              ######      ###    ##    ##  #######"<<endl;
cout<<"             ##    ##    ## ##   ###   ## ##     ##"<<endl;
cout<<"             ##         ##   ##  ####  ## ##     ##"<<endl;
cout<<"             ##   #### ##     ## ## ## ## ##     ##"<<endl;
cout<<"             ##    ##  ######### ##  #### ##     ##"<<endl;
cout<<"             ##    ##  ##     ## ##   ### ##     ##"<<endl;
cout<<"              ######   ##     ## ##    ##  #######"<<endl;
}else{
cout<<endl;
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
}
}
void pantalla_inicial(){
bool valido = false;
char p;
while(!valido){
p = '0';
cout<<"     #######    #####   ##         #######"<<endl;
cout<<"    ##     ##  ##   ##  ##    ##  ##     ##"<<endl;
cout<<"           ## ##     ## ##    ##  ##     ##"<<endl;
cout<<"     #######  ##     ## ##    ##   #######"<<endl;
cout<<"    ##        ##     ## ######### ##     ##"<<endl;
cout<<"    ##         ##   ##        ##  ##     ##"<<endl;
cout<<"    #########   #####         ##   #######"<<endl;
cout<<endl;
cout<<"      --------------------------------"<<endl;
cout<<"    | E => Empezar juego    S => Salir |     "<<endl;
cout<<"      --------------------------------"<<endl;
while(p!='e'&&p!='E'&&p!='s'&&p!='S'){
    cin>>p;
}
if (p=='e'||p=='E'){
char n = '0';
cout<<" Ingrese el tamano del tablero (Entre 3 y 9)"<<endl;
while(!(n>'2'&& n <='9')){
    cin>>n;
}
int m = n-'0';
system("pause");
empezar(m);
}else if (p=='s'||p=='S'){
    valido = true;
}
}
}
int main()
{
    pantalla_inicial();
}
