
#ifndef ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DATACREATOR_H
#define ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DATACREATOR_H


#include <list>

class DataCreator {
public:
    void create();

    void dispalayTab();

    DataCreator(int numberOfVerticles,int numberOfEdges);

    ~DataCreator();

private:
    int numberOfVerticles;
    int numberOfEdges;
    int **verticlesTab;
    void generateGraf();
};


#endif //ALGORITHMS_KRUSKAL_PRIM_DJKSTRY_BELLMANFORD_DATACREATOR_H
