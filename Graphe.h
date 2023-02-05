/*************************************************************************
                           GenerateurGraphe  -  description
                             -------------------
    début                : 27/01/2023
    copyright            : (C) 2023 par Martin Bonnefoy, Ambre Hutier
    e-mail               : martin.bonnefoy@insa-lyon.fr; ambre.hutier@insa-lyon.fr
*************************************************************************/

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <unordered_map>
#include <string>

// Rôle de la classe <Graphe>
// Créer une structure de Graphe
//
//------------------------------------------------------------------------
typedef unordered_map<string, int> Precedents;      // Documents desquels on arrive (sources) + pondérations
typedef pair<int, Precedents> DocumentInfos;        // Total des hits + liste des documents
typedef unordered_map<string, DocumentInfos> Graph; // Stat d'un document : chaque doc (cible) + ses infos