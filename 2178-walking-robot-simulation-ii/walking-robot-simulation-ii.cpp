class Robot {
public:
    string dir;
    int n, m;
    int x, y;
    Robot(int width, int height) {
        dir = "East";
        n = width;
        m = height;
        x = 0, y = 0;
    }

    void step(int num) {
        int per = 2 * (n + m - 2);
        num %= per;
        if(num == 0 && x == 0 && y == 0) {
            dir = "South";
            return;
        }
        while (num > 0) {
            if (dir == "East") {
                int move = min(num, n-1-x);
                x += move;
                num -= move;
                if(num > 0) dir ="North";
            } else if (dir == "North") {
                int move = min(num,m -1-y);
                y+= move;
                num -= move;
                if(num > 0) dir ="West";
            } else if (dir == "West") {
                int move = min(num,x);
                x -= move;
                num -= move;
                if(num > 0) dir ="South";
            } else if (dir == "South") {
                int move = min(num, y);
                y -= move;
                num -= move;
                if(num > 0) dir ="East";
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() { return dir; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */