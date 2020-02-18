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

	string EliminarPL(PilaPL &Pila, string PalabraBuscar, string PalabraReemplazar, bool Estado, string Palabra, int Posicion)
	{
		PilaPL aux = Pila;
		string Res = "";

		if(aux != NULL)
		{
			PalabraBuscar = aux -> PalabraReemplazar;
			PalabraReemplazar = aux -> PalabraBuscar;
			Estado = aux -> Estado;
			Palabra = aux -> Palabra;
			Posicion = aux -> Posicion;

            Res = PalabraBuscar + ";" + PalabraReemplazar;

			Pila = aux -> sgte;

			delete(aux);
		}
		return Res;
	}

	void ReporteBuscadosPL(PilaPL &Pila)
	{
		ofstream Reporte2("Reporte2.dot");
		PilaPL aux = Pila;
		Reporte2<< "digraph G" << endl;
		Reporte2<< "{" << endl;
		Reporte2<< "LogCambios [shape = cds, fontname = Arial, fontcolor = black, style=filled, fillcolor = green]" <<endl;
		Reporte2<< "node [shape = box, fontname = Arial, fontcolor = black, color = green];" <<endl;
		int contador = 0;
		string temp[10000];
		string Same;
		string Estado;
		string Posicion;
		string Asc = "";

		do
		{
			if(aux -> Estado == false)
			{
				Estado = "No Revertido";
			}
			else
			{
				Estado = "Revertido";
			}

			if(aux -> Posicion == -1)
			{
				Posicion = "Null";
			}
			else
			{
				Posicion = aux -> Posicion;
            }

			Reporte2<< "A" << contador << " [label = " <<"\"" << "Palabra Buscar: " << aux -> PalabraBuscar << "\\l" << "Palabra Reemplazar: " << aux -> PalabraReemplazar << "\\l" << "Estado: " << Estado << "\\l"  << "Palabra: " << aux -> Palabra << "\\l"  << "Posicion: " << Posicion << "\\l" <<"\"]" <<endl;
			temp[contador] = "A" + to_string(contador);
			contador++;
			aux = aux -> sgte;
		}
		while(aux != NULL);

		for(int i = 0; i < contador; i++)
		{
			Same = Same + temp[i] + " ";
			if(i < contador - 1)
			{
				Asc = Asc + temp[i] + "->";
			}
			else
			{
				Asc = Asc + temp[i];
			}
		}

		Reporte2<< "{ rank = same " << Same << "}" << endl;
		Reporte2<< Asc <<endl;
		Reporte2<< " " <<endl;
		Reporte2<< "}";
		Reporte2.close();

		//Generar Imagen
		system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng Reporte2.dot -o Reporte2.png");
		//Abrir Imagen
		system("C:\\Usac\\\"Estructuras De Datos\"\\EDD_1S2020_P1_201801628\\Win32\\Debug\\Reporte2.png &" );
	}

