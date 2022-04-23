#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include <stdlib.h>
#include "adherent.h"
using namespace std;
void Adherent:: CreerAdherent()
{
  cout<<"\n\n\tEntre votre Nom:";
  gets(Nom);
  cout<<"\n\tEntrer Votre Nom d'Utulisateur:";
  gets(Nom_utilisateur);
  cout<<"\n\tEntrer Votre Mot De Pass:";
  cin>>Mot_de_pass;
}
