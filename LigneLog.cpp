/*************************************************************************
                           LigneLog  -  description
                             -------------------
    début                : 20/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LigneLog> (fichier LigneLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LigneLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LigneLog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
ostream& operator<<(ostream & os, LigneLog log)
{
    os << log.ip << " "
       << log.logname << " "
       << log.authenticatedUser << " ["
       << log.date.jour << "/"
       << log.date.mois << "/"
       << log.date.annee << ":"
       << log.date.heure << ":"
       << log.date.minute << ":"
       << log.date.seconde << " "
       << log.date.fuseau << "] \""
       << log.methode << " "
       << log.cible << " "
       << log.versionProtocol << "\" "
       << log.status << " "
       << log.tailleReponse << " \""
       << log.source << "\" \""
       << log.userAgent << "\"";
       
    return os;
}

//-------------------------------------------- Constructeurs - destructeur
LigneLog::LigneLog()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LigneLog> sur " << this << endl;
#endif
} //----- Fin de LigneLog

LigneLog::~LigneLog()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LigneLog> sur " << this << endl;
#endif
} //----- Fin de ~LigneLog

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
