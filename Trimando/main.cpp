#include <windows.h>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
ostream& escribir(string a, ostream& os){
    os<<a;
    return os;
}
ostream& escribir2(string a, ostream& os){
    os<<a;
    os<<'\0';
    return os;
}
string leer (istream& is){
    string a;
    is>> a;
    return a;
}
bool validaregistro(char* nombre,char* correo,char* contrasena,char* telefono,char* usuario){
 bool b_nombre = false;
 bool b_correo = false;
 bool b_contrasena = false;
 bool b_telefono = false;
 bool b_usuario = true;
 bool b_final = false;

 for(int i=0;i<strlen(correo);i++){
        if((correo[i]>='0'&&correo[i]<='9')||(correo[i]>='A'&&correo[i]<='Z')||(correo[i]>='a'&&correo[i]<='z')
                    ||correo[i]=='@'||correo[i]=='.'){
            b_correo = true;
        }
        else{
            b_correo = false;
            i = strlen(correo);
        }
    }
if(b_correo){
    int arr=0;
    int pnt=0;
    for(int i= 0; i<strlen(correo);i++){
        if(correo[i]=='@'){
            arr++;
        }else if(correo[i]=='.'){
            pnt++;
        }
    }
if(arr!=1 ||pnt!=1){
    b_correo = false;
}
if(b_correo){
    for(int i=0;i< strlen(correo);i++){
        if(correo[i]=='@'){
           for(int j=i;j<strlen(correo);j++){
                if(correo[j]=='.'){
                    b_correo=true;
                    j = strlen(correo);
                    i = strlen(correo);
                }else{
                    b_correo = false;
                }
           }
        }
    }
    }
}

    for(int i=0;i<strlen(usuario);i++){
        if((usuario[i]>='0'&&usuario[i]<='9')||(usuario[i]>='A'&&usuario[i]<='Z')||(usuario[i]>='a'&&usuario[i]<='z')){
            b_usuario = true;
        }
        else{
            b_usuario = false;
            i = strlen(nombre);
        }
    }
    if(b_usuario){
    ifstream ifsU("UvsC.txt");
    string user_pasword;
    string user_p;
    string snombre;
    char* user_pas= new char[100];
    bool valido = false;
    while(!valido){
      user_pasword = leer(ifsU);
      user_pas = (char*) user_pasword.c_str();
      for(int i =0; i< strlen(user_pas);i++){
        if(user_pas[i]!='&'){
            user_p = user_p+""+user_pas[i];
        }else{
            i = strlen(user_pas);
        }
      }
     if(user_pasword.length()==0){
        valido = true;
    }else{
        if(strcmp(usuario, user_p.c_str())==0){
            valido = true;
            b_usuario = false;
        }
    }
  }
}
    for(int i=0;i<strlen(nombre);i++){
        if((nombre[i]>='0'&&nombre[i]<='9')||(nombre[i]>='A'&&nombre[i]<='Z')||(nombre[i]>='a'&&nombre[i]<='z')
           ||nombre[i]==' '){
            b_nombre = true;
        }
        else{
            b_nombre = false;
            i = strlen(nombre);
        }
    }

    for(int i=0;i<strlen(contrasena);i++){
        if((contrasena[i]>='0'&&contrasena[i]<='9')||(contrasena[i]>='A'&&contrasena[i]<='Z')||
           (contrasena[i]>='a'&&contrasena[i]<='z')){
            b_contrasena = true;
        }
        else{
            b_contrasena = false;
            i = strlen(contrasena);
        }
    }
    for(int i=0;i<strlen(telefono);i++){
        if(telefono[i]>='0'&&telefono[i]<='9'){
            b_telefono = true;
        }
        else{
            b_telefono = false;
            i = strlen(telefono);
        }
    }
    if(b_telefono){
        if(telefono[0]=='0'){
            b_telefono = false;
        }
    }
    if(b_nombre && b_correo&&b_contrasena&&b_telefono&&b_usuario){
        b_final=true;
    }
    else{
       b_final=false;
        if(!b_nombre){
            cout<<"ERROR EN NOMBRE"<<endl;
        }else if(!b_correo){
        cout<<"ERROR EN CORREO"<<endl;
        }else if(!b_contrasena){
        cout<<"ERRROR EN CONTRASENA"<<endl;
        }else if(!b_telefono){
        cout<<"ERRROR EN TELEFONO"<<endl;
        }else if(!b_usuario){
        cout<<"EL USUARIO YA EXISTE"<<endl;
        }
    }
return b_final;
}
bool validarlogin (char* usuario, char* contrasena, int n, int m){
ifstream ifs("UvsC.txt");
string en_user_pasword = string(usuario)+"&"+string(contrasena)+"&";
char* e_user_pasword = (char*) en_user_pasword.c_str();
string user_pasword ;
char* user_pas= new char[100];
bool valido = false;
bool valus = false;
bool valido2 = true;
while (!valido){
user_pasword = leer(ifs);
user_pas = (char*) user_pasword.c_str();
if(user_pasword.length()==0){
    valido2 = false;
    valido = true;
}else{
    for(int i = 0; i<user_pasword.length() && i<en_user_pasword.length();i++){
        if(e_user_pasword[i]==user_pas[i]){
            valus = true;
        }else{
          valus = false;
          i = user_pasword.length();
        }
    }
}
if(valus){
    valido = true;
}}
if(!valido2){
    valido = false;
}
ifs.close();
return valido;
}
string login (){
 string user;
 string pasword;
 bool entrar = false;
 while(!entrar){
cout<<"********************************************************************************"<<endl;
cout<<"    ######## ########  #### ##    ##    ###    ##    ## ########   #######"<<endl;
cout<<"       ##    ##     ##  ##  ###   ##   ## ##   ###   ## ##     ## ##     ##"<<endl;
cout<<"       ##    ##     ##  ##  ####  ##  ##   ##  ####  ## ##     ## ##     ##"<<endl;
cout<<"       ##    ########   ##  ## ## ## ##     ## ## ## ## ##     ## ##     ##"<<endl;
cout<<"       ##    ##   ##    ##  ##  #### ######### ##  #### ##     ## ##     ##"<<endl;
cout<<"       ##    ##    ##   ##  ##   ### ##     ## ##   ### ##     ## ##     ##"<<endl;
cout<<"       ##    ##     ## #### ##    ## ##     ## ##    ## ########   #######"<<endl;
cout<<endl;
    cout<<"USUARIO: ";
    cin>>user;
    cout<<"CONTRASENA: ";
    cin>>pasword;
    cin.ignore();
cout<<endl;
cout<<"********************************************************************************"<<endl;
    int n = user.length();
    int m = pasword.length();
    const char *cuser = user.c_str();
    const char *cpasword = pasword.c_str();
    entrar = validarlogin((char*)cuser, (char*)cpasword,n,m);
    if(!entrar){
        cout<<"Usuario o contrasena no validos"<<endl;
    }
    system("pause");
    system("cls");
    }
    return user;
}
char* fecha (){
   time_t now = time(0);
   char* dt = ctime(&now);
   return dt;
}
string noespacios(char* a){
  string n = string(a);
  for(int i = 0; i< n.length();i++){
    if(a[i]==' ' || a[i]=='\n'){
        a[i]='°';
    }
  }
  return string(a);
}
char* espacios(string b){
  const char *c = b.c_str();
  char* a = (char*) c;
  for(int i = 0; i< b.length();i++){
    if(a[i]=='°'){
       a[i]=' ';
    }
  }
  return a;
}
void configuracion(string userkey){
bool valido = false;
char p;
while(!valido){
system("cls");
p = '0';
char* nombre = new char[100];
char* correo = new char[360];
char* contrasena = new char [100];
char* telefono = new char [100];
char* descripcion = new char [320];
ifstream ifsUsuario ((userkey+"USER.txt").c_str());
string snombre = string(espacios(leer(ifsUsuario)));
string scontrasena= string(leer(ifsUsuario));
string scorreo = string(leer(ifsUsuario));
string stelefono= string(leer(ifsUsuario));
string sdescripcion = string(espacios(leer(ifsUsuario)));
cout<<"********************************************************************************"<<endl;
cout<<endl;
cout<<"@"+userkey<<endl;
cout<<"NOMBRE COMPLETO: "+snombre<<endl;
cout<<endl;
cout<<"CORREO ELECTRONICO: "+scorreo<<endl;
cout<<endl;
cout<<"CONTRASENA: "+scontrasena<<endl;
cout<<endl;
cout<<"TELEFONO: "+stelefono<<endl;
cout<<endl;
cout<<"DESCRIPCION: "<<endl;
cout<<sdescripcion<<endl;
cout<<endl;
cout<<"                             ¿QUE DESEA MODIFICAR?"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o        N => Nombre Completo    C => Correo        o"<<endl;
cout<<"             o        P => Contrasena         T => Telefono      o"<<endl;
cout<<"             o        D => Descripcion        V => Volver        o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='n'&&p!='N'&&p!='c'&&p!='C'&&p!='p'&&p!='P'&&p!='t'&&p!='T'&&p!='d'&&p!='D'&&p!='v'&&p!='V'){
    cin>>p;
    cin.ignore();
}
nombre = (char*)(snombre.c_str());
correo = (char*)(scorreo.c_str());
if(p=='n'||p=='N'){
    bool valido1 = false;
    while(!valido1){
    cout<<"NOMBRE COMPLETO: ";
    cin.getline(nombre, 100, '\n');
    snombre = string(nombre);
    valido1 = validaregistro((char*)(snombre.c_str()),(char*)(scorreo.c_str()),(char*)(scontrasena.c_str()),(char*)(stelefono.c_str()),(char*)("W"));
}}else if(p=='c'||p=='C'){
    bool valido1 = false;
    while(!valido1){
    cout<<"CORREO ELECTRONICO: ";
    cin.getline(correo, 360, '\n');
    scorreo = string(correo);
    valido1 = validaregistro((char*)(snombre.c_str()),(char*)(scorreo.c_str()),(char*)(scontrasena.c_str()),(char*)(stelefono.c_str()),(char*)("W"));
}}else if(p=='p'||p=='P'){
    bool valido1 = false;
    while(!valido1){
    cout<<"CONTRASENA: ";
    cin.getline(contrasena, 100, '\n');
    scontrasena = string(contrasena);
    valido1 = validaregistro((char*)(snombre.c_str()),(char*)(scorreo.c_str()),(char*)(scontrasena.c_str()),(char*)(stelefono.c_str()),(char*)("W"));
}}else if(p=='T'||p=='t'){
    bool valido1 = false;
    while(!valido1){
    cout<<"TELEFONO: ";
    cin.getline(telefono, 100, '\n');
    stelefono = string(telefono);
    valido1 = validaregistro((char*)(snombre.c_str()),(char*)(scorreo.c_str()),(char*)(scontrasena.c_str()),(char*)(stelefono.c_str()),(char*)("W"));
}}else if(p=='d'||p=='D'){
    cout<<"DESCRIPCION: "<<endl;
    cin.getline(descripcion, 320, '\n');
    sdescripcion = string(noespacios(descripcion));
}else{
valido = true;
}
string usuario = noespacios((char*)(snombre.c_str()))+ " "+scontrasena+" "+scorreo+" "+stelefono+" "+noespacios((char*)(sdescripcion.c_str()))+" "+userkey+" ";
ofstream ofsUuario((userkey+"USER.txt").c_str());
escribir(usuario, ofsUuario);
}
}
string leeretiquetas(string userkey){
string usereti = userkey+ "ETIQUETAS.txt";
ifstream ifsEti (usereti.c_str());
string uetiqueta = leer(ifsEti);
string uspar;
bool salir = false;
while (!salir){
    uspar=leer(ifsEti);
    if(uspar.length()==0){
        salir = true;
    }else{
    uetiqueta = uetiqueta+" "+uspar;
    }
}
return espacios(uetiqueta);
}
void etiqueta(char* trino,string userkey){
string etiquetado;
string user_p;
bool eti = false;
    for(int i = 0; i< strlen(trino);i++){
        if(trino[i]=='@'){
            for(int j = i+1; j<strlen(trino);j++){
                if(trino[j]!=-80){
                    etiquetado = etiquetado +""+ trino[j];
                    eti = true;
                }else{
                    j = strlen(trino);
                }
            }
        }else if(eti){
    eti = false;
    ifstream ifsU ("UvsC.txt");
    string user_pasword;
    char* user_pas= new char[100];
    bool valido = false;
    while(!valido){
      user_pasword = leer(ifsU);
      user_pas = (char*) user_pasword.c_str();
      user_p ="";
      for(int i =0; i< strlen(user_pas);i++){
        if(user_pas[i]!='&'){
            user_p = user_p+""+user_pas[i];
        }else{
            i = strlen(user_pas);
        }
      }
     if(user_pasword.length()==0){
        valido = true;
    }else{
        if(strcmp(etiquetado.c_str(), user_p.c_str())==0){
            valido = true;
            eti = true;
            i = strlen(trino);
        }else{

        }
    }
  }
        }

    }
if(eti){
string usereti = user_p+ "ETIQUETAS.txt";
string uetiqueta = leeretiquetas(etiquetado);
ofstream ofsEti(usereti.c_str());
uetiqueta = noespacios(fecha())+"&"+string(userkey)+"&"+noespacios(trino)+"&"+" "+noespacios((char*)uetiqueta.c_str());
escribir(uetiqueta,ofsEti);
}
}
string leermensajes (string usmen){
 ifstream ifsMen(usmen.c_str());
 string mensaje = leer(ifsMen);
 char* men = new char [mensaje.length()];
 men = espacios(mensaje);
 return string(men);
}
void postear(string userkey){
string userpost = userkey+ "POST"+".txt";
ifstream ifsPost (userpost.c_str());
string postanteriores = leer(ifsPost);
ofstream ofsPost(userpost.c_str());
char post;
bool valido = false;
while (!valido){
    post ='0';
    char* trino = new char[140];
    cout<<"********************************************************************************"<<endl;
    cout<<endl;
    cout<<"   ------- POST (140) ------------------------------------------------------"<<endl;
    cin.getline(trino, 140, '\n');
    cout<<"   -------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"                                 ¿QUE DESEA HACER?"<<endl;
    cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
    cout<<"             o        P => Publicar             R => Repetir     o"<<endl;
    cout<<"             o                      V => Volver                  o"<<endl;
    cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
    while(post!='p' && post!='P'&&post!='R'&&post!='r'&&post!='v'&&post!='V'){
    cin>>post;
    cin.ignore();
    }
    if (post=='p' || post == 'P'){
    valido = true;
    string strino = noespacios(trino);
    string sfecha = (noespacios(fecha()));
    escribir(sfecha+"&"+userkey+"&"+strino+"&"+postanteriores,ofsPost);
    etiqueta(trino,userkey);
    }else if(post=='v'||post == 'V'){
    escribir(postanteriores,ofsPost);
    valido = true;
    }
    system("cls");
}}
string leerpost(string userkey){
string userpost = userkey+ "POST"+".txt";
ifstream ifsPost (userpost.c_str());
string postanteriores = leer(ifsPost);
char* postant = new char[postanteriores.length()];
postant = espacios(postanteriores);
ifsPost.close();
return string(postant);
}
bool sigue(string userkey, string userk){
string userseg = userkey+ "SEGUIDOS.txt";
ifstream ifsSeg (userseg.c_str());
string useguidos = leer(ifsSeg);
string usuario;
char* useg = new char[useguidos.length()];
useg = (char*)useguidos.c_str();
bool sigue = false;
int i =0;
int j = 0;
if(useguidos.length()!=0){
while (j<strlen(useg)){
        usuario ="";
for(i = j; i<strlen(useg);i++){
        if(useg[i]=='&'){
            j = i+1;
            i = strlen(useg);
        }else{
           usuario = usuario +""+ useg[i];
        }
}
if(strcmp(usuario.c_str(), userk.c_str())==0){
    sigue = true;
    j = strlen(useg);
}
}}
return sigue;
}
void eseguir(string userkey, string userk){
string userseg = userkey+ "SEGUIDOS.txt";
ifstream ifsSeg (userseg.c_str());
string useguidos = leer(ifsSeg);
ofstream ofsSeg(userseg.c_str());
useguidos = userk +"&"+useguidos;
escribir(useguidos,ofsSeg);
}
void emensaje(string userkey, string userk){
string userseg = userkey+ "MENSAJE.txt";
ifstream ifsSeg (userseg.c_str());
string useguidos = leer(ifsSeg);
ofstream ofsSeg(userseg.c_str());
useguidos = userk +"&"+useguidos;
escribir(useguidos,ofsSeg);
}
void deseguir(string userkey, string userk){
string userseg = userkey+ "SEGUIDOS.txt";
ifstream ifsSeg (userseg.c_str());
string useguidos = leer(ifsSeg);
ofstream ofsSeg(userseg.c_str());
string usuario;
int pos2 = 0;
int pos1 = 0;
char* useg = new char[useguidos.length()];
useg = (char*)(useguidos.c_str());
int i = 0;
int j = 0;
while (j<strlen(useg)){
for(i = j;i<strlen(useg);i++){
    if(useg[i]=='&'){
    j = i;
    pos2 = i;
    i = strlen(useg);
}else{
    usuario = usuario +""+ useg[i];
}}
pos1 = pos2 - usuario.length();
int n = strlen(useg)-usuario.length();
char* useg1 = new char[n];
if(strcmp(usuario.c_str(), userk.c_str())==0){
    int k = 0;
     for(int h = 0; h<n;h++){
        if(!(h>3 && h<=5)){
            useg[k]= useg1[h];
        }
        k++;
     }
}}
}
void responder(){

}
void imprimirpost(string fecha, string usuario, string trino){
cout<<"---------- "<<fecha<<"--------------------------------------------"<<endl;
cout<<usuario<<endl;
cout<<trino<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
}
char* impost (char* post){
char* post1 = post;
int k = strlen(post);
for(int i =0; i<k; i++){
    post1[i]=post[i];
}
int a = 0;
int maxi =0;
string fecha;
string usuario="@";
string trino;
for(int i = 0; i<k;i++){
    if (a<3){
    if(post1[i]!='&'){
        if(a==0){
            fecha = fecha +""+ post1[i];
        }else if(a==1){
            usuario = usuario +""+ post1[i];
        }else if (a==2){
            trino = trino +""+ post1[i];
        }}
       else{
        a++;
        maxi = i;
       }}else{
    maxi = i;
    i = k;
       }

}
int deftamamo = k-maxi+1;
char* definitivo = new char[deftamamo];
for(int i = 0; i< deftamamo;i++){
    definitivo[i]= post[i+maxi];
}
imprimirpost(fecha,usuario,trino);
return definitivo;
}
void postpantalla(string userkey, int n){
string a = leerpost(userkey);
char* b = (char*) a.c_str();
for(int i= 0; i<n;i++){
    if(strlen(b)>6){
       b = impost(b);
    }else{
     i = n;
     cout<<"NO HAY MAS POST"<<endl;
    }
}
}
void etiquetapantalla(string userkey, int n){
string a = leeretiquetas(userkey);
char* b = (char*) a.c_str();
for(int i= 0; i<n;i++){
    if(strlen(b)>6){
       b = impost(b);
    }else{
     i = n;
     cout<<"NO HAY MAS ETIQUETAS"<<endl;
    }
}
}
void imperfil(string userkey, string userk){
ifstream ifsUsuario ((userkey+"USER.txt").c_str());
string nombre = string(espacios(leer(ifsUsuario)));
leer(ifsUsuario);
leer(ifsUsuario);
leer(ifsUsuario);
string descripcion = string(espacios(leer(ifsUsuario)));
bool valido = false;
char p;
while(!valido){
bool sig = sigue(userk,userkey);
p = '0';
cout<<"********************************************************************************"<<endl;
cout<<userkey<<"                                             ..OFFLINE.."<<endl;
cout<<nombre<<endl;
cout<<"SEGUIDO: "<<sig<<endl;
cout<<endl;
cout<<"   ================================= ESTADO ================================    "<<endl;
cout<<descripcion<<endl;
cout<<"   =========================================================================    "<<endl;
cout<<endl;
postpantalla(userkey,2);
cout<<endl;
cout<<"                                 ¿QUE DESEA HACER?"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o            S => Seguir / Dejar de Seguir          o"<<endl;
cout<<"             o                     V => Volver                   o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='s'&&p!='S'&&p!='v'&&p!='V'){
    cin>>p;
    cin.ignore();
}
if(p=='s' || p =='S'){
    if(sig){
        deseguir(userk,userkey);
    }else{
        eseguir(userk,userkey);

    }
}else{
    valido = true;
}
system("pause");
system("cls");
}
}
void imprimirperfiles(string userkey,string user,int i){
ifstream ifsUsuario ((userkey+"USER.txt").c_str());
leer(ifsUsuario);
leer(ifsUsuario);
leer(ifsUsuario);
leer(ifsUsuario);
string descripcion = string(espacios(leer(ifsUsuario)));
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<i<<"."<<endl;
cout<<"USUARIO:  @"+userkey<<endl;
cout<<"SEGUIDO: "<<sigue(user,userkey)<<endl;
cout<<"ESTADO: "<<endl;
cout<<descripcion<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
}
void perfiles(string userkey){
    ifstream ifsU ("UvsC.txt");
    string user_pasword;
    string user_p;
    string snombre;
    char* user_pas= new char[100];
    bool valido = false;
    int i = 0;
    string* perfiles = new string [5];

while(i==0){
cout<<"********************************************************************************"<<endl;
char p;
int j = 1;
while(!valido){
p = '0';
      user_pasword = leer(ifsU);
      user_pas = (char*) user_pasword.c_str();
      string user_p;
      for(int h =0; h< strlen(user_pas);h++){
        if(user_pas[h]!='&'){
            user_p = user_p+""+user_pas[h];
        }else{
            h = strlen(user_pas);
        }
      }
     if(user_pasword.length()==0|| i>2){
          if(user_pasword.length()==0){
            cout<<endl;
            cout<<"NO HAY MAS PERFILES"<<endl;
          }
        valido = true;
    }else{
        if(strcmp(userkey.c_str(), user_p.c_str())!=0){
                perfiles[i]= user_p;
                imprimirperfiles(perfiles[i],userkey,j);
                j++;
        }else{
            i--;
        }
    }

    i++;
}
cout<<"                                 ¿QUE DESEA HACER?"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o   P => Ver Perfil         M => Ver mas Perfiles   o"<<endl;
cout<<"             o                     V => Volver                   o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='p'&&p!='P'&&p!='m'&&p!='M'&&p!='v'&&p!='V'){
    cin>>p;
    cin.ignore();
}
if(p=='p' || p =='P'){
    char* l = new char[1];
    char l1;
    l[0]='0';
    int m;
    while(!('0'<l[0] && l[0]<='5')){
        cout<<"NUMERO DEl PERFIL QUE DESEA VER: "<<endl;
        cin>>l1;
        l[0]=l1;
        m = atoi(string(l).c_str())-1;
        if(m>j-2){
            l[0]='0';
        }
        cin.ignore();
    }
    system("pause");
    system("cls");
    imperfil(perfiles[m],userkey);
    valido = false;
    i=0;

}else if(p=='m' || p =='M'){
    valido = false;
    system("pause");
    i=0;

}else if(p=='v' || p =='V'){
    i =1;
    system("pause");
}

    system("cls");

}

}
bool mensaje (string userkey, string userk){
string userseg = userkey+ "MENSAJE.txt";
ifstream ifsSeg (userseg.c_str());
string useguidos = leer(ifsSeg);
string usuario;
char* useg = new char[useguidos.length()];
useg = (char*)useguidos.c_str();
bool sigue = false;
int i =0;
int j = 0;
if(useguidos.length()!=0){
while (j<strlen(useg)){
        usuario ="";
for(i = j; i<strlen(useg);i++){
        if(useg[i]=='&'){
            j = i+1;
            i = strlen(useg);
        }else{
           usuario = usuario +""+ useg[i];
        }
}
if(strcmp(usuario.c_str(), userk.c_str())==0){
    sigue = true;
    j = strlen(useg);
}
}}
return sigue;
}
void imprimirmensajes (string fecha,string usuario, string mensaje){
cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
cout<<fecha<<endl;
cout<<"=> @"<<usuario<<endl;
cout<<endl;
cout<<mensaje<<endl;
cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
cout<<endl;
}
string fech(){
    string sfec = (noespacios(fecha()));
    return sfec;
}
void mensajes (string userkey, string userk){
   string usmen = userkey+"M"+userk+".txt";
   if(!mensaje(userkey,userk)&&!mensaje(userk,userkey)){
        ofstream ofsMen (usmen.c_str());
        emensaje(userkey,userk);
   }
string fecha;
string usuario;
string mensage;
bool valido = false;
char p;
while(!valido){
string mensajeant = leermensajes(usmen);
if(mensajeant.length()==0){
    usmen = userk+"M"+userkey+".txt";
    mensajeant=leermensajes(usmen);
}
char* menant = new char [mensajeant.length()];
menant = espacios(mensajeant);
ofstream ofsMe (usmen.c_str());
p = '0';
int a = 0;
for(int i = 0; i<strlen(menant)+1;i++){
    if (a<3){
    if(menant[i]!='&'){
        if(a==0){
            fecha = fecha +""+ menant[i];
        }else if(a==1){
            usuario = usuario +""+ menant[i];
        }else if (a==2){
            mensage = mensage +""+ menant[i];
        }}
       else{
        a++;
       }}else{
           a = 0;
           imprimirmensajes(fecha,usuario,mensage);
           fecha = "";
           usuario ="";
           mensage="";
   }}
cout<<"                                 ¿QUE DESEA HACER?"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o        E => Escribir Mensaje    V => Volver       o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='v'&&p!='V'&&p!='e'&&p!='E'){
    cin>>p;
    cin.ignore();
}

if (p=='e'||p=='E'){
   cout<<"ESCRIBA SU MENSAJE: "<<endl;
  char* mensajef = new char[1000];
  cin.getline(mensajef, 1000, '\n');
  string smensaje = noespacios(mensajef);
   string sfec = fech();
  escribir(noespacios(menant)+noespacios((char*)sfec.c_str())+"&"+userkey+"&"+noespacios((char*)smensaje.c_str())+"&",ofsMe);
}else if(p=='v'||p=='V'){
    escribir(noespacios(menant),ofsMe);
    valido = true;
}
system("pause");
system("cls");
}}
void perfileseguidos(string userkey){
string persegu;
string* perfiles = new string [100];
char p;
bool valido = false;
while(!valido){
p = '0';
int j = 0;
ifstream ifsSeg((userkey+"SEGUIDOS.txt").c_str());
string seguidos = leer(ifsSeg);
char* cseguidos  = new char[100];
cseguidos = (char*) seguidos.c_str();
for(int i = 0; i<strlen(cseguidos);i++){
    if(cseguidos[i]!='&'){
        persegu = persegu+""+cseguidos[i];
    }else{
     perfiles[j] = persegu;
     j++;
     persegu="";
    }
}
cout<<"********************************************************************************"<<endl;
for(int i = 0; i<j;i++){
    imprimirperfiles(perfiles[i],userkey,i+1);
}
cout<<"                                 ¿QUE DESEA HACER?"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o         M => Mensaje          V => Volver         o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='m'&&p!='M'&&p!='v'&&p!='V'){
    cin>>p;
    cin.ignore();
}
if(p=='m' || p =='M'){
    char* l = new char[1];
    char l1;
    l[0]='0';
    int m;
    while(!('0'<l[0] && l[0]<='9')){
        cout<<"NUMERO DEl PERFIL QUE DESEA VER: "<<endl;
        cin>>l1;
        l[0]=l1;
        m = atoi(string(l).c_str())-1;
        if(m>j-1){
            l[0]='a';
        }
        cin.ignore();
    }
    system("pause");
    system("cls");
    mensajes(userkey, perfiles[m]);
    valido = false;


}else if(p=='v' || p =='V'){
    valido =true;

}
    system("pause");
    system("cls");
}}
void pantalla_incio(string userkey){
ifstream ifsUsuario ((userkey+"USER.txt").c_str());
string nombre = string(espacios(leer(ifsUsuario)));
leer(ifsUsuario);
leer(ifsUsuario);
leer(ifsUsuario);
string descripcion = string(espacios(leer(ifsUsuario)));
bool valido = false;
char p;
while(!valido){
p = '0';
cout<<"********************************************************************************"<<endl;
cout<<userkey<<"                                             ..ONLINE.."<<endl;
cout<<nombre<<endl;
cout<<endl;
cout<<"   ================================= ESTADO ================================    "<<endl;
cout<<descripcion<<endl;
cout<<"   =========================================================================    "<<endl;
cout<<endl;
postpantalla(userkey,2);
cout<<endl;
cout<<"                                 ¿QUE DESEA HACER?"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o        T => Trinar               P => Post        o"<<endl;
cout<<"             o     C => Configuracion         M => Mensajes      o"<<endl;
cout<<"             o       B => Perfiles            E => Etiquetas     o"<<endl;
cout<<"             o                 S => Cerrar Sesion                o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='t'&&p!='T'&&p!='p'&&p!='P'&&p!='s'&&p!='S'&&p!='c'&&p!='C'&&p!='b'&&p!='B'&&p!='e'&&p!='E'&&p!='m'&&p!='M'){
    cin>>p;
    cin.ignore();
}
system("pause");
system("cls");
if(p=='T' || p =='t'){
     postear(userkey);
}else if (p=='P'|| p == 'p'){
bool val = false;
int m = 1;
char l;
while(!val){
l ='0';
cout<<"------------- TUS POST -------------"<<endl;
postpantalla(userkey,m);
string* perfiles = new string [100];
ifstream ifsSeg((userkey+"SEGUIDOS.txt").c_str());
string seguidos = leer(ifsSeg);
string persegu;
char* cseguidos  = new char[100];
int j = 0;
cseguidos = (char*) seguidos.c_str();
for(int i = 0; i<strlen(cseguidos);i++){
    if(cseguidos[i]!='&'){
        persegu = persegu+""+cseguidos[i];
    }else{
     perfiles[j] = persegu;
     j++;
     persegu="";
    }
}
cout<<"------------- POST SEGUIDOS -------------"<<endl;
for(int i = 0; i<j;i++){
    postpantalla(perfiles[i],m);
}
cout<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o        M => Ver mas Post          V => Volver     o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
while(l!='m'&&l!='M'&&l!='v'&&l!='V'){
    cin>>l;
    cin.ignore();
}if(l=='m'||l=='M'){
m++;
}else if(l=='v'||l=='V'){
val = true;
}
system("pause");
system("cls");
}}else if(p=='c'||p=='C'){
configuracion(userkey);
}
else if(p=='s'||p=='S'){
valido = true;
}else if(p=='b'||p=='B'){
perfiles(userkey);
}else if(p=='m'||p=='M'){
perfileseguidos(userkey);
}else if(p=='e'||p=='E'){
bool val = false;
int m = 5;
char l;
while(!val){
l ='0';
etiquetapantalla(userkey,m);
cout<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o        M => Ver mas Post          V => Volver     o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
while(l!='m'&&l!='M'&&l!='v'&&l!='V'){
    cin>>l;
    cin.ignore();
}if(l=='m'||l=='M'){
m++;
}else if(l=='v'||l=='V'){
val = true;
}
system("pause");
system("cls");
}
}
}}
void registrarchivos(char* nombre, char* correo, char* contrasena, char* telefono, char* descripcion,char*usuario1){
ifstream ifs("UvsC.txt");
string user = leer(ifs);
string uspar;
bool salir = false;
while (!salir){
    uspar=leer(ifs);
    if(uspar.length()==0){
        salir = true;
    }else{
    user = user+" "+uspar;
    }
}
ofstream ofs("UvsC.txt");
string usuario = noespacios(nombre)+ " "+string(contrasena)+" "+string(correo)+" "+string(telefono)+" "+noespacios(descripcion)+" "+string(usuario1)+" ";
string userpas = string(usuario1)+"&"+string(contrasena)+"&";
ofstream ofsPost((string(usuario1)+"POST.txt").c_str());
ofstream ofsSeg((string(usuario1)+"SEGUIDOS.txt").c_str());
ofstream ofsEti((string(usuario1)+"ETIQUETAS.txt").c_str());
ofstream ofsMen((string(usuario1)+"MENSAJE.txt").c_str());
ofstream ofsUuario((string(usuario1)+"USER.txt").c_str());
escribir(usuario, ofsUuario);
escribir(user+" "+userpas,ofs);

}
void registro(){
char* nombre = new char[100];
char* usuario = new char[100];
char* correo = new char[360];
char* contrasena = new char [100];
char* telefono = new char [100];
char* descripcion = new char [320];
bool valido = false;
char p;
while(!valido){
p = '0';
cout<<"********************************************************************************"<<endl;
cout<<"    ######## ########  #### ##    ##    ###    ##    ## ########   #######"<<endl;
cout<<"       ##    ##     ##  ##  ###   ##   ## ##   ###   ## ##     ## ##     ##"<<endl;
cout<<"       ##    ##     ##  ##  ####  ##  ##   ##  ####  ## ##     ## ##     ##"<<endl;
cout<<"       ##    ########   ##  ## ## ## ##     ## ## ## ## ##     ## ##     ##"<<endl;
cout<<"       ##    ##   ##    ##  ##  #### ######### ##  #### ##     ## ##     ##"<<endl;
cout<<"       ##    ##    ##   ##  ##   ### ##     ## ##   ### ##     ## ##     ##"<<endl;
cout<<"       ##    ##     ## #### ##    ## ##     ## ##    ## ########   #######"<<endl;
cout<<endl;
cout<<"NOMBRE COMPLETO: ";
cin.getline(nombre, 100, '\n');
cout<<"USUARIO: ";
cin.getline(usuario, 100, '\n');
cout<<"CORREO ELECTRONICO: ";
cin.getline(correo, 360, '\n');
cout<<"CONTRASENA: ";
cin.getline(contrasena, 100, '\n');
cout<<"TELEFONO: ";
cin.getline(telefono, 100, '\n');
cout<<"DESCRIPCION: "<<endl;
cin.getline(descripcion, 320, '\n');
cout<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o        R => Registrarse        V => Volver        o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='r'&&p!='R'&&p!='v'&&p!='V'){
    cin>>p;
    cin.ignore();
}
if(p=='r'||p=='R'){
valido = validaregistro(nombre,correo,contrasena,telefono,usuario);
if(valido){
    registrarchivos(nombre,correo,contrasena,telefono,descripcion,usuario);
}
}else if (p=='v'||p=='V'){
valido = true;
}
system("pause");
system("cls");
}
}
void iniciar(){
bool valido = false;
char p;
while(!valido){
p = '0';
cout<<"********************************************************************************"<<endl;
cout<<"    ######## ########  #### ##    ##    ###    ##    ## ########   #######"<<endl;
cout<<"       ##    ##     ##  ##  ###   ##   ## ##   ###   ## ##     ## ##     ##"<<endl;
cout<<"       ##    ##     ##  ##  ####  ##  ##   ##  ####  ## ##     ## ##     ##"<<endl;
cout<<"       ##    ########   ##  ## ## ## ##     ## ## ## ## ##     ## ##     ##"<<endl;
cout<<"       ##    ##   ##    ##  ##  #### ######### ##  #### ##     ## ##     ##"<<endl;
cout<<"       ##    ##    ##   ##  ##   ### ##     ## ##   ### ##     ## ##     ##"<<endl;
cout<<"       ##    ##     ## #### ##    ## ##     ## ##    ## ########   #######"<<endl;
cout<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o"<<endl;
cout<<"             o     I => Iniciar Sesion       R => Registrarse     o"<<endl;
cout<<"             o                      S => Salir                    o"<<endl;
cout<<"              o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o "<<endl;
cout<<endl;
cout<<"********************************************************************************"<<endl;
while(p!='r'&&p!='R'&&p!='i'&&p!='I'&&p!='s'&&p!='S'){
    cin>>p;
    cin.ignore();
}
if(p=='r'||p=='R'){
system("pause");
system("cls");
 registro();
}else if (p=='i'||p=='I'){
system("pause");
system("cls");
string userkey = login();
pantalla_incio(userkey);
}else if(p=='s'||p=='S'){
valido = true;
}

}}

int main()
{
iniciar();
return 0;
}
