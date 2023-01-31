#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
using namespace std;

struct MotoOficina{
	float Cv;
	int VelMax,Cilindrada;
	char Marca[30];
};
MotoOficina x[5];

int fim = -1, inicio=0;
char conf;
MotoOficina val;

char menu();
void InserirI();
void InserirF();
void RemoverI();
void RemoverF();
void BuscMoto();
void ProcMCv();
char Sair();

int main(){
	system("color 3");
	setlocale(LC_ALL, "portuguese");
	char opcao='N';
	while (opcao != 'S'){
		opcao=menu();
		switch (opcao) {
			case '1' : { InserirI(); break;}
			case '2' : { InserirF(); break;}
			case '3' : { RemoverI(); break;}
			case '4' : { RemoverF(); break;}
			case '5' : { BuscMoto(); break;}
			case '6' : { ProcMCv(); break;}
			case '7' : { opcao = Sair(); break;}
			default : { cout<<"\n\nOpcao invalida. Tecle algo para continuar..."; getch(); }
						
			}
		}
	}
	
	
char menu(){
char op;
system("cls"); //LIMPA A TELA
cout<<"\t\tOpções:\n\n";
cout<<"\t\t\t1 - Inserir Moto no Inicio\n\n";
cout<<"\t\t\t2 - Inserir Moto no Final\n\n";
cout<<"\t\t\t3 - Remover Moto no Inicio\n\n";
cout<<"\t\t\t4 - Remover Moto no Final\n\n";
cout<<"\t\t\t5 - Buscar uma moto pela marca e remover o no encontrado \n\n";
cout<<"\t\t\t6 - Procurar a moto com menor Cv e inserir um no apos o encontrado \n\n";
cout<<"\t\t\t7 - Sair do programa\n\n";
cout<<"\t\tEscolha a opção: ";
op=toupper(getche());
	return op;
}

char Sair(){
	char sair='N';
	cout<<"\n\nDeseja encerrar o programa? (S/N) : ";
	sair=toupper(getche());
	if (sair=='S') {
		cout<<"\n\nSaindo do programa...";
		getch();
		system("cls");
	} 
	return sair;
}


void InserirI(){
	if(fim < 5 - 1 ){
		system("cls");
		cout<<"\n\nQuantas Cilindradas: ";
		cin>>val.Cilindrada;
		cout<<"\n\nvalor de cavalo de potencia: ";
		cin>>val.Cv;
		cout<<"\n\nMarca da Moto: ";
		cin>>val.Marca;
		cout<<"\n\nVelocidade Maxima de: ";
		cin>>val.VelMax;
		cout<<"\n\nConfirmar Inclusão (S/N) : ";
		cin>>conf;
		conf=toupper(conf);
		if(conf == 'S' ){
			fim= fim + 1;
			inicio = fim;
			while(inicio != 0){
				x[inicio] = x[inicio-1];
				inicio = inicio-1;
				      }
				x[inicio]=val;
			}
			else{ cout<<"\n\nNao confirmou a Operacao! ";getch();}
	}
	else{cout<<"OVERFLOW!!!! ";getch();}
}
void InserirF(){
	system("cls");
	if(fim<5-1){
		cout<<"\n\nQuantas Cilindradas: ";
		cin>>val.Cilindrada;
		cout<<"\n\nvalor de cavalo de potencia: ";
		cin>>val.Cv;
		cout<<"\n\nMarca da Moto: ";
		cin>>val.Marca;
		cout<<"\n\nVelocidade Maxima de: ";
		cin>>val.VelMax;
		cout<<"\n\nConfirmar Inclusão (S/N) : ";
		cin>>conf;
		conf=toupper(conf);
		if(conf == 'S' ){
			fim=fim+1;
			x[fim]= val;
		}
		else{
			cout<<"\n\nNão confirmou a operação ";
		}
	}
	else{
		cout<<"OVERFLOW!!!! ";
	}
	getch();
}
void RemoverI(){
	system("cls");
	if(fim>-1){
		inicio=0;
		cout<<"\t\tCilindrada:.."<<x[inicio].Cilindrada<<endl;
		cout<<"\t\tCavalo:......"<<x[inicio].Cv<<endl;
		cout<<"\t\tMarca:......."<<x[inicio].Marca<<endl;
		cout<<"\t\tVelMax:......"<<x[inicio].VelMax<<endl;
		cout<<"\n\nConfirmar Exclusão (S/N) : ";
		cin>>conf;
		conf=toupper(conf);
		if(conf=='S'){
			while(inicio!=fim){
				x[inicio]=x[inicio+1];
				inicio++;
			}
			fim--;
		}
		else{
			cout<<"\n\nNão confirmou a operação ";getch();
		}
	}
	else{
		cout<<"\n\nLista  Vazia!!! "; getch();
	}
}
void RemoverF(){
	system("cls");
	if(fim>-1){
		val=x[fim];
		cout<<"\t\tCilindrada:.."<<x[fim].Cilindrada<<endl;
		cout<<"\t\tCavalo:......"<<x[fim].Cv<<endl;
		cout<<"\t\tMarca:......."<<x[fim].Marca<<endl;
		cout<<"\t\tVelMax:......"<<x[fim].VelMax<<endl;
		cout<<"\n\nConfirmar Exclusão (S/N) : ";
		cin>>conf;
		conf=toupper(conf);
		if(conf=='S'){
			fim--;
		}
		else{
			cout<<"\n\nNão confirmou a operação ";getch();}	
	}
	else{
		cout<<"\n\nLista  Vazia!!! "; getch();}
}

void BuscMoto(){
	system("cls");
	if(fim>-1){
		cout<<"\n\nDigite Marca da Moto: ";
		cin>>val.Marca;
		inicio=0;
		while(inicio!=fim && strcmp(x[inicio].Marca,val.Marca)==0){
			inicio++;
		}
		if(strcmp(x[inicio].Marca,val.Marca)==0){
			cout<<"\n\nDeseja excluir Moto "<<val.Marca<<" do sistema (S/N): " ;
			cin>>conf;
			conf=toupper(conf);
			if(conf=='S'){
				while(inicio!=fim){
					x[inicio]=x[inicio+1];
					inicio++;
				}
			fim--;	
			}
			else{cout<<"\n\nNão confirmou a operação"; getch();}
		}
		else{cout<<val.Marca<<"\n\nNão existe na Lista"; getch();}
	}
	else{cout<<"\n\nLista Vazia!!!";getch();}
}

void ProcMCv(){
	system("cls");
	MotoOficina menor;
	if(fim>-1){
		cout<<"\n\nDeseja encontrar menor valor (S/N)? ";
		cin>>conf;
		conf=toupper(conf);
		if(conf=='S'){
			inicio=0;
			menor=x[inicio];
			while(x[inicio].Cv!=val.Cv && inicio!=fim ){
				
				inicio++;
			}
			for(inicio=0; inicio < 5 ; inicio++){
				if(menor.Cv < x[inicio].Cv)
				menor.Cv= x[inicio].Cv;
				
			}
			
			//if(x[inicio].Cv == val.Cv){
			
				cout<< "\n\nMenor cavalaria é: "<<menor.Cv; getch(); 
			//}
			//else{
				//cout<< "\n\nNão a moto cadastrada no sistema. ";  getch();
			//}
		}
		else{
			cout<<"\n\nNão confirmou operação. "; getch();
		}
	}
	else{
		cout<<"\n\n Lista Vazia ";getch();
	}
	
}
