/*
 * APSP.cpp
 *
 *  Created on: 07.07.2015
 *      Author: Arie Slobbe
 */

#include <networkit/auxiliary/Log.hpp>
#include <networkit/distance/APSP.hpp>
#include <networkit/distance/BFS.hpp>
#include <networkit/distance/Dijkstra.hpp>

namespace NetworKit {

APSP::APSP(const Graph &G) : Algorithm(), G(G) {}

void APSP::run() {
    std::vector<edgeweight> distanceVector(G.upperNodeIdBound(), 0.0);
    distances.resize(G.upperNodeIdBound(), distanceVector);
    if (G.isWeighted()) {
        G.parallelForNodes([&](node u) {
            Dijkstra dijk(G, u);
            dijk.run();
            distances[u] = dijk.getDistances();
        });
    } else {
        G.parallelForNodes([&](node u) {
            BFS bfs(G, u);
            bfs.run();
            distances[u] = bfs.getDistances();
        });
    }
    hasRun = true;
}

std::string APSP::toString() const {
    return "All-Pairs Shortest Path Algorithm";
}

} /* namespace NetworKit */
