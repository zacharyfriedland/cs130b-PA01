#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;


int main(){
    // n is soldiers, m is enemy pairs
    int n, m;
    scanf("%d %d", &n, &m);
    // vector of vectors holds enemies of soliders
    vector<vector<int>> enemyList(n);
    for(int i = 0; i < m; i++){
        // read in enemy pairs and put in respective index at array
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        // enemies are mutual
        enemyList[a].push_back(b);
        enemyList[b].push_back(a);
    }

    // keeps track of enemies in a group
    vector<int> group(n, 2);
    vector<int> enemy(n, 0);
    for(int i = 0; i < n; i++){                 
        vector<int> count(3);
        for(int j = 0; j < enemyList[i].size(); j++){
            count[group[enemyList[i][j]]]++;
        }

        int flag = 0;
        // follow index
        int current = i;
        if (count[0] > 1){
            flag = 1;
        }
        // keep checking until break
        while (true){
            // group[current] starts at 0 or 1 if count > 1
            group[current] = flag;
            int ncur = -1;
            // check enemies at current solider
            for(int j = 0; j < enemyList[current].size(); j++){              
                if (group[enemyList[current][j]] == flag){
                    enemy[current]++;
                    // if two enemies exist then ncur = that index
                    if (++enemy[enemyList[current][j]] == 2){
                        ncur = enemyList[current][j];
                        for(int x = 0; x < enemyList[ncur].size(); x++){
                            if (group[enemyList[ncur][x]] == flag){
                                enemy[enemyList[ncur][x]]--;
                                enemy[ncur]--;
                            }
                        }
                    }
                }
            }
            // if two enemies did not exist then break out of while
            if (ncur == -1){
                break;
            }
            current = ncur;
            flag = !flag;
        }
    }

    // print result
    vector<vector<int>> result(2);
    for(int i = 0; i < n; i++){                      
        result[group[i]].push_back(i);
    }
    printf("%d\n", 1 + !result[1].empty());
    for(int i = 0; i < 2; i++){         
        for(int j = 0; j < result[i].size(); j++){
            printf("%d", result[i][j] + 1);
            if (j + 1 < result[i].size())
                printf(" ");
            else
                printf("\n");
        }
    }
}