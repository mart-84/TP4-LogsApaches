/*************************************************************************
                           Controleur  -  description
                             -------------------
    début                : 27/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Controleur> (fichier Controleur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Controleur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Controleur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Controleur> sur " << this << endl;
#endif
} //----- Fin de Controleur

Controleur::~Controleur()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Controleur> sur " << this << endl;
#endif
} //----- Fin de ~Controleur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
