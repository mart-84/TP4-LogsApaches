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

//------------------------------------------------------------------------
// Rôle de la classe <Statistiques>
// Fait les différents calculs possibles
//
//------------------------------------------------------------------------

class Statistiques
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void CalculerStatistiques();
    // Mode d'emploi :
    //
    // Contrat :
    //

    multimap<int, string> GetTop10() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Graph &GetGraph() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

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
    const list<LigneLog> &donnees;
    Graph graphStat;
};

//-------------------------------- Autres définitions dépendantes de <Statistiques>

#endif // STATISTIQUES_H
