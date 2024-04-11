/**
 /**
 * \file RegistreBorne.cpp
 * \brief Implantation de la classe RegistreBorne
 * \author Gaya Kaddour
 */


#include "RegistreBorne.h"
using namespace std;
using namespace bornesQuebec;
using namespace util;

/**
 * \brief constructeur de la classe RegistreBorne
 * @param p_nomRegistreBorne
 * \pre ne doit pas etre vide
 */
RegistreBorne::RegistreBorne(const std::string& p_nomRegistreBorne) 
: m_nomRegistreBorne(p_nomRegistreBorne)
{
  PRECONDITION(!(p_nomRegistreBorne.empty ()));
  
  POSTCONDITION(m_nomRegistreBorne == p_nomRegistreBorne);
  
  INVARIANTS ();

}

/**
 * \brief constructeur copie pour la classe RegistreBorne.
 * @param p_RegistreBorne est l'objet RegistreBorne original
 */
RegistreBorne::RegistreBorne(const bornesQuebec::RegistreBorne &p_RegistreBorne)
{
m_nomRegistreBorne = p_RegistreBorne.m_nomRegistreBorne;
copieVecteur(p_RegistreBorne);

POSTCONDITION (m_nomRegistreBorne == p_RegistreBorne.m_nomRegistreBorne);
POSTCONDITION (m_bornes.empty ());

INVARIANTS ();

}

/**
 * \brief accesseur pour le nom du registre
 * @return le nom du registre
 */
const string& RegistreBorne::reqNomRegistre() const
{
  return m_nomRegistreBorne;
}

/**
 * \brief méthode permettant de savoir combien de bornes sont enregistrées
 * @return un entier qui nous donne le nombre de bornes
 */
const size_t RegistreBorne::reqNombreBorne() const 
{
  return m_bornes.size();
}

/**
 * \brief méthode de formatage
 * @return un string contenat les informations d'un registre des bornes
 */
string RegistreBorne::reqRegistreBorneFormate() const 
{
  ostringstream oss;
  oss <<"Registre :"<<m_nomRegistreBorne<<endl;
  oss<<"Borne de stationnement"<<endl;
  oss<<"----------------------------------------------"<<endl;
  vector<Borne*>::const_iterator k;
  for(k = m_bornes.begin (); k < m_bornes.end (); k++)
    {
      oss<<(*k) ->reqBorneFormate () <<endl;
    }
  return oss.str(); 
} //je ne suis pas sur !!!


/**
 * \brief RegistreBorne operateur =
 * @param p_RegistreBorne
 * @return un string contenat les informations d'un registre des bornes
 */
RegistreBorne& RegistreBorne::operator=(const RegistreBorne& p_RegistreBorne)
{
    m_nomRegistreBorne = p_RegistreBorne.m_nomRegistreBorne;
    copieVecteur (p_RegistreBorne);
    INVARIANTS();
    return *this;
}

/**
 * \brief méthode pour ajouter un borne au vecteur
 * @param p_nouvelleBorne
 */
void RegistreBorne::ajouteBorne(const Borne& p_nouvelleBorne)
{
  m_bornes.push_back (p_nouvelleBorne.clone());
  INVARIANTS();
}

/**
 * \brief méthode pour faire une copie du vecteur
 * @param p_RegistreBorne
 */
void RegistreBorne::copieVecteur (const 
bornesQuebec::RegistreBorne &p_RegistreBorne)
{
  PRECONDITION (m_bornes.empty());
  for(int i = 0; i< p_RegistreBorne.m_bornes.size(); i++)
    {
    ajouteBorne (*p_RegistreBorne.m_bornes[i]);
    }
  INVARIANTS();
}

/**
 * \brief méthode pour verifier les invariants 
 */
void RegistreBorne::verifieInvariant () const 
{
  INVARIANT (m_bornes.size () >= 0);
}

