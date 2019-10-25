/*
 *  Tarea 4
 *
 *  Daniel Roa 
 *  A01021960
 *  25/octubre/2019
 * 
 */ 
#include <iostream>
#include <fstream>
#include <ctime>
#include "Snap.h"
#include "Tarea4.hpp"
//#include <chrono>

using namespace std;
using namespace std::chrono;

typedef PNGraph SnapGraph;

void GraphML(SnapGraph g);
void GEXF(SnapGraph g);
void GDF(SnapGraph g);
void JSON(SnapGraph g);

int main()
{
    SnapGraph dg = TSnap::LoadEdgeList<SnapGraph>("Wiki-Vote.txt", 0, 1);

    //Comienza GraphML

    auto start = high_resolution_clock::now();
    
    GraphML(dg);
    
    auto stop = high_resolution_clock::now();
    auto durationSegGML = duration_cast<seconds>(stop - start);
    auto durationMilliGML = duration_cast<milliseconds>(stop - start);

    cout << "A GraphML le tomó " << durationSegGML.count() << " segundos\n";
    cout << "A GraphML le tomó " << durationMilliGML.count() << " milisegundos\n";

    cout << "\n";

    //Comienza GEXF

    auto start1 = high_resolution_clock::now();

    GEXF(dg);

    auto stop1 = high_resolution_clock::now();
    auto durationSegGEXF = duration_cast<seconds>(stop1 - start1);
    auto durationMilliGEXF = duration_cast<milliseconds>(stop1 - start1);

    cout << "A GEXF le tomó " << durationSegGEXF.count() << " segundos\n";
    cout << "A GEXF le tomó " << durationMilliGEXF.count() << " milisegundos\n";

    cout << "\n";

    //Comienza GDF

    auto start2 = high_resolution_clock::now();

    GDF(dg);

    auto stop2 = high_resolution_clock::now();
    auto durationSegGDF = duration_cast<seconds>(stop2 - start2);
    auto durationMilliGDF = duration_cast<milliseconds>(stop2 - start2);

    cout << "A GDF le tomó " << durationSegGDF.count() << " segundos\n";
    cout << "A GDF le tomó " << durationMilliGDF.count() << " milisegundos\n";

    cout << "\n";

    //Comienza JSON

    auto start3 = high_resolution_clock::now();

    JSON(dg);

    auto stop3 = high_resolution_clock::now();
    auto durationSegJSON = duration_cast<seconds>(stop3 - start3);
    auto durationMilliJSON = duration_cast<milliseconds>(stop3 - start3);

    cout << "A JSON le tomó " << durationSegJSON.count() << " segundos\n";
    cout << "A JSON le tomó " << durationMilliJSON.count() << " milisegundos\n";

    return 0;
}



//g++ -Wall -D__STDC_LIMIT_MACROS -O3 -DNDEBUG -o Tarea4 Tarea4.cpp ../snap-core/Snap.o -I../snap-core -I../glib-core -fopenmp