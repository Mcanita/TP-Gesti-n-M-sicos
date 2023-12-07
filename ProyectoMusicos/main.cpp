#include <iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include <ctime>
#include <string>
#include "windows.h"

using namespace std;

const char* ArchivoMusicosString = "Musicos.dat";
const char* ArchivoGenerosString = "Generos.dat";
const char* ArchivoInstrumentosString = "Instrumentos.dat";
const char* ArchivoPaisesString = "Paises.dat";

#include "rlutil.h"
#include "FuncionesGlobales.h"
#include "Fecha.h"
#include "Musico/Musico.h"
#include "Musico/ArchivoMusicos.h"
#include "Musico/FuncionesMusico.h"
#include "Genero/Genero.h"
#include "Genero/ArchivoGenero.h"
#include "Genero/FuncionesGenero.h"
#include "Instrumento/Instrumento.h"
#include "Instrumento/ArchivoInstrumento.h"
#include "Instrumento/FuncionesInstrumento.h"
#include "Pais/Pais.h"
#include "Pais/ArchivoPais.h"
#include "Pais/FuncionesPais.h"
#include "Reportes.h"
#include "Configuracion.h"
#include "Menu.h"

int main()
{
    // setlocale(LC_ALL,"spanish");

  /*Generos genero;
  ArchivoGeneros aGeneros(ArchivoGenerosString);
  genero = aGeneros.leerRegistro(1);
  genero.setNombre("Clasica");
  aGeneros.modificarRegistro(genero, 1);

  genero = aGeneros.leerRegistro(3);
  genero.setNombre("Melodica");
  aGeneros.modificarRegistro(genero, 3);*/

  menuPrincipal();

    return 0;
}
