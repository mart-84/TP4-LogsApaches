/*************************************************************************
                           GenerateurGraphe  -  description
                             -------------------
    début                : 27/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GenerateurGraphe> (fichier GenerateurGraphe.h) ----------------
#if !defined(GENERATEURGRAPHE_H)
#define GENERATEURGRAPHE_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>
#include "Graphe.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GenerateurGraphe>
// Cette classe permet de génerer le fichier .dot qui permettra de générer un graphe
//
//------------------------------------------------------------------------

class GenerateurGraphe
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void ExporterGraphe();
    // Mode d'emploi :
    //
    

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    GenerateurGraphe(ofstream &, const Graph &);
    // Mode d'emploi :
    //

    virtual ~GenerateurGraphe();
    // Mode d'emploi :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    ofstream & fichier;
    const Graph & donnees;
};

//-------------------------------- Autres définitions dépendantes de <GenerateurGraphe>

#endif // GENERATEURGRAPHE_H
