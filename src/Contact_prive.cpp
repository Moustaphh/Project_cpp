#include "../includes/Contact_prive.h"
#include <ctime>

Contact_prive::Contact_prive(int id, std::string nom, std::string prenom, char sexe, int numero, std::string rue, std::string complement,
    std::string code_p, std::string ville, int jour, int mois, int annee):Contact(id,nom,prenom,sexe,numero,rue,complement,code_p,ville)
{

this->jour=jour;
this->mois=mois,
this->annee=annee;

}


void Contact_prive::info()
{

    std::time_t t = std::time(0);   // temps actuel
    std::tm* now = std::localtime(&t);//temps local 
    std::cout<<"\nParticulier : "<< std::setfill('0') << std::setw(5)<<this->Getid()<<"\n\n";
    std::cout<<"       ";
    this->afficherNom();
    std::cout<<"       "<<this->blue <<this->getnum_ad()<<", "<<this->getrue()<<"\n";
    std::cout<<"       "<<this->getcp()<<" "<<this->getville()<<this->reset<<"\n\n";
    std::cout<<"       "<<"Age : "<<2022-(this->annee)<<((now->tm_mon+1)==this->mois&&(now->tm_mday)==this->jour?" ans et Bon anniversaire ! ":" ans ") <<"\n";


}


Contact_prive::~Contact_prive()
{
    std::cout<<"Destruction de ct prive \n";
}
