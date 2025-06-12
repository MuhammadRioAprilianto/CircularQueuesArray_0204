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

        //1. cek apakah antrian penuh?
        if ((FRONT == 0 && REAR == max -1 ) || (FRONT == REAR + 1))
        {
            cout << "\nQueue Overflow\n"; //1.a
            return; // 1.b
        }

        //2. apakah antrian kosong?
        if (FRONT == -1)
        {
            FRONT = 0; //2.a
            REAR = 0; //2.b
        }
        else
        {
            //Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max -1)
                REAR = 0;
            else
                REAR = REAR + 1;
        } 
        queues_array[REAR] = num;
    }

    void remove()
    {
        
    }
};