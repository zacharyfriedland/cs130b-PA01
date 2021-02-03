#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


class Node{
    public:
        int vertexNum; // vertex number
        int marbleCount; // # of marbles vertex has
        vector<int> children; // holds children of each Node
};

pair<int, int> findNecessaryMarbles(vector<Node>& n , int rootVertex){
    int parentIndex = rootVertex-1;
    int sum = 0;
    int def = 0;
    pair<int, int> p;

    for (int i = 0; i < n[parentIndex].children.size(); i++){
        p = findNecessaryMarbles(n, n[parentIndex].children[i]);
        sum += p.first;
        def += p.second;
    }
    // if the node has no children, return marbleCount-1    
    if(n[parentIndex].children.size() == 0){
        return make_pair(abs(n[parentIndex].marbleCount-1), n[parentIndex].marbleCount-1);
    }
    else{
        def = def + n[parentIndex].marbleCount - 1;
        sum = sum + abs(def);
    }

    return make_pair(sum, def);
}
    

int main(){
    int n;
    cin >> n;
    while(n != 0){
        vector<Node> vec(n);
        vector<int> findRoot;
        for(int z = 1; z <= n; z++){
            findRoot.push_back(z);
        }
        for(int i = 0; i < n; i++){
            int vertex;
            int numMarbles;
            int childrenNum;
            cin >> vertex >> numMarbles >> childrenNum;
            vec[i].vertexNum = vertex;
            vec[i].marbleCount = numMarbles;

            for (int child = 0; child < childrenNum; child++){
                int childNum;
                cin >> childNum;
                vec[i].children.push_back(childNum);
                findRoot.erase(remove(findRoot.begin(), findRoot.end(), childNum), findRoot.end());
            }
        }
        int rootVertex = findRoot[0];
        cout << findNecessaryMarbles(vec, rootVertex).first << endl;
        
        vec.clear();
        findRoot.clear();
        cin >> n;
    }
}
