#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool isOperator(const string& tok) {
    if (tok=="+"||tok=="-"||tok=="*"||tok=="/") return true;
    return false;
}

// (피)연산자 추출
// *-, /- 인 경우 별도 처리
// return: 추출한 문자열, 다음 인덱스
pair<string,int> parse(const string& expr,int idx) {
    if (isOperator(string(1,expr[idx]))) {
        // 별도 처리
        if (idx!=0&&!isOperator(string(1,expr[idx-1])))
            return {string(1,expr[idx]),idx+1};
    }

    pair<string,int> ret={"",expr.size()};
    for (int i=idx;i<expr.size();i++) {
        if (isOperator(string(1,expr[i]))&&i!=idx) {
            ret.second=i;
            break;
        }
        ret.first+=expr[i];
    }

    return ret;
}

// 1: front 더 높음
// -1: back 더 높음
// 0: 같음
int cmp(const string& front,const string& back) {
    int a=front=="*"||front=="/"?1:0;
    int b=back=="*"||back=="/"?1:0;
    if (a>b) return 1;
    if (a<b) return -1;
    return 0;
}

long long calc(const string& op,long long a,long long b) {
    if (op=="+") return a+b;
    if (op=="*") return a*b;
    if (op=="/") return a/b;
    if (op=="-") return a-b;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string expr;
    cin>>expr;

    int idx=0;
    deque<long long> operands;
    deque<string> operators;
    while (idx<expr.size()) {
        auto ret=parse(expr,idx);
        string token=ret.first;
        idx=ret.second;

        if (isOperator(token)) operators.push_back(token);
        else operands.push_back(stoll(token));
    }

    while (!operators.empty()) {
        string frontOp=operators.front();
        string backOp=operators.back();

        int prior=cmp(frontOp,backOp);

        // front 우선순위 높음
        if (prior==1) {
            operators.pop_front();
            long long a=operands.front(); operands.pop_front();
            long long b=operands.front(); operands.pop_front();
            operands.push_front(calc(frontOp,a,b));
        }
        // back 우선순위 높음
        else if (prior==-1) {
            operators.pop_back();
            long long a=operands.back(); operands.pop_back();
            long long b=operands.back(); operands.pop_back();
            operands.push_back(calc(backOp,b,a));
        }
        // 우선순위 같음
        else {
            long long frontRes=calc(frontOp,operands[0],operands[1]);
            long long backRes=calc(backOp,operands[operands.size()-2],operands[operands.size()-1]);

            if (frontRes>=backRes) {
                operators.pop_front();
                operands.pop_front(); operands.pop_front();
                operands.push_front(frontRes);
            }
            else {
                operators.pop_back();
                operands.pop_back(); operands.pop_back();
                operands.push_back(backRes);
            }
        }
    }

    cout<<operands.front();
}
