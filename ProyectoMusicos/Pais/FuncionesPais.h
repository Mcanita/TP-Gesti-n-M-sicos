#ifndef FUNCIONESPAIS_H_INCLUDED
#define FUNCIONESPAIS_H_INCLUDED

int autonumericoIDpais();
int validarPaisOrigen(int po);
bool mostrarPaisXid();
void mostrarArchivoPaises();
bool modificarNombrePais(int id);
bool eliminarRegistroPais();


int autonumericoIDpais()
{
  ArchivoPaises aPaises(ArchivoPaisesString);
  int cantReg=0;

  cantReg = aPaises.contarRegistros();


    if (cantReg == 0) return 1;

    else
    {
        Paises pais;
        pais = aPaises.leerRegistro(cantReg-1);
        return pais.getIdPaises() + 1;
    }
}

int validarPaisOrigen(int po){

while(po< 1 || po>100){

    cout<<"opcion incorrecta"<<endl;
    cout<< "Ingrese el pais de origen (1-100): "<<endl;
    cin>> po;

}

Paises pais;
ArchivoPaises aPaises(ArchivoPaisesString);
int cantReg = aPaises.contarRegistros();

for(int i = 0; i<cantReg; i++){

 pais = aPaises.leerRegistro(i);

 if(pais.getIdPaises() == po && pais.getEstado()) return po;


}

return -1;

}

bool mostrarPaisXid(){

Paises pais;
ArchivoPaises aPaises(ArchivoPaisesString);
int id,pos;

cout<<"Ingrese el id del pais a mostrar: "<<endl;
cin>> id;
lineBreak();
pos=verificarIdPos(id);

if(pos == -1) return false;

pais=aPaises.leerRegistro(pos);
pais.Mostrar();
lineBreak();

return true;

}

void mostrarArchivoPaises(){

Paises pais;
ArchivoPaises aPaises("Paises.dat");
int cantRegP= aPaises.contarRegistros();

for(int i=0; i<cantRegP; i++){

    pais=aPaises.leerRegistro(i);
    pais.Mostrar();
    cout<<endl;
}

}

bool modificarNombrePais(){

Paises pais;
char nombrePaisNuevo[30];
ArchivoPaises aPaises(ArchivoPaisesString);
int id, pos;
bool modificoP;

cout<<"Ingrese el id del pais a modificar el nombre: "<<endl;
cin>>id;
pos=verificarIdPos(id);
if(pos==-1) return false;

pais = aPaises.leerRegistro(pos);
cout<<"Nuevo nombre: "<<endl;
cargarCadena(nombrePaisNuevo,29);
lineBreak();

pais.setNomrePaises(nombrePaisNuevo);
modificoP = aPaises.modificarRegistroPaises(pais,pos);

return modificoP;

}

bool eliminarRegistroPais(){

bool eliminoP;
char r;
int id,pos;
Paises pais;
ArchivoPaises aPaises(ArchivoPaisesString);

cout<<"Ingrese ID del pais a eliminar: "<<endl;
cin>>id;
pos=verificarIdPos(id);
if(pos==-1) return false;

cout<<"¿Estas seguro que deseas eliminar este registro? (S-s)"<<endl;
cin>>r;
if(r == 's' || r == 'S'){

pais = aPaises.leerRegistro(pos);
pais.setEstado(false); //"elimino"

eliminoP = aPaises.modificarRegistroPaises(pais,pos);
return eliminoP;
}

return false;

}

#endif // FUNCIONESPAIS_H_INCLUDED
