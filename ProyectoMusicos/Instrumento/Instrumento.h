#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

int autonumericoIDinstrumento();

class Instrumentos
{
private:
    int idInstrumento;
    char nombreInstrumento [30];
    int clasificacion;
    bool estado;

public:

    Instrumentos (int idI=0, const char* nomI="0", int clas=0){
    idInstrumento=idI;
    strcpy(nombreInstrumento,nomI);
    clasificacion=clas;
    }

    bool Cargar();
    void Mostrar();

    ///setter
    void setIdInstrumento(int idI){
    idInstrumento=idI;
    }
    void setNomreInstrumento(const char* nomI){
        strcpy(nombreInstrumento,nomI);
    }
    void setClasificacion(int clas){
        clasificacion=clas;
    }
    void setEstado(bool e){
        estado=e;
    }
    ///getters
    int getIdInstrumento()
    {
        return idInstrumento;
    }
    const char* getNombreInstrumento()
    {
        return nombreInstrumento;
    }
    int getClasificacion()
    {
        return clasificacion;
    }
    bool getEstado()
    {
        return estado;
    }
};

bool Instrumentos::Cargar()
{
    idInstrumento = autonumericoIDinstrumento();

    cout<< "id del instrumento : "<<idInstrumento<<endl;

    cout<< "Ingrese el nombre del instrumento : "<<endl;
    cargarCadena(nombreInstrumento,29);
    cout<< "Ingrese la clasificación del instrumento: "<<endl;
    cin>> clasificacion;
    estado=true;
    return true;
}

void Instrumentos::Mostrar()
{
if(this->getEstado())
{
cout<<"Id del instrumento : ";
cout<<idInstrumento<<endl;
cout<<"Nombre del instrumento : ";
cout<<nombreInstrumento<<endl;
cout<<"Clasificación del instrumento :";
cout<<clasificacion<<endl;

}

}

#endif // INSTRUMENTO_H_INCLUDED
