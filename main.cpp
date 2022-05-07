#include<bits/stdc++.h>
using namespace std;

// Minimum time to make target X from cards in range [L, R]
// where each pile cards is a power of 2 and you take 1 second to
// divide a pile into two equal piles 

// Initial idea : Keep a prefix array of size 64 * n (bits) and store the count of each bit
// being set for every pile initially
// Then pref[R] - pref[L - 1] will give the count of each number in the range in O(1)

// Then find out if you can calculate time effectively in O(64) or O(64 * 64)

// -1 case will be when sum of all numbers in [L,R] i.e. x1 * c1 + x2 * c2 .... < X
// where x and c are the bit value and bit count

// inp1 and inp2 attached already, rest files with similar names in desktop

vector<int> min_time (int N, vector<int> cards, vector<vector<long long> > queries) {
   // Write your code here
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> cards(N);
    for(int i_cards = 0; i_cards < N; i_cards++)
    {
    	cin >> cards[i_cards];
    }
    int Q;
    cin >> Q;
    vector<vector<long long> > queries(Q, vector<long long>(3));
    for(int i=0; i<Q; i++)
    {
    	for(int j=0; j<3; j++)
    	{
    		cin >> queries[i][j];
    	}
    }

    vector<int> out_;
    out_ = min_time(N, cards, queries);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}