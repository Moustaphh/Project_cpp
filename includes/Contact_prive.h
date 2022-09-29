#ifndef CONTACT_PRIVE_H
#define CONTACT_PRIVE_H
#include"Contact.h"


class Contact_prive: public Contact
{
    public:

        Contact_prive(int id,std::string nom, std::string prenom, char sexe, int numero, std::string rue, std::string complement,std::string code_p, std::string ville, int jour, int mois, int annee);

        virtual ~Contact_prive();


        void info() override;

        int getjour(){return this->jour;}
        int getmois(){return this->mois;}
        int getannee(){return this->annee;}

    private:

        int jour,mois,annee;

};

#endif // CONTACT_PRIVE_H
