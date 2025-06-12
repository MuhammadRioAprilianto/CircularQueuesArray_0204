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
        //cek apakah antrian kosong?
        if (FRONT == -1)
        {
            cout << "\nQueue Underflow\n";
            return;
        }
        cout << "\nThe element deleted from Queue is: " << queues_array[FRONT] << "\n"; //elemen mana yang mau dihapus?

        //cek jika antrian hanya memiliki 1 elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            //Jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max -1)
                FRONT = 0;
            else
                FRONT = FRONT +1; 
        }
    }

    void display()
    {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // cek apakah antrian kosong?
        if (FRONT == -1)
        {
            cout << "Queue is Empty\n";
            return; 
        }

        cout << "\nElements in the queue are...\n";

        //jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queues_array[FRONT_position] << "   ";
                FRONT_position;
            }
            cout << endl;
        }
        else
        {
            //jika FRONT_position > REAR_position, iterasi dari FRONT hingga array
            while (FRONT_position <= max -1)
            {
                cout << queues_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            FRONT_position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_position <= REAR_position)
            {
                cout << queues_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Queues q; 
    char ch;

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement Insert Operation" << endl;
            cout << "2. Implement Delete Operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter Your Choice: (1-4)";
            cin >> ch;
            cout << endl;

            switch (ch) //membuat switch case
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid Option!!" << endl;
                    break;
                }
            }
        }
        catch  (exception &e)
        {
            cout << "Check for the values entered." << endl;
        }    
    }  
}