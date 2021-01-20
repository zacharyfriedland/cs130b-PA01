#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int a = 0; a < n; a++){
        int b, c;
        cin >> b >> c;      // b = n (# of strings), c = m (# of char in each string)
        vector<int> vec(0);
        // set vector vec to all 0's for this case;
        vec.resize(c);
        vector<string> bStrings;
        // get each binary string in this test case;
        for(int i = 0; i < b; i++){
            string str;
            cin >> str;
            //bStrings.push_back(str);
            // loop through each binary char in each string
            for(int j = 0; j < str.size(); j++){
                if(str[j] == '1'){
                    vec[j] += 1;
                }
            }
        }
        for(int iter = 0; iter < vec.size(); iter++){
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