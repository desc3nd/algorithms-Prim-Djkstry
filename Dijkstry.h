
#ifndef ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DIJKSTRY_H
#define ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DIJKSTRY_H
#include<list>
#include <string>
#include "PrimeL.h"
#include "StopWatch.h"
class Dijkstry {
private:
    int **verticlesTab;
    int numberOfVerticles;
    int numberOfEdges;
    int INF;
    std::list<int> *queue;
    std::list<pair> *verticleList;
    StopWatch stopWatch;

    void readNumbers(const std::string &fileName); ///metoda odczytująca tylko liczbe wierzcholkow i krawędzi
public:
    explicit Dijkstry(std::string const &fileName);

    void printTab() const;

    void dijkstraTab(bool outcome);

    void dijkstraList(bool outcome);

    void displayNeighbourList() const;

    long long int returnElapsedTime();

    ~Dijkstry();

    void readDataFromFile(const std::string &fileName); ///metoda odczytująca z pliku wierzchołki i krawędzie
};


#endif //ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DIJKSTRY_H
