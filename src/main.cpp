#include <iostream>

#include"../includes/Contact_prive.h"
#include"../includes/Contact_pro.h"
#include"../includes/Annuaire.h"
using namespace std;

int main()
{
    Annuaire M;
    M.Ajouter(new Contact_prive(0,"Macron","manu",'M',25," rue de la pompe","rdc","75000","PARIS",29,9,1996));
    M.Ajouter(new Contact_prive(2,"Gandhi","mahatma",'M',25," rue de la benediction ","rdc","69000","LYON",29,9,1900));

    std::cout<<"\033[1;37m" <<" Bienvenue sur votre Annuaire "<< "\033[0m"<<"\n ";
    
    char inp;
    do{
        std::cout<<"\033[1;37m" <<"\n\n                            Que souhaitez vous faire ?  "<<"\n\n ";
        std::cout<<"-----------------------------------------------------------------------------------------\n";
        std::cout<<"| A:Ajouter R:Rechercher F:Afficher M:Modifier(addresse) S:Supprimer E:Exporter Q:Quitter |\n";
        std::cout<<" -----------------------------------------------------------------------------------------\n"<<"\033[0m";

        std::cin>>inp;
        switch (inp)
        {

        case('A'):
            M.Ajouter();
            break;

        case('R'):
            M.rechercher();

            break;
        case('F'):
            M.afficher();
            break;
        case('M'):
            M.modifier();

            break;
        case('S'):
            M.supprimer(); 
            break;
        case ('E'):
            M.exporter();
            break;
        case('Q'):
            std::cout<<" A votre disposition \n";
            break;
      
        
        default:
            std::cout<<"action inconnue \n";
            break;
        }



    }while(inp!='Q');


    return 0;
}
