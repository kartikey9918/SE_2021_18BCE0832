#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string,pair<int, int> > m;
vector<vector<string> > grid(5, vector<string> (5,"  - "));
void Place(int turn){
    int fact;
    string str;
    if(turn == 0){
        fact = 0;
        str = "A";
    }else{
        fact = 4;
        str = "B";
    }
    cout<<"Enter Pawn's of Player "+str+": ";
    for(int i=0;i<5;i++){
        cin>>grid[fact][i];
        grid[fact][i] = str+"-"+ grid[fact][i];
        m[grid[fact][i]] = make_pair(fact, i);
    }
    cout<<endl;
    return;
}
void Move(char movement, int x, int y, string p){
}
int main(){
    int turn = 0; //Player 1's turn
    Place(0);
    Place(1);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int t = 2;
    string player = "A";
    string move;
    string in;
    int x,y;
    while(t--){
        cout<<"Turn of Player "+player+" :";
        cin>>move;
        in = (player+"-"+move.substr(0,2));
        x = m[in].first;
        y = m[in].second;
        Move(move[3], x, y, player);
        cout<<in<<"-> ("<<x<<","<<y<<")"<<endl;
        player = (turn == 0 ? "B": "A");
        turn = (turn == 0 ? 1: 0);
    }
    cout<<endl;
    for(auto s: m){
        cout<<s.first<<"-> ("<<m[s.first].first<<","<<m[s.first].second<<")"<<endl;
    }
    return 0;
}