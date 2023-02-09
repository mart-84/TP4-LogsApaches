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
#include <algorithm>

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
// Algorithme :
//
{
    ifstream fichierLogs(commande.fichierLogs);
    if (!fichierLogs)
    {
        cerr << "Erreur a l'ouverture du fichier de logs" << endl;
        return;
    }

    AnalyseurLogs anal(fichierLogs);
    anal.LireFichier();

    logs = anal.GetLogs();
    nettoyerLogs();
    filtrerLogs();

    Statistiques stat(logs);
    stat.CalculerStatistiques();

    if (commande.genererGraphe)
    {
        genererGraphe(stat);
    }

    afficherTop10(stat);
} //----- Fin de Demarrer

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Controleur::Controleur(VerificateurCommande &cmd)
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
void Controleur::nettoyerLogs()
// Algorithme :
//
{
    for_each(logs.begin(), logs.end(),
             [this](LigneLog &log)
             {
                 log.cible = nettoyerUrl(log.cible);
                 log.source = nettoyerUrl(log.source);
             });
} //----- Fin de nettoyerLogs

void Controleur::filtrerLogs()
// Algorithme :
// regarde si besoin de filtrer le Logs
{
    if (commande.exclusion)
    {
        filtrerLogsType();
    }
    if (commande.filtrerHeure)
    {
        filtrerLogsHeure();
    }
} //----- Fin de filtrerLogs

void Controleur::filtrerLogsType()
// Algorithme :
// filtrage du Logs par type
{
    logs.remove_if(typeInvalide);
} //----- Fin de filtrerLogsType

void Controleur::filtrerLogsHeure()
// Algorithme :
// filtrage du Logs par heure
{
    int horaire(commande.heure);
    logs.remove_if([horaire](const LigneLog &logs)
                   { return logs.date.heure != horaire; });

    cerr << "Warning : only hits between " << horaire << "h and "
         << horaire + 1 << "h have been taken into account" << endl;
} //----- Fin de filtrerLogsHeure

void Controleur::genererGraphe(Statistiques &stat)
// Algorithme :
//
{
    ofstream o(commande.fichierGraphe);
    if (!o)
    {
        cerr << "Erreur a l'ouverture du fichier de graphe" << endl;
        return;
    }
    GenerateurGraphe gg(o, stat.GetGraph());
    gg.ExporterGraphe();
    cout << "Graphe genere dans le fichier " << commande.fichierGraphe << endl;
} //----- Fin de genererGraphe

void Controleur::afficherTop10(Statistiques &stat)
// Algorithme :
//
{
    multimap<int, string> result = stat.GetTop10();
    for (multimap<int, string>::reverse_iterator it = result.rbegin();
         it != result.rend();
         ++it)
    {
        cout << it->second << " - " << it->first << " hits" << endl;
    }
} //----- Fin de afficherTop10

//-------------------------------- Autres définitions dépendantes de <Controleur>
string nettoyerUrl(const string &url)
// Algorithme :
//
{
    string cleanUrl(url);
    size_t pos = cleanUrl.find('?', 0);
    if (pos != string::npos)
    {
        cleanUrl = url.substr(0, pos);
    }
    pos = cleanUrl.find(';', 0);
    if (pos != string::npos)
    {
        cleanUrl = url.substr(0, pos);
    }
    if (cleanUrl.find(baseUrl, 0) == 0)
    {
        cleanUrl = cleanUrl.substr(baseUrl.size());
    }
    if (cleanUrl.back() == '/')
    {
        cleanUrl = cleanUrl.substr(0, cleanUrl.size() - 1);
    }
    return cleanUrl;
} //----- Fin de nettoyerUrl

bool typeInvalide(const LigneLog &logs)
// Algorithme :
//
{
    size_t pos = logs.cible.rfind('.');
    if (pos == string::npos)
    {
        return false;
    }
    string typeFichier = logs.cible.substr(pos);
    return !(typeFichier != ".js" &&
             typeFichier != ".css" &&
             typeFichier != ".png" &&
             typeFichier != ".jpg" &&
             typeFichier != ".jpeg" &&
             typeFichier != ".gif" &&
             typeFichier != ".ico" &&
             typeFichier != ".bmp");
} //----- Fin de typeInvalide