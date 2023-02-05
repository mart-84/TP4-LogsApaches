using namespace std;
#include <fstream>
#include <iostream>
#include "../../LigneLog.h"
#include "../../AnalyseurLogs.h"

// --------------------------------------------------------------------------------
// Test de l'analyseur des logs, qui lit le fichier et crée la liste de LigneLog
// --------------------------------------------------------------------------------


// Description : Lecture du fichier test.log (2 lignes)
// Resultat attendu : Une liste avec les 2 lignes et les informations complètes
void testFichierNormal()
{
    ifstream fichier("data/test.log");
    AnalyseurLogs anal(fichier);
    anal.LireFichier();
    list<LigneLog> &logs(anal.GetLogs());
    cout << logs.size() << " lignes" << endl;
    for (auto const &log : logs)
    {
        cout << log << endl;
    }
}

// Description : Lecture d'un fichier vide
// Resultat attendu : Une liste vide retournée
void testFichierVide()
{
    ifstream fichier("data/vide.log");
    AnalyseurLogs anal(fichier);
    anal.LireFichier();
    list<LigneLog> &logs(anal.GetLogs());
    cout << logs.size() << " lignes" << endl;
}

// Description : Lecture d'une ligne avec le nombre d'octets envoyés : -
// Resultat attendu : Une liste avec la ligne où le - est remplacé par un 0
void testInformationManquante()
{
    ifstream fichier("data/incomplet.log");
    AnalyseurLogs anal(fichier);
    anal.LireFichier();
    list<LigneLog> &logs(anal.GetLogs());
    cout << logs.size() << " lignes" << endl;
    for (auto const &log : logs)
    {
        cout << log << endl;
    }
}

int main()
{
    testFichierNormal();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testFichierVide();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testInformationManquante();
}