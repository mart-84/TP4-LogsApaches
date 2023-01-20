/*************************************************************************
                           AnalyseurLogs  -  description
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AnalyseurLogs> (fichier AnalyseurLogs.h) ----------------
#if !defined(ANALYSEURLOGS_H)
#define ANALYSEURLOGS_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>
#include <list>
#include "LigneLog.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AnalyseurLogs>
//
//
//------------------------------------------------------------------------

class AnalyseurLogs
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    list<LigneLog> GetLogs();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void LireFichier();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    AnalyseurLogs(ifstream &fichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AnalyseurLogs();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void lireLigne();

    string lireChamp(char separateur = ' ');

    //----------------------------------------------------- Attributs protégés
    list<LigneLog> lignes; 
    ifstream &fichierLog;
};

//-------------------------------- Autres définitions dépendantes de <AnalyseurLogs>

#endif // ANALYSEURLOGS_H
