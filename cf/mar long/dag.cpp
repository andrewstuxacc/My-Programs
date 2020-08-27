#include<bits/stdc++.h> 
using namespace std; 

void Graph::alltopologicalSortUtil(vector<int>& res,bool visited[])

{

    // To indicate whether all topological are found

    // or not

    bool flag = false; 

 

    for (int i = 0; i < V; i++)

    {

        //  If indegree is 0 and not yet visited then

        //  only choose that vertex

        if (indegree[i] == 0 && !visited[i])

        {

            //  reducing indegree of adjacent vertices

            list<int>:: iterator j;

            for (j = adj[i].begin(); j != adj[i].end(); j++)

                indegree[*j]--;

 

            //  including in result

            res.push_back(i);

            visited[i] = true;

            alltopologicalSortUtil(res, visited);

 

            // resetting visited, res and indegree for

            // backtracking

            visited[i] = false;

            res.erase(res.end() - 1);

            for (j = adj[i].begin(); j != adj[i].end(); j++)

                indegree[*j]++;

 

            flag = true;

        }

    }

 

    //  We reach here if all vertices are visited.

    //  So we print the solution here

    if (!flag)

    {

        for (int i = 0; i < res.size(); i++)

            cout << res[i] << " ";

        cout << endl;

    }

}

 

//  The function does all Topological Sort.

//  It uses recursive alltopologicalSortUtil()

void Graph::alltopologicalSort()

{

    // Mark all the vertices as not visited

    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)

        visited[i] = false;

 

    vector<int> res;

    alltopologicalSortUtil(res, visited);

}
