using namespace std;
#include <iostream>
#include "../../Controleur.h"
#include "../../LigneLog.h"

// --------------------------------------------------------------------------------
// Test du composant de contrôle général de l'application
// --------------------------------------------------------------------------------

// Description : Différentes possibilités de type de fichier
// Resultat attendu : false pour les 4 premiers, true pour les autres
void testTypeInvalideFoncteur()
{
    LigneLog log;
    log.cible = "test";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.txt";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.html";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.php";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.js";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.css";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.png";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.jpg";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.jpeg";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.gif";
    cout << boolalpha << typeInvalide(log) << endl;

    log.cible = "test.bmp";
    cout << boolalpha << typeInvalide(log) << endl;
}

// Description : Suppression des parties après le ? et/ou le ; dans les urls
// Resultat attendu : Les parties non voulues sont supprimées
void testNettoyageUrl()
{
    string test("test");
    cout << nettoyerUrl(test) << endl;

    test = "test.html";
    cout << nettoyerUrl(test) << endl;

    test = "test.html?a_supprimer";
    cout << nettoyerUrl(test) << endl;

    test = "test.html?";
    cout << nettoyerUrl(test) << endl;

    test = "test.html;a_supprimer";
    cout << nettoyerUrl(test) << endl;

    test = "test.html;";
    cout << nettoyerUrl(test) << endl;

    test = "test.html;a_supprimer1?a_supprimer2";
    cout << nettoyerUrl(test) << endl;
}

void betweenTest()
{
    cout << endl
         << "------------------------------" << endl
         << endl;
}

int main()
{
    auto tests = {testTypeInvalideFoncteur, testNettoyageUrl};
    for (auto &test : tests)
    {
        test();
        betweenTest();
    }
}