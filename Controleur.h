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
//
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

    string nettoyerUrl(const string &);

    void filtrerLogs();

    void filtrerLogsHeure();

    void filtrerLogsType();

    void genererGraphe(Statistiques &);

    void afficherTop10(Statistiques &);

    //----------------------------------------------------- Attributs protégés
    VerificateurCommande & commande;
    list<LigneLog> logs;
};

//-------------------------------- Autres définitions dépendantes de <Controleur>
bool typeInvalide(const LigneLog &);

#endif // CONTROLEUR_H
