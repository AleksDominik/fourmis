
#include <iostream>
#include<vector>
using namespace std;
#ifndef VILLE_H
#define VILLE_H
#include<vector>
class ville
{
   private :

    float position_X;
    float position_Y;
    //vector<ville*> villeconnecte;
   public:
   vector<int> routelie;
    vector<float> getposition ();
    ville(float xx,float yy);
    friend bool conditiondegalite(ville* a, ville* b);
   // bool operator==(ville*);
    ville* operator=(ville*);
    void egalite(ville* a );
    vector<int> getroutelie();
    void putvillelie(ville*);
    void display();

}
#endif
;
#ifndef ROUTE_H
#define ROUTE_H
class Route
   {
    private:
    float longueur;

    ville *premiere;
    ville *seconde;


    public:
    float pheromone;//facilitation de code vu que les agents modifient le niveau de pheromone o peut biensur utiliser une methode friend plus syntaxiqueñent correct
    Route( ville *pre,ville *deuxie);
    void evaporer_pheromone(); //simulation de la pheromone
    float getphero();
    float getlongueur();
    ville* getpre();
    ville* getsec();
}

#endif
;
#ifndef ANT_H
#define ANT_H


class ant
{
    private:




public:
    vector<ville*> villedejavisite;//lors d'un tour
    vector<ville*> cheminprec;// tout son parcour
     vector<ville*> cheminprec2;
    ville *destination;
    ville *depart;
    float distanceaparcourir;
    float alfa;
    float beta;
    float gamma;
    float quantite_nourriture=0;
    int nb_foisrepe;
    bool porte_nourriture=false;
//****methodes*****
    float longueur_empreinte2=0;
    float longueur_empreinte=0.0001;//pour evite les division par zeros
    ant();
    ant(ant papa, ant maman);
    void putdestination(ville* vill);
    void putdepart(ville* vill);
    float getTendance(Route *road);
    void prendre_nourriture();
    void laisser_nourriture();
    float get_longueur_empreinte();
    void deposer_pheromone(Route *road);
    void marcher();//avancer une etape plus
    void mutation();
    bool pasvisite(ville * road);
    ant * operator=(ant* );

}
#endif
;




#ifndef CIVILISATION_H
#define CIVILISATION_H
#include<vector>
 class Civilisation
{
private :
     float err=0;
    ville *src_nourriture;
    ville *nid;
    vector<Route*> route;
    vector<ville*> villes;
    vector<ant*> fourmis;
    int selectionNaturelle;
public:
    void faireuntour();
    void initifourmis(int nombrfourmi);
    void initiroute();
    void initiville(int nombrville);//etape proto
    void routage(ant *f);
    void traitement();
    vector <ville*> getville();
    vector<Route *> getroute();
    vector<ant*> getant();
  //  void metjourdisparcour(ant& four);
    void chemin();
    void rangelesantq();
    void progeniture();
    void construirenet();
};
#endif


