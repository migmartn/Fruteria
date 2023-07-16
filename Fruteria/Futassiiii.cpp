#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
/////////////////////////////////////////////
using namespace std;
void proceso();
void marco();
void gotoxy(int x,int y);
///////////////////////////
	char id[10];
	char nombre[50];
	char precio[10];
	char unidad[10];
////////////////////////////////
int main(){
	proceso();
}

void proceso(){
	////////////////////////////variables////////////////////////////////////////
	char re;
	int opc, i=1,a = 1, y=2;
	ofstream archivo;
	fstream archivob;
	ifstream Leer;
    fstream Temp;
	////////////////////////////////////////////////////////////////////////////
		//while(a=1){
		system("color 02");
		gotoxy(20,1);cout<<"FRUTERIA.";
		marco();
		gotoxy(2,2); cout<<"Elige una opcion"<<endl;
		gotoxy(2,3); cout<<"1.Ingresa datos del Producto"<<endl;
		gotoxy(2,4); cout<<"2.Buscar la fruta comprada"<<endl;
		gotoxy(2,5);cout<<"3.Todos las compras"<<endl;
		gotoxy(2,6);cout<<"4.Salir"<<endl;
		gotoxy(2,7);cin>>opc;
		system("cls");
		
		
		if(opc==1){
			system("color 0e");
			marco();
			archivo.open("fruta.txt",ios::app); 
			if(archivo.fail()){ 
				cout<<"No se pudo abrir el archivo";
				exit(1);
				}
			gotoxy(15,1);cout<<"Ingresa datos del Producto: ";
			do{
						fflush(stdin);
						gotoxy(2,2);cout<<"ID: "; 
						cin>>id;
						archivo<<id<<endl;
						
						fflush(stdin);
						gotoxy(2,3);cout<<"Nombre: ";
						cin.getline(nombre,50);
						archivo<<nombre<<endl;
						
						gotoxy(2,4);cout<<"Precio: "; 
						cin>>precio;
						archivo<<precio<<endl;
						
						gotoxy(2,5);cout<<"Unidad: "; 
						cin>>unidad;
						archivo<<unidad<<endl;
						
						y=2;
					}while(y==1);
				archivo.close();
				proceso();
				system("cls");
				system("pause");
		}	
		
		///////////////////////////////////////////////////////////////////////////////////////////
		if(opc==2){
			system("color 06");
			marco();
			string cadena, linea, linea2, linea3, linea4;

		int res = 0, opb;
		
	gotoxy(2,2)	;cout<<"Como Quieres Buscar: ";
		gotoxy(2,3);cout<<"1.ID";
		gotoxy(2,4);cout<<"2. Nombre";
		gotoxy(2,5);cout<<"Elige";
		gotoxy(2,6);cin>>opb;
		system("cls");
		
		if (!archivob.is_open())
		{
		archivob.open("fruta.txt",ios::in);
		}
		if(opb==1){
		gotoxy(2,2);cout<< "Introduce el ID del producto a buscar: \n"; 
		gotoxy(2,3);cin >> cadena;
		while(getline(archivob, linea)){
			if(linea.find(cadena) != string::npos){
				
				gotoxy(2,4);cout<<"ID: "<<linea<<endl;
				getline(archivob, linea2);
				gotoxy(2,5);cout<<"Nombre: "<<linea2<<endl;
				getline(archivob, linea3);
				gotoxy(2,6);cout<<"Precio: "<<linea3<<endl;
				getline(archivob, linea4);
				gotoxy(2,7);cout<<"Unidad: "<<linea4<<endl;
				system("pause");
				system("cls");
				proceso();
				res = 1;
			}
			
	}
}
	if(opc==2){
		gotoxy(2,2);cout<< "Introduce el Nombre del producto a buscar: \n"; 
		gotoxy(2,3);cin >> cadena;
					while(getline(archivob, linea)){
			if(linea.find(cadena) != string::npos){
				
				gotoxy(2,4);cout<<"Nombre: "<<linea<<endl;
				getline(archivob, linea2);
				gotoxy(2,5);cout<<"Precio: "<<linea2<<endl;
				getline(archivob, linea3);
				gotoxy(2,6);cout<<"Unidad: "<<linea3<<endl;
				system("pause");
				system("cls");
				proceso();
				res = 1;
			}
	}
			}

	     if(res==0){
		gotoxy(2,2);cout<<cadena<<" no se a encontrado"<<endl;
     	}
	gotoxy(2,7); system("pause");
	system("cls");
		}

	///////////////////////////////////////////////////////////////////////////////
	
	
		if(opc==3){
			system("color 01");
			ifstream archivo;
			string texto;
			archivo.open("fruta.txt");
			if(archivo.fail()){
			gotoxy(2,2);cout<<"No se pudo abrir el archivo"<<endl;
				system("pause");
				system("cls");
				proceso();
			}
			
			while(!archivo.eof()){
				fflush(stdin);
				getline(archivo,texto);
				cout<<texto<<endl;
			}
			archivo.close(); 
			
			system("pause");
			system("cls");
			
		}
		///////////////////////////////////////////////////////////////////////
		if(opc==4){
			system("color 04");
			marco();
			gotoxy(5,1);cout<<"Estas seguro que quieres salir(s/n):";
			gotoxy(5,2);cin>>re;
				system("cls");
				if(re=='s'){
					
					exit(1);
				}
				if(re=='n'){
					proceso();
					
				}
		}
		}
	
//}

 //////////////////////////marco///////////////////////////

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 void marco(){
	for(int x=1; x<=50; x++)
	{
		gotoxy (x,0);
		putchar ('*');
		gotoxy (x,24);
		putchar ('*');
	}
	
	for(int y=1; y<=24; y++)
	{
		gotoxy (0,y);
		putchar ('*');
		gotoxy (50,y);
		putchar ('*');
	}
}  
