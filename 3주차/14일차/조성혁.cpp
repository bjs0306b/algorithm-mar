#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;
    int oddSum=0;
    int evenSum=0;
    int odd=0;
    int even=0;
    vector<int> v(n);
    for (int i=0;i<n;i++) {
        cin>>v[i];
        if (v[i]%2) {
            odd++;
            oddSum+=v[i];
        }
        else {
            even++;
            evenSum+=v[i];
        }
    }

    int sum=oddSum+evenSum;
    if (sum%3!=0) {
        cout<<"NO";
        return 0;
    }

    // 일단 1 뿌리기
    int one=sum/3,two=sum/3;
    oddSum-=odd;
    one-=odd;
    if (one>=0&&oddSum+evenSum==2*(one/2+two)) cout<<"YES";
    else cout<<"NO";
}
