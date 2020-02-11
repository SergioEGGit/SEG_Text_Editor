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

     //-------------------------------Colores-------------------------------

		void Color(int Background, int Text)
		{
		   // Funci�n para cambiar el color del fondo y/o pantalla

		   HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
		   // Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
		   // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
		   int    New_Color= Text + (Background * 16);
		   SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
		}


	 //---------------------------------Men�-------------------------------

		void Menu()
		{
		   //Informaci�n
		   Color(0,4);
		   gotoxy ((Ancho - 2)/2 - 20, 2);
		   cout<< "Universidad De San Carlos De Guatemala" <<endl;
		   gotoxy ((Ancho - 2)/2 - 12, 4);
		   cout<< "Facultad De Ingenieria" <<endl;
		   gotoxy ((Ancho - 2)/2 - 11, 6);
		   cout<< "Estructuras De Datos" <<endl;
		   gotoxy ((Ancho - 2)/2 - 6, 8);
		   cout<< "Practica 1" <<endl;
		   gotoxy ((Ancho - 2)/2 - 17, 10);
		   Color(0,1);
		   cout<< "Sergio Alexander Echigoyen Gomez" <<endl;
		   gotoxy ((Ancho - 2)/2 - 6, 12);
		   cout<< "201801628" <<endl;

		   //Men�
		   Color(0,6);
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
		   Color(0,9);
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

		   Menu();
		}

		void MarcoPrincipal(int Col1, int Col2, int Fil1, int Fil2)
		{
		   Color(0,9);
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
		   Color(0,4);
		   gotoxy(Col1 + 40,Fil2 - 2);
		   cout << "^w (Buscar Y Remplazar)";
		   gotoxy(Col1 + 80,Fil2 - 2);
		   cout << "^c (Reportes)";
		   gotoxy(Col1 + 110,Fil2 - 2);
		   cout << "^s (Guardar)";
		   gotoxy(Col1 + 75,Fil1 + 1);
		   Color(0,6);
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

	   void Coordenada(int col, int fila)
	   {
		  string digiCol, digiFila;
		  gotoxy(Ancho - 25, Alto + 4);
		  if(col < 10)
		  {
			 digiCol = "00";
		  }

		  if(col >= 10 && col < 100)
		  {
			 digiCol = "0";
		  }

		  if(col >= 100)
		  {
			 digiCol = "";
		  }

		  if(fila < 10)
		  {
			 digiFila = "00";
		  }

		  if(fila >= 10 && fila < 100)
		  {
			 digiFila = "0";
		  }

		  if(fila >= 100)
		  {
			 digiFila = "";
		  }

		   Color(0,10);
		   gotoxy(Ancho - 22, Alto + 4);
		   cout<< "Col: " << digiCol << col << " Fila: " << digiFila << fila;
		   Color(0,15);
		}

		bool Editor()
		{

		  //Variables

		  int Ascii = 0;
		  int col = 1;
		  int fila = 1;
		  int margenIzquierdo = 3;
		  int margenSuperior = 3;
		  int margenDerecho = Ancho - 9;
		  int margenInferior = Alto - 6;
		  bool salir = false;
		  char C[100000];
		  bool tempo = true;
		  string Caracter;
          ListaLD Cabeza = NULL;
		  ListaLD Cola = NULL;


		 do
		 {

			 Coordenada(col, fila);
			 gotoxy(col + margenIzquierdo,fila + margenSuperior);
			 if(tempo)
			 {
				Ascii = getche();
                C[col] = Ascii;
				Caracter = C[col];
				tempo = true;
			 }
			 else
			 {
				Ascii = getch();
				tempo = true;
			 }

			 if( Ascii == 0 )
			 {
			 tempo = false;
			 Ascii = getch(); // Las compuestas
			 Ascii = Ascii * 100;
			 }
			 gotoxy(margenDerecho/2, margenInferior/2);
			 cout<<"                   ";
			 gotoxy(margenDerecho/2, margenInferior/2);
			 cout<< Ascii;

			 switch (Ascii)
			 {
			  case 32 ... 253:
					C[col] = Ascii;
					col ++;
					InsertarLDFinal(Cabeza, Cola, Caracter);
					if (col >= margenDerecho)
					{
						if (fila < margenInferior)
						{
							col = 1;
							fila++;
						}
						else
						{
							col--;
							fila = margenInferior;
                        }
					}
					break;
			  case 13:
					if (fila < margenInferior)
					{
					   col = 1;
					   fila++;
					}
					else
					{
					   fila = margenInferior;
					}
					break;
			 case 8:
					 col--;
					 gotoxy(col + margenIzquierdo,fila + margenSuperior);
					 cout<<" ";
					 if (col <= 1)
					 {
                         col = 1;
					 }
					 else
					 {
						BorrarUltimo(Cola);
                     }
					break;
			 case 27:
					salir = true;
					gotoxy(col + margenIzquierdo,fila + margenSuperior);
					cout<< "  ";
					break;
			 case 23:
					gotoxy(col + margenIzquierdo,fila + margenSuperior);
					cout<<" ";
					gotoxy(margenDerecho/2, margenInferior/2);
					cout<<"                   ";
					gotoxy(margenDerecho/2, margenInferior/2);
					 cout<< "Control W";
					break;
			 case 3:
					gotoxy(col + margenIzquierdo,fila + margenSuperior);
					cout<<" ";
					gotoxy(margenDerecho/2, margenInferior/2);
					cout<<"                   ";
					gotoxy(margenDerecho/2, margenInferior/2);
					 cout<< "Control C";
					break;
			 case 19:
					gotoxy(col + margenIzquierdo,fila + margenSuperior);
					cout<<" ";
					gotoxy(margenDerecho/2, margenInferior/2);
					cout<<"                   ";
					gotoxy(margenDerecho/2, margenInferior/2);
					cout<< "Control S";
					break;
			 case 7500:
					 col--;
					 gotoxy(col + margenIzquierdo,fila + margenSuperior);
					 if(col <= 1)
					 {
						col = 1;
					 }
			 break;
			 default:
				 ;
			 }


		  }  while(!salir);

             BuscarYRemplazar(Cabeza, Cola, "Juan", "Manolo");
			 MostrarLD(Cabeza);
			 getch();

			 system("cls");

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





