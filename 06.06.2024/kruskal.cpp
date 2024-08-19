#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Edge
{
public:
    int city1, city2, distance;
    Edge() : city1(0), city2(0), distance(0) {}
    Edge(int city1, int city2, int distance) : city1(city1), city2(city2), distance(distance) {}
};

class City
{
public:
    string name;
    double posX, posY;
    City() : name(""), posX(0), posY(0) {}
    City(string name, double posX, double posY) : name(name), posX(posX), posY(posY) {}
};

int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y)
{
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rank[rootX] < rank[rootY])
    {
        parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY])
    {
        parent[rootY] = rootX;
    }
    else
    {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskalMST(Edge edges[], int numEdges, int numCities)
{
    Edge* mst = new Edge[numCities - 1];
    int* parent = new int[numCities];
    int* rank = new int[numCities];

    for (int i = 0; i < numCities; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    //cout << "Sorting edges..." << endl;
    sort(edges, edges + numEdges, [](Edge a, Edge b)
    {
        return a.distance < b.distance;
    });
    //cout << "Edges sorted." << endl;

    int e = 0;
    int i = 0;

    while (e < numCities - 1 && i < numEdges)
    {
        Edge nextEdge = edges[i++];

        int x = find(parent, nextEdge.city1);
        int y = find(parent, nextEdge.city2);

        if (x != y)
        {
            mst[e++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    //cout << "Krawêdzie wchodz¹ce w sk³ad MST:" << endl;
    if (e == 0)
    {
        //cout << "MST jest puste, ¿adna krawêdŸ nie zosta³a dodana." << endl;
    }
    else
    {
        for (i = 0; i < e; i++)
        {
            //cout << "Miasto " << mst[i].city1 << " - Miasto " << mst[i].city2 << " : " << mst[i].distance << endl;
        }
    }

    delete[] mst;
    delete[] parent;
    delete[] rank;
}

int calculateDistance(City city1, City city2)
{
    double dx = city1.posX - city2.posX;
    double dy = city1.posY - city2.posY;
    int distance = static_cast<int>(sqrt(dx * dx + dy * dy) * 1000);
    return distance;
}

void parseCityLine(const string& line, string& name, double& posX, double& posY)
{
    size_t pos1 = line.find('#');
    size_t pos2 = line.find('#', pos1 + 1);

    name = line.substr(0, pos1);
    posX = atof(line.substr(pos1 + 1, pos2 - pos1 - 1).c_str());
    posY = atof(line.substr(pos2 + 1).c_str());
}

int countLines(const string& filename)
{
    ifstream inFile(filename);
    int lines = 0;
    string line;
    while (getline(inFile, line))
    {
        lines++;
    }
    return lines;
}

int main()
{
    const string filename = "Miasta5.txt";

    // Policz liczbê linii w pliku
    int numCities = countLines(filename);
    //cout << " Numer miasta: " << numCities << endl;

    // Otwórz plik ponownie, aby odczytaæ dane
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Nie mo¿na otworzyæ pliku Miasta5.txt" << endl;
        return 1;
    }

    City* cities = new City[numCities];
    string line;

    for (int i = 0; i < numCities; ++i)
    {
        if (!getline(inFile, line))
        {
            cerr << "B³¹d podczas odczytywania linii nr " << i + 1 << endl;
            break;
        }

        string name;
        double posX, posY;
        parseCityLine(line, name, posX, posY);
        cities[i] = City(name, posX, posY);
        //cout << "Read city: " << name << " at (" << posX << ", " << posY << ")" << endl;
    }

    inFile.close();

    // Tworzenie krawêdzi
    int numEdges = (numCities * (numCities - 1)) / 2;
    Edge* edges = new Edge[numEdges];
    int edgeIndex = 0;

    for (int i = 0; i < numCities; i++)
    {
        for (int j = i + 1; j < numCities; j++)
        {
            int distance = calculateDistance(cities[i], cities[j]);
            edges[edgeIndex++] = Edge(i, j, distance);
        }
    }

    //cout << "Ilosc stworzonych krawedzi: " << edgeIndex << endl;

    // Uruchomienie algorytmu Kruskala
    //cout << "Alogrytm Kruskala..." << endl;
    kruskalMST(edges, numEdges, numCities);

    delete[] edges;
    delete[] cities;
    return 0;
}
