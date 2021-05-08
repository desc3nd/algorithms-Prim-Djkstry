
#ifndef ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_PRIMEL_H
#define ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_PRIMEL_H
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include "StopWatch.h"
///para odpowiadająca za reprezentacje krawędzi i wierzchołków
typedef std::pair<int,int> pair;

///klasa odpowiadająca za reprezentacje algorytmu Prima za pomocą listy
class PrimeL {
public:
    explicit PrimeL(const std::string &fileName);
/// funckja wyświetlająca liste sąsiedztwa
    void displayNeighbourList() const;
    ///funkcja wyświetlająca najkrótszą scieżkę algorytmem prima
    void PrimeDoList();
    void printList() const;  ///funcka wyświetlająca liste wierzchołków
    void printTab() const;
    void PrimeDoArray();
    void readNumberOfVerticles(const std::string &fileName);
    ~PrimeL();
    long long int returnElapsedTime();
    void readDataFromFile(const std::string &fileName);

private:
    int numberOfVerticles;  //ilość wierzchołków
    int numerOfEdges;  //liczba krawędzi
    int INF; // nieskonczonosc
    std::list <pair> *verticlesList;    //lista przetrzymująca wierzchołki i ich wagi
    std::priority_queue<pair,std::vector<pair>,std::greater<> > queue; // lista priorytetowa posortowana względem wag od najniższej do najwyższej
    std::vector<pair> *verticles;
    int **verticlesTab;
    StopWatch stopWatch;
    ///metoda odczytująca z pliku wierzchołki i krawędzie

    void exportFromArrayToQueue();


};

#endif //ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_PRIMEL_H
