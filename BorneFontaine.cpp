/**
 /**
 * \file BorneFontaine.cpp
 * \brief Implantation de la classe BorneFontaine
 * \author Gaya Kaddour
 */



#include "BorneFontaine.h"
#include <sstream>


using namespace std;
using namespace bornesQuebec;

/**
 * \brief Constructeur de la classe BorneFontaine
 * \param[in] p_identifiant : l'identifiant de la borne
 * \param[in] p_identifiantVoiePublique : la voie sur laquelle la borne est située
 * \param[in] p_nomTopographique : nom du centre de chaussée
 * \param[in] p_longitude
 * \param[in] p_latitude
 * \param[in] p_ville : La ville ou se trouve la borne 
 * \param[in] p_arrondissement : ou se trouve la borne 
 */

BorneFontaine::BorneFontaine(int p_identifiant,
                  string& p_identifiantVoiePublique, 
                  string& p_nomTopographique, 
                  double p_longitude, 
                  double p_latitude, 
                  const string& p_ville, 
                  const string& p_arrondissement) : bornesQuebec::Borne 
(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude),
m_ville(p_ville), m_arrondissement(p_arrondissement) 
{
  PRECONDITION(!(p_arrondissement.empty ()) && p_ville == "Québec");
  
  POSTCONDITION(m_ville == p_ville);
  POSTCONDITION(m_arrondissement == p_arrondissement);
  
  INVARIANTS();
}

/**
 * \brief accesseur pour la ville de la borne
 */
const string& BorneFontaine::reqVille() const
{
  return m_ville;
}

/**
 * \brief accesseur pour l'arrondissement de la borne
 */
 const string& BorneFontaine::reqArrondissement() const
 {
   return m_arrondissement;
 }
 
 /**
 * \brief methode virtuelle d'acces aux informations d'une borne
 * \return un string contenant les nouvelles et les anciennes
  *        informations formattées d'une borne 
 */
 string BorneFontaine::reqBorneFormate() const
 {
   ostringstream oss;
   oss<<"Borne-fontaine"<<endl;
   oss<<"----------------------------------------------"<<endl;
   oss<<"Identifiant de la borne :"<<m_identifiant<<endl;
   oss<<"Voie publique     :"<<m_identifiantVoiePublique<<endl;
   oss<<"Nom topographique :"<<m_nomTopographique<<endl;
   oss<<"Latitude          :"<<m_latitude<<endl;
   oss<<"Longitude         :"<<m_longitude<<endl;
   oss<<"Ville :"<<m_ville<<endl;
   oss<<"Arrondissement :"<<m_arrondissement<<endl;
   return oss.str ();
 }
 
 /**
  * \breif Méthode qui permet de faire 
  *        une copie allouée sur le monceau de l'objet courant
  * @return Clone de l'objet BorneFontaine courant
  */
 Borne* BorneFontaine::clone() const
 {
   return new BorneFontaine(*this);
 }
 
 void BorneFontaine::verifieInvariant() const
 {
   INVARIANT (!(m_arrondissement.empty ()) && m_ville == "Québec");
 }


