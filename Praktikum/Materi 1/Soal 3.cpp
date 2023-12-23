#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//cek apakah input memenuhi kriteria
auto destinasi_valid = [](const string& destinasi){ //pakai auto soalnya int ataupun void tidak bisa dipakai
    int o = 0; //declarasikan banyak huruf o
    for(char c : destinasi){ //loop setiap huruf untuk check o dari string destinasi
        if(tolower(c) == 'o'){ //jika ada o maka o bertambah 1 dengan semua o dikecilkan menjadi lowercase o (mempersingkat code) 
            o++;
        }
    }
    return o <= 2; //jika o kurang atau sama dengan 2 maka return destinasinya
};

int main() {
    //declarsikan variable
    vector<string> destinasi;
    string input;

    //baca input sampai gass
    while(true){
        getline(cin, input); //input string
        if(input == "gasss"){ //jika gasss maka break dari loop
            break;
    }
    destinasi.push_back(input); //vector push.back
    }

    //menghapus destinasi yang tidak valid dari input menggunakan vector erase dan remove_if
    destinasi.erase(remove_if(destinasi.begin(), destinasi.end(), [&destinasi_valid](const string& destinasi){
        return !destinasi_valid(destinasi);
    }), destinasi.end());

    //sort destinasi secara alfabet dengan vector sort
    sort(destinasi.begin(), destinasi.end());

    //print
    cout << endl;
    for(const string& destinasi : destinasi){
        cout << destinasi << endl;
    }
    return 0;
}

//pakai VSCode untuk testing agar bisa lihat errornya