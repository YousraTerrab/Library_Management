#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include <stdlib.h>
#include "adherent.h"
#include"Admin.h"
#include"Livre.h"
using namespace std;
void cover();
int gotoxy(int, int);
Adherent u;
livre b;
admin a;
//****************global variable for current user*************************
char adherent_Actuel[10];
char no_serie[3];
char Nom_livre_actuel[50];
//********************add user***********************
void Ajouter_Adherent()
 {
	u.CreerAdherent();
	ofstream out("Adherent.txt",ios::app);
	if(!out){
	cout<<"Impossible d'ouvrir le fichier Adherent.txt. \n";
}
	strcpy(u.no_livre_emp,"0");
	out.write((char*) &u,sizeof(Adherent));
cout<<"\t votre compte a etait bien cree.";
	}
//********************add admin***********************
void Ajouter_admin()
 {
	a.Creer_admin();
	ofstream out("admin.dat",ios::app);
	if(!out){
	cout<<"impossible d'ouvrir le fichier  admin.dat.\n";
	}
	out.write((char*) &a,sizeof(admin));
	cout<<"\t votre compte a etait bien cree.";
 }
//*********************log in for user*****************
extern void admin_menu();
extern void menu_adherent();
void connect_adherent()
 {
  char n[25],p[5];
  int flag=0;
  ifstream in("Adherent.txt",ios::in|ios::out);

  cout<<"\n\n\tEntrer votre nom d'utulisateur: ";
  cin.getline(n,25);
  cout<<"\n\n\tEntrer votre mot de pass: ";
  cin>>p;
  if(!in)
  {
	 cout<<"Fichier non trouvable";
  }
  while(in.read((char *)&u,sizeof(Adherent)))
  {
	  if(strcmp(u.Nom_utilisateur,n)==0 &&strcmp(u.Mot_de_pass,p)==0)
	  {
		 strcpy(adherent_Actuel,u.Nom_utilisateur);
		 strcpy(no_serie,u.no_livre_emp);
		 flag=1;
		 cout<<"\n\tWELCOME  "<<u.Nom<<"\n";
		 menu_adherent();
		 }
	 }
	 if(flag==0)
	 {
	  cout<<"\tNom d'utulisateur ou Mot de pass incorrect";
	 connect_adherent();
	 }
	 in.close();
 }
//*********************log in for Admin****************
  void admin_con()
 {
  char x[4];
  ifstream in("admin.dat",ios::in|ios::out);
  cout<<"\n\n\tEntrer votre mot de pass: ";
  cin>>x;
  if(!in)
  {
	 cout<<"Fichier introuvable";
  }

  while(in.read((char *)&a,sizeof(admin)))
  {
	  if(strcmp(a.pass_admin,x)==0)
	  {
		cout<<"\n\tCONNECTE" ;
		admin_menu();
		 }
	  else
	  {
		  cout<<"\tMot de pass incorrect";
		  admin_con();
	  }
	 }
	 in.close();
 }
//****************search book by book no********
 void chercher_Livre_no()
 {
	ifstream in;
	char n[3],x;
	int flag=0;
	int t;
	do{
	cout<<"\n\n\tEntrer le no de serie du livre: ";
	cin>>n;
	in.open("Livre.txt");
	while(in.read((char*)&b,sizeof(livre)))
	{
	    t= strcmpi(b.no_livre,n);
		if(t==0)
		{  cout<<"\t\t\t     *LISTE DES LIVRES*\n\n";
			b.afficher_livre();
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
		cout<<"/tLivre Introuvable";
		}
		flag=0;
		cout<<"\n\n\tVoulez Vous Chercher Une Autre Fois..(y/n?)";
		cin>>x;
		in.close();
		}while(x=='y'||x=='Y');
		menu_adherent();
 }
//*******************search book by name***********
  void chercher_Livre_nom()
 {
	ifstream in;
	char n[50],x;
	int flag=0;
	do{
	cout<<"\n\n\tEntrer Le Nom Du Livre:";
	cin>>n;
	in.open("Livre.txt");
	while(in.read((char*)&b,sizeof(livre)))
	{
	    int t=strcmpi(b.Nom_livre,n);
		if(t==0)
		{  cout<<"\t\t\t     *LISTE DES LIVRES*\n\n";
		b.afficher_livre();
			flag=1;
			break;
		}
	}
		if(flag==0)
		{
		cout<<"Livre Introuvable";
		}
		flag=0;
		cout<<"\n\n/tVoulez Vous Chercher Une Autre Fois..(y/n?)";
		cin>>x;
		in.close();
		}while(x=='y'||x=='Y');
		menu_adherent();
 }
//*******************search book by author**********
  void chercher_Livre_aut()
 {
	ifstream in;
	char n[20],x;
	int flag=0;
	cout<<"\n\n\tENTRER LE NOM DE L'AUTEUR:";
	cin>>n;
	cout<<"\t\t\t     *LISTE DES LIVRES*\n\n";
	do{
	in.open("Livre.txt");
	while(in.read((char*)&b,sizeof(livre)))
	{
		if(strcmpi(b.Auteur,n)==0)
		{
			b.afficher_livre();
			flag=1;
		}
	}
	  if(flag==0)
		{
		cout<<"Livre Introuvable";
		}
		cout<<"\n\n\ttVoulez Vous Chercher Une Autre Fois..(y/n?)";
		cin>>x;
		in.close();
		}while(x=='y'||x=='Y');
		menu_adherent();
 }
//*******************add_book********************
 void ajouter_livre()
 {
  char c;
  do{
  b.creer_livre();
  ofstream out("Livre.txt",ios::app);
  if(!out){
  cout<<"Impossible D'ouvrir Le Fichier Livre.txt . \n";
  }
  out.write((char*) &b,sizeof(livre));
  cout<<"\n\n\tVoulez Vous Ajouter D'autre Livres(y/n?)";
  cin>>c;
  out.close();
  } while(c=='y'||c=='Y');
  admin_menu();
  }
//*******************show_allb for admin*******************
 void Afficher_Livres_adm()
 {
  ifstream in("Livre.txt");
  if(!in)
  {
  cout<<"Fichier Introuvable";
  }
		cout<<"\t\t\t     *Listes Des Livres*n\n";
  while(in.read((char*)&b,sizeof(livre)))
  {
	b.afficher_livre();
  }
  admin_menu();
  in.close();
 }
//*******************AFFICHAGE DE LISTE DES LIVRES*******************
  void Afficher_Livres_adh()
 {
  ifstream in("Livre.txt");
  if(!in)
  {
  cout<<"Fichier Introuvable";
  }
  cout<<"\t\t\t     * LISTES DES LIVRES*\n\n";
  while(in.read((char*)&b,sizeof(livre)))
  {
	b.afficher_livre();
  }
  menu_adherent();
  in.close();
 }
//*******************AFFICHAGE DE LISTE DES LIVRES*******************
 void Afficher_liste_A()
 {
  ifstream in("Adherent.txt");
  if(!in)
  {
  cout<<"Fichier Introuvable";
  }
	 cout<<"\n\t|Nom|"<<setw(33)<<"|Nom d'Utulisateur|"<<"\n";
	 cout<<"\t***************************************\n";
  while(in.read((char*)&u,sizeof(Adherent)))
  {
		  cout<<"\t"<<u.Nom<<"\t\t\t"<<u.Nom_utilisateur<<"\n";
  }
  in.close();
 }
//********************SUPPRESSION DE LIVRE****************
void supp_livre()
{
		char n[3];
		char c2;
		int flag=0;
		fstream f1;
		fstream f2;
		cout<<"\n\n\n\tSUPPRIMER UN LIVRE...";
		do{
		cout<<"\n\nEntrer Le numero de serie du Livre  : ";
		cin>>n;
		f1.open("Livre.txt",ios::in|ios::out);
		f2.open("temp.txt",ios::out);
		f1.seekg(0,ios::beg);
		while(f1.read((char*)&b,sizeof(livre)))
	{
		if(strcmpi(b.no_livre,n)!=0)
				f2.write((char*)&b,sizeof(livre));
		else
				flag=1;
	}
	f2.close();
		f1.close();
		remove("Livre.txt");
		rename("temp.txt","Livre.txt");
		cout<<b.no_livre;
		if(flag==1)
			{
			cout<<"\n\n\tLe Livre est Supprime ..";
			cout<<"\n\nVoulez Vous Supprimer d'Autre Livres..(y/n?)";
			cin>>c2;
			}
		else
		  {	cout<<"\n\nLivre Introuvable";
			cout<<"\n\nVoulez vous Ajouter D'Autre Livres..(y/n?)";
			cin>>c2;
			}
			}while(c2=='y'||c2=='Y');
			admin_menu();
}
//*********************modifFICATION DE LIVRE*******************
void mod_livre()
{ 	char n[6],ch;
	fstream fp;
	int found=0;
	system("cls");
	cout<<"\n\n\tMODIFIER UN LIVRE.... ";
	cout<<"\n\n\tEntrer Le Numero De Serie Du Livre :";
	cin>>n;
	fp.open("Livre.txt",ios::in|ios::out);
	while(fp.read((char*)&b,sizeof(livre)) && found==0)
	{
		if(strcmpi(b.no_livre,n)==0)
		{
		  do{
			system("cls");
			cout<<"\n\t\t\t     *LISTE DES LIVRES*\n\n";
			b.afficher_livre();
			cout<<"\n\n\t**********************";
			cout<<"\n\tMenu De Modification Des Livres";
			cout<<"\n\t**********************";
			cout<<"\n\t1.Modifier Le Numero De Serie Du Livre";
			cout<<"\n\t2.Modifier Le Nom Du Livre";
			cout<<"\n\t3.Modifier Le Nom De l'Auteur";
			cout<<"\n\t4.Modifier Le Nombre Des Livres";
			cout<<"\n\t5.Aller A Menu De l'Admin\n";
			cout<<"\n\tEntre Votre Choix: ";
			ch=getche();
			switch(ch)
		{
			 case '1':
			 {
			 cout<<"\n\tModification Du Numero De Serie Du Livre : ";
			 cin>>b.no_livre;
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(livre));
			 found=1;
			 fp.close();
			 break;
			 }
			  case '2':
			  {
			 cout<<"\n\tModIfication Du Nom Du Livre : ";
			 cin.getline(b.Nom_livre,50);
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(livre));
			 cout<<"\n\n\t Livre Modifie Avec Succee";
			 found=1;
				 fp.close();
			 break;
			 }
			  case '3':
			 {
			 cout<<"\n\tModifier Le Nom De L'auteur : ";
			 cin.getline(b.Auteur,20);
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(livre));
			 cout<<"\n\n\t Livre Modifie Avec Succee";
			 found=1;
				 fp.close();
			 break;
			 }
			  case '4':
			 {
			 cout<<"\n\tModifier Le Nombre Des Livres : ";
			 cin>>b.nbr_livres;
			 int pos=-1*sizeof(b);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&b,sizeof(livre));
			 cout<<"\n\n\t  Livre Modifie Avec Succee";
			 found=1;
				 fp.close();
			 break;
			 }
			 case '5':
			 {
			 system("cls");
			 admin_menu();
			 break;
			 }
	  }
	  }while(ch!='5');
		}
	}
		fp.close();
		if(found==0)
			cout<<"\n\n Livre Introuvable";
			admin_menu();
	}
//*****************EMPRUNT DE LIVRE*****************
void Emprunter_livre()
{
	char n[3];
	fstream fp,f;
	int found=0;
	system("cls");
	cout<<"\n\n\tEntrer Le Numero De Serie Du Livre:";
	cin>>n;
	fp.open("Livre.txt",ios::in|ios::out);
	while(fp.read((char*)&b,sizeof(livre)) && found==0)
	{
		if(strcmpi(b.no_livre,n)==0)
		{  found=1;
			b.afficher_livre();
			if(b.nbr_livres==0)
			{
			 cout<<"\n\n\t   ********Ce Livre N'Est Pas Valable Pour L'Emprunt.********\n";
			 break;
			}
			else
			{
			b.nbr_livres=b.nbr_livres-1;
			strcpy(Nom_livre_actuel,b.Nom_livre);
				int pos=-1*sizeof(b);
				fp.seekp(pos,ios::cur);
				fp.write((char*)&b,sizeof(livre));
				cout<<"\n\n\tLivre Emprunte Pour 7 Jours\n";
			}
		}
	}
		fp.close();
		if(found==0)
			cout<<"\n\n Livre Introuvable ";
		f.open("Adherent.txt",ios::in|ios::out);
		while(f.read((char*)&u,sizeof(Adherent)))
	{
		if(strcmpi(u.Nom_utilisateur,adherent_Actuel)==0)
		{
				strcpy(u.no_livre_emp,n);
				strcpy(no_serie,u.no_livre_emp);
				int pos=-1*sizeof(u);
				f.seekp(pos,ios::cur);
				f.write((char*)&u,sizeof(Adherent));
		 }
	}
		menu_adherent();
}
//***************RENDRE UN LIVRE*********
void rendre_livre()
{
	char n[6];
	fstream fp,f;
	int found=0;
	system("cls");
		f.open("Adherent.txt",ios::in|ios::out);
		while(f.read((char*)&u,sizeof(Adherent)))
	{
		if(strcmpi(u.Nom_utilisateur,adherent_Actuel)==0)
		{
			  strcpy(n,u.no_livre_emp);
			  strcpy(u.no_livre_emp,"0");

			int pos=-1*sizeof(u);
				f.seekp(pos,ios::cur);
				f.write((char*)&u,sizeof(Adherent));
		}
		}
	fp.open("Livre.txt",ios::in|ios::out);
	while(fp.read((char*)&b,sizeof(livre)) && found==0)
	{
		if(strcmpi(b.no_livre,n)==0)
		{  cout<<"\t\t\t     *LISTE DES LIVRES*\n\n";
			b.afficher_livre();
			b.nbr_livres=b.nbr_livres+1;

			int pos=-1*sizeof(b);
				fp.seekp(pos,ios::cur);
				fp.write((char*)&b,sizeof(livre));
				cout<<"\n\n\tLivre Rendu Avec Succee\n";
				found=1;
		}
	}
		fp.close();
		if(found==0)
			cout<<"\n\n\t Aucun Livre A Rendre ";
	 menu_adherent();
	}
//***************AFFICHAGE DES DETAILS DU COMPTE************************
void Afficher_compte()
{
	ifstream in,i;
	i.open("Livre.txt");
	while(i.read((char*)&b,sizeof(livre)))
	{
	  if(strcmpi(b.no_livre,no_serie)==0)
	  {
		 strcpy(Nom_livre_actuel,b.Nom_livre);
	  }
	  }
	in.open("Adherent.txt");
	while(in.read((char*)&u,sizeof(Adherent)))
	{
	if(strcmpi(u.Nom_utilisateur,adherent_Actuel)==0)
		{
		 cout<<"\n\t|Nom|"<<setw(25)<<"|Mot De Pass|"<<setw(30)<<"|Livres Empruntes|"<<"\n";
		 cout<<"\t**********************************************************\n";
		  cout<<"\t"<<u.Nom<<setw(20)<<u.Mot_de_pass<<setw(30)<<Nom_livre_actuel<<"\n\n";
		}
	 }
	 in.close();
		menu_adherent() ;
	}
//**************admin_menu*********************
void admin_menu()
{
char c1;
cout<<"\n\n\t*****************";
cout<<"\n\t Menu De l'Admin";
cout<<"\n\t*****************";
cout<<"\n\t1.Afficher Liste Des Livres";
cout<<"\n\t2.Ajouter Livre";
cout<<"\n\t3.Modidier Livre";
cout<<"\n\t4.Supprimer Livre";
cout<<"\n\t5.Afficher Liste Des Adherents";
cout<<"\n\t6. Se Deconnecter\n";
cout<<"\n\tEntrer Votre Choix: ";
c1=getche();
switch(c1)
{
 case '1':system("cls");
			 Afficher_Livres_adm();
			 break;
 case '2':system("cls");
			 ajouter_livre();
			 break;
 case '3':system("cls");
			 mod_livre();
			 break;
 case '4':system("cls");
			 supp_livre();
			 break;
 case '5':system("cls");
			 Afficher_liste_A();
			 break;
 case '6':system("cls");
			 cover();
			 break;
}
}
//****************MENU ADHERENT***********
void menu_adherent()
{
  char c1;
cout<<"\n\t*****************";
cout<<"\n\t    Menu De L'Adherent";
cout<<"\n\t*****************";
cout<<"\n\n\t1.Afficher Les Details Du Compte";
cout<<"\n\t2.Afficher Liste Des Livres";
cout<<"\n\t3.Chercher Un Livre Par Numero De Serie";
cout<<"\n\t4.Chercher Un Livre Par Nom";
cout<<"\n\t5.Chercher Un Livre Par Auteur";
cout<<"\n\t6.Emprunter Un Livre";
cout<<"\n\t7.Rendre Un Livre";
cout<<"\n\t8.Se Deconnecter\n";
cout<<"\n\tEntrer Votre Choix: ";
c1=getche();
switch(c1)
{
 case '1':system("cls");
			 Afficher_compte();
			 break;
 case '2':system("cls");
			 Afficher_Livres_adh();
			 break;
 case '3':system("cls");
			 chercher_Livre_no();
			 break;
 case '4':system("cls");
			 chercher_Livre_nom();
			 break;
 case '5':system("cls");
			 chercher_Livre_aut();
			 break;
 case '6':system("cls");
			 Emprunter_livre();
			 break;
 case '7':system("cls");
			 rendre_livre();
			 break;
 case '8':system("cls");
			 strcpy(adherent_Actuel,"");
			 cover();
			 break;
}
}
void cover()
{
char ch;
  cout<<"\n\n\t\t\t  ***************************\n";
  cout<<"\t\t\t  [GESTION D'UNE BIBLIOTHEQUE]";
  cout<<"\n\t\t\t  ***************************";
  cout<<"\n\tSe Connecter En Tant Que:";
   cout<<"\n\t1.Adherent";
  cout<<"\n\t2.Admin ";
  cout<<"\n\t3.Creer Un Compte\n\t";
  ch=getche();
  switch(ch)
  {
	case '1':system("cls");
				connect_adherent();
				break;
	case '2':system("cls");
				admin_con();
				break;
	case '3':system("cls");
				Ajouter_Adherent();
				break;
  }
}
int main()
{
 cover();
}
