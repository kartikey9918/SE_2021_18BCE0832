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
string Collision(int x,int y,char ch){
    for(auto s: m){
        if(s.first[0] == ch)
            continue;
        if(x == m[s.first].first && y == m[s.first].second)
            return s.first;
    }
    return "";
}
bool Move(char movement, int x, int y, string pawn, string p){
    if(x == -1 && y == -1)
        return false;
    if(p == "A"){
        if(movement=='F' && x < 4){
            x++;
        }else if(movement == 'B' && x > 0){
            x--;
        }else if(movement == 'L' && y < 4){
            y++;
        }else if(movement == 'R' && y > 0){
            y--;
        }else{
            cout<<"Out of Bounds no Updates occured"<<endl;
            return false;
        }
    }else{
        if(movement == 'F' && x > 0){
            x--;
        }else if(movement == 'B' && x < 4){
            x++;
        }else if(movement == 'L' && y  > 0){
            y--;
        }else if(movement == 'R' && y < 4){
            y++;
        }else{
            cout<<"Out of Bounds no Updates occured"<<endl;
            return false;
        }
    }
    string coll_pawn = Collision(x, y, p[0]);
    if(coll_pawn != ""){
        m[coll_pawn] = make_pair(-1,-1);
    }
    grid[m[pawn].first][m[pawn].second] = "  - ";
    m[pawn] = make_pair(x, y);
    grid[x][y] = pawn;
    return true;
}
void Print_grind(){
    cout<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
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
    int t = 8; // Moves of player
    string player = "A";
    string move;
    string in;
    int x,y;
    bool ans;
    while(t--){
        cout<<"Turn of Player "+player+" :";
        cin>>move;
        in = (player+"-"+move.substr(0,2));
        x = m[in].first;
        y = m[in].second;
        ans = Move(move[3], x, y, in,player);
        if(ans){
            Print_grind();
        }
        player = (turn == 0 ? "B": "A");
        turn = (turn == 0 ? 1: 0);
    }
    for(auto s: m){
        cout<<s.first<<"-> ("<<m[s.first].first<<","<<m[s.first].second<<")"<<endl;
    }
    return 0;
}