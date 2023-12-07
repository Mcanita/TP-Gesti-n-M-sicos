#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int menuPrincipal();
void menuMusicos();
void menuGeneros();
void menuInstrumentos();
void menuPaises();


int menuPrincipal()
{
    system("cls");
    int op=1, y=0;
    rlutil::hidecursor();
   do{
      DibujarCuadro(21, 6, 38, 12);
      rlutil::locate(30,9);
       std::cout<<"--- MENU PRINCIPAL --- "<<std::endl;
       showItem(" MENU MUSICOS " ,31,10,y==0);
       showItem(" MENU GENEROS " ,31,11,y==1);
       showItem(" MENU INSTRUMENTOS " ,31,12,y==2);
       showItem(" MENU PAISES " ,31,13,y==3);
       showItem(" REPORTES ",31,14,y==4);
       showItem(" CONFIGURACION " ,31,15,y==5);
       rlutil::locate(30,16);
       std::cout<<"--------------------- "<<std::endl;
       showItem(" SALIR " ,31,17,y==7);

       rlutil::locate(29,10+ y);
       std::cout<<(char)175<<std::endl;
       switch(rlutil::getkey())
       {
       case 14://up
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y--;
           if(y<0){
            y=0;
           }
           else if(y==6){
            y=5;
           }
           break;
       case 15://down
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y++;
           if(y==6 || y>7){
            y=7;
           }
           break;
        case 1://enter
            switch(y)
            {
            case 0:
                 menuMusicos();
                break;
            case 1:
                menuGeneros();
                break;
            case 2:
                menuInstrumentos();
                break;
            case 3:
                menuPaises();
                break;
            case 4:
                menuReportes();
                break;
            case 5:
                menuConfiguracion();
                break;
            case 7:
                lineBreak();
                lineBreak();
                lineBreak();
                return 0;
            }
           break;
       default:
           break;

       }
       //std::cout<< "key: "<<key;
       //rlutil::anykey();


    }while(op !=0);



   }

void menuMusicos()
{
    ArchivoMusico aMusicos(ArchivoMusicosString);
    bool agrego, mostro, modifico,elimino;

    int opc=1, y=0;
    system("cls");

     rlutil::hidecursor();
    do{
       DibujarCuadro(21, 6, 46, 12);
       rlutil::locate(30,9);
       std::cout<<"--------- MENU MUSICOS -------- "<<std::endl;
       showItem(" AGREGAR MUSICOS " ,31,10,y==0);
       showItem(" LISTAR MUSICO POR DNI " ,31,11,y==1);
       showItem(" LISTAR TODOS LOS MUSICOS " ,31,12,y==2);
       showItem(" MODIFICAR FECHA DE INSCRIPCION " ,31,13,y==3);
       showItem(" ELIMINAR REGISTRO DE MUSICO ",31,14,y==4);
       rlutil::locate(30,15);
       std::cout<<"------------------------------- "<<std::endl;
       showItem(" VOLVER AL MENU PRINCIPAL " ,31,16,y==6);

        rlutil::locate(29,10+ y);
       std::cout<<(char)175<<std::endl;
       switch(rlutil::getkey())
       {
       case 14://up
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y--;
           if(y<0){
            y=0;
           }
           else if(y==5){
            y=4;
           }
           break;
       case 15://down
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y++;
           if(y==5 || y>6){
            y=6;
           }
           break;
        case 1://enter
            switch(y)
            {
            case 0:
                 system("cls");
                 agrego = aMusicos.agregarMusico();
                 if(agrego) cout<<"El músico se agregó con éxito"<<endl;
                 else {
                  system("cls");
                  cout<<"Error al agregar el músico"<<endl;
                  }
                 lineBreak();
                 pausa();
                 system("cls");
                break;
            case 1:
                system("cls");
                mostro = mostrarXdni();
                lineBreak();
                if(mostro) cout<<"Se ha encontrado registro"<<endl;
                else cout<<"No existe el DNI ingresado en el archivo"<<endl;
                lineBreak();
                pausa();
                system("cls");
                break;
            case 2:
                system("cls");
                mostrarArchivoMusicos();
                lineBreak();
                pausa();
                system("cls");
                break;
            case 3:
                system("cls");
                modifico = modificarFechaInscripcion();
                lineBreak();
                if(modifico) cout<<"Se modifico con éxito la fecha"<<endl;
                else cout<<"No se ha podido modificar el registro"<<endl;
                lineBreak();
                pausa();
                system("cls");
                break;
            case 4:
                system("cls");
                elimino = bajaMusico();
                if(elimino) cout<<"Se elimino con éxito el registro"<<endl;
                else cout<<"El dni ingresado no se encuentra registrado"<<endl;
                 pausa();
                 system("cls");
                break;
            case 6:
                system("cls");
                return;
                break;
           default:
                break;

       }
       }

    }while(opc !=0);

    return ;

}


void menuGeneros()
{
    int op=1, y=0;
    bool mostroG, modificoG, eliminoG, agrego;
    ArchivoGeneros aGenero(ArchivoGenerosString);
   system("cls");
   rlutil::hidecursor();
   do{
       DibujarCuadro(21, 6, 40, 12);
       rlutil::locate(30,9);
       std::cout<<"--- MENU GENEROS --- "<<std::endl;
       showItem(" AGREGAR GENERO " ,31,10,y==0);
       showItem(" LISTAR GENERO POR ID " ,31,11,y==1);
       showItem(" LISTAR TODO " ,31,12,y==2);
       showItem(" MODIFICAR ANIO DE ORIGEN " ,31,13,y==3);
       showItem(" ELIMINAR REGISTRO ",31,14,y==4);
       rlutil::locate(30,15);
       std::cout<<"--------------------- "<<std::endl;
       showItem(" VOLVER AL MENU PRINCIPAL " ,31,16,y==6);

       rlutil::locate(29,10+ y);
       std::cout<<(char)175<<std::endl;
       switch(rlutil::getkey())
       {
       case 14://up
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y--;
           if(y<0){
            y=0;
           }
           else if(y==5){
            y=4;
           }
           break;
       case 15://down
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y++;
           if(y==5 || y>6){
            y=6;
           }
           break;
        case 1://enter
            switch(y)
            {
            case 0:
                 system("cls");
                 agrego = aGenero.agregarGenero();
                 if(agrego) cout<< "El género se agregó con éxito" <<endl;
                 else {
                 system("cls");
                 cout<<"Error al agregar el género"<<endl;
                 }
                 lineBreak();
                 pausa();
                 system("cls");
                break;
            case 1:
                system("cls");
                mostroG = mostrarXid();
                lineBreak();
                if(!mostroG)
                cout<<"No existe el id ingresado en el archivo"<<endl;
                lineBreak();
                 pausa();
                 system("cls");
                break;
            case 2:
                system("cls");
                mostrarArchivoGeneros();
                pausa();
                system("cls");
                break;
            case 3:
                 system("cls");
                 modificoG = modificarAnioOrigen();
                 lineBreak();
                 if(modificoG) cout<<"Se modifico con éxito el año de origen"<<endl;
                 else cout<<"No se ha podido modificar el registro"<<endl;
                 lineBreak();
                 pausa();
                 system("cls");
                break;
            case 4:
                system("cls");
                eliminoG = eliminarRegistroGenero();
                if(eliminoG) cout<<"Se elimino con éxito el registro"<<endl;
                else cout<<"El id ingresado no se encuentra en el archivo"<<endl;
                pausa();
                lineBreak();
                system("cls");
                break;
            case 6:
                system("cls");
                return;
            }
           break;
       default:
           break;

       }
       //std::cout<< "key: "<<key;
       //rlutil::anykey();


    }while(op !=0);

    return ;
}

void menuConfiguracion()
{
    system("cls");
    int op=1, y=0;
    bool copioM, restauroM, copioG,restauroG, establecio;
     rlutil::hidecursor();
   do{
       DibujarCuadro(21, 6, 58, 12);
       rlutil::locate(30,9);
       std::cout<<"---------- MENU CONFIGURACION ---------- "<<std::endl;
       showItem(" COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS " ,31,10,y==0);
       showItem(" COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS " ,31,11,y==1);
       showItem(" RESTAURAR DEL ARCHIVO DE MUSICOS " ,31,12,y==2);
       showItem(" RESTAURAR DEL ARCHIVO DE GENEROS " ,31,13,y==3);
       showItem(" ESTABLECER DATOS DE INICIO ",31,14,y==4);
       rlutil::locate(30,15);
       std::cout<<"---------------------------------------- "<<std::endl;
       showItem(" VOLVER AL MENU PRINCIPAL " ,31,16,y==6);

       rlutil::locate(29,10+ y);
       std::cout<<(char)175<<std::endl;
       switch(rlutil::getkey())
       {
       case 14://up
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y--;
           if(y<0){
            y=0;
           }
           else if(y==5){
            y=4;
           }
           break;
       case 15://down
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y++;
           if(y==5 || y>6){
            y=6;
           }
           break;
        case 1://enter
            switch(y)
            {
            case 0:
                system("cls");
                copioM = backUpMusicos();
                if(copioM) cout<< "La copia de seguridad se creó con éxito"<<endl;
                else cout<<"No se ha realizado la copia de seguridad"<<endl;
                 pausa();
                 system("cls");
                break;
            case 1:
                system("cls");
                copioG=backUpGeneros();
                if(copioG) cout<< "La copia de seguridad se creó con éxito"<<endl;
                else cout<<"No se ha realizado la copia de seguridad"<<endl;
                 pausa();
                 system("cls");
                break;
            case 2:
                system("cls");
                restauroM = restaurarMusicos();
                if(restauroM) cout<<"Se ha restaurado el archivo Músicos"<<endl;
                else cout<<"No se ha podido restaurar el archivo Músicos"<<endl;
                 pausa();
                 system("cls");
                break;
            case 3:
                system("cls");
                restauroG=restaurarGeneros();
                if(restauroG) cout<<"Se ha restaurado el archivo Géneros"<<endl;
                 pausa();
                 system("cls");
                break;
            case 4:
                system("cls");
                establecerDatosDeInicio();
                pausa();
                system("cls");
                break;
            case 6:
                system("cls");
                return;
                break;
          /*case 7:
                establecio = establecerDatosDeInicioDATaINI();
                if(establecio) cout<<"Se crearon los .INI con éxito"<<endl;
                else cout<<"Error al crear los .INI"<<endl;
                break;*/
        default:
                break;
            }


       }

    }while(op !=0);

    return ;


}

void menuInstrumentos()
{
    system("cls");
    int op=1, y=0;
    bool agregoI, mostroI, modificoI, eliminoI;
    ArchivoInstrumentos aInstrumentos(ArchivoInstrumentosString);
     rlutil::hidecursor();
   do{
       DibujarCuadro(21, 6, 41, 12);
       rlutil::locate(30,9);
       std::cout<<"----- MENU INSTRUMENTOS ---- "<<std::endl;
       showItem(" AGREGAR INSTRUMENTO " ,31,10,y==0);
       showItem(" LISTAR INSTRUMENTO POR ID " ,31,11,y==1);
       showItem(" LISTAR TODO " ,31,12,y==2);
       showItem(" MODIFICAR NOMBRE " ,31,13,y==3);
       showItem(" ELIMINAR REGISTRO ",31,14,y==4);
       rlutil::locate(30,15);
       std::cout<<"------------------------ "<<std::endl;
       showItem(" VOLVER AL MENU PRINCIPAL " ,31,16,y==6);

       rlutil::locate(29,10+ y);
       std::cout<<(char)175<<std::endl;
       switch(rlutil::getkey())
       {
       case 14://up
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y--;
           if(y<0){
            y=0;
           }
           else if(y==5){
            y=4;
           }
           break;
       case 15://down
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y++;
           if(y==5 || y>6){
            y=6;
           }
           break;
        case 1://enter
            switch(y)
            {
            case 0:
                system("cls");
                agregoI = aInstrumentos.agregarInstrumento();
                if(agregoI) cout<<"El instrumento se agrego con éxito"<<endl;
                else cout<<"Error al agregar el instrumento"<<endl;
                lineBreak();
                 pausa();
                 system("cls");
                break;
            case 1:
                system("cls");
                mostroI = mostrarInstrumentoXid();
                lineBreak();
                if(!mostroI)
                cout<<"No existe el id ingresado en el archivo"<<endl;
                lineBreak();
                 pausa();
                 system("cls");
                break;
            case 2:
                system("cls");
                mostrarArchivoInstrumentos();
                lineBreak();
                pausa();
                system("cls");
                break;
            case 3:
                system("cls");
                modificoI = modificarNombreInstrumento();
                lineBreak();
                if(modificoI) cout<<"Se modifico con exito el nombre del instrumento"<<endl;
                else cout<<"No se ha podido modificar el registro"<<endl;
                lineBreak();
                 pausa();
                 system("cls");
                break;
            case 4:
                system("cls");
                eliminoI = eliminarRegistroInstrumento();
                if(eliminoI) cout<<"Se elimino con exito el registro"<<endl;
                else cout<<"El id ingresado no se encuentra en el archivo"<<endl;
                 pausa();
                 system("cls");
                break;
            case 6:
                system("cls");
                return;
            }
           break;
       default:
           break;

       }
       //std::cout<< "key: "<<key;
       //rlutil::anykey();


    }while(op !=0);

    return ;

}


void menuPaises()
{
   system("cls");
   int op=1, y=0;
   ArchivoPaises aPaises(ArchivoPaisesString);
   bool agrego,mostroPais,modificoPais, eliminoPais;
   rlutil::hidecursor();
   do{
       DibujarCuadro(21, 6, 40, 12);
       rlutil::locate(30,9);
       std::cout<<"--- MENU PAISES --- "<<std::endl;
       showItem(" AGREGAR PAIS " ,31,10,y==0);
       showItem(" LISTAR PAIS POR ID " ,31,11,y==1);
       showItem(" LISTAR TODO " ,31,12,y==2);
       showItem(" MODIFICAR NOMBRE " ,31,13,y==3);
       showItem(" ELIMINAR REGISTRO ",31,14,y==4);
       rlutil::locate(30,15);
       std::cout<<"--------------------- "<<std::endl;
       showItem(" VOLVER AL MENU PRINCIPAL " ,31,16,y==6);

       rlutil::locate(29,10+ y);
       std::cout<<(char)175<<std::endl;
       switch(rlutil::getkey())
       {
       case 14://up
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y--;
           if(y<0){
            y=0;
           }
           else if(y==5){
            y=4;
           }
           break;
       case 15://down
           rlutil::locate(29,10+ y);
           std::cout<<" "<<std::endl;
           y++;
           if(y==5 || y>6){
            y=6;
           }
           break;
        case 1://enter
            switch(y)
            {
            case 0:
                system("cls");
                agrego = aPaises.agregarPais();
                if(agrego) cout<< "Se ha agregado con éxito el pais" <<endl;
                else {
                     system("cls");
                     cout<< "No se pudo agregar el registro" <<endl;
                     }
                      pausa();
                      system("cls");
                      lineBreak();
                break;
            case 1:
                system("cls");
                mostroPais=mostrarPaisXid();
                lineBreak();
                 if(!mostroPais)
                cout<<"No existe el id ingresado en el archivo"<<endl;
                 pausa();
                 system("cls");
                 lineBreak();
                break;
            case 2:
                system("cls");
                mostrarArchivoPaises();
                pausa();
                system("cls");
                lineBreak();
                break;
            case 3:
                system("cls");
                modificoPais=modificarNombrePais();
                break;
            case 4:
                system("cls");
                eliminoPais=eliminarRegistroPais();
                pausa();
                system("cls");
                break;
            case 6:
                system("cls");
                return;
            }
           break;
       default:
           break;

       }
       //std::cout<< "key: "<<key;
       //rlutil::anykey();


    }while(op !=0);

    return ;

}

#endif // MENU_H_INCLUDED
