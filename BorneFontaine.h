

/* 
 * File:   BorneFontaine.h
 * \brief Déclaration de la classe BorneFontaine qui hérite de la classe Borne
 * Author: Gaya Kaddour
 */

#ifndef BORNEFONTAINE_H
#define BORNEFONTAINE_H


#include "Borne.h"
#include "ContratException.h"
#include <string>
#include <memory>

namespace bornesQuebec
{

 /**
 * \class BorneFontaine
 * \brief Cette classe permet de gérer les bornes-fontaines du Québec. Elle hérite de Borne
 */
class BorneFontaine : public bornesQuebec::Borne {
  public:
     BorneFontaine (int p_identifiant,
                  std::string& p_identifiantVoiePublique, 
                  std::string& p_nomTopographique, 
                  double p_longitude, 
                  double p_latitude, 
                  const std::string& p_ville, 
                  const std::string& p_arrondissement);
    const std::string& reqVille() const;
    const std::string& reqArrondissement() const;
  
    virtual Borne* clone() const;
    
    virtual std::string reqBorneFormate() const;
    
  private:
    void verifieInvariant () const;
    
    std::string m_ville;
    std::string m_arrondissement;   
};

}//namespace BornesQuébec

#endif // BORNEFONTAINE_H

