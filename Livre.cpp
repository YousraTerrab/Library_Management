#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include <stdlib.h>
#include"Livre.h"
using namespace std;
void livre:: creer_livre()
	{
	 cout<<"\n\n\tEntrer Le Numero De Serie Du Livre. :";
	 cin.getline(no_livre,3);
	 cout<<"\n\tEntrer Le Nom Du Livre :";
	 cin.getline(Nom_livre,50);
	 cout<<"\n\tEntrer Le Nom De L'Auteur:";
	 cin.getline(Auteur,20);
	 cout<<"\n\tEntrer Le Nombre Des Livres :";
	 cin>>nbr_livres;
	}
	void livre:: afficher_livre()
	{
   cout<<"\n\t\tNo Du Livre  :"<<no_livre<<endl;
    cout<<"\n\t\tNom Du Livre: "<<Nom_livre<<endl;
    cout<<"\n\t\tAuteur : "<<Auteur<<endl;
    cout<<"\n\t\tNombre Des Livres : "<<nbr_livres<<endl;

   cout<<"*********************************************************"<<endl;
	}
	void livre:: modifier_livre()
	{
		cout<<"\n\tNumero Du Livre. : "<<no_livre;
		cout<<"\n\tModifier Le Nom Du Livre : ";
        cin.getline(Nom_livre,50);
		cout<<"\n\tModifier Le Nom De l'Auteur : ";
		cin.getline(Auteur,20);
		cout<<"\n\tModifier Nombre Des Livres : ";
		cin>>nbr_livres;
	}
