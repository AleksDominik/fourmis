     #include<iostream>
    #include <ant.h>

    using namespace std;
    #include<random>
    #include <cstdlib>
    #include <ctime>
    #include <math.h>

    //methode de la classe ville

     ville::ville(float xx ,float yy ):position_X(xx),position_Y(yy)//constructeur
    {cout<<"la ville cree est a "<<this->position_X<<" d\'abscisse et a "<<this->position_Y<<"  d'ordonnee"<<endl;
     }
     vector<float> ville::getposition()
        {
         return {this->position_X,this->position_Y};
          }
     /*vector<ville> ville:: routage()
     {

     }*/
    bool conditiondegalite (ville* town,ville*b){
         bool veri=false;
         //cout<<b->getposition()[0]<<"a comp "<<town->getposition()[0]<<"et "<<b->getposition()[1]<<"a comp a "<<town->getposition()[1]<<endl;
        if(b->getposition()[0]==town->getposition()[0] && b->getposition()[1]==town->getposition()[1]){veri=true;}
         return veri;
    }
    ville* ville:: operator =(ville* dd){
         if(this!=dd)
         {
             this->routelie=dd->routelie;
             this->position_X=dd->getposition()[0];
             this->position_Y=dd->getposition()[1];


         }
       return this ;
    }
    vector<int > ville::getroutelie(){
        return routelie;
    }
    void ville:: display(){
        cout<<"il s'agit de la ville au coordonnees "<<position_X<<" "<<position_Y<<endl;
    }
void ville :: egalite(ville * dd){
    this->routelie=dd->routelie;
    this->position_X=dd->getposition()[0];
    this->position_Y=dd->getposition()[1];
}



    //methode de la classe ant**********************************************************




    std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(-5, 5);




    ant:: ant()
    {
        alfa=dis(gen);gamma=dis(gen);beta=dis(gen);
    cout<<alfa<<" "<<gamma<<" "<< beta<<endl;
    this->villedejavisite= {};
    this->cheminprec={};
    this->nb_foisrepe=0;
    this->quantite_nourriture=0;
    this->distanceaparcourir=-1;
    this->longueur_empreinte=0;
        }
    ant :: ant(ant papa, ant maman)
     {  cout<<"arrive t on ici";
        float temp;
        float selector=dis(gen);
        if(true){
        if(selector<2.5){temp=papa.alfa;this->alfa=temp;}
        if(selector>=   2.5) {temp=maman.alfa;this->alfa=temp;}}
        if(true){
        float selector1=dis(gen);
        if(selector1<2.5){temp=papa.beta;beta=temp;}
        else {beta=maman.beta;}}
        if(true){
        float selector2=dis(gen);
        if(selector2<2.5)gamma=papa.gamma;
        else gamma=maman.gamma;
        }
        this->distanceaparcourir=-1;
        this->longueur_empreinte=0;

        this->depart=maman.depart;
         cout<<"le depart de la fourmi cree est"; this->depart->display();
        this->destination=maman.destination;;
        cout<<"la destination de la fourmi cree est"; this->destination->display();
        this->villedejavisite= {};
        this->cheminprec={};
        this->nb_foisrepe=0;
        this->quantite_nourriture=0;//important pour la selection il faut une reinitialisation

    }
     ant* ant::operator =(ant* affecte)
     {
        this->villedejavisite=affecte->villedejavisite;
         this->cheminprec=affecte->cheminprec;
         this->destination=  affecte->destination;
         this->depart=affecte->depart;
         this->alfa=affecte->alfa;
         this->beta=affecte->beta;
         this->gamma=affecte->gamma;
         this->quantite_nourriture=affecte->quantite_nourriture;
         this->nb_foisrepe=affecte->nb_foisrepe;
         this->porte_nourriture=affecte->porte_nourriture;
         this->longueur_empreinte=affecte->longueur_empreinte;
         this->distanceaparcourir=affecte->distanceaparcourir;
         return  this;
     }


    float ant:: getTendance(Route* route)// a tester
    {
      int pp= pow(route->pheromone,alfa)*(1/pow(route->getlongueur(),beta));
      int dd= abs(route->getphero()*(1/pow(route->getlongueur(),beta)));
      if(pp<dd)return dd;
      else return pp ;

    }

    void ant:: prendre_nourriture(){
        porte_nourriture=true;
    }
    void ant:: laisser_nourriture(){porte_nourriture=false;}

    float ant::get_longueur_empreinte(){
        return longueur_empreinte;
    }
    void ant::marcher(){
    this->longueur_empreinte ++;
    cout<<"la fourmi a parcouri "<< this->longueur_empreinte<<endl;
    }
    void ant::putdestination(ville* desti){
        destination=desti;
    }
    void ant::putdepart(ville* vill) { depart=vill;}

    void ant:: deposer_pheromone(Route* road)
    {

        road->pheromone=road->pheromone+abs((1/(gamma*abs(3*longueur_empreinte))));//pour etre sur que les pheromones augmente qvec le temps
      //cout<<road->pheromone<<"pheromone"<<endl;
    }

    bool ant :: pasvisite (ville* town)
    { bool sortie=true;
       for(int i= 0; i<this->villedejavisite.size();i++)
       {
           if(conditiondegalite(town,this->villedejavisite[i])) {sortie= false;
          }

       }
    //if(!sortie){cout<<"ca doit marcher"<<endl;}
    return sortie;
    }

    /*void mutation(){

    }*/


    //methode de la classe road
    void Route::evaporer_pheromone()
    { pheromone=0.9*pheromone;//*(1/(9*longueur));

    }
    Route:: Route(ville* pre,ville* seco):premiere(pre),seconde(seco)
    {
      vector<float> temp1=premiere->getposition();
      vector<float> temp2 =seconde->getposition();

        this->longueur=sqrt(pow((temp1[0]-temp2[0]),2)+ pow((temp1[1]-temp2[1]),2));
    cout<<"la route est de longueur "<<longueur<<endl;
    pheromone=15/pow(longueur,5);
        }

    float Route::getphero(){
        return pheromone;
    }
    float Route :: getlongueur()
    {
        return longueur;
    }
    ville* Route:: getpre(){return premiere;}
    ville* Route:: getsec(){return seconde;}



     //methode de la classe civilisation
    void Civilisation ::initifourmis(int nomb)
    {
      fourmis.resize(nomb);//pour que la matrice est la bonne taille car declarer les pointeurs ne modifie pas la taille du tableau


        for(int j=0;j<fourmis.size();++j){
            fourmis[j]=new ant;
            fourmis[j]->depart=this->nid;
            fourmis[j]->destination=nid;
            fourmis[j]->distanceaparcourir=-1;//distanca a parcourir
            fourmis[j]->longueur_empreinte=0; //dsstination pour declencher le premier traitement
           // fourmis[j]->villede avisite.push_back(nid);cout<<fourmis[j]->villedejavisite.size()<<endl;
            cout<<"test"<<endl;
        }

      }

    void Civilisation:: faireuntour()
    {
        cout<<"cest reparti pour un tour ou un pas"<<endl;

        for(  int  g=0 ; (unsigned) g<fourmis.size();++g)
           {
            cout <<"il s'agit de la fourmi"<<g<<endl;
             ant * temp ;
             temp= fourmis[g];

            temp->marcher();
            cout<<"on test mtn"<< temp->distanceaparcourir<<"  "<<temp->longueur_empreinte<<endl;
             if(temp->distanceaparcourir <=temp->longueur_empreinte  )//la fourmi est arrivee a destination
             {
              this->routage(temp);
               }
             }
         for(  int  i=0 ; (unsigned) i<route.size();++i) route[i]->evaporer_pheromone();
    }


    void Civilisation ::initiville(int nombville)
    {

          villes.resize(17);
          villes[0]=new ville(0,0);
          villes[1]=new ville(1,1);
          villes[2]=new ville(2,3);
          villes[3]=new ville(4,2);
          villes[4]=new ville(3,0);
          villes[5]=new ville(2,-3);
          villes[6]=new ville(5,1);
          villes[7]=new ville(7,3);
          villes[8]=new ville(7,-1);
          villes[9]=new ville(7,-3);
          villes[10]=new ville(9,-1);
          villes[11]=new ville(9,1);
          villes[12]=new ville(10,3);
          villes[13]=new ville(12,1);
          villes[14]=new ville(11,-1);
          villes[15]=new ville(13,-2);
          villes[16]=new ville(15,0);
          src_nourriture= villes[16];
          nid=villes[0];
       /*

      villes.resize(nombville);//pour que la matrice est la bonne taille car declarer les pointeurs ne modifie pas la taille du tableau


        for(int j=0;j<=nombville;++j){
            float x;
            float y;
            cin>>x;
            cin>>y;
            villes[j]=new ville(x,y);
            cout<<"test1"<<endl;
        }*/

      }
    void Civilisation::initiroute(){
        route.resize(26);
        route[0]=new Route(villes[0],villes[1]);
        route[1]=new Route(villes[1],villes[2]);
        route[2]=new Route(villes[1],villes[4]);
        route[3]=new Route(villes[2],villes[3]);
        route[4]=new Route(villes[4],villes[3]);
        route[5]=new Route(villes[4],villes[6]);
        route[6]=new Route(villes[3],villes[6]);
        route[7]=new Route(villes[5],villes[4]);
        route[8]=new Route(villes[5],villes[6]);
        route[9]=new Route(villes[5],villes[9]);
        route[10]=new Route(villes[6],villes[8]);
        route[11]=new Route(villes[6],villes[7]);
        route[12]=new Route(villes[7],villes[11]);
        route[13]=new Route(villes[8],villes[11]);
        route[14]=new Route(villes[10],villes[11]);
        route[15]=new Route(villes[11],villes[12]);
        route[16]=new Route(villes[10],villes[14]);
        route[17]=new Route(villes[9],villes[10]);
        route[18]=new Route(villes[12],villes[13]);
        route[19]=new Route(villes[14],villes[13]);
        route[20]=new Route(villes[14],villes[16]);
        route[21]=new Route(villes[13],villes[16]);
        route[22]=new Route(villes[14],villes[15]);
        route[23]=new Route(villes[15],villes[16]);
        route[24]=new Route(villes[11],villes[13]);
        route[25]=new Route(villes[0],villes[4]);


    }
    vector<Route*> Civilisation:: getroute()
    {return route;}
    vector<ville*>Civilisation::getville(){return villes;}
    vector<ant*>Civilisation:: getant(){return fourmis;}

    void Civilisation ::routage (ant* four )//on est arrive a destination et on cherche a partir dans une meilleur ville.

    {   //ville petaouchnok(444,4);

        vector<int> listemp= four->destination->routelie;



        bool beenmodified;
        Route *routechoisi;
        ville* newdesti;
        ville* newdepart;
        ville* premvroute;
        ville* secvroute;
        ville *destfour;
        float Max=0;
        destfour= four->destination;
        cout<<"cette fourmi va a "<<endl;
        destfour->display();
       beenmodified=false;

  cout<<"quelque chose existe "<<listemp.size()<<endl;
      for( int i=0;i<listemp.size();i++)
      {
          int f=listemp[i];
            Route * temp=route[f];
          //cout<<temp->getpre()->getposition()[0]<<endl;
             premvroute =temp->getpre();
             secvroute=temp->getsec();
             four->depart->display();
             premvroute->display();
             secvroute->display();


            if( conditiondegalite(secvroute,destfour) &&  Max<=four->getTendance(temp)  &&  four->pasvisite(premvroute) /* !(conditiondegalite(premvroute,four->depart))*/ )

            {   cout<<"cgfgfg"<<endl;

                Max=four->getTendance(temp);
                routechoisi=temp;
                newdesti=premvroute;
                newdepart=secvroute;
                cout<<"une modification a eu lieu"<<endl;
                newdesti->display();
                beenmodified=true;

           }

         if(conditiondegalite(premvroute,destfour) &&  Max<=four->getTendance(temp)    &&  four->pasvisite(secvroute) /*!(conditiondegalite(secvroute,four->depart))*/ )
           {
                 cout<<"cgfgfg2"<<endl;
                 Max=four->getTendance(temp);
                 routechoisi=temp;
                  newdesti=secvroute;
                  newdepart=premvroute;
                   beenmodified=true;
                  cout<<"une modificationa a eu lieu"<<endl;
                  newdesti->display();
            }
      }

  if(beenmodified==true)
      {
           if(!four->pasvisite(routechoisi->getpre())) four->nb_foisrepe++;

            if(conditiondegalite( destfour,src_nourriture))// revoir cette condion a quelle moment depose la nourriture quand on se dirige ou quand on en repart vu quon fait un virage
              {
                four->distanceaparcourir=0;
                four->longueur_empreinte=1;
                four->prendre_nourriture();//methode change la valeur de la variable booleenne
                four->cheminprec2=four->villedejavisite;
                four->villedejavisite={src_nourriture};
                 };


            if(conditiondegalite(destfour,nid))
                  {
                   if(four->porte_nourriture)
                     {
                       four->distanceaparcourir=0;
                       four->longueur_empreinte=1;
                       four->quantite_nourriture++;
                       four->cheminprec=four->villedejavisite;
                       four->longueur_empreinte2=four->longueur_empreinte;

                      // cout<<"a deposer de la nourriture en plus il arrive au nid et il dit pas a quelqu'un "<<endl;}
                     //  four->cheminprec.insert(four->cheminprec.end(),four->villedejavisite.begin(),four->villedejavisite.end());

                       four->villedejavisite={nid};
                       four->porte_nourriture=false;//il depose logique
                         }

                   } ;
        if(!conditiondegalite( destfour,src_nourriture) && !conditiondegalite( destfour,nid))
              {

                   four->distanceaparcourir+=routechoisi->getlongueur();
                   four->villedejavisite.push_back(four->destination);
                    }//la ville va changer


            //four->distanceaparcourir+=routechoisi->getlongueur();
            four->deposer_pheromone(routechoisi);

            four->destination=newdesti;
            four->depart=newdepart;
            cout<<"vers la nouvelle destination"<<endl;
            newdesti->display();

           }
  if(beenmodified==false)
  { err++;cout<<"la ville qui ne trouve pas de proprio";
      four->destination=nid;
      four->depart=nid;
      four->villedejavisite={};
     // four->cheminprec={};
      four->longueur_empreinte=0;
      four->distanceaparcourir=-1;
      four->porte_nourriture=false;
  }
 cout<< four->distanceaparcourir<<"  "<<four->longueur_empreinte<<endl;

    }

   void Civilisation:: traitement()
    {

        this->initiville(5);
        this->initifourmis(50);
        this->initiroute();
         this->construirenet();
        for (int t=0;t<20; t++) {
              for(int ff=0; ff<50; ff++) this->faireuntour();
             this->rangelesantq();
              this->progeniture();
             this->construirenet();
            }// le pas

          //this->chemin();



     for (int d=0;d<route.size(); d++) cout<<"la route "<<d<<"a un niveau de phero"<<route[d]->getphero()<<endl;

     //this->chemin();
     cout<<this->err;

    }
    void Civilisation:: chemin(){      // affiche les villes visite par chaque fourmis
        for( int i=0 ; i<this->fourmis.size();i++)
            {   ant* four=fourmis[i];
            vector<ville*>  temp;
            temp=four->cheminprec;
            cout<<"les villes visite par la fourmis "<<i<<"sont"<<temp.size()<<endl;
            for(int tt=0; tt<temp.size();tt++) temp[tt]->display();
            cout<<four->quantite_nourriture<<"distance parcurur pendant ce tour est "<<four->longueur_empreinte2<<endl;
            }
        for( int i=0 ; i<this->fourmis.size();i++)
            {   ant* four=fourmis[i];
            vector<ville*>  temp;
            temp=four->cheminprec2;
            cout<<"les villes visite par la fourmis  "<<i<<"a l'alller sont"<<temp.size()<<endl;
            for(int tt=0; tt<temp.size();tt++) temp[tt]->display();
            //cout<<four->quantite_nourriture<<endl;
            }



    }
 void Civilisation :: rangelesantq()

 {
   ant trans ;
   float max=0;
   /*for(int y=0;y<fourmis.size();y++)
      {
                      fourmis[y]->destination->display();
              }*/
        for(int i=0; i<fourmis.size();i++)
        {
            max=fourmis[i]->quantite_nourriture;

           for(int j=i;j<fourmis.size();j++)
              {   if(max<=fourmis[j]->quantite_nourriture)
                    {   max=fourmis[j]->quantite_nourriture;
                        trans= fourmis[i];
                        * (fourmis[i])=fourmis[j];
                       *fourmis[j]=trans;
                        cout<<"le depart est "<<endl;
                        fourmis[j]->depart-> display();
                    }
             }
        }
       this->chemin();

//         for(int y=0;y<fourmis.size();y++)//initialisation des quantite apres un tour
//         {
//               // fourmis[y]->destination->display();
//             fourmis[y]->quantite_nourriture=0;
//                }
    }
    void Civilisation:: progeniture()//a appliquer a un tableau de fourmis range
    {
     int ind= fourmis.size()-1;
        cout<<"debut de la progeniture"<<endl;

        fourmis[fourmis.size()-1] = new ant  (*fourmis[0],*fourmis[1]);

        cout<<"le fiston est tel que "<<fourmis[ind]->alfa<<fourmis[fourmis.size()-1]-> beta<<fourmis[fourmis.size()-1]-> gamma<<endl;
        fourmis[fourmis.size()-1]->destination->display();
        cout<<fourmis[fourmis.size()-1]->distanceaparcourir<<fourmis[fourmis.size()-1]->longueur_empreinte<<endl;

        /*ant * c;
              c=&b;
       fourmis[fourmis.size()-1]=c;*/

    }

 void Civilisation:: construirenet(){

   for(int i=0; i<villes.size();i++)
     {   villes[i]->routelie={};
       for(int j=0; j<route.size();j++)
        {  if(conditiondegalite(route[j]->getpre(),villes[i]) || conditiondegalite(route[j]->getsec(),villes[i]))
             {
               villes[i]->routelie.push_back(j);
             }

         }
       }
   for(int k=0;k<villes.size();k++){cout<<"on est a la ville"<<k<<endl; for(int z=0;z<villes[k]->routelie.size(); z++) cout<< villes[k]->routelie[z]<<endl;}
 }
