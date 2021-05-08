
#include "DataCreator.h"
#include<fstream>
#include <iostream>
#include <random>
#include <ctime>

void DataCreator::create(int numberOfVerticles, int numberOfEdges) {
    std::ofstream write("dane.txt");
    srand (time(nullptr));
    if(write.is_open())
    {
        write<<numberOfEdges<<" "<<numberOfVerticles;
        int ver = 0;
        int ver2;
        ver2 = rand() % numberOfVerticles;
        int weight;
        weight = rand() %100 +1;
        while(ver2 == ver)
        {
            ver2 = rand() % numberOfVerticles;
        }
        write<<std::endl<<ver<<" "<<ver2<<" "<<weight<<std::endl;
        numberOfEdges--;
        int possibility = numberOfEdges/2;
        while (numberOfEdges !=0)
        {
            int verStay = rand() % numberOfEdges;
            if(verStay < possibility)
            {
                ver++;
                possibility++;
            } else{
                possibility++;
            }
            ver2 = rand() % numberOfVerticles;
            while(ver2 == ver)
            {
                ver2 = rand() % numberOfVerticles;
            }
            weight = rand() % 100 + 1;
            write<<ver<<" "<<ver2<<" "<<weight<<std::endl;
            numberOfEdges--;
        }
    }
    else
    {
        std::cerr<<"CANNOT OPEN FILE: dane.txt "<<"in function readNumber - Djikstry";
        return;
    }
    write.close();

}

void DataCreator::generateGraf() {
    int realNumberOfEdges = (numberOfVerticles * (numberOfVerticles - 1)) / 2;
    int number = 0;
    bool Ver[numberOfVerticles][numberOfVerticles];
    for(int i = 0; i < numberOfVerticles; ++i)
    {
        for(int j = 0; j < numberOfVerticles; ++j)
        {
            Ver[i][j] = false;
        }
    }
    srand(time(nullptr));

    while(number != realNumberOfEdges)
    {
         int i = rand() % (numberOfVerticles) +1 ;// 1 - 32
         int  j = rand() %(numberOfVerticles-i+1) + i ; //

        if(!Ver[i-1][j])
        {
            verticlesTab[i-1][j] = rand() % 30 + 1;
            Ver[i-1][j] = true;
            number++;
        }

    }
}
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

DataCreator::~DataCreator() {
    for(int i = 0; i<numberOfVerticles; ++i)
    {
        delete [] verticlesTab[i];
    }
    delete [] verticlesTab;

}

//int DataCreator::randomRangeExcept(int min, int max, std::list<int> &exeptions) {
//      auto  number = rand() % max + min;
//      exeptions.assign(max,0);
//  bool inExeptions = true;
//  while(inExeptions)
//  {
//      for(std::_List_iterator<int>it=exeptions.begin(); it!=exeptions.end(); ++it)
//      {
//          if(exeptions[1]==number)
//          {
//              number = rand() % max + min;
//              it=exeptions.begin();
//          }
//      }
//
//  }
//
//}
