#include <iostream>
#include<vector>
#include<ville.h>
#ifndef ROUTE_H
#define ROUTE_H
using namespace std;
class Route
   {
    private:
    float longeur;
    float pheromone;
    ville &premiere;
    ville &seconde;

    public:
    Route( ville *pre,ville *deuxie);
    void evaporer_pheromone(); //simulation de la pheromone
}
#endif // ROUTE_H
