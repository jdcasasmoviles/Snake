#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
//TECLAS
#define ARRIBA    72
#define DERECHA   77
#define IZQUIERDA 75
#define ABAJO     80
#define ESCAPE    27
#define GUARDAR   103
#define CARGAR    99
#define ESPACIO   32
#define ENTER   13
//COLORES
#define AZUL     0x009
#define AMARILLO 0x00E
#define ROJO     0x00C
#define VERDE    0x002
#define VERDE2   0x00B
#define MORADO   0x005
#define PLATA    0x00F
#define VERDE3   0x00A
char tecla;
int flechaX=22,flechaY=13;
//VARIABLES DEL JUEGO
int cuerpo_serpiente[30][2];
int n=1;
int tam=7;
int x=10,y=12;
int direccion=3;
int xcomida,ycomida;
int velocidad=190;
int puntos,h=1;
int vidas=5;
//VARIABLES DE CONTROL DE NIVELES
int con_nivel2=2;
int con_nivel3=2;
int con_nivel4=2;
int con_nivel5=2;
//NIVEL2
int xpiedra[20];
int ypiedra[20];
//NIVEL3
int direccionb;
int xb[3],yb[3];
//NIVEL 5 SERPIENTE FANTASMA
int sf[60][2];
int tamf=5;
int xf=(rand()%73)+3;
int yf=(rand()%18)+4;
int direccionf;

char inicio[70][150] =
{"                                                                      ",
 "                                                                      ",
 "             >O***********************************                    ",
 "                                                                      ",
 "               BBBB  B     B  BBBB  B   B  BBBB                       ",
 "               B     B B   B  B  B  B  B   B                          ",
 "               BBBB  B  B  B  B  B  BBB    BBBB                       ",
 "                  B  B   B B  BBBB  B  B   B                          ",
 "               BBBB  B    BB  B  B  B   B  BBBB                       ",
 "                                                                      ",
 "              **********************************O<                    ",
 "                                                                      ",
 "              ECCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCE                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              ECCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCE                     ",
};

char final[70][150] =
{"                                                                      ",
 "                                                                      ",
 "             >O***********************************                    ",
 "                                                                      ",
 "               BBBB  B     B  BBBB  B   B  BBBB                       ",
 "               B     B B   B  B  B  B  B   B                          ",
 "               BBBB  B  B  B  B  B  BBB    BBBB                       ",
 "                  B  B   B B  BBBB  B  B   B                          ",
 "               BBBB  B    BB  B  B  B   B  BBBB                       ",
 "                                                                      ",
 "              **********************************O<                    ",
 "                                                                      ",
 "              ECCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCE                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D            YOU LOSE             D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              D                                 D                     ",
 "              ECCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCE                     ",
};

char ganaste[70][150] =
{"                                                                      ",
 "                                                                      ",
 "       A A           AAAA AA   A AAAA A A   AAAA                      ",
 "        A            A    A A  A A  A AAA   A                         ",
 "        A            A    A  A A AAAA A  A  AAA                       ",
 "      AAAAA          A    A   AA A  A A   A A                         ",
 "     A AAA A     AAAAA    A   AA A  A A   A AAAA                      ",
 "    AAAAAAAAA                                                         ",
 "    AAAAAAAAA                                                         ",
 "     AAAAAAA           AAAAAAAAAAA               AAAAAAAAAAAAAAAA     ",
 "     AAAAAAA          AAAAAAAAAAAAAA            AAAAAAAAAAAAAAAAAA    ",
 "      AAAAAAA        AAAAAAAAAAAAAAAA          AAAAAAAAAAAAAAAAAA     ",
 "       AAAAAAA      AAAAAA     AAAAAAA        AAAAAAA                 ",
 "        AAAAAAA    AAAAAA       AAAAAAA      AAAAAA                   ",
 "         AAAAAAAAAAAAAAA         AAAAAAAAAAAAAAAAA                    ",
 "          AAAAAAAAAAAAA           AAAAAAAAAAAAAAA                     ",
 "           AAAAAAAAAAA             AAAAAAAAAAAAA                      ",
 "                                                                      ",
 "                PROXIMAMENTE..!!!   VERSION 2.0                       ",
 "                                                                      ",
 "              ECCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCE                     ",
 "              D            YOU WIN              D                     ",
 "              ECCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCE                     ",
};

void gotoxy(int x,int y);
void OcultaCursor();
void Color(int color);
void guardar_posicion();
void dibujar_cuerpo();
void borrar_cuerpo();
void pintar_pantalla();
void guardar_partida();
void cargar_partida();
void pausado();
bool game_over();
void cambiar_velocidad();
void comida();
void puntaje();
void menu_seleccion();
void teclear();
void juego_serpiente();
void pantalla_gameover();
void menu_inicial();
void instrucciones();
void creditos();
void pantalla_ganaste();
void serpientef();
void creditos()
{   system("cls");
     int borrar;
    for(int i=19; i>4; i--)
    {    borrar=i;
        Color(ROJO);gotoxy(20,i);printf("Creditos:");
        Color(PLATA);gotoxy(30,borrar+1);printf("Franklin Gonzales");
        Sleep(150);
        //borrar linea
        for(int x=10; x<60; x++)
        {//borrar produccion
         gotoxy(x,borrar);printf(" ");
         //borrar nombres
         gotoxy(x,borrar+1);printf(" ");
        }
    }
    for(int i=19; i>4; i--)
    {    borrar=i;
        //titulo
        Color(ROJO);gotoxy(20,i);printf("Programacion:");
        //nombre1
        Color(PLATA);gotoxy(30,borrar+1);printf(" Tomas J. Casas Rodriguez");
        Sleep(150);
        //borrar linea
        for(int x=10; x<60; x++)
        {//borrar produccion
            gotoxy(x,borrar);printf(" ");
            //borrar nombre1
            gotoxy(x,borrar+1);printf(" ");
        }
    }
    for(int i=19; i>4; i--)
    {    borrar=i;
        //titulo
        Color(ROJO);gotoxy(20,i);printf("Diseño:");
        Color(PLATA);gotoxy(30,borrar+1);printf(" Jose Castro Ochante");
        Sleep(150);
        //borrar linea
        for(int x=10; x<60; x++)
        {//borrar produccion
            gotoxy(x,borrar);printf(" ");
            //borrar nombres
            gotoxy(x,borrar+1);printf(" ");
        }
    }
}

void salir(){
system("cls");
gotoxy(22,12);printf("SALIENDO ..........");
Sleep(500);
exit(0);
}

void instrucciones(){
  system("cls");
Color(MORADO);gotoxy(4,3);printf("Instrucciones: ");
Color(VERDE);gotoxy(4,5);printf("1-QUE TECLAS SE PUEDE USAR: ");
Color(PLATA);gotoxy(4,7);printf("Izquierda = %c",27);
gotoxy(4,9);printf("Derecha = %c",26);
gotoxy(4,11);printf("Arriba = %c",24);
gotoxy(4,13);printf("Abajo = %c",25);
gotoxy(4,15);printf("TECLA ESC = sirve para salir");
Color(VERDE);gotoxy(4,17);printf("2-Objetivo: ");
Color(PLATA);gotoxy(4,18);printf(">> COMER LA COMIDA EVITANDO CHOCAR CON LAS PAREDES, ");
Color(PLATA);gotoxy(4,19);printf("                       BACTERIAS,PIEDRAS Y MUROS.  <<");
Color(AMARILLO);gotoxy(4,21);printf("Para volver a la pantalla de inicio PRESIONA ENTER");
tecla=getch();
if((tecla==ENTER)){menu_seleccion();}
}

void gotoxy(int x,int y)
{
HANDLE hCon;
COORD dwPos;
dwPos.X=x;
dwPos.Y=y;
hCon=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hCon,dwPos);
}

void OcultaCursor() {
    CONSOLE_CURSOR_INFO cci = {100, FALSE}; // El segundo miembro de la estructura indica si se muestra el cursor o no.
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Color(int color){
	static HANDLE hConsole;
    hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hConsole, color | (0 * 0x10 + 0x100) );
}

void guardar_posicion(){
cuerpo_serpiente[n][0]=x;
cuerpo_serpiente[n][1]=y;
n++;
if(n==tam)n=1;
}

void dibujar_cuerpo(){

for(int i=1;i<tam;i++){Color(VERDE);gotoxy(cuerpo_serpiente[i][0],cuerpo_serpiente[i][1]);printf("%c",127);}
}

void borrar_cuerpo(){
for(int i=1;i<tam;i++){
        gotoxy(cuerpo_serpiente[n][0],cuerpo_serpiente[n][1]);printf(" ");
}
}

void pintar_pantalla(){
//LINEAS HORIZONTALES
for(int i=2;i<78;i++){Color(AZUL);
        gotoxy(i,3);printf("%c",31);
        gotoxy(i,23);printf("%c",30);
        }
//LINEAS VERTICALES
for(int i=4;i<23;i++){Color(AZUL);
        gotoxy(2,i);printf("%c",16);
        gotoxy(77,i);printf("%c",17);
        }
//ESQUINAS
Color(AZUL);
gotoxy(2,3);printf("%c",201);
gotoxy(2,23);printf("%c",200);
gotoxy(77,3);printf("%c",187);
gotoxy(77,23);printf("%c",188);
//OPCIONES DE JUEGO
Color(AMARILLO);gotoxy(2,24);printf("  C ; CARGAR PARTIDA   G : GUARDAR PARTIDA   ESPACE : PAUSE  ESC : SALIR");
}

void guardar_partida(){
int guardar[11];
guardar[0]=n;
guardar[1]=tam;
guardar[2]=x;
guardar[3]=y;
guardar[4]=direccion;
guardar[5]=xcomida;
guardar[6]=ycomida;
guardar[7]=velocidad;
guardar[8]=puntos;
guardar[9]=h;
guardar[10]=vidas;

FILE *pfichero;
pfichero=fopen("Datos.dat","w");
if(pfichero==NULL)return ;
else {
 for(int i=0;i<11;i++) fprintf(pfichero,"%d \n",guardar[i]);
 for(int i=0;i<30;i++)fprintf(pfichero,"%d %d\n",cuerpo_serpiente[i][0],cuerpo_serpiente[i][1]);
if(h==2) for(int i=0;i<20;i++) fprintf(pfichero,"%d %d\n",xpiedra[i],ypiedra[i]);
if(h==3) for(int i=0;i<3;i++)  fprintf(pfichero,"%d %d\n",xb[i],yb[i]);
if(h==4) {for(int i=0;i<20;i++) fprintf(pfichero,"%d %d\n",xpiedra[i],ypiedra[i]);
         for(int i=0;i<3;i++)  fprintf(pfichero,"%d %d\n",xb[i],yb[i]);
         }
if(h==5) {for(int i=0;i<20;i++) fprintf(pfichero,"%d %d\n",xpiedra[i],ypiedra[i]);
         for(int i=0;i<3;i++)  fprintf(pfichero,"%d %d\n",xb[i],yb[i]);
         }
 fclose(pfichero);
}
}

void cargar_partida(){
FILE *pfichero;
pfichero=fopen("Datos.dat","r");
 if(pfichero==NULL)return ;
 else{
fscanf( pfichero,"%d",&n);
fscanf( pfichero,"%d",&tam);
fscanf( pfichero,"%d",&x);
fscanf( pfichero,"%d",&y);
fscanf( pfichero,"%d",&direccion);
fscanf( pfichero,"%d",&xcomida);
fscanf( pfichero,"%d",&ycomida);
fscanf( pfichero,"%d",&velocidad);
fscanf( pfichero,"%d",&puntos);
fscanf( pfichero,"%d",&h);
fscanf( pfichero,"%d",&vidas);
 for(int i=0;i<30;i++) fscanf(pfichero,"%d %d",&cuerpo_serpiente[i][0],&cuerpo_serpiente[i][1]);
if(h==2) for(int i=0;i<20;i++)fscanf( pfichero,"%d %d",&xpiedra[i],&ypiedra[i]);        
if(h==3) for(int i=0;i<3;i++) fscanf( pfichero,"%d %d",&xb[i],&yb[i]);
if(h==4) {
         for(int i=0;i<20;i++) fscanf(pfichero,"%d %d\n",&xpiedra[i],&ypiedra[i]);
         for(int i=0;i<3;i++) fscanf( pfichero,"%d %d",&xb[i],&yb[i]);
         }
if(h==5) {
         for(int i=0;i<20;i++) fscanf(pfichero,"%d %d\n",&xpiedra[i],&ypiedra[i]);
         for(int i=0;i<3;i++) fscanf( pfichero,"%d %d",&xb[i],&yb[i]);
         }
 fclose(pfichero);
}
}

void pausado(){
OcultaCursor();
system("PAUSE>null");
gotoxy(48,1);printf("              ");
}

void despausado(){
 pintar_pantalla();

}

bool game_over(){
//SE CHOCA CON LOS MUROS
if(y==3 || y==23|| x==2 || x==77) {vidas--;return false;}
//SI CHOCA CON SU PROPIO CUERPO
for(int j=tam-1;j>0;j--){
if(cuerpo_serpiente[j][0]==x && cuerpo_serpiente[j][1]==y) {vidas--;return false;}
}
//SI CHOCA CON PIEDRAS NIVEL 2 NIVEL 2,4,5
if(h==2 || h==4 || h==5){
for(int j=0;j<20;j++){
if(xpiedra[j]==x && ypiedra[j]==y)vidas--;
if(vidas==0) return false;
}
}
//SI CHOCA CON BACTERIAS NIVEL 3,4,5
if(h==3 || h==4 || h==5){
 for(int j=0;j<3;j++){
           for(int i=tam-1;i>0;i--){
                                    if(cuerpo_serpiente[i][0]==xb[j] && cuerpo_serpiente[i][1]==yb[j])vidas--;
                                   }
          if(vidas==0) return false;
 }
 }

return true;
}
void cambiar_velocidad(){
  if(puntos==h*5){
    velocidad-=10;
    h++;
  }
}

void comida(){
int i=0;
if(x==xcomida && y==ycomida){
while(i<1){
xcomida=(rand()%73)+3;
ycomida=(rand()%18)+4;
++i;
for(int j=0;j<20;j++){
                     if(xpiedra[j]==xcomida && ypiedra[j]==ycomida)--i;
                     }
for(int j=0;j<3;j++){
                     if(xb[j]==xcomida && yb[j]==ycomida)i=0;
                     }
}
tam++;
puntos+=1;
Color(VERDE2);gotoxy(xcomida,ycomida);printf("%c",4);
cambiar_velocidad();
}
}

void piedras(){
for(int j=0;j<20;j++){
xpiedra[j]=(rand()%73)+3;
ypiedra[j]=(rand()%18)+4;
if(xpiedra[j]==xcomida && ypiedra[j]==ycomida)j--;
else {Color(PLATA);gotoxy(xpiedra[j],ypiedra[j]);printf("%c",177);}
}
}

void bacterias(){
for(int j=0;j<3;j++)//borrando bacterias
{
if(xb[j]==xcomida && yb[j]==ycomida){}
else{gotoxy(xb[j],yb[j]);printf(" ");}
}
int tempx,tempy;
//generando direccion para cada bacteria
for(int j=0;j<3;j++){
            tempx=xb[j];tempy=yb[j];
           direccionb=(rand()%99)+1;
           if(direccionb<=25)tempy--;
           if(direccionb>=26 && direccionb<=50)tempy++;
           if(direccionb>=56 && direccionb<=75)tempx++;
           if(direccionb>=76 )tempx--;
           //SI SE  CHOCA CON LOS MUROS o la comida
           if((tempy<=3 || tempy>=23|| tempx<=2 || tempx>=77) ||  (xb[j]==xcomida && yb[j]==ycomida))--j;
           else {//SI CHOCAN ENTRE ELLAS MISMAS
                if(tempx==xb[j-1] && tempy==yb[j-1])--j;
                else {xb[j]=tempx;yb[j]=tempy;}
                }
}
for(int j=0;j<3;j++){
        Color(VERDE3);gotoxy(xb[j],yb[j]);printf("%c",178);
        }
}

void puntaje(){
  Color(AMARILLO);gotoxy(3,1);printf("PUNTOS :  %d   NIVEL :  %d   VIDAS : %d   ",puntos,h,vidas);
  //NIVEL 2
  if(puntos==5 && (con_nivel2%2==0)){
  con_nivel2++;
  piedras();
  Sleep(1000);
  }
  //NIVEL 3
  if(puntos==10 && (con_nivel3%2==0)){
  con_nivel3++;
  for(int j=0;j<20;j++){//borra piedras
                       gotoxy(xpiedra[j],ypiedra[j]);printf(" ");
                       xpiedra[j]=0;
                       ypiedra[j]=0;
                       }
  //iniciañizando bacterias
   for(int j=0;j<3;j++){
                       xb[j]=(rand()%73)+3;
                       yb[j]=(rand()%18)+4;
                       if((xb[j]==x && yb[j]==y)|| (xb[j]==xcomida && yb[j]==ycomida))--j;
                        Color(VERDE3);gotoxy(xb[j],yb[j]);printf("%c",178);
   }
  Sleep(1000);
  }
  if(10<=puntos && puntos<=14) bacterias();
  //NIVEL4
  if(puntos==15 && (con_nivel4%2==0)){
  con_nivel4++;
  piedras();
  Sleep(3000);
    }
  //NIVEL5
  if(puntos==20 && (con_nivel5%2==0)){
  con_nivel5++;
  Sleep(800);
  }
  if(20<=puntos && puntos<=24) {}
  //NIVEL FINAL
  if(h==6 && puntos==25) pantalla_ganaste();
}

 /*PANTALLAS DE MENU*/
void menu_seleccion(){
menu_inicial();
int flechaX=20,flechaY=13;
    Color(AMARILLO);gotoxy(flechaX,13);printf("%c   Iniciar juego",175);
    Color(PLATA);gotoxy(flechaX,15);printf("    Ayuda/Instruciones");
    gotoxy(flechaX,17);printf("    Creditos");
    gotoxy(flechaX,19);printf("    Salir del juego");
    OcultaCursor();
do{
    tecla=getch();
    if((tecla==ARRIBA && flechaY== 15)||(tecla==ABAJO && flechaY==19) ){
     flechaY=13;
    Color(AMARILLO);gotoxy(flechaX,13);printf("%c   Iniciar juego",175);
    Color(PLATA);gotoxy(flechaX,15);printf("    Ayuda/Instruciones");
    gotoxy(flechaX,17);printf("    Creditos");
    gotoxy(flechaX,19);printf("    Salir del juego");
    tecla=getch();
    }
    if((tecla==ABAJO && flechaY==13) || (tecla==ARRIBA && flechaY==17) ){
    flechaY=15;
    Color(PLATA);gotoxy(flechaX,13);printf("    Iniciar juego");
    Color(AMARILLO);gotoxy(flechaX,15);printf("%c   Ayuda/Instruciones",175);
    Color(PLATA);gotoxy(flechaX,17);printf("    Creditos");
    gotoxy(flechaX,19);printf("    Salir del juego");
    tecla=getch();
    }
    if((tecla==ABAJO && flechaY==15)||(tecla==ARRIBA && flechaY==19) ){
        flechaY=17;
    Color(PLATA);gotoxy(flechaX,13);printf("    Iniciar juego");
    gotoxy(flechaX,15);printf("    Ayuda/Instruciones");
    Color(AMARILLO);gotoxy(flechaX,17);printf("%c   Creditos",175);
    Color(PLATA);gotoxy(flechaX,19);printf("    Salir del juego");
    tecla=getch();
    }
    if((tecla==ABAJO &&flechaY==17)||(tecla==ARRIBA &&flechaY==13) ){
        flechaY=19;
    Color(PLATA);gotoxy(flechaX,13);printf("    Iniciar juego");
    gotoxy(flechaX,15);printf("    Ayuda/Instruciones");
    gotoxy(flechaX,17);printf("    Creditos");
    Color(AMARILLO);gotoxy(flechaX,19);printf("%c   Salir del juego",175);
    }
}while(tecla!=ENTER && tecla!=ESCAPE);
if(tecla==ENTER &&flechaY==13){juego_serpiente();}
if(tecla==ENTER &&flechaY==15){instrucciones();}
if(tecla==ENTER &&flechaY==17){creditos();menu_seleccion();}
if((tecla==ENTER && flechaY ==19) || tecla==ESCAPE){salir();}

}

void teclear(){
     int contador=2;
    if(kbhit()){
                tecla=getch();
                if(tecla==67)tecla=CARGAR;
                if(tecla==71)tecla=GUARDAR;
                switch(tecla){
                              case ARRIBA:if(direccion|=2)
                                          direccion=1;
                                          break;
                              case ABAJO:if(direccion|=1)
                                          direccion=2;
                                          break;
                              case DERECHA:if(direccion|=4)
                                          direccion=3;
                                          break;
                              case IZQUIERDA:if(direccion|=3)
                                           direccion=4;
                                           break;
                              case CARGAR:
                                          cargar_partida();
                                          system("cls");
                                          Color(AMARILLO);gotoxy(48,1);printf("CARGANDO....");
                                          Sleep(800);
                                          system("cls");
                                          pintar_pantalla();
                                          gotoxy(48,1);printf("             ");
                                          Color(VERDE2);gotoxy(xcomida,ycomida);printf("%c",4);
                                          if(h==2) for(int j=0;j<20;j++){Color(PLATA);gotoxy(xpiedra[j],ypiedra[j]);printf("%c",177);}
                                          if(h==3) for(int j=0;j<3;j++){Color(VERDE3);gotoxy(xb[j],yb[j]);printf("%c",177);}
                                          if(h==4) {for(int j=0;j<20;j++){Color(PLATA);gotoxy(xpiedra[j],ypiedra[j]);printf("%c",177);}
                                                    for(int j=0;j<3;j++){Color(VERDE3);gotoxy(xb[j],yb[j]);printf("%c",177);}
                                                   }
                                          if(h==5) {for(int j=0;j<20;j++){Color(PLATA);gotoxy(xpiedra[j],ypiedra[j]);printf("%c",177);}
                                                    for(int j=0;j<3;j++){Color(VERDE3);gotoxy(xb[j],yb[j]);printf("%c",177);}
                                                   }
                                           break;
                              case GUARDAR:guardar_partida();
                                           Color(AMARILLO);gotoxy(48,1);printf("GUARDANDO....");
                                           Sleep(800);
                                           gotoxy(48,1);printf("             ");
                                           break;
                              case ESPACIO:if(contador%2==0)
                                           {Color(AMARILLO);gotoxy(48,1);printf("PAUSADO.....");
                                           pausado();
                                           }
                                           else despausado();
                                           contador++;
                                           break;
                              case ESCAPE:Color(AMARILLO);gotoxy(48,1);printf("SALIENDO....");
                                           Sleep(100);
                                          break;
                              }
                }
}

void juego_serpiente(){
     xcomida=(rand()%73)+3;
     ycomida=(rand()%18)+4;
    Sleep(800);system("cls");
    pintar_pantalla();
    Color(VERDE2); gotoxy(xcomida,ycomida);printf("%c",4);
    while(tecla!=ESCAPE && game_over()){
                        borrar_cuerpo();
                        guardar_posicion();
                        dibujar_cuerpo();
                        comida();
                        puntaje();
                        teclear();
                        teclear();
                        if(direccion==1)y--;
                        if(direccion==2)y++;
                        if(direccion==3)x++;
                        if(direccion==4)x--;
                        Sleep(velocidad);
    }
    pantalla_gameover();
}

void pantalla_gameover(){
system("cls");
for(int i = 0 ; i< 24 ; i++)
    {
        for(int j = 0 ; j < 71 ; j++)
        {Color(MORADO);
         printf("%c",final[i][j]);
        }
      printf("\n");
    }
tecla=getch();
if((tecla==ENTER))exit(0);
}

void pantalla_ganaste(){
system("cls");
for(int i = 0 ; i< 24 ; i++)
    {
        for(int j = 0 ; j < 71 ; j++)
        {Color(VERDE2);
         printf("%c",ganaste[i][j]);
        }
      printf("\n");
    }
Sleep(3500);
creditos();
exit(0);
}


void menu_inicial(){
gotoxy(0,0);
for(int i = 0 ; i< 24 ; i++)
    {
        for(int j = 0 ; j < 71 ; j++)
        {Color(AMARILLO);
         printf("%c",inicio[i][j]);
        }
      printf("\n");
    }
}


using namespace std;
int main(int argc, char *argv[])
{
    menu_seleccion();
    system("PAUSE>null");
    return EXIT_SUCCESS;
}

