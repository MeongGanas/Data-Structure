#include <stdio.h>   

// Fungsi untuk mengecek apakah sebuah bilangan adalah bilangan prima
int is_prime(int n){
    if (n < 2) return 0;    // Jika n kurang dari 2, maka bukan bilangan prima
    
    // Perulangan untuk mengecek apakah n habis dibagi angka selain 1 dan dirinya sendiri; i*i <= n artinya cukup cek sampai akar dari n
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0) return 0;     // Jika n habis dibagi i, maka bukan prima
    }
    return 1;   // Jika tidak ada pembagi, maka bilangan prima
}

int main(){
    int n, q;       // Variabel: n = jumlah piring: q = jumlah iterasi
    printf("Jumlah Piring dan Iterasi :  ");
    scanf("%d %d", &n, &q);
    
    int a[50000];       // Array utama untuk menyimpan nomor piring
    int b[50000];       // Array untuk menyimpan piring yang habis dibagi bilangan prima
    int temp_a[50000];  // Array sementara untuk menyimpan piring yang tidak habis dibagi
    
    printf("Input %d nomor piring : ", n);  // Input nomor piring
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);     // Menyimpan input ke array a
    }
    
    int a_size = n;     // Menyimpan ukuran array a
    int primes[1200];   // Array untuk menyimpan bilangan prima

    // count = jumlah prima yang sudah ditemukan
    // num = angka yang sedang dicek
    int count = 0, num = 2;

    // Cari q buah bilangan prima
    while(count < q){
        if(is_prime(num)){            // Jika num adalah prima
            primes[count++] = num;    // Simpan ke array primes
        }
        num++;      // Cek angka berikutnya
    }
    printf("\nOUTPUT\n");
    for(int i = 0; i < q; i++){         // Perulangan sebanyak q iterasi
        int b_size = 0;                 // Ukuran array b
        int temp_a_size = 0;            // Ukuran array temp_a
        
        for(int j = a_size - 1; j >= 0; j--){   // Memproses array a dari belakang karena konsep stack (LIFO)
            if(a[j] % primes[i] == 0){          // Jika angka habis dibagi bilangan prima saat ini
                b[b_size++] = a[j];             // Masukkan ke array b
            } else {
                temp_a[temp_a_size++] = a[j];   // Jika tidak habis dibagi, simpan ke temp_a
            }
        }
        // Cetak isi b dari belakang agar urutan stack benar
        for(int j = b_size - 1; j >= 0; j--){
            printf("%d\n", b[j]);
        }

        // Update ukuran a
        a_size = temp_a_size;
        // Copy isi temp_a kembali ke a
        for(int j = 0; j < a_size; j++){
            a[j] = temp_a[j];
        }
    }
    // Setelah semua iterasi selesai,
    // cetak sisa elemen di a
    for(int j = a_size - 1; j >= 0; j--){
        printf("%d\n", a[j]);
    }
    return 0;
}   
