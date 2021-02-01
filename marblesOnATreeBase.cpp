#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

struct node
{
    int numMarbles;
    int marbleDiff;
    
    vector<node*> descendents;
    
    bool hasParent;
};

int Solve(node* current)
{
    if (current->descendents.size() == 0)
    {
        current->marbleDiff = current->numMarbles - 1;
        
        return abs(current->marbleDiff);
    }
    
    int count = 0;

    
    for (int i = 0; i < current->descendents.size(); ++i)
    {
        count += Solve(current->descendents[i]);
        current->marbleDiff += current->descendents[i]->marbleDiff;
    }
    
    current->marbleDiff += current->numMarbles - 1;
    count += abs(current->marbleDiff);
    
    return count;
}

int main()
{
    int n;
    cin >> n;
    while(n != 0){
        vector<node> verticies(n);
        
        for (int i = 0; i < n; ++i)
        {
            int num, numMarbles, descendents;
            cin >> num >> numMarbles >> descendents;
            --num;
            verticies[num].numMarbles = numMarbles;
            
            for (int d = 0; d < descendents; ++d)
            {
                int dPos;
                cin >> dPos;
                --dPos;
                verticies[num].descendents.push_back(&verticies[dPos]);
                verticies[dPos].hasParent = true;
            }
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (!verticies[i].hasParent)
            {
                printf("%d\n", Solve(&verticies[i]));
                break;
            }
        }
        cin >> n;
    }
}
// #include <cstdio>
// #include <vector>
// #include <cmath>
// #include <iostream>
// #include <string>
// #include <sstream>

// using namespace std;

// struct node
// {
//     int numMarbles;
//     int marbleDiff;
    
//     vector<node*> descendents;
    
//     bool hasParent;
// };

// int Solve(node* current)
// {
//     if (current->descendents.size() == 0)
//     {
//         current->marbleDiff = current->numMarbles - 1;
        
//         return abs(current->marbleDiff);
//     }
    
//     int count = 0;

    
//     for (int i = 0; i < current->descendents.size(); ++i)
//     {
//         count += Solve(current->descendents[i]);
//         current->marbleDiff += current->descendents[i]->marbleDiff;
//     }
    
//     current->marbleDiff += current->numMarbles - 1;
//     count += abs(current->marbleDiff);
    
//     return count;
// }

// int main()
// {
//     string input = "9 1 2 3 2 3 4 2 1 0 3 0 2 5 6 4 1 3 7 8 9 5 3 0 6 0 0 7 0 0 8 2 0 9 0 0 0";
//     int n;
//     stringstream(input) >> n;
//     for(int j = 0; j < n; j++)
//     {
//         vector<node> verticies(n);
        
//         for (int i = 0; i < n; ++i)
//         {
//             int num, numMarbles, descendents;
//             stringstream(input) >> num >> numMarbles >> descendents;
//             --num;
            
//             verticies[num].numMarbles = numMarbles;
            
//             for (int d = 0; d < descendents; ++d)
//             {
//                 int dPos;
//                 stringstream(input) >> dPos;
//                 --dPos;
//                 verticies[num].descendents.push_back(&verticies[dPos]);
//                 verticies[dPos].hasParent = true;
//             }
//         }
        
//         for (int i = 0; i < n; ++i)
//         {
//             if (!verticies[i].hasParent)
//             {
//                 printf("%d\n", Solve(&verticies[i]));
//                 break;
//             }
//         }
        
//     }
// }