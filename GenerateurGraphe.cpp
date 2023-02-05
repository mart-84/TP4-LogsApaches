/*************************************************************************
                           GenerateurGraphe  -  description
                             -------------------
    début                : 27/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GenerateurGraphe> (fichier GenerateurGraphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "GenerateurGraphe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publique

void GenerateurGraphe::ExporterGraphe()
// Algorithme :
//
{
    fichier << "digraph {" << endl;
    for (Graph::const_iterator it = donnees.cbegin(); it != donnees.cend(); ++it)
    {
        fichier << "\t\"" << it->first << "\";" << endl;
    }
    for (Graph::const_iterator it = donnees.cbegin(); it != donnees.cend(); ++it)
    {
        for (Precedents::const_iterator it2 = it->second.second.cbegin(); 
             it2 != it->second.second.cend(); ++it2)
        {
            fichier << "\t\"" << it2->first << "\" -> \"" << it->first 
                    << "\" [label=\"" << it2->second << "\"];" << endl;
        }
    }
    fichier << "}" << endl;
} //----- Fin de ExporterGraphe


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
GenerateurGraphe::GenerateurGraphe(ofstream & file, const Graph & graph)
    :fichier(file), donnees(graph)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GenerateurGraphe> sur " << this << endl;
#endif
} //----- Fin de GenerateurGraphe

GenerateurGraphe::~GenerateurGraphe()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GenerateurGraphe> sur " << this << endl;
#endif
} //----- Fin de ~GenerateurGraphe

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
