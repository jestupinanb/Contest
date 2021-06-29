#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class FreqStack {
public:

    /*
    function<bool(pair<int,list<int>>,pair<int,list<int>>)> cmp = [](pair<int,list<int>>& p2,pair<int,list<int>> p1){
        if(p1.second.size()!=p2.second.size()){
            return p1.second.size()>p2.second.size();
        }
        return p1.second.back()>p2.second.back();
    };
    */
    //define the lambda function
    function<bool(int,int)> cmp = [&](int v1, int v2) {return v1 < v2; };

    //priority_queue<pair<int,list<int>>,vector<pair<int,list<int>>>,decltype(cmp)> pq;
    priority_queue<int, vector<int>, decltype(cmp)> pq;

    int pos = 0;

    FreqStack() {
	//use the lambda function in the constructor of the priority_queue
        pq = decltype(pq)(cmp);
    }

    void push(int val) {
        pq.push(val);
    }

    int pop() {
        return 1;
    }
};

int main() {
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    FreqStack f = FreqStack();

    f.push(1);
    f.push(2);
    f.push(13);
    f.push(45);

	return 0;
}
