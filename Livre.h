class livre
{
    char no_livre[3];
    char Nom_livre[50];
    char Auteur[20];
    int nbr_livres;
    void creer_livre();
    void afficher_livre();
    void modifier_livre();
    friend void ajouter_livre();
    friend void Afficher_Livres_adm();
    friend void Afficher_Livres_adh();
    friend void chercher_Livre_no();
    friend void chercher_Livre_nom();
    friend void chercher_Livre_aut();
    friend void supp_livre();
    friend void mod_livre();
    friend void Emprunter_livre();
    friend void rendre_livre();
    friend void Afficher_compte();
};
