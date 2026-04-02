#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

// Fungsi Prototype
int yearsOld(tm* inputTgl, tm* currentTgl);
int monthsOld(tm* inputTgl, tm* currentTgl);
string dayOfDate(tm* inputTgl);

int main(int argc, char ** argv) 
{
    time_t currentTime;
    time(&currentTime);
    tm* currentTgl = localtime(&currentTime);

    int yearinput, monthinput, dayinput;
    string inputstr;
    char ch;
    
    // Input format DD/MM/YYYY
    if (!(cin >> inputstr)) return 0;
    stringstream ss(inputstr);
    ss >> dayinput >> ch >> monthinput >> ch >> yearinput;
    
    tm* inputTgl = new tm();
    inputTgl->tm_year = yearinput - 1900;
    inputTgl->tm_mon = monthinput - 1;
    inputTgl->tm_mday = dayinput;

    // Memanggil fungsi yang sudah diisi
    int ageOfYear = yearsOld(inputTgl, currentTgl);
    int ageOfMonth = monthsOld(inputTgl, currentTgl);
    string dayName = dayOfDate(inputTgl);

    cout << ageOfYear << " " << ageOfMonth << " " << dayName;

    delete inputTgl; // Menghapus memori manual
    return 0;
}

// --- ISI LOGIKA DI SINI ---

int yearsOld(tm* inputTgl, tm* currentTgl)
{
    // Hitung selisih tahun dasar
    int age = currentTgl->tm_year - inputTgl->tm_year;
    
    // Koreksi jika belum berulang tahun di tahun ini
    if (currentTgl->tm_mon < inputTgl->tm_mon || 
       (currentTgl->tm_mon == inputTgl->tm_mon && currentTgl->tm_mday < inputTgl->tm_mday)) {
        age--;
    }
    return age;
}

int monthsOld(tm* inputTgl, tm* currentTgl)
{
    // Konversi semua ke bulan
    int totalMonths = (currentTgl->tm_year - inputTgl->tm_year) * 12;
    totalMonths += (currentTgl->tm_mon - inputTgl->tm_mon);
    
    // Koreksi jika hari ini belum mencapai tanggal lahir di bulan ini
    if (currentTgl->tm_mday < inputTgl->tm_mday) {
        totalMonths--;
    }
    return totalMonths;
}

string dayOfDate(tm* inputTgl)
{
    // mktime akan mengisi variabel tm_wday secara otomatis (0-6)
    mktime(inputTgl); 
    
    // Array hari sesuai urutan tm_wday (0=Minggu, 1=Senin, dst)
    string hari[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    
    // Mengembalikan nama hari berdasarkan index tm_wday
    if(inputTgl->tm_wday >= 0 && inputTgl->tm_wday <= 6) {
        return hari[inputTgl->tm_wday];
    }
    return "Error";
}