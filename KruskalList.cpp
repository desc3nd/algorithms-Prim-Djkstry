
#include <iostream>
#include "KruskalList.h"
///metoda odpowaidająca za odczyt danych z pliku do listy krawędzi
void KruskalList::readDataFromFile(const std::string &fileName) {
    std::ifstream read(fileName);
    //sprawdzam czy plik się otworzył
    if(read.is_open())
    {
        //wczytuje dwie pierwsze wartości
        read>>numberOfEdges>>numberOfVertex;
        //zmienna przechowująca krawędź
        Edge *edge = new Edge;
        //czytam plik dopóki nie skończą się znaki, dodając wieżchołki do listy
        while(read>>edge->vertex1>>edge->vertex2>>edge->weight)
        {
            listOfEdges.push_back(*edge);
        }
        delete edge;
    } else
    {
        std::cerr<<"CANNOT OPEN FILE: "<<fileName<<"in function readDataFromFile - kruskalList";
        return;
    }

}
///metoda drukująca liste krawędzi i wierzchołków z ich wagami
void KruskalList::printList() const {
    for (auto listOfEdge : listOfEdges) {
        std::cout << listOfEdge.vertex1 << " " << listOfEdge.vertex2<<" "<<listOfEdge.weight;
    }
}
