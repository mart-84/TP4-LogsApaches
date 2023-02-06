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
    const char *argv[] = {"./analog"};
    VerificateurCommande commande(1, argv);
    cout << boolalpha << bool(commande) << endl;
}

// Description : L'option -t est mal orthographiée : pas de valeur, une valeur alphabétique,
//               des valeurs en dehors de l'intervalle [0, 23]
// Resultat attendu : Des messages sur la sortie d'erreur et commande vaut toujours false
void testHeure()
{
    {
        const char *argv[] = {"./analog", "-t", "a.log"};
        VerificateurCommande commande(3, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-t", "az", "a.log"};
        VerificateurCommande commande(4, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-t", "26", "a.log"};
        VerificateurCommande commande(4, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-t", "-2", "a.log"};
        VerificateurCommande commande(4, argv);
        cout << boolalpha << bool(commande) << endl;
    }
}

// Description : La commande a un argument -e
// Resultat attendu : Rien de spécial, commande vaut true
void testExclusionTypes()
{
    const char *argv[] = {"./analog", "-e", "a.log"};
    VerificateurCommande commande(3, argv);
    cout << boolalpha << bool(commande) << endl;
}

// Description : La valeur de l'argument -g n'est pas un .dot ou aucune valeur n'est pas fournie
// Resultat attendu : Un message sur la sortie + commande vaut false
void testGenerationGraphe()
{
    {
        const char *argv[] = {"./analog", "-g", "a.log"};
        VerificateurCommande commande(3, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-g", "a.txt", "a.log"};
        VerificateurCommande commande(4, argv);
        cout << boolalpha << bool(commande) << endl;
    }
}

// Description : Le fichier à analyser n'est pas un .log
// Resultat attendu : commande vaut false en bool + un message sur la sortie d'erreur
void testFichierNonLog()
{
    const char *argv[] = {"./analog", "a.txt"};
    VerificateurCommande commande(2, argv);
    cout << boolalpha << bool(commande) << endl;
}

// Description : Des combinaisons valides d'arguments sont passées à la commande
// Resultat attendu : commande vaut toujours true et rien n'est affiché dans la sortie d'erreur
void testArgumentsCorrects()
{
    {
        const char *argv[] = {"./analog", "a.log"};
        VerificateurCommande commande(2, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-e", "a.log"};
        VerificateurCommande commande(3, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-t", "12", "a.log"};
        VerificateurCommande commande(4, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-g", "graph.dot", "a.log"};
        VerificateurCommande commande(4, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-e", "-t", "9", "-g", "graph.dot", "a.log"};
        VerificateurCommande commande(7, argv);
        cout << boolalpha << bool(commande) << endl;
    }
}

// Description : La commande a un argument non prévu
// Resultat attendu : Un message d'erreur + commande vaut false
void testArgumentIncorrect()
{
    {
        const char *argv[] = {"./analog", "-a", "a.log"};
        VerificateurCommande commande(3, argv);
        cout << boolalpha << bool(commande) << endl;
    }
    {
        const char *argv[] = {"./analog", "-aaaaaaaaa", "a.log"};
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
    auto tests = {testAucunArgument, testHeure, testExclusionTypes, testGenerationGraphe,
                  testFichierNonLog, testArgumentsCorrects, testArgumentIncorrect};
    for (auto &test : tests)
    {
        test();
        betweenTest();
    }
}