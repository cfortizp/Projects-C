
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>

using namespace std;

ostream& escribir(string a, ostream& os){
    os<<a;
    return os;
}
char** matriz(int n, int m){
    char** x= new char*[n];
    for(int i=0; i<n; i++){
        x[i]= new char[m];
    }
    return x;
}
int posicionleng(char* l,char a){
    int pos = -1;
    for(int i = 0; i<strlen(l);i++){
        if(a == l[i]){
            pos = i;
            i = strlen(l);
        }
    }
    return pos;
}
void imprimirmatriz(char** m,char* l, char* e){
  cout<<"\nMatriz de Transicion\n"<<endl;

  cout<<"   ";
  for(int k=0;k<strlen(e);k++){
    cout<<e[k]<<" ";
  }
  cout<<endl;
  for(int i = 0; i<strlen(l);i++){
        cout<<" "<<l[i]<<" ";
        for(int j =0; j<strlen(e);j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool validar(string a,char** m,char* l,char* e,char in,char* fin){
    bool val = true;
    if(a=="N"){
        if(posicionleng(fin,in)!=-1){
            return true;
        }else{
            return false;
        }
    }else{
    int n = a.length();
    char* cadena = new char[n+1];
    strcpy(cadena, a.c_str());
    char estado = in;
    for(int i = 0; i<strlen(cadena);i++){
        int posl =posicionleng(l,cadena[i]);
        if(posl!=-1){
            int pose = posicionleng(e,estado);
            estado = m[posl][pose];
        }else{
            //cout<<"Caracter no pertenece al lenguaje"<<endl;
            val = false;
            i = strlen(cadena);
        }
    }
    if(posicionleng(fin,estado)!=-1){
        if(val!=false){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
    }
}
bool entero(string cadena){
    char lenguaje1 [10]= {'0','1','2','3','4','5','6','7','8','9'};
    char estados1 [1] = {'0'};
    char estadoin = '0';
    char estadosf1 [1] = {'0'};
    char transicion1 [10][1] ={{'0'},{'0'},{'0'},{'0'},{'0'},{'0'},{'0'},{'0'},{'0'},{'0'}};
    int filas = sizeof(lenguaje1);
    int columnas = sizeof(estados1);
    char* lenguaje = new char[filas];
        for(int j = 0; j<filas;j++){
            lenguaje[j] = lenguaje1[j];
        }
    char* estados = new char[columnas];
    for(int j = 0; j<columnas;j++){
            estados[j] = estados1[j];
    }
    char* estadosf = new char[sizeof(estadosf1)];
    for(int j = 0; j<sizeof(estadosf1);j++){
            estadosf[j] = estadosf1[j];
    }
    char** transicion = matriz(filas,columnas);
    for (int i = 0; i<filas;i++){
        for(int j = 0; j<columnas;j++){
            transicion[i][j] = transicion1[i][j];
        }
    }
    return validar(cadena,transicion,lenguaje,estados,estadoin,estadosf);
}
bool flotante(string cadena){
    char lenguaje1 [11]= {'0','1','2','3','4','5','6','7','8','9','.'};
    char estados1 [5] = {'0','1','2','3','4'};
    char estadoin = '0';
    char estadosf1 [1] = {'2'};
    char transicion1 [11][5] ={{'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'4','2','2','3','4'},
                               {'3','3','3','3','1'}};
    int filas = sizeof(lenguaje1);
    int columnas = sizeof(estados1);
    char* lenguaje = new char[filas];
        for(int j = 0; j<filas;j++){
            lenguaje[j] = lenguaje1[j];
        }
    char* estados = new char[columnas];
    for(int j = 0; j<columnas;j++){
            estados[j] = estados1[j];
    }
    char* estadosf = new char[sizeof(estadosf1)];
    for(int j = 0; j<sizeof(estadosf1);j++){
            estadosf[j] = estadosf1[j];
    }
    char** transicion = matriz(filas,columnas);
    for (int i = 0; i<filas;i++){
        for(int j = 0; j<columnas;j++){
            transicion[i][j] = transicion1[i][j];
        }
    }
    return validar(cadena,transicion,lenguaje,estados,estadoin,estadosf);
}
string validar (string cadena){
    //Definir los automatas de las variables numericas
    //Enteros (funcion entero)
    //Flotantes (funcion flotante)
    //Definir los tokens de palabras
    char* palabrastokens [21] = {"cos","end","e","else","fabs","false","for",
                          "function","importar","in","if","log","math",
                          "pow","pi","retorno","sqrt","sin","true",
                          "while","elseif"};
    // Definir los tokens de caracteres y expresiones

    char* simbolostokens [26][2] = {{"{","token_llave_izq"},
                                   {"}","token_llave_der"},
                                   {"#","token_com"},
                                   {"[","token_cor_izq"},
                                   {"]","token_cor_der"},
                                   {"(","token_par_izq"},
                                   {")","token_par_der"},
                                   {">","token_mayor"},
                                   {"<","token_menor"},
                                   {">=","token_mayor_igual"},
                                   {"<=","token_menor_igual"},
                                   {"==","token_igual_num"},
                                   {".","token_point"},
                                   {"!=","token_diff_num"},
                                   {"&&","token_and"},
                                   {"=","token_equal"},
                                   {"||","token_or"},
                                   {"!","token_not"},
                                   {"+","token_mas"},
                                   {"-","token_menos"},
                                   {"*","token_mul"},
                                   {"/","token_div"},
                                   {"%","token_mod"},
                                   {"^","token_pot"},
                                   {":","token_asignar"},
                                   {",","token_coma"}};
    string retorno = "";
    char char_cadena [cadena.length()];
    strcpy(char_cadena,cadena.c_str());
    bool is_string = 0;
    if(char_cadena[0]=='"'){
        is_string =1;
    }
    if(is_string==0){
       bool numero = true;
       for(int i = 0; i<strlen(char_cadena);i++){
                if(!((char_cadena[i]>='0' && char_cadena[i]<='9')||(char_cadena[i]=='.'))){
                        numero = false;
                        i = strlen(char_cadena);
       }}
       if(numero){
            bool is_entero = entero(cadena);
            bool is_flotante = flotante(cadena);
            if(is_entero){
                retorno = "token_entero";
            }
            else if(is_flotante){
                retorno = "token_flotante";
            }else{
                retorno = "Flotientero";
            }
       }else{
       int simbolo = 0;
       for(int i = 0; i<strlen(char_cadena);i++){
                if((char_cadena[i]>='a' && char_cadena[i]<='z') ||(char_cadena[i]>='A' && char_cadena[i]<='Z')||
                   (char_cadena[i]>='0' && char_cadena[i]<='9')){
                        simbolo++;
                }else{
                        simbolo--;
                }
        }
        if (simbolo==strlen(char_cadena)){
            for (int i = 0; i<21;i++){
            string tokenword (palabrastokens[i]);
            if (tokenword.compare(cadena) == 0){
                retorno = tokenword;
            }
            }
        if (retorno.compare("")==0){
            if(char_cadena[0]>='0' && char_cadena[0]<='9'){
                retorno ="";
            }else{
            retorno = "id";
            }
        }
       }else if (simbolo==-(strlen(char_cadena))){
            for (int i = 0; i<26;i++){
                string token (simbolostokens[i][0]);
            if (token.compare(cadena) == 0){
                string tokenr(simbolostokens[i][1]);
                retorno = tokenr;
            }
            }
       }
       }

    }else{
        if (strlen(char_cadena)!=1){
        if (char_cadena[strlen(char_cadena)-1]=='"'){
            retorno = "token_string";
        }
        }
    }
    return retorno;
}
string imprimir(string retorno, string cadena,int f, int c){
    string iguales [4] = {"id","token_string","token_entero","token_flotante"};
    bool especial_imp = false;
    string imprimir ="";
    for (int i = 0; i<4;i++){
        if (retorno.compare(iguales[i])==0){
            i = 4;
            especial_imp = true;
        }
    }
    imprimir = "<";
    imprimir = imprimir + retorno+",";
    if (especial_imp){
        imprimir= imprimir+cadena+",";
    }
    stringstream ss;
    ss << f;
    imprimir = imprimir + ss.str()+",";
    ss << c;
    imprimir = imprimir + ss.str();
    imprimir = imprimir+">";
    return imprimir;
}
string imprimirerror(int f, int c){
    string imprimir ="";
    imprimir = "ERROR LEXICO (";
    stringstream ss;
    ss << f;
    imprimir = imprimir + ss.str()+",";
    ss << c;
    imprimir = imprimir + ss.str();
    imprimir = imprimir+")";
    return imprimir;
}
bool es_gramatica_inicio(char**gram_inicio,string word){
    bool is = false;
    for(int i = 0; i<11;i++){
        string llave(gram_inicio[i]);
        if (llave.compare(word) == 0){
            is = true;
            i = 11;
        }
    }
    return is;
}
bool validar_sintactico(vector<char**>gramatica,vector<int>tamanio,vector<string*>evaluar,char**gram_inicio,vector<int>size_e,string init){
    char* inicio[12] = {"end","else","for","function","importar","if","log","retorno","while","ASG","elseif","FUNL"};
    bool is_inicio = false;
    for(int i = 0; i<12;i++){
        string inicioword (inicio[i]);
        if (inicioword.compare(evaluar[0][0]) == 0){
                is_inicio = true;
                i = 12;
        }
    }
    int coma = 0;
    bool arreglo = false;
    //cout<<init<<endl;
    //cout<<init<<endl;
    if(init.compare("ARR")==0){
    bool array_is = false;
    if(evaluar[0][0].compare("token_cor_izq")==0){
        vector<string*>evaluar2;
        vector<string*>evaluar2_copia;
        vector<int>size_e2;
        vector<int>size_e2_copia;

        for(int i = 1; i<evaluar.size();i++){
            if(evaluar[i][0].compare("token_coma")==0){
                if (validar_sintactico(gramatica,tamanio,evaluar2,gram_inicio,size_e2,"EXP2")){
                    array_is = true;
                    evaluar2.clear();
                }else{
                    i = evaluar.size();
                    array_is = false;
                }
            }else if(evaluar[i][0].compare("token_cor_der")==0){
                if(evaluar2.size()!=0){
                if (validar_sintactico(gramatica,tamanio,evaluar2,gram_inicio,size_e2,"EXP2")){
                    array_is = true;
                    evaluar2.clear();
                }else{
                    i = evaluar.size();
                    array_is = false;
                }}else{
                    i = evaluar.size();
                    array_is = false;
                }
            }else{
                evaluar2.push_back(evaluar[i]);
                size_e2.push_back(size_e[i]);
            }
        }
        if (evaluar2.size()!=0){
            array_is = false;
        }

    }
    return array_is;
    }else if(init.compare("ARL")==0){
    bool array_is = false;
    if(evaluar[0][0].compare("token_par_izq")==0){
        vector<string*>evaluar2;
        vector<string*>evaluar2_copia;
        vector<int>size_e2;
        vector<int>size_e2_copia;

        for(int i = 1; i<evaluar.size();i++){
            if(evaluar[i][0].compare("token_coma")==0){
                if (validar_sintactico(gramatica,tamanio,evaluar2,gram_inicio,size_e2,"EXP2")){
                    array_is = true;
                    evaluar2.clear();
                }else{
                    i = evaluar.size();
                    array_is = false;
                }
            }else if(evaluar[i][0].compare("token_par_der")==0){
                if(evaluar2.size()!=0){
                if (validar_sintactico(gramatica,tamanio,evaluar2,gram_inicio,size_e2,"EXP2")){
                    array_is = true;
                    evaluar2.clear();
                }else{
                    i = evaluar.size();
                    array_is = false;
                }}else{
                    i = evaluar.size();
                    array_is = false;
                }
            }else{
                evaluar2.push_back(evaluar[i]);
                size_e2.push_back(size_e[i]);
            }
        }
        if (evaluar2.size()!=0){
            array_is = false;
        }

    }
    return array_is;
    }
    else{

    //cout<<"******************************"<<endl;
    /*for(int j = 0; j<evaluar.size();j++){
                cout<<evaluar[j][0]<<" ";
    }
    cout<<endl;
    */
    /*cout<<"I "<<is_inicio<<endl;
    cout<<"W "<<init<<endl;*/
        bool valido = false;
        for(int i = 0; i<gramatica.size();i++){
            string llave(gramatica[i][0]);
            string initial;
            if (is_inicio){
                initial = evaluar[0][0];
            }else{
                if(evaluar[0][0].compare("id")==0){
                    if(init.compare("")==0){
                        if (evaluar[1][0].compare("token_equal")==0){
                            initial = "ASG";
                        }else{
                            initial = "FUNL";
                        }
                    }else{
                        initial = init;
                    }
                }else{
                    initial = init;
                }
            }
            if (llave.compare(initial)==0){
                /*
                cout<<"-------------"<<endl;
                for(int j= 0; j<tamanio[i];j++){
                    cout<<gramatica[i][j]<<" ";
                }cout<<endl;
                cout<<"-------------"<<endl;
                */
                bool is_valido = false;
                int regla_size = 1;
                vector<string*>evaluar2;
                vector<string*>evaluar2_copia;
                vector<int>size_e2;
                vector<int>size_e2_copia;
                int pos = -1;
                bool value = false;
                bool new_val = false;
                string a_evaluar;
                for(int j=0;j<evaluar.size();j++){
                    //system("pause");
                    /*cout<<"NV "<<new_val<<" V "<<valido<<endl;
                    cout<<"RZ "<<regla_size<<endl;*/
                    if (new_val == false){
                        //cout<<"NEW VAL"<<endl;
                        if(evaluar2.size()!=0){
                            //cout<<"HOLO"<<endl;
                            if(validar_sintactico(gramatica,tamanio,evaluar2,gram_inicio,size_e2,a_evaluar)){
                                valido = true;
                                evaluar2.clear();
                                size_e2.clear();
                            }else{
                                j = evaluar.size();
                                valido = false;
                            }
                        }
                    }
                    if(regla_size<tamanio[i]){
                        string toke(gramatica[i][regla_size]);
                        a_evaluar = toke;
                       //cout<<"T "<<toke<<" AT "<<a_evaluar<<endl;
                        if(es_gramatica_inicio(gram_inicio,toke)){
                            //cout<<"A"<<endl;
                            new_val = true;
                        }else{
                        //cout<<evaluar[j][0]<<endl;
                        if(toke.compare(evaluar[j][0])==0){
                                //cout<<"A1"<<endl;
                                regla_size++;
                                valido = true;
                        }else{
                            //cout<<"A2"<<endl;
                            j = evaluar.size();
                            valido = false;
                        }
                        }
                        if(new_val){
                            //cout<<"A3"<<endl;
                            evaluar2.push_back(evaluar[j]);
                            size_e2.push_back(size_e[j]);
                            bool v = validar_sintactico(gramatica,tamanio,evaluar2,gram_inicio,size_e2,a_evaluar);
                            //cout<<"BOOL "<<v<<endl;
                            if(v){
                                //cout<<"A4"<<endl;
                                pos = j;
                                evaluar2_copia = evaluar2;
                                size_e2_copia =size_e2;
                            }
                            if(j==evaluar.size()-1){
                                //cout<<"A5"<<endl;
                                if(regla_size<tamanio[i]-1){
                                        //cout<<"A6"<<endl;
                                        if(pos!=-1){
                                           // cout<<"A7"<<endl;
                                            j = pos;
                                            pos = -1;
                                            regla_size++;
                                            new_val = false;
                                            evaluar2 = evaluar2_copia;
                                            size_e2 = size_e2_copia;
                                        }
                                }
                            }
                        }
                    }else{
                         //cout<<"A8"<<endl;
                         j = evaluar.size();
                         valido = false;
                    }


                }
                //cout<<"A EV "<<a_evaluar<<endl;
                if (new_val == true){
                        //cout<<"NEW VAL1"<<endl;
                        if(evaluar2.size()!=0){
                           // cout<<"HOLO2"<<endl;
                            if(validar_sintactico(gramatica,tamanio,evaluar2,gram_inicio,size_e2,a_evaluar)){
                                valido = true;
                                evaluar2.clear();
                                size_e2.clear();
                            }else{
                                valido = false;
                            }
                        }
                    }
                //MIRAR REGLA SIZE
                // Y VALID0
                /*cout<<"VAL "<<valido<<endl;
                cout<<"RE "<<regla_size<<" TAMANIO "<<tamanio[i]-1<<endl;*/
                if(regla_size<tamanio[i]-1){
                    valido = false;
                }
                //cout<<"VAL2 "<<valido<<endl;
            }
            if(valido){
                i = gramatica.size();
            }
        }
        if(valido){
            return true;
        }else{
            return false;
        }
}}
bool gen_gramatica(vector<string*>evaluar,vector<int>size_e,string a){
    char* gram_inicio[11]={"EXP","FACTOR","NUM","OP","FUN","EXP1","STRING","EXP2","COND","ARR","ARL"};
    vector<char**>gramatica;
    vector<int>tamanio;
    char* regla_gra0[2] = {"STRING","token_string"};
    gramatica.push_back(regla_gra0);
    tamanio.push_back(2);
    char* regla_gra1[2] = {"EXP","FACTOR"};
    gramatica.push_back(regla_gra1);
    tamanio.push_back(2);
    char* regla_gra2[4] = {"EXP","FACTOR","OP","EXP1"};
    gramatica.push_back(regla_gra2);
    tamanio.push_back(4);
    char* regla_gra3[5] = {"EXP","FUN","token_par_izq","EXP1","token_par_der"};
    gramatica.push_back(regla_gra3);
    tamanio.push_back(5);
    char* regla_gra4[6] = {"EXP","FACTOR","OP","token_par_izq","EXP1","token_par_der"};
    gramatica.push_back(regla_gra4);
    tamanio.push_back(6);
    char* regla_gra5[7] = {"EXP","FUN","token_par_izq","EXP1","token_par_der","OP","EXP1"};
    gramatica.push_back(regla_gra5);
    tamanio.push_back(7);
    char* regla_gra6[2] = {"FACTOR","id"};
    gramatica.push_back(regla_gra6);
    tamanio.push_back(2);
    char* regla_gra7[2] = {"FACTOR","NUM"};
    gramatica.push_back(regla_gra7);
    tamanio.push_back(2);
    char* regla_gra8[3] = {"FACTOR","token_menos","FACTOR"};
    gramatica.push_back(regla_gra8);
    tamanio.push_back(3);
    char* regla_gra9[4] = {"FACTOR","token_par_izq","EXP1","token_par_der"};
    gramatica.push_back(regla_gra9);
    tamanio.push_back(4);
    char* regla_gra10[2] = {"NUM","token_entero"};
    gramatica.push_back(regla_gra10);
    tamanio.push_back(2);
    char* regla_gra11[2] = {"NUM","token_flotante"};
    gramatica.push_back(regla_gra11);
    tamanio.push_back(2);
    char* regla_gra12[2] = {"NUM","pi"};
    gramatica.push_back(regla_gra12);
    tamanio.push_back(2);
    char* regla_gra13[2] = {"NUM","e"};
    gramatica.push_back(regla_gra13);
    tamanio.push_back(2);
    char* regla_gra14[2] = {"OP","token_mas"};
    gramatica.push_back(regla_gra14);
    tamanio.push_back(2);
    char* regla_gra15[2] = {"OP","token_menos"};
    gramatica.push_back(regla_gra15);
    tamanio.push_back(2);
    char* regla_gra16[2] = {"OP","token_mul"};
    gramatica.push_back(regla_gra16);
    tamanio.push_back(2);
    char* regla_gra17[2] = {"OP","token_div"};
    gramatica.push_back(regla_gra17);
    tamanio.push_back(2);
    char* regla_gra18[2] = {"OP","token_mod"};
    gramatica.push_back(regla_gra18);
    tamanio.push_back(2);
    char* regla_gra19[2] = {"FUN","cos"};
    gramatica.push_back(regla_gra19);
    tamanio.push_back(2);
    char* regla_gra20[2] = {"FUN","sen"};
    gramatica.push_back(regla_gra20);
    tamanio.push_back(2);
    char* regla_gra21[2] = {"FUN","fabs"};
    gramatica.push_back(regla_gra21);
    tamanio.push_back(2);
    char* regla_gra22[2] = {"FUN","sqrt"};
    gramatica.push_back(regla_gra22);
    tamanio.push_back(2);
    char* regla_gra23[4] = {"EXP1","token_par_izq","EXP","token_par_der"};
    gramatica.push_back(regla_gra23);
    tamanio.push_back(4);
    char* regla_gra24[2] = {"EXP1","EXP"};
    gramatica.push_back(regla_gra24);
    tamanio.push_back(2);
    char* regla_gra25[5] = {"log","log","token_par_izq","EXP2","token_par_der"};
    gramatica.push_back(regla_gra25);
    tamanio.push_back(5);
    char* regla_gra26[4] = {"ASG","id","token_equal","EXP2"};
    gramatica.push_back(regla_gra26);
    tamanio.push_back(4);
    char* regla_gra27[2] = {"EXP2","EXP"};
    gramatica.push_back(regla_gra27);
    tamanio.push_back(2);
    char* regla_gra28[2] = {"EXP2","STRING"};
    gramatica.push_back(regla_gra28);
    tamanio.push_back(2);
    char* regla_gra29[3] = {"retorno","retorno","EXP2"};
    gramatica.push_back(regla_gra29);
    tamanio.push_back(3);
    char* regla_gra30[4] = {"COND","EXP2","token_mayor","EXP2"};
    gramatica.push_back(regla_gra30);
    tamanio.push_back(4);
    char* regla_gra31[4] = {"COND","EXP2","token_menor","EXP2"};
    gramatica.push_back(regla_gra31);
    tamanio.push_back(4);
    char* regla_gra32[4] = {"COND","EXP2","token_mayor_igual","EXP2"};
    gramatica.push_back(regla_gra32);
    tamanio.push_back(4);
    char* regla_gra33[4] = {"COND","EXP2","token_menor_igual","EXP2"};
    gramatica.push_back(regla_gra33);
    tamanio.push_back(4);
    char* regla_gra34[4] = {"COND","EXP2","token_igual_num","EXP2"};
    gramatica.push_back(regla_gra34);
    tamanio.push_back(4);
    char* regla_gra35[4] = {"COND","EXP2","token_diff_num","EXP2"};
    gramatica.push_back(regla_gra35);
    tamanio.push_back(4);
    char* regla_gra36[4] = {"COND","EXP2","token_and","EXP2"};
    gramatica.push_back(regla_gra36);
    tamanio.push_back(4);
    char* regla_gra37[4] = {"COND","EXP2","token_or","EXP2"};
    gramatica.push_back(regla_gra37);
    tamanio.push_back(4);
    char* regla_gra38[4] = {"COND","EXP2","token_not","EXP2"};
    gramatica.push_back(regla_gra38);
    tamanio.push_back(4);
    char* regla_gra39[4] = {"while","while","COND","token_llave_izq"};
    gramatica.push_back(regla_gra39);
    tamanio.push_back(4);
    char* regla_gra40[4] = {"if","if","COND","token_llave_izq"};
    gramatica.push_back(regla_gra40);
    tamanio.push_back(4);
    char* regla_gra41[3] = {"else","else","token_llave_izq"};
    gramatica.push_back(regla_gra41);
    tamanio.push_back(3);
    char* regla_gra42[4] = {"elseif","elseif","COND","token_llave_izq"};
    gramatica.push_back(regla_gra42);
    tamanio.push_back(4);
    char* regla_gra43[4] = {"function","function","id","ARL"};
    gramatica.push_back(regla_gra43);
    tamanio.push_back(4);
    char* regla_gra44[4] = {"ASG","id","token_equal","ARR"};
    gramatica.push_back(regla_gra44);
    tamanio.push_back(4);
    char* regla_gra45[6] = {"for","for","id","in","ARR","token_llave_izq"};
    gramatica.push_back(regla_gra45);
    tamanio.push_back(6);
    char* regla_gra46[3] = {"FUNL","id","ARL"};
    gramatica.push_back(regla_gra46);
    tamanio.push_back(3);
    return validar_sintactico(gramatica,tamanio,evaluar,gram_inicio,size_e,a);
}
string imprimirerrorsintactico(string f, string c, string encontro, string* esperar, int e_size){
    string imprimir ="<"+f+","+c+"> ERROR SINTACTICO. Se encontro: "+encontro+", Se esperaba: ";
    for (int i = 0; i<e_size-1;i++){
        imprimir = imprimir + esperar[i] + ", ";
    }
    imprimir = imprimir + esperar[e_size-1];
    return imprimir;
}
string traducir(string a){
    char* simbolostokens [27][2] = {{"{","token_llave_izq"},
                                   {"}","token_llave_der"},
                                   {"#","token_com"},
                                   {"[","token_cor_izq"},
                                   {"]","token_cor_der"},
                                   {"(","token_par_izq"},
                                   {")","token_par_der"},
                                   {">","token_mayor"},
                                   {"<","token_menor"},
                                   {">=","token_mayor_igual"},
                                   {"<=","token_menor_igual"},
                                   {"==","token_igual_num"},
                                   {".","token_point"},
                                   {"!=","token_diff_num"},
                                   {"&&","token_and"},
                                   {"=","token_equal"},
                                   {"||","token_or"},
                                   {"!","token_not"},
                                   {"+","token_mas"},
                                   {"-","token_menos"},
                                   {"*","token_mul"},
                                   {"/","token_div"},
                                   {"%","token_mod"},
                                   {"^","token_pot"},
                                   {":","token_asignar"},
                                   {",","token_coma"},
                                   {"identificador","id"}};
    string traducir = "";
    for(int i = 0; i<27; i++){
        string str = simbolostokens[i][1];
        if(a.compare(str)==0){
            traducir = simbolostokens[i][0];
            i = 27;
        }

    }
    if(traducir.compare("")==0){
        traducir = a;
    }
    return traducir;
}
void lista_gramaticas(vector<string*>evaluar,vector<int>size_e){
    char* gram_inicio[11]={"EXP","FACTOR","NUM","OP","FUN","EXP1","STRING","EXP2","COND","ARR","ARL"};
    vector<char**>gramatica;
    vector<int>tamanio;
    char* regla_gra0[2] = {"STRING","token_string"};
    gramatica.push_back(regla_gra0);
    tamanio.push_back(2);
    char* regla_gra1[2] = {"EXP","FACTOR"};
    gramatica.push_back(regla_gra1);
    tamanio.push_back(2);
    char* regla_gra2[4] = {"EXP","FACTOR","OP","EXP1"};
    gramatica.push_back(regla_gra2);
    tamanio.push_back(4);
    char* regla_gra3[5] = {"EXP","FUN","token_par_izq","EXP1","token_par_der"};
    gramatica.push_back(regla_gra3);
    tamanio.push_back(5);
    char* regla_gra4[6] = {"EXP","FACTOR","OP","token_par_izq","EXP1","token_par_der"};
    gramatica.push_back(regla_gra4);
    tamanio.push_back(6);
    char* regla_gra5[7] = {"EXP","FUN","token_par_izq","EXP1","token_par_der","OP","EXP1"};
    gramatica.push_back(regla_gra5);
    tamanio.push_back(7);
    char* regla_gra6[2] = {"FACTOR","id"};
    gramatica.push_back(regla_gra6);
    tamanio.push_back(2);
    char* regla_gra7[2] = {"FACTOR","NUM"};
    gramatica.push_back(regla_gra7);
    tamanio.push_back(2);
    char* regla_gra8[3] = {"FACTOR","token_menos","FACTOR"};
    gramatica.push_back(regla_gra8);
    tamanio.push_back(3);
    char* regla_gra9[4] = {"FACTOR","token_par_izq","EXP1","token_par_der"};
    gramatica.push_back(regla_gra9);
    tamanio.push_back(4);
    char* regla_gra10[2] = {"NUM","token_entero"};
    gramatica.push_back(regla_gra10);
    tamanio.push_back(2);
    char* regla_gra11[2] = {"NUM","token_flotante"};
    gramatica.push_back(regla_gra11);
    tamanio.push_back(2);
    char* regla_gra12[2] = {"NUM","pi"};
    gramatica.push_back(regla_gra12);
    tamanio.push_back(2);
    char* regla_gra13[2] = {"NUM","e"};
    gramatica.push_back(regla_gra13);
    tamanio.push_back(2);
    char* regla_gra14[2] = {"OP","token_mas"};
    gramatica.push_back(regla_gra14);
    tamanio.push_back(2);
    char* regla_gra15[2] = {"OP","token_menos"};
    gramatica.push_back(regla_gra15);
    tamanio.push_back(2);
    char* regla_gra16[2] = {"OP","token_mul"};
    gramatica.push_back(regla_gra16);
    tamanio.push_back(2);
    char* regla_gra17[2] = {"OP","token_div"};
    gramatica.push_back(regla_gra17);
    tamanio.push_back(2);
    char* regla_gra18[2] = {"OP","token_mod"};
    gramatica.push_back(regla_gra18);
    tamanio.push_back(2);
    char* regla_gra19[2] = {"FUN","cos"};
    gramatica.push_back(regla_gra19);
    tamanio.push_back(2);
    char* regla_gra20[2] = {"FUN","sen"};
    gramatica.push_back(regla_gra20);
    tamanio.push_back(2);
    char* regla_gra21[2] = {"FUN","fabs"};
    gramatica.push_back(regla_gra21);
    tamanio.push_back(2);
    char* regla_gra22[2] = {"FUN","sqrt"};
    gramatica.push_back(regla_gra22);
    tamanio.push_back(2);
    char* regla_gra23[4] = {"EXP1","token_par_izq","EXP","token_par_der"};
    gramatica.push_back(regla_gra23);
    tamanio.push_back(4);
    char* regla_gra24[2] = {"EXP1","EXP"};
    gramatica.push_back(regla_gra24);
    tamanio.push_back(2);
    char* regla_gra25[5] = {"log","log","token_par_izq","EXP2","token_par_der"};
    gramatica.push_back(regla_gra25);
    tamanio.push_back(5);
    char* regla_gra26[4] = {"ASG","id","token_equal","ARR"};
    gramatica.push_back(regla_gra26);
    tamanio.push_back(4);
    char* regla_gra27[2] = {"EXP2","EXP"};
    gramatica.push_back(regla_gra27);
    tamanio.push_back(2);
    char* regla_gra28[2] = {"EXP2","STRING"};
    gramatica.push_back(regla_gra28);
    tamanio.push_back(2);
    char* regla_gra29[3] = {"retorno","retorno","EXP2"};
    gramatica.push_back(regla_gra29);
    tamanio.push_back(3);
    char* regla_gra30[4] = {"COND","EXP2","token_mayor","EXP2"};
    gramatica.push_back(regla_gra30);
    tamanio.push_back(4);
    char* regla_gra31[4] = {"COND","EXP2","token_menor","EXP2"};
    gramatica.push_back(regla_gra31);
    tamanio.push_back(4);
    char* regla_gra32[4] = {"COND","EXP2","token_mayor_igual","EXP2"};
    gramatica.push_back(regla_gra32);
    tamanio.push_back(4);
    char* regla_gra33[4] = {"COND","EXP2","token_menor_igual","EXP2"};
    gramatica.push_back(regla_gra33);
    tamanio.push_back(4);
    char* regla_gra34[4] = {"COND","EXP2","token_igual_num","EXP2"};
    gramatica.push_back(regla_gra34);
    tamanio.push_back(4);
    char* regla_gra35[4] = {"COND","EXP2","token_diff_num","EXP2"};
    gramatica.push_back(regla_gra35);
    tamanio.push_back(4);
    char* regla_gra36[4] = {"COND","EXP2","token_and","EXP2"};
    gramatica.push_back(regla_gra36);
    tamanio.push_back(4);
    char* regla_gra37[4] = {"COND","EXP2","token_or","EXP2"};
    gramatica.push_back(regla_gra37);
    tamanio.push_back(4);
    char* regla_gra38[4] = {"COND","EXP2","token_not","EXP2"};
    gramatica.push_back(regla_gra38);
    tamanio.push_back(4);
    char* regla_gra39[4] = {"while","while","COND","token_llave_izq"};
    gramatica.push_back(regla_gra39);
    tamanio.push_back(4);
    char* regla_gra40[4] = {"if","if","COND","token_llave_izq"};
    gramatica.push_back(regla_gra40);
    tamanio.push_back(4);
    char* regla_gra41[3] = {"else","else","token_llave_izq"};
    gramatica.push_back(regla_gra41);
    tamanio.push_back(3);
    char* regla_gra42[4] = {"elseif","elseif","COND","token_llave_izq"};
    gramatica.push_back(regla_gra42);
    tamanio.push_back(4);
    char* regla_gra43[4] = {"function","function","id","ARL"};
    gramatica.push_back(regla_gra43);
    tamanio.push_back(4);
    char* regla_gra44[4] = {"ASG","id","token_equal","EXP2"};
    gramatica.push_back(regla_gra44);
    tamanio.push_back(4);
    char* regla_gra45[6] = {"for","for","id","in","ARR","token_llave_izq"};
    gramatica.push_back(regla_gra45);
    tamanio.push_back(6);
    char* regla_gra46[3] = {"FUNL","id","ARL"};
    gramatica.push_back(regla_gra46);
    tamanio.push_back(3);

    //PALABRAS INICIO
    char* palabrastokens [27] = {"cos","end","e","else","fabs","false","for",
                          "function","importar","in","if","log","math",
                          "pow","pi","retorno","sqrt","sin","true",
                          "while","elseif","id","token_llave_izq","token_llave_der",
                          "token_par_izq","token_par_der","token_equal"};
    //MIRAR EL INICIO

    char* inicio[12] = {"end","else","for","function","importar","if","log","retorno","while","ASG","elseif","FUNL"};
    bool is_inicio = false;
    for(int i = 0; i<12;i++){
        string inicioword (inicio[i]);
        if (inicioword.compare(evaluar[0][0]) == 0){
                is_inicio = true;
                i = 12;
        }
    }
    string initial = "";
    if(is_inicio){
        initial = evaluar[0][0];
    }else{
        if(evaluar[0][0].compare("id")==0){
                     if (evaluar[1][0].compare("token_equal")==0){
                            initial = "ASG";
                     }else if (evaluar[1][0].compare("token_equal")==0){
                            initial = "FUNL";
                     }
        }
    }
    if(initial.compare("")==0){
        bool was_inicio = false;
        string lower = "";
        if(evaluar[0][0].compare("id")==0){
            string str1 = evaluar[0][1];
            char* s = (char*) str1.c_str();
            char* s1 = new char[str1.size()];
            for(int i = 0; i<str1.size();i++){
                char b = s[i];
                if (b>=65 && b<=90){
                    b = b+32;
                }
                s1[i] = b;


            }
            lower = s1;
            for(int i = 0; i<12;i++){
                string inicioword (inicio[i]);
                if (inicioword.compare(lower) == 0){
                    was_inicio = true;
                    i = 12;
                }
            }
        }
        if(was_inicio){
            string* esperar = new string[1];
            esperar[0] = lower;
            cout<<imprimirerrorsintactico(evaluar[0][size_e[0]-2],evaluar[0][size_e[0]-1],traducir(evaluar[0][1]),esperar,1)<<endl;
        }else{
        string* esperar = new string[12];
        for(int i = 0; i<12;i++){
            string str = inicio[i];
            if(str.compare("ASG")==0){
                str = "identificador";
            }else if(str.compare("FUNL")==0){
                str = "Nombre funcion";
            }
            esperar[i] = str;
        }
        cout<<imprimirerrorsintactico(evaluar[0][size_e[0]-2],evaluar[0][size_e[0]-1],traducir(evaluar[0][0]),esperar,12)<<endl;
        }
        exit(0);
    }else{
        int pos = 0;
        for(int i = 0; i<gramatica.size();i++){
            string str = gramatica[i][0] ;
            if(str.compare(initial)==0){
                pos = i;
                i = gramatica.size();
            }
        }
        int k = 1;
        vector<string*>evaluar2;
        vector<int>size_e2;
        string f;
        string c;
        for (int i = 0; i<evaluar.size();i++){
                if (k<tamanio[pos]){
                    bool token =false;
                    for(int j = 0; j<27;j++){
                        if(palabrastokens[j]==gramatica[pos][k]){
                        token = true;
                        j = 27;
                    }
                    }
                    if(token){
                        string str1 = gramatica[pos][k] ;
                        if (evaluar[i][0].compare(str1)!=0){
                            if(evaluar2.size()!=0){
                                evaluar2.push_back(evaluar[i]);
                                size_e2.push_back(size_e[i]);
                            }else{
                            string* esperar = new string[1];
                            esperar[0]=traducir(str1);
                            cout<<imprimirerrorsintactico(evaluar[i][size_e[i]-2],evaluar[i][size_e[i]-1],traducir(evaluar[i][0]),esperar,1)<<endl;
                            exit(0);
                            }
                        }else{
                            if (evaluar2.size()!=0){
                                string str2 = gramatica[pos][k-1];
                                if(gen_gramatica(evaluar2,size_e2,str2)){
                                evaluar2.clear();
                                size_e2.clear();
                                }else{
                                    string encontro = "";
                                    for(int i = 0; i<evaluar2.size();i++){
                                        string a = traducir(evaluar2[i][0]);
                                        if((a.compare("token_entero")==0)||(a.compare("token_string")==0)
                                           ||(a.compare("token_flotante")==0)){
                                                a = evaluar2[i][1];
                                           }
                                        encontro = encontro+a;
                                    }
                                    string* encontrar = new string[1];
                                    if(str2.compare("EXP2")==0){
                                        encontrar[0]="String, Expresion matematica";
                                    }else if(str2.compare("ARR")==0){
                                        encontrar[0]="[Expresion(,Expresion)*]";
                                    }else if(str2.compare("ARL")==0){
                                        encontrar[0]="(Expresion(,Expresion)*)";
                                    }else if(str2.compare("COND")==0){
                                        encontrar[0]="Expresion Condicional";
                                    }
                                    cout<<imprimirerrorsintactico(f,c,encontro,encontrar,1)<<endl;
                                    exit(0);
                                }

                            }
                            k++;
                        }

                    }else{
                        evaluar2.push_back(evaluar[i]);
                        size_e2.push_back(size_e[i]);
                        f = evaluar[i][size_e[i]-2];
                        c = evaluar[i][size_e[i]-1];
                        k++;
                    }

                }
                else if (evaluar2.size()!=0){
                                evaluar2.push_back(evaluar[i]);
                                size_e2.push_back(size_e[i]);


                }
        }
        if (evaluar2.size()!=0){
                                string str2 = gramatica[pos][k-1];
                                if(gen_gramatica(evaluar2,size_e2,str2)){
                                evaluar2.clear();
                                size_e2.clear();
                                }else{
                                    string encontro = "";
                                    for(int i = 0; i<evaluar2.size();i++){
                                        string a = traducir(evaluar2[i][0]);
                                        if((a.compare("token_entero")==0)||(a.compare("token_string")==0)
                                           ||(a.compare("token_flotante")==0)){
                                                a = evaluar2[i][1];
                                           }
                                        encontro = encontro+a;
                                    }
                                    string* encontrar = new string[1];
                                    if(str2.compare("EXP2")==0){
                                        encontrar[0]="String, Expresion matematica";
                                    }else if(str2.compare("ARR")==0){
                                        encontrar[0]="[Expresion(,Expresion)*]";
                                    }else if(str2.compare("ARL")==0){
                                        encontrar[0]="(Expresion(,Expresion)*)";
                                    }else if(str2.compare("COND")==0){
                                        encontrar[0]="Expresion Condicional";
                                    }
                                    cout<<imprimirerrorsintactico(f,c,encontro,encontrar,1)<<endl;
                                    exit(0);
                                }

                            }

        }




}

int main(){
    char* inicio[12] = {"end","else","for","function","importar","if","log","retorno","while","ASG","elseif","FUNL"};
    cout<<"---------- ANALISIS LEXICO ----------"<<endl;
    int fila = 0;
    fstream archivo("Evaluar.txt");
    ofstream archivo2 ("Evaluado.txt");
    string linea;
    if(!archivo.is_open()){
        archivo.open("Evaluar.txt",ios::in);
    }
    vector<int>columnas;
    while(getline(archivo,linea)){
          int l_columnas = 0;
          int columna = 0;
          char * char_linea = new char[linea.length()+1];
          strcpy(char_linea,linea.c_str());
          int a = -1;
          string retorno ="";
          string antretorno = "";
          string l = "";
          string entflo = "";
          int efila = 0;
          int ecolumna = 0;
          int effila = 0;
          int efcolumna = 0;
          bool entra = false;
          bool error = false;
          bool ent = false;
          bool floti = false;
          string l1 ="";
          string l2 = "";
          for(int i = 0; i< strlen(char_linea);i++){
            if((int)char_linea[i]!=32){
                 ent = true;
                 l1 = l;
                 l = l+char_linea[i];
                 retorno = validar(l);
                 if(retorno.compare("")==0){
                        if(!error){
                                efila = fila;
                                ecolumna = columna;
                                error = true;
                        }
                        if(antretorno.compare("")!=0){
                                if (antretorno.compare("Flotientero")==0){
                                    if(!floti){
                                        escribir(imprimir(entflo,l2,effila,efcolumna)+"\n",archivo2);
                                        cout<<imprimir(entflo,l2,effila,efcolumna)<<endl;
                                        l_columnas++;
                                    }
                                    escribir(imprimirerror(efila,ecolumna)+"\n",archivo2);
                                    cout<<imprimirerror(efila,ecolumna)<<endl;
                                    system("pause");
                                    archivo2.close();
                                    archivo.close();
                                    exit(0);
                                }else{
                                escribir(imprimir(antretorno,l1,fila,columna)+"\n",archivo2);
                                cout<<imprimir(antretorno,l1,fila,columna)<<endl;
                                l_columnas++;
                                l = "";
                                retorno = "";
                                antretorno = "";
                                entra = false;
                                error = false;
                                floti = true;
                                columna++;
                                i--;
                                }

                        }
                }else{
                    if ((antretorno.compare("token_entero")==0 || antretorno.compare("token_flotante")==0) && retorno.compare("Flotientero")==0){
                        entflo = antretorno;
                        effila = fila;
                        efcolumna = columna;
                        efila = effila;
                        ecolumna = efcolumna+1;
                        l2 = l1;
                        floti = false;
                    }
                    entra  = true;
                    antretorno = retorno;
                    error = false;
                }
            }else{
                    bool is_string = 0;
                    if(l[0]=='"'){
                        is_string =1;
                    }

            if(!is_string){
                 if(antretorno.compare("")!=0){
                    if (antretorno.compare("Flotientero")==0){
                                    if(!floti){
                                        escribir(imprimir(entflo,l2,effila,efcolumna)+"\n",archivo2);
                                        cout<<imprimir(entflo,l2,effila,efcolumna)<<endl;
                                        l_columnas++;

                                    }
                                    escribir(imprimirerror(efila,ecolumna)+"\n",archivo2);
                                    cout<<imprimirerror(efila,ecolumna)<<endl;

                                    system("pause");
                                    archivo2.close();
                                    archivo.close();
                                    exit(0);
                    }else{
                    escribir(imprimir(antretorno,l,fila,columna)+"\n",archivo2);
                    cout<<imprimir(antretorno,l,fila,columna)<<endl;
                    l_columnas++;
                    floti = true;
                    columna++;
                    entra = 0;
                    }
                 l = "";
                 antretorno = "";
                 retorno = "";
                 columna++;
                }else{
                    if(ent){
                        escribir(imprimirerror(efila,ecolumna)+"\n",archivo2);
            cout<<imprimirerror(efila,ecolumna)<<endl;
            system("pause");
            archivo2.close();
            archivo.close();
            exit(0);
                    }
                  l= "";
                 columna++;

          }


            }else{
                l = l+char_linea[i];
            }
            }
          }
          if (linea.compare("")!=0){
          if(antretorno.compare("")!=0){
            if (antretorno.compare("Flotientero")==0){
                                    if(!floti){
                                        escribir(imprimir(entflo,l2,effila,efcolumna)+"\n",archivo2);
                                        cout<<imprimir(entflo,l2,effila,efcolumna)<<endl;
                                        l_columnas++;
                                    }
                                    escribir(imprimirerror(efila,ecolumna)+"\n",archivo2);
                                    cout<<imprimirerror(efila,ecolumna)<<endl;
                                    archivo2.close();
                                    archivo.close();
                                    system("pause");
                                    exit(0);
                    }else{
            escribir(imprimir(antretorno,l,fila,columna)+"\n",archivo2);
            cout<<imprimir(antretorno,l,fila,columna)<<endl;
            l_columnas++;
            floti = true;
                    }
          }else{
            escribir(imprimirerror(efila,ecolumna)+"\n",archivo2);
            cout<<imprimirerror(efila,ecolumna)<<endl;
            archivo2.close();
            archivo.close();
            system("pause");
            exit(0);
          }
          }
          fila++;
          columnas.push_back(l_columnas);
    }
    archivo2.close();
    archivo.close();

    cout<<"    ANALISIS LEXICO SATISFACTORIO    "<<endl;
    cout<<"-------------------------------------"<<endl;
    system("pause");
    cout<<endl;
    cout<<"******** ANALISIS SINTACTICO ********"<<endl;
    fstream archivo3("Evaluado.txt");
    if(!archivo3.is_open()){
        archivo3.open("Evaluado.txt",ios::in);
    }
    vector<string*>l_vector;
    vector<int>size_vector;
    while(getline(archivo3,linea)){
        int coma = 0;
        //cout<<linea<<endl;
        char * char_linea = new char[linea.length()+1];
        strcpy(char_linea,linea.c_str());
        for (int i =0; i< strlen(char_linea);i++){
            if (char_linea[i]== ','){
                coma = coma+1;
            }
        }
        string* slinea = new string[coma+1];
        for (int i =0; i<coma+1;i++){
            size_t found;
            found = linea.find(",");
            if (i==0){
               slinea[i] = linea.substr(1,found-1);
            }else if(i==coma){
               slinea[i] = linea.substr(0,linea.size()-1);
            }else{
                slinea[i] = linea.substr(0,found);

            }
            linea = linea.substr(found+1,linea.size());
        }
        l_vector.push_back(slinea);
        size_vector.push_back(coma+1);
    }

    int num_c = 0;
    int num_c1 = 0;
    vector<string*>vector_a;
    vector<int>size_vector_a;
    bool block_wh = false;
    int pos_wh = -1;
    vector<string>vector_cola;
    bool retorno = false;
    bool block_for = false;
    int cola = 0;
    for(int i = 0; i<l_vector.size();i++){
        vector_a.push_back(l_vector[i]);
        size_vector_a.push_back(size_vector[i]);
        if(vector_a.size() == columnas[num_c]){
            num_c++;
            if(((vector_a[0][0]).compare("while")==0)||((vector_a[0][0]).compare("for")==0)
            ||((vector_a[0][0]).compare("if")==0)||((vector_a[0][0]).compare("else")==0)||
               ((vector_a[0][0]).compare("elseif")==0)){
                vector_cola.push_back("token_llave_der");
            }else if((vector_a[0][0]).compare("function")==0){
                retorno = true;
                vector_cola.push_back("end");
            }
            bool valido_gram = true;
            if(vector_a.size()==1){
                if (vector_cola.size()!=0){
                        if(vector_cola[cola]==vector_a[0][0]){
                            cola++;
                        }else{
                            string* esperar = new string[1];
                            esperar[0] = traducir(vector_cola[cola]);
                            cout<<imprimirerrorsintactico(vector_a[0][size_vector_a[0]-2],vector_a[0][size_vector_a[0]-1],traducir(vector_a[0][0]),esperar,1)<<endl;
                            exit(0);
                        }
                }else{
                    string* esperar = new string[12];
                    for(int i = 0; i<12;i++){
                        string str = inicio[i];
                        if(str.compare("ASG")==0){
                            str = "identificador";
                        }else if(str.compare("FUNL")==0){
                            str = "Nombre funcion";
                        }
                        esperar[i] = str;
                    }
                    cout<<imprimirerrorsintactico(vector_a[0][size_vector_a[0]-2],vector_a[0][size_vector_a[0]-1],traducir(vector_a[0][0]),esperar,12)<<endl;
                    exit(0);
                }
            }else{
                if((vector_a[0][0]).compare("retorno")==0){
                    if (retorno){
                        valido_gram = gen_gramatica(vector_a,size_vector_a,"");
                    }
                    else{
                        valido_gram = false;
                    }
                }else{
                    valido_gram = gen_gramatica(vector_a,size_vector_a,"");
                }
            }
            if(!valido_gram){
                lista_gramaticas(vector_a,size_vector_a);
                cout<<"ERROR"<<endl;
            }
            vector_a.clear();
        }
    }
    cout<<"  ANALISIS SINTACTICO SATISFACTORIO  "<<endl;
    cout<<"*************************************"<<endl;
   return 0;
}
