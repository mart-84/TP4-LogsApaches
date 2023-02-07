using namespace std;
#include <iostream>
#include <fstream>
#include "../../Statistiques.h"
#include "../../AnalyseurLogs.h"
#include "../../Graphe.h"

// --------------------------------------------------------------------------------
// Test des statistiques
// --------------------------------------------------------------------------------


// Description : les données du top sont à égalité
// Resultat attendu : affiche les données à égalité l'une derrière l'autre
// ou seulement l'une des deux si dépasse du classement
void testEgaliteTop()
{
     ifstream fichier("egalite.log");
     AnalyseurLogs anal(fichier);
     anal.LireFichier();
     list<LigneLog> donnees = anal.GetLogs();
     Statistiques stat(donnees);
     stat.CalculerStatistiques();
     multimap<int, string> top10 = stat.GetTop10();
     for (multimap<int, string>::reverse_iterator it = top10.rbegin();
          it != top10.rend();
          ++it)
     {
          cout << it->second << " - " << it->first << " hits" << endl;
     }

}

// Description : on crée le graphe à partir de plusieurs données
// Resultat attendu : affichage du graphe
void testGetGraphNonVide()
{
     ifstream fichier("test.log");
     AnalyseurLogs anal(fichier);
     anal.LireFichier();
     list<LigneLog> donnees = anal.GetLogs();
     Statistiques stat(donnees);
     stat.CalculerStatistiques();
     Graph graph = stat.GetGraph();
     for (Graph::const_iterator it = graph.cbegin(); it != graph.cend(); ++it)
     {
          cout << *it << endl;
     }
}

// Description : Aucune données dans l'attribut données
// Resultat attendu : aucun résultat à l'affichage 
void testTop10Vides()
{
     ifstream fichier("vide.log");
     AnalyseurLogs anal(fichier);
     anal.LireFichier();
     list<LigneLog> donnees = anal.GetLogs();
     Statistiques stat(donnees);
     stat.CalculerStatistiques();
     multimap<int, string> top10 = stat.GetTop10();
     for (multimap<int, string>::reverse_iterator it = top10.rbegin();
          it != top10.rend();
          ++it)
     {
          cout << it->second << " - " << it->first << " hits" << endl;
     }
}

// Description : plus de dix cibles en données
// Resultat attendu : affiche le top 10 des cibles
void testTop10()
{
     ifstream fichier("test.log");
     AnalyseurLogs anal(fichier);
     anal.LireFichier();
     list<LigneLog> donnees = anal.GetLogs();
     Statistiques stat(donnees);
     stat.CalculerStatistiques();
     multimap<int, string> top10 = stat.GetTop10();
     for (multimap<int, string>::reverse_iterator it = top10.rbegin();
          it != top10.rend();
          ++it)
     {
          cout << it->second << " - " << it->first << " hits" << endl;
     }
}

// Description : on crée le graphe lorsqu'il n'y a aucune données  
// Resultat attendu : affichage d'un graphe vide
void testGetGraphVide()
{
     ifstream fichier("vide.log");
     AnalyseurLogs anal(fichier);
     anal.LireFichier();
     list<LigneLog> donnees = anal.GetLogs();
     Statistiques stat(donnees);
     stat.CalculerStatistiques();
     Graph graphVide = stat.GetGraph();
     for (Graph::const_iterator it = graphVide.cbegin(); it != graphVide.cend(); ++it)
     {
          cout << *it << endl;
     }
     
}


int main()
{
    testEgaliteTop();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testGetGraphNonVide();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testTop10Vides();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testTop10();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testGetGraphVide();
    cout << endl
         << "------------------------------" << endl
         << endl;
         
}