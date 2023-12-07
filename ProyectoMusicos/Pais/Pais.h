#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

int autonumericoIDpais();

class Paises
{
private:
    int idPaises;
    char nombrePaises [30];
    char continente[30];
    bool estado;

public:

    Paises(int idP=0, const char* nomP="0", const char* cont="0"){
    idPaises=idP;
    strcpy(nombrePaises,nomP);
    strcpy(continente,cont);
    }

    bool Cargar();
    void Mostrar();

    ///setter
    void setIdPaises(int idP){
    idPaises=idP;
    }
    void setNomrePaises(const char* nomP){
        strcpy(nombrePaises,nomP);
    }
    void setContinente(const char* cont){
        strcpy(continente,cont);
    }
    void setEstado(bool e){
        estado=e;
    }
    ///getters
    int getIdPaises()
    {
        return idPaises;
    }
    const char* getNombrePaises()
    {
        return nombrePaises;
    }
    const char* getContinente()
    {
        return continente;
    }
    bool getEstado()
    {
        return estado;
    }
};

bool Paises::Cargar()
{
    idPaises=autonumericoIDpais();
    cout<< "ID del pais : "<<idPaises<<endl;
    cout<< "Ingrese el nombre del pais : "<<endl;
    cargarCadena(nombrePaises,29);
    cout<< "Ingrese el continente al que pertenece: "<<endl;
    cargarCadena(continente,29);

    estado=true;
    return true;
}

void Paises::Mostrar()
{
if(this->getEstado())
{
cout<<"Id del pais: ";
cout<<idPaises<<endl;
cout<<"Nombre del pais : ";
cout<<nombrePaises<<endl;
cout<<"Continente al que pertenece :";
cout<<continente<<endl;

}

}

#endif // PAIS_H_INCLUDED
