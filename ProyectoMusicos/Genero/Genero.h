#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

int autonumericoID();
int validarPaisOrigen(int po);


class Generos
{
private:
    int idGenero;
    char nombre[30];
    int paisOrigen;
    Fecha anioOrigen; ///preguntar por año, es fecha
    bool estado;

public:///constructor
    Generos(int id=0, const char* n="0", int po=0){
        idGenero=id;
        strcpy(nombre,n);
        paisOrigen=po;
        ///anioOrigen=ao;
    }

    bool Cargar();
    void Mostrar();

    ///setters
     void setIdGenero(int id){
         idGenero=id;
    }
     void setNombre(const char* n){
         strcpy(nombre,n);
    }
     void setPaisOrigen(int po){
         paisOrigen=po;
    }
     void setAnioOrigen(Fecha ao){
         anioOrigen=ao;
    }
     void setEstado(bool e){
         estado=e;
    }

    ///getters
     int getIdGenero(){
         return idGenero;
    }
      const char* getNombre(){
         return nombre;
    }
     int getPaisOrigen(){
         return paisOrigen;
    }
     Fecha getAnioOrigen(){
         return anioOrigen;
    }
     bool getEstado(){
         return estado;
    }

};


bool Generos::Cargar()
{
    idGenero = autonumericoID();
    int valido;

    cout<<"ID Género "<< idGenero <<endl;
    cout<< "Ingrese el nombre : "<<endl;
    cargarCadena(nombre,29);
    cout<< "Ingrese el pais de origen : "<<endl;
    cin>> paisOrigen;
   valido = validarPaisOrigen(paisOrigen);
   if(valido != -1){

    cout<< "Ingrese el año de origen : "<<endl;
    anioOrigen.CargarAnio();

    /*while(anioOrigen<1500 || anioOrigen>2023){
        cout<<" error de ingreso (1500-2023) "<<endl;
        cout<< "Ingrese el año de origen nuevamente : "<<endl;
        cin>> anioOrigen;
    }*/

    estado=true;
    return true;


   }

   else
   {
    cout<<"El país no está registrado"<<endl;
    system("pause");
    return false;
       }




}

void Generos::Mostrar()
{

if(this->getEstado())
{
cout<<"ID del género musical : ";
cout<<idGenero<<endl;
cout<<"Nombre : ";
cout<<nombre<<endl;
cout<<"País de origen :";
cout<<paisOrigen <<endl;
cout<<"Año de origen : ";
anioOrigen.MostrarAnio();
}

}


#endif // GENERO_H_INCLUDED
