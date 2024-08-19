#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <ctime>
using namespace std;

const int MAX_CITIES = 2000; // Maksymalna liczba miast

struct Road
{
    int start; // Punkt początkowy drogi
    int end; // Punkt końcowy drogi
    float distance; // Długość drogi
    Road* next; // Wskaźnik na następną drogę w liście
};

struct City
{
    float x, y; // Pozycja miasta na płaszczyźnie
    string name; // Nazwa miasta
    int color; // Pole koloru dla algorytmu kolorowania
    int parent; // Pole rodzica dla algorytmu UNION-FIND

    City(string _name, float _x, float _y)
    {
        x = _x;
        y = _y;
        name = _name;
        color = -1; // Inicjalizacja koloru na -1 (nieprzypisany)
        parent = -1; // Inicjalizacja rodzica na -1
    }
};

// Struktura dynamicznej tablicy do przechowywania dróg
struct DynamicArray
{
    Road** data; // Tablica wskaźników na drogi
    int size; // Aktualny rozmiar tablicy
    int capacity; // Pojemność tablicy

    DynamicArray(int initial_capacity = 10)
    {
        size = 0;
        capacity = initial_capacity;
        data = new Road*[capacity];
    }

    void push_back(Road* value)
    {
        if (size == capacity)
        {
            capacity *= 2;
            Road** new_data = new Road*[capacity];
            for (int i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size++] = value;
    }

    Road* operator[](int index)
    {
        return data[index];
    }
};

// Struktura do reprezentowania zbiorów rozłącznych (UNION-FIND)
struct DisjointSet
{
    int* parent; // Tablica rodziców
    int size; // Rozmiar zbioru

    DisjointSet(int n)
    {
        size = n;
        parent = new int[n];
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    ~DisjointSet()
    {
        delete[] parent;
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        parent[find(u)] = find(v);
    }
};

City* Cities[MAX_CITIES]; // Tablica wskaźników na miasta
Road* Edges[(MAX_CITIES * (MAX_CITIES - 1)) / 2]; // Tablica wskaźników na drogi

void AddRoad(Road*& head, int _end, float _distance)
{
    Road* newRoad = new Road;
    newRoad->end = _end;
    newRoad->distance = _distance;
    newRoad->next = head;
    head = newRoad;
}

// Funkcja do obliczania odległości między dwoma miastami
float calculateDistance(City A, City B)
{
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2)) * 100;
}

// Funkcja do wczytywania danych o miastach z pliku
void LoadCities()
{
    ifstream inputFile("Miasta5.txt");
    if (!inputFile.is_open())
    {
        cerr << "Nie można otworzyć pliku Miasta5.txt" << endl;
        exit(1);
    }
    string line;
    int i = 0;
    while (getline(inputFile, line) && i < MAX_CITIES)
    {
        string name = line.substr(0, line.find('#'));
        line = line.substr(line.find('#') + 1);
        string strX = line.substr(0, line.find('#'));
        line = line.substr(line.find('#') + 1);
        string strY = line.substr(0, 100);
        Cities[i] = new City(name, stof(strX), stof(strY));
        i++;
    }
    inputFile.close();
}

// Funkcja do tworzenia krawędzi między miastami
void LoadEdges()
{
    int idx = 0;
    for (int i = 0; i < MAX_CITIES; i++)
    {
        for (int j = i + 1; j < MAX_CITIES; j++)
        {
            float dist = calculateDistance(*Cities[i], *Cities[j]);
            Road* newEdge = new Road;
            newEdge->start = i;
            newEdge->end = j;
            newEdge->distance = dist;
            Edges[idx] = newEdge;
            idx++;
        }
    }
}

// Funkcja do obliczania długości ścieżki
float calculatePathLength(int path[], int count)
{
    float length = 0;
    for (int i = 0; i < count - 1; i++)
        length += calculateDistance(*Cities[path[i]], *Cities[path[i + 1]]);
    length += calculateDistance(*Cities[path[0]], *Cities[path[count - 1]]);
    return length;
}

// Funkcja do wypisywania ścieżki
void PrintPath(int path[], int count)
{
    for (int i = 0; i < count; i++)
        cout << Cities[path[i]]->name << ", ";
}

// Funkcja do zamiany dwóch krawędzi
void swapRoads(Road*& a, Road*& b)
{
    Road* temp = a;
    a = b;
    b = temp;
}

// Funkcja do partycjonowania tablicy krawędzi (dla quicksorta)
int partition(Road* arr[], int low, int high)
{
    float pivot = arr[high]->distance;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j]->distance < pivot)
        {
            i++;
            swapRoads(arr[i], arr[j]);
        }
    }
    swapRoads(arr[i + 1], arr[high]);
    return (i + 1);
}

// Funkcja sortująca tablicę krawędzi za pomocą quicksorta
void quickSort(Road* arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Funkcja implementująca algorytm Kruskala z użyciem kolorowania
void KruskalUsingColors()
{
    clock_t start = clock();
    int edgeCount = (MAX_CITIES * (MAX_CITIES - 1)) / 2;
    quickSort(Edges, 0, edgeCount - 1);

    int colors[MAX_CITIES];
    for (int i = 0; i < MAX_CITIES; ++i)
    {
        colors[i] = i; // Inicjalizacja każdego wierzchołka unikalnym kolorem
    }

    DynamicArray MST;

    for (int i = 0; i < edgeCount; ++i)
    {
        int u = Edges[i]->start;
        int v = Edges[i]->end;

        if (colors[u] != colors[v])
        {
            int oldColor = colors[v];
            int newColor = colors[u];
            MST.push_back(Edges[i]);

            // Zmiana koloru wszystkich wierzchołków z kolorami oldColor na newColor
            for (int j = 0; j < MAX_CITIES; ++j)
            {
                if (colors[j] == oldColor)
                {
                    colors[j] = newColor;
                }
            }
        }
    }

    cout << "Minimalne drzewo rozpinajace [Kruskal, kolory]:" << endl;
    for (int i = 0; i < MST.size; ++i)
    {
        cout << "Z " << MST[i]->start << " do " << MST[i]->end << " o dlugosci " << MST[i]->distance << endl;
    }
    clock_t stop = clock();
    double duration = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas [Kruskala z kolorami]: " << duration << " sekund" << endl;
    cout << endl;
}

// Funkcja implementująca algorytm Kruskala z użyciem UNION-FIND
void KruskalUsingUnionFind()
{
    clock_t start = clock();
    int edgeCount = (MAX_CITIES * (MAX_CITIES - 1)) / 2;
    quickSort(Edges, 0, edgeCount - 1);

    DisjointSet ds(MAX_CITIES);

    DynamicArray MST;

    for (int i = 0; i < edgeCount; ++i)
    {
        int u = Edges[i]->start;
        int v = Edges[i]->end;

        if (ds.find(u) != ds.find(v))
        {
            ds.unionSets(u, v);
            MST.push_back(Edges[i]);
        }
    }

    cout << "Minimalne drzewo rozpinajace [Kruskal, UNION-FIND]:" << endl;
    for (int i = 0; i < MST.size; ++i)
    {
         cout << "Z " << MST[i]->start << " do " << MST[i]->end << " o dlugosci " << MST[i]->distance << endl;
    }
    clock_t stop = clock();
    double duration = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas [Kruskala z Union-Find]: " << duration << " sekund" << endl;
}

int main()
{
    LoadCities(); // Wczytanie danych o miastach
    LoadEdges(); // Wczytanie danych o krawędziach
    KruskalUsingUnionFind(); // Uruchomienie algorytmu Kruskala z użyciem UNION-FIND
    cout<<endl;
    KruskalUsingColors(); // Uruchomienie algorytmu Kruskala z użyciem kolorowania

    return 0;
}
