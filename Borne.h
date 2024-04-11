/* 
 * File:   BORNE.h
 * Brief Déclaration de la classe Borne , classe abstraite
 * Author: GAYA KADDOUR
 * Vlidée le 10 Avril 2024
 */

#ifndef BORNE_H
#define BORNE_H

#include <iostream>
#include <string>
#include <memory>
#include <sstream>

#include "ContratException.h"
#include "validationFormat.h"




/**
*\namespace bornesQuebec  
*\brief du dévloppement des bornes 
 */
namespace bornesQuebec
{
/**
*\class Borne 
*\brief classe abstraite qui permet de gérer des bornes
 */ 
class Borne
{
public:
  Borne (int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude);
  virtual ~Borne () {};
  int reqIdentifiant() const;
  const std::string reqIdentifiantVoiePublique() const;
  const std::string reqNomTopographique() const;
  double reqLongitude() const;
  double reqLatitude() const;
  
  void asgNomTopographique(const std::string& p_nomTopographique);
  
  bool operator==(const Borne& p_borne) const;
  
  virtual std::string reqBorneFormate() const = 0; 
  
  virtual Borne* clone() const = 0;
   
  
protected:
  int m_identifiant;
  std::string m_identifiantVoiePublique;
  std::string m_nomTopographique;
  double m_longitude;
  double m_latitude;
  
private:
  void verifieInvariant() const;
  
};

} // fin du namespace bornesQuebec

#endif /* BORNE_H */

