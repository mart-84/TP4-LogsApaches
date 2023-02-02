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
#include <iostream>
#include <fstream>
#include <list>
#include <map>

//------------------------------------------------------ Include personnel
#include "Controleur.h"
#include "GenerateurGraphe.h"
#include "AnalyseurLogs.h"
#include "Statistiques.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Controleur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Controleur::Demarrer()
{
    ifstream fichierLogs(commande.fichierLogs);
    if (!fichierLogs)
    {
        cout << "Erreur à l'ouverture du fichier de logs" << endl;
        return;
    }

    AnalyseurLogs anal(fichierLogs);
    anal.LireFichier();

    logs = anal.GetLogs();
    filtrerLogs();

    Statistiques stat(logs);
    stat.CalculerStatistiques();

    if(commande.genererGraphe)
    {
        genererGraphe(stat);
    }

    afficherTop10(stat);
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur(VerificateurCommande& cmd)
    : commande(cmd)
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
void Controleur::filtrerLogs()
{
    if(commande.exclusion)
    {
        filtrerLogsType();
    }
    if(commande.filtrerHeure)
    {
        filtrerLogsHeure();
    }
}

void Controleur::filtrerLogsType()
{
    logs.remove_if(typeInvalide);
}

void Controleur::filtrerLogsHeure()
{
    int horaire(commande.heure);
    cout << "Warning : only hits between "<<horaire<<"h and "<<horaire+1
         <<"h have been taken into account"<<endl;
    logs.remove_if([horaire](const LigneLog & logs){
        return logs.date.heure != horaire;
    });
    
}

void Controleur::genererGraphe(Statistiques & stat)
{
    ofstream o(commande.fichierGraphe);
    if(!o)
    {
        cout<<"Erreur à l'ouverture du fichier de graphe" << endl;
        return;
    }
    GenerateurGraphe gg(o, stat.GetGraph());
    gg.ExporterGraphe();
}

void Controleur::afficherTop10(Statistiques & stat)
{
    multimap<int, string> result = stat.GetTop10();
    for (multimap<int, string>::reverse_iterator it = result.rbegin();
         it != result.rend();
         ++it)
    {
        cout << it->second << "\t " << it->first << " hits" << endl;
    }
}

bool typeInvalide(const LigneLog & logs)
{
    size_t pos = logs.cible.rfind('.');
    if (pos == string::npos)
    {
        return false;
    }
    string typeFichier = logs.cible.substr(pos);
    return !(typeFichier != ".js" && typeFichier != ".css" 
        && typeFichier != ".png" && typeFichier != ".jpg" 
        && typeFichier != ".jpeg" && typeFichier != ".gif" 
        && typeFichier != ".ico" && typeFichier != ".bmp");
}