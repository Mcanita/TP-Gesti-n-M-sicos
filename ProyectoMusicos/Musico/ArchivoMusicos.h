#ifndef ARCHIVOMUSICOS_H_INCLUDED
#define ARCHIVOMUSICOS_H_INCLUDED

int contarRegistros();
bool agregarMusico();
bool modificarRegistro(Musico musico, int pos);

class ArchivoMusico
{
private:
    char nombre[30];

public:
    ArchivoMusico (const char* n) {strcpy(nombre,n);}

    Musico leerRegistro(int pos){

       Musico reg;
       FILE *p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Musico)*pos,0);
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
        return tam/sizeof(Musico);
    }

    bool agregarMusico(){ //PUNTO 1

    bool cargo;
    Musico reg;
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return false;

    cargo = reg.Cargar();

    if(cargo){

    fwrite(&reg, sizeof(Musico), 1, p);
    fclose(p);
    return true;

    }

    else return cargo;

    }

    bool modificarRegistro(Musico musico, int pos){

    bool modifico;
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL) return false;

    fseek(p,sizeof(Musico)*pos,0);
    modifico=fwrite(&musico, sizeof(Musico), 1, p);

    fclose(p);

    return modifico;


    }




};

#endif // ARCHIVOMUSICOS_H_INCLUDED
