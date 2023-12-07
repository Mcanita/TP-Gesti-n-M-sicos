#ifndef FUNCIONESGENERO_H_INCLUDED
#define FUNCIONESGENERO_H_INCLUDED

int autonumericoID();
void mostrarArchivoGeneros();
int verificarIdPos(int id);
bool mostrarXid();
bool modificarAnioOrigen();
bool eliminarRegistroGenero();

int autonumericoID()
{
  ArchivoGeneros aGeneros(ArchivoGenerosString);
  int cantReg=0;

  cantReg = aGeneros.contarRegistros();


    if (cantReg == 0) return 1;

    else
    {
        Generos genero;
        genero = aGeneros.leerRegistro(cantReg-1);
        return genero.getIdGenero() + 1;
    }
}

void mostrarArchivoGeneros(){

Generos reg;
ArchivoGeneros aGeneros("Generos.dat");
int cantRegG= aGeneros.contarRegistros();

for(int i=0; i<cantRegG; i++){

    reg=aGeneros.leerRegistro(i);
    reg.Mostrar();
    cout<<endl;
}

}

int verificarIdPos(int id){

Generos genero;
ArchivoGeneros aGeneros (ArchivoGenerosString);
int cantRegG = aGeneros.contarRegistros();

for(int i=0; i<cantRegG; i++){

   genero = aGeneros.leerRegistro(i);
    if(genero.getIdGenero() == id && genero.getEstado()) {
        return i;
    }

}
return -1;

}

bool mostrarXid(){

Generos genero;
ArchivoGeneros aGeneros(ArchivoGenerosString);
int id,pos;

cout<<"Ingrese el id del genero a mostrar: "<<endl;
cin>> id;
lineBreak();
pos=verificarIdPos(id);

if(pos == -1) return false;

genero=aGeneros.leerRegistro(pos);
genero.Mostrar();
lineBreak();

return true;

}

bool modificarAnioOrigen(){

Generos genero;
Fecha anioNuevo;
ArchivoGeneros aGeneros(ArchivoGenerosString);
int id, pos;
bool modificoG;

cout<<"Ingrese el id del genero a modificar el año de origen: "<<endl;
cin>>id;
pos=verificarIdPos(id);
if(pos==-1) return false;

genero = aGeneros.leerRegistro(pos);
cout<<"Año nuevo: "<<endl;
anioNuevo.CargarAnio();

lineBreak();

genero.setAnioOrigen(anioNuevo);
modificoG = aGeneros.modificarRegistro(genero,pos);

return modificoG;

}

bool eliminarRegistroGenero(){

bool eliminoG;
char r;
int id,pos;
Generos genero;
ArchivoGeneros aGeneros(ArchivoGenerosString);

cout<<"Ingrese ID del género a eliminar: "<<endl;
cin>>id;
pos=verificarIdPos(id);
if(pos==-1) return false;

cout<<"¿Estas seguro que deseas eliminar este registro? (S-s)"<<endl;
cin>>r;
if(r == 's' || r == 'S'){

genero = aGeneros.leerRegistro(pos);
genero.setEstado(false); //"elimino"

eliminoG = aGeneros.modificarRegistro(genero,pos);
return eliminoG;
}

return false;

}

int validarTipoDeMusica(int tm){

while(tm<1 || tm>10){
    cout<<"opcion incorrecta "<<endl;
        cout<< "Ingrese el tipo de música (1-10) : "<<endl;
        cin>> tm;
    }

Generos genero;
ArchivoGeneros aGeneros(ArchivoGenerosString);
int cantReg = aGeneros.contarRegistros();

for(int i=0; i<cantReg; i++){

genero= aGeneros.leerRegistro(i);
if (genero.getIdGenero() == tm && genero.getEstado()) return tm;

}

return -1;


}


#endif // FUNCIONESGENERO_H_INCLUDED
