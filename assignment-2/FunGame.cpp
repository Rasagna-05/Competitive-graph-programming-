#include<bits/stdc++.h>
using namespace std;

vector<int> funGame (vector<int> arr) {
   // Write your code here
   stack<int> b;
   queue<int> a;
   vector<int> v;
   for(int i=0;i<arr.size();i++){
    a.push(arr[i]);
    b.push(arr[i]);
   }
   while((!a.empty()) && (!b.empty())){
    if(a.front()==b.top()){
        v.push_back(0);
        a.pop();
        b.pop();
    }else if((a.front())>(b.top())){
        v.push_back(1);
        b.pop();
    }else if((a.front())<(b.top())){
        v.push_back(2);
        a.pop();
    }
   }
   return v;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    vector<int> out_;
    out_ = funGame(arr);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}
