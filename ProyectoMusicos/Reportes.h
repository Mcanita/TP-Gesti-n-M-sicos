#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

bool buscarXNombreMusicos();

bool buscarXNombreMusicos()
{

    char nombreAux[30] = {};
    Musico musico, auxMusico;
    ArchivoMusico aMusicos(ArchivoMusicosString);
    int cantReg = aMusicos.contarRegistros();


    cout<<"Ingrese nombre del musico a buscar: "<<endl;
    cargarCadena(nombreAux,29);

    auxMusico.setNombre(nombreAux);

    for(int i=0; i<cantReg; i++)
    {

        musico = aMusicos.leerRegistro(i);

        if(auxMusico == musico)
        {

            musico.Mostrar();
            return true;

        }

    }

    return false;
}


void buscarNombresMayoresXValue()
{

    Musico musico;
    ArchivoMusico aMusicos(ArchivoMusicosString);
    int cantReg = aMusicos.contarRegistros();
    int value;

    cout<<"Ingrese valor a comparar: (Devuelve nombres mayores a un valor ingresado): "<<endl;
    cin>>value;


    for(int i=0; i<cantReg; i++)
    {

        musico = aMusicos.leerRegistro(i);
        if (musico >= value)
        {
            musico.Mostrar();
            lineBreak();
        }

    }


}

void buscarAmaria()
{

    Musico musico;
    ArchivoMusico aMusicos(ArchivoMusicosString);
    int cantReg = aMusicos.contarRegistros();
    const char* maria = "Maria";

    cout<<"SE MOSTRARA EL REGISTRO DE MARIA: "<<endl;

    for(int i=0; i<cantReg; i++)
    {
        musico = aMusicos.leerRegistro(i);
        if (musico == maria) musico.Mostrar(); //sobrecarga operator ==

    }


}




void menuReportes()
{
    ArchivoMusico aMusicos(ArchivoMusicosString);

    int op=1, y=0;
    system("cls");
    do
    {
        DibujarCuadro(21, 6, 40, 12);
        rlutil::locate(30,9);
        std::cout<<"------ PARCIAL ------ "<<std::endl;
        showItem(" PUNTO 1 ",31,10,y==0);
        showItem(" PUNTO 2 ",31,11,y==1);
        showItem(" PUNTO 3 ",31,12,y==2);
        showItem(" PUNTO 4 ",31,13,y==3);
        showItem("  ... ",31,14,y==4);
        rlutil::locate(30,15);
        std::cout<<"---------------------- "<<std::endl;
        showItem(" VOLVER AL MENU PRINCIPAL ",31,16,y==6);

        rlutil::locate(29,10+ y);
        std::cout<<(char)175<<std::endl;
        switch(rlutil::getkey())
        {
        case 14://up
            rlutil::locate(29,10+ y);
            std::cout<<" "<<std::endl;
            y--;
            if(y<0)
            {
                y=0;
            }
            else if(y==5)
            {
                y=4;
            }
            break;
        case 15://down
            rlutil::locate(29,10+ y);
            std::cout<<" "<<std::endl;
            y++;
            if(y==5 || y>6)
            {
                y=6;
            }
            break;
        case 1://enter
            switch(y)
            {
            case 0:
                system("cls");
            buscarAmaria();
                pausa();
                system("cls");
                lineBreak();
                break;
            case 1:
                system("cls");
                buscarXNombreMusicos();
                pausa();
                system("cls");
                lineBreak();
                break;
            case 2:
                system("cls");
                pausa();
                system("cls");
                lineBreak();
                break;
            case 3:
                system("cls");
                buscarNombresMayoresXValue();
                pausa();
                system("cls");
                break;
            case 4:
                system("cls");
                buscarXNombreMusicos();
                pausa();
                system("cls");
                break;
            case 5:
                system("cls");

                pausa();
                system("cls");
                return;
                break;
            case 6:
                system("cls");

                pausa();
                system("cls");
                return;
                break;
            default:
                break;
            }

        }
        //std::cout<< "key: "<<key;
        //rlutil::anykey();


    }
    while(op !=0);


}

#endif // REPORTES_H_INCLUDED
