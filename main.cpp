#include <iostream>
#include <string>
#include <fstream>


class Player {
private:
    const int x;
    const int y;
    int hp;

    std:: string name;
public:
    Player(const int x_, int y_, int hp_, std::string name_) : x{x_}, y{y_}, hp{hp_}, name{name_} {
        std:: cout<<name << "\n";
    }
    // const de initializare
    int alive () {
        return hp;
    }
    void hit (){
        --hp;
    }
    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << "x: " << player.x << " y: " << player.y << " hp: " << player.hp << " name: " << player.name << "\n";
        return os;
    }
    // op<<

    void getxy(int& cx, int& cy){
        cx = x;
        cy = y;
    }
    void hpshow(){
        std:: cout <<"Viata ramasa:" << hp<<"\n";
    }

};

class Level {
private:
    int lvl;
public:

    Level(const int lvl_) : lvl{lvl_} {
        std:: cout<<"Level initial: "<< lvl<< "\n";
    }
    // constructor de initializare

    friend std::ostream &operator<<(std::ostream &os, const Level &level) {
        os << "lvl: " << level.lvl;
        return os;
    }
    void nextlvl(){
        ++lvl;
    }
    void getlvl(int& clvl){
        clvl = lvl;
    }
    // op<<
};


class Game {
private:
    static const int n = 20;
    int m[n][n];
    Player pl;
    Level lv;

public:
    Game(Player player_ , Level level_) :pl{player_}, lv{level_}{
        std:: cout<<pl << lv << '\n';
    }
    // const de initializare
    void buildmatrix (){
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m[i][j] = 0;
            }
        }
    }

    void afmatrix (){
        
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(m[i][j] == -1){
                    
                    std:: cout<<" ";
                }
                else if (m[i][j] == 0){
                    
                    std:: cout<<" ";
                }
                else if(m[i][j] == 1){
                    
                    std:: cout<<" ";
                }
                else{
                    
                    std:: cout<<" ";
                }

            }
            std:: cout<<"\n";
            
        }
    }

    void putinmatrix (int cx, int cy){
        m[cx][cy] = 1;
    }

    void movement(int& cx, int& cy){
        char mymove = ' ';

        std::cin >> mymove;
        if (mymove == 'W') {
            cx--;
        }
        else if (mymove == 'A') {
            cy--;
        }
        else if (mymove == 'S') {
            cx++;
        }
        else if (mymove == 'D') {
            cy++;
        }
        if(cx < 0) {cx = 0;}
        else if(cx > 19) {cx = 19;}
        if(cy < 0) {cy = 0;}
        else if(cy > 19) {cy = 19;}
    }

    void randomshoot(int a, int b){

        std:: cout<<a<<b<<"Fisier \n";
        if (m[a][b] == 1)
            m[a][b] = -2;
        else
            m[a][b] = -1;
    }
    int verhit (int cx, int cy){
        if(m[cx][cy] == -2)
            return 0;
        return 1;
    }
    
    // op==

    friend std::ostream &operator<<(std::ostream &os, const Game &game) {
        os << "n: " << game.n;
        std:: cout<< "game.n";
        return os;
    }
    // op<<


    ~Game() {
        std:: cout<<"destructor Game" << "\n";
    }
    //destruct


};
void startgame()
{

    Player pl{10,10,3,"Chad"};
    Level lv{0};
    Game gm{pl,lv};
    gm.buildmatrix();
    int contor = 10;
    int dummy = 0, dummy2 = 0 , cx = 10, cy = 10;
    while(pl.alive() and contor!=0){
        pl.getxy(cx,cy);
        lv.nextlvl();
        lv.getlvl(dummy);
        dummy2 = dummy;
        std::cout << lv << "\n";
        while(dummy != 0) {
            gm.movement(cx, cy);
            dummy--;
        }
        gm.putinmatrix(cx,cy);
        gm.afmatrix();
        std:: cout<<"Miscarea mea \n";
        while(dummy2 != 0){
            int a=0,b=0;
            std::cin >> a >> b;
            gm.randomshoot(a,b);
            dummy2--;
        }
        gm.afmatrix();
        std::cout<<"Random misc \n";
        if(gm.verhit(cx,cy) == 0){
            pl.hit();
        }
        pl.hpshow();
        gm.buildmatrix();
        contor--;
    }

}


int main() {

    startgame();
    std:: cout<< "Final de joc";
    return 0;
}
