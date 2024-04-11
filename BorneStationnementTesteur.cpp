/**
 * File:   BorneFontaineTesteur.cpp
 * \brief implentation des tests unitaires de la classe BorneStationnement
 *        dérivée du Borne 
 * Author: Gaya Kaddour
 */

#include <gtest/gtest.h>
#include "BorneStationnement.h"
#include "ContratException.h"
#include <string>

using namespace bornesQuebec;

/**
 *\brief Test du constructeur BorneStationnement
 *       cas valide : 
 *             Constructeur valide : tous les parametres sont valide 
 *       cas invalide :
 *            le numéro de la borne est de longeur 0 ou >4
 */

TEST (BorneStationnement, ConstructeurValide)
{
  std::string identifiantVoiePublique = "115066";
  std::string coteRue = "1re Avenue";
  std::string pointCardinal = "E";
BorneStationnement uneBorneStationnement (100001, identifiantVoiePublique, coteRue, 
    46.82899800269792, -71.23627057605484, 4005, pointCardinal);

ASSERT_EQ (4005, uneBorneStationnement.reqNumBorne ());
ASSERT_EQ ("E", uneBorneStationnement.reqCoteRue ());

ASSERT_TRUE (util::validePointCardinal (uneBorneStationnement.reqCoteRue ()));
}

TEST (BorneStationnement, constructeurNumInvalide)
{
  std::string identifiantVoiePublique = "115066";
  std::string coteRue = "1re Avenue";
  std::string pointCardinal = "E";
  ASSERT_THROW (BorneStationnement uneBorneStationnement(100001, identifiantVoiePublique, coteRue, 
    46.82899800269792, -71.23627057605484, 4005, pointCardinal), PreconditionException)
          <<"Le numéro de la borne ne peut pas avoir plus de 4 chiffres";
  ASSERT_THROW (BorneStationnement uneBorneStationnement(100001, identifiantVoiePublique, coteRue, 
    46.82899800269792, -71.23627057605484, 4005, pointCardinal), PreconditionException)
          <<"Le numéro de la borne doit contenir au moins un chiffre";
}



/**
 *\class BorneStationnementValide
 * \brief Fixture BorneStationnementValide pour la création d'un objet 
 *        BorneStationnement valide pour les tests
 */

class BorneStationnementValide : public::testing::Test
{
public:
  std::string identifiantVoiePublique = "115066";
  std::string coteRue = "1re Avenue";
  std::string pointCardinal = "E";
    BorneStationnementValide () : t_borneStationnement (100001, identifiantVoiePublique, coteRue, 
    46.82899800269792, -71.23627057605484, 4005, pointCardinal) {};
   BorneStationnement  t_borneStationnement;
};

/**
 *\brief Test de la méthode const string BorneStationnement::reqCoteRue()
 * cas valide : reqNumBorne retourne un numéro 
 * cas invalide : aucun
 */

TEST_F (BorneStationnementValide, reqNumBorne)
{
  ASSERT_EQ (4005, t_borneStationnement.reqNumBorne ());
}

/**
 *\brief Test de la méthode const int BorneStationnement::reqNumBorne()
 * cas valide : reqNumBorne retourne un numéro 
 * cas invalide : aucun
 */
TEST_F (BorneStationnementValide, reqCoteRue)
{
  ASSERT_EQ ("E", t_borneStationnement.reqCoteRue ());
}

/**
 *\brief Test de la méthode BorneStationnement::reqBorneFormate() const
 * cas valide : vérifier le retour d'un format d'une borne de stationnement 
 */

TEST_F (BorneStationnementValide, reqBorneFormate)
{
    ASSERT_EQ("Borne de stationnement numéro 100001, côté 1re Avenue", 
              t_borneStationnement.reqBorneFormate());
}

/**
 *\brief Test de la méthode Borne* ::clone() const
 * cas valide : vérifier que l'objet *unClone est identique a t_borneStationnement
 *      
 */
TEST_F (BorneStationnementValide, cloneValide)
{
  Borne* unClone = t_borneStationnement.clone ();
  
  ASSERT_EQ (t_borneStationnement.reqIdentifiant (), unClone ->reqIdentifiant ());
  ASSERT_EQ (t_borneStationnement.reqNomTopographique (), 
      unClone ->reqNomTopographique ());
  ASSERT_EQ (t_borneStationnement.reqLatitude (), unClone ->reqLatitude ());
  ASSERT_EQ (t_borneStationnement.reqLongitude (), unClone ->reqLongitude ());
  
  delete unClone;
}
