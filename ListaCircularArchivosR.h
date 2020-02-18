//------------------------------------------------------------------------------

	#ifndef ListaCircularArchivosRH
	#define ListaCircularArchivosRH
	#include <iostream>
	#include <string>
	#include <cstdlib>
	using namespace std;

//-------------------------------Estructura-------------------------------------

	struct ArchivosRecientesLC
	{
		string Nombre;
		string Ruta;
		struct ArchivosRecientesLC *sgte;
	};

	typedef struct ArchivosRecientesLC *ListaCAR;

	void InsertarInicioLCAR(ListaCAR &listaCAR, ListaCAR &Final, string Nombre, string Ruta);

	bool BuscarLCAR(ListaCAR &listaCAR, ListaCAR &Final, string Ruta);

	void MostrarLCAR(ListaCAR &listaCAR, int margenDerecho, int margenInferior);

	void ReporteArchivosLCAR(ListaCAR &listaCAR, ListaCAR &Final);

    string BuscarARLCAR(ListaCAR &listaCAR, ListaCAR &Final, string Posicion);

//------------------------------------------------------------------------------

	#endif
