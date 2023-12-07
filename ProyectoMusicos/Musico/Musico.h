#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

bool verificarDNI(int dni);
int validarInstrumentoPrincipal(int ip);
int validarTipoDeMusica(int tm);

class Musico
{
private:
    int dni;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro;
    int instrumentoPrincipal;
    int tipoDeMusica;
    Fecha fechaInscripcion;
    float matricula;
    bool estado;

public:///constructor

    Musico (int d =0, const char* n= "0", const char* a="0", const char* em="0", const char* t="0", int cla=0, int ip=0, int tm= 0, float m=0 ) {
        dni=d;
        strcpy(nombre,n);
        strcpy(apellido,a);
        strcpy(email,em);
        strcpy(telefono,t);
        claustro=cla;
        instrumentoPrincipal=ip;
        tipoDeMusica=tm;
        matricula=m;
    }

    bool Cargar();
    void Mostrar();


///setter

     void setDni(int d){
         dni=d;
    }
     void setNombre(const char* n){
        strcpy(nombre,n);
    }
     void setApellido(const char* a){
        strcpy(apellido,a);
    }
     void setEmail(const char* em){
        strcpy(email,em);
    }
     void setTelefono(const char* t){
        strcpy(telefono,t);
    }
    void setClaustro(int cla){
         claustro=cla;
    }
    void setInstrumentoPrincipal(int ip){
         instrumentoPrincipal=ip;
    }
    void setTipoDeMusica(int tm){
         tipoDeMusica=tm;
    }
    void setFechaInscripcion(Fecha f){
        fechaInscripcion=f;
    }
    void setMatricula(int m){
         matricula=m;
    }
    void setEstado(bool e){
         estado=e;
    }

///getter
    int getDni()
    {
        return dni;
    }
    const char* getNombre()
    {
        return nombre;
    }
    const char* getApellido()
    {
        return apellido;
    }
    const char* getEmail()
    {
        return email;
    }
    const char* getTelefono()
    {
        return telefono;
    }
    int getClaustro()
    {
        return claustro;
    }
    int getInstrumentoPrincipal()
    {
        return instrumentoPrincipal;
    }
    int getTipoDeMusica()
    {
        return tipoDeMusica;
    }
    Fecha getFechaInscripcion()
    {
        return fechaInscripcion;
    }
    float getMatricula()
    {
        return matricula;
    }
    bool getEstado()
    {
        return estado;
    }

    //sobreCarga => van dentro de la clase.

    bool operator == (Musico &musico){ //2 objetos musicos iguales con respecto al nombre. & SOLO PARA OBJETOS.
        if(strcmp(nombre,musico.getNombre()) == 0) return true;
        else return false;
    }

   /* bool operator == (Musicos &musico){ //2 objetos musicos iguales con respecto a la edad. & SOLO PARA OBJETOS.
        if(edad == musico.getedad()) return true;
        else return false;
    }*/


    bool operator > (Musico &musico){ //obj musico > obj musico => compara nombres.
      if(strlen(nombre) > strlen(musico.getNombre())) return true;
      else return false;

    }

     bool operator == (const char* nombreAux){ //1 obj musicos y 1 cadena iguales con respecto al nombre.
        if(strcmp(nombre,nombreAux) == 0) return true;
        else return false;
    }


    bool operator >= (int value){ //objeto  >= entero

        if(strlen(nombre) >= value) return true;
        else return false;

    }

};

bool Musico::Cargar()
{
    bool verifico;
    int valido,validoTM;

    cout<< "Ingrese el número de DNI : "<<endl;
    cin>> dni;

    verifico=verificarDNI(dni);
    while(verifico){
        cout<< "El DNI ya está registrado - ingrese nuevamente "<<endl;
        cin>>dni;
        verifico = verificarDNI(dni);
    }

    cout<< "Ingrese el nombre : "<<endl;
    cargarCadena(nombre,29);
    cout<< "Ingrese el apellido : "<<endl;
    cargarCadena(apellido,29);
    cout<< "Ingrese el email : "<<endl;
    cargarCadena(email,29);
    cout<< "Ingrese el numero de telefono : "<<endl;
    cargarCadena(telefono,29);
    cout<< "Ingrese el numero de claustro (1-4) : "<<endl;
    cin>> claustro;
    while(claustro<1 || claustro>4){
        cout<<"opcion incorrecta "<<endl;
        cout<< "Ingrese el numero de claustro (1-4) : "<<endl;
        cin>> claustro;
    }
    cout<< "Ingrese el numero del instrumento (1-15) : "<<endl;
    cin>> instrumentoPrincipal;
    valido = validarInstrumentoPrincipal(instrumentoPrincipal);
    if(valido != -1){

    cout<< "Ingrese el tipo de musica (1-10) : "<<endl;
    cin>> tipoDeMusica;
    validoTM = validarTipoDeMusica(tipoDeMusica);
    if(validoTM != -1){

    fechaInscripcion.cargarFechaActual(fechaInscripcion);
    cout<<endl;

    cout<< "Ingrese el valor de la matricula : "<<endl;
    cin>> matricula;
    while(matricula<0){
        cout<<" error de ingreso ($>0) "<<endl;
        cout<< "Ingrese el valor de la matricula : "<<endl;
        cin>> matricula;
    }

    estado=true;
    return true;

    }

    else{

     cout<<"El instrumento ingresado no se encuentra registrado"<<endl;
     system("pause");
     return false;
    }

    }
     else{

     cout<<"El tipo de musica ingresado no se encuentra registrado"<<endl;
     system("pause");
     return false;

    }

}

void Musico::Mostrar()
{
if(this->getEstado()) //no olvidar
{
cout<<"Numero de DNI : ";
cout<<dni<<endl;
cout<<"Nombre : ";
cout<<nombre<<endl;
cout<<"Apellido :";
cout<<apellido<<endl;
cout<<"Email : ";
cout<<email<<endl;
cout<<"Telefono : ";
cout<<telefono<<endl;
cout<<"Claustro : ";
cout<<claustro<<endl;
cout<<"Instrumento principal : ";
cout<<instrumentoPrincipal<<endl;
cout<<"Tipo de musica : ";
cout<<tipoDeMusica<<endl;
cout<<"Fecha de inscripcion : ";
fechaInscripcion.Mostrar();
cout<<"Matricula : ";
cout<< matricula<<endl;

}



}

#endif // MUSICO_H_INCLUDED
