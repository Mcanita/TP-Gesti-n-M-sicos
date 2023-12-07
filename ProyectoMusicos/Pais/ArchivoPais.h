#ifndef ARCHIVOPAIS_H_INCLUDED
#define ARCHIVOPAIS_H_INCLUDED

 int contarRegistros();
 bool agregarPais();
  bool modificarRegistroPaises(Paises pais, int pos);


class ArchivoPaises
{
private:
    char nombre[30];
public:
    ArchivoPaises(const char* n) {strcpy(nombre,n);}

     Paises leerRegistro(int pos){

       Paises reg;
       FILE *p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Paises)*pos,0);
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
        return tam/sizeof(Paises);
    }

    bool agregarPais(){

    Paises reg;
    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return false;

    reg.Cargar();
    fwrite(&reg, sizeof(Paises), 1, p);
    fclose(p);
    return true;

    }

    bool modificarRegistroPaises(Paises pais, int pos){

    bool modificoPais;
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL) return false;

    fseek(p,sizeof(Paises)*pos,0);
    modificoPais=fwrite(&pais, sizeof(Paises), 1, p);

    fclose(p);

    return modificoPais;


    }

};

#endif // ARCHIVOPAIS_H_INCLUDED
