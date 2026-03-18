#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;
    cin>>str;

    string a="KSA";
    string b="SAK";
    string c="AKS";
    int aCnt=0,bCnt=0,cCnt=0;

    // 패턴별로 가장 긴 연속된 문자열의 길이를 찾는다.
    for (int i=0;i<str.size();i++) {
        if (a[aCnt%3]==str[i]) aCnt++;
        if (b[bCnt%3]==str[i]) bCnt++;
        if (c[cCnt%3]==str[i]) cCnt++;
    }

    bCnt=min(bCnt,(int)str.size()-1);
    cCnt=min(cCnt,(int)str.size()-2);

    int maxCnt=max({aCnt,bCnt,cCnt});
    cout<<2*str.size()-2*maxCnt;
}
