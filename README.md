# Sisop-5-2025-IT12

## Kelompok

Nama | NRP
--- | ---
Nadia Kirana Afifah Prahandita | 5027241005
Hansen Chang | 5027241028
Muhammad Khosyi Syehab | 5027241089

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## SOAL 1 

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:
   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:
   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:
   * `user <username>` = mengubah username menjadi `<username>`
   * `user` = mengubah username menjadi default `user`
   
   Ilustrasi:
   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:
   * `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   * `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   * `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   * `grandcompany <selain atau kosong>` = tunjukkan error message
   * `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:
   * Maelstrom = `user@Storm`
   * Twin Adder = `user@Serpent`
   * Immortal Flames = `user@Flame`
   * `clear` = menghapus nama grand company

   Ilustrasi:
   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:
   * `add <x> <y>` = x + y
   * `sub <x> <y>` = x - y
   * `mul <x> <y>` = x * y
   * `div <x> <y>` = x / y

   Ilustrasi:
   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt
   
   gurt:
   * `yo`
   * `ts unami gng </3`
   * `sygau`

   pilih secara *random*

   Ilustrasi:
   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

8. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

* [kernel.asm](src/kernel.asm)
  * `_putInMemory`: penjelasan terdapat dalam modul
  * `_interrupt`: fungsi untuk interrupt
    * `number`: interrupt vector number
    * `AX`,`BX`,`CX`,`DX`: register untuk diisi
    * `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    * Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
   * `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
* [kernel.c](src/kernel.c)
  * Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    * untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    * untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    * untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
* [shell.c](src/shell.c)
  * Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

* [std_type.h](include/std_type.h)
  * `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  * `bool`: untuk boolean (true/false), karena boolean tidak built-in
* [std_lib.h](include/std_lib.h)
  * `div`: division
  * `mod`: modulo
  * Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  * `strcmp`: membandingkan dua string
  * `strcpy`: copy string
  * `clear`: fill memory dengan `0`
  * `atoi`: alphanumeric to integer (string menjadi angka)
  * `itoa`: integer to alphanumeric (angka menjadi string)
* [kernel.h](include/kernel.h)
  * Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
* [shell.h](include/shell.h)
  * Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

* [makefile](./makefile)
   * `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
   * `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
   * `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
   * `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
   * `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
   * `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
   * `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mp4)

https://github.com/user-attachments/assets/1cfa66b1-b2f5-4e3e-a4b2-ec8b012f6fbb


## Laporan
## SOAL 1 
 Pada soal pertama, shell diminta untuk mencetak ulang perintah pengguna jika perintah tersebut tidak dikenali sebagai command yang valid.
Fitur ini dikenal sebagai The Echo, yaitu shell akan "mengulang" kata-kata pengguna layaknya gema.

![WhatsApp Image 2025-06-08 at 17 03 12_11266832](https://github.com/user-attachments/assets/4627dc1a-083d-4644-9667-31c2f4bbbb48)

## SOAL 2 
Soal ini mengharuskan shell untuk merespons dua perintah istimewa: yo dan gurt.
Masing-masing perintah akan membalas dengan pasangan sebaliknya:

yo → output: gurt

gurt → output: yo

![WhatsApp Image 2025-06-08 at 17 03 12_a0937267](https://github.com/user-attachments/assets/b4cad505-08ba-4c76-b2b7-13b6c3bb0977)

## SOAL 3
Shell perlu memiliki fitur untuk mengganti nama pengguna (username) yang ditampilkan di prompt.
Perintah yang digunakan adalah:

user <nama> untuk mengganti nama.

user saja untuk mengembalikannya ke user.

![WhatsApp Image 2025-06-08 at 17 03 12_88ce9adc](https://github.com/user-attachments/assets/7fe0ea44-a3e9-488c-867f-6a3515b31b12)

## SOAL 4
 Soal ini memperkenalkan command grandcompany yang akan mengatur warna tampilan terminal serta identitas pengguna berdasarkan faksi:

grandcompany maelstrom → teks merah, prompt menjadi user@Storm

grandcompany twinadder → teks kuning, prompt menjadi user@Serpent

grandcompany immortalflames → teks biru, prompt menjadi user@Flame

clear → kembalikan warna default dan hapus afiliasi faksi (para Grand Company sedih kamu netral)

## grandcompany maelstrom → teks merah, prompt menjadi user@Storm

![WhatsApp Image 2025-06-08 at 17 03 11_ba31e7f2](https://github.com/user-attachments/assets/7063f45e-5c23-457f-a20a-188cf064f2dc)

## grandcompany twinadder → teks kuning, prompt menjadi user@Serpent

![WhatsApp Image 2025-06-08 at 17 03 23_adc2859c](https://github.com/user-attachments/assets/280967aa-037b-48bd-b137-095441ccf039)


## grandcompany immortalflames → teks biru, prompt menjadi user@Flame

![WhatsApp Image 2025-06-08 at 17 03 23_31796527](https://github.com/user-attachments/assets/7ad5b067-d5bd-4fd6-bf15-c7cb49bc7965)


## clear → kembalikan warna default dan hapus afiliasi faksi (para Grand Company sedih kamu netral)

![WhatsApp Image 2025-06-08 at 17 03 23_f5792cf6](https://github.com/user-attachments/assets/ab305509-5b2f-4a45-98b3-dc526f7bc6eb)

## SOAL 5 
Shell kini ditambahkan kemampuan kalkulasi dengan perintah aritmatika:

add x y → hasil dari x + y

sub x y → hasil dari x - y

mul x y → hasil dari x * y

div x y → hasil dari x / y (dengan pengecekan nol)

![WhatsApp Image 2025-06-08 at 17 03 24_70a59df1](https://github.com/user-attachments/assets/c3655abe-2f06-4e10-80d7-3adc484ef260)

## SOAL 6
 Perintah yogurt akan menampilkan satu dari beberapa balasan acak, seperti:

"yo"

"ts unami gng </3"

"sygau"

![WhatsApp Image 2025-06-08 at 17 03 24_5a5e3483](https://github.com/user-attachments/assets/d101aeaa-43c2-4100-be6e-2803295800e6)





