#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int a = 0; a < n; a++){
        int b, c;
        // b = # of strings, c = # of char in each string
        cin >> b >> c;
        vector<int> vec(0);
        // set vector vec to all 0's for this case;
        vec.resize(c);
        vector<string> bStrings;
        // get each binary string in this test case;
        for(int i = 0; i < b; i++){
            string str;
            cin >> str;
            // loop through each binary char in each string
            for(int j = 0; j < str.size(); j++){
                // if the bString at j is a 1, add 1 to vec[j] 
                if(str[j] == '1'){
                    vec[j] += 1;
                }
            }
        }
        // loop through vec
        for(int iter = 0; iter < vec.size(); iter++){
            // if vec[iter] >= half the size of # of strings then print 1
            // otherwise print 0 as that string
            double half = double(b)/2.0;
            if(vec[iter] >= half){
                cout << '1';
            }
            else{
                cout << '0';
            }
        }
        cout << endl;

    }

    return 0;
}