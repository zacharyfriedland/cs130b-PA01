#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


class Box{
    public:
        vector<Box*> children;
        int marbleCount; // numMarbles
        int marbleAmount;// marbleDiff
        bool parent;
};

int findMoves(Box* n)
{
    if (n->children.size() == 0)
    {
        n->marbleAmount = n->marbleCount - 1;
        
        return abs(n->marbleAmount);
    }
    
    int count = 0;

    
    for (int i = 0; i < n->children.size(); i++){
        count += findMoves(n->children[i]);
        n->marbleAmount = n->marbleAmount + n->children[i]->marbleAmount; 
    }
    
    n->marbleAmount = n->marbleAmount + n->marbleCount - 1;
    count += abs(n->marbleAmount);
    
    return count;
}

int main()
{
    int n;
    cin >> n;
    while(n != 0){
        vector<Box> nodes(n);        
        for (int i = 0; i < n; i++){
            int vertex;
            int marbleAmount;
            int childrenNum;
            cin >> vertex >> marbleAmount >> childrenNum;
            nodes[vertex-1].marbleCount = marbleAmount;



            for (int d = 0; d < childrenNum; d++){
                int dPos;
                cin >> dPos;
                dPos--;
                nodes[vertex-1].children.push_back(&nodes[dPos]);
                nodes[dPos].parent = true;
            }

        }
        int x = 0;
        while(x < n){
            if (!nodes[x].parent){
                cout << findMoves(&nodes[x]) << endl;
                x++;
                break;
            }
            else{
                x++;
            }
        }
        cin >> n;
    }
}
