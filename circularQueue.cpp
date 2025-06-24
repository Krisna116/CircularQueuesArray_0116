/**
 * @mainpage Documentation Circular Queues
 * 
 * @section Introduction
 * project ini menruapkan project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrrsy
 * 
 * @section OPeration
 * Project ini memiliki beberapa operasi antara lain:
 * 1. insert
 * 2. delete
 * 3. dispalay
 * 
 * @section cara penggunaan
 * berikut beberapa menu yang dapat digunakan:
 * 1. en queue
 * 2. de queue
 * 3. display
 * 4. exit
 * 
 * @author Profil
 * -nama : Krisna Ageng Pangestu
 * -nim : 20240140116
 * -kelas : C
 * 
 * @brief
 * @version 1.0
 * date 2025-06-24
 * 
 * @copyright krisna.ageng.ft24@mail.umy.ac.id (c) 2025
 * 
 * 
 */


#include <iostream>
using namespace std;
/**
 * @class Queue
 * @brief class ini untuk operasi lengkap queues
 * 
 * 
 */

class Queues {
private:
    int FRONT;// < variable private front untuk menyimpan posisi depan antrian
    int REAR; ///< variable private rear untuk menyimpan posisi belakang antrian
    int queue_array[5]; ///< varible private queue_array untuk menyimpan antrian
    static const int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian

public:
    /**
     * @brief Counstruct a new Queues project
     * set default quues null
     * with front = -1 and rear = -1
     */
    Queues() {
        FRONT = -1;
        REAR = -1;
    }
    /**
     * @brief metode unruk memasukkan data dalam antrian
     * data dimasukkan dalam variable queue_array
     */

    void insert() {
        int num; //< variable num unruk menyimapan nilai
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // 1. cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // 2. cek apakah antrian kosong 
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        } 
        else {
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }

        queue_array[REAR] = num;
    }
    /**
     * @brief metode untuk menghhapus data dalam antrian
     * data dihapus dari dalam variable queue_array
     */
    void remove() {
        //Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        //Cek jika antrian hanya memiliki satu element
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;

        }
        else {
            //Jika element yg dihapus berada diposisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    /**
     * @brief metode untuk menampilkan data dalam antrian
     * data ditampilakn yang berada dalam variablr queue_array
     */
    void display() {
        int FRONT_position = FRONT; //<variable front_position untuk menandakan posisi element pertama pada variable front
        int REAR_position = REAR; //<variable rear_position untuk menandakan posisi element terakhir pada variable rear

        //Cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";
        
        //Jika FRONT_position <= REAR_position, interasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
        }
        else {
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            FRONT_position = 0;
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
        }
        cout << endl;
    }
};
/**
 * @brief metode untuk menjalankan program
 * 
 * @return int
 */
int main() {
    Queues q; //< objek untuk menggunakan member yang ada dalam class queues
    char ch; //< variable ch untuk  menyimpan pilihan pada menu yang diberikan

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display value" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch) {
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
                cout << "Invalid option, please choose between 1 and 4.\n";
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "Check for the value entered." << endl;
        }
    }

    return 0;
}
