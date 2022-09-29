#ifndef ANNUAIRE_H
#define ANNUAIRE_H
#include"Contact_prive.h"
#include"Contact_pro.h"
#include<map>

class Annuaire
{

    private:
        std::map<int,Contact*> repertoire;



    public:
        void Ajouter();
        void Ajouter(Contact*);

        void rechercher();

        void rechercherNom();
        void rechercherVille();
        void rechercherNum();
        void rechercherCP();
        void rechercherDep();
        void AjouterCtPro();
        void AjouterCtPrive();
        void afficher();
        void afficherprive();
        void afficherpro();
        void affichertout();
        void supprimer();
        void modifier();
        void exporter();


        Annuaire();
        virtual ~Annuaire();


};

#endif // ANNUAIRE_H
