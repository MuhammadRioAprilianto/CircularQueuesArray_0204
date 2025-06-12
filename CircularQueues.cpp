#include <iostream>
using namespace std;

class Queues{
    private:
    static const int max = 5; //memubuat array dengan panjang 5 index
    int FRONT, REAR; // membuat penanda eleman pertama dan terakhir
    int queues_array[5]; //membuat array queues

    public:
    Queues(){ //memuat penanda queues dengan set FRONT dan REAR
        FRONT = -1;
        REAR = -1;
    }

    void insert(){ //memuat fungsi insert
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;
        
    }
};