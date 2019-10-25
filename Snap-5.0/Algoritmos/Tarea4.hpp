#include <iostream>
#include <fstream>
#include <chrono>
#include "Snap.h"

using namespace std;
using namespace std::chrono;

typedef PNGraph SnapGraph;

void GraphML(SnapGraph g);
void GEXF(SnapGraph g);
void GDF(SnapGraph g);
void JSON(SnapGraph g);

void GraphML(SnapGraph g)
{
    std::ofstream file("Wiki-Vote.graphml");
    if (file.is_open())
    {
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        file << "<graphml xmlns=\"http://graphml.graphdrawing.org/xmlns\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://graphml.graphdrawing.org/xmlns http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\">\n";
        file << "<graph id=\"G\" edgedefault=\"directed\">\n";

        for (SnapGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
            file << "<node id=\"" << NI.GetId() << "\"/>\n";

        int i = 1;
        for (SnapGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++, ++i)
            file << "<edge id=\"e" << i << "\" source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\"/>\n";

        file << "</graph>\n";
        file << "</graphml>\n";
        file.close();
    }
}

void GEXF(SnapGraph g)
{
    std::ofstream file("Wiki-Vote.gexf");
    if (file.is_open())
    {
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        file << "<gexf xmlns=\"http://www.gexf.net/1.2draft\" version=\"1.2\">\n";
        file << "<graph mode=\"static\" defaultedgetype=\"directed\">\n";

        file << "<nodes>\n";
        for (SnapGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
            file << "<node id=\"" << NI.GetId() << "\" />\n";
        file << "</nodes>\n";

        file << "<edges>\n";
        int i = 1;
        for (SnapGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++, ++i)
            file << "<edge id=\"" << i << "\" source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\" />\n";
        file << "</edges>\n";

        file << "</graph>\n";
        file << "</gexf>\n";
        file.close();
    }
}

void GDF(SnapGraph g)
{
    std::ofstream file("Wiki-Vote.gdf");
    if (file.is_open())
    {
        file << "nodedef>id VARCHAR\n";
        for (SnapGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
            file << NI.GetId() << "\n";

        file << "edgedef>source VARCHAR, destination VARCHAR\n";
        for (SnapGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++)
            file << EI.GetSrcNId() << ", " << EI.GetDstNId() << "\n";

        file.close();
    }
}

void JSON(SnapGraph g)
{
    std::ofstream file("Wiki-Vote.json");
    if (file.is_open())
    {
        file << "{ \"graph\": {\n";
        file << "\"nodes\": [\n";
        for (SnapGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI();)
        {
            file << "{ \"id\": \"" << NI.GetId() << "\" }";
            if (NI++ == g->EndNI())
                file << " ],\n";
            else
                file << ",\n";
        }

        file << "\"edges\": [\n";
        for (SnapGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI();)
        {
            file << "{ \"source\": \"" << EI.GetSrcNId() << "\", \"target\": \"" << EI.GetDstNId() << "\" }";
            if (EI++ == g->EndEI())
                file << " ]\n";
            else
                file << ",\n";
        }
        file << "} }";

        file.close();
    }
}