
#include "DataCreator.h"
#include<fstream>
#include <iostream>
#include <random>
#include <ctime>
///metoda odpowiadająca za zapisanie wygenerowanego grafu do pliku
void DataCreator::create() {
    //generuje graf
    generateGraf();
    std::ofstream write("dane.txt");
    srand (time(nullptr));
    //otwieram plik
    if(write.is_open())
    {
        write<<numberOfEdges<<" "<<numberOfVerticles<<std::endl;
        for(int i = 0; i < numberOfVerticles; i++ )
        {
            for(int j = i; j < numberOfVerticles; j++)
            {
                if(verticlesTab[i][j]!=0)
                {
                    write<<i<<" "<<j<<" "<<verticlesTab[i][j];
                    write<<std::endl;
                }

            }

        }
    }
    else
    {
        std::cerr<<"CANNOT OPEN FILE: dane.txt "<<"in function readNumber - Djikstry";
        return;
    }
    write.close();

}

///metoda odpowiadająca za stworzenie grafu
void DataCreator::generateGraf() {
    int realNumberOfEdges = numberOfEdges;
    int number = 0;
    //zmienna tablica sprawdzająca czy element juz ma krawędź
    bool Ver[numberOfVerticles][numberOfVerticles];
    //inicjacja zmiennej pomocnicznej
    for (int i = 0; i < numberOfVerticles; i++) {
        for (int j = 0; j < numberOfVerticles; j++) {
            Ver[i][j] = false;
        }
    }
    srand(time(nullptr));
    //stworzenie połączenia między wierzchołkami 0->1->2->3->n
    for (int i = 0; i < numberOfVerticles - 1; i++) {
        verticlesTab[i][i + 1] = rand() % 30 + 1;
        Ver[i][i + 1] = true;
    }
    number = numberOfVerticles - 1;
    //generowanie dodatkowych krawędzi
    while (number != realNumberOfEdges) {
        int j = 0;
        int i = rand() % (numberOfVerticles - 1) + 1;// 1 - 31
        i--;
        //0-30
        j = rand() % (numberOfVerticles - i - 1) + i + 1;
        if (!Ver[i][j]) {
            verticlesTab[i][j] = rand() % 30 + 1;
            Ver[i][j] = true;
            number++;
        }
    }
}

///koonstruktor klasy odpowiadający za inicjacje elemtntów
DataCreator::DataCreator(int numberOfVerticles, int numberOfEdges) {
    this->numberOfVerticles = numberOfVerticles;
    this->numberOfEdges = numberOfEdges;
    verticlesTab = new int *[numberOfVerticles];
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        verticlesTab[i] = new int [numberOfVerticles];
    }
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        for(int j = 0; j < numberOfVerticles; ++j)
        {
            verticlesTab[i][j] = 0;
        }
    }

}

///metoda wyświetlająca wygenerowany graf w postaci macierzowej
void DataCreator::dispalayTab() {
    for(int i = 0; i < numberOfVerticles; i++)
    {
        for(int j = 0; j < numberOfVerticles; j++)
        {
            std::cout<< verticlesTab[i][j]<< " ";
        }
        std::cout<<"\n";
    }


}

///destruktor
DataCreator::~DataCreator() {
    for(int i = 0; i<numberOfVerticles; ++i)
    {
        delete [] verticlesTab[i];
    }
    delete [] verticlesTab;

}

