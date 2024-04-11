/* 
 * File:   BorneStationnement.h
 * \brief Déclaration de la classe BorneStationnement 
 *        qui hérite de la classe Borne
 * Author: Gaya Kaddour
 */

#ifndef BORNESTATIONNEMENT_H
#define BORNESTATIONNEMENT_H

#include "Borne.h"
#include "ContratException.h"


namespace bornesQuebec
{

 /**
 * \class BorneStationnement
 * \brief Cette classe permet de gérer les bornes de stationnement. 
 *       Elle hérite de Borne
 */
class BorneStationnement: public bornesQuebec::Borne
{
public:
  BorneStationnement (int p_identifiant, 
   std::string& p_identifiantVoiePublique,
   std::string& p_nomTopographique, 
   double p_longitude, 
   double p_latitude, 
   int p_numBorne, 
   std::string& p_coteRue);

  const int reqNumBorne () const;
  
  const std::string& reqCoteRue () const;
  
  virtual Borne* clone() const;
  
  virtual std::string reqBorneFormate () const;
  
  
private:
  
  int m_numBorne;
  std::string m_coteRue;

    void verifieInvariant () const;
};

} // namespace BornesQuébec


#endif /* BORNESTATIONNEMENT_H */

