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
   #include <ListaDobleCaracteres.h>
   using namespace std;

//----------------------------------Variables-----------------------------------

   int Alto = 0;
   int Ancho = 0;
   int Opcion;

//------------------------------------M�todos-----------------------------------

	 //---------------------------------Men�-------------------------------

		void menu()
		{
		   //Informaci�n
		   gotoxy ((Ancho - 2)/2 - 20, 2);
		   cout<< "Universidad De San Carlos De Guatemala" <<endl;
		   gotoxy ((Ancho - 2)/2 - 12, 4);
		   cout<< "Facultad De Ingenieria" <<endl;
		   gotoxy ((Ancho - 2)/2 - 11, 6);
		   cout<< "Estructuras De Datos" <<endl;
		   gotoxy ((Ancho - 2)/2 - 6, 8);
		   cout<< "Practica 1" <<endl;
		   gotoxy ((Ancho - 2)/2 - 17, 10);
		   cout<< "Sergio Alexander Echigoyen Gomez" <<endl;
		   gotoxy ((Ancho - 2)/2 - 6, 12);
		   cout<< "201801628" <<endl;

		   //Men�
		   gotoxy ((Ancho - 2)/2 - 4, 20);
		   cout<< "Menu" <<endl;
		   gotoxy ((Ancho - 2)/2 - 11, 22);
		   cout<< "1. Crear Archivo" <<endl;
		   gotoxy ((Ancho - 2)/2 - 11, 24);
		   cout<< "2. Abrir Archivo" <<endl;
		   gotoxy ((Ancho - 2)/2 - 11, 26);
		   cout<< "3. Archivos Recientes" <<endl;
		   gotoxy ((Ancho - 2)/2 - 11, 28);
		   cout<< "4. Salir" <<endl;
		   gotoxy ((Ancho - 2)/2 - 11, 30);
		   cout<< "Elija Una Opcion: " <<endl;
		   gotoxy ((Ancho - 2)/2 + 8, 30);
		   cin>> Opcion;
		}

	 //-------------------------------Marcos-------------------------------

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

		   menu();
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
				 //Status Bar
				 else if ((Cols != Col1) && (Fils == Fil2 - 4))
				 {
					cout << (char)205;
				 }
				 //Barra De T�tulo
				 else if ((Cols != Col1) && (Fils == Fil1 + 2))
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
		   //T Derecha Status Bar
		   gotoxy(Col2,Fil2 - 4);
		   cout << (char)185;
		   //T Izquierda Status Bar
		   gotoxy(Col1,Fil2 - 4);
		   cout << (char)204;
		   //T Derecha Barra De T�tulo
		   gotoxy(Col2,Fil1 + 2);
		   cout << (char)185;
		   //T Derecha Barra De T�tulo
		   gotoxy(Col1,Fil1 + 2);
		   cout << (char)204;


		   //Textos
		   gotoxy(Col1 + 40,Fil2 - 2);
		   cout << "^w (Buscar Y Remplazar)";
		   gotoxy(Col1 + 80,Fil2 - 2);
		   cout << "^c (Reportes)";
		   gotoxy(Col1 + 110,Fil2 - 2);
		   cout << "^s (Guardar)";
		   gotoxy(Col1 + 75,Fil1 + 1);
		   cout << "Editor De Texto SEG";
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

	 //------------------------------Editor--------------------------------

		void Coordenada(int x, int y)
		{
		   gotoxy(150, 45);
		   cout<< "           ";
		   gotoxy(150, 45);
		   cout<< "C: " << y << " F: " << x;
		}

		bool Editor()
		{
		   int C = 0;
		   int Col = 1;
		   int Fil = 1;
		   char str[1000];

		   Coordenada(Fil, Col);

		   //Fijar Cursor
		   gotoxy(3,4);

		   do
		   {

			  if(Fil <= 36)
			  {
				 gotoxy(Col + 4, Fil + 3);
			  }
			  if(Fil == 37)
			  {
				 gotoxy(Col + 5, Fil + 3);
			  }
			  C = getche();
			  //cout<< C;
			  if(Fil <= 36)
			  {
				 str[Col] = C;
			  }
			  if(Fil == 37)
			  {
				 str[Col + 1] = C;
			  }

			  Col++;

			  switch(C)
			  {
				 case 8:

					if(Fil <= 36)
					{
					   if(Col > 2)
					{
					Col = Col - 2;


					   Coordenada(Fil, Col);
					   gotoxy(Col + 4, Fil + 3);
					   cout<< " ";
					}
					else
					{


						  Col = 1;
						  Coordenada(Fil, Col);
						  gotoxy(Col + 4, Fil + 3);

					}
					}


					if(Fil == 37)
					{
					   if(Col > 1)
					{
					Col = Col - 2;


					   Coordenada(Fil, Col + 1);
					   gotoxy(Col + 5, Fil + 3);
					   cout<< " ";
					}
					else
					{


						  Col = 0;
						  Coordenada(Fil, Col + 1);
						  gotoxy(Col + 5, Fil + 3);

					}
					}





				 break;

				 case 13:
					if(Fil <= 36)
					{
					   Fil = Fil + 1;
					   Col = 1;
					}
					if(Fil == 37)
					{
					   Fil = Fil + 1;
					   Col = Col - 1;
					}
				 break;
			  }


			  if(Col >= 159)
			  {
				 if(Fil <= 36)
				 {
					Fil = Fil + 1;
					Col = 1;
				 }
				if(Fil == 37)
				 {
					Fil = 37;
					Col = Col - 1;
				 }
			  }

			  if(Fil >= 38)
			  {
				 Fil = 37;
			  }


			  if(Fil <= 36)
			  {
				 Coordenada(Fil, Col);
			  }

			  if(Fil == 37)
			  {
				 Coordenada(Fil, Col + 1);
			  }

			  //Col++;
		   }

		   while(C != 27);



		   return true;
		}






//-------------------------------------Main-------------------------------------

	 int _tmain(int argc, _TCHAR* argv[])
	 {
		Fullscreen();
		Resolucion();
		system("color 0b");
		system("cls");
		MarcoMenu(0,Ancho - 2,0,Alto + 6);

		do
		{
		   switch(Opcion)
		   {
			  case 1:
				 system("cls");
				 MarcoPrincipal(0,Ancho - 2,0,Alto + 6);
				 Editor();
				 system("pause > null");
				 Opcion = 0;
			  break;

			  case 2:
				 cout<< "Opcion 2" << endl;
				 system("Pause > null");
				 Opcion = 0;
			  break;

			  case 3:
				 cout<< "Opcion 3" << endl;
				 system("Pause > null");
				 Opcion = 0;
			  break;

			  default:
				 MarcoMenu(0,Ancho - 2,0,Alto + 6);
			  break;
		   }
		   cout<<endl<<endl;
		   system("cls");
		}

		while(Opcion != 4);
		cout<< "\n";
		cout<< "\n";
		cout<< "Aplicacion Finalizada";
		cout<< "\n";
		cout<< "\n";
		system("pause");

		return 0;
	 }





