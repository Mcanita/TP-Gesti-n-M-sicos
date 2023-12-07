#ifndef FUNCIONESINSTRUMENTO_H_INCLUDED
#define FUNCIONESINSTRUMENTO_H_INCLUDED

int validarInstrumentoPrincipal(int ip);
int autonumericoIDinstrumento();
void mostrarArchivoInstrumentos();
bool mostrarInstrumentoXid();
bool modificarNombreInstrumento();
bool eliminarRegistroInstrumento();



int validarInstrumentoPrincipal(int ip){

while(ip<1 || ip>15){
    cout<<" opcion incorrecta "<<endl;
        cout<< "Ingrese el ID del instrumento (1-15) : "<<endl;
        cin>> ip;
    }

Instrumentos instrumento;
ArchivoInstrumentos aInstrumento(ArchivoInstrumentosString);
int cantReg = aInstrumento.contarRegistros();

for(int i=0; i<cantReg; i++){

instrumento= aInstrumento.leerRegistro(i);
if (instrumento.getIdInstrumento() == ip && instrumento.getEstado()) return ip;

}

return -1;


}

int autonumericoIDinstrumento()
{
  ArchivoInstrumentos aInstrumentos(ArchivoInstrumentosString);
  int cantRegI=0;

  cantRegI = aInstrumentos.contarRegistros();


    if (cantRegI == 0) return 1;

    else
    {
        Instrumentos instrumento;
        instrumento = aInstrumentos.leerRegistro(cantRegI-1);
        return instrumento.getIdInstrumento() + 1;
    }
}

void mostrarArchivoInstrumentos(){

Instrumentos instrumento;
ArchivoInstrumentos aInstrumentos("Instrumentos.dat");
int cantReg= aInstrumentos.contarRegistros();

for(int i=0; i<cantReg; i++){

    instrumento=aInstrumentos.leerRegistro(i);
    instrumento.Mostrar();
    cout<<endl;
}

}

bool mostrarInstrumentoXid(){

Instrumentos instrumento;
ArchivoInstrumentos aInstrumentos(ArchivoInstrumentosString);
int id,pos;

cout<<"Ingrese el id del instrumento a mostrar: "<<endl;
cin>> id;
lineBreak();
pos=verificarIdPos(id);

if(pos == -1) return false;

instrumento=aInstrumentos.leerRegistro(pos);
instrumento.Mostrar();
lineBreak();

return true;

}

bool modificarNombreInstrumento(){

Instrumentos instrumento;
char nombreNuevo[30];
ArchivoInstrumentos aInstrumentos(ArchivoInstrumentosString);
int id, pos;
bool modificoI;

cout<<"Ingrese el id del instrumento a modificar el nombre: "<<endl;
cin>>id;
pos=verificarIdPos(id);
if(pos==-1) return false;

instrumento = aInstrumentos.leerRegistro(pos);
cout<<"Ingrese el nuevo nombre: "<<endl;
cargarCadena(nombreNuevo,29);
lineBreak();

instrumento.setNomreInstrumento(nombreNuevo);
modificoI = aInstrumentos.modificarRegistroInstrumentos(instrumento,pos);

return modificoI;

}

bool eliminarRegistroInstrumento(){

bool eliminoInstrumento;
char r;
int id,pos;
Instrumentos instrumento;
ArchivoInstrumentos aInstrumentos(ArchivoInstrumentosString);

cout<<"Ingrese ID del instrumento que desea eliminar: "<<endl;
cin>>id;
pos=verificarIdPos(id);
if(pos==-1) return false;

cout<<"¿Estas seguro que deseas eliminar este registro? (S-s)"<<endl;
cin>>r;
if(r == 's' || r == 'S'){

instrumento = aInstrumentos.leerRegistro(pos);
instrumento.setEstado(false);

eliminoInstrumento = aInstrumentos.modificarRegistroInstrumentos(instrumento,pos);
return eliminoInstrumento;
}

return false;

}


#endif // FUNCIONESINSTRUMENTO_H_INCLUDED
