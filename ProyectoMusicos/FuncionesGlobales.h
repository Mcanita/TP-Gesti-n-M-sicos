#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargarCadena(char *pal, int tam);
void lineBreak();
void pausa();
void DibujarCuadro(int x, int y, int ancho, int alto);

void showItem(const char* text,int posX,int posY, bool selected){
    if(selected){
        rlutil::setBackgroundColor(rlutil::MAGENTA);
    }
    else{
        rlutil::setBackgroundColor(rlutil::BLACK);
    }
          rlutil::locate(posX,posY);
          std::cout<<text<<std::endl;
          rlutil::setBackgroundColor(rlutil::BLACK);
}

void DibujarCuadro(int x, int y, int ancho, int alto)
{
    rlutil::locate(x, y); // izquierdo hacia abajo !=
    std::cout<<(char)201;
    rlutil::locate(x + 1, y); /// LINEA SUPERIOR
    for (int i = 0; i <= ancho; i++)
    {
        std::cout<<(char)205;
    }
    rlutil::locate(x + ancho + 1, y); // Derecho hacia abajo =!
    std::cout<<(char)187;


    ///////////////////////////////////////////////////
/// LATERALES
    for (int i = 1; i <= alto + 1; i++) {
        rlutil::locate(x, y + i); // Lateral 1
         std::cout<<(char)186;
        rlutil::locate(x + ancho + 1, y + i); // Lateral 2
         std::cout<<(char)186;

    }

    ///////////////////////////////////////////////////

    rlutil::locate(x, y + 2 + alto); // izquierdo hacia arriba !=
    printf("%c", 200);
    rlutil::locate(x + 1, y + 2 + alto); /// LINEA INFERIOR
    for (int i = 0; i <= ancho; i++)
    {
        std::cout<<(char)205;
    }
    rlutil::locate(x + ancho + 1, y + 2 + alto);
    std::cout<<(char)188; // Derecho hacia arriba =!

}

void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin);
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}

void lineBreak(){
cout<<endl;
}

void pausa(){
  system("pause");
  }

#endif // FUNCIONESGLOBALES_H_INCLUDED
