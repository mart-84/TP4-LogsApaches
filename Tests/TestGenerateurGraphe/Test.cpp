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

    DocumentInfos &infos(graph["/page1"] );
    infos.first = 7;
    infos.second["/page2"] = 4;
    infos.second["/page3"] = 3;

    DocumentInfos &infos(graph["/page2"] );
    infos.first = 1;
    infos.second["/page1"] = 1;

    DocumentInfos &infos(graph["/page3"] );
    infos.first = 2;
    infos.second["/page2"] = 2;

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

    DocumentInfos &infos(graph["/page1"] );
    infos.first = 4;
    infos.second["/page2"] = 4;

    DocumentInfos &infos(graph["/page2"] );
    infos.first = 1;
    infos.second["/page1"] = 1;

    DocumentInfos &infos(graph["/page3"] );
    infos.first = 2;
    infos.second["/page4"] = 2;

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