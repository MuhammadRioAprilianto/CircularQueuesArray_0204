/**
 * @mainpage Documentation Project Circular Queues
 * 
 * @section introduction
 * project ini merupakan project struktur data
 * menggunakan struktur queues dengan pendekatan circular array
 * 
 * @section opration
 * project ini memiliki bebrapa operasi diantaranya:
 * 1. insert
 * 2. delete
 * 3. display
 * 
 * @section cara penggunaan
 * berikut beberapa menu yang bisa digunakan
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profile
 * - Nama : Muhammad Rio Aprilianto
 * - NIM  : 20240140204
 * - Kelas: TI/D
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright rio.umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief Class ini untuk operasi lengkap queues
 */
class Queues{
    private:
    static const int max = 5; ///< variable max untuk menyimpan ukuran maximum antrian
    int FRONT; ///< variable private FRONT untuk menyimpan posisi depan antrian
    int REAR; ///< variable private REAR unutk menyimpan posisi belakang antrian
    int queues_array[max]; //variable queues_array untuk menyimpan eleman antrian

    public:
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with FRONT = -1 and REAR = -1 
     */
    Queues(){ //memuat penanda queues dengan set FRONT dan REAR
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method untuk memasukkan data dalam antrian
     * data dimasukkan dalam variable queues_array
     * terdapat variable num untuk menyimpan data yang diinputkan
     */
    void insert(){ //memuat fungsi insert
        int num; ///< variable num untuk menyimpan data yang diinputkan
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

    /**
     * @brief method yang digunakan unutk menghapus element pada array
     * data yang akan dihapus adalan element FRONT dari queues_array
     */
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

    /**
     * @brief method ini digunakan untuk menampilkan data antrian
     * data yang ditampilkan terdapat di dalam variable queues_array
     */
    void display()
    {
        int FRONT_position = FRONT; ///< variable FRONT_positian menandakan data pertama pada array
        int REAR_position = REAR; ///< variable REAR_positian menandakan data terakhir pada array

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
                FRONT_position++;
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

/**
 * @brief function yang digunakan untuk memanggil dan menjalankan semua method yang telah dibuat
 * pada function ini dibuat objek q dari class Queues 
 */
int main()
{
    Queues q; 
    char ch; ///< variable ch yang digunakan untuk membuat switch case

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement Insert Operation" << endl;
            cout << "2. Implement Delete Operation" << endl;
            cout << "3. Display Values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter Your Choice(1-4):";
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