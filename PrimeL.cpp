
#include <iostream>
#include <vector>
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
            verticles->push_back(pair(ver1,weight));
            //wrzucam do pierwszej listy do wierzchołka sąsiadów
            verticlesList[ver1].emplace_back(ver2, weight);
            //wrzucam do drugiej listy wierzchołka sąsiadów
            verticlesList[ver2].emplace_back(ver1, weight);
            verticlesTab[ver1][ver2] = weight;
            verticlesTab[ver2][ver1] = weight;
            queue.push(pair(ver1,weight));
        }
    } else
    {
        std::cerr<<"CANNOT OPEN FILE: "<<fileName<<"in function readDataFromFile - PrimeL";
        return;
    }
    read.close();
}
///metoda drukująca liste krawędzi i wierzchołków z ich wagami
void PrimeL::printList() const {
    for (auto listOfEdge : *verticlesList) {
        std::cout << listOfEdge.first << " " << listOfEdge.second;
    }
}

PrimeL::PrimeL(const std::string &fileName) {
    readNumberOfVerticles(fileName);
    //ustawiam nieskonczość
    INF = 0x3f3f3f3f;
    //alokuje pamięć na tablice list wirzchołków i macierzy sąsiadów
    verticlesList = new std::list<pair> [numberOfVerticles];
    verticles = new std::vector<pair>;
    verticlesTab = new int *[numberOfVerticles];
    for(int i = 0; i < numberOfVerticles ; ++i)
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
    readDataFromFile(fileName);
}

void PrimeL::PrimeDoList(bool outcome) {
    //zmienna inicjalizująca wierzchołek początkowy
    int startVertex = 0;
    //zmienna przechowująca wektor kluczy
    std::vector<int> key(numberOfVerticles, INF);
    //zmienna przewująca wiadomość czy wierzchołek przechodził przez mst czy nie
    std::vector<bool> ifInMst(numberOfVerticles, false);
    //zmienna przechowująca rodzica wierzchołka zainicjowana wartościami -1
    std::vector<int> parent(numberOfVerticles, -1);
    //zeruje pierwszy z wierzchołków
    stopWatch.startCountingTime();
    key[startVertex] = 0;
    // queue.push(pair(key[startVertex],startVertex));
    //dopóki kolejka wierzchołków nie jest pusta
    while(!queue.empty())
    {
        int ver = queue.top().first;
        ifInMst[ver] = true;
        queue.pop();
        for(auto it : verticlesList[ver])
        {
            int neighbour,weight;
            neighbour = it.first;
            weight = it.second;
            if (ifInMst[neighbour] == false && key[neighbour] > weight) {
                key[neighbour] = weight;
                queue.push(pair(neighbour, key[neighbour]));
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
        int sum = 0;
        for (int i = 0; i < numberOfVerticles; ++i) {
            if (key[i] != INF) {
                sum += key[i];
            }
        }
        std::cout << "suma: " << sum;
        std::cout << std::endl;
    }

//    while(!queue.empty())
//    {
//        queue.pop();
//    }
}
///metoda wyświetlająca liste sąsiadów dla każdego wierzchołka wraz z wagami krawędzi
void PrimeL::displayNeighbourList() const {
    //pętla po tablicy list
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        std::cout << "ver " << i <<std::endl;
        //pętla po listach
        for(auto & it : verticlesList[i])
        {
            std::cout <<" |wierzcholek:"<< it.first <<" waga:"<<it.second <<"|";
        }
        std::cout<<std::endl;
    }

}
///metoda wyświetlająca tablice sąsiadów
void PrimeL::printTab() const {
    std::cout<<std::endl<<"-  ";
    for(int i=0 ;i<numberOfVerticles;++i)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        std::cout<<i<<"| ";
        for(int j = 0; j < numberOfVerticles; ++j)
        {
            std::cout << verticlesTab[i][j] << " ";
        }
        std::cout<<"\n";
    }

}
///destruktor czyści dynamicznie zaalokowane elemeny
PrimeL::~PrimeL() {
   delete [] verticlesList;
    delete verticles;
    for(int i = 0; i < numberOfVerticles; ++i) {
        delete [] verticlesTab[i];
    }
    delete [] verticlesTab;
}

///metoda czytająca tylko liczbe wierzchołków i liczbę krawędzi
void PrimeL::readNumberOfVerticles(const std::string &fileName)  {
    std::ifstream read(fileName);
    //sprawdzam czy plik się otworzył
    if(read.is_open())
    {
        //wczytuje dwie pierwsze wartości
        read >> numerOfEdges >> numberOfVerticles;
    } else {
        std::cerr << "CANNOT OPEN FILE: " << fileName << "in function readNumberOfVerticles - PrimeL";
        return;
    }
    read.close();
}

///metoda odpowiadająca za algorytm prima w reprezentacji macierzowej
void PrimeL::PrimeDoArray(bool outcome) {
    exportFromArrayToQueue();
    int startVertex = 0;
    //zmienna przechowująca wektor kluczy
    std::vector<int> key(numberOfVerticles, INF);
    //zmienna przewująca wiadomość czy wierzchołek przechodził przez mst czy nie
    std::vector<bool> ifInMst(numberOfVerticles, false);
    //zmienna przechowująca rodzica wierzchołka zainicjowana wartościami -1
    std::vector<int> parent(numberOfVerticles, -1);
    //zeruje pierwszy z wierzchołków
    stopWatch.startCountingTime(); //wlaczam stoper
    key[startVertex] = 0;
    // queue.push(pair(key[startVertex],startVertex));
    //dopóki kolejka wierzchołków nie jest pusta
    while (!queue.empty()) //dopoki kolejka wierzchołków nie jest pusta
    {
        int ver = queue.top().first; //wez pierwszy  wierzchołek o najmniejszej wadze
        ifInMst[ver] = true; // ustaw jako przejrzany
        queue.pop(); // wyrzuc go
        for (int i = ver + 1; i < numberOfVerticles; ++i) // przeglądam sąsiadó
        {
            if (verticlesTab[ver][i] != 0) { //jeżeli jest krawdź między wierzchołkami
                int neighbour, weight;
                neighbour = i;
                weight = verticlesTab[ver][i];
                if (ifInMst[neighbour] == false &&
                    key[neighbour] > weight) { // jeżeli nie przejrzany i key wiekszy od aktualnej wagi
                    key[neighbour] = weight;
                    queue.push(pair(neighbour, key[neighbour]));
                    parent[neighbour] = ver;
                }
            }
        }
    }
    stopWatch.stopCountingTime(); // stopuje czas algorytmu
    if (outcome) //jezeli chce wypisac outcome
    {
        for (int i = 0; i < numberOfVerticles; ++i) {
            std::cout << "ver " << i << ":" << parent[i] << " ";
        }
        std::cout << std::endl;
        int sum = 0;
        for (int i = 0; i < numberOfVerticles; ++i) {
            if (key[i] != INF) {
                sum += key[i];
            }
        }
        std::cout << "suma: " << sum;
        std::cout << std::endl;
    }


}

///metoda wczytujaca do kolejki wierzchołki
void PrimeL::exportFromArrayToQueue() {
    for(int i = 0;  i < numberOfVerticles; ++i)
    {
        for(int j = i; j < numberOfVerticles; ++j)
        {
            if(verticlesTab[i][j] != 0)
            {
                queue.push(pair(i, verticlesTab[i][j]));
            }
        }
    }

}

///metoda zwracająca czas wykonania algorytmu
long long int PrimeL::returnElapsedTime() {
    return stopWatch.elapsedTime();
}
