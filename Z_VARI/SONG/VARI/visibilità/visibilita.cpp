#include <iostream>

using namespace std;

class Visibilita{
    public:
        int a = 2;
    
    private:
        int b = 4;

    protected:
        int c = 5;

    public:
        int getB(){ return b;}
        void setB(int x){b = x;}
};

class Sottovisibilita : public Visibilita{
    public:
        int d = 12;

    void prova(){
        cout << a << " " << c << " " << d << endl;
    }
};

int main(){
    
    Visibilita v;
    v.a = 2;
    v.setB(4);
    cout << v.getB() << endl;
    //v.c = 5;

    Sottovisibilita va;
    va.prova();
    return 0;
}