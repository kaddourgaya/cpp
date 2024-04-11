/* 
 * File:   RegistreBorne,h
 *\brief Déclaration de la classe RegistreBorne 
 * Author: Gaya Kaddour
 */

#ifndef REGISTREBORNE_H
#define REGISTREBORNE_H

#include "Borne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "ContratException.h"

#include <vector>
#include <string>
#include <memory>

namespace bornesQuebec
{
 /**
 \class RegistreBorne
  * \brief classe pour gérer la gestion des bornes fontaines et stationnements
 */
class RegistreBorne
{
  public:  
    RegistreBorne(const std::string& p_nomRegistreBorne);
    RegistreBorne(const RegistreBorne& p_RegistreBorne);
    
    const std::string& reqNomRegistre() const;
    const size_t reqNombreBorne() const;

    void ajouteBorne(const Borne& p_borne);
    
    std::string reqRegistreBorneFormate() const;

    //la méthode clone() ?? 

    private:
      std::string m_nomRegistreBorne;
      std::vector<Borne*> m_bornes;
      
      void copieVecteur ( const RegistreBorne& p_RegistreBorne);
      
      RegistreBorne& operator=(const RegistreBorne& p_RegistreBorne);
      
      void verifieInvariant() const;



};

}

#endif /* REGISTREBORNE_H */

