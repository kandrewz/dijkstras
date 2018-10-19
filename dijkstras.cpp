#include <iostream>
#include <fstream>
using namespace std ;
int pastures, fav, path ;
int favs[502] ;
int paths[502][502] ;
int dist[502] ;
int totdist[502] ;
bool visited[502] ;
int main(int argc, const char * argv[])
{
    //use dijkstras for this problem
    ifstream fin ("bestspot.in.txt") ;
    ofstream fout ("bestspot.out") ;
    fin >> pastures >> fav >> path ;
    for (int i = 0; i < fav ; i++)
    {
        fin >> favs[i] ;
    }
    int start, end, time ;
    for (int i = 0 ; i < path; i++)
    {
        fin >> start >> end >> time ;
        paths[start][end] = time ;
        paths[end][start] = time ;
    }
    for (int k = 1; k < pastures + 1; k++)
    {
        for (int i = 1; i < pastures  +1; i++)
        {
            dist[i] = 999999 ;
            visited[i] = false ;
        }
        dist[k] = 0 ;
        for(int i = 1; i < pastures + 1; i++)
        {
            int u = -1;
            for(int j = 1; j < pastures + 1; j++)
            {
                if (visited[j]) continue;
                if (u == -1 || dist[j] < dist[u])
                {
                    u = j;
                }
            }
            visited[u] = true;
            for(int j = 1; j < pastures  +1; j++)
            {
                if (paths[u][j] != 0)
                {
                    int dis = dist[u] + paths[u][j];
                    if (dis < dist[j])
                    {
                        dist[j] = dis;
                    }
                    
                }
            }
        }
        for (int j = 0; j < fav; j++)
        {
            totdist[k] = totdist[k] + dist[favs[j]] ;
        }
        
    }
    int best = 9999999;
    int bestnum = 0 ;
    for (int i = 1; i < pastures + 1; i++)
    {
        if (totdist[i] < best )
        {
            best = totdist[i] ;
            bestnum = i ;
        }
    }
    cout << bestnum << endl ;
    
}
