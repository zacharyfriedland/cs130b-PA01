#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void switchGroups(int indexToBeMoved, vector<int>& from, vector<int>& destination){
    destination.push_back(from[indexToBeMoved]);
    from.erase(remove(from.begin(), from.end(), from[indexToBeMoved]), from.end());
}

// returns index of the culprit or -1 if not found
int findOneEnemy(int origIndex, vector<int> v, vector<vector<int>> enemies){
    for(int i = 0; i < v.size(); i++){
        if(i != origIndex){
            // if v[i] is one of the original index's enemies, return the index (it is the culprit)
            if(find(enemies[v[origIndex]-1].begin(), enemies[v[origIndex]-1].end(), v[i]) != enemies[v[origIndex]-1].end()){
                return i;
            }
        }
    }
    return -1;
}

int findOneEnemy(int origIndex, vector<int> v, vector<vector<int>> enemies, int newIndex){
	if(newIndex == 0){
		return findOneEnemy(int origIndex, vector<int> v, vector<vector<int>> enemies);
	}
    for(int i = newIndex; i < v.size(); i++){
        if(i != origIndex){
            // if v[i] is one of the original index's enemies, return the index (it is the culprit)
            if(find(enemies[v[origIndex]-1].begin(), enemies[v[origIndex]-1].end(), v[i]) != enemies[v[origIndex]-1].end()){
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
        int count = 0;
		int newIndex = 0;
		// if enemy is found, update count by 1
		if(findOneEnemy(s, groupOne, enemies, newIndex) >= 0){
			// enemy count += 1
			count++;
			newIndex = findOneEnemy(s, groupOne, enemies, newIndex);
			if(count > 1){
				// always starts from groupTwo to groupOne if switchback needed
				int fromGroupOne = -1;
				// put this value into groupTwo
				groupTwo.push_back(groupOne[s]);
				// delete value from groupOne
				groupOne.erase(remove(groupOne.begin(), groupOne.end(), groupOne[s]), groupOne.end());
				// findOneEnemy returns index of culprit = hasEnemy
				int hasEnemy = findOneEnemy(groupTwo.size()-1, groupTwo, enemies);
				bool enemyHasEnemies = false;
				if(hasEnemy >= 0){
					enemyHasEnemies = findEnemies(hasEnemy, groupTwo, enemies);
				}
				while(enemyHasEnemies){
					if(fromGroupOne > 0){
						switchGroups(hasEnemy, groupOne, groupTwo);
						fromGroupOne *= -1;
						hasEnemy = findOneEnemy(groupTwo.size()-1, groupTwo, enemies);
						if(hasEnemy >= 0){
							enemyHasEnemies = findEnemies(hasEnemy, groupTwo, enemies);
						}
						else{
							enemyHasEnemies = false;
							hasEnemy = -1;
						}
					}
					else{
						switchGroups(hasEnemy, groupTwo, groupOne);
						fromGroupOne *= -1;
						hasEnemy = findOneEnemy(groupOne.size()-1, groupOne, enemies);
						if(hasEnemy >= 0){
							enemyHasEnemies = findEnemies(hasEnemy, groupOne, enemies);
						}
						else{
							enemyHasEnemies = false;
							hasEnemy = -1;
						}
					}
				}
				fromGroupOne = -1;
				s--;
				iter = groupOne.size()+1;
				count = 0;
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

    return 0;
}