/**
 *file validationFormat.cpp
 * author Gaya Kaddour
 */

#include "validationFormat.h" 
#include <sstream> 
#include <iostream> 
#include <vector> 
#include <algorithm> 

/**
 * name space util pour le dévloppement des fonctions
 */
namespace util 

/**
 * fonction bool validePointCardinal 
 *          pour valider un point cardinal d'une borne
 * @param p_cardinalite
 * @return 
 */
{ 
  bool validePointCardinal(const std::string& p_cardinalite) 
  { 
    return (p_cardinalite.empty() || p_cardinalite == "N" || p_cardinalite == "S" || p_cardinalite == "E" || p_cardinalite == "O"); 
  }

} 
 /** bool valideLigneCVSBorneStationnement(const std::string& p_ligne)    
  { 
    std::vector<std::string> tokens; 
    std::stringstream ss(p_ligne); 
    std::string token;

  while (std::getline(ss, token, ',')) 
    { 
      tokens.push_back(token); 
    } 
   if (tokens.size() != 7) 
     {
       return false;    // La ligne ne contient pas le bon nombre de champs

     } 
    
    // Vérification des contraintes sur les champs 
    if (tokens[4].empty() || tokens[5].empty() || tokens[6].empty()) 
      { 
        return false; // Les champs ID_VOIE_PUBLIQUE, NOM_TOPOGRAPHIQUE, LONGITUDE ou LATITUDE sont vides
      }
    if (!util::validePointCardinal(tokens[3])) 
      { 
        return false; // La COTE_RUE n'est pas un point cardinal valide 
      } 
    try 
     { 
        
        int (longitude) = std::stoi(tokens[5]); 
        int (latitude) = std::stoi(tokens[6]); 
        
        if (longitude != -71 || latitude != 46)
          { 
            return false; // La longitude n'est pas -71 ou la latitude n'est pas 46 
          }  
       catch (std::invalid_argument& e) 
             { 
               return false; // Erreur de conversion en entier pour la longitude ou la latitude 
      
             }
        }
      return (true); // La ligne est valide
  }
    
  bool valideFichierBornesStationnement(std::istream& p_fluxBornesStationnement) 
  { 
    std::string line; 
    std::getline(p_fluxBornesStationnement, line); // Lire la premièr
    
    if (line != "ID,NO_BORNE,COTE_RUE,ID_VOIE_PUBLIQUE,NOM_TOPOGRAPHIQUE,LONGITUDE,LATITUDE") 
      { 
        return false;// L'en-tête ne correspond pas au format attendu
      }  
    while (std::getline(p_fluxBornesStationnement, line))
      {
        if (line.empty()) 
          { break; // Fin du fichier 
          }
        if (!valideLigneCVSBorneStationnement(line)) 
          { 
            return false;  // Une ligne du fichier n'est pas valide
          } 
      } 
    return true; // Le fichier est conforme 
  }
  
  
  
  
#include "validationFormat.h" 
#include <iostream> 
#include <fstream> 
  int 
  main() 
  { 
     // Test de validation d'une ligne CSV de bornes de stationnement
    std::string ligneCSV = "1,1234,N,5678,Rue de Test,-71,46";
    if (util::valideLigneCVSBorneStationnement(ligneCSV))
      {
        std::cout << "La ligne CSV est valide." << std::endl;
      } 
    else 
      {
        std::cout << "La ligne CSV n'est pas valide." << std::endl; 
      } 
         // Test de validation d'un fichier de bornes de stationnement 
    std::ifstream fichier("fichierBornesStationnement.csv"); 
    if (fichier.is_open()) 
      { 
        if 
            (util::valideFichierBornesStationnement(fichier)) 
          { 
            std::cout << "Le fichier de bornes de stationnement est conforme." << std::endl;
          } 
        else 
          { 
            std::cout << "Le fichier de bornes de stationnement n'est pas conforme." << std::endl;
          } 
        fichier.close(); 
      } 
    else 
      { 
        std::cerr << "Impossible d'ouvrir le fichier." << std::endl; 
      } 
    return 0;}
  */