#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#include <string>
#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include"Monexception.h"
#include <limits.h>

#define NAME_SIZE 30

class Contact
{
    private:
        int id;
        std::string nom;
        std::string prenom;
        char sexe;
        int num_ad;
        std::string Rue, Complement, Code_p,Ville;


    public:
        const std::string red="\033[0;31m";
        const std::string green="\033[1;32m";
        const std::string blue="\033[1;34m";
        const std::string underline="\033[4m";
        const std::string reset="\033[0m";

        int getnum_ad(){return this->num_ad;}
        void setnum_ad(int val){this->num_ad=val;}

        std::string getrue(){return this->Rue;}
        std::string getcp(){return this->Code_p;}
        std::string getville(){return this->Ville;}
        void setRue(std::string R){this->Rue=R;}
        void setComlement(std::string C){this->Complement=C;}
        void setcp(std::string c){this->Code_p=c;}
        void setville(std::string v){this->Ville=v;}
        Contact(int id , std::string nom, std::string prenom,char sexe,int num_ad,std::string rue, std::string Complement,std::string code_p,std::string ville);
        virtual ~Contact();

        int Getid() { return this->id; }
        void Setid(int val) { this->id = val; }
        std::string Getnom() { return this->nom; }
        void Setnom(std::string val) {
        if(val.length()<NAME_SIZE)
        {
        this->nom = val;
        for(auto e : this->nom){toupper(e);}//conversion du nom en maj
        }else{
            throw monXception::MonException("taille trop grande  !");
        }
        }
        std::string Getprenom() { return this->prenom; }
        void Setprenom( std::string val) {
        if(val.length()<NAME_SIZE)
        {
        this->prenom = val;
        toupper(this->prenom[0]);//premère lettre du prenom en maj
        }else{
            throw monXception::MonException("taille trop grande  !");
        }
        }
        char Getsexe() { return this->sexe; }
        void Setsexe(char val) { this->sexe = val; }


        void afficherNom();

        virtual void  info()=0;



};

#endif // CONTACT_H
