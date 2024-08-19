#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

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

void merge(Edge* edges, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Edge* L = new Edge[n1];
    Edge* R = new Edge[n2];

    for (int i = 0; i < n1; i++)
        L[i] = edges[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = edges[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].distance <= R[j].distance)
        {
            edges[k] = L[i];
            i++;
        }
        else
        {
            edges[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        edges[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        edges[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Edge* edges, int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(edges, left, mid);
    mergeSort(edges, mid + 1, right);
    merge(edges, left, mid, right);
}

int find(int* parent, int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSets(int* parent, int* rank, int x, int y)
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

void kruskalMST(Edge* edges, int numEdges, int numCities)
{
    Edge* mst = new Edge[numCities - 1];
    int* parent = new int[numCities];
    int* rank = new int[numCities]();

    for (int i = 0; i < numCities; i++)
    {
        parent[i] = i;
    }

    mergeSort(edges, 0, numEdges - 1);

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

    if (e == numCities - 1)
    {
        for (int i = 0; i < e; i++)
        {
            //cout << "Miasto " << mst[i].city1 << " - Miasto " << mst[i].city2 << " : " << mst[i].distance << endl;
        }
    }
    else
    {
        //cout << "MST is empty, no edges added." << endl;
    }

    delete[] mst;
    delete[] parent;
    delete[] rank;
}

int calculateDistance(const City& city1, const City& city2)
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
    posX = stod(line.substr(pos1 + 1, pos2 - pos1 - 1));
    posY = stod(line.substr(pos2 + 1));
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

    // Count the number of lines in the file
    int numCities = countLines(filename);
    //cout << "Number of cities: " << numCities << endl;

    // Open the file again to read the data
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Cannot open file Miasta5.txt" << endl;
        return 1;
    }

    City* cities = new City[numCities];
    string line;

    for (int i = 0; i < numCities; ++i)
    {
        if (!getline(inFile, line))
        {
            cerr << "Error reading line number " << i + 1 << endl;
            break;
        }

        string name;
        double posX, posY;
        parseCityLine(line, name, posX, posY);
        cities[i] = City(name, posX, posY);
        //cout << "Read city: " << name << " at (" << posX << ", " << posY << ")" << endl;
    }

    inFile.close();

    // Create edges
    int numEdges = numCities * (numCities - 1) / 2;
    Edge* edges = new Edge[numEdges];
    int edgeCount = 0;
    for (int i = 0; i < numCities; i++)
    {
        for (int j = i + 1; j < numCities; j++)
        {
            int distance = calculateDistance(cities[i], cities[j]);
            edges[edgeCount++] = Edge(i, j, distance);
        }
    }

    //cout << "Number of edges created: " << edgeCount << endl;

    // Run Kruskal's algorithm
    //cout << "Running Kruskal's algorithm..." << endl;
    kruskalMST(edges, edgeCount, numCities);

    delete[] cities;
    delete[] edges;

    return 0;
}
