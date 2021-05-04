#include <iostream>
#include "KruskalList.h"
int main() {
    KruskalList kruskalList;
    kruskalList.readDataFromFile("dane.txt");
    kruskalList.printList();
}
