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

list<LigneLog> AnalyseurLogs::GetLogs()
// Algorithme :
//
{
    return lignes;
} //----- Fin de GetLogs

void AnalyseurLogs::LireFichier()
// Algorithme :
//
{
    while(!fichierLog.eof())
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
    LigneLog newLigne;

    newLigne.ip = lireChamp();
    newLigne.logname = lireChamp();
    newLigne.authenticatedUser = lireChamp();
    fichierLog.ignore();
    
    newLigne.date.jour = stoi(lireChamp('/'));
    newLigne.date.mois = lireChamp('/');
    newLigne.date.annee = stoi(lireChamp(':'));
    newLigne.date.heure = stoi(lireChamp(':'));
    newLigne.date.minute = stoi(lireChamp(':'));
    newLigne.date.seconde = stoi(lireChamp());
    fichierLog.ignore();
    newLigne.date.fuseau = stoi(lireChamp(']'));

    fichierLog.ignore(2);

    newLigne.methode = lireChamp();
    newLigne.cible = lireChamp();
    newLigne.versionProtocol = lireChamp('"');
    fichierLog.ignore();

    newLigne.status = stoi(lireChamp());
    string tailleRep = lireChamp();
    if(tailleRep == "-") {newLigne.tailleReponse = 0;}
    else {newLigne.tailleReponse = stoi(tailleRep);}
    fichierLog.ignore();

    newLigne.source = lireChamp('"');
    fichierLog.ignore(2);
    newLigne.userAgent = lireChamp('"');
    fichierLog.ignore(2);

    lignes.push_back(newLigne);

} //----- Fin de lireLigne

string AnalyseurLogs::lireChamp(char separateur)
// Algorithme :
//
{
    char buffer[500];
    fichierLog.getline(buffer, 499, separateur);
    return string(buffer);
} //----- Fin de lireChamp
