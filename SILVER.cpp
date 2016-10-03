#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int n;
    while(1){
        cin >> n;
        if(n==0) break;
        else{
            cout << (int)log2(n) << "\n";
        }
    }
    return 0;
}
 
