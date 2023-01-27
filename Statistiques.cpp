/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : 27/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Statistiques> (fichier Statistiques.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <map>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Statistiques.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Statistiques::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Statistiques::CalculerStatistiques()
// Algorithme :
//
{
    for (list<LigneLog>::const_iterator it = donnees.cbegin(); it != donnees.cend(); ++it)
    {
        DocumentInfos &info(graphStat[nettoyerUrl(it->cible)]);
        ++info.first;
        ++info.second[nettoyerUrl(it->source)];
        // normalement ça marche, donc on touche pas
    }
} //----- Fin de CalculerStatistiques

multimap<int, string> Statistiques::GetTop10() const
// Algorithme :
//
{
    multimap<int, string> consultationDocuments;
    for (Graph::const_iterator it = graphStat.cbegin(); it != graphStat.cend(); ++it)
    {
        consultationDocuments.insert(make_pair(it->second.first, it->first));
    }
    
    int i = 0;
    multimap<int, string>::reverse_iterator it;

    multimap<int, string> resultat;
    for (it = consultationDocuments.rbegin();
         i < 10 && it != consultationDocuments.rend();
         ++it, ++i)
    {
        resultat.insert(*it);
    }
    return resultat;
} //----- Fin de GetTop10

const Graph & Statistiques::GetGraph() const
// Algorithme :
//
{
    return graphStat;
} //----- Fin de GetGraph

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Statistiques::Statistiques(const list<LigneLog> & data)
    : donnees(data)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Statistiques> sur " << this << endl;
#endif
} //----- Fin de Statistiques

Statistiques::~Statistiques()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Statistiques> sur " << this << endl;
#endif
} //----- Fin de ~Statistiques

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
string Statistiques::nettoyerUrl(const string & url)
// Algorithme :
//
{
    string cleanUrl(url);
    size_t pos = cleanUrl.find('?', 0);
    if (pos != string::npos)
    {
        cleanUrl = url.substr(0, pos);
    }
    pos = cleanUrl.find(';', 0);
    if (pos != string::npos)
    {
        cleanUrl = url.substr(0, pos);
    }
    if (cleanUrl.find(baseUrl, 0) == 0)
    {
        cleanUrl = cleanUrl.substr(baseUrl.size());
    }
    return cleanUrl;
} //----- Fin de retirerBaseUrl


