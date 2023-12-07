#ifndef ARCHIVOGENERO_H_INCLUDED
#define ARCHIVOGENERO_H_INCLUDED

int contarRegistros();
bool agregarGenero();
bool modificarRegistro(Generos genero, int pos);

class ArchivoGeneros
{

private:

    char nombre[30];

public:

    ArchivoGeneros (const char* n) {strcpy(nombre,n);}

     Generos leerRegistro(int pos){

       Generos reg;
       FILE *p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Generos)*pos,0);
       fread(&reg, sizeof(reg),1,p);
       fclose(p);
       return reg;
   }

   int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Generos);
    }

    bool agregarGenero(){

    Generos reg;
    bool cargo, modifico;

    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return false;

     cargo = reg.Cargar();
     if(cargo)
     {
    modifico = fwrite(&reg, sizeof(Generos), 1, p);
    fclose(p);
    return modifico;

     }

     else return cargo;


    }

    bool modificarRegistro(Generos genero, int pos){

    bool modifico;
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL) return false;

    fseek(p,sizeof(Generos)*pos,0);
    modifico=fwrite(&genero, sizeof(Generos), 1, p);

    fclose(p);

    return modifico;


    }
};

#endif // ARCHIVOGENERO_H_INCLUDED
