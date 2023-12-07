#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

bool backUpMusicos();
bool restaurarMusicos();
bool backUpGeneros();
bool restaurarGeneros();
void menuConfiguracion();


/*bool establecerDatosDeInicioDATaINI(){ //DAT => INI.

Generos genero;
Musicos musico;
Instrumentos instrumento;
Paises pais;

ArchivoGeneros aGeneros(ArchivoGenerosString);
ArchivoMusicos aMusicos(ArchivoMusicosString);
ArchivoInstrumentos aInstrumentos(ArchivoInstrumentosString);
ArchivoPaises aPaises(ArchivoPaisesString);

int cantRegM = aMusicos.contarRegistros();
int cantRegG = aGeneros.contarRegistros();
int cantRegI = aInstrumentos.contarRegistros();
int cantRegP = aPaises.contarRegistros();

FILE *m,*g,*i,*p;

m = fopen("Musicos.ini", "wb");
g = fopen("Generos.ini","wb");
i = fopen("Instrumentos.ini", "wb");
p = fopen("Paises.ini", "wb");

if(m == NULL || g == NULL || i == NULL || p == NULL) return false;


for(int i = 0; i<cantRegM; i++){

   musico = aMusicos.leerRegistro(i);
   if(musico.getEstado()){}
   fwrite(&musico, sizeof musico, 1,m);

}

for(int i = 0; i<cantRegG; i++){

    genero = aGeneros.leerRegistro(i);
    fwrite(&genero, sizeof genero, 1,g);

}

for(int j = 0; j<cantRegI; j++){

    instrumento = aInstrumentos.leerRegistro(j);
    fwrite(&instrumento, sizeof instrumento,1,i);

}

for(int i = 0; i<cantRegP; i++){

    pais = aPaises.leerRegistro(i);
    fwrite(&pais, sizeof pais,1,p);

}

 fclose(m);
  fclose(g);
   fclose(i);
    fclose(p);

    return true;

}

*/

bool establecerDatosDeInicio(){

Generos genero;
Musico musico;
Instrumentos instrumento;
Paises pais;

ArchivoGeneros aGeneros("Generos.ini");
ArchivoMusico aMusicos("Musicos.ini");
ArchivoInstrumentos aInstrumentos("Instrumentos.ini");
ArchivoPaises aPaises("Paises.ini");

int cantRegM = aMusicos.contarRegistros();
int cantRegG = aGeneros.contarRegistros();
int cantRegI = aInstrumentos.contarRegistros();
int cantRegP = aPaises.contarRegistros();

FILE *m,*g,*i,*p;


m = fopen(ArchivoMusicosString, "wb");
g = fopen(ArchivoGenerosString,"wb");
i = fopen(ArchivoInstrumentosString,"wb");
p = fopen(ArchivoPaisesString,"wb");

if(m == NULL || g == NULL || i == NULL || p == NULL) return false;

char r;

cout<<"---ESTABLECER DATOS DE INICIO---"<<endl;
cout<<"¿Desea continuar? (s-S) / otra tecla para cancelar"<<endl;
cin>>r;

if(r == 's' || r == 'S'){



for(int i = 0; i<cantRegM; i++){

   musico = aMusicos.leerRegistro(i);
   fwrite(&musico, sizeof musico, 1,m);

}

for(int i = 0; i<cantRegG; i++){

    genero = aGeneros.leerRegistro(i);
    fwrite(&genero, sizeof genero, 1,g);

}

for(int j = 0; j<cantRegI; j++){

    instrumento = aInstrumentos.leerRegistro(j);
    fwrite(&instrumento, sizeof instrumento,1,i);

}

for(int i = 0; i<cantRegP; i++){

    pais = aPaises.leerRegistro(i);
    fwrite(&pais, sizeof pais,1,p);

}

 fclose(m);
  fclose(g);
   fclose(i);
    fclose(p);
  return true;
}



return false;

}



bool backUpMusicos(){

Musico musico;
ArchivoMusico aMusico(ArchivoMusicosString);
int cantReg = aMusico.contarRegistros();

FILE *p;
char r;

cout<<"---COPIA DE SEGURIDAD ARCHIVO MUSICOS---"<<endl;
cout<<"¿Desea continuar? (s-S) / otra tecla para cancelar"<<endl;
cin>>r;

if(r == 's' || r == 'S'){

p= fopen("Musicos.bkp", "wb");
if(p == NULL) return false;


for(int i = 0; i<cantReg; i++){

   musico = aMusico.leerRegistro(i); //Musicos.dat
   fwrite(&musico, sizeof musico, 1, p);

}

 fclose(p);
 return true;

}

else return false;

}

bool restaurarMusicos(){

Musico musico;
ArchivoMusico aMusico(ArchivoMusicosString);
//int cantReg = aMusico.contarRegistros();

FILE *aBack, *aDat;
char r;

cout<<"---RESTAURAR ARCHIVO MUSICOS---"<<endl;
cout<<"¿Desea continuar? (s-S) / otra tecla para cancelar"<<endl;
cin>>r;

if(r == 's' || r == 'S'){

aBack = fopen("Musicos.bkp","rb");
aDat = fopen(ArchivoMusicosString, "wb");

if(aBack == NULL || aDat == NULL) return false;


while(fread(&musico, sizeof(Musico),1,aBack) == 1) fwrite(&musico, sizeof musico, 1, aDat);

fclose(aBack);
fclose(aDat);

return true;

}

else return false;

}

bool backUpGeneros(){

Generos genero;
ArchivoGeneros aGeneros(ArchivoGenerosString);
int cantReg = aGeneros.contarRegistros();

FILE *p;
char r;

cout<<"---COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS---"<<endl;
cout<<"¿Desea continuar? (s-S) / otra tecla para cancelar"<<endl;
cin>>r;

if(r == 's' || r == 'S'){

p= fopen("Generos.bkp", "wb");
if(p == NULL) return false;


for(int i = 0; i<cantReg; i++){

   genero = aGeneros.leerRegistro(i); //Musicos.dat
   fwrite(&genero, sizeof genero, 1, p);

}

 fclose(p);
 return true;

}

else return false;

}

bool restaurarGeneros(){

Generos genero;
ArchivoGeneros aGeneros(ArchivoGenerosString);
//int cantReg = aGeneros.contarRegistros();

FILE *aBack, *aDat;
char r;

cout<<"---RESTAURAR EL ARCHIVO DE GÉNEROS---"<<endl;
cout<<"¿Desea continuar? (s-S) / otra tecla para cancelar"<<endl;
cin>>r;

if(r == 's' || r == 'S'){

aBack = fopen("Generos.bkp","rb");
aDat = fopen(ArchivoGenerosString, "wb");

if(aBack == NULL || aDat == NULL) return false;


while(fread(&genero, sizeof(Generos),1,aBack) == 1) fwrite(&genero, sizeof genero, 1, aDat);

fclose(aBack);
fclose(aDat);

return true;

}

else return false;

}

#endif // CONFIGURACION_H_INCLUDED
