#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

struct Edge
{
    char u;
    char v;
};

void dfs_visit(char u, std::map<char, int> &vertices, std::map<int, std::vector<char>> &connected_components, Edge *edges, int edges_size, int connected_component_index)
{
    vertices[u] = 1;

    for (int i = 0; i < edges_size; i++)
    {
        if (edges[i].u == u && vertices[edges[i].v] == 0)
        {
            dfs_visit(edges[i].v, vertices, connected_components, edges, edges_size, connected_component_index);
        }
        else if (edges[i].v == u && vertices[edges[i].u] == 0)
        {
            dfs_visit(edges[i].u, vertices, connected_components, edges, edges_size, connected_component_index);
        }
    }

    vertices[u] = 2;
    connected_components[connected_component_index].push_back(u);
}

void initialize_vertices(std::map<char, int> &vertices, char final_vertice)
{
    for (char c = 'a'; c <= final_vertice; c++)
    {
        vertices[c] = 0;
    }
}

void initialize_edges(Edge *edges, int edges_size)
{
    for (int i = 0; i < edges_size; i++)
    {
        scanf(" %c %c", &edges[i].u, &edges[i].v);
    }
}

void show_connected_components(std::map<int, std::vector<char>> &connected_components)
{
    for (auto connected_component : connected_components)
    {
        std::sort(connected_component.second.begin(), connected_component.second.end());
        for (char vertice : connected_component.second)
        {
            printf("%c, ", vertice);
        }
        printf("\n");
    }

    printf("%ld connected components\n\n", connected_components.size());
}

void connected_components_for_entry(int test_cases)
{
    for (int i = 1; i <= test_cases; i++)
    {
        printf("Case #%d:\n", i);

        int vertices_size, edges_size;
        scanf("%d %d", &vertices_size, &edges_size);

        Edge *edges = new Edge[edges_size];
        std::map<char, int> vertices;
        int connected_component_index = 0;
        int final_vertice = 'a' + vertices_size - 1;
        std::map<int, std::vector<char>> connected_components;

        initialize_vertices(vertices, final_vertice);

        initialize_edges(edges, edges_size);

        for (char c = 'a'; c <= final_vertice; c++)
        {
            if (vertices[c] == 0)
            {
                connected_component_index++;
                dfs_visit(c, vertices, connected_components, edges, edges_size, connected_component_index);
            }
        }

        show_connected_components(connected_components);

        delete[] edges;
    }
}

int main()
{

    int test_cases;
    scanf("%d", &test_cases);

    connected_components_for_entry(test_cases);

    return 0;
}