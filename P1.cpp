
//-------------------------------Pr�ctica 1-------------------------------------

	#pragma hdrstop
	#pragma argsused
	#ifdef _WIN32
	   #include <tchar.h>
	#else
	   typedef char _TCHAR;
	   char* strtok( char* cadena_a_tokenizar, const char* delimitador );
	   #define _tmain main
	 #endif

//--------------------------------Librer�as-------------------------------------

	#include <iostream>
	#include <stdio.h>
	#include <conio.h>
	#include <string>
	#include <windows.h>
	#include <fstream>
    #include <algorithm>
	#include <functional>
	#include <cctype>
	#include <locale>
	#include <cstring>
	#include <ListaDobleCaracteres.h>
	#include <ListaCircularArchivosR.h>
	#include <PilaLog.h>
	#include <PilaRevertidos.h>
	#include <ListaSimpleOrden.h>
	using namespace std;

//---------------------------------Variables------------------------------------

	int Alto = 0;
	int Ancho = 0;
	int Opcion = 0;
	bool ArchivoOK = true;
	string PalabraBuscar = "";
	string PalabraReemplazar = "";
	string CoorFil = "";
	string CoorCol = "";
	string RutaArchivo = "";
	ListaCAR listaCAR = NULL;
	ListaCAR Final = NULL;

//----------------------------------M�todos-------------------------------------

	//-----------------------------Colores---------------------------------

		void Color(int Background, int Text)
		{
			// Funci�n para cambiar el color del fondo y/o pantalla

			HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
			// Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
			// Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.
			int    New_Color= Text + (Background * 16);
			SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
		}

	//-----------------------------Trimmed---------------------------------

		const string WHITESPACE = " \n\r\t\f\v";

		string ltrim(const string& s)
		{
			size_t start = s.find_first_not_of(WHITESPACE);
			return (start == string::npos) ? "" : s.substr(start);
		}

		string rtrim(const string& s)
		{
			size_t end = s.find_last_not_of(WHITESPACE);
			return (end == string::npos) ? "" : s.substr(0, end + 1);
		}

		string trimmed(const string& s)
		{
			return rtrim(ltrim(s));
		}

	//--------------------------------Split--------------------------------

		string SepararRuta(string RutaArchivo)
		{
			char Cadena[100000];
			char Delimitador[] = "\\";
			string Res;

			//Convertir String A Char
			strcpy(Cadena ,RutaArchivo.c_str());

			char *Tokens = strtok(Cadena, Delimitador);

			if(Tokens != NULL)
			{
				while(Tokens != NULL)
				{
					Res = Tokens;
					Tokens = strtok(NULL, Delimitador);
                }
			}
			return Res;
		}

		void SepararBuscar(string Busqueda)
		{
			char Cadena[100000];
			char Delimitador[] = ";";
			int contador = 0;

			//Convertir String A Char
			strcpy(Cadena ,Busqueda.c_str());

			char *Tokens = strtok(Cadena, Delimitador);

			if(Tokens != NULL)
			{
				while(Tokens != NULL)
				{
					if(contador == 0)
					{
						PalabraBuscar = Tokens;
					}
					if(contador == 1)
					{
						PalabraReemplazar = Tokens;
                    }
					Tokens = strtok(NULL, Delimitador);
                    contador++;
				}
			}
        }

		void Separarcoor(string Coor)
		{
            char Cadena[1000];
			char Delimitador[] = ";";
			int contador = 0;

			//Convertir String A Char
			strcpy(Cadena ,Coor.c_str());

			char *Tokens = strtok(Cadena, Delimitador);

			if(Tokens != NULL)
			{
				while(Tokens != NULL)
				{
					if(contador == 0)
					{
						CoorCol = Tokens;
					}
					if(contador == 1)
					{
						CoorFil = Tokens;
                    }
					Tokens = strtok(NULL, Delimitador);
                    contador++;
				}
			}
		}

	//-----------------------------Posiciones------------------------------

		int PantallaTDA(int Col, int Fila, int MargenDerecho)
		{
			int Res = 0;

			Res = (Fila - 1)*MargenDerecho + Col;

			return Res;
		}

	//-------------------------------Men�----------------------------------

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

	//------------------------------Marcos---------------------------------

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
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
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
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
					{
						cout << (char)205;
					}
					//Status Bar
					else if((Cols != Col1) && (Fils == Fil2 - 4))
					{
						cout << (char)205;
					}
					//Barra De T�tulo
					else if((Cols != Col1) && (Fils == Fil1 + 2))
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

		void MarcoArchivos(int Col1, int Col2, int Fil1, int Fil2)
		{
			Color(0,9);
			for(int Cols = Col1; Cols <= Col2; Cols++)
			{
				for(int Fils = Fil1; Fils <= Fil2; Fils++)
				{
					gotoxy(Cols,Fils);
					//Linea Vertical Derecha E Izquierda
					if((Cols == Col1 || Cols == Col2) && (Fils != Fil1 && Fils != Fil2))
					{
						cout << (char)186;
					}
					//Linea Horizontal Superior E Inferior
					else if((Fils == Fil1 || Fils == Fil2) && (Cols != Col1 && Cols != Col2))
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

			//Textos
			Color(0,7);
			gotoxy(Col1 + 68,Fil2 - 8);
			cout << "X: Generar Reporte De Archivos";
			gotoxy(Col1 + 68,Fil2 - 6);
			cout << "A: Abrir Archivo Reciente";

		}

	//----------------------------Fullscreen-------------------------------

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
			cout<< "Col: " << digiCol << col << " Fil: " << digiFila << fila;
			Color(0,15);
		}

		void LeerArchivo(string RutaArchivo, ListaLDC &CabezaC, ListaLDC &ColaC, bool salir)
		{
			string Cadena;
			string Caracter;
			string CadenaTr;
			int contador = 0;
			bool Flag = false;
			fstream FicheroEntrada;

			FicheroEntrada.open(RutaArchivo.c_str(), ios::in);

			if(FicheroEntrada.is_open())
			{
				ArchivoOK = true;
				while(!FicheroEntrada.eof())
				{
					getline(FicheroEntrada, Cadena);
					CadenaTr = trimmed(Cadena);
					if((CadenaTr.length() > 0) && (Flag))
					{
						InsertarFinalLDC(CabezaC, ColaC, "�");
					}
					if(CadenaTr.length() == 0)
					{
						InsertarFinalLDC(CabezaC, ColaC, "�");
					}
					else
					{
						for(int i = 0; i < Cadena.length(); i++)
						{
							Caracter = Cadena[i];
							InsertarFinalLDC(CabezaC, ColaC, Caracter);
						}
					}
					Flag = true;
				}
				FicheroEntrada.close();
			}
			else
			{
				 gotoxy(4, 4);
				 Color(0, 4);
				 cerr << "El Archivo No Existe En El Sistema" << endl;
				 ArchivoOK = false;
			}
		}

		void EscribirArchivo(string RutaArchivo, ListaLDC &CabezaC, ListaLDC &ColaC, int col, int fila, int margenIzquierdo, int margenInferior, int margenSuperior)
		{
			ofstream FicheroSalida;
			string NombreArchivo;
			string Cadena;
			string Ruta;
			ListaLDC aux = CabezaC;


			Ruta = trimmed(RutaArchivo);

			Ruta = Ruta + ".txt";

			FicheroSalida.open(Ruta.c_str(), ios::out | ios::trunc);

			if(FicheroSalida.is_open())
			{
				while(aux != NULL)
				{
					if(aux -> Caracter != "�")
					{
						Cadena = Cadena + aux -> Caracter;
					}
					else
					{
						FicheroSalida<< Cadena << endl;
						Cadena = "";
					}

					if(aux == ColaC)
					{
						FicheroSalida<< Cadena << endl;
						Cadena = "";
					}
					aux = aux -> sgte;
				}
			}
			else
			{
				//cout<< "Error de apertura del archivo." << endl;
			}
			FicheroSalida.close();
		}

		bool Editor()
		{
			//Variables
			int Ascii = 0;
			int AsciiB = 0;
			int AsciiR = 0;
			int AsciiG = 0;
			int col = 1;
			int fila = 1;
			int margenIzquierdo = 3;
			int margenSuperior = 3;
			int margenDerecho = Ancho - 9;
			int margenInferior = Alto - 6;
			char C[100000];
			char B[100000];
			char R[100000];
			char G[100000];
			bool salir = false;
			string Cadena;
			bool tempo = true;
			string Caracter;
			string Busqueda;
			string Reporte;
			string Res;
			string Coor;
			int Reportei;
			int Buscai;
			int Guardari;
			int PalabrasAF;
			int Posicion;
			bool ctrlx = false;


			ListaLDC CabezaC = NULL;
			ListaLDC ColaC = NULL;

			PilaPL PilaL = NULL;
			PilaPR PilaR = NULL;

            ListaLSO listaLSO = NULL;
			Color(0, 15);
			do
			{
                Color(0, 15);

				//Fijar Coordenada
				Coordenada(col, fila);
				//Fijar Posici�n
				gotoxy(col + margenIzquierdo,fila + margenSuperior);
				if(tempo)
				{
					Ascii = getche();
					C[col] = Ascii;
					Caracter = C[col];
					Cadena += C[col];
					tempo = true;
				}
				else
				{
					Ascii = getch();
					tempo = true;
				}

				if(Ascii == 0)
				{
					tempo = false;
					Ascii = getch(); // Las compuestas
					Ascii = Ascii * 100;
				}

				switch(Ascii)
				{
					case 32 ... 253:
						C[col] = Ascii;
						col ++;
						InsertarFinalLDC(CabezaC, ColaC, Caracter);
						if(col >= margenDerecho)
						{
							if(fila < margenInferior)
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
						if(Ascii == 13)
						{
							InsertarFinalLDC(CabezaC, ColaC, "�");
						}

						if(fila < margenInferior)
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
						PilaL = NULL;
						PilaR = NULL;
						Posicion = PantallaTDA(col, fila, margenDerecho);
						if(col <= 1)
						{
							col = 1;
						}
						else
						{
							BorrarUltimoLDC(ColaC);
						}
					break;

                    case 25:
						Res = EliminarPR(PilaR, PalabraBuscar, PalabraReemplazar, true, "Null", -1);
						Res = trimmed(Res);
						SepararBuscar(Res);
						PalabraBuscar = trimmed(PalabraBuscar);
						PalabraReemplazar = trimmed(PalabraReemplazar);
						if(PalabraBuscar.length() > 0)
						{
							BuscarRLCD(CabezaC, ColaC, PalabraBuscar, PalabraReemplazar);
							InsertarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
						}
						Coor = MostrarLDC(CabezaC, margenIzquierdo + 1, margenSuperior, margenInferior, margenDerecho);
						Coor = trimmed(Coor);
						Separarcoor(Coor);
						CoorCol = trimmed(CoorCol);
						CoorFil = trimmed(CoorFil);
						col = stoi(CoorCol) + 1;
						fila = stoi(CoorFil);
						Coor = "";
						CoorCol = "";
						CoorFil = "";
						PalabraBuscar = "";
						PalabraReemplazar = "";
						Res = "";
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<< "  ";
					break;

					case 26:
						Res = EliminarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
						Res = trimmed(Res);
						SepararBuscar(Res);
						PalabraBuscar = trimmed(PalabraBuscar);
						PalabraReemplazar = trimmed(PalabraReemplazar);
						if(PalabraBuscar.length() > 0)
						{
							BuscarRLCD(CabezaC, ColaC, PalabraBuscar, PalabraReemplazar);
							InsertarPR(PilaR, PalabraReemplazar, PalabraBuscar, true, "Null", -1);
						}
                        Coor = MostrarLDC(CabezaC, margenIzquierdo + 1, margenSuperior, margenInferior, margenDerecho);
						Coor = trimmed(Coor);
						Separarcoor(Coor);
						CoorCol = trimmed(CoorCol);
						CoorFil = trimmed(CoorFil);
						col = stoi(CoorCol) + 1;
						fila = stoi(CoorFil);
						Coor = "";
						CoorCol = "";
						CoorFil = "";
						PalabraBuscar = "";
						PalabraReemplazar = "";
						Res = "";
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<< "  ";
					break;

					case 27:
						salir = true;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<< "  ";
					break;

					case 23:
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<<" ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,4);
						cout<<"Buscar Y Remplazar: ";
						Color(0,15);
						do
						{
							gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);

							AsciiB = getch();
							B[Buscai] = AsciiB;

							switch(AsciiB)
							{
								case 32 ... 253:
									gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);
									B[Buscai] = AsciiB;
									cout<< B[Buscai];
									Buscai++;
								break;

								case 24:
									gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);
									cout<< " ";
									ctrlx = true;
									AsciiB = 0;
								break;

								case 8:
									Buscai--;
									gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);
									cout<<" ";
								break;

								case 13:
									for(int i = 0; i <= Buscai; i++)
									{
										 Busqueda = Busqueda + B[i];
									}
									AsciiB = 0;
								break;

							}
						}
						while(AsciiB != 0);
						Buscai = 0;
						gotoxy(6, 6);
						Busqueda = trimmed(Busqueda);
						SepararBuscar(Busqueda);
						PalabraBuscar = trimmed(PalabraBuscar);
						PalabraReemplazar = trimmed(PalabraReemplazar);
                        if((PalabraBuscar.length() > 0) && (PalabraReemplazar.length() > 0))
						{
							PalabrasAF = BuscarRLCD(CabezaC, ColaC, PalabraBuscar, PalabraReemplazar);
						}
						Coor = MostrarLDC(CabezaC, margenIzquierdo + 1, margenSuperior, margenInferior, margenDerecho);
						Coor = trimmed(Coor);
						Separarcoor(Coor);
						CoorCol = trimmed(CoorCol);
						CoorFil = trimmed(CoorFil);
						col = stoi(CoorCol) + 1;
						fila = stoi(CoorFil);
						Coor = "";
						CoorCol = "";
						CoorFil = "";
						Busqueda = "";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                         ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,10);
						if(PalabrasAF > 0)
						{
							if(PalabrasAF == 1)
							{
								cout<< PalabrasAF << " Palabra Afectada";
								getch();
								InsertarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
							}
							else
							{
								cout<< PalabrasAF << " Palabras Afectadas";
								getch();
								InsertarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
							}
						}
						else
						{
							if(ctrlx == false)
							{
								Color(0, 4);
								cout<< "No Se Encontro La Palabra Indicada";
							}
						}
						PalabraBuscar = "";
						PalabraReemplazar = "";
						ctrlx = false;
						PalabrasAF = 0;
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                         ";
					break;

					case 3:
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<<" ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,4);
						cout<<"1.Reporte Lista, 2.Reporte Palabras Buscadas, 3.Reporte Palabras Ordenadas: ";
						Color(0,15);
						do
						{
							gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);

							AsciiR = getch();
							R[Reportei] = AsciiR;

							switch(AsciiR)
							{
								case 32 ... 253:
									gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);
									R[Reportei] = AsciiR;
									cout<< R[Reportei];
									Reportei++;
								break;

								case 24:
									gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);
									cout<< " ";
									AsciiR = 0;
								break;

								case 8:
									Reportei--;
									gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);
									cout<<" ";
								break;

								case 13:
									for(int i = 0; i <= Reportei; i++)
									{
										 Reporte = Reporte + R[i];
									}
									AsciiR = 0;
								break;

							}
						}
						while(AsciiR != 0);
						Reportei = 0;
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                                                    ";
						Reporte = trimmed(Reporte);
						if(Reporte == "1")
						{
							ReporteListaLDC(CabezaC, ColaC);
						}
						if(Reporte == "2")
						{
							ReporteBuscadosPL(PilaL);
                            ReporteBuscadosPR(PilaR);
						}
						if(Reporte == "3")
						{
							ReporteOrdenLS(listaLSO, PilaL);
                        }
						Reporte = "";
					break;

					case 19:
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<<" ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,4);
						cout<<"Guardar: [Ruta Archivo]";
						Color(0,15);
						gotoxy(margenIzquierdo + 25, margenInferior + 6);
						do
						{
							gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);

							AsciiG = getch();
							G[Guardari] = AsciiG;

							switch(AsciiG)
							{
								case 32 ... 253:
									gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);
									G[Guardari] = AsciiG;
									cout<< G[Guardari];
									Guardari++;
								break;

								case 24:
									gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);
									cout<< " ";
									AsciiG = 0;
								break;

								case 8:
									Guardari--;
									gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);
									cout<<" ";
								break;

								case 13:
									for(int i = 0; i <= Guardari; i++)
									{
										 RutaArchivo = RutaArchivo + G[i];
									}
									AsciiG = 0;
								break;

							}
						}
						while(AsciiG != 0);
						Guardari = 0;
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                         ";
						gotoxy(5, 5);
						EscribirArchivo(RutaArchivo, CabezaC, ColaC, col, fila, margenIzquierdo, margenInferior, margenSuperior);
						RutaArchivo = "";
					break;

					case 7500:
						col--;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(col <= 1)
						{
							col = 1;
						}
					break;

					case 7200:
						fila--;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(fila <= 1)
						{
							fila = 1;
						}
					break;

					case 8000:
						fila++;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(fila >= margenInferior)
						{
							fila = margenInferior;
						}
					break;

					case 7700:
						col++;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(col >= margenDerecho)
						{
							col = margenDerecho;
						}
					break;

					default:
						;
				}


			}

			while(!salir);

			system("cls");

			return true;
		}

		bool EditorAbrir(string Archivo)
		{
			//Variables
			int Ascii = 0;
			int AsciiB = 0;
			int AsciiR = 0;
			int AsciiG = 0;
			int col = 1;
			int fila = 1;
			int margenIzquierdo = 3;
			int margenSuperior = 3;
			int margenDerecho = Ancho - 9;
			int margenInferior = Alto - 6;
			char C[100000];
			char B[100000];
			char R[100000];
			char G[100000];
			bool salir = false;
			string Cadena;
			bool tempo = true;
			string Caracter;
			string Busqueda;
			string Reporte;
            string NombreArchivo;
			string Res;
			string Coor;
			int Reportei;
			int Buscai;
			int Guardari;
			int PalabrasAF;
			bool ctrlx = false;


			ListaLDC CabezaC = NULL;
			ListaLDC ColaC = NULL;
			PilaPL PilaL = NULL;
			PilaPR PilaR = NULL;

            ListaLSO listaLSO = NULL;

			//Abrir Archivo
			if(Archivo == "")
			{
				gotoxy(col + margenIzquierdo,fila + margenSuperior);
				cout<<" ";
				gotoxy(margenIzquierdo + 1, margenInferior + 6);
				Color(0,4);
				cout<<"Abrir Archivo: [Ruta Archivo]";
				Color(0,15);
				gotoxy(margenIzquierdo + 31, margenInferior + 6);
				cin>> RutaArchivo;
				gotoxy(margenIzquierdo + 1, margenInferior + 6);
				cout<<"                                                                                               ";
			}
			else
			{
				RutaArchivo = Archivo;
				Color(0,15);
			}

			LeerArchivo(RutaArchivo, CabezaC, ColaC, salir);
			Coor = MostrarLDC(CabezaC, margenIzquierdo + 1, margenSuperior, margenInferior, margenDerecho);
			Coor = trimmed(Coor);
			Separarcoor(Coor);
			CoorCol = trimmed(CoorCol);
			CoorFil = trimmed(CoorFil);
			col = stoi(CoorCol) + 1;
			fila = stoi(CoorFil);
			Coor = "";
			CoorCol = "";
			CoorFil = "";
			NombreArchivo = SepararRuta(RutaArchivo);

			if(ArchivoOK == true)
			{
				if(BuscarLCAR(listaCAR, Final, RutaArchivo) == false)
				{
					InsertarInicioLCAR(listaCAR, Final, NombreArchivo, RutaArchivo);
				}

                RutaArchivo = "";
				do
				{
					Color(0, 15);

					//Fijar Coordenada
					Coordenada(col, fila);
					//Fijar Posici�n
					gotoxy(col + margenIzquierdo,fila + margenSuperior);
					if(tempo)
					{
						Ascii = getche();
						C[col] = Ascii;
						Caracter = C[col];
						Cadena += C[col];
						tempo = true;
					}
					else
					{
						Ascii = getch();
						tempo = true;
					}

					if(Ascii == 0)
					{
						tempo = false;
						Ascii = getch(); // Las compuestas
						Ascii = Ascii * 100;
					}

					switch(Ascii)
					{
						case 32 ... 253:
							C[col] = Ascii;
							col ++;
							InsertarFinalLDC(CabezaC, ColaC, Caracter);
							if(col >= margenDerecho)
							{
								if(fila < margenInferior)
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
							if(Ascii == 13)
							{
								InsertarFinalLDC(CabezaC, ColaC, "�");
							}

							if(fila < margenInferior)
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
							if(col <= 1)
							{
								col = 1;
							}
							else
							{
								BorrarUltimoLDC(ColaC);
							}
						break;

						case 25:
						Res = EliminarPR(PilaR, PalabraBuscar, PalabraReemplazar, true, "Null", -1);
						Res = trimmed(Res);
						SepararBuscar(Res);
						PalabraBuscar = trimmed(PalabraBuscar);
						PalabraReemplazar = trimmed(PalabraReemplazar);
						if(PalabraBuscar.length() > 0)
						{
							BuscarRLCD(CabezaC, ColaC, PalabraBuscar, PalabraReemplazar);
							InsertarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
						}
						Coor = MostrarLDC(CabezaC, margenIzquierdo + 1, margenSuperior, margenInferior, margenDerecho);
						Coor = trimmed(Coor);
						Separarcoor(Coor);
						CoorCol = trimmed(CoorCol);
						CoorFil = trimmed(CoorFil);
						col = stoi(CoorCol) + 1;
						fila = stoi(CoorFil);
						Coor = "";
						CoorCol = "";
						CoorFil = "";
						PalabraBuscar = "";
						PalabraReemplazar = "";
						Res = "";
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<< "  ";
					break;

					case 26:
						Res = EliminarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
						Res = trimmed(Res);
						SepararBuscar(Res);
						PalabraBuscar = trimmed(PalabraBuscar);
						PalabraReemplazar = trimmed(PalabraReemplazar);
						if(PalabraBuscar.length() > 0)
						{
							BuscarRLCD(CabezaC, ColaC, PalabraBuscar, PalabraReemplazar);
							InsertarPR(PilaR, PalabraReemplazar, PalabraBuscar, true, "Null", -1);
						}
                        Coor = MostrarLDC(CabezaC, margenIzquierdo + 1, margenSuperior, margenInferior, margenDerecho);
						Coor = trimmed(Coor);
						Separarcoor(Coor);
						CoorCol = trimmed(CoorCol);
						CoorFil = trimmed(CoorFil);
						col = stoi(CoorCol) + 1;
						fila = stoi(CoorFil);
						Coor = "";
						CoorCol = "";
						CoorFil = "";
						PalabraBuscar = "";
						PalabraReemplazar = "";
						Res = "";
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<< "  ";
					break;

					case 27:
						salir = true;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<< "  ";
					break;

					case 23:
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<<" ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,4);
						cout<<"Buscar Y Remplazar: ";
						Color(0,15);
						do
						{
							gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);

							AsciiB = getch();
							B[Buscai] = AsciiB;

							switch(AsciiB)
							{
								case 32 ... 253:
									gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);
									B[Buscai] = AsciiB;
									cout<< B[Buscai];
									Buscai++;
								break;

								case 24:
									gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);
									cout<< " ";
									ctrlx = true;
									AsciiB = 0;
								break;

								case 8:
									Buscai--;
									gotoxy(margenIzquierdo + 21 + Buscai, margenInferior + 6);
									cout<<" ";
								break;

								case 13:
									for(int i = 0; i <= Buscai; i++)
									{
										 Busqueda = Busqueda + B[i];
									}
									AsciiB = 0;
								break;

							}
						}
						while(AsciiB != 0);
						Buscai = 0;
						gotoxy(6, 6);
						Busqueda = trimmed(Busqueda);
						SepararBuscar(Busqueda);
						PalabraBuscar = trimmed(PalabraBuscar);
						PalabraReemplazar = trimmed(PalabraReemplazar);
                        if((PalabraBuscar.length() > 0) && (PalabraReemplazar.length() > 0))
						{
							PalabrasAF = BuscarRLCD(CabezaC, ColaC, PalabraBuscar, PalabraReemplazar);
						}
						Coor = MostrarLDC(CabezaC, margenIzquierdo + 1, margenSuperior, margenInferior, margenDerecho);
						Coor = trimmed(Coor);
						Separarcoor(Coor);
						CoorCol = trimmed(CoorCol);
						CoorFil = trimmed(CoorFil);
						col = stoi(CoorCol) + 1;
						fila = stoi(CoorFil);
						Coor = "";
						CoorCol = "";
						CoorFil = "";
						Busqueda = "";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                         ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,10);
						if(PalabrasAF > 0)
						{
							if(PalabrasAF == 1)
							{
								cout<< PalabrasAF << " Palabra Afectada";
								getch();
								InsertarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
							}
							else
							{
								cout<< PalabrasAF << " Palabras Afectadas";
								getch();
								InsertarPL(PilaL, PalabraBuscar, PalabraReemplazar, false, "Null", -1);
							}
						}
						else
						{
							if(ctrlx == false)
							{
								Color(0, 4);
								cout<< "No Se Encontro La Palabra Indicada";
							}
						}
						PalabraBuscar = "";
						PalabraReemplazar = "";
						ctrlx = false;
						PalabrasAF = 0;
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                         ";
					break;

					case 3:
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<<" ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,4);
						cout<<"1.Reporte Lista, 2.Reporte Palabras Buscadas, 3.Reporte Palabras Ordenadas: ";
						Color(0,15);
						do
						{
							gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);

							AsciiR = getch();
							R[Reportei] = AsciiR;

							switch(AsciiR)
							{
								case 32 ... 253:
									gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);
									R[Reportei] = AsciiR;
									cout<< R[Reportei];
									Reportei++;
								break;

								case 24:
									gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);
									cout<< " ";
									AsciiR = 0;
								break;

								case 8:
									Reportei--;
									gotoxy(margenIzquierdo + 78 + Reportei, margenInferior + 6);
									cout<<" ";
								break;

								case 13:
									for(int i = 0; i <= Reportei; i++)
									{
										 Reporte = Reporte + R[i];
									}
									AsciiR = 0;
								break;

							}
						}
						while(AsciiR != 0);
						Reportei = 0;
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                                                    ";
						Reporte = trimmed(Reporte);
						if(Reporte == "1")
						{
							ReporteListaLDC(CabezaC, ColaC);
						}
						if(Reporte == "2")
						{
							ReporteBuscadosPL(PilaL);
                            ReporteBuscadosPR(PilaR);
						}
						if(Reporte == "3")
						{
							ReporteOrdenLS(listaLSO, PilaL);
                        }
						Reporte = "";
					break;

					case 19:
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						cout<<" ";
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						Color(0,4);
						cout<<"Guardar: [Ruta Archivo]";
						Color(0,15);
						gotoxy(margenIzquierdo + 25, margenInferior + 6);
						do
						{
							gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);

							AsciiG = getch();
							G[Guardari] = AsciiG;

							switch(AsciiG)
							{
								case 32 ... 253:
									gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);
									G[Guardari] = AsciiG;
									cout<< G[Guardari];
									Guardari++;
								break;

								case 24:
									gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);
									cout<< " ";
									AsciiG = 0;
								break;

								case 8:
									Guardari--;
									gotoxy(margenIzquierdo + 25 + Guardari, margenInferior + 6);
									cout<<" ";
								break;

								case 13:
									for(int i = 0; i <= Guardari; i++)
									{
										 RutaArchivo = RutaArchivo + G[i];
									}
									AsciiG = 0;
								break;

							}
						}
						while(AsciiG != 0);
						Guardari = 0;
						gotoxy(margenIzquierdo + 1, margenInferior + 6);
						cout<<"                                                                         ";
						gotoxy(5, 5);
						EscribirArchivo(RutaArchivo, CabezaC, ColaC, col, fila, margenIzquierdo, margenInferior, margenSuperior);
						RutaArchivo = "";
					break;

					case 7500:
						col--;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(col <= 1)
						{
							col = 1;
						}
					break;

					case 7200:
						fila--;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(fila <= 1)
						{
							fila = 1;
						}
					break;

					case 8000:
						fila++;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(fila >= margenInferior)
						{
							fila = margenInferior;
						}
					break;

					case 7700:
						col++;
						gotoxy(col + margenIzquierdo,fila + margenSuperior);
						if(col >= margenDerecho)
						{
							col = margenDerecho;
						}
					break;

					default:
							;
					}
				}

				while(!salir);

			}
			else
			{
				system("Pause > null");
            }

			return true;
		}

		bool EditorArchivosRecientes()
		{
			//Variables
			int Ascii = 0;
			int margenIzquierdo = 3;
			int margenSuperior = 3;
			int margenDerecho = Ancho - 9;
			int margenInferior = Alto - 6;
			int col = margenDerecho - 60;
			int fila = margenInferior + 4;
			char C[100000];
            bool salir = false;
			string Cadena;
			bool tempo = true;
			string Caracter;
			string Busqueda;
			string RutaArchivo;
			string NombreArchivo;
			string Archivo;

			gotoxy((margenDerecho/2 - 5), margenSuperior - 1);
			Color(0,4);
			cout<< "Archivos Recientes";
			Color(0,6);
			MostrarLCAR(listaCAR, margenDerecho/2 - 8, margenSuperior + 1);
			gotoxy((margenDerecho - 60), margenInferior + 4);

			do
			{
				gotoxy(col, fila);
				Ascii = getche();

				switch(Ascii)
				{
					case 32 ... 253:
						col = margenDerecho - 60;
						fila = margenInferior + 4;
						gotoxy(col, fila);
						cout<<" ";
						Archivo = "";
						if(Ascii == 65 || Ascii == 97)
						{
							gotoxy(col - 5, fila + 2);
							Color(0, 6);
							cout<< "Ingrese El Numero Del Archivo: ";
							cin>> Archivo;
							gotoxy(col - 5, fila + 2);
							cout<< "                                   ";
                            if((BuscarARLCAR(listaCAR, Final, Archivo) == "Vacio") || (BuscarARLCAR(listaCAR, Final, Archivo) == "No Existe"))
							{
								gotoxy(col - 5, fila + 2);
								Color(0, 4);
								cout<< "No Existe El Archivo Seleccionado";
								getch();
								gotoxy(col - 5, fila + 2);
								cout<< "                                 ";
							}
							else
							{
								system("cls");
								RutaArchivo = BuscarARLCAR(listaCAR, Final, Archivo);
								MarcoPrincipal(0,Ancho - 2,0,Alto + 6);
								EditorAbrir(RutaArchivo);
                            }

						}

						if(Ascii == 88 || Ascii == 120)
						{
							ReporteArchivosLCAR(listaCAR, Final);
						}
					break;

					case 27:
						salir = true;
                        col = margenDerecho - 60;
						fila = margenInferior + 4;
						gotoxy(col, fila);
						cout<< "  ";
					break;

					default:
						;
				}


			}

			while(!salir);

			system("cls");

			return true;
		}


//----------------------------------Main----------------------------------------

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
					Opcion = 0;
				break;

				case 2:
					system("cls");
					MarcoPrincipal(0,Ancho - 2,0,Alto + 6);
					EditorAbrir("");
					Opcion = 0;
				break;

				case 3:
					system("cls");
					MarcoArchivos(0,Ancho - 2,0,Alto + 6);
					EditorArchivosRecientes();
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





