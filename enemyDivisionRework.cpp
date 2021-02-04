#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

#define rep(i,a,b) for(__typeof(b) i = a; i < (b); i++)
#define trav(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)

typedef vector<int> vi;
int main(){
    // n is soldiers, m is enemy pairs
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a=a-1;
        b=b-1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> group(n, 2);
    vector<int> enemy(n, 0);
    for(int i = 0; i < n; i++){                 
        vector<int> cnt(3);
        for(int j = 0; j < g[i].size(); j++){
            cnt[group[g[i][j]]]++;
        }

        int color = 0, cur = i;
        if (cnt[0] > 1)
            color = 1;

        while (true){
            group[cur] = color;
            int ncur = -1;
            for(int j = 0; j < g[cur].size(); j++){              
                if (group[g[cur][j]] == color){
                    enemy[cur]++;
                    if (++enemy[g[cur][j]] == 2){
                        ncur = g[cur][j];
                        for(int l = 0; l < g[ncur].size(); l++){
                            if (group[g[ncur][l]] == color){
                                enemy[g[ncur][l]]--;
                                enemy[ncur]--;
                            }
                        }
                    }
                }
            }

            if (ncur == -1)
                break;
            cur = ncur;
            color = !color;
        }
    }

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