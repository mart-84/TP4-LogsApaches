using namespace std;
#include <iostream>
#include <fstream>
#include "../../Graphe.h"
#include "../../GenerateurGraphe.h"

// --------------------------------------------------------------------------------
// Test d'analyse du graphe
// --------------------------------------------------------------------------------


// Description : graphe avec plusieurs donnees reliées entre elles
// Resultat attendu : génération d'un fichier .dot avec descriptif des éléments
void testExporterGraphe()
{
    Graph  graph;

    graph["/page1"].first = 7;
    graph["/page1"].second["/page2"] = 4;
    graph["/page1"].second["/page3"] = 3;

    graph["/page2"].first = 1;
    graph["/page2"].second["/page1"] = 1;

    graph["/page3"].first = 2;
    graph["/page3"].second["/page2"] = 2;

    ofstream fichier("elements.dot");
    GenerateurGraphe genere(fichier, graph);
    genere.ExporterGraphe();
}

// Description : graphe avec plusieurs donnees qui ne sont pas sources les unes des autres 
// Resultat attendu : génération d'un fichier .dot avec descriptif d'éléments non reliées entre eux 
void testGrapheVide()
{
    Graph  graphVide;
    ofstream fichier("vide.dot");
    GenerateurGraphe genere(fichier, graphVide);
    genere.ExporterGraphe();
}

// Description : graphe avec plusieurs donnees qui ne sont pas sources les unes des autres
// Resultat attendu : génération d'un fichier .dot avec descriptif d'éléments non reliées entre eux
void testDonneesDisjointes()
{
     Graph  graph;

    graph["/page1"].first = 4;
    graph["/page1"].second["/page2"] = 4;

    graph["/page2"].first = 1;
    graph["/page2"].second["/page1"] = 1;

    graph["/page3"].first = 2;
    graph["/page3"].second["/page4"] = 2;

    ofstream fichier("elements.dot");
    GenerateurGraphe genere(fichier, graph);
    genere.ExporterGraphe();
}

int main()
{
    testExporterGraphe();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testGrapheVide();
    cout << endl
         << "------------------------------" << endl
         << endl;
    testDonneesDisjointes();
    cout << endl
         << "------------------------------" << endl
         << endl;
}