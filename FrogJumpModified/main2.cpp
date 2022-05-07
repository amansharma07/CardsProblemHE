#include<bits/stdc++.h>
using namespace std;

vector<int> solve (int N, vector<int> H, int A, int B, int Q, vector<int> K) {
   // Write your code here
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> H(N);
    for(int i_H = 0; i_H < N; i_H++)
    {
    	cin >> H[i_H];
    }
    int A;
    cin >> A;
    int B;
    cin >> B;
    int Q;
    cin >> Q;
    vector<int> K(Q);
    for(int i_K = 0; i_K < Q; i_K++)
    {
    	cin >> K[i_K];
    }

    vector<int> out_;
    out_ = solve(N, H, A, B, Q, K);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}