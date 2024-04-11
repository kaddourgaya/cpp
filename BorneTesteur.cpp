/**
 * File:   BorneTesteur.cpp
 * \brief implentation des tests unitaires de la classe borne
 *        Borne est une classe abstraite donc on doit créer une classe 
 *        concrete dérivée afin de pouvoir effectuer les tests 
 * Author: Gaya Kaddour
 */

#include <gtest/gtest.h>
#include "Borne.h"
#include <ContratException.h>
#include "validationFormat.h"
#include <string>

using namespace std;
using namespace bornesQuebec;
using namespace util;

/**
 *\class BorneTest 
 * \brief classe de test permettant de tester la classe abstraite Borne
 */
class BorneTest : public Borne 
{
public:
  BorneTest (int p_identifiant, const std::string& p_identifiantVoiePublique, const std::string& p_nomTopographique, double p_longitude, double p_latitude):
  Borne (p_identifiant, p_identifiantVoiePublique, p_nomTopographique, p_longitude, p_latitude){};
  
    virtual Borne* clone() const {
        return nullptr;
   
  };
};


TEST (Borne, ConstructeurIdentifiantVide)
{
  const std::string identifiantVoiePublique = "100328";
  const std::string nomTopographique = "Boulevard René-Levesque Est";
  BorneTest borneTest (300070, identifiantVoiePublique, nomTopographique, 46.814323, -71.226669);
  
  ASSERT_EQ (300070, borneTest.reqIdentifiant ());
  ASSERT_EQ ("100328", borneTest.reqIdentifiantVoiePublique ());
  ASSERT_EQ ("Boulevard René-Levesque Est", borneTest.reqNomTopographique ());
  ASSERT_EQ (46.814323, borneTest.reqLongitude ());
  ASSERT_EQ (-71.226669, borneTest.reqLatitude ());
  
  ASSERT_TRUE (validerNomTP (borneTest.reqNomTopographique ()));
  ASSERT_TRUE (borneTest.reqIdentifiant () > 0);
  
}

TEST (Borne, ConstructeurIdentifiantInvalide)
{
  ASSERT_THROW (BorneTest borneTest(0,"100328", "Boulevard René-Levesque Est", 46.814323, -71.226669),
                PreconditionException)<<"L'identifiant doit etre supérieur a 0";
}

TEST (BorneTest, ConstructeurNomTopographiqueVide)
{
  ASSERT_THROW (BorneTest borneTest(300070, "100328", " ", 46.814323, -71.226669),
                PreconditionException)<<"Le nom topographyque ne doit pas etre vide.";
}

/**
 *\classe BorneValide
 * \brief fixture BorneValide pour la creation d'un objet Borne pour les tests
 */
class BorneValide : public::testing::Test
{
public:
  BorneValide () : t_borne (300070, "100328", "Boulevard René-Levesque Est", 46.814323, -71.226669) {};
  BorneTest t_borne;
};  

/**
 *\ Test de la méthode reqIdentifiant() 
 * \brief cas valide : l'identifiant doit etre supérieur a 0
 *        cas invalide : l'identifiant inférieur ou égal a 0
 */
TEST_F (BorneValide, reqIdentifiantValide)
{
  ASSERT_EQ (300070, t_borne.reqIdentifiant ());
  ASSERT_TRUE (t_borne.reqIdentifiant () > 0);
}

/**
 *\ Test de la méthode reqNomTopographique() 
 * \brief cas valide : Le nom TG doit etre non vide
 *        cas invalide : le nom TG est vide 
 */
TEST_F (BorneValide, reqNomTopographiqueValide)
{
  ASSERT_EQ ("Boulevard René-Levesque Est", t_borne.reqNomTopographique ());
  ASSERT_TRUE (!(t_borne.reqNomTopographique ().empty())); //????
}

/**
 *\ Test de la méthode reqNomTopographique() 
 * \brief cas valide : Le nom TG doit etre non vide
 *        cas invalide : le nom TG est vide 
 */
TEST_F (BorneValide, asgNomTopographiqueValide)
{
  t_borne.asgNomTopographique ("1re Avenue");
  ASSERT_EQ ("1re Avenue", t_borne.asgNomTopographique ());
  ASSERT_TRUE (!((t_borne.asgNomTopographique ().empty())));
}

/**
 *\ test pour l'opérateur =
 */
TEST_F(BorneValide, operatorEgal)
{
  BorneTest autreBorne (300070, "100328", "Boulevard René-Levesque Est", 46.814323, -71.226669);
  ASSERT_TRUE (t_borne == autreBorne);
}

TEST_F (BorneValide, operatorPasIdenVPEgaux)
{
  BorneTest autreBorne (300071, "100330", "Boulevard René-Levesque Est", 46.814323, -71.226669);
  ASSERT_FALSE (t_borne == autreBorne);
}

TEST_F (BorneValide, operatorNomTPG)
{
  BorneTest autreBorne (300070, "100328", "1re Avenue", 46.814323, -71.226669);
  ASSERT_FALSE (t_borne == autreBorne);
}

