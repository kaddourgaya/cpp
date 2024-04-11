/* 
 * File:   RegistreBorneTesteur.cpp
 * \brief implentation des tests unitaires de la classe RegistreBorne
 * Author: Gaya Kaddour
 */


#include <gtest/gtest.h>
#include "Borne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "RegistreBorne.h"
#include "ContratException.h"
#include <string>
#include <sstream>

using namespace std;
using namespace util;
using namespace bornesQuebec;

/**
 *\brief Test du nom du registre donné est non-vide 
 */
TEST (RegistreBorne, ConstructeurValide)
{
RegistreBorne Testeur ("Borne de Québec");
ASSERT_EQ ("Borne de Québec", Testeur.reqNomRegistre ());
}

/**
 *\class UnRegistreBorne
 * \brief Fixture UnRegistreBorne pour la création d'un objet 
 *        RegistreBorne valide pour les tests
 */

class UnRegistreBorne : public::testing::Test
{
public:
  UnRegistreBorne():
  t_registreborne ("Borne de Québec"),
  t_borneStationnement (100001, "1re Avenue", 
    46.82899800269792, -71.23627057605484, 4005, "E"),
  t_borneFontaine(103270, "115066", "Rue Arthur-Dion",
        46.848633221772715, -71.36942554972563, "Québec", 
        "La Haute-Saint-Charles"){};

  RegistreBorne t_registreborne;
  BorneStationnement  t_borneStationnement;
  BorneFontaine  t_borneFontaine;
};

/**
 \brief test du constructeur copie de RegistreBorne
 */

TEST_F (UnRegistreBorne, ConstructeurCopieValide)
{
RegistreBorne uneCopie (t_registreborne);
ASSERT_EQ ("Borne de Québec", uneCopie.reqNomRegistre ());
ASSERT_EQ (t_registreborne.reqRegistreBorneFormate (), 
            uneCopie.reqRegistreBorneFormate ());
}

TEST_F (UnRegistreBorne, reqNomRegistre)
{
  ASSERT_EQ ("Borne de Québec", t_registreborne.reqNombreBorne ());
}

/**
 *\brief Test d'ajout de borne multiple
 */

TEST_F (UnRegistreBorne, ajouterBorne)
{
BorneFontaine uneBorneFontaine (103271, "115066", "Rue Arthur-Dion",
        46.848633221772715, -71.36942554972563, "Québec", 
        "La Haute-Saint-Charles");

t_registreborne.ajouteBorne (uneBorneFontaine);
ostringstream oss;
oss<<"Borne-fontaine :"<<endl;
oss<<"----------------------------------------------"<<endl;
oss<<" [1]  Identifiant de la borne : 103270"
"\nVoie publique : 115066"
"\n Nom topographique : Rue Arthur-Dion"
"\n Latitude : 46.848633221772715"
"\n Longitude : -71.36942554972563"
"\n Ville : Québec"
"\n Arrondissement : La Haute-Saint-Charles"<<endl;
oss<<  "[2]  Identifiant de la borne : 103271"
"\nVoie publique : 115066"
"\n Nom topographique : Rue Arthur-Dion"
"\n Latitude : 46.848633221772715"
"\n Longitude : -71.36942554972563"
"\n Ville : Québec"
"\n Arrondissement : La Haute-Saint-Charles"<<endl;
        ASSERT_EQ (oss.str (),t_registreborne.reqRegistreBorneFormate ());
}