//---------------------------------------------------------------------------

   #pragma hdrstop

//---------------------------------Librerias---------------------------------
   #include <iostream>
   #include <stdio.h>
   #include <conio.h>
   #include <string>
   #include <cstdlib>
   #include <windows.h>
   #include "ListaDobleCaracteres.h"
   using namespace std;

//---------------------------------------------------------------------------
   #pragma package(smart_init)

//---------------------------------M�todos-----------------------------------

   void InsertarLDFinal(ListaLD &Cabeza, ListaLD &Cola, string Caracter)
   {
	  ListaLD aux = new(struct CaracteresLD);
	  aux -> Caracter = Caracter;
	  aux -> sgte = NULL;
	  aux -> ante = NULL;

	  if(Cabeza == NULL)
	  {
		 Cabeza = aux;
		 Cola = aux;
	  }
	  else
	  {
		 Cola -> sgte = aux;
		 aux -> ante = Cola;
		 Cola = aux;
      }

   }

   void Borrar(ListaLD &Cabeza, ListaLD &Cola, string Caracter)
   {
	  ListaLD auxq, auxp = new(struct CaracteresLD);
	  auxq = Cabeza;
	  auxp = Cabeza;
	  while ((auxp != NULL) && (auxp -> Caracter != Caracter))
	  {
		 auxq = auxp;
		 auxp = auxp -> sgte;
	  }

	  if (auxq == NULL)
	  {
		 cout<< "No Existe El Caracter";
	  }

	  else
	  {
		 if(Cabeza == Cola)
		 {
			Cabeza = NULL;
			Cola = NULL;
		 }
		 else
		 {
			auxq -> sgte = auxp -> sgte;
			if(auxp == Cabeza)
			{
			   Cabeza = auxp -> sgte;
			}
			else
			{
			   if(auxp == Cola)
			   {
				  Cola = auxq;
			   }
			}

		 }
	  }
   }

   void BorrarUltimo(ListaLD &Cola)
   {
	  ListaLD aux = new(struct CaracteresLD);

	  aux = Cola;
	  Cola = Cola -> ante;
	  aux -> ante = NULL;
	  Cola -> sgte = NULL;
   }

   void MostrarLD(ListaLD &Cabeza)
   {
	  while(Cabeza != NULL)
	  {
		 cout<< Cabeza -> Caracter;
		 Cabeza = Cabeza -> sgte;
	  }
   }

   void BuscarYRemplazar(ListaLD &Cabeza, ListaLD &Cola, string PalabraB, string PalabraR)
   {
	  ListaLD aux = Cabeza;
	  ListaLD auxE = NULL;
	  string PalabraBuscada = " ";
	  int NumeroE = 0;

	  while(true)
	  {
		 if(Cabeza == NULL)
		 {
			cout<< "Lista Vacia";
			break;
		 }

		 else if(Cabeza -> Caracter == " " && NumeroE == 0)
		 {
			cout<< "Entre Espacio 0";
			auxE = aux;
			NumeroE++;
			aux = aux -> sgte;
		 }

		 else if(aux -> Caracter == " " && NumeroE == 1)
		 {
			cout<< "Entre Al Espacio 1";
			if(PalabraBuscada == PalabraB)
			{
			   for(int i = 0; i <= PalabraR.length(); i++)
			   {
				  char C = PalabraR.at(i);
				  ListaLD auxN = new(struct CaracteresLD);
				  auxN -> Caracter = C;
				  auxE -> sgte = auxN;
				  auxN -> ante = auxE;
				  auxE = auxE -> sgte;
			   }
			   auxE = aux;
			   NumeroE = 1;
			   aux = aux -> sgte;
			}
			else
			{
			   PalabraBuscada += aux -> Caracter;
			   aux = aux -> sgte;
			}
		 }
         //aux = aux -> sgte;
	  }
   }




