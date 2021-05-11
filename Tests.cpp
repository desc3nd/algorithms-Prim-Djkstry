

#include <iostream>
#include "Tests.h"
#include "DataCreator.h"
#include "PrimeL.h"
#include "Dijkstry.h"

void Tests::test() {
    int numberOfVerticles;
    int numberOfEdges;
    std::cout << "\n Wpisz ilosc wierzcholkow:";
    std::cin >> numberOfVerticles;
    std::cout << "\n Wpisz ilosc krawedzi:";
    std::cin >> numberOfEdges;
    while (numberOfEdges < 0 || numberOfVerticles < 0) {
        std::cout << "\n Wpisz ilosc wierzcholkow:";
        std::cin >> numberOfVerticles;
        std::cout << "\n Wpisz ilosc krawedzi:";
        std::cin >> numberOfEdges;
    }
    int numberOfTests = 100;
    int sumPrimeArr = 0;
    int sumPrimeList = 0;
    int sumDijArr = 0;
    int sumDijList = 0;
    for (int i = 0; i < numberOfTests; i++) {
        DataCreator dataCreator(numberOfVerticles, numberOfEdges);
        dataCreator.create();
        PrimeL primeL("dane.txt");
        primeL.readDataFromFile("dane.txt");
        primeL.PrimeDoArray(false);
        sumPrimeArr += primeL.returnElapsedTime();
        primeL.readDataFromFile("dane.txt");
        primeL.PrimeDoList(false);
        sumPrimeList += primeL.returnElapsedTime();
        Dijkstry dijkstry("dane.txt");
        dijkstry.readDataFromFile("dane.txt");
        dijkstry.dijkstraTab(false);
        sumDijArr += dijkstry.returnElapsedTime();
        dijkstry.readDataFromFile("dane.txt");
        dijkstry.dijkstraList(false);
        sumDijList += dijkstry.returnElapsedTime();

    }
    int averagePrimeArr = sumPrimeArr / numberOfTests;
    int averagePrimeList = sumPrimeList / numberOfTests;
    int averageDijArr = sumDijArr / numberOfTests;
    int averageDijList = sumDijList / numberOfTests;
    std::cout << "srednia ze 100 testow  dla prime w macierzy: " << averagePrimeArr << std::endl;
    std::cout << "srednia ze 100 testow  dla prime w liscie : " << averagePrimeList << std::endl;
    std::cout << "srednia ze 100 testow  dla dijkstry w macierzy : " << averageDijArr << std::endl;
    std::cout << "srednia ze 100 testow  dla dijkstry w liście : " << averageDijList << std::endl;

}
