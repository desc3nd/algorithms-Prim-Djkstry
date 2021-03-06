//
// Created by Marcinek on 08.05.2021.
//

#include <iostream>
#include "Menu.h"
#include "Dijkstry.h"
#include "PrimeL.h"
#include "DataCreator.h"
#include "Tests.h"
void Menu::start() {
    int xcin=0;
    bool dataInAnotherFile = false;
    std::string fileName;
    while(xcin != -1)
    {
        std::cout<<"Witaj. Wybierz akcje ktora chcesz zrobic:"<<std::endl;
        std::cout<<"1.Wczytaj graf z pliku."<<std::endl;
        std::cout<<"2.Wyswietl graf macierzowo i listowo"<<std::endl;
        std::cout<<"3.Algorytm Dijkstry"<<std::endl;
        std::cout << "4.Algorytm Prima" << std::endl;
        std::cout << "5.Rób testy" << std::endl;
        std::cout << "-1.Wyjdz";
        std::cin>>xcin;
        if(xcin == 1)
        {
            std::cout<<"Wpisz nazwe pliku i upewnij sie ze jest w odpowiednim katalogu: ";
            std::cin>>fileName;
            Dijkstry dijkstry(fileName);
            dijkstry.readDataFromFile(fileName);
            dijkstry.displayNeighbourList();
            dataInAnotherFile = true;
            std::cout<<"Sukces!";
        }
        else if(xcin == 2)
        {
            if(dataInAnotherFile)
            {
                Dijkstry dijkstry(fileName);
                dijkstry.readDataFromFile(fileName);
                std::cout<<"Twoj graf macierzowo: \n";
                dijkstry.printTab();
                std::cout<<"Twoj graf listowo \n";
                dijkstry.displayNeighbourList();
            } else
            {
                Dijkstry dijkstry("dane.txt");
                dijkstry.readDataFromFile("dane.txt");
                std::cout<<"Twoj graf macierzowo: \n";
                dijkstry.printTab();
                std::cout<<"Twoj graf listowo \n";
                dijkstry.displayNeighbourList();
            }
        }
        else if(xcin == 3) {
            if (!dataInAnotherFile) {
                int ver, edg;
                std::cout << "wpisz ilość krawedzi: ";
                std::cin >> edg;
                std::cout << "wpisz ilość wierzcholkow: ";
                std::cin >> ver;
                while (edg > 10000 || ver > 10000 || edg < 0 || ver < 0) {
                    std::cerr << "zla liczba wierzcholkow badz krawedzi, wpisz ponownie: \n";
                    std::cout << "wpisz ilość krawedzi: ";
                    std::cin >> edg;
                    std::cout << "wpisz ilość wierzcholkow: ";
                    std::cin >> ver;
                }
                DataCreator dataCreator(ver, edg);
                dataCreator.create();
                Dijkstry dijkstry("dane.txt");
                dijkstry.readDataFromFile("dane.txt");
                std::cout << "metoda za pomoca tablicy:\n";
                dijkstry.dijkstraTab(true);
                std::cout << "czas w mikrosekundach: " << dijkstry.returnElapsedTime() << std::endl;
                dijkstry.readDataFromFile("dane.txt");
                dijkstry.dijkstraList(true);
                std::cout << "czas w mikrosekundach: " << dijkstry.returnElapsedTime() << std::endl;
            } else {
                Dijkstry dijkstry(fileName);
                dijkstry.readDataFromFile(fileName);
                std::cout << "metoda za pomoca tablicy:\n";
                dijkstry.dijkstraTab(true);
                std::cout << "czas w mikrosekundach: " << dijkstry.returnElapsedTime() << std::endl;
                dijkstry.readDataFromFile(fileName);
                dijkstry.dijkstraList(true);
                std::cout << "czas w mikrosekundach: " << dijkstry.returnElapsedTime() << std::endl;
            }
        }
            else if(xcin == 4)
            {
                if(!dataInAnotherFile)
                {
                    int ver, edg;
                    std::cout << "wpisz ilość krawedzi: ";
                    std::cin >> edg;
                    std::cout << "wpisz ilość wierzcholkow: ";
                    std::cin >> ver;
                    while (edg > 10000 || ver > 10000 || edg < 0 || ver < 0) {
                        std::cerr << "zla liczba wierzcholkow badz krawedzi, wpisz ponownie: \n";
                        std::cout << "wpisz ilość krawedzi: ";
                        std::cin >> edg;
                        std::cout << "wpisz ilość wierzcholkow: ";
                        std::cin >> ver;
                    }
                    DataCreator dataCreator(ver, edg);
                    dataCreator.create();
                    PrimeL primeL("dane.txt");
                    primeL.readDataFromFile("dane.txt");
                    std::cout << "metoda za pomoca tablicy:\n";
                    primeL.PrimeDoArray(true);
                    std::cout << "czas w mikrosekundach: " << primeL.returnElapsedTime() << std::endl;
                    std::cout << "metoda za pomoca listy:\n";
                    primeL.readDataFromFile("dane.txt");
                    primeL.PrimeDoList(true);
                    std::cout << "czas w mikrosekundach: " << primeL.returnElapsedTime() << std::endl;
                } else {
                    PrimeL primeL(fileName);
                    primeL.readDataFromFile(fileName);
                    std::cout << "metoda za pomoca tablicy:\n";
                    primeL.PrimeDoArray(true);
                    std::cout << "czas w mikrosekundach: " << primeL.returnElapsedTime() << std::endl;
                    primeL.readDataFromFile(fileName);
                    std::cout << "metoda za pomoca listy:\n";
                    primeL.PrimeDoList(true);
                    std::cout << "czas w nmikrosekundach: " << primeL.returnElapsedTime() << std::endl;
                }
            } else if (xcin == 5) {
            Tests tests;
            tests.test();
        } else if (xcin == -1) {
            exit(0);
        } else {
            while (xcin != 1 || xcin != 2 || xcin != 3 || xcin != 4 || xcin != -1) {
                std::cerr << "Wybrales zla opcje wybierz ponownie:";
                std::cin >> xcin;
            }
        }

    }
}



