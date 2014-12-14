#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
//#include "red_pokazivac.h"
#include "red_polje.h"

using namespace std;
queue *red = new queue;
queue *pom_que = new queue;
queue *pom_que2 = new queue;

osoba *osobe;
int random_kalendar(int a, int b){
	return rand()%b + a;
}
void ispis4(int a,int b, int c, int d){
	cout << "Dolazak u red nakon prethodnog: " << a << " s"<<endl;
	cout << "Trajanje posluzivanja: " << b << " s"<<endl;
	cout << "Priroritet klijenta: ";
	switch(c){
		case 1: cout << "1 - VIP klijent"<<endl; break;
		case 2: cout << "2 - Invalid"<<endl; break;
		case 3: cout << "3 - Trudnica"<<endl; break;
		case 4: cout << "4 - Umirovljenik"<<endl; break;
		case 5: cout << "5 - Ostali"<<endl; break;
	}
	cout << "Vrsta usluge: ";
	switch(d){
		case 1: cout << "1 - Predaja/preuzimanje posiljke"<<endl; break;
		case 2: cout << "2 - Placanje racuna"<<endl; break;
		case 3: cout << "3 - Uplata lutrije"<<endl; break;
		case 4: cout << "4 - Western Union"<<endl; break;
		case 5: cout << "5 - Evotv"<<endl; break;
	}

};
void random4(int broj){
	osobe = new osoba[broj];
	for(int i = 0; i<broj; i++){
		cout<<i+1<<". cetvorka"<<endl;
		osobe[i].ai = rand()%490 + 10;
		osobe[i].bi = rand()%720 + 80;
		osobe[i].ci = rand()%5 + 1;
		osobe[i].di = rand()%5 + 1;
		cout<<osobe[i].ai<<" | "<<osobe[i].bi<<" | "<<osobe[i].ci<<" | "<<osobe[i].di<<endl;
	}
	cout<<"Generirano "<<broj<<" cetvorki."<<endl;
};
void prioritet(queue *que){
	pom_que = InitQ(pom_que);
	pom_que2 = InitQ(pom_que2);
	osoba x;
	while(!IsEmptyQ(que)){
		x = FrontQ(que);
		DeQueueQ(que);
		EnQueueQ(x, pom_que);
	}
	for(int i=1; i<=5; i++){
		while(!IsEmptyQ(pom_que)){
			x = FrontQ(pom_que);
			DeQueueQ(pom_que);
			if(x.ci == i) EnQueueQ(x, que);
		else EnQueueQ(x, pom_que2);
		}
		while(!IsEmptyQ(pom_que2)){
			x = FrontQ(pom_que2);
			DeQueueQ(pom_que2);
			EnQueueQ(x, pom_que);
		}
	}
};
void jarac(queue *red){
	cout<<"Svi horoskopskog znaka Jarac mladji od 40 godina i zanima ih uplata lutrije: "<<endl<<endl;
	pom_que = InitQ(pom_que);
	osoba x;
	while(!IsEmptyQ(red)){
		x = FrontQ(red);
		DeQueueQ(red);
		EnQueueQ(x,pom_que);
		if((((x.dan>=22) && x.mjesec==12) || ((x.dan<=20) && x.mjesec==1)) && x.ci == 3 && (2015-x.godina)<40){
			cout<<"Ime i prezime: "<<x.ime<<endl;
			cout<<"Datum rodjenja: "<<x.dan<<". "<<x.mjesec<<". "<<x.godina<<".g"<<endl;
			cout<<"Spol: "<<x.spol<<endl;
			ispis4(x.ai,x.bi,x.ci,x.di);
		}
	}
	while(!IsEmptyQ(pom_que)){
		x = FrontQ(pom_que);
		DeQueueQ(pom_que);
		EnQueueQ(x, red);
	}
};
void ispis(queue *red){
	pom_que = InitQ(pom_que);
	osoba x;
	while(!IsEmptyQ(red)){
		x = FrontQ(red);
		DeQueueQ(red);
		EnQueueQ(x,pom_que);
			cout<<"Ime i prezime: "<<x.ime<<endl;
			cout<<"Datum rodjenja: "<<x.dan<<". "<<x.mjesec<<". "<<x.godina<<".g"<<endl;
			cout<<"Spol: "<<x.spol<<endl;
			ispis4(x.ai,x.bi,x.ci,x.di);
			cout<<endl;
		}
	while(!IsEmptyQ(pom_que)){
		x = FrontQ(pom_que);
		DeQueueQ(pom_que);
		EnQueueQ(x, red);
	}
};
void unos(int broj){
	osoba client;
	for(int i = 0; i<broj; i++){
		cout<<i+1<<". cetvorka"<<endl;
		cout<< osobe[i].ai<<" | "
			<< osobe[i].bi<<" | "
			<< osobe[i].ci<<" | "
			<< osobe[i].di<<endl;
			int x = osobe[i].ci;
			int y = osobe[i].di;
		for(int j = 0; j<5; j++){
			cout<<j+1<<". klijent"<<endl;
			cin.ignore();
			cout<<"Ime i prezime: "; cin.getline(client.ime,30);
			cout<<"Datum rodjenja: "<<endl;
			client.dan = random_kalendar(1,31); cout<<"dan: "<<client.dan<<endl;
			client.mjesec = random_kalendar(1,12); cout<<"mjesec: "<<client.mjesec<<endl;
			client.godina = random_kalendar(1920,95); cout<<"godina: "<<client.godina<<endl;
			if(osobe[i].ci == 3){
				client.spol = 'z';
			}
			else{
				if (random_kalendar(1,2) == 0)
					client.spol = 'm';
				else
					client.spol = 'z';
			}
			cout<<"Spol: "<<client.spol<<endl;
			cout<<"status: "<<x<<endl;
			client.ai = osobe[i].ai;
			client.bi = osobe[i].bi;
			client.ci = x;
			client.di = y;
			EnQueueQ(client,red);
		}
		prioritet(red);
	}
};
void trudnice(queue* que) 
{
 pom_que =InitQ(pom_que);
 
 cout << "\nTrudnice koje cekaju predugo: " << endl;
 osoba x; 
 while(!IsEmptyQ(que) ){
  x = FrontQ(que);
  DeQueueQ(que);
  if(x.ci == 3 && x.di == 5){
   cout << "Ime i prezime: " << x.ime << endl;
   cout << "Datum rodjenja: " << x.dan << "." << x.mjesec << "." << x.godina << "." << endl;
   cout << "Spol ( m/z ): " << x.spol << endl;
	ispis4(x.ai,x.bi,x.ci,x.di);
  } 
  else
   EnQueueQ(x, pom_que);
 }
 while(!IsEmptyQ(pom_que) ) {
  x = FrontQ(pom_que);
  DeQueueQ(pom_que);
  EnQueueQ(x, red);
 }
}
int main()
{
	srand(time(NULL));
	red = InitQ(red);
	int b4; bool generirano = false;
	cout<<"Welcome to Hrvatska posta"<<endl<<endl;
	int izbor;
	do{
		
		cout<<" 1 - Generiraj cetvorke"<<endl;
		cout<<" 2 - Unesi 5 klijenata za svaku cetvorku u red"<<endl;
		cout<<" 3 - Ispis svih jaraca"<<endl;
		cout<<" 4 - Izlaz svih trudnica koje predugo cekaju evo tv"<<endl;
		cout<<" 5 - Ispis reda"<<endl;
		cout<<" 9 - Izlaz iz programa"<<endl<<endl;
		cout<<" Izbor: "; cin>>izbor;
		switch(izbor){
			case 1:
				cout<<"Koliko cetvorki zelite generirati?"<<endl;
				cin>>b4;
				random4(b4);
				generirano = true;
				break;	
			case 2:
				if(!generirano){
					cout<<"Prvo je potrebno generirati cetvorke!"<<endl;
					break;
				}
				unos(b4);
				break;
			case 3:
				if(!generirano){
					cout<<"Prvo je potrebno generirati cetvorke!"<<endl;
					break;
				}
				jarac(red);
				break;
			case 4:
				if(!generirano){
					cout<<"Prvo je potrebno generirati cetvorke!"<<endl;
					break;
				}
				trudnice(red);
				break;
			case 5:
				if(!generirano){
					cout<<"Prvo je potrebno generirati cetvorke!"<<endl;
					break;
				}
			 	ispis(red);
				break;
			case 9:
				cout<<"Izlaz iz programa!"<<endl<<endl;
				break;
			default:
				cout<<endl<<"Krivi unos!"<<endl;
		};		
				
	}while(izbor != 9);
	return 0;
}
