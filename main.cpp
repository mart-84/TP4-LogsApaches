#include <iostream>
#include <fstream>
using namespace std;

#include "AnalyseurLogs.h"
#include "GenerateurGraphe.h"
#include "VerificateurCommande.h"
#include "Statistiques.h"
#include "Controleur.h"

void test1() {
    ifstream fichier("anonyme.log");
    AnalyseurLogs anal(fichier);
    anal.LireFichier();

    Statistiques stat(anal.GetLogs());
    stat.CalculerStatistiques();
    auto result = stat.GetTop10();
    for (multimap<int, string>::reverse_iterator it = result.rbegin();
         it != result.rend();
         ++it)
    {
        cout << it->second << "\t " << it->first << " hits" << endl;
    }
}

void test2()
{
    ifstream fichier("anonyme.log");
    AnalyseurLogs anal(fichier);
    anal.LireFichier();

    Statistiques stat(anal.GetLogs());
    stat.CalculerStatistiques();

    ofstream o("graph.dot");
    GenerateurGraphe gg(o, stat.GetGraph());
    gg.ExporterGraphe();
}

int main(int argc, char **argv)
{
    VerificateurCommande commande(argc, argv);
    if (commande)
    {
        Controleur controleur(commande);
        controleur.Demarrer();
    }
}
