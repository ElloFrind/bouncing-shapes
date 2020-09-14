#include "nav.h"
#include <cstdio>
#include <algorithm>
#include <queue>
#include <random>

using namespace std;

namespace nav_ {
    const int MAX_NB_VERTICES = 100000;

    int nb_vertices, nb_links;
    vector<int> A, B;
    vector<pair<int,int>> neighbors[MAX_NB_VERTICES];
    int prime_vertex;

    int nb_queries;
    int max_queries;
}

using namespace nav_;

int nav(int u) {
    if (u<0 || u>=nb_vertices) {
        printf("Error: invalid vertex: %d\n", u);
        exit(0);
    }

    nb_queries++;

    if (u==prime_vertex) {
        return -1;
    }

    vector<int> distances(nb_vertices);
    vector< pair<int,int> > prev(nb_vertices);
    fill(distances.begin(), distances.end(), -1);
    queue<int> exploring;
    exploring.push(u);
    distances[u] = 0;
    prev[u] = make_pair(u,-1);
    while (!exploring.empty() && distances[prime_vertex]==-1) {
        int n = exploring.front();
        exploring.pop();
        for (auto v : neighbors[n]) {
            int v_vertex = v.first;
            int v_edge = v.second;
            if (distances[v_vertex] != -1) continue;
            distances[v_vertex] = distances[n]+1;
            prev[v_vertex] = make_pair(n,v_edge);
            if (v_vertex == prime_vertex) break;
            exploring.push(v_vertex);
        }
    }

    if (distances[prime_vertex]==-1) {
        printf("Error: the graph is not connected.");
        exit(0);
    }

    int current_vertex = prime_vertex;
    vector<int> edgesUsed;
    while (current_vertex != u) {
        edgesUsed.push_back(prev[current_vertex].second);
        current_vertex = prev[current_vertex].first;
    }
    return edgesUsed[rand()%distances[prime_vertex]];
}

int main() {
    // Seed the random.
    srand(3);

    int _;

    int subtask;
    _ = scanf("%d %d %d", &subtask, &nb_vertices, &nb_links);
    for (int i=0; i<nb_links; i++) {
        int a,b;
        _ = scanf("%d %d", &a, &b);
        A.push_back(a);
        B.push_back(b);
        neighbors[a].push_back(make_pair(b,i));
        neighbors[b].push_back(make_pair(a,i));
    }

    init(subtask, nb_vertices, nb_links, A, B);

    int num_queries;
    _ = scanf("%d", &num_queries);

    for (int i=0; i<num_queries; i++) {
        _ = scanf("%d", &prime_vertex);
        printf("Searching for prime vertex %d...\n", prime_vertex);

        nb_queries = 0;
        int ans = findPrime();

        if (ans == prime_vertex) {
            printf("Success with %d queries.\n", nb_queries);
        } else {
            printf("Failure: your program returned %d instead of %d.\n", ans, prime_vertex);
        }
    }

    return 0;
}
