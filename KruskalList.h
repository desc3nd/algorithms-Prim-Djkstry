
#ifndef ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_KRUSKALLIST_H
#define ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_KRUSKALLIST_H
#include <list>
#include <string>
#include <fstream>
///struktura odpowiadająca za reprezentacje krawędzi
struct Edge
{
    //wierzchołek 1
    int vertex1;
    //wierzchołek 2
    int vertex2;
    //waga krawędzi
    int weight;
};
///klasa odpowiadająca za reprezentacje algorytmu kruskala
class KruskalList {
private:
    //lista przetrzymująca krawędzie
    std::list <Edge> listOfEdges;
    //ilość krawędzi
    int numberOfEdges;
    //ilość wierzchołków
    int numberOfVertex;
public:
    ///metoda odpowaidająca za odczyt danych z pliku do listy krawędzi
    void readDataFromFile(const std::string &filename);
    ///metoda drukująca liste krawędzi i wierzchołków z ich wagami
    void  printList() const;
};


#endif //ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_KRUSKALLIST_H
