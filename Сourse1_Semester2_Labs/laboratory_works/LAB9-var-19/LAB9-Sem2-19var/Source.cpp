#include <iostream>
#include <fstream>
#include <string>
#include <codecvt>
#include <windows.h>

wchar_t consonants[84] = {
    L'b',L'c',L'd',L'f',L'g',L'h',L'j',L'k',L'l',L'm',
    L'n',L'p',L'q',L'r',L's',L't',L'v',L'w',L'x',L'y',L'z',

    L'B',L'C',L'D',L'F',L'G',L'H',L'J',L'K',L'L',L'M',
    L'N',L'P',L'Q',L'R',L'S',L'T',L'V',L'W',L'X',L'Y',L'Z',

    L'á',L'â',L'ã',L'ä',L'æ',L'ç',L'é',L'ê',L'ë',L'ì',
    L'í',L'ï',L'ð',L'ñ',L'ò',L'ô',L'õ',L'ö',L'÷',L'ø',L'ù',

    L'Á',L'Â',L'Ã',L'Ä',L'Æ',L'Ç',L'É',L'Ê',L'Ë',L'Ì',
    L'Í',L'Ï',L'Ð',L'Ñ',L'Ò',L'Ô',L'Õ',L'Ö',L'×',L'Ø',L'Ù'
};

int main() {

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::ifstream in("F1.txt");
    std::ofstream out("F2.txt");
    std::string s;

    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    std::wstring ws = conv.from_bytes(s);

    while (getline(in, s)) {
        int i = 0;
        std::string temps = "";
        while (s[i] != ' ' && (i != s.length())) {
            temps += s[i];
            i++;
        }
        std::cout << temps;
        bool f = true;

        //std::cout << temps << '\n';
        //std::cout << s << '\n';
        std::string wordbe = "";
        while (i != (s.length()+1)) {
            if (s[i] == ' ' || i == s.length()) {
                std::cout << wordbe << ' ';
                if (temps == wordbe) {
                    f = false;
                    break;
                }
                wordbe = "";
                i++;
            }
            else {
                wordbe += s[i];
                i++;
            }
        }
        std::cout << std::endl;

        if (f) {
            out << s << '\n';
        }
    }

    out.close();
    std::cout << "============================\n";
    std::ifstream res("F2.txt");

    int counter = 0;
    if (getline(res, s)) {
        for (int i = 0; i < s.length(); i++) {
            for (int k = 0; k < 84; k++) {
                if (s[i] == consonants[k]) {
                    counter++;
                    break;
                }
            }
        }
    }

    std::cout << counter << '\n' << s << '\n';
    while (getline(res, s)) {
        std::cout << s << '\n';
    }

    return 0;
}