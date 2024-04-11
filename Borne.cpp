/* 
 * File:   Borne.cpp
 * Author: Gaya Kaddour
 *
 * Created on 29 mars 2024, 16 h 36
 */

#include <cstdlib>
#include "Borne.h"

using namespace std;
using namespace util;

namespace bornesQuebec
{

/*
 * \brief Constructeur de la classe Borne
 * \param[in] p_identifiant : l'identifiant de la borne
 * \pre doit etre supérieur strictement a 0
 * \param[in] p_identifiantVoiePublique : la voie sur laquelle la borne est située
 * \param[in] p_nomTopographique : nom du centre de chaussée
 * \pre ne doit pas etre vide
 * \param[in] p_longitude
 * \param[in] p_latitude
 * Destructeur de la classe Borne
 */

bornesQuebec::Borne::Borne (int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude):
  m_identifiant(p_identifiant),
  m_identifiantVoiePublique(p_identifiantVoiePublique),
  m_nomTopographique(p_nomTopographique), 
  m_longitude(p_longitude),
  m_latitude(p_latitude)
{
  PRECONDITION(p_identifiant > 0);
  PRECONDITION(!(p_nomTopographique.empty ()));
  
  POSTCONDITION(m_identifiant == p_identifiant);
  POSTCONDITION(m_identifiantVoiePublique == p_identifiantVoiePublique);
  POSTCONDITION(m_nomTopographique == p_nomTopographique);
  POSTCONDITION(m_longitude == p_longitude);
  POSTCONDITION(m_latitude == p_latitude);
  
  INVARIANTS();
}
/**
 * \brief Surcharge de l'opérateur de comparaison, se fait sur tous les attributs
 * \param[in] p_borne Une borne
 * @return un bool disant si les deux bornes sont égales ou non 
 */

bool Borne::operator==(const Borne& p_borne) const
{
  return reqIdentifiant() == p_borne.reqIdentifiant() && 
         reqIdentifiantVoiePublique() == p_borne.reqIdentifiantVoiePublique() &&
         reqNomTopographique() == p_borne.reqNomTopographique() &&
         reqLongitude() == p_borne.reqLongitude() &&
         reqLatitude() == p_borne.reqLatitude();
}

/**
 * \brief mutateur du nom topographique de la borne 
 * @param p_nomTopographique Le nouveau nom de la borne
 */
void Borne::asgNomTopographique(const std::string& p_nomTopographique)
{
  PRECONDITION (!(p_nomTopographique.empty ()));
  m_nomTopographique = p_nomTopographique;
  POSTCONDITION(m_nomTopographique == p_nomTopographique);
  INVARIANTS();
}

/**
 * \brief accesseur pour l'identifiant de la borne
 */
int Borne::reqIdentifiant() const 
{
  return m_identifiant; 
}

/**
 * \brief accesseur pour l'identifiant de la voie public 
 */
const std::string Borne::reqIdentifiantVoiePublique() const
{
  return m_identifiantVoiePublique;
}

/**
 * \brief accesseur pour le nom topographique  
 */
const std::string Borne::reqNomTopographique() const
{
    return m_nomTopographique;
}

/**
 * \brief accesseur pour la latitude
 */
double Borne::reqLatitude() const
{
  return  m_latitude;
}

/**
 * \brief accesseur pour la longitude 
 */
double Borne::reqLongitude() const
{
  return m_longitude;
}

/**
 * \brief methode virtuelle d'acces aux informations d'une borne
 * \return un string contenant les informations formattées d'une borne 
 */
std::string Borne::reqBorneFormate() const
{
  std::ostringstream oss;
  oss<<"Identifiant de la borne :"<<m_identifiant<<endl;
  oss<<"Voie publique     :"<<m_identifiantVoiePublique<<endl;
  oss<<"Nom topographique :"<<m_nomTopographique<<endl;
  oss<<"Latitude          :"<<m_latitude<<endl;
  oss<<"Longitude         :"<<m_longitude<<endl;
  return oss.str();
}

void Borne::verifieInvariant () const 
{
  INVARIANT(m_identifiant > 0);
  INVARIANT(!(m_nomTopographique.empty ()));
}

}//namespace BornesQuébec

