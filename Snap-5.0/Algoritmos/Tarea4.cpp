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
#include <chrono>
#include "Snap.h"
#include "Tarea4.hpp"

using namespace std;
using namespace std::chrono;

typedef PNGraph SnapGraph;

void GraphML(SnapGraph g);
void GEXF(SnapGraph g);
void GDF(SnapGraph g);
void JSON(SnapGraph g);

int main()
{
    SnapGraph dg = TSnap::LoadEdgeList<SnapGraph>("twitter_combined.txt", 0, 1);

    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    GraphML(dg);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "GraphML: " << duration << std::endl;
    t1 = high_resolution_clock::now();
    GEXF(dg);
    t2 = high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "GEXF: " << duration << std::endl;

    t1 = high_resolution_clock::now();
    GDF(dg);
    t2 = high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "GDF: " << duration << std::endl;

    t1 = high_resolution_clock::now();
    JSON(dg);
    t2 = high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "JSON: " << duration << std::endl;
    return 0;
}



//g++ -Wall -D__STDC_LIMIT_MACROS -O3 -DNDEBUG -o Tarea4 Tarea4.cpp ../snap-core/Snap.o -I../snap-core -I../glib-core -fopenmp