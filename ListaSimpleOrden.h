//------------------------------------------------------------------------------

	#ifndef ListaSimpleOrdenH
	#define ListaSimpleOrdenH
	#include <iostream>
	#include <string>
	#include <cstdlib>
    #include <PilaLog.h>
	using namespace std;

//-------------------------------Estructura-------------------------------------

	struct OrdenLS
	{
		string PalabraBuscar;
		string PalabraReemplazar;
		struct OrdenLS *sgte;
	};

	typedef struct OrdenLS *ListaLSO;

    void InsertarFinalLS(ListaLSO &listaLSO, string PalabraBuscar, string PalabraReemplazar);

	int PilaTa(PilaPL &Pila);

	void ReporteLS1(ListaLSO &listaLSO, PilaPL &Pila);

	void ReporteOrdenLS(ListaLSO &listaLSO, PilaPL &Pila);

//------------------------------------------------------------------------------

	#endif
