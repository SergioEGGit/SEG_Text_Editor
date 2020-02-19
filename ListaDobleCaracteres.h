//------------------------------------------------------------------------------

	#ifndef ListaDobleCaracteresH
	#define ListaDobleCaracteresH
	#include <iostream>
	#include <string>
	#include <cstdlib>
	using namespace std;

//-------------------------------Estructura-------------------------------------

	struct CaracteresLD
	{
		string Caracter = " ";
		struct CaracteresLD *sgte;
		struct CaracteresLD *ante;
	};

	typedef struct CaracteresLD *ListaLDC;

    void InsertarInicioLDC(ListaLDC &Cabeza, ListaLDC &Cola, string Caracter);

	void InsertarFinalLDC(ListaLDC &Cabeza, ListaLDC &Cola, string Caracter);

    int TLDC(ListaLDC &Cabeza);

	void BorrarPrimeroLDC(ListaLDC &Cabeza);

    void BorrarEnmedioLDC(ListaLDC &Cabeza, int Posicion);

	void BorrarUltimoLDC(ListaLDC &Cola);

	string MostrarLDC(ListaLDC &Cabeza, int margenIzquierdo, int margenSuperior, int margenInferior, int margenDerecho);

    void LeerLDC(ListaLDC &Cabeza, int margenIzquierdo, int margenSuperior, int margenInferior, int margenDerecho);

	void ReporteListaLDC(ListaLDC &Cabeza, ListaLDC &Cola);

	void ReemplazarLDC(ListaLDC &Cabeza, ListaLDC &Primero, ListaLDC &Esp2, string PalabraReemplazar);

	int BuscarRLCD(ListaLDC &Cabeza, ListaLDC &Cola, string PalabraReemplazar, string PalabraBuscar);

//------------------------------------------------------------------------------

	#endif

