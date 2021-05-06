
#ifndef ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_PRIMEL_H
#define ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_PRIMEL_H
#include <list>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
///para odpowiadająca za reprezentacje krawędzi i wierzchołków
typedef std::pair<int,int> pair;

///klasa odpowiadająca za reprezentacje algorytmu Prima za pomocą listy
class PrimeL {
public:
    explicit PrimeL(const std::string &fileName);
/// funckja wyświetlająca liste sąsiedztwa
    void displayNeighbourList() const;
    ///funkcja wyświetlająca najkrótszą scieżkę algorytmem prima
    void PrimeDo();
    void printList() const;  ///funcka wyświetlająca liste wierzchołków
    void printTab() const;
    ~PrimeL();
private:
    int numberOfVerticles;  //ilość wierzchołków
    int numerOfEdges;  //liczba krawędzi
    int INF; // nieskonczonosc
    std::list <pair> *verticles;    //lista przetrzymująca wierzchołki i ich wagi
    std::priority_queue<pair,std::vector<pair>,std::greater<> > queue; // lista priorytetowa posortowana względem wag od najniższej do najwyższej
    int tabVerticles;
    void readDataFromFile(const std::string &fileName); ///metoda odczytująca z pliku wierzchołki i krawędzie

public:

};

#endif //ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_PRIMEL_H
