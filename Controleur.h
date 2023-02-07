/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 27/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Controleur> (fichier Controleur.h) ----------------
#if !defined(CONTROLEUR_H)
#define CONTROLEUR_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;

#include "VerificateurCommande.h"
#include "LigneLog.h"
#include "Statistiques.h"

//------------------------------------------------------------- Constantes
const string baseUrl = "http://intranet-if.insa-lyon.fr";

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Controleur>
// Fait le lien entre les différentes classes existantes
//
//------------------------------------------------------------------------

class Controleur
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Demarrer();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Controleur(VerificateurCommande &);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Controleur();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    void nettoyerLogs();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void filtrerLogs();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void filtrerLogsHeure();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void filtrerLogsType();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void genererGraphe(Statistiques &);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void afficherTop10(Statistiques &);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //----------------------------------------------------- Attributs protégés
    VerificateurCommande &commande;
    list<LigneLog> logs;
};

//-------------------------------- Autres définitions dépendantes de <Controleur>
string nettoyerUrl(const string &);
// Mode d'emploi :
//
// Contrat :
//

bool typeInvalide(const LigneLog &);
// Mode d'emploi :
//
// Contrat :
//

#endif // CONTROLEUR_H
