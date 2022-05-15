#include<bits/stdc++.h>
using namespace std;

#define ll long long

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
   vector<int> res;
   vector<vector<int>> bits_pref(N + 3, vector<int>(64, 0));
   int idx = 0;
   for(auto val : cards) {
       bitset<64> bs(val);
       for(int i = 0; i < 64; i++) {
           bits_pref[idx + 1][i] = bits_pref[idx][i] + (bs.test(i) ? 1 : 0);
       }
       idx++;
   }
   idx = 0;
   for(auto val : queries) {
       ll low = val[0];
       ll hi = val[1];
       ll target = val[2];
       vector<int> v_low = bits_pref[low - 1];
       vector<int> v_hi = bits_pref[hi];
       ll max_target = 0;
       vector<int> calc_vec;
       for(int i = 0; i < 64; i++) {
           if(v_hi[i] - v_low[i]) {
               max_target += (pow(2, i) * (v_hi[i] - v_low[i]));
           }
           calc_vec.push_back(v_hi[i] - v_low[i]);
       }
       if(target > max_target) {
           res.push_back(-1);
       }
       else if(target == max_target) {
           res.push_back(0);
       }
       else {
           // For time being
           bitset<64> tt(target);
           int count = 0;
           for(int i = 0; i < 64; i++)
           {
               if(calc_vec[i] != 0) {
                   idx = i;
                   break;
               }
           }
           int found_idx = idx;
           idx--;
           while(idx >= 0) {
               if(tt.test(idx)) {
                   count += (found_idx - idx);
                   found_idx = idx;
               }
               idx--;
           }
           res.push_back(count);
       }
   }
   return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    ifstream fin;
    fin.open("input.txt");
    fin >> N;
    vector<int> cards(N);
    for(int i_cards = 0; i_cards < N; i_cards++)
    {
    	fin >> cards[i_cards];
    }
    int Q;
    fin >> Q;
    vector<vector<long long> > queries(Q, vector<long long>(3));
    for(int i=0; i<Q; i++)
    {
    	for(int j=0; j<3; j++)
    	{
    		fin >> queries[i][j];
    	}
    }

    vector<int> out_;
    out_ = min_time(N, cards, queries);
    ofstream fout;
    fout.open("output.txt");
    fout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	fout << " " << out_[i_out_];
    }
    fout.close();
    return 0;
}