#ifndef CONTACT_PRO_H
#define CONTACT_PRO_H
#include"Contact.h"

enum statut_juridique{SARL, SA, SAS, EURL};

class Contact_pro:public Contact
{

    private:
    std::string nom_entreprise;
    statut_juridique stat_jur;
    std::string ad_mail;




    public:
        Contact_pro(int id,std::string nom, std::string prenom,char sexe,std::string nom_entreprise, statut_juridique stat_jur,
            int numero,std::string rue, std::string complement, std::string code_p,std::string ville,std::string ad_mail);

        virtual ~Contact_pro();
        void info();
        std::string getnom_entreprise(){return this->nom_entreprise;}
        std::string getad_mail(){return this->ad_mail;}
        void setad_mail(std::string ad ){

            std::size_t found = ad.find('@');

            if(found!=std::string::npos)
            {
                this->ad_mail=ad;
            }else{
                throw monXception::MonException("adresse mail invalide !");
            }
        }
};

#endif // CONTACT_PRO_H
