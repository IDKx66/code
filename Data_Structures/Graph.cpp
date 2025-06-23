//图
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//邻接矩阵
class Graph
{
public:
    Graph(int n)
    {
        this->n = n;
        this->matrix.resize(n);
        for (int i = 0; i < n; i++)
        {
            this->matrix[i].resize(n);
        }
    }

    void addEdge(int x, int y)
    {
        this->matrix[x][y] = 1;
        this->matrix[y][x] = 1; //无向图


    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << this->matrix[i][j] << " ";
            }
            cout << endl;
        }


    }

private:

    int n;
    vector<vector<int>> matrix;


};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.print();
    return 0;
}