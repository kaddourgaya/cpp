/**
 /**
 * \file BorneFontaine.cpp
 * \brief Implantation de la classe BorneStationnement
 * \author Gaya Kaddour
 */

#include "BorneStationnement.h"
#include "validationFormat.h"
#include "ContratException.h"
#include <sstream>
#include <utility>

using namespace std;
using namespace util;
using namespace bornesQuebec;

/**
 * \brief Constructeur de la classe BorneFontaine
 * \param[in] p_identifiant : l'identifiant de la borne
 * \param[in] p_nomTopographique : nom du centre de chaussée
 * \param[in] p_longitude
 * \param[in] p_latitude
 * \param[in] p_numBorne : Le numéro de la borne 
 * \param[in] p_coteRue : Le coté par rapport au centre de chaussée 
 *            où est la borne, il correspend a un point cardinal
 */

BorneStationnement::BorneStationnement(int p_identifiant, 
   std::string& p_identifiantVoiePublique,                                    
   std::string& p_nomTopographique, 
   double p_longitude, 
   double p_latitude, 
   int p_numBorne, 
   std::string& p_coteRue) : bornesQuebec::Borne 
(p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude),
m_numBorne(p_numBorne), m_coteRue(p_coteRue)
{
  PRECONDITION (p_numBorne >= 0 && p_numBorne < 9999);
  PRECONDITION (util::validePointCardinal (p_coteRue));
  
  POSTCONDITION (m_numBorne == p_numBorne);
  POSTCONDITION (m_coteRue == p_coteRue);
  
  INVARIANTS ();
}

/**
 * \brief accesseur pour le numéro de la borne
 * \return le numéro de la borne
 */

const int BorneStationnement::reqNumBorne() const
{
  return m_numBorne;
}

/**
 * \brief accesseur pour le cote ou se trouve la borne
 * \return un point cardinal correspend au cote 
 */

const std::string& BorneStationnement::reqCoteRue() const
{
  return m_coteRue;
}

/**
 * \brief methode virtuelle d'acces aux informations d'une borne
 * \return un string contenant les nouvelles et les anciennes
  *        informations formattées d'une borne 
 */
string BorneStationnement::reqBorneFormate () const
{
  std::ostringstream oss;
  oss<< "Borne de stationnement"<<endl;
  oss<<"----------------------------------------------"<<endl;
  oss<<"Identifiant de la borne :"<<m_identifiant<<endl;
  oss<<"Nom topographique :"<<m_nomTopographique<<endl;
  oss<<"Latitude          :"<<m_latitude<<endl;
  oss<<"Longitude         :"<<m_longitude<<endl;
  oss<<"Numero de la borne :"<<m_numBorne<<endl;
  oss<<"Cote de la rue :"<<m_coteRue<<endl;
  return oss.str ();
}
/**
  * \breif Méthode qui permet de faire 
  *        une copie allouée sur le monceau de l'objet courant
  * @return Clone de l'objet BorneStationnement courant
  */
Borne* BorneStationnement::clone() const
{
  return new BorneStationnement(*this);
}

void BorneStationnement::verifieInvariant() const
{
  INVARIANT (m_numBorne >=0 && m_numBorne <= 9999 );
  INVARIANT (util::validePointCardinal (m_coteRue));
}