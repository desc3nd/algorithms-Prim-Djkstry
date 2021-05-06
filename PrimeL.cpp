
#include <iostream>
#include <vector>
#include <utility>
#include "PrimeL.h"
///metoda odpowaidająca za odczyt danych z pliku do listy krawędzi
void PrimeL::readDataFromFile(const std::string &fileName) {
    std::ifstream read(fileName);
    //sprawdzam czy plik się otworzył
    if(read.is_open())
    {
        //wczytuje dwie pierwsze wartości
        read>>numerOfEdges>>numberOfVerticles;
        //zmienna przechowująca krawędź
        //czytam plik dopóki nie skończą się znaki, dodając wieżchołki do listy
        int ver1, ver2,weight;
        while(read>>ver1>>ver2>>weight)
        {
            //wrzucam do pierwszej listy do wierzchołka sąsiadów
            verticles[ver1].emplace_back(ver2,weight);
            //wrzucam do drugiej listy wierzchołka sąsiadów
            verticles[ver2].emplace_back(ver1,weight);
          //  tabVerticles[ver1][ver2] = weight;
        }
    } else
    {
        std::cerr<<"CANNOT OPEN FILE: "<<fileName<<"in function readDataFromFile - kruskalList";
        return;
    }

}
///metoda drukująca liste krawędzi i wierzchołków z ich wagami
void PrimeL::printList() const {
    for (auto listOfEdge : *verticles) {
        std::cout << listOfEdge.first << " " << listOfEdge.second;
    }
}

PrimeL::PrimeL(const std::string &fileName) {
    //ustawiam nieskonczość
    INF = 0x3f3f3f3f;
    //alokuje pamięć na tablice list wirzchołków i macierzy sąsiadów
    verticles = new std::list<pair> [numberOfVerticles + 1];
//    tabVerticles = new int *[numberOfVerticles + 1];
//    for(int i = 0; i < numberOfVerticles + 1; ++i)
//    {
//        tabVerticles[i] = new int[numberOfVerticles + 1];
//    }
//    for(int i = 0; i < numberOfVerticles; i++)
//    {
//        for(int j = 0; j < numberOfVerticles; j++)
//        {
//            tabVerticles[i][j] = 0;
//        }
//    }
    //wczytuje wierzchołki
    readDataFromFile(fileName);
    //inicjuje kolejke priorytetową
    for(int i = 0; i < numberOfVerticles+1; i++)
    {
        for(auto & it : verticles[i])
        {
            queue.push(it);
        }
    }

}

void PrimeL::PrimeDo() {
    //zmienna inicjalizująca wierzchołek początkowy
    int startVertex = 0;
    //zmienna przechowująca wektor kluczy
    std::vector<int> key(numberOfVerticles,INF);
    //zmienna przewująca wiadomość czy wierzchołek przechodził przez mst czy nie
    std::vector<bool> ifInMst(numberOfVerticles,false);
    //zmienna przechowująca rodzica wierzchołka zainicjowana wartościami -1
    std::vector<int> parent(numberOfVerticles,-1);
    //zeruje pierwszy z wierzchołków
    key[startVertex] = 0;
    queue.push(pair(key[startVertex],startVertex));
    //dopóki kolejka wierzchołków nie jest pusta
    while(!queue.empty())
    {
        int ver = queue.top().second;
        std::cerr<<"to jest war "<<ver<<std::endl;
        ifInMst[ver] = true;
        queue.pop();
        for(auto it : verticles[ver])
        {
            int neighbour,weight;
            neighbour = it.first;
            weight = it.second;
            if(ifInMst[neighbour] == false && key[neighbour] > weight)
            {
                key[neighbour] = weight;
                queue.push(pair(key[neighbour],neighbour));
                parent[neighbour] = ver;
            }
        }

    }
    for (int i = 1; i < numberOfVerticles; i++)
    {
        std::cout<<"ver "<<i<<":"<<parent[i]<<" ";
    }
    std::cout<<std::endl;
    for (int i = 1; i < numberOfVerticles; i++)
    {
        std::cout<<key[i]<<" ";
    }

}
///metoda wyświetlająca liste sąsiadów dla każdego wierzchołka wraz z wagami krawędzi
void PrimeL::displayNeighbourList() const {
    //pętla po tablicy list
    for(int i = 0; i < numberOfVerticles; i++)
    {
        std::cout << "ver " << i <<std::endl;
        //pętla po listach
        for(auto & it : verticles[i])
        {
            std::cout <<" |wierzcholek:"<< it.first <<" waga:"<<it.second <<"|";
        }
        std::cout<<std::endl;
    }

}

void PrimeL::printTab() const {
//    for(int i = 0; i < numberOfVerticles; i++)
//    {
//        for(int j = 0; j < numberOfVerticles; j++)
//        {
//            std::cout<<tabVerticles[i][j]<<" ";
//        }
//        std::cout<<"\n";
//    }

}

PrimeL::~PrimeL() {
   for (int i = 0; i< numberOfVerticles; i++)
   {
        delete [] verticles;
   }


}
