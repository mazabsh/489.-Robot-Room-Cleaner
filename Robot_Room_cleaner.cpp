#include<iostream> 
#include<set> 
#include<vector> 

using namespace std; 

class Robot{
    bool move(); 
    void turnRight(); 
    void turnLeft(); 
    void clean(); 
}; 
class Solution{
public: 
      vector<pair<int,int>> directions={{-1,0}, {1,0}, {0,1},{0,-1}}; 
      set<pair<int,int>> visited; 
      void goback(Robot* robot){
        robot.turnRigh(); 
        robot.turnRight(); 
        robot.move(); 
        robot.turnRight(); 
        robot.turnRight(); 
      }
      void dfs(int x, int y, int dir , Robot& robo){
        visited.insert({x,y}); 
        robot.clean(); 
        for(int i=0; i<4;++i){
          int newdir = (dir+i)%4; 
          int nx = x+directions[newDir][0]; 
          int ny = y + directions[newDir][1]; 
          if(!visited.count({nx,ny}) && robot.move()){
            dfs(nx, ny, newDir, robot); 
            robot.goback(); 
          }
          robot.turnRight(); 
        }
        
      }
      void cleanRoom(Robot& robot) {
        dfs(0,0,0, robot); 
      }
};
