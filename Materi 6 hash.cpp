<<<<<<< HEAD
#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

// buat map string to string
map<string, map<string, string> > dataAkun;

// Hash function
int hashFunction(string password){
    int hash = 0;
    const int PRIME_CONST = 11;

    // ASCII sum
    for (char c : password) {
        hash += static_cast<int>(c);
    }

    // Polynomial hash
    int final_hash = 0;
    for (int i = 0; i < password.length(); i++) {
        final_hash += password[i] * static_cast<int>(pow(PRIME_CONST, i));
    }

    // Combine both hashes
    return hash + final_hash;
}

void registerAkun() {
    string username, password, fullname;

    cout << "Masukan Username:" << endl;
    cin >> username;
    cout << "Masukan Password:" << endl;
    cin >> password;
    cout << "Masukkan Nama Lengkap: " << endl;
    cin >> fullname; 

    string hash_key = to_string(hashFunction(password));

    //nessted map
    map<string, string> dataDetail;
    dataDetail["username"] = username;
    dataDetail["fullname"] = fullname;

    //masukan ke map
    //dataAkun[hash_key] = username; 
    dataAkun[hash_key] = dataDetail;   
}

void loginAkun()
{
  string username, password;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;

  string hash_key = to_string(hashFunction(password));

  cout << endl;
  if (dataAkun.find(hash_key) != dataAkun.end())
  {
    cout << "Login berhasil!" << endl
         << endl;
    cout << "==== Account Details ====" << endl;
    cout << "Username: " << dataAkun[hash_key]["username"] << endl;
    cout << "Fullname: " << dataAkun[hash_key]["fullname"] << endl;

  } else {
    cout << "Login gagal!" << endl
         << endl;
  }
}

void printAkun() {
    for (auto i = dataAkun.begin(); i != dataAkun.end(); i++) {
    cout << "Key: " << i->first << "\t"
         << " Username: " << i->second["username"] 
         << " Fullname: " << i->second["fullname"] << endl;
  }
}

// Menu
void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << endl;
    cout << "Pilih Menu: " << endl;
    cin >> input_user;

    if (input_user == 1)
    {
      registerAkun();
    }
    else if (input_user == 2)
    {
      loginAkun();
    }
    else if (input_user == 3)
    {
      printAkun();
      break;
    }
    else
    {
      cout << "Invalid!" << endl;
    }
  }
}

int main() {
    menu();
    return 0;
}
=======
#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

// buat map string to string
map<string, map<string, string> > dataAkun;

// Hash function
int hashFunction(string password){
    int hash = 0;
    const int PRIME_CONST = 11;

    // ASCII sum
    for (char c : password) {
        hash += static_cast<int>(c);
    }

    // Polynomial hash
    int final_hash = 0;
    for (int i = 0; i < password.length(); i++) {
        final_hash += password[i] * static_cast<int>(pow(PRIME_CONST, i));
    }

    // Combine both hashes
    return hash + final_hash;
}

void registerAkun() {
    string username, password, fullname;

    cout << "Masukan Username:" << endl;
    cin >> username;
    cout << "Masukan Password:" << endl;
    cin >> password;
    cout << "Masukkan Nama Lengkap: " << endl;
    cin >> fullname; 

    string hash_key = to_string(hashFunction(password));

    //nessted map
    map<string, string> dataDetail;
    dataDetail["username"] = username;
    dataDetail["fullname"] = fullname;

    //masukan ke map
    //dataAkun[hash_key] = username; 
    dataAkun[hash_key] = dataDetail;   
}

void loginAkun()
{
  string username, password;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;

  string hash_key = to_string(hashFunction(password));

  cout << endl;
  if (dataAkun.find(hash_key) != dataAkun.end())
  {
    cout << "Login berhasil!" << endl
         << endl;
    cout << "==== Account Details ====" << endl;
    cout << "Username: " << dataAkun[hash_key]["username"] << endl;
    cout << "Fullname: " << dataAkun[hash_key]["fullname"] << endl;

  } else {
    cout << "Login gagal!" << endl
         << endl;
  }
}

void printAkun() {
    for (auto i = dataAkun.begin(); i != dataAkun.end(); i++) {
    cout << "Key: " << i->first << "\t"
         << " Username: " << i->second["username"] 
         << " Fullname: " << i->second["fullname"] << endl;
  }
}

// Menu
void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << endl;
    cout << "Pilih Menu: " << endl;
    cin >> input_user;

    if (input_user == 1)
    {
      registerAkun();
    }
    else if (input_user == 2)
    {
      loginAkun();
    }
    else if (input_user == 3)
    {
      printAkun();
      break;
    }
    else
    {
      cout << "Invalid!" << endl;
    }
  }
}

int main() {
    menu();
    return 0;
}
>>>>>>> 005225e (add files)
