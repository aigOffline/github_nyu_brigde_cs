
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

const int BUGS_COUNT = 5;
const int ANTS_COUNT = 100;
const int N = 20;

class Organism{
protected:
    int x;
    int y;
    int survived;
public:
    void set_xy(int x1, int y1) {
        x = x1;
        y = y1;
    }
    
    virtual void move(char world[N][N]) {
        
    }
    
    int get_x() {
        return x;
    }
    int get_y() {
        return y;
    }
    
    int get_survived() {
        return survived;
    }
    
    Organism(int x1, int y1) {
        set_xy(x1, y1);
        survived = 0;
    }
    
};

class Ant : public Organism{
private:
public:
    void move(char world[N][N]) {
        int direction;
        
        // direction = 0 up
        // 1 left
        // 2 down
        // 3 right
        direction = rand() % 4;
        switch(direction){
            case 0:
                if (y - 1 >= 0 && world[x][y-1] == '-') {
                    world[x][y] = '-';
                    y--;
                    world[x][y] = 'o';
                }
                break;
            case 1:
                if(x - 1 >= 0 && world[x-1][y] == '-') {
                    world[x][y] = '-';
                    x--;
                    world[x][y] = 'o';
                }
                break;
            case 2:
                if (y + 1 <= N - 1 && world[x][y+1] == '-') {
                    world[x][y] = '-';
                    y++;
                    world[x][y] = 'o';
                }
                break;
            case 3:
                if(x + 1 <= N - 1 && world[x+1][y] == '-') {
                    world[x][y] = '-';
                    x++;
                    world[x][y] = 'o';
                }
                break;
        }
        survived++;
    }
    Ant(int x1, int y1) : Organism(x1, y1) {}
};

class Doodlebug : public Organism{
private:
    int eaten;
public:
    Doodlebug(int x1, int y1) : Organism(x1, y1) {
        eaten = 0;
    }
    
    int get_eaten() {
        return eaten;
    }
    
    void eat_ant(vector<Ant> &ants) {
        int k = 0;
        for (; k < ants.size(); k++)
            if (ants[k].get_x() == x && ants[k].get_y() == y)
                break;
        ants.erase(ants.begin() + k);
        eaten++;
    }
    void move(char world[][N], vector<Ant> &ants) {
        int direction;
        // direction = 0 up
        // 1 left
        // 2 down
        // 3 right
        direction = rand() % 4;
        switch(direction){
            case 0:
                if (y - 1 >= 0 && world[x][y-1] != 'X') {
                    world[x][y] = '-';
                    y--;
                    if (world[x][y] == 'o') {
                        eat_ant(ants);
                    }
                    world[x][y] = 'X';
                }
                break;
            case 1:
                if (x - 1 >= 0 && world[x-1][y] != 'X')
                {
                    world[x][y] = '-';
                    x--;
                    if (world[x][y] == 'o') {
                        eat_ant(ants);
                    }
                    world[x][y] = 'X';
                }
                break;
            case 2:
                if (y + 1 <= N - 1 && world[x][y+1] != 'X') {
                    world[x][y] = '-';
                    y++;
                    if (world[x][y] == 'o') {
                        eat_ant(ants);
                    }
                    world[x][y] = 'X';
                }
                break;
            case 3:
                if (x + 1 <= N - 1  && world[x+1][y] != 'X')
                {
                    world[x][y] = '-';
                    x++;
                    if (world[x][y] == 'o') {
                        eat_ant(ants);
                    }
                    world[x][y] = 'X';
                }
                break;
        }
        eaten--;
        survived++;
    }
};

void print_world(char world[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << world[i][j] << " ";
        cout << endl;
    }
}

int main(void) {
    
    char world[N][N];
    //'-' - клетка пустая
    //'o' - муравей
    //'X' - жук
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            world[i][j] = '-';
    
    vector<Doodlebug> bugs;
    vector<Ant> ants;
    srand(time(NULL));
    int k = 0;
    int x = 0;
    int y = 0;
    while (k < BUGS_COUNT) {
        x = rand() % N;
        y = rand() % N;
        if (world[x][y] == '-') {
            Doodlebug temp = Doodlebug(x, y);
            bugs.push_back(temp);
            world[x][y] = 'X';
            k++;
        }
    }
    k = 0;
    
    while(k < ANTS_COUNT) {
        x = rand() % N;
        y = rand() % N;
        if(world[x][y] == '-') {
            Ant temp = Ant(x, y);
            ants.push_back(temp);
            world[x][y] = 'o';
            k++;
        }
    }
    print_world(world);
    int count = 0;
    cout << "please enter \'enter\' key" << endl;
    while (true)  {
        cin.get();
        for (int i = 0 ; i < bugs.size(); i++) {
            bugs[i].move(world, ants);
            if (bugs.size() > 0) {
                if (bugs[i].get_eaten() == -3) {
                    world[bugs[i].get_x()][bugs[i].get_y()] = '-';
                    bugs.erase(bugs.begin() + i);
                    i--;
                }
                
                if (bugs[i].get_survived() % 8 == 0) {
                    if (bugs[i].get_x() > 0 && world[x - 1][y] == '-') {
                        Doodlebug temp = Doodlebug(x - 1, y);
                        world[x - 1][y] = 'X';
                        bugs.push_back(temp);
                    } else {
                        if (bugs[i].get_y() > 0 && world[x][y - 1] == '-') {
                            Doodlebug temp = Doodlebug(x, y - 1);
                            world[x][y - 1] = 'X';
                            bugs.push_back(temp);
                        } else {
                            if (bugs[i].get_x() < N - 1 && world[x + 1][y] == '-') {
                                Doodlebug temp = Doodlebug(x + 1, y);
                                world[x + 1][y] = 'X';
                                bugs.push_back(temp);
                            }
                            else {
                                if (bugs[i].get_y() < N - 1 && world[x][y + 1] == '-') {
                                    Doodlebug temp = Doodlebug(x, y + 1);
                                    world[x][y + 1] = 'X';
                                    bugs.push_back(temp);
                                }
                            }
                        }
                    }
                }
                
            }
        }
        for (int i = 0 ; i < ants.size(); i++)
            if (ants.size() > 0) {
                ants[i].move(world);
                
                if (ants[i].get_survived() % 3 == 0) {
                    if (ants[i].get_x() > 0 && world[x - 1][y] == '-') {
                        Ant temp = Ant(x - 1, y);
                        world[x - 1][y] = 'o';
                        ants.push_back(temp);
                    } else {
                        if (ants[i].get_y() > 0 && world[x][y - 1] == '-') {
                            Ant temp = Ant(x, y - 1);
                            world[x][y - 1] = 'o';
                            ants.push_back(temp);
                        } else {
                            if (ants[i].get_x() < N - 1 && world[x + 1][y] == '-') {
                                Ant temp = Ant(x + 1, y);
                                world[x + 1][y] = 'o';
                                ants.push_back(temp);
                            }
                            else {
                                if (ants[i].get_y() < N - 1 && world[x][y + 1] == '-') {
                                    Ant temp = Ant(x, y + 1);
                                    world[x][y + 1] = 'o';
                                    ants.push_back(temp);
                                }
                            }
                        }
                    }
                }
                
            }
        
        
        print_world(world);
        if (bugs.size() == 0 && ants.size() == 0) {
            cout << "GAME OVER! The world is empty" << endl;
            break;
        }
        if (ants.size() == N * N) {
            cout << "GAME OVER! The world is full of ants!" << endl;
            break;
        }
        cout << "please enter \'enter\' key" << endl;
    }
    return 0;
}
