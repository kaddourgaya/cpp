/**
 *file ; gestionRegistre.cpp
 * author : Gaya Kaddour
 */

#include "Borne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "RegistreBorne.h"
#include "validationFormat.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace util;
using namespace bornesQuebec;

void demandersaisieBorneFontaine (RegistreBorne& p_registreborne);
void demandersaisieBorneStationnement (RegistreBorne& p_registreborne);

int main()
{
    {
    //création du registre
      RegistreBorne unRegistreBorne("bornes de l'agglomération de la ville de Québec");
    //Titre de la section pour la saisie des informations des différentes bornes.
      cout<<"Contenu du registre :"<<endl;
      cout<<"Registre : bornes de l'agglomération de la ville de Québec"<<endl;
      
      string espaceTirets = "----------------------------------------------";
      
      //BorneFontaine
      cout<<espaceTirets<<endl;
      cout<<"Borne fontaine"<<endl;
      cout<<espaceTirets<<endl;
      
      //Récuperer les information sur la borne Fontaine et 
      // l'ajout de l'objet au registre
      
      demandersaisieBorneFontaine (unRegistreBorne);
      
      //Borne Stationnement
      cout<<espaceTirets<<endl;
      cout<<"Borne de stationnement"<<endl;
      cout<<espaceTirets<<endl;
      
       //Récuperer les information sur la borne Fontaine et 
      // l'ajout de l'objet au registre
      
      demandersaisieBorneStationnement(unRegistreBorne);
      
      // affichage du registre
      
      cout<<unRegistreBorne.reqRegistreBorneFormate ();
    }
    return 0;
}

/**
 *\fonction demandersaisieBorneFontaine (RegistreBorne& p_registreborne)
 * \brief Fonction permet de saisir les information d'une borne fontaine
 *        et ajouter cette borne au registre
 * \pram[in] p_registreborne 
 */

void demandersaisieBorneFontaine (RegistreBorne& p_registreborne)
{
  char buffer [256];
   int identifiant;
   string identifiantVoiePublique; 
   string nomTopographique;
   double longitude;
   double latitude; 
   string ville; 
   string arrondissement;
   
   cout<<"Enregistrement d’une borne fontaine :"<<endl;
   do 
     {
       cout<<"Entrez l'identifiant de la borne valide:"<<endl;
       cin.getline(buffer, 256);
       identifiant = stoi (buffer);
     }
   while (identifiant <= 0);
   
   cout<<"Entrez l'identifiant de la Voie Publique de la borne valide:"<<endl;
   cin.getline (buffer, 256);
   identifiantVoiePublique = buffer;
   
   do 
     {
       cout<<"Entrez le nom topographique valide:"<<endl;
       cin.getline (buffer, 256);
       nomTopographique = buffer;
     }
   while (nomTopographique.empty ());
   
   cout<<"Entrez la longitude:"<<endl;
   cin.getline (buffer, 256);
   longitude = stoi (buffer);
   
   cout<<"Entrez la latitude:"<<endl;
   cin.getline (buffer, 256);
   latitude = stoi (buffer);
   
   cout<<"Entrez le nom de la ville :"<<endl;
   cin.getline (buffer, 256);
   ville = buffer;
   
   do
     {
       cout<<"Entrez le nom de l'arrondissement :"<<endl;
       cin.getline (buffer, 256);
       arrondissement = buffer;
     }
   while (ville != "Québec");
   
   BorneFontaine uneBorneFontaine (identifiant, identifiantVoiePublique,
                                   nomTopographique, longitude, latitude,
                                   ville, arrondissement);

   p_registreborne.ajouteBorne (uneBorneFontaine);
   
   
}

/**
 *\fonction demandersaisieBorneStationnement (RegistreBorne& p_registreborne)
 * \brief Fonction permet de récuperer les information d'une borne de 
 *         stationnement et l'ajouter dans le registre 
 * \param[in] p_registreborne
 */

void demandersaisieBorneStationnement (RegistreBorne& p_registreborne)
{
   char buffer [256];
   
   int identifiant;
   string identifiantVoiePublique; 
   string nomTopographique;
   double longitude;
   double latitude;
   int numBorne;
   string coteRue;
   
   cout<<"Enregistrement d’une borne de stationnement :"<<endl;
   do 
     {
       cout<<"Entrez l'identifiant de la borne valide:"<<endl;
       cin.getline(buffer, 256);
       identifiant = stoi (buffer);
     }
   while (identifiant <= 0);
   
   cout<<"Entrez l'identifiant de la Voie Publique de la borne valide:"<<endl;
   cin.getline (buffer, 256);
   identifiantVoiePublique = buffer;
   
   do 
     {
       cout<<"Entrez le nom topographique valide:"<<endl;
       cin.getline (buffer, 256);
       nomTopographique = buffer;
     }
   while (nomTopographique.empty ());
   
   cout<<"Entrez la longitude:"<<endl;
   cin.getline (buffer, 256);
   longitude = stoi (buffer);
   
   cout<<"Entrez la latitude:"<<endl;
   cin.getline (buffer, 256);
   latitude = stoi (buffer);
   
   do 
     {
       cout<<"Entrez le numéro de la borne de stationnement:"<<endl;
       cin.getline (buffer, 256);
       numBorne = stoi (buffer);
     }
   while (numBorne > -9999 || numBorne < 9999);
   
   do 
     {
       cout<<"Entrez le cote de la rue (N, S, E, O) :"<<endl;
       cin.getline (buffer, 256);
       coteRue = buffer;
     }
   while (!(util::validePointCardinal (coteRue)));
   
   BorneStationnement uneBorneStationnement (identifiant, identifiantVoiePublique,
                                   nomTopographique, longitude, latitude,
                                   numBorne, coteRue);

   p_registreborne.ajouteBorne (uneBorneStationnement);
}