#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <mmsystem.h>
#include <string.h>
#include <math.h>
#include <cstdlib>

using namespace std;

int Convbool (char Num []){
    bool Numero=true;
    for(int i=0; i<strlen(Num) ;i++){
       if(Numero==true &&(Num[i]<48||Num[i]>50)){
         Numero=false;
        }
    }
    int Re =-1;
    if(Numero==true){
       Re= atoi(Num);
    }
    return Re;
}
int Calcular(char Expr[]){
int Ev1 = Convbool (Expr);
       if( Ev1 >=0){
           return Ev1;
       }

       char Expr1[50]="";
       char Expr2[50]="";
        char Expr3[50]="";
        char Expr4[50]="";

       sscanf(Expr,"%50[^<=>] <=> %50[^y]",Expr1,Expr2);
       if((strlen(Expr1)!=0)&& (strlen(Expr2)!=0)){
                    int num1=Calcular(Expr1);
          int num2=Calcular(Expr2);
          return (!(num1)||num2) && (!(num2)||num1);

       }

       sscanf(Expr,"%50[^=>] => %50[^v]",Expr1,Expr2);
       if((strlen(Expr1)!=0)&& (strlen(Expr2)!=0)){

             if(Expr2[3]=='0'){
              for(int i=0; i<strlen(Expr2);i++){
                if(i==0){
                   Expr4[i]=Expr1[0];
                    }
                else if (i==1){
                    Expr4[i]='=';
                }
                else if (i==2){
                    Expr4[i]='>';
                }
                else{
                    Expr4[i]= Expr2[0];
                    }
                }
                Expr3[0]='0';
                int num1=Calcular(Expr4);
               int num2=Calcular(Expr3);
              return (!(num1)||num2);
               }
            int num1=Calcular(Expr1);
          int num2=Calcular(Expr2);
          return (!(num1)||num2);
       }
       sscanf(Expr,"%50[^v] v %50[^y]",Expr1,Expr2);
       if((strlen(Expr1)!=0)&& (strlen(Expr2)!=0)){
          int num1=Calcular(Expr1);
          int num2=Calcular(Expr2);
          return num1 || num2;
       }

       sscanf(Expr,"%50[^y] y %50[^v]",Expr1,Expr2);
       if((strlen(Expr1)!=0)&& (strlen(Expr2)!=0)){
          int num1=Calcular(Expr1);
          int num2=Calcular(Expr2);
          return num1&&num2;
          }}
char* Convchar (int a){
    if (a==0){
        char* tex = "0";
        return tex;
        }
    else {
        char* tex = "1";
        return tex;
    }

}
char Enparen (char Oracion []){
int Pos = -1;
int Pos2 = -1;
char Oracion1 [50]="";
char Finalp[1]="";
char Finalt[50]="";
char Paren[50]="";
int j = 0;
for(int i=0; i< strlen(Oracion); i++){
   if ( Oracion[i] == 40){
       Pos = i;
    }}
for (int i = Pos; i< strlen(Oracion); i++){
   if (j!=1){
    if ( Oracion [i]==41){
        Pos2=i;
        j++;
        }
}
}
if((Pos==-1)&&(Pos2==-1)){
    cout<<'\t'<<Calcular (Oracion);
    return EXIT_SUCCESS;
}
j = 0;
for (int i = (Pos+1); i<Pos2 ; i++){
 Paren[j] = Oracion[i];
  j++;
}
strcpy(Finalp, Convchar (Calcular(Paren)) );
int o = 0;
for (int i = 0; i<strlen(Oracion);i++){
    if (i<Pos){
        Finalt[o]=Oracion[i];
        o++;
       }
    else if (i==Pos){
        Finalt[o]= Finalp[0];
        o++;
    }
    else if (i>Pos2){
        Finalt[o]= Oracion[i];
        o++;
        }
}
Enparen(Finalt);
}
char Variable (char Expr[]){
int j = 0;
int j1 = 0;
int j2 = 0;
int j3 = 0;
int n1 = 0;
int n2 = 0;
int n3 = 0;
int k = 0;
int u;

for(int i=0; i<strlen(Expr) ;i++){
if (Expr[i]==112){
    if (j1==0){
        j++;
        j1++;
    }
    }
if (Expr[i]==113){
    if (j2==0){
        j++;
        j2++;
    }
 }
 if (Expr[i]==114){
    if (j3==0){
        j++;
        j3++;
    }}
    }
for(int i=0; i<strlen(Expr) ;i++){
if (Expr[i]== 80){
      n1++;
   if (j1 == 0){
        j++;
        j1++;
    }
}
if (Expr[i]== 81){
      n2++;
   if (j2 == 0){
        j++;
        j2++;
    }

}
if (Expr[i]== 82){
      n3++;
   if (j3 == 0){
        j++;
        j3++;
    }

}
}
 if (j==0){
      Enparen(Expr);

 }
 else{
        u = pow (2,j);
        int f = 0;
        int f1 = 0;
        int f2 = 0;
        int d = 0;
        char Expry[50]="";
        char Exprt[50]="";

while (k<u){
        if (j==3){
            if (d==0){
            for(int i=0; i<strlen(Expr) ;i++){
                    if ((Expr[i]== 112)||(Expr[i]== 113)||(Expr[i]== 114)||(Expr[i]== 80)||(Expr[i]== 81)||(Expr[i]== 82)){
                        Exprt[i]= Expr[i];
                    }
                    else{
                        Exprt[i]= 32;
                    }}
             cout<<'\t'<<Exprt<<'\t'<<'\t'<<Expr<<endl;
             d++;
             }
            if (f2==0){
                for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 112){
                         Expry[i]= 48;
                }
                 else if (Expr[i]==80){
                    Expry[i]=49;}

                else{
                  Expry[i]=Expr[i];
                }
              }
              if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 48;
                }
                 else if (Expr[i]==81){
                    Expry[i]=49;
               }}
                if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                 else if (Expr[i]==82){
                    Expry[i]=49;

                              }}

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
            cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                 else if (Expr[i]==82){
                    Expry[i]=48;
                }}
              cout<<'\t'<<'\t'<<Expry<<'\t';
              cout<<Enparen (Expry)<<endl;
              f1=0;
              f++;
              k++;

                }
                }
            else{
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 49;
                }
                 else if (Expr[i]==81){
                    Expry[i]=48;
               }}
              if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                 else if (Expr[i]==82){
                    Expry[i]=49;
                              }}

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                 else if (Expr[i]==82){
                    Expry[i]=48;
                                }}
               cout<<'\t'<<'\t'<<Expry<<'\t';
              cout<<Enparen (Expry)<<endl;
              f=0;
              f1=0;
              k++;
              f2++;

                }
            }

            }
            else{
                    for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 112){
                         Expry[i]= 49;
                }
                 else if (Expr[i]==80){
                    Expry[i]=48;}
                else{
                  Expry[i]=Expr[i];
                }
              }
                if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 48;
                }
                 else if (Expr[i]==81){
                    Expry[i]=49;
               }}
                  if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                 else if (Expr[i]==82){
                    Expry[i]=49;
                              }}

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
            cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                 else if (Expr[i]==82){
                    Expry[i]=48;
                }}
                cout<<'\t'<<'\t'<<Expry<<'\t';
              cout<<Enparen (Expry)<<endl;
              f1=0;
              f++;
              k++;

                }
               }
            else{
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 49;
                }
                 else if (Expr[i]==81){
                    Expry[i]=48;
               }}
              if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                 else if (Expr[i]==82){
                    Expry[i]=49;
                              }}

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                 else if (Expr[i]==82){
                    Expry[i]=48;
                                }}
              cout<<'\t'<<'\t'<<Expry<<'\t';
              cout<<Enparen (Expry)<<endl;
              f++;
              k++;
              f2++;

                }
            }
            }
        }
        else if (j==2){
           if (j1==0){
           if (d==0){
            for(int i=0; i<strlen(Expr) ;i++){
                    if ((Expr[i]== 113)||(Expr[i]== 114)|| (Expr[i]==81)|| (Expr[i]==82)){
                        Exprt[i]= Expr[i];

                    }
                    else{
                        Exprt[i]= 32;
                    }}
             cout<<'\t'<<Exprt<<'\t'<<'\t'<<Expr<<endl;
             d++;
             }
               if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 48;
                }
                else if (Expr[i]==81){
                    Expry[i]=49;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }
                  if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                else if (Expr[i]==82){
                    Expry[i]=49;
                }
                              }

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                else if (Expr[i]==82){
                    Expry[i]=48;
                }
                }
                cout<<'\t'<<'\t'<<Expry<<'\t';
              cout<<Enparen (Expry)<<endl;
              f1=0;
              f++;
              k++;

                }
                }
            else{
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 49;
                }
                else if (Expr[i]==81){
                    Expry[i]=48;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }
              if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                else if (Expr[i]==82){
                    Expry[i]=49;
                }
                              }

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                else if (Expr[i]==82){
                    Expry[i]=48;
                }
                                }
               cout<<'\t'<<'\t'<<Expry<<'\t';
               cout<<Enparen (Expry)<<endl;

              f++;
              k++;

                }
            }

           }
           else if (j2==0){
            if (d==0){
            for(int i=0; i<strlen(Expr) ;i++){
                    if ((Expr[i]== 112)||(Expr[i]== 114)|| (Expr[i]==80)|| (Expr[i]==82)){
                        Exprt[i]= Expr[i];

                    }
                    else{
                        Exprt[i]= 32;
                    }}
             cout<<'\t'<<Exprt<<'\t'<<'\t'<<Expr<<endl;
             d++;
             }
                if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 112){
                         Expry[i]= 48;

                }
                else if (Expr[i]==80){
                    Expry[i]=49;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }
                  if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                                 }
                    else if (Expr[i] == 82){
                        Expry[i]=49;
                    }
                              }

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                else if (Expr[i]== 82){
                    Expry[i]= 48;
                }
                }
                cout<<'\t'<<'\t'<<Expry<<'\t';
                cout<<Enparen (Expry)<<endl;
              f1=0;
              f++;
              k++;

                }
                }
            else{
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 112){
                         Expry[i]= 49;
                }
                else if (Expr[i]==80){
                    Expry[i]=48;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }
              if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                else if (Expr[i]==82){
                    Expry[i]=49;
                }
                              }

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                else if (Expr[i]==82){
                        Expry[i]= 48;

                }
                                }
               cout<<'\t'<<'\t'<<Expry<<'\t';
               cout<<Enparen (Expry)<<endl;

              f++;
              k++;

                }
            }

           }
           else{
           if (d==0){
            for(int i=0; i<strlen(Expr) ;i++){
                    if ((Expr[i]== 112)||(Expr[i]== 113)|| (Expr[i]==80)|| (Expr[i]==81)){
                        Exprt[i]= Expr[i];

                    }
                    else{
                        Exprt[i]= 32;
                    }}
             cout<<'\t'<<Exprt<<'\t'<<'\t'<<Expr<<endl;
             d++;
             }
               if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 112){
                         Expry[i]= 48;
                }
                else if (Expr[i]==80){
                    Expry[i]=49;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }
                  if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 48;
                }
                else if (Expr[i]==81){
                    Expry[i]=49;
                }
                              }

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 113){
                    Expry[i]= 49;
                }
                else if (Expr[i]==81){
                    Expry[i]=48;
                }
                }
              cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
              f1=0;
              f++;
              k++;

                }
                }
            else{
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 112){
                         Expry[i]= 49;
                }
                else if (Expr[i]==80){
                    Expry[i]=48;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }
              if (f1==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 48;
                }
                else if (Expr[i]==81){
                    Expry[i]=49;
                }
                              }

             f1++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 113){
                    Expry[i]= 49;
                }
                else if (Expr[i]==81){
                    Expry[i]=48;
                }
                                }
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;

              f++;
              k++;

                }
            }

           }
        }
        else {
          if (j1>0){
                if(d==0){
                if (n1==0){
                cout<<'\t'<<"p"<<'\t'<<'\t'<<Expr<<endl;
               }
                else{
                   for(int i=0; i<strlen(Expr) ;i++){
                    if ((Expr[i]== 112)||(Expr[i]== 80)){
                        Exprt[i]= Expr[i];
                    }
                    else{
                        Exprt[i]= 32;
                    }}
                 cout<<'\t'<<Exprt<<'\t'<<'\t'<<Expr<<endl;
                }
                 d++;
             }
               if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 112){
                         Expry[i]= 48;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }
                if (n1>0){
                   for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 80){
                         Expry[i]= 49;
                }
                else{
                  Expry[i]=Expry[i];
                }
              }
                }


             f++;
             cout<<'\t'<<'\t'<<Expry<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
               }
              else  {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 112){
                    Expry[i]= 49;
                                    }
                else{
                    Expry[i]=Expr[i];
                     }
                }
                 if (n1>0){
                   for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 80){
                         Expry[i]= 48;
                }
                else{
                  Expry[i]=Expry[i];
                }
              }
                }
                cout<<'\t'<<'\t'<<Expry<<'\t';
               cout<<Enparen (Expry)<<endl;
              f++;
              k++;
                }
             }
         else if (j2>0){
                if(d==0){
                if (n2==0){
                cout<<'\t'<<"q"<<'\t'<<'\t'<<Expr<<endl;
               }
                else{
                   for(int i=0; i<strlen(Expr) ;i++){
                    if ((Expr[i]== 113)||(Expr[i]== 81)){
                        Exprt[i]= Expr[i];
                    }
                    else{
                        Exprt[i]= 32;
                    }}
                 cout<<'\t'<<Exprt<<'\t'<<'\t'<<Expr<<endl;
                }
                 d++;
             }
               if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 113){
                         Expry[i]= 48;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }

             f++;
             cout<<'\t'<<'\t'<<"0"<<'\t';
             cout<<Enparen(Expry)<<endl;
             k++;
             }
              else  {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 113){
                    Expry[i]= 49;
                }
                else{
                    Expry[i]=Expr[i];
                }
                }
              cout<<'\t'<<'\t'<<"1"<<'\t';
              cout<<Enparen (Expry)<<endl;
              f++;
              k++;

                }
             }
           else{
                  if(d==0){
                if (n3==0){
                cout<<'\t'<<"r"<<'\t'<<'\t'<<Expr<<endl;
               }
                else{
                   for(int i=0; i<strlen(Expr) ;i++){
                    if ((Expr[i]== 114)||(Expr[i]== 82)){
                        Exprt[i]= Expr[i];
                    }
                    else{
                        Exprt[i]= 32;
                    }}
                 cout<<'\t'<<Exprt<<'\t'<<'\t'<<Expr<<endl;
                }
                 d++;
             }
                     if (f==0){
                  for(int i=0; i<strlen(Expr) ;i++){
                    if (Expr[i]== 114){
                         Expry[i]= 48;
                }
                else{
                  Expry[i]=Expr[i];
                }
              }

             f++;
             cout<<'\t'<<'\t'<<"0"<<'\t';
             cout<<Enparen(Expry)<<endl;

             k++;
             }
              else  {
                for(int i=0; i<strlen(Expr) ;i++){
                if (Expr[i]== 114){
                    Expry[i]= 49;
                }
                else{
                    Expry[i]=Expr[i];
                }
                }
                cout<<'\t'<<'\t'<<"1"<<'\t';
              cout<<Enparen (Expry)<<endl;
              f++;
              k++;

                }
             }
           }
        }
    }}
bool Sintaxis (char A[]){
for (int i=0; i<strlen(A);i++){
 if ((A[i]!= '(')&&(A[i]!= ')')&&(A[i]!= '0')&&(A[i]!= '1')&&(A[i]!= '=')&&(A[i]!= '>')&&(A[i]!= '<')&&(A[i]!= 'y')&&(A[i]!= 'p')&&(A[i]!= 'P')&&(A[i]!= 'v')&&(A[i]!= 'q')&&(A[i]!= 'r')&&(A[i]!= 'R')&&(A[i]!= 'Q')){
     return 0;
}}
return 1;
}
bool Paquetes (char A[]){
int j =0;
int k =0;
for (int i=0; i<strlen(A);i++){
  if (A[i]=='('){
        j++;
      }
  else if (A[i]==')'){
        k++;
      }
}
if(j!=k){
    return 0;
}
else{
    return 1;
}
}
bool Dobleoper (char A[]){
for (int i=0; i<strlen(A);i++){
   if ((A[0]=='y')||(A[0]=='v')||(A[0]=='=')||(A[0]=='<')){
    return 0;
   }
else if ((A[i]=='y')||(A[i]=='v')||(A[i]=='>')){
     if ((A[i+1]!='p')&&(A[i+1]!='q')&&(A[i+1]!='r')&&(A[i+1]!='1')&&(A[i+1]!='0')&&(A[i+1]!='P')&&(A[i+1]!='Q')&&(A[i+1]!='R')&&(A[i+1]!='(')){
        return 0;
      }
  }
}
for (int i=0; i<strlen(A);i++){
if ((A[i]=='p')||(A[i]=='q')||(A[i]=='r')||(A[i]=='1')||(A[i]=='0')||(A[i]=='P')||(A[i]=='Q')||(A[i]=='R')){
    if ((A[i+1]=='p')||(A[i+1]=='q')||(A[i+1]=='r')||(A[i+1]=='1')||(A[i+1]=='0')||(A[i+1]=='P')||(A[i+1]=='Q')||(A[i+1]=='R')){
        return 0;
    }
}
return 1;
}}
bool Doblepaque (char A[]){
for (int i =0;i<strlen(A);i++){
    if (A[i]=='('){
            if (A[i+1]==')'){
                return 0;
            }
        }
}
int j = 0;
int k = 0;
for (int i =0;i<strlen(A);i++){
    if (j==0){
         if (A[i]==')'){
        j = i;}
    }
}
for (int i =0;i<strlen(A);i++){
    if (k==0){
         if (A[i]=='('){
        k = i;}
    }
}
if (j<k){
    return 0;
}
else{
  for (int i =0;i<strlen(A);i++){
            if (A[i]=='('){
             if ((A[i+1]=='y')||(A[i+1]=='v')||(A[i+1]=='=')||(A[i+1]=='<')){
             return 0;}}}
for (int i =0;i<strlen(A);i++){
            if (A[i]==')'){
             if ((A[i+1]=='y')||(A[i+1]=='v')||(A[i+1]=='=')||(A[i+1]=='<')){
             return 0;}}}
return 1;
}}
bool Finderror (char A[]){
    Variable(A);
}
char Dibujo (char a, char A[]){
while (a=='S'){
cout<<'\n';
cout<<'\t'<<" ---------------------------------------------------------------"<<endl;
cout<<'\t'<<"                                                               "<<endl;
cout<<'\t'<<"                EVALUADOR DE EXPRESIONES LOGICAS               "<<endl;
cout<<'\n';
cout<<'\t'<<"  >> LOS CONECTIVOS LOGICOS SE DEBEN ESCRIBIR ASI:"<<endl;
cout<<'\n';
cout<<'\t'<<"      ~ CONJUNCION     y"<<endl;
cout<<'\t'<<"      ~ DISYUNCION     v"<<endl;
cout<<'\t'<<"      ~ CONDICIONAL    =>"<<endl;
cout<<'\t'<<"      ~ BICONDICIONAL   <=>"<<endl;
cout<<'\n';
cout<<'\t'<<"  >> LAS VARIABLES PARA UTILIZAR SON:"<<endl;
cout<<'\n';
cout<<'\t'<<"      ~ p - q - r (TABLA DE VERDAD)"<<endl;
cout<<'\t'<<"      ~ P - Q - R (NEGACION DE LAS VARIABLES)"<<endl;
cout<<'\t'<<"      ~ 0 - 1 (RESULTADO ESPECIFICO)"<<endl;
cout<<'\n';
cout<<'\t'<<"  > INGRESE LA EXPRESION: ";
cin>>A;
cout<<'\n';
cout<<'\t'<<" > RESULTADO:";
cout<<'\n';
cout<<'\n';
cout<<'\n';
cout<<'\t';
Finderror(A);
cout<<'\n';
cout<<'\n';
cout<<'\n';
cout<<'\t'<<"            ¿DESEA SEGUIR UTILIZANDO EL EVALUADOR?      "<<endl;
cout<<'\t'<<"            SI: S                          "<<endl;
cout<<'\t'<<'\t'<<'\t'<<'\t';
cin>>a;
cout<<'\n';
cout<<'\n';
cout<<'\n';
cout<<'\t'<<" ---------------------------------------------------------------"<<endl;
system ("cls");

}


}
int main(){
system("color 0a");
char texto[50];
char a = 'S';
Dibujo (a, texto);
}
