#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isvalid(int row, int col,vector<string>& board,int n){
    int dprow = row;
    int dpcol = col;
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    col = dpcol;
    row = dprow;
    while(col>=0){
        if(board[row][col] == 'Q') return false;
        col--;
    }
    col = dpcol;
    row = dprow;
    while(row<n && col>=0){
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;

}
void func(int col, vector<string>& board,vector<vector<string>>& ans,int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for(int i = 0; i < n; i++){
        if(isvalid(i,col,board,n)){
            board[i][col] = 'Q';
            func(col+1,board,ans,n);
            board[i][col] = '.';
        }
    }

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin>>n;

    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i = 0; i < n; i++){
        board[i] = s;
    }
    func(0,board,ans,n);

    for(auto & it : ans){
        vector<string> & v = it;
        for(auto & s : v){
            cout<<s<<" ";
        }
        cout<<endl;
    }

    return 0;
}