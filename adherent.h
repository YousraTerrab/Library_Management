class Adherent{
public:
char Nom[20];
char Nom_utilisateur[10];
char Mot_de_pass[5];
char no_livre_emp[3];
void CreerAdherent();
friend void Ajouter_Adherent();
friend void connect_adherent();
friend void Afficher_liste_A();
friend void admin_menu();
friend void menu_adherent();
friend void Emprunter_livre();
friend void Afficher_compte();
};
