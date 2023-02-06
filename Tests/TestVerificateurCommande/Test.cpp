using namespace std;
#include <iostream>
#include "../../VerificateurCommande.h"

// --------------------------------------------------------------------------------
// Test de la vérification des arguments de la commande
// --------------------------------------------------------------------------------


// Description : Aucun argument n'est passé à la commande
// Resultat attendu : commande vaut false en bool et affichage d'un message sur la sortie d'erreur
void testAucunArgument()
{
    const char* argv[] = {"./analog"};
    VerificateurCommande commande(1, argv);
    cout << boolalpha << bool(commande) << endl;
}

// Description : 
// Resultat attendu : 
void testHeure()
{
}

// Description : 
// Resultat attendu : 
void testExclusionTypes()
{
}

// Description : 
// Resultat attendu : 
void testGenerationGraphe()
{
}

// Description : 
// Resultat attendu : 
void testFichierNonLog()
{
}

// Description : Des combinaisons valides d'arguments sont passées à la commande
// Resultat attendu : commande vaut toujours true et rien n'est affiché dans la sortie d'erreur
void testArgumentsCorrects()
{
    {
        const char* argv[] = {"./analog", "a.log"};
        VerificateurCommande commande(2, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char* argv[] = {"./analog", "-e", "a.log"};
        VerificateurCommande commande(3, argv);
        cout << boolalpha << bool(commande) << endl;
    }
}

void betweenTest()
{
    cerr << endl
         << "------------------------------" << endl
         << endl;
    cout << endl
         << "------------------------------" << endl
         << endl;
}

int main()
{
    auto tests = {testAucunArgument, testHeure, testExclusionTypes, 
                  testGenerationGraphe, testFichierNonLog, testArgumentsCorrects};
    for (auto &test : tests)
    {
        test();
        betweenTest();
    }
}