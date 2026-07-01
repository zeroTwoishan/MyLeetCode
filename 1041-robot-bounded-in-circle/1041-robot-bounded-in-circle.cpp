class Solution {
public:
    char trunLeft(char prevDir){
        if(prevDir == 'N') return 'W';
        else if(prevDir == 'W') return 'S';
        else if(prevDir == 'S') return 'E';
        return 'N';
    }
    char trunRight(char prevDir){
        if(prevDir == 'N') return 'E';
        else if(prevDir == 'E') return 'S';
        else if(prevDir == 'S') return 'W';
        return 'N';
    }
    void move(vector<int> & pos,char dir){
        if(dir == 'N')pos[1]++;
        else if(dir == 'E')pos[0]++;
        else if(dir == 'S')pos[1]--;
        else pos[0]--;     
    }
    bool isRobotBounded(string instructions) {
        int n = instructions.size();
        char direction = 'N';
        vector<int> pos(2,0);
        for(int i = 0;i < n;i++){
            if(instructions[i] == 'G') move(pos,direction);
            else if(instructions[i] == 'L') direction = trunLeft(direction);
            else direction = trunRight(direction);
        }
        return ((pos[0] == 0 && pos[1] == 0) || direction != 'N');
    }
};