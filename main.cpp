#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    std::vector<int> neighbours;
    int value;
    int incoming;
    bool visited;
};

bool comp(Node a, Node b) {
    return a.value < b.value;
}



void topological_sort(std::vector<Node> &graph, std::vector<Node> &sorted_graph, std::queue<int> queue) {
    while (!queue.empty()) {
            int tmp = queue.front();
            queue.pop();
            for (int i = 0; i < graph[tmp].neighbours.size(); i++) {
                graph[graph[tmp].neighbours[i]].incoming--;
                if (!graph[graph[tmp].neighbours[i]].visited && graph[graph[tmp].neighbours[i]].incoming == 0) {
                    queue.push(graph[tmp].neighbours[i]);
                    graph[graph[tmp].neighbours[i]].visited = true;
                }
                graph[graph[tmp].neighbours[i]].value = max(graph[graph[tmp].neighbours[i]].value, graph[tmp].value);
            }
            sorted_graph.push_back(graph[tmp]);
}
}

void read_graph(std::vector<Node> &graph, int m) {
int tmp1, tmp2;
 for (int i = 0; i < m; i++) {
            std::cin >> tmp1 >> tmp2;
            graph[tmp2-1].neighbours.push_back(tmp1-1);
            graph[tmp1-1].incoming++;
        }
}

int main()
{
 std::ios_base::sync_with_stdio(0);
      std::cin.tie(0);
    int n, m, k;
    std::cin >> n >> m >> k;
        std::vector<Node> graph(n);
        for (int i = 0; i < n; i++) {
            std::cin >> graph[i].value;
            graph[i].visited = false;
        }
        read_graph(graph, m);
        std::queue<int> queue;
        for (int i = 0; i < n; i++) {
            if (graph[i].incoming == 0) {
                queue.push(i);
            }
        }
        std::vector<Node> sorted_graph;
        topological_sort(graph, sorted_graph, queue);
            if (k == 0) {
                std::cout << 0 << '\n';
            }
            else {
                std::nth_element(sorted_graph.begin(), sorted_graph.begin()+(k-1), sorted_graph.end(), comp);
                std::cout << sorted_graph[k-1].value << '\n';
            }
}




