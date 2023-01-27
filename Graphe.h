using namespace std;
#include <unordered_map>
#include <string>

// Graphe par liste d'adjacence
typedef unordered_map<string, int> Precedents;      // Documents desquels on arrive (sources) + pondérations
typedef pair<int, Precedents> DocumentInfos;        // Total des hits + liste des documents
typedef unordered_map<string, DocumentInfos> Graph; // Stat d'un document : chaque doc (cible) + ses infos