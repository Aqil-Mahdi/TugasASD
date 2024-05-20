Penjelasan Code:
1. struct Node:
   Ini adalah struktur untuk merepresentasikan setiap node dalam senarai. Setiap node memiliki dua bagian utama, yaitu data yang menyimpan nilai dan dua pointer
   yang menunjuk ke node berikutnya (next) dan sebelumnya (prev).
   
2. newNode():
   Fungsi ini digunakan untuk membuat node baru dengan nilai data tertentu. Ini mengalokasikan memori untuk node baru dan mengatur nilai-nilai awalnya.
   
3. insert():
   Fungsi ini digunakan untuk memasukkan node baru ke dalam senarai. Jika senarai kosong, maka node baru akan menjadi satu-satunya node dalam senarai.
   Jika tidak, node baru akan dimasukkan sebelum node pertama dan setelah node terakhir dalam senarai.
   
4. printList():
   Fungsi ini digunakan untuk mencetak semua node dalam senarai, dimulai dari node pertama hingga kembali ke node pertama.
   Ini menggunakan perulangan do-while karena senarai bersifat bersirkular.
   
5. sortListAddress():
   Fungsi ini mengurutkan node dalam senarai berdasarkan alamat memori dari node.
   Ini adalah implementasi pengurutan bubble sort yang membandingkan alamat memori dari node-node.
   
6. sortListNumber():
   Fungsi ini mengurutkan node dalam senarai berdasarkan nilai data yang disimpan dalam node.
   Ini juga adalah implementasi pengurutan bubble sort, tetapi kali ini membandingkan nilai data dari node-node.
   
7. main():
   Fungsi utama program. Di sini, input dari pengguna digunakan untuk membuat senarai dan kemudian mencetaknya sebelum dan sesudah pengurutan
   menggunakan kedua metode yang disebutkan di atas.
