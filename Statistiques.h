/*************************************************************************
                           Statistiques  -  description
                             -------------------
    début                : 27/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Statistiques> (fichier Statistiques.h) ----------------
#if !defined(STATISTIQUES_H)
#define STATISTIQUES_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <list>
#include <map>
#include "LigneLog.h"
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// Graphe par liste d'adjacence
typedef unordered_map<string, int> Precedents;      // Documents desquels on arrive (sources) + pondérations
typedef pair<int, Precedents> DocumentInfos;        // Total des hits + liste des documents
typedef unordered_map<string, DocumentInfos> Graph; // Stat d'un document : chaque doc (cible) + ses infos

//------------------------------------------------------------------------
// Rôle de la classe <Statistiques>
//
//
//------------------------------------------------------------------------

class Statistiques
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void CalculerStatistiques();

    multimap<int, string> GetTop10() const;

    const Graph & GetGraph() const;

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Statistiques(const list<LigneLog> &);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Statistiques();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    const list<LigneLog> & donnees;
    Graph graphStat;
};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // STATISTIQUES_H
