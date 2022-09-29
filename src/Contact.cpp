#include "../includes/Contact.h"




Contact::~Contact()
{
    std::cout<<"contact detruit \n";

}
Contact::Contact(int id ,std::string nom, std::string prenom,char sexe,int num_ad,std::string rue, std::string complement,std::string code_p,std::string ville)
{
    try
    {
        this->Setid(id);
        this->Setnom(nom);
        this->Setprenom(prenom);
        this->Setsexe(sexe);
        this->num_ad=num_ad;
        this->setRue(rue);
        this->setComlement(complement);
        this->setcp(code_p);
        this->setville(ville);
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
void Contact::afficherNom()
{
  
    

    if(sexe=='M')
    {
        std::cout<<this->green <<"M. "<< this->nom<<" "<<this->prenom<<this->reset <<"\n";
    }else if( sexe=='F')
    {
        std::cout<<this->green <<"Mme. "<< this->nom<<" "<<this->prenom<<this->reset <<"\n";
    }
}
