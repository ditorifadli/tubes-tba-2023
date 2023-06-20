<h1 align ="center"> Lexical Analyzer dan Parser "for-loop C++".</h1>

## Cara menjalankan program:
1. Clone menggunakan `git clone https://github.com/ditorifadli/tubes-tba-2023.git`
2. Pada folder yang sudah di clone, jalankan  `tubes-tba.exe`
3. Atau gunakan compiler C++ dan jalankan `tubes-tba.cpp`
4. Program siap dijalankan

## Cara memasukan inputan:
1. Setelah di run, akan muncul input:
2. Masukan file dengan format txt seperti `SourceCode.txt`
3. Lalu enter, kode berhasil dijalankan

## Contoh isi dari SourceCode.txt:
```
for (int i = 1; i <= 5; i++){ 
    cout <<i; 
    }
```

## Output dari SourceCode.txt
<h3>Hasil</h3>
```
	 Token   No :01  |          for  ------->  |                Statement                  
	 Token   No :02  |            (  ------->  |           Special-Symbol                  
	 Token   No :03  |          int  ------->  |                Data Type                  
	 Token   No :04  |            i  ------->  |                 Variable                  
	 Token   No :05  |            =  ------->  |                 Operator                  
	 Token   No :06  |            1  ------->  |                  Integer                  
	 Token   No :07  |            ;  ------->  |           Special-Symbol                  
	 Token   No :08  |            i  ------->  |                 Variable                  
	 Token   No :09  |            <  ------->  |                 Operator                  
	 Token   No :10  |            =  ------->  |                 Operator                  
	 Token   No :11  |            5  ------->  |                  Integer                  
	 Token   No :12  |            ;  ------->  |           Special-Symbol                  
	 Token   No :13  |            i  ------->  |                 Variable                  
	 Token   No :14  |           ++  ------->  |                 Operator                  
	 Token   No :15  |            )  ------->  |           Special-Symbol                  
	 Token   No :16  |            {  ------->  |           Special-Symbol                  
	 Token   No :17  |         cout  ------->  |                 Keywords                  
	 Token   No :18  |           <<  ------->  |                 Operator                  
	 Token   No :19  |            i  ------->  |                 Variable                  
	 Token   No :20  |            ;  ------->  |           Special-Symbol                  
	 Token   No :21  |            }  ------->  |           Special-Symbol                  
Hasil Parsing Dari:
for (int i = 1; i <= 5; i++){ 
    cout <<i; 
    }
Valid/ Diterima!
```
