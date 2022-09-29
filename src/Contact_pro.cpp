#include "../includes/Contact_pro.h"

Contact_pro::Contact_pro(int id,std::string nom, std::string prenom, char sexe, std::string nom_entreprise, statut_juridique stat_jur, int numero,
std::string rue, std::string Complement, std::string code_p, std::string ville, std::string ad_mail):Contact(id,nom,prenom,sexe,numero,rue,Complement,code_p,ville)
{
    try
    {
        this->nom_entreprise=nom_entreprise;
        this->stat_jur=stat_jur;
        this->setad_mail(ad_mail);
    }
        catch(const int& ex)
    {
        std::cout << "Erreur (int) " << ex<<"\n";
    }
    catch(monXception::MonException& ex)
    {
        std::cout << "Erreur : " << ex.what()<<"\n";
    }
    catch(std::exception& ex)
    {
        std::cout << "Erreur (exception): " << ex.what();
    }
    catch(...)
    {
        std::cout << std::endl << "Erreur non geree !!!" << std::endl;
    }

}


Contact_pro::~Contact_pro()
{
    std::cout<<"Destruction de ct pro \n";
}


void Contact_pro::info()
{

    std::cout<<"\nProfessionnel : " << std::setfill('0') << std::setw(5)<<this->Getid()<<"\n\n";
    std::cout<<"       "<<"Societe : "<<this->nom_entreprise<<"\n";
    std::cout<<"       "<<this->underline<<"Contact"<<this->reset<<" : ";
    this->afficherNom();
    std::cout<<"       "<<this->blue <<this->getnum_ad()<<", "<<this->getrue()<<"\n";
    std::cout<<"       "<<this->getcp()<<" "<<this->getville()<<this->reset<<"\n\n";
    std::cout<<"       Mail: "<<this->ad_mail<<"\n";

}
