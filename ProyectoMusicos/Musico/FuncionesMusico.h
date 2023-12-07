#ifndef FUNCIONESMUSICO_H_INCLUDED
#define FUNCIONESMUSICO_H_INCLUDED

int verificarDniPos(int dni);
void mostrarArchivoMusicos();
bool mostrarXdni();


int verificarDniPos(int dni){

Musico musico;
ArchivoMusico aMusicos(ArchivoMusicosString);
int cantRegMusicos = aMusicos.contarRegistros();

for(int i=0; i<cantRegMusicos; i++){

    musico = aMusicos.leerRegistro(i);
    if(musico.getDni() == dni && musico.getEstado()) {
        return i;
    }

}
return -1;

}

bool verificarDNI(int dni){

Musico musico;
ArchivoMusico aMusicos(ArchivoMusicosString);
int cantRegMusicos = aMusicos.contarRegistros();

for(int i=0; i<cantRegMusicos; i++){

    musico = aMusicos.leerRegistro(i);
    if(musico.getDni() == dni && musico.getEstado()) {
        return true;
    }

}
return false;



}


void mostrarArchivoMusicos(){

Musico reg;
ArchivoMusico aMusicos("Musicos.dat");
int cantRegM= aMusicos.contarRegistros();

for(int i=0; i<cantRegM; i++){

    reg=aMusicos.leerRegistro(i);
    reg.Mostrar();
    cout<<endl;
}

}

bool mostrarXdni(){

Musico musico;
ArchivoMusico aMusicos(ArchivoMusicosString);
int dni,pos;

cout<<"Ingrese DNI del musico a buscar: "<<endl;
cin>> dni;
lineBreak();
pos=verificarDniPos(dni);

if(pos == -1) return false;

musico=aMusicos.leerRegistro(pos);
musico.Mostrar();
lineBreak();

return true;

}

bool modificarFechaInscripcion(){

Musico musico;
Fecha fechaNueva;
ArchivoMusico aMusicos(ArchivoMusicosString);
int dni, pos;
bool modifico;

cout<<"Ingrese DNI del musico a modificar fecha: "<<endl;
cin>>dni;
pos=verificarDniPos(dni);
if(pos==-1) return false;

musico = aMusicos.leerRegistro(pos);
cout<<"Fecha nueva: "<<endl;
fechaNueva.Cargar();
lineBreak();

musico.setFechaInscripcion(fechaNueva);
modifico = aMusicos.modificarRegistro(musico,pos); //guardamos la modificacion en el archivo.

/*
    FILE *p;
    p=fopen(ArchivoMusicosString,"rb+");
    if(p==NULL) return false;

    fseek(p,sizeof(Musicos)*pos,0);
    fwrite(&musico, sizeof(Musicos), 1, p);*/


return modifico;


}

bool bajaMusico(){

bool elimino;
char r;
int dni,pos;
Musico musico;
ArchivoMusico aMusicos(ArchivoMusicosString);

cout<<"Ingrese DNI del musico a eliminar: "<<endl;
cin>>dni;
pos=verificarDniPos(dni);
if(pos==-1) return false;

cout<<"¿Estas seguro que deseas eliminar este registro? (S-s)"<<endl;
cin>>r;
if(r == 's' || r == 'S'){

musico = aMusicos.leerRegistro(pos);
musico.setEstado(false); //"elimino"

elimino = aMusicos.modificarRegistro(musico,pos);
return elimino;
}

return false;

}

#endif // FUNCIONESMUSICO_H_INCLUDED
