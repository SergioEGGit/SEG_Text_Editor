//---------------------------------------------------------------------------

	#pragma hdrstop

//---------------------------------Librerias---------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <cstdlib>
	#include <fstream>
	#include <windows.h>
	#include "PilaLog.h"
	using namespace std;

//---------------------------------------------------------------------------

	#pragma package(smart_init)

//---------------------------------M�todos-----------------------------------

	void gotoxy(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void InsertarPL(PilaPL &Pila, string PalabraBuscar, string PalabraReemplazar, bool Estado, string Palabra, int Posicion)
	{
		PilaPL aux = new(struct CambiosPL);

		aux -> PalabraBuscar = PalabraBuscar;
		aux -> PalabraReemplazar = PalabraReemplazar;
		aux -> Estado = Estado;
		aux -> Palabra = Palabra;
		aux -> Posicion = Posicion;

		aux -> sgte = Pila;

		Pila = aux;
	}

	void MostrarPL(PilaPL &Pila)
	{
		PilaPL aux = Pila;

		while(aux != NULL)
		{
			cout<< aux -> PalabraBuscar << endl;
			cout<< aux -> PalabraReemplazar << endl;
			cout<< aux -> Estado << endl;
			cout<< aux -> Palabra << endl;
			cout<< aux -> Posicion << endl;

			aux = aux -> sgte;
		}
    }
