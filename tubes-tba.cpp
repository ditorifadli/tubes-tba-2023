#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <iomanip>

using namespace std;

// Fungsi untuk membuat map regex
map<string, string> Buat_Map_Regex() {
    map<string, string> my_map{
        { "cin|cout|main|using|namespace|std|endl", "Keywords" },
        { "for", "Statement" },
        { "\\;|\\{|\\}|\\(|\\)", "Special-Symbol" },
        { "int|char|float|bool", "Data Type" },
        { "\\*|\\/|\\++|\\--|\\>>|\\<<|\\<|\\>|\\<=|\\>=|\\=", "Operator" },
        { "[0-9]+", "Integer" },
        { "[a-zA-Z]+", "Variable" },
        { "[ ]", " " }
    };
    return my_map;
}

// Fungsi untuk mencocokkan token dengan pola dalam bahasa pemrograman
map<size_t, pair<string, string>> Match_Language(map<string, string> patterns, string str) {
    map<size_t, pair<string, string>> lang_matches;

    for (auto i = patterns.begin(); i != patterns.end(); ++i) {
        regex compare(i->first);
        auto words_begin = sregex_iterator(str.begin(), str.end(), compare);
        auto words_end = sregex_iterator();

        // MEMBUAT PAIR DARI [STRING OF REGEX 'compare' : 'pattern']
        for (auto it = words_begin; it != words_end; ++it)
            lang_matches[it->position()] = make_pair(it->str(), i->second);
    }
    return lang_matches;
}

bool parseForLoop(const string& str) {
    // Menentukan pola untuk for-loop C++
    regex forLoopPattern(R"(for\s*\(\s*(\w+\s+\w+\s*=\s*\w+\s*;\s*\w+\s*[<>]=?\s*\w+\s*;\s*\w+\s*(\+\+|--))\s*\)\s*\{\s*([\s\S]*?)\s*(cout\s*<<\s*[\s\S]+;\s*)*\})");

    // Untuk memeriksa apakah string input cocok dengan pola
    return regex_match(str, forLoopPattern);
}

int main() {
    ofstream fout;
    cout << endl << endl << endl;
    cout.fill(' ');
    cout.width(100);
    fout.open("OutputFile.txt");
    string filename;

    cout << "MASUKAN NAMA FILE 'SourceCode.txt' LALU TEKAN ENTER! \n";
    cout << "Input: ";
    cin >> filename;
    ifstream fin(filename);
    string str;

    if (fin.is_open()) {
        str.assign((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());

        // Membuat map yang mendefinisikan regex dalam token ke pola dalam bahasa pemrograman
        map<string, string> patterns = Buat_Map_Regex();

        // Mendapatkan pasangan dari ['Kode Sumber':'Pola Terdefinisi'] melalui regex yang bernama 'compare'
        map<size_t, pair<string, string>> lang_matches = Match_Language(patterns, str);

        // Menulis pasangan hasil cocokan dalam File dengan mengabaikan 'spasi' dan '\n'.
        int count = 1;
        cout << "\t\t\t\t------------------------------------------------------------------------------------------- \n";
        cout.width(40);
        cout << "\t        NUMBER" << setw(10) << "              TOKEN " << " " << "            " << setw(20) << " PATTERN \n";
        cout.fill(' ');
        cout.width(40);
        cout << "\t\t\t\t------------------------------------------------------------------------------------------- \n\n\n";

        for (auto match = lang_matches.begin(); match != lang_matches.end(); ++match) {
            if (!(match->second.first == " ") && !(match->second.first == "//")) {
                cout.width(40);
                if (count < 10) {
                    string double_digits = to_string(count);
                    double_digits = "0" + double_digits;
                    cout << "\t Token   No :" << double_digits << "  |   " << setw(10) << match->second.first << " " << " ------->  |" << setw(25) << match->second.second << setw(18) << "   " << endl;
                    fout << "\t Token   No :" << double_digits << "  |   " << setw(10) << match->second.first << " " << " ------->  |" << setw(25) << match->second.second << setw(18) << "   " << endl;
                    count++;
                } else {
                    cout << "\t Token   No :" << count << "  |   " << setw(10) << match->second.first << " " << " ------->  |" << setw(25) << match->second.second << setw(18) << "   " << endl;
                    fout << "\t Token   No :" << count << "  |   " << setw(10) << match->second.first << " " << " ------->  |" << setw(25) << match->second.second << setw(18) << "   " << endl;
                    count++;
                }
            }
                         
        }
        cout << "-------------------------------------------------------------------------------------------------- \n";
        cout << "\nHasil Parsing Dari:\n" << endl;
        fout << "Hasil Parsing Dari:\n";
        cout.fill(' ');
        cout << str << endl;
        fout << str << endl;
        bool isValid = parseForLoop(str);

        if (isValid) {
            cout.fill(' ');
            cout << "-------------------------------------------------------------------------------------------------- \n";
            cout << "Valid/ Diterima!" << endl;
            fout << "Valid/ Diterima!" << endl;
            cout << "-------------------------------------------------------------------------------------------------- \n";
        } else {
            cout.fill(' ');
            cout << "-------------------------------------------------------------------------------------------------- \n";
            cout << "Tidak Diterima/ Invalid!" << endl;
            fout << "Tidak Diterima/ Invalid!" << endl;
            cout << "-------------------------------------------------------------------------------------------------- \n";
        }
        string command = " ";

        while (command != "EXIT") {
            cout.fill(' ');
            cout.width(40);
            cout << "\n\n\t TULIS 'EXIT' UNTUK KELUAR DARI PROGRAM.\n\t NOTE: HASIL PROGRAM DAPAT DILIHAT PADA FILE 'OutputFile.txt' \n";
            cin.width(40);
            cin >> command;

            if (command == "exit" || command == "EXIT" || command == "Exit")
                break;
            else {
                cout.fill(' ');
                cout.width(40);
                cout << "Masukan kata yang benar.";
                cin.width(10);
                cin >> command;
            }
        }
    } else {
        cout.fill(' ');
        cout.width(40);
        cout << "\n FILE TIDAK DITEMUKAN!\n\n";
    }
    return 0;
}