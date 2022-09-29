#include "../includes/Annuaire.h"


Annuaire::Annuaire()
{
    //ctor
}

Annuaire::~Annuaire()
{


    for (std::map<int ,Contact*>::iterator it=this->repertoire.begin(); it!=this->repertoire.end(); ++it){


        std::cout << "destruction de l'element "<< it->first <<"\n";
        if (it->second!=nullptr)
        {
            delete it->second;
            it->second=nullptr;

        }

        }
        std::cout << "information detruites : "<<"\n";

        this->repertoire.clear();
    
}
void Annuaire::afficher()
{
char aff;

std::cout<<"\033[1;37m"<<"Section affichage  \n";
std::cout<<" A:prive , B:pro , C:tout \n";
std::cin>>aff;
std::cout<< "\033[0m"<<"\n ";

switch(aff){
    case('A'):
        this->afficherprive();
        break;
    case('B'):
        this->afficherpro();
        break;
    case('C'):
        this->affichertout();
        break;
    default:
        std::cout<<"non reconnu \n";
        break;
}
}

void Annuaire::exporter()
{
    std::cout<<" en coures d'exportation des contacts dans des fichiers privates.dat et pros.dat \n";
    
    std::ofstream priv("Private.dat");
    std::ofstream pros("Pros.dat");
    for(auto &e:this->repertoire)
    {
        Contact_prive *prv=dynamic_cast<Contact_prive*>(e.second);
        if(prv!=nullptr)
        {
            // Create and open a text file
            std::time_t t = std::time(0);   // temps actuel
            std::tm* now = std::localtime(&t);//temps local 
            priv<<"\nParticulier : "<< std::setfill('0') << std::setw(5)<<prv->Getid()<<"\n\n";
            priv<<"       ";
            if(prv->Getsexe()=='M')
            {
                    priv<<"M. "<< prv->Getnom()<<" "<<prv->Getprenom()<<"\n";
            }else if( prv->Getsexe()=='F')
            {
                    priv<<"Mme. "<< prv->Getnom()<<" "<<prv->Getprenom()<<"\n";
            }

            priv<<"       "<<prv->getnum_ad()<<", "<<prv->getrue()<<"\n";
            priv<<"       "<<prv->getcp()<<" "<<prv->getville()<<"\n";
            priv<<"       "<<"Age : "<<2022-(prv->getannee())<<((now->tm_mon+1)==prv->getmois()&&(now->tm_mday)==prv->getjour()?" ans et Bon anniversaire ! ":" ans ") <<"\n";

            

        }

        Contact_pro *pro=dynamic_cast<Contact_pro*>(e.second);
        if(pro!=nullptr)
        {
            pros<<"\nProfessionnel : " << std::setfill('0') << std::setw(5)<<pro->Getid()<<"\n\n";
            pros<<"       "<<"Societe : "<<pro->getnom_entreprise()<<"\n";
            pros<<"       "<<"Contact : ";
            if(pro->Getsexe()=='M')
            {
                    pros<<"M. "<< pro->Getnom()<<" "<<pro->Getprenom()<<"\n";
            }else if( pro->Getsexe()=='F')
            {
                    pros<<"Mme. "<< pro->Getnom()<<" "<<pro->Getprenom()<<"\n";
            }
            
            pros<<"       "<<pro->getnum_ad()<<", "<<pro->getrue()<<"\n";
            pros<<"       "<<pro->getcp()<<" "<<pro->getville()<<"\n\n";
            pros<<"       Mail: "<<pro->getad_mail()<<"\n";
            

        }


    }

    priv.close();
    pros.close();


}

void Annuaire::modifier()
{
    int m_id;

    std::cout<<"\033[1;37m"<<"\n entrez l'ID du contact a modifier  : ";
    std::cin>>m_id;

    if(this->repertoire.count(m_id)!=0)
    {
        int m_numad;
        std::cout<<"\n entrez le nouveau numero de rue : ";
        std::cin>>m_numad;
        this->repertoire[m_id]->setnum_ad(m_numad);
        std::string m_rue;
        std::cout<<"\n entrez la  rue : ";
        std::cin.ignore();
        std::getline(std::cin,m_rue);

        this->repertoire[m_id]->setRue(m_rue);
        
        std::string m_cp;

        std::cout<<"\n entrez le code postal : ";
        std::cin.ignore();
        std::getline(std::cin,m_cp);
        this->repertoire[m_id]->setcp(m_cp);
        
        std::string m_ville;
        std::cout<<"\n entrez la ville  : ";
        std::getline(std::cin,m_ville);
        this->repertoire[m_id]->setville(m_ville);

        std::string m_comp;
        std::cout<<"\n entrez le complement s il y en a  : ";
        std::getline(std::cin,m_comp);
        this->repertoire[m_id]->setComlement(m_comp);

        std::cout<<" l addresse a bien ete modifiee \n";
        std::cout<< "\033[0m"<<"\n ";




    }else{

        std::cout<<" ID introuvable \n";
    }



}

void Annuaire::afficherprive(){
    for( auto &e : this->repertoire){
    Contact_prive *c= dynamic_cast<Contact_prive*>(e.second);

    if(c!=nullptr){
        e.second->info();
    }


    }
}
void Annuaire::afficherpro(){

    for( auto &e : this->repertoire){
    Contact_pro *c= dynamic_cast<Contact_pro*>(e.second);

    if(c!=nullptr){
        e.second->info();
    }


    }

}
void Annuaire::affichertout(){

    for( auto &e : this->repertoire){
            e.second->info();
        }

    }
    void Annuaire::supprimer()
    {
    int a_sup;
    std::cout<<"\033[1;37m"<<"entrez l'identifiant du contact à suprimer : ";
    std::cin>>a_sup;

    if(this->repertoire.count(a_sup)!=0)
    {

    std::cout<<"b size : "<<this->repertoire.size()<<"\n";

    delete this->repertoire[a_sup];

    this->repertoire.erase(a_sup);

    std::cout<<"a size : "<<this->repertoire.size()<<"\n";


    }
    else{
        std::cout<<" ID non existant ! \n";
    }
    std::cout<< "\033[0m"<<"\n ";
}



void Annuaire::Ajouter()
{
    std::cout<<" \n"<< "\033[1;37m"<<"Entrez 1 pour un contact prive et 2 Pour un contact pro"<<"\n";
    int short inp;
    std::cin>>inp;
    if (inp==1)
    {
    this->AjouterCtPrive();

    }else if(inp==2)
    {
    this->AjouterCtPro();

    }
    std::cout<< "\033[0m"<<"\n ";


}
void Annuaire::AjouterCtPro()
{
    int id;
    std::cout<<" \n entrez le numero id que vous vous souhaitez attribuer : ";
    std::cin>>id;

    std::string nom;
    std::cout<<" \n entrez le nom : ";
    std::cin>>nom;
    std::string prenom;
    std::cout<<" \n entrez le prenom : ";
    std::cin>>prenom;
    char sexe;
    std::cout<<" \n entrez sexe M ou F : ";
    std::cin>>sexe;

    std::string nom_entreprise;
    std::cout<<" \n entrez le nom de l'entreprise  : ";
    std::cin>>nom_entreprise;

    std::cout<<" \n entrez le numero de la voie (addresse) : ";
    int numero;
    std::cin>>numero;
   

    std::cout<<" \n entrez le nom de la Rue : ";
    std::string rue;
    std::cin.ignore();
    std::getline(std::cin,rue);
    


    std::cout<<" \n entrez le complement : ";
    std::string complement;
    std::getline(std::cin,complement);
    std::cout<<" \n entrez le code postal : ";
    std::string code_p;
    std::cin>>code_p;
    std::cout<<" \n entrez la Ville : ";

    std::string ville;
    std::cin.ignore();
    std::getline(std::cin,ville);
    std::cout<<"\n entrez l'addresse mail : ";
    std::string ad_mail;
    std::cin>>ad_mail;
    statut_juridique stat_jur=SARL;
    Contact_pro* c=new Contact_pro(id,nom,prenom,sexe,nom_entreprise,stat_jur,numero,rue,complement,code_p,ville,ad_mail);
    this->Ajouter(c);

}

void Annuaire::AjouterCtPrive()
{
    int id;
    std::cout<<" \n entrez le numero id que vous vous souhaitez attribuer : ";
    std::cin>>id;

    std::string nom;
    std::cout<<" \n entrez le nom : ";
    std::cin>>nom;
    std::string prenom;
    std::cout<<" \n entrez le prenom : ";
    std::cin>>prenom;
    char sexe;
    std::cout<<" \n entrez sexe M ou F : ";
    std::cin>>sexe;


    std::cout<<" \n entrez le numero de la voie (addresse) : ";
    int numero;

    std::cin>>numero;

   

    std::cout<<" \n entrez le nom de la Rue : ";

    std::string rue;
    std::cin.ignore();
    std::getline(std::cin,rue);
    std::cout<<" \n entrez le complement : ";
    std::string complement;
    std::getline(std::cin,complement);

    std::cout<<" \n entrez le code postal : ";
    std::string code_p;
    std::getline(std::cin,code_p);

    std::cout<<" \n entrez la Ville : ";

    std::string ville;

    std::getline(std::cin,ville);

    std::cout<<" \n entrez le jour de naissance : ";
    int jour;
    std::cin>>jour;

    std::cout<<" \n entrez le mois de naissance : ";

    int mois;
    std::cin>>mois;

    std::cout<<" \n entrez l annee de naissance : ";

    int annee;
    std::cin>>annee;

    Contact_prive* c=new Contact_prive(id,nom,prenom,sexe,numero,rue, complement,code_p,ville,jour,mois,annee);
    this->Ajouter(c);

}

void Annuaire::Ajouter(Contact*c)
{
    this->repertoire[c->Getid()]=c;
}

void Annuaire::rechercher()
{
    char choix_rech;

    std::cout<< "\033[1;37m" <<"\nRechercher par Nom(N),Ville(V),id(I), code postal(C),departement(D) ? :\n";
    std::cin>>choix_rech;
    switch(choix_rech){
        case 'N':
            this->rechercherNom();
            break;
        case 'V':
            this->rechercherVille();
            break;
        case 'I':
            this->rechercherNum();
            break;
        case 'C':
            this->rechercherCP();
            break;
        case 'D':
            this->rechercherDep();
            break;
            }

}

void Annuaire::rechercherNom()
{
    std::string n;
    std::cout<<"entrez le Nom(en Maj) : ";
    std::cin>>n;
    std::cout<< "\033[0m"<<"\n ";
    for( auto e : this->repertoire)
    {
        if(e.second->Getnom()==n)
        {   

            e.second->info();

        }
    }

}

void Annuaire::rechercherVille()
{
std::string v;
    std::cout<<"entrez la ville (en Maj) : ";
    std::cin>>v;
    std::cout<< "\033[0m"<<"\n ";
    for( auto e : this->repertoire)
    {
        if(e.second->getville()==v)
        {
            e.second->info();

        }
    }
}

void Annuaire::rechercherNum()
{
int i;
    std::cout<<"entrez l'ID  : ";
    std::cin>>i;
    std::cout<< "\033[0m"<<"\n ";
    for( auto e : this->repertoire)
    {
        if(e.second->Getid()==i)
        {
            e.second->info();

        }
    }

}

void Annuaire::rechercherCP()
{
    std::string cp;
    std::cout<<"entrez le code postal : ";
    std::cin>>cp;
    std::cout<< "\033[0m"<<"\n ";
    for( auto e : this->repertoire)
    {
        if(e.second->getcp()==cp)
        {
            e.second->info();

        }
    }
}

void Annuaire::rechercherDep()
{
std::string dp;
    std::cout<<"entrez le numero de departement : ";
    std::cin>>dp;
    std::cout<< "\033[0m"<<"\n ";
    for( auto e : this->repertoire)
    {
        std::stringstream ss;
        std::string dep;
        ss<<e.second->getcp();
        ss>>dep;

        if(dep[0]==dp[0] && dep[1]==dp[1] )
        {
            e.second->info();

        }
    }
    }
