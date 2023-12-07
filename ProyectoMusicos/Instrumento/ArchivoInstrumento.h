#ifndef ARCHIVOINSTRUMENTO_H_INCLUDED
#define ARCHIVOINSTRUMENTO_H_INCLUDED

int contarRegistros();
bool agregarInstrumento();
bool modificarRegistroInstrumentos(Instrumentos instrumento, int pos);

class ArchivoInstrumentos
{
private:
    char nombre[30];

public:
    ArchivoInstrumentos (const char* n) {strcpy(nombre,n);}

    Instrumentos leerRegistro(int pos){

       Instrumentos reg;
       FILE *p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Instrumentos)*pos,0);
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
        return tam/sizeof(Instrumentos);
    }

    bool agregarInstrumento(){

    Instrumentos reg;
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return false;

    reg.Cargar();
    fwrite(&reg, sizeof(Instrumentos), 1, p);
    fclose(p);
    return true;

    }

    bool modificarRegistroInstrumentos(Instrumentos instrumento, int pos){

    bool modifico;
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL) return false;

    fseek(p,sizeof(Instrumentos)*pos,0);
    modifico=fwrite(&instrumento, sizeof(Instrumentos), 1, p);

    fclose(p);

    return modifico;


    }

};



#endif // ARCHIVOINSTRUMENTO_H_INCLUDED
