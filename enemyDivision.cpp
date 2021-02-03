#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// bool checkEnemies(vector<vector<int>>& e, vector<int> group){
//     for(int i = 0; i < group.size(); i++){
//         if(group.)
//     }
// }

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
                        // put this value into groupTwo
                        groupTwo.push_back(groupOne[s]);
                        // delete value from groupOne
                        groupOne.erase(remove(groupOne.begin(), groupOne.end(), groupOne[s]), groupOne.end());
                        //perform check here
                        // if(***there is an enemy of groupOne[s]***){
                        //     see if that enemy
                        // }


                        // ----------
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