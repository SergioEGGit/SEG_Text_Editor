#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

//---------------------------------Librerias------------------------------------
   #include <iostream>
   #include <stdio.h>
   #include <conio.h>
   #include <string>
   #include <windows.h>
   using namespace std;

//----------------------------------Variables-----------------------------------

   int Alto = 0;
   int Ancho = 0;

//------------------------------------M�todos-----------------------------------

      //---------------------------------Men�-------------------------------

		void Menu()
		{
			cout<<"\n\t\tPractica 1\n\n";
			cout<<" 1. Crear Archivo                     "<<endl;
			cout<<" 2. Abrir Archivo                     "<<endl;
			cout<<" 3. Archivos Recientes                "<<endl;
			cout<<" 4. Salir                             "<<endl;

			cout<<"\n Ingrese El Numero De La Opcion A Elegir: ";
		}

	 //-------------------------------Marcos-------------------------------

		  void MarcoMenu ()
		  {
			 int i;

			 //Linea Horizontal Superior
			 for (i = 2; i < Ancho; i++)
			 {
				gotoxy(i, 2);
				if(i < Ancho - 1)
				{
				   printf("%c", 205);
				}
				else
				{
				   printf("%c", 187);
				}
			 }

			 //Linea Horizontal Inferior
			 for (i = 2; i < Ancho; i++)
			 {
				gotoxy(i, Alto);
				if(i < Ancho - 1)
				{
				   printf("%c", 205);
				}
				else
				{
				   printf("%c", 188);
				}
			 }

			 /*//Linea Vertical Derecha
			 for(int z = 0; z < Alto - 3; z++)
			 {
				for(i = 2; i < Ancho - 1; i++)
				{
				   gotoxy(i + 1, z + 3);
				   if(i < Ancho - 2)
				   {
					  printf("%c", 32);
				   }
				   else
				   {
					  printf("%c", 186);
				   }
				}
			 } */

			 //Linea Vertical Izquierda
			 for (i = 3; i < Alto; i++)
			 {
				gotoxy(2, i);
				printf("%c", 186);
			 }

			 //Esquina Superior Izquierda
			 gotoxy(2, 2);
			 printf("%c", 201);

			 //Esquina Inferior Izquierda
			 gotoxy(2, Alto);
			 printf("%c", 200);
		 }

		  void MarcoPrincipal()
		  {
			 int i;

			 //Linea Horizontal Superior
			 for (i = 2; i < Ancho; i++)
			 {
				gotoxy(i, 2);
				if(i < Ancho - 1)
				{
				   printf("%c", 205);
				}
				else
				{
				   printf("%c", 187);
				}
			 }

			 //Linea Horizontal Inferior
			 for (i = 2; i < Ancho; i++)
			 {
				gotoxy(i, Alto);
				if(i < Ancho - 1)
				{
				   printf("%c", 205);
				}
				else
				{
				   printf("%c", 188);
				}
			 }

			 //Linea Vertical Derecha
			 for(int z = 0; z < Alto - 3; z++)
			 {
				for(i = 2; i < Ancho - 1; i++)
				{
				   gotoxy(i + 1, z + 3);
				   if(i < Ancho - 2)
				   {
					  printf("%c", 32);
				   }
				   else
				   {
					  printf("%c", 186);
				   }
				}
			 }

			 //Linea Vertical Izquierda
			 for (i = 3; i < Alto; i++)
			 {
				gotoxy(2, i);
				printf("%c", 186);
			 }

			 //Esquina Superior Izquierda
			 gotoxy(2, 2);
			 printf("%c", 201);

			 //Esquina Inferior Izquierda
			 gotoxy(2, Alto);
			 printf("%c", 200);

			 //Divisi�n, Texto En Pantalla
			 for (i = 2; i < Ancho; i++)
			 {
				gotoxy(i, Alto - 4);
				if(i < Ancho - 1)
				{
				   printf("%c", 205);
				}
				else
				{
				   printf("%c", 185);
				}
			 }

			 //T Divisi�n
			 gotoxy(2, Alto - 4);
			 printf("%c", 204);

			 //Texto Buscar Y Remplazar
			 gotoxy(25, Alto - 2); cout<< "^w (Buscar Y Remplazar)";
			 gotoxy(80, Alto - 2); cout<< "^c (Reportes)";
			 gotoxy(120, Alto - 2); cout<< "^s (Guardar)";

			 //Generar �rea De Trabajo


			 getchar();
		  }

	 //-----------------------------Fullscreen-----------------------------

		void Fullscreen()
		{
		   keybd_event(VK_MENU,
						  0x38,
							 0,
							 0);
		   keybd_event(VK_RETURN,
							0x1c,
							   0,
							   0);
		   keybd_event(VK_RETURN,
							0x1c,
				 KEYEVENTF_KEYUP,
							   0);
		   keybd_event(VK_MENU,
						  0x38,
			   KEYEVENTF_KEYUP,
							 0);
		   return;
		}

	 //---------------------Obtener Resoluci�n Pantalla--------------------

		void Resolucion()
		{
			Ancho = (GetSystemMetrics(SM_CXSCREEN) / 8) - 2;
			Alto = (GetSystemMetrics(SM_CYSCREEN) / 19) + 1;
		}

	 //------------------------Posici�n Cursor-----------------------------



		void gotoxy(int x, int y)
		{
		   COORD coord;
		   coord.X = x;
		   coord.Y = y;
		   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		}

		void MarcoMenu(int Col1, int Col2, int Fil1, int Fil2)
		{
		   for (int Cols = Col1; Cols <= Col2; Cols++)
		   {
			  for (int Fils = Fil1; Fils <= Fil2; Fils++)
			  {
				 gotoxy(Cols,Fils);
				 //Linea Vertical Derecha E Izquierda
				 if ((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
				 {
					cout << (char)186;
				 }
				 //Linea Horizontal Superior E Inferior
				 else if ((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
				 {
					cout << (char)205;
				 }
			  }
		   }

		   //Esquina Superior Izquierda
		   gotoxy(Col1,Fil1);
		   cout << (char)201;
		   //Esquina Inferior Izquierda
		   gotoxy(Col1,Fil2);
		   cout << (char)200;
		   //Esquina Superior Derecha
		   gotoxy(Col2,Fil1);
		   cout << (char)187;
		   //Esquina Inferior Derecha
		   gotoxy(Col2,Fil2);
		   cout << (char)188;
		   getchar();
		}

		void MarcoPrincipal(int Col1, int Col2, int Fil1, int Fil2)
		{
		   for (int Cols = Col1; Cols <= Col2; Cols++)
		   {
			  for (int Fils = Fil1; Fils <= Fil2; Fils++)
			  {
				 gotoxy(Cols,Fils);
				 //Linea Vertical Derecha E Izquierda
				 if ((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
				 {
					cout << (char)186;
				 }
				 //Linea Horizontal Superior E Inferior
				 else if ((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
				 {
					cout << (char)205;
				 }
				 else if ((Cols != Col1) && (Fils == Fil2 - 4))
				 {
					cout << (char)205;
				 }

			  }
		   }

		   //Esquina Superior Izquierda
		   gotoxy(Col1,Fil1);
		   cout << (char)201;
		   //Esquina Inferior Izquierda
		   gotoxy(Col1,Fil2);
		   cout << (char)200;
		   //Esquina Superior Derecha
		   gotoxy(Col2,Fil1);
		   cout << (char)187;
		   //Esquina Inferior Derecha
		   gotoxy(Col2,Fil2);
		   cout << (char)188;
		   //T Derecha
		   gotoxy(Col2,Fil2 - 4);
		   cout << (char)185;
		   //T Izquierda
		   gotoxy(Col1,Fil2 - 4);
		   cout << (char)204;

		   //Textos
		   gotoxy(Col1 + 40,Fil2 - 2);
		   cout << "^w (Buscar Y Remplazar)";
		   gotoxy(Col1 + 80,Fil2 - 2);
		   cout << "^c (Reportes)";
		   gotoxy(Col1 + 110,Fil2 - 2);
		   cout << "^s (Guardar)";
		}



//-------------------------------------Main-------------------------------------
	 int _tmain(int argc, _TCHAR* argv[])
	 {
		Fullscreen();
		Resolucion();
		system("color 0b");
		clrscr();
		int Op = 0;
		MarcoMenu(0,Ancho - 2,0,Alto + 6);

		//Menu(); cin>> Op;

		do
		{

		   switch(Op)
		   {
			  case 1:
				 clrscr();
				 MarcoPrincipal();
			  break;

			  case 2:
				 cout<< "Opcion 1" << endl;
				 system("Pause > NULL");
			  break;

			  case 3:
				 cout<< "Opcion 1" << endl;
				 system("Pause > NULL");
			  break;
		   }
           cout<<endl<<endl;
		   system("cls");
		}

		while(Op != 4);
		cout<< "\n";
		cout<< "\n";
		cout<< "Aplicacion Finalizada";
		cout<< "\n";
		cout<< "\n";
		system("pause");

		return 0;
	 }




