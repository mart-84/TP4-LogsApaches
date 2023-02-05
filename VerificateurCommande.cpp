/*************************************************************************
                           VerificateurCommande  -  description
                             -------------------
    début                : 02/02/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <VerificateurCommande> (fichier VerificateurCommande.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdexcept>

//------------------------------------------------------ Include personnel
#include "VerificateurCommande.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type VerificateurCommande::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
VerificateurCommande::operator bool() const
// Algorithme :
//
{
    return estValide;
} //----- Fin de operator bool

//-------------------------------------------- Constructeurs - destructeur
VerificateurCommande::VerificateurCommande(int argc, char** argv)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <VerificateurCommande> sur " << this << endl;
#endif
if (argc < 2)
{
    cerr << "Nom du fichier manquant" << endl;
    return;
}

for (int i = 1; i < argc-1; ++i)
{
    string option(argv[i]);
    if (option == "-t")
    {
        ++i;
        string heureStr(argv[i]);
        int h;
        try
        {
            h = stoi(heureStr);
        }
        catch (const invalid_argument & ia)
        {
            cerr << "La valeur apres le -t n'est pas un entier" << endl;
            return;
        }
        if (h < 0 || h > 23)
        {
            cerr << "L'heure indiquee n'est pas valide" << endl;
            return;
        }
        heure = h;
        filtrerHeure = true;
    }
    else if (option == "-e")
    {
        exclusion = true;
    }
    else if (option == "-g")
    {
        ++i;
        string fichier(argv[i]);
        if (fichier.rfind(".dot") == string::npos)
        {
            cerr << "Le fichier du graphe doit etre un .dot" << endl;
            return;
        }
        genererGraphe = true;
        fichierGraphe = fichier;
    }
    else
    {
        cerr << "Option invalide : " << option << endl;
        return;
    }
}

string fichier(argv[argc - 1]);
if (fichier.rfind(".log") == string::npos)
{
    cerr << "Le fichier a analyser doit etre un .log" << endl;
    return;
}
fichierLogs = fichier;
estValide = true;

} //----- Fin de VerificateurCommande

VerificateurCommande::~VerificateurCommande()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <VerificateurCommande> sur " << this << endl;
#endif
} //----- Fin de ~VerificateurCommande

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
