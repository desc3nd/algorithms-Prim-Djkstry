//
// Created by Marcinek on 07.05.2021.
//

#ifndef ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DATACREATOR_H
#define ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DATACREATOR_H


#include <list>

class DataCreator {
public:
    void create(int numberOfVerticles, int numberOfEdges);
    int numberOfVerticles;
    int numberOfEdges;
    void dispalayTab();
    void generateGraf();

    DataCreator(int numberOfVerticles,int numberOfEdges);

    ~DataCreator();

private:
    int randomRangeExcept (int min, int max, std::list<int> &exeptions);

    int **verticlesTab;

};


#endif //ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DATACREATOR_H
