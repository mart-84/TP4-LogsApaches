/*************************************************************************
                           AnalyseurLogs  -  description
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AnalyseurLogs> (fichier AnalyseurLogs.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AnalyseurLogs.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type AnalyseurLogs::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

list<LigneLog> & AnalyseurLogs::GetLogs()
// Algorithme :
//
{
    return lignes;
} //----- Fin de GetLogs

void AnalyseurLogs::LireFichier()
// Algorithme :
//
{
    // Le peek permet de vérifier le prochain caractère et de mettre à jour les flags
    // sans l'enlever du flux
    while (fichierLog.peek(), !fichierLog.eof())
    {
        lireLigne();
    }

} //----- Fin de LireFichier

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
AnalyseurLogs::AnalyseurLogs(ifstream &fichier)
    : fichierLog(fichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AnalyseurLogs> sur " << this << endl;
#endif
} //----- Fin de AnalyseurLogs

AnalyseurLogs::~AnalyseurLogs()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AnalyseurLogs> sur " << this << endl;
#endif
} //----- Fin de ~AnalyseurLogs

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void AnalyseurLogs::lireLigne()
// Algorithme :
//
{
    LigneLog ligne;

    getline(fichierLog, ligne.ip, ' ');
    getline(fichierLog, ligne.logname, ' ');
    getline(fichierLog, ligne.authenticatedUser, ' ');

    fichierLog.ignore(); // caractère '['

    ligne.date.jour = stoi(lireChamp('/'));
    getline(fichierLog, ligne.date.mois, '/');
    ligne.date.annee = stoi(lireChamp(':'));
    ligne.date.heure = stoi(lireChamp(':'));
    ligne.date.minute = stoi(lireChamp(':'));
    ligne.date.seconde = stoi(lireChamp());
    ligne.date.fuseau = stoi(lireChamp(']'));

    fichierLog.ignore(2); // caractères ' ' et '"'

    getline(fichierLog, ligne.methode, ' ');
    getline(fichierLog, ligne.cible, ' ');
    getline(fichierLog, ligne.versionProtocol, '"');

    fichierLog.ignore(); // caractère espace

    ligne.status = stoi(lireChamp());
    string tailleRep;
    getline(fichierLog, tailleRep, ' ');
    ligne.tailleReponse = tailleRep == "-" ? 0 : stoi(tailleRep);

    fichierLog.ignore(); // caractère '"'
    getline(fichierLog, ligne.source, '"');
    fichierLog.ignore(2); // caractères ' ' et '"'
    getline(fichierLog, ligne.userAgent, '"');

    string buffer;
    getline(fichierLog, buffer); // permet de "vider" ce qu'il reste de la ligne 'espace vide, retour à la ligne, ...)

    lignes.push_back(ligne);
} //----- Fin de lireLigne

string AnalyseurLogs::lireChamp(char separateur)
// Algorithme :
//
{
    char buffer[500];
    fichierLog.getline(buffer, 499, separateur);
    return string(buffer);
} //----- Fin de lireChamp
