#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void switchGroups(int indexToBeMoved, vector<int>& from, vector<int>& destination){
    // must figure out indexToBeMoved
    destination.push_back(from[indexToBeMoved]);
    from.erase(remove(from.begin(), from.end(), from[indexToBeMoved]), from.end());
}

// returns index of the culprit or -1 if not found
int findOneEnemy(int origIndex, vector<int> v, vector<vector<int>> enemies){
    for(int i = 0; i < v.size(); i++){
        if(i != origIndex){
            // if v[i] is one of the original index's enemies, return the index (it is the culprit)
            if(find(enemies[v[origIndex]-1].begin(), enemies[v[origIndex]-1].end(), v[i]) != enemies[v[origIndex]-1].end()){
                cout << "found the culprit, index is: " << i << " and v[i] = " << v[i] << endl;
                return i;
            }
        }
    }
    return -1;
}

bool findEnemies(int culpritIndex, vector<int> v, vector<vector<int>> enemies){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(i != culpritIndex){
            // if there is more than one enemy then we must move the culprit
            if(find(enemies[v[culpritIndex]-1].begin(), enemies[v[culpritIndex]-1].end(), v[i]) != enemies[v[culpritIndex]-1].end()){
                count++;
                cout << "found " << count << " enemies" << endl;
                if(count > 1){
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    int soldiers; // n 
    int enemyPairs; // m (m lines)
    cin >> soldiers >> enemyPairs;
    vector<int> groupOne;
    vector<int> groupTwo;
    for(int i = 1; i <= soldiers; i++){
        groupOne.push_back(i);
    }
    

    vector<vector<int>> enemies(soldiers);
    for(int j = 0; j < enemyPairs; j++){  
        int pairOne, pairTwo;
        cin >> pairOne >> pairTwo;
        enemies[pairOne-1].push_back(pairTwo);
        enemies[pairTwo-1].push_back(pairOne);
    }

    for(int s = 0; s < groupOne.size(); s++){
        int iter = 0;
        int count = 0;
        while(iter < groupOne.size()){
            if(iter != s){
                // if solider is found in groupOne[s] enemy list
                if(find(enemies[groupOne[s]-1].begin(), enemies[groupOne[s]-1].end(), groupOne[iter]) != enemies[groupOne[s]-1].end()){
                    // enemy count += 1
                    count++;
                    // cout << "s: " << s << " iter: " << iter << " soldier: " << groupOne[s] << " count: " << count << endl;
                    if(count > 1){
                        // always starts from groupTwo to groupOne if switchback needed
                        int fromGroupOne = -1;
                        // put this value into groupTwo
                        groupTwo.push_back(groupOne[s]);
                        // delete value from groupOne
                        groupOne.erase(remove(groupOne.begin(), groupOne.end(), groupOne[s]), groupOne.end());
                        // bool hasEnemies = false;
                        // findOneEnemy returns index of culprit
                        int hasEnemy = findOneEnemy(groupTwo.size()-1, groupTwo, enemies);
                        // TO DO =================================
                        if(hasEnemy >= 0){
                            bool enemyHasEnemies = findEnemies(hasEnemy, groupTwo, enemies);
                        }
                        else{
                            bool enemyHasEnemies = false;
                        }
                        // =======================================
                        //perform check here
                        // if(***there is an enemy1 of groupOne[s]***){
                        //     if( enemy1 has one other enemy in current group){
                        //          move enemy1 to other group
                        //     }
                        // }
                        // TO DO======================================
                        // while(enemyHasEnemies){
                        //     if(fromGroupOne > 0){
                        //         switchGroups(toBeMoved, groupOne, groupTwo);
                        //         fromGroupOne *= -1;
                        //         hasEnemy = findOneEnemy(orig, groupTwo);
                        //         if(hasEnemy){
                        //             enemyHasEnemies = findEnemies(culprit, groupTwo);
                        //         }
                        //     }
                        //     else{
                        //         switchGroups(toBeMoved, groupTwo, groupOne);
                        //         fromGroupOne *= -1;
                        //         hasEnemy = findOneEnemy(orig, groupOne);
                        //         if(hasEnemy){
                        //             enemyHasEnemies = findEnemies(culprit, groupOne);
                        //         }
                        //     }
                        // }
                        // ========================================

                        // ----------
                        fromGroupOne = -1;
                        s--;
                        iter = groupOne.size()+1;
                        count = 0;
                    }
                    else{
                        iter++;
                    }
                }
                else{
                    iter++;
                }
            }
            else{
                iter++;
            }
        }
    }
    if(groupTwo.size() > 0){
        cout << "2" << endl;
        for(int l = 0; l < groupOne.size(); l++){
            cout << groupOne[l] << " ";
        }
        cout << endl;
        for(int j = 0; j < groupTwo.size(); j++){
            cout << groupTwo[j] << " ";
        }
        cout << endl;
    }
    else{
        cout << "1" << endl;
        for(int l = 0; l < groupOne.size(); l++){
            cout << groupOne[l] << " ";
        }
        cout << endl;
    }
    
    

    // for(int z = 0; z < enemies.size(); z++){
    //     cout << "Index: " << z << " Soldier: " << z+1 << " Enemies: ";
    //     for(int y = 0; y < enemies[z].size(); y++){
    //         cout << enemies[z][y] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}