/**
 * File:   BorneFontaineTesteur.cpp
 * \brief implentation des tests unitaires de la classe BorneFontaine
 *        dérivée du Borne 
 * Author: Gaya Kaddour
 */

#include <gtest/gtest.h>
#include "BorneFontaine.h"
#include "ContratException.h"
#include <string>

using namespace bornesQuebec;

/**
 *\brief Test du constructeur BorneFontaine
 *       cas valide : 
 *             Constructeur valide : tous les parametres sont valide 
 *       cas invalide :
 *             ConstructeurArrondissementVide : l'arrondissement est vide 
 *                        si la ville est Québec 
 */


TEST (BorneFontaine, ConstructeurValide)
{
std::string identifiantVoiePublique = "115066";
std::string coteRue = "Rue Arthur-Dion";
BorneFontaine uneBorneFontaine (103270, identifiantVoiePublique, coteRue,
        46.848633221772715, -71.36942554972563, "Québec", 
        "La Haute-Saint-Charles");

ASSERT_EQ ("Québec", uneBorneFontaine.reqVille ());
ASSERT_EQ ("La Haute-Saint-Charles", uneBorneFontaine.reqArrondissement ());

ASSERT_TRUE (uneBorneFontaine.reqVille () == "Québec" || 
!(uneBorneFontaine.reqArrondissement().empty ()));
}


/**
 *\class BorneFontaineValide
 * \brief Fixture BorneFontaineValide pour la création d'un objet 
 *        BorneFontaine valide pour les tests
 */
class BorneFontaineValide : public::testing::Test
{
public:
  
  std::string identifiantVoiePublique = "115066";
  std::string coteRue = "Rue Arthur-Dion";
  BorneFontaineValide() : t_borneFontaine(103270, identifiantVoiePublique, coteRue,
        46.848633221772715, -71.36942554972563, "Québec", 
        "La Haute-Saint-Charles"){};
  BorneFontaine  t_borneFontaine;
};

/**
 *\brief Test de la méthode const string& BorneFontaine::reqVille() const 
 * cas valide : reqVille retourne une ville 
 * cas invalide : aucun
 */

TEST_F (BorneFontaineValide, reqVille)
{
  ASSERT_EQ ("Québec", t_borneFontaine.reqVille ());
}

/**
 *\brief Test de la méthode const string& BorneFontaine::reqArrondissement() const 
 * cas valide : reqArrondissement retourne une arrondissement 
 * cas invalide : arrondissement vide si la ville est québec
 */
TEST_F (BorneFontaineValide, reqArrondissement)
{
  ASSERT_EQ ("La Haute-Saint-Charles", t_borneFontaine.reqArrondissement ());
  if (t_borneFontaine.reqVille () == "Québec")
    {
      ASSERT_TRUE (!(t_borneFontaine.reqArrondissement ().empty()));
    }
}

/**
 *\brief Test de la méthode BorneFontaine::reqBorneFormate() const
 * cas valide : vérifier le retour d'un format d'une borne fontaine
 */

TEST_F (BorneFontaineValide, reqBorneFormate)
{
  ASSERT_EQ (
  "Borne-fontaine "
  "----------------------------------------------"
  "Identifiant de la borne : 103270"
  "Voie publique : 115066"
  "Nom topographique : Rue Arthur-Dion"
  "Latitude : 46.848633221772715"
  "Longitude : -71.36942554972563"
  "Ville : Québec"
  "Arrondissement : La Haute-Saint-Charles", 
             t_borneFontaine.reqBorneFormate ());
}


/**
 *\brief Test de la méthode Borne* BorneFontaine::clone() const
 * cas valide : vérifier que l'objet *unClone est identique a t_borneFontaine
 *      
 */
TEST_F (BorneFontaineValide, cloneValide)
{
  Borne* unClone = t_borneFontaine.clone ();
  
  ASSERT_EQ (t_borneFontaine.reqIdentifiant (), unClone ->reqIdentifiant ());
  ASSERT_EQ (t_borneFontaine.reqIdentifiantVoiePublique (), 
      unClone ->reqIdentifiantVoiePublique ());
  ASSERT_EQ (t_borneFontaine.reqNomTopographique (), 
      unClone ->reqNomTopographique ());
  ASSERT_EQ (t_borneFontaine.reqLatitude (), unClone ->reqLatitude ());
  ASSERT_EQ (t_borneFontaine.reqLongitude (), unClone ->reqLongitude ());
  ASSERT_EQ (t_borneFontaine.reqBorneFormate (), unClone ->reqBorneFormate ());
  
  delete unClone;
}