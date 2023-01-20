/*************************************************************************
                           LigneLog  -  description
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LigneLog> (fichier LigneLog.h) ----------------
#if !defined(LIGNELOG_H)
#define LIGNELOG_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Date {
    int annee;
    string mois;
    int jour;
    int heure;
    int minute;
    int seconde;
    int fuseau;
};

//------------------------------------------------------------------------
// Rôle de la classe <LigneLog>
//
//
//------------------------------------------------------------------------

class LigneLog
{
    //----------------------------------------------------------------- PUBLIC

public:
    string ip;
    string logname;
    string authenticatedUser;
    Date date;
    string methode;
    string cible;
    string versionProtocol;
    int status;
    int tailleReponse;
    string source;
    string userAgent;
    
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs

    friend ostream& operator<<(ostream &, LigneLog);

    //-------------------------------------------- Constructeurs - destructeur
    LigneLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LigneLog();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <LigneLog>

#endif // LIGNELOG_H
