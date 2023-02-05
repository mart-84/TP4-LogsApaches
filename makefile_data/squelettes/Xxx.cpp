/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : %DATE%
    copyright            : (C) %YEAR% par %AUTHOR%
    e-mail               : %EMAIL%
*************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Xxx.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Xxx &Xxx::operator=(const Xxx &autreXxx)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel a l'operateur d'affectation de <Xxx> sur " << this << " et " << &autreXxx << endl;
#endif
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Xxx::Xxx(const Xxx &autreXxx)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx> sur " << this << " et " << &autreXxx << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)

Xxx::Xxx()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx> sur " << this << endl;
#endif
} //----- Fin de Xxx

Xxx::~Xxx()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx> sur " << this << endl;
#endif
} //----- Fin de ~Xxx

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
