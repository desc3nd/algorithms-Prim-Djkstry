
#include "DataCreator.h"
#include<fstream>
#include <iostream>
#include <random>
#include <ctime>

void DataCreator::create() {
    std::ofstream write("dane.txt");
    srand (time(nullptr));
    if(write.is_open())
    {
        write<<numberOfEdges<<" "<<numberOfVerticles<<std::endl;
        for(int i = 0; i < numberOfVerticles; i++ )
        {
            for(int j = i; j < numberOfVerticles; j++)
            {
                write<<i<<" "<<j<<" "<<verticlesTab[i][j];
                write<<std::endl;
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


void DataCreator::generateGraf() {
    int realNumberOfEdges = (numberOfVerticles * (numberOfVerticles - 1)) / 2;
    int number = 0;
    bool Ver[numberOfVerticles][numberOfVerticles];
    for(int i = 0; i < numberOfVerticles; i++)
    {
        for(int j = 0; j < numberOfVerticles; j++)
        {
            Ver[i][j] = false;
        }
    }
    for(int i = 0; i < numberOfVerticles; i++)
    {
        for(int j = 0; j < numberOfVerticles; j++)
        {
            if(Ver[i][j])
            {
                std::cerr<<"1"<<" ";
            }
            else
            {
                std::cerr<<"0 ";
            }
        }
        std::cerr<<std::endl;
    }
    srand(time(nullptr));

    while(number != realNumberOfEdges)
    {
        int j =0;
        int i = rand() % (numberOfVerticles - 1) +1 ;// 1 - 31
        i--;//0-30
        j = rand() %(numberOfVerticles-i -1) + i + 1 ;
//        while (i==0 && j==0 || (i==numberOfVerticles-1 && j==numberOfVerticles-1))
//        {
//            i = rand() % (numberOfVerticles) +1 ;// 1 - 32
//        }
        if(!Ver[i][j])
        {
            verticlesTab[i][j] = rand() % 30 + 2;
            Ver[i][j] = true;
            number++;
            std::cerr<<number<<std::endl;
        }
    }
    for(int i = 0; i < numberOfVerticles; i++)
    {
        for(int j = 0; j < numberOfVerticles; j++)
        {
            if(Ver[i][j])
            {
                std::cerr<<"1"<<" ";
            }
            else
                {
                    std::cerr<<"0 ";
                }
        }
        std::cerr<<std::endl;
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
