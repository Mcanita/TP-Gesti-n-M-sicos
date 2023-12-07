#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

void CargarAnio();
void Cargar();
void Mostrar();

class Fecha{

private:

    int dia,mes, anio;

public:

   /* Fecha(int d=00, int m=00, int a=0000) //omision
    {
       dia=d;
       mes=m;
       anio=a;
    }*/


    Fecha(){

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    anio = now->tm_year + 1900;
    mes = now->tm_mon + 1;
    dia = now->tm_mday;

    }

    Fecha cargarFechaActual(Fecha fechaActual)
    {

    time_t t = time(nullptr);
    tm* now = localtime(&t);

    fechaActual.anio = now->tm_year + 1900;
    fechaActual.mes = now->tm_mon + 1;
    fechaActual.dia = now->tm_mday;

      return fechaActual;

    }

    void Cargar(){
        cout<<"Ingrese el dia: ";
        cin>>dia;
        while(dia<1 || dia>31){
            cout<<"dia no valido, vuelva a ingresar: ";
            cin>>dia;
        }
        cout<<"Ingrese el mes: ";
        cin>>mes;
        while(mes<1 ||mes>12){
            cout<<"mes no valido, vuelva a ingresar: ";
            cin>>mes;
        }
        cout<<"Ingrese el anio: ";
        cin>>anio;
        while(anio<1500 || anio>2023){
            cout<<"Anio no valido, vuelva a ingresar: ";
            cin>>anio;
        }
    }

    void CargarAnio(){

         cout<<"Ingrese el anio: ";
        cin>>anio;
        while(anio<1500 || anio>2023){
            cout<<"Anio no valido, vuelva a ingresar: ";
            cin>>anio;
        }


    }

    void MostrarAnio(){

    cout<<anio<<endl;

    }


    void Mostrar(){

        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

#endif // FECHA_H_INCLUDED
