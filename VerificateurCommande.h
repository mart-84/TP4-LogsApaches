/*************************************************************************
                           VerificateurCommande  -  description
                             -------------------
    début                : 02/02/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <VerificateurCommande> (fichier VerificateurCommande.h) ----------------
#if !defined(VERIFICATEURCOMMANDE_H)
#define VERIFICATEURCOMMANDE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <VerificateurCommande>
//
//
//------------------------------------------------------------------------

class VerificateurCommande
{
    //----------------------------------------------------------------- PUBLIC

public:
    friend class Controleur;
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    operator bool() const;



    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    VerificateurCommande(int argc, char** argv);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~VerificateurCommande();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    bool estValide = false;
    string fichierLogs;
    string fichierGraphe;
    bool genererGraphe = false;
    bool exclusion = false;
    int heure;
    bool filtrerHeure = false;
};

//-------------------------------- Autres définitions dépendantes de <VerificateurCommande>

#endif // VERIFICATEURCOMMANDE_H
