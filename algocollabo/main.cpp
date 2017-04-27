//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include<iostream>
#include<ant.h>
#include<random>
int main(int argc, char *argv[])
{
   /* QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();*/
   /* ville abengourou(5,4);
    ville constantinople(4,5);
    ville* c= &abengourou;
    ville*p=&constantinople;
    ant jeanpierre;
    ant jeanclaude;
//    p=c;
//    cout<<"ici";
//    p->display();
    ant* four=&jeanpierre;
    ant* four1=&jeanclaude;
    four1->destination=c;
    four->destination->display();
    ant cloclo(jeanclaude,jeanpierre);
    cout<<cloclo.alfa<<" "<<cloclo.beta<<" "<<cloclo.gamma<<endl;
    cout<<four->alfa<<" "<<four->beta<<" "<<four->gamma<<endl;
    cout<<four1->alfa<<" "<<four1->beta<<" "<<four1->gamma<<endl;
    four1->distanceaparcourir=20;
    four=four1;
    cout<<four->distanceaparcourir<<endl;

   /* jeanpierre.marcher();
    Route cc (c,p);
    Route* f=&cc;
   four->deposer_pheromone(f);
    //cout<<randomUniform(1,2)<<endl;
   //************************/

Civilisation dumoyenage;
 //dumoyenage.initifourmis(5);
  //dumoyenage.faireuntour();
  //dumoyenage.faireuntour();
  //dumoyenage.initiville(5);
  //dumoyenage.initiroute();
  //**************************************/
   //ant* magellan =dumoyenage.fourmis[0];

 dumoyenage.traitement();



    return 0;
}
