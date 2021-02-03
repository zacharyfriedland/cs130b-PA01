#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkEnemies(vector<vector<int>>& e, vector<int> group){
    for(int i = 0; i < group.size(); i++){
        if(group.)
    }
}

int main(){
    int soldiers; // n 
    int enemyPairs; // m (m lines)
    cin >> soldiers >> enemyPairs;
    vector<int> groupOne;
    vector<int> groupTwo;
    for(int i = 1; i <= soldiers; i++){
        if(i <= soldiers/2){
            groupOne.push_back(i);
        }
        else{
            groupTwo.push_back(i);
        }
    }
    vector<vector<int>> enemies;


    for(int j = 0; j < enemyPairs; j++){  
        int pairOne, pairTwo;
        cin >> pairOne >> pairTwo;
        enemies[pairOne].push_back(pairTwo);
    }

    for(int k = 0; k < groupOne.size())

    return 0;
}