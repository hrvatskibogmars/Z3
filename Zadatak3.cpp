#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
//#include "red_polje.h"
#include "red_pokazivac.h"
using namespace std;

int n = 0;
bool prioritet = true;
int a[100];
int b[100];
int c[100];
int d[100];
int e[100];

int brojRekurzija = 0;
int pomocniBrojac = 0;


void generatorPetorki ()
{
	cout <<"Koliko petorki zelite generirati: ";
	cin >> n;
	for (int i=0; i <n; i++)
	{
		a[i]=rand()%300+50;
        b[i]=rand()%300+50;
        c[i]=rand()%5+1;
        d[i]=rand()%4+1;
        e[i]=rand()%5+1;
        
		//TESTIRANJE
		//c[i]=rand()%3+1;
        //d[i]=rand()%2+1;
        //e[i]=rand()%2+1;
        
        //Testiranje
        //c[i]=2;
        //d[i]=3;
        //e[i]=1;
	
        if(c[i] == 1) //Hitni slucaj(1)
        {
        	d[i]=rand()%2+1; // Hitni slucaj moze biti samo previjanje(2) ili pregled(1)	
        	e[i]=rand()%5+2; // Hitni slucaj moze obaviti svako osim obiteljske medicine (1)
        }
        
        if(c[i] == 3) // Trudnice mogu posjetiti svakog osim urologa
        {

        		e[i]=rand()%4+1;
        }
        
        if(c[i] == 4) // Djeca nema potrebu ici ginkologu ili urologu
        {
        		e[i]=rand()%3+1;
        }
		
	}
	return;
}

void provjerageneratoraPetorki() //provjera unosa
{
	for (int i=0; i <n; i++)
	{
		cout <<"Broj: "<<i+1 <<endl;
		cout <<"A: "<<a[i]<<endl;
		cout <<"B: "<<b[i]<<endl;
		cout <<"C: "<<c[i]<<endl;
		cout <<"D: "<<d[i]<<endl;
		cout <<"E: "<<e[i]<<endl;
		cout <<"-------------------"<<endl;
	}
}

void dodavanjePacijenta(que *red)
{
	 int ispitivanjePrioriteta = 0;
	 int pomBr = 0;
	 cin.ignore();
     
	 for(int i=0; i<n; i++)
	 {
	     for (int j = 0; j < 3; j++)
	     {
	     	
			 cout <<"<ai:" <<a[i]<<", bi:" <<b[i]<<", ci:" <<c[i]<<", di:" <<d[i]<<", ei:" <<e[i]<<">"<<endl;  
			 pacijent novi; 
			 cout << "Ime pacijenta: ";
		     getline(cin,novi.imePacijenta);
		     
		     cout << "Prezime pacijenta: ";
		     getline(cin,novi.prezimePacijenta);
		     
		     cout << "Datum rodjenja(DD.MM.GGGG.) pacijenta: ";
		     getline(cin,novi.datumRodjenja);
		     
		     cout <<"Spol pacijenta(M/Z): ";
		     getline(cin,novi.spol);
		     cout <<"-------------------"<<endl;
	
		     
			 novi.a = a[i];
		     novi.b = b[i];
		     novi.c = c[i];
		     novi.d = d[i];
		     novi.e = e[i];
		     
			 EnQueueQ(novi, red);
			 
			 //cout <<ispitivanjePrioriteta<< " " << c[i] <<endl;
			 
			 if (ispitivanjePrioriteta != c[i])
			 {
			 	 ispitivanjePrioriteta = c[i];
				 pomBr++;
			 }
	     }
	
	 }
	 
	//cout <<"Prioritet: " << pomBr <<endl;
	if (pomBr == 1)
		prioritet = false;
}

void ispisGlavnogReda(que *red)
{
	
	pacijent pomPacijent[100];
	int pomBr = 0;
	while(!isEmpty(red))
	{
		pomPacijent[pomBr] = FrontQ(red);
		cout <<"<ai:" <<pomPacijent[pomBr].a<<", bi:" <<pomPacijent[pomBr].b<<", ci:" <<pomPacijent[pomBr].c<<", di:" <<pomPacijent[pomBr].d<<", ei:" <<pomPacijent[pomBr].e<<">"<<endl;   
		cout << "Ime pacijenta: "<< pomPacijent[pomBr].imePacijenta<<endl;
		cout << "Prezime pacijenta: "<< pomPacijent[pomBr].prezimePacijenta<<endl;
		cout << "Datum rodjenja(DD.MM.GGGG.) pacijenta: "<< pomPacijent[pomBr].datumRodjenja<<endl;
		cout <<"Spol pacijenta: "<< pomPacijent[pomBr].spol<<endl;
		cout <<"-------------------"<<endl;
		DeQueueQ(red);
		pomBr++;
	}
	
	for (int i = 0; i <pomBr; i++)
		EnQueueQ(pomPacijent[i], red);
	
}

void sort(que *red)
{
	int pomBr = 0;
	
	if (prioritet == false)
	{
		cout <<"Red se poslužuje slijedno"<<endl;
		return;
	}	
	
	cout <<"Prioritetniji pacijenti imaju prednost" <<endl; 
	
	pacijent popis[100];
	 
	
	while(!isEmpty(red))
	{
		popis[pomBr] = FrontQ(red);
        pomBr++;
        DeQueueQ(red);
    }
    
    
    for (int i = pomBr-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			if (popis[j].c > popis[i].c)
			{
				pacijent pom = popis[j];
				popis[j] = popis[i];
				popis[i] = pom;
			}
	}
	
	for (int i = 0; i <pomBr; i++)
		EnQueueQ(popis[i], red);
	
	//pacijent provjera;
	//provjera = FrontQ(red);
	//cout <<"Prvi element: " << provjera.c << endl;
}

void ispisOftamologa (que *red)
{
	pacijent popis[100];
	int pomBr = 0;
	
	while(!isEmpty(red))
	{
		popis[pomBr] = FrontQ(red);
        pomBr++;
        DeQueueQ(red);
    }
    
    for (int i = 0; i <pomBr; i++) // Žene starije od 25 godina, oftamolog 
	{
		
			EnQueueQ(popis[i], red);
			
			string datumRod = popis[i].datumRodjenja.substr(6,4);
			//cout <<"DatumRod" << datumRod<<endl;
			
			
			if (popis[i].e == 2 && popis[i].spol == "Z"  && (2013-atoi(datumRod.c_str())) >= 25)
			{
				cout <<"-------------"<<endl;
				cout <<"<ai:" <<popis[i].a<<", bi:" <<popis[i].b<<", ci:" <<popis[i].c<<", di:" <<popis[i].d<<", ei:" <<popis[i].e<<">"<<endl;   
				cout <<"Ime: " <<popis[i].imePacijenta<<endl;
    			cout <<"Prezime: " <<popis[i].prezimePacijenta<<endl;
    			cout <<"Datum rodjenja: " <<popis[i].datumRodjenja<<endl;
				cout <<"Spol: " <<popis[i].spol<<endl;
				cout <<"-------------"<<endl;
			}
	}
	     
}

void previjanje(que *red) //invalidi, stariji od 50 godina, obiteljska medicina, previjanje
{
	pacijent popis[100];
	int pomBr = 0;
	
	while(!isEmpty(red))
	{
		popis[pomBr] = FrontQ(red);
        pomBr++;
        DeQueueQ(red);
    }
    
    for (int i = 0; i <pomBr; i++)
	{
		EnQueueQ(popis[i], red);
		string datumRod = popis[i].datumRodjenja.substr(6,4);
		//cout <<"DatumRodjenja: " <<2013 - atoi(datumRod.c_str())<<endl;
		
			if ((2013 - atoi(datumRod.c_str()))>=50 && popis[i].c==2 && popis[i].d==2 && popis[i].e==1 )
			{
				DeQueueQ(red);
				cout <<"----IZBRISANI---"<<endl;
				cout <<"<ai:" <<popis[i].a<<", bi:" <<popis[i].b<<", ci:" <<popis[i].c<<", di:" <<popis[i].d<<", ei:" <<popis[i].e<<">"<<endl;   
				cout <<"Ime: " <<popis[i].imePacijenta<<endl;
    			cout <<"Prezime: " <<popis[i].prezimePacijenta<<endl;
    			cout <<"Datum rodjenja: " <<popis[i].datumRodjenja<<endl;
				cout <<"Spol: " <<popis[i].spol<<endl;
				cout <<"-------------"<<endl;
			}
	}
	
}

void brziRed(que *red, que *brzi)
{	
	if (isEmpty(red))
		return;
		
	brojRekurzija++;
	pacijent pomoc = FrontQ(red);
	DeQueueQ(red);
	brziRed(red,brzi);
	
    //cout <<"Broj rekurzija: " <<brojRekurzija <<endl;

	
	if (((brojRekurzija*0.3) >=pomocniBrojac) && (pomoc.d ==3 || pomoc.d ==4))
	{
		EnQueueQ(pomoc, brzi);
		pomocniBrojac++;
	}
	else
		EnQueueQ(pomoc, red);
}

void ispisBrzogReda(que *brzi)
{
	pacijent pomPacijent[100];
	int pomBr = 0;
	while(!isEmpty(brzi))
	{
		pomPacijent[pomBr] = FrontQ(brzi);
		cout <<"<ai:" <<pomPacijent[pomBr].a<<", bi:" <<pomPacijent[pomBr].b<<", ci:" <<pomPacijent[pomBr].c<<", di:" <<pomPacijent[pomBr].d<<", ei:" <<pomPacijent[pomBr].e<<">"<<endl;   
		cout << "Ime pacijenta: "<< pomPacijent[pomBr].imePacijenta<<endl;
		cout << "Prezime pacijenta: "<< pomPacijent[pomBr].prezimePacijenta<<endl;
		cout << "Datum rodjenja(DD.MM.GGGG.) pacijenta: "<< pomPacijent[pomBr].datumRodjenja<<endl;
		cout <<"Spol pacijenta: "<< pomPacijent[pomBr].spol<<endl;
		cout <<"-------------------"<<endl;
		DeQueueQ(brzi);
		pomBr++;
	}
	
	for (int i = 0; i <pomBr; i++)
		EnQueueQ(pomPacijent[i], brzi);
	
}

int main ()
{
	srand(time(NULL));
	generatorPetorki();
	
	que *red;
	red = new que;
	InitQ(red);
	
	que *brzi;
	brzi = new que;
	InitQ(brzi);
	
	int izbor;
    do
    {
    	cout << endl;
    	cout << "IZBORNIK" << endl;
        cout << "---------------------"<< endl;
        cout <<" 1. Dodavanje zapisa o pacijentima i ispis pacijentica"<<endl; 
        cout <<" 2. Ispis pacijenta kod obiteljske medicine starijih od 50 godina koji cekaju na previjanje" << endl;
        cout <<" 3. Brzi red" << endl;
        cout <<" 4.Izlaz" <<endl;
        cout <<"----------------------"<<endl;
        cout <<"PROVJERA"<<endl;
		cout <<"10. Ispis petorki"<<endl;
		cout <<"11. Glavni red"<<endl;
    	cout << "---------------------"<< endl;
	    cout << "Vas izbor: ";
		cin >> izbor;
    	cout << "---------------------"<< endl;

		
		switch(izbor)
		{
			case 1:
				dodavanjePacijenta(red);
				sort(red);
				ispisOftamologa(red);
				break;
            case 2:
            	cout <<"Ispis pacijenta koji cekaju na previjanje" <<endl;
				previjanje(red);
            	cout <<"Ispis glavnog reda" <<endl;
            	ispisGlavnogReda(red);
				break;
            case 3:
            	brziRed(red,brzi);
            	cout <<"Ispis glavnog reda" <<endl;
            	sort(red);
            	ispisGlavnogReda(red);
            	cout <<"Ispis Brzog reda" <<endl;
            	sort(brzi);
            	ispisBrzogReda(brzi);
            	break;
			case 10:
				provjerageneratoraPetorki();
				break;
			case 11:
				ispisGlavnogReda(red);
				break;
			default:
				break;
		}
    }while(izbor!=4);
	
	return 0;
}





