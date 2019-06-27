#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <mmsystem.h>
#include <string.h>
#include <math.h>
#include <cstdlib>
using namespace std;
ostream& escribir(string* a, ostream& os, int n){
      for(int i = 0; i< n; i++){
          os<<a[i]<<endl;
          }
    return os;
}
string* leer (istream& is ){
    string* x = new string[2];
    string a;
   for(int i = 0; i <2; i++){
    is>>a;
    x[i]=a;
   }
  return x;
}
char** matriz(int n, int m){
    char** x= new char*[n];
    for(int i=0; i<n; i++){
        x[i]= new char[m];
    }
    return x;
}
char** creartableroinicial(int n){
char** x= matriz(n,n);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
            x[i][j]=' ';
    }
}
return x;
}
void imprimirtablero(char** x, int n){
    cout<<"        ";
 for(int i = 0; i< n; i++){
        cout<<" "<<i+1;
}
cout<<""<<endl;
int k = 1;
for(int i=0;i<n;i++){
    cout<<"       "<<k;
    k++;
    for(int j=0;j<n;j++){
    cout<<"|"<<x[i][j];
  }
cout<<"|"<<endl;
}

}
bool vacio(int a, int b, char** x){
bool y = true;
if(x[a-1][b-1] == 32){
    y = false;
}else{
y = true;
}
return y;
}
bool logica(char** x, int t, int turno){
bool a;
bool n = true;
char* Win = new char[1];
if (turno == 0){
     Win[0] = 'O';
}
else{
     Win[0] = 'X';
}

int w = 0;
   for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                if ((j + 1 < t) & (j + 2 < t)) {
                    if (x[i][j] == Win[0]) {
                        if (x[i][j + 1] == Win[0]) {
                            if (x[i][j + 2] == Win[0]) {
                                w++;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                if ((i + 1 < t) & (i + 2 < t) & (j + 1 < t) & (j + 2 < t)) {
                    if (x[i][j] == Win[0]) {
                        if (x[i + 1][j + 1] == Win[0]) {
                            if (x[i + 2][j + 2] == Win[0]) {
                                w++;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                if ((i + 1 < t) & (i + 2 < t)) {
                    if (x[i][j] == Win[0]) {
                        if (x[i + 1][j] == Win[0]) {
                            if (x[i + 2][j] == Win[0]) {
                                w++;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                if (((i + 1 < t) & (i + 2 < t)) & ((j - 1 > -1) & (j - 2 > -1))) {
                    if (x[i][j] == Win[0]) {
                        if (x[i + 1][j - 1] == Win[0]) {
                            if (x[i + 2][j - 2] == Win[0]) {
                                w++;
                            }
                        }
                    }
                }
            }
        }
if (w >= 1) {
  a = false;
 }
else{
 a = true;
 }
return a;
    }
int* juegojugvscp (char** x, int n, int* JUGCOM){
system("cls");
int empezar = 0;
empezar = rand()%2;
bool b;
bool a = true;
bool c = true;
cout<<empezar<<endl;
if(empezar == 0){
    cout<<"Empieza el Jugador (O)"<<endl;
    b = true;
}else{
    cout<<"Empieza el Computador (X)"<<endl;
    b = false;
}
while(a){
    if(b){
        while(c){
            imprimirtablero(x,n);
            string f;
            string d;
            cout<<"Turno (O)"<<endl;
            cout<<"Fila: ";
            cin>>f;
            cout<<"Columna: ";
            cin>>d;
            int fila;
            int columna;
            try{
            fila = atoi(f.c_str());
            columna = atoi(d.c_str());
              if(fila<n+1 && columna <n+1){
                c = vacio(fila, columna, x);
            }
            if(c==false){
               x[fila - 1][columna - 1] = 'O';
            }else{
            cout<<"Opcion Invalida"<<endl;
            }
            }catch(exception e){
            }

         }
         system("cls");
         c = true;
         b = false;
         a= logica(x,n,0);
    }
    else{
       cout<<"Turno X:"<<endl;
                while (c) {
                 int I =  rand()%n+1;
                 int J =  rand()%n+1;
                 I+1;
                 J+1;
                 c = vacio(I, J, x);
                 if (c == false) {
                   cout<<"Fila:"<<endl;
                   cout<<I<<endl;
                   cout<<"Columna:"<<endl;
                   cout<<J<<endl;
                   x[I - 1][J - 1] = 'X';

                    }
                }
                c = true;
                b = true;
                a = logica(x,n,1);
     }
     system("cls");
        int p = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (x[i][j] == 32) {
                        p++;
                    }
                }
            }
            if (p == 0) {
                a = false;
            }
}
imprimirtablero(x,n);
        if ((logica(x,n,0) == true) && (logica(x,n,1) == true)) {
            cout<<"EMPATE"<<endl;;
        } else if (logica(x,n,1) == false) {
            cout<<"Perdio :("<<endl;
            JUGCOM[1]= JUGCOM[1]+1;
        } else if (logica(x,n,0) == false) {
            cout<<"GANO :)"<<endl;
            JUGCOM[0]= JUGCOM[0]+1;


        }

cout<<endl;
cout<<"1. SEGUIR JUGANDO"<<endl;
cout<<"De lo contrario se saldra del programa"<<endl;
cout<<"-> ";
JUGCOM[2]= JUGCOM[2]+1;
return JUGCOM;
}
void juegojugvsjug(char** x, int n){
int empezar = 0;
empezar = rand()%2;
bool b;
bool a = true;
bool c = true;
cout<<empezar<<endl;
if(empezar == 0){
    cout<<"Empieza el Jugador (O)"<<endl;
    b = true;
}else{
    cout<<"Empieza el Jugador (X)"<<endl;
    b = false;
}
while(a){
    if(b){
        while(c){
                system("cls");
               imprimirtablero(x,n);
            string f;
            string d;
            cout<<"Turno (O)"<<endl;
            cout<<"Fila: ";
            cin>>f;
            cout<<"Columna: ";
            cin>>d;
            int fila;
            int columna;
            try{
            fila = atoi(f.c_str());
            columna = atoi(d.c_str());
            if(fila<n+1 && columna <n+1){
                c = vacio(fila, columna, x);
            }
            if(c==false){
               x[fila - 1][columna - 1] = 'O';
            }else{
            cout<<"Opcion Invalida"<<endl;
            }
            }catch(exception e){
            }
           }
         c = true;
         b = false;
         a= logica(x,n,0);
    }
    else{
            while(c){
                system("cls");
                    imprimirtablero(x,n);
            string f;
            string d;
            cout<<"Turno (X)"<<endl;
            cout<<"Fila: ";
            cin>>f;
            cout<<"Columna: ";
            cin>>d;
            int fila;
            int columna;
            try{
            fila = atoi(f.c_str());
            columna = atoi(d.c_str());
            if(fila<n+1 && columna <n+1){
                c = vacio(fila, columna, x);
            }
            if(c==false){
               x[fila - 1][columna - 1] = 'X';
            }else{
            cout<<"Opcion Invalida"<<endl;
            }
            }catch(exception e){
            }
            }

                c = true;
                b = true;
                a = logica(x,n,1);
     }
        int p = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (x[i][j] == 32) {
                        p++;
                    }
                }
            }
            if (p == 0) {
                a = false;
            }
}
        system("cls");
        imprimirtablero(x,n);
        if ((logica(x,n,0) == true) && (logica(x,n,1) == true)) {
            cout<<"EMPATE"<<endl;;
        } else if (logica(x,n,1) == false) {
            cout<<"Gano el Jugador (X) :)"<<endl;
        } else if (logica(x,n,0) == false) {
            cout<<"GANO el Jugador (O) :)"<<endl;

        }
cout<<endl;
cout<<"1. SEGUIR JUGANDO"<<endl;
cout<<"De lo contrario se saldra del programa"<<endl;
cout<<"-> ";
}
void juegocpvscp (char**x, int n){
    system("cls");
int empezar = 0;
empezar = rand()%2;
bool b;
bool a = true;
bool c = true;
if(empezar == 0){
    cout<<"Empieza el Computador (O)"<<endl;
    b = true;
}else{
    cout<<"Empieza el Computador (X)"<<endl;
    b = false;
}
while(a){
       if(b){
            imprimirtablero(x,n);
            cout<<"Turno O:"<<endl;
                while (c) {
                 int I =  rand()%n+1;
                 int J =  rand()%n+1;
                 I+1;
                 J+1;
                 c = vacio(I, J, x);
                 if (c == false) {
                   cout<<"Fila:"<<endl;
                   cout<<I<<endl;
                   cout<<"Columna:"<<endl;
                   cout<<J<<endl;
                   x[I - 1][J - 1] = 'O';

                    }
                }

         c = true;
         b = false;
         a= logica(x,n,0);
    }
    else{
       imprimirtablero(x,n);
       cout<<"Turno X:"<<endl;
                while (c) {
                 int I =  rand()%n+1;
                 int J =  rand()%n+1;
                 I+1;
                 J+1;
                 c = vacio(I, J, x);
                 if (c == false) {
                   cout<<"Fila:"<<endl;
                   cout<<I<<endl;
                   cout<<"Columna:"<<endl;
                   cout<<J<<endl;
                   x[I - 1][J - 1] = 'X';

                    }
                }

                c = true;
                b = true;
                a = logica(x,n,1);
     }
        int p = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (x[i][j] == 32) {
                        p++;
                    }
                }
            }
            if (p == 0) {
                a = false;
            }
}
imprimirtablero(x,n);
        if ((logica(x,n,0) == true) && (logica(x,n,1) == true)) {
            cout<<"EMPATE"<<endl;;
        } else if (logica(x,n,1) == false) {
            cout<<"Gano el Computador (X) :)"<<endl;
        } else if (logica(x,n,0) == false) {
            cout<<"Gano el Computador (O) :)"<<endl;

        }
cout<<endl;
cout<<"1. SEGUIR JUGANDO"<<endl;
cout<<"De lo contrario se saldra del programa"<<endl;
cout<<"-> ";
}
int* pantalladificultad(char**x, int n, int* JUGCOM){
system("cls");
cout<<""<<endl;
cout<<"         *************************************************************"<<endl;
cout<<"         *          @@@@@ @@@@  @@@@@  @@@@@  @   @ @@@@@            *"<<endl;
cout<<"         *            @   @  @    @    @   @  @   @   @              *"<<endl;
cout<<"         *            @   @@@@    @    @ @ @  @   @   @              *"<<endl;
cout<<"         *            @   @ @     @    @  @@  @   @   @              *"<<endl;
cout<<"         *            @   @  @  @@@@@  @@@@@  @@@@@ @@@@@            *"<<endl;
cout<<"         *                                  @                        *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                SELECCIONE EL MODO DE JUEGO                *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                   1. Jugador VS Jugador                   *"<<endl;
cout<<"         *                  2. Jugador  VS Computador                *"<<endl;
cout<<"         *                3. Computador VS Computador                *"<<endl;
cout<<"         *                          0. SALIR                         *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *************************************************************"<<endl;
char a;
cout<<"-> ";
cin>>a;
if (a =='1'){
juegojugvsjug(x,n);
}else if(a=='2'){
JUGCOM = juegojugvscp(x,n, JUGCOM);
}else if(a=='3'){
juegocpvscp(x,n);
}else if(a=='0'){
cout<<"Presione una tecla para salir"<<endl;
   EXIT_SUCCESS;
}else{
cout<<"Opcion Invalida"<<endl;
pantalladificultad(x,n, JUGCOM);
}
return JUGCOM;
}
int* pantallatablero(int* JUGCOM){
        system("cls");
cout<<""<<endl;
cout<<"         *************************************************************"<<endl;
cout<<"         *          @@@@@ @@@@  @@@@@  @@@@@  @   @ @@@@@            *"<<endl;
cout<<"         *            @   @  @    @    @   @  @   @   @              *"<<endl;
cout<<"         *            @   @@@@    @    @ @ @  @   @   @              *"<<endl;
cout<<"         *            @   @ @     @    @  @@  @   @   @              *"<<endl;
cout<<"         *            @   @  @  @@@@@  @@@@@  @@@@@ @@@@@            *"<<endl;
cout<<"         *                                  @                        *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                  SELECCIONE EL TAMAÑO                     *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                      1. 3 x 3                             *"<<endl;
cout<<"         *                      2. 4 x 4                             *"<<endl;
cout<<"         *                      3. 5 x 5                             *"<<endl;
cout<<"         *                      4. 6 x 6                             *"<<endl;
cout<<"         *                      0. SALIR                             *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *************************************************************"<<endl;
cout<<"         NOTA: EN TODOS LOS TABLEROS SE GANA AL TENER TRES CONSECUTIVAS"<<endl;
char a;
cout<<"-> ";
cin>>a;
if (a =='1'){
char**x;
x = creartableroinicial(3);
JUGCOM = pantalladificultad(x,3, JUGCOM);
}else if(a=='2'){
char**x;
x = creartableroinicial(4);
JUGCOM = pantalladificultad(x,4, JUGCOM);
}else if(a=='3'){
char**x;
x = creartableroinicial(5);
JUGCOM = pantalladificultad(x,5, JUGCOM);
}else if (a=='4'){
char**x;
x = creartableroinicial(6);
JUGCOM = pantalladificultad(x,6, JUGCOM);
}else if(a=='0'){
cout<<"Presione una tecla para salir"<<endl;
   EXIT_SUCCESS;
}else{
cout<<"Opcion Invalida"<<endl;
pantallatablero(JUGCOM);
}
return JUGCOM;
}
void configuraciones(){
        system("cls");
cout<<""<<endl;
cout<<"         *************************************************************"<<endl;
cout<<"         *          @@@@@ @@@@  @@@@@  @@@@@  @   @ @@@@@            *"<<endl;
cout<<"         *            @   @  @    @    @   @  @   @   @              *"<<endl;
cout<<"         *            @   @@@@    @    @ @ @  @   @   @              *"<<endl;
cout<<"         *            @   @ @     @    @  @@  @   @   @              *"<<endl;
cout<<"         *            @   @  @  @@@@@  @@@@@  @@@@@ @@@@@            *"<<endl;
cout<<"         *                                  @                        *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                        1. GREEN                           *"<<endl;
cout<<"         *                        2. PINK                            *"<<endl;
cout<<"         *                        3. YELLOW                          *"<<endl;
cout<<"         *                        4. BLUE                            *"<<endl;
cout<<"         *                        5. RED                             *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *************************************************************"<<endl;
char a;
cout<<"-> ";
cin>>a;
if (a =='1'){
system("color 0a");
}else if(a=='2'){
system("color 0d");
}else if(a=='3'){
system("color 0e");
}else if(a=='4'){
system("color 0b");
}else if(a=='5'){
system("color 0c");
}else{
cout<<"Opcion Invalida"<<endl;

}
cout<<"1. MENU PRINCIPAL"<<endl;
cout<<"De lo contrario se saldra del programa"<<endl;
cout<<"-> ";
}
int* pantalla(int* JUGCOM){
system("cls");
cout<<""<<endl;
cout<<"         *************************************************************"<<endl;
cout<<"         *          @@@@@ @@@@  @@@@@  @@@@@  @   @ @@@@@            *"<<endl;
cout<<"         *            @   @  @    @    @   @  @   @   @              *"<<endl;
cout<<"         *            @   @@@@    @    @ @ @  @   @   @              *"<<endl;
cout<<"         *            @   @ @     @    @  @@  @   @   @              *"<<endl;
cout<<"         *            @   @  @  @@@@@  @@@@@  @@@@@ @@@@@            *"<<endl;
cout<<"         *                                  @                        *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                   1. EMPEZAR JUEGO                        *"<<endl;
cout<<"         *                   2. CONFIGURACIONES                      *"<<endl;
cout<<"         *                   0.    SALIR                             *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *                                                           *"<<endl;
cout<<"         *************************************************************"<<endl;
char a;
cout<<"-> ";
cin>>a;
if (a =='1'){
JUGCOM = pantallatablero(JUGCOM);
}else if(a=='2'){
configuraciones();
}    else if(a=='0'){
cout<<"Presione una tecla para salir"<<endl;
EXIT_SUCCESS;
}else{
cout<<"Opcion Invalida"<<endl;
pantalla(JUGCOM);
}
return JUGCOM;
}
int sacarpuntaje (int* JUGCOM){
JUGCOM[0]= JUGCOM[0]*100;
JUGCOM[1]= JUGCOM[1]*100;

return ((2*JUGCOM[0])-JUGCOM[1])/JUGCOM[2];

}
int main()
{
    int* JUGCOM = new int[3];
    JUGCOM[0]= 0;
    JUGCOM[1]= 0;
    JUGCOM[2]= 0;
    string nombre;
    cout<<"INGRESA TU NOMBRE: ";
    cin>>nombre;
    char a = '1';
    while('1'==a){
    JUGCOM = pantalla(JUGCOM);
    cin>>a;
    }
    string* x = new string[2];
    x[0]=nombre;
    x[1]= sacarpuntaje(JUGCOM);
}
