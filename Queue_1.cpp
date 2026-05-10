#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// (Fungsi rev() yang sudah kamu buat biarkan di sini)
queue<int> rev(queue<int> q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    return q;
}

// Tambahkan blok ini agar bisa di-Run di VS Code
int main() {
    queue<int> antrean_awal;
    
    // Masukkan data contoh: 4, 3, 1
    antrean_awal.push(4);
    antrean_awal.push(3);
    antrean_awal.push(1);

    // Panggil fungsi rev untuk membalikkan
    queue<int> hasil = rev(antrean_awal);

    // Tampilkan hasilnya
    cout << "Hasil antrean terbalik: ";
    while (!hasil.empty()) {
        cout << hasil.front() << " ";
        hasil.pop();
    }
    cout << endl;

    return 0;
}