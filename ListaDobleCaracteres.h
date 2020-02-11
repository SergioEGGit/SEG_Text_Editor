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
	  string Caracter;
	  struct CaracteresLD *sgte;
	  struct CaracteresLD *ante;
   };

   typedef struct CaracteresLD *ListaLD;

   void InsertarLDFinal(ListaLD &Cabeza, ListaLD &Cola, string Caracter);

   void Borrar(ListaLD &Cabeza, ListaLD &Cola, string Caracter);

   void BorrarUltimo(ListaLD &Cola);

   void MostrarLD(ListaLD &Cabeza);

   void BuscarYRemplazar(ListaLD &Cabeza, ListaLD &Cola, string PalabraB, string PalabraR);

//------------------------------------------------------------------------------
   #endif

