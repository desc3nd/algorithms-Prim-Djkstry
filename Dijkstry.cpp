

#include <fstream>
#include "Dijkstry.h"
#include<iostream>
#include <vector>
///konstruktor inicjalizujący elementy
Dijkstry::Dijkstry(std::string const &fileName) {
    ///inicjacja największej wartości
    INF = 0x3f3f3f3f;
    ///wczytanie z pliku odpowiednio liczby wierzchołków i krawędzi
    readNumbers(fileName);
    ///utworzenie oraz inicjacja zmiennytch przechowujących sąsiadów w formie macierzy i listy
    verticlesTab = new int *[numberOfVerticles];
    verticleList = new std::list<pair> [numberOfVerticles];
    queue = new std::list<int>;
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        verticlesTab[i] = new int[numberOfVerticles];
    }
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        for(int j = 0; j < numberOfVerticles; ++j)
        {
            verticlesTab[i][j] = 0;
        }
    }
}

///metoda odczytująca wszystko z pliku
void Dijkstry::readDataFromFile(const std::string &fileName) {
    std::ifstream read(fileName);
    //sprawdzam czy plik się otworzył
    if(read.is_open())
    {
        //wczytuje dwie pierwsze wartości
        read>>numberOfEdges>>numberOfVerticles;
        //zmienna przechowująca krawędź
        //czytam plik dopóki nie skończą się znaki, dodając wieżchołki do listy
        int ver1, ver2,weight;
        while(read>>ver1>>ver2>>weight)
        {
            verticlesTab[ver1][ver2] = weight;
            verticleList[ver1].emplace_back(ver2,weight);
            queue->push_back(ver1);
        }
    } else
    {
        std::cerr<<"CANNOT OPEN FILE: "<<fileName<<"in function readDataFromFile - PrimeL";
        return;
    }
    read.close();

}

///metoda odczytująca 2 pierwsze wartości z pliku
void Dijkstry::readNumbers(const std::string &fileName) {
    std::ifstream read(fileName);
    //sprawdzam czy plik się otworzył
    if(read.is_open())
    {
        //wczytuje dwie pierwsze wartości
        read>>numberOfEdges>>numberOfVerticles;
    }
    else
    {
        std::cerr<<"CANNOT OPEN FILE: "<<fileName<<"in function readNumber - Djikstry";
        return;
    }
    read.close();
}

///destruktor klasy
Dijkstry::~Dijkstry() {
    for(int i = 0; i < numberOfVerticles; ++i) {
        delete [] verticlesTab[i];
    }
    delete [] verticlesTab;
    delete queue;
}

///metoda wyswietlająca miacierz sąsiedztwa
void Dijkstry::printTab() const {
    std::cout<<std::endl<<"-  ";
    for(int i=0 ;i<numberOfVerticles;++i)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    for(int i = 0; i < numberOfVerticles; ++i) {
        std::cout << i << "| ";
        for (int j = 0; j < numberOfVerticles; ++j) {
            std::cout << verticlesTab[i][j] << " ";
        }
        std::cout << "\n";
    }

}

///metoda tworząca algorytm dijkstry z wykorzystaniem macierzy sąsiedztwa
void Dijkstry::dijkstraTab(bool outcome) {
    //inicjacja zmiennych pomocniczych
    int *key;
    key = new int[numberOfVerticles];
    int *parent;
    parent = new int[numberOfVerticles];
    int ver = 0;
    bool *reviewed;
    reviewed = new bool[numberOfVerticles];
    stopWatch.startCountingTime(); //startuje czas
    for (int i = 0; i < numberOfVerticles; i++) {
        reviewed[i] = false;
        key[i] = INF;
        parent[i] = -1;
    }
    key[ver] = 0; // wartość pierwszego wierzchołka
    while (!queue->empty()) //dopoki kolejka wierzchołków nie jest pusta
    {
        ver = queue->front(); //wyciągam pierwszy wierzchołek z kolejki
        queue->remove(ver); //usuwam ten wierzchołek z kolejki
        for (int i = ver + 1; i < numberOfVerticles; ++i) { //przeglądam sąsiadów wierzchołka
            if (verticlesTab[ver][i] != 0) {
                int neighbour, weight;
                neighbour = i;
                weight = verticlesTab[ver][i];
                if (reviewed[neighbour] == false && key[neighbour] > key[ver] +
                                                                     weight) { //jeżeli wierzchołek nie jest przejrzany jego wartość jest mniejsza to przypisuje mu nową wartość
                    key[neighbour] = key[ver] + weight;
                    parent[neighbour] = ver;
                }
            }
        }
    }
    stopWatch.stopCountingTime(); //zatrzymuje czas
    if (outcome) //jeżeli chce wyświetlić wynik
    {
        for (int i = 0; i < numberOfVerticles; ++i) {
            std::cout << "ver " << i << ":" << parent[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < numberOfVerticles; ++i) {
            if (key[i] != INF) {
                std::cout << " " << key[i];
            }
        }
        std::cout << std::endl;
    }
//usuwam zmienne pomocnocze
    delete[] key;
    delete[] reviewed;
    delete[] parent;
}

///metoda tworząca algorytm dijkstry z wykorzystaniem listy sąsiedztwa
void Dijkstry::dijkstraList(bool outcome) {
    int *key;
    key = new int[numberOfVerticles];
    int *parent;
    parent = new int[numberOfVerticles];
    int ver = 0;
    bool *reviewed;
    reviewed = new bool[numberOfVerticles];
    stopWatch.startCountingTime();
    for (int i = 0; i < numberOfVerticles; i++) {
        reviewed[i] = false;
        key[i] = INF;
        parent[i] = -1;
    }
    key[ver] = 0;
    while(!queue->empty())
    {
        ver = queue->front();
        queue->remove(ver);
        for (auto it : verticleList[ver]) { //róznica taka że tu przeglądam wszystkich sąsiadów listy
            int neighbour, weight;
            neighbour = it.first;
            weight = it.second;
            if (reviewed[neighbour] == false && key[neighbour] > key[ver] + weight) {
                key[neighbour] = key[ver] + weight;
                parent[neighbour] = ver;
            }
        }
    }
    stopWatch.stopCountingTime();
    if (outcome) {
        for (int i = 0; i < numberOfVerticles; ++i) {
            std::cout << "ver " << i << ":" << parent[i] << " ";
        }
        std::cout << std::endl;
        for (int i = 0; i < numberOfVerticles; ++i) {
            if (key[i] != INF) {
                std::cout << " " << key[i];
            }
        }
        std::cout << std::endl;
    }

    delete[] key;
    delete[] reviewed;
    delete[] parent;

}

///metoda wyświetlająca sąsiadów wierzchołka przy pomocy listy sąsiedztwa
void Dijkstry::displayNeighbourList() const{
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        std::cout << "ver " << i <<std::endl;
        //pętla po listach
        for(auto & it : verticleList[i])
        {
            std::cout <<" |wierzcholek:"<< it.first <<" waga:"<<it.second <<"|";
        }
        std::cout<<std::endl;
    }

}
long long int Dijkstry::returnElapsedTime()  {
    return stopWatch.elapsedTime();
}
