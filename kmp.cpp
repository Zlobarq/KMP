#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char *argv[]) {
    string String;
    cout << "Enter String: ";
    getline (cin, String);
    string Pattern;
    cout << "Enter Pattern: ";
    getline (cin, Pattern);
    int stringlen = String.length();
    int patternlen = Pattern.length();
    int Table[patternlen];
    Table[0] = 0;
    Table[1] = 0;
    int i = 1, j = 0;
    while (i < patternlen - 1) {
        if (Pattern[i] == Pattern[j]) {
            Table[++i] = ++j;
        } else if (j == 0) {
            Table[++i] = 0;
        } else {
            j = Table[j];
        }
    }
    i = j = 0;
    while (i < stringlen) {
        if (String[i] == Pattern[j]) {
            ++i;
            if (++j == patternlen) {
                i -= patternlen;
                break;
            }
        } else if (j == 0) {
            ++i;
        } else {
            j = Table[j];
        }
    }
    if (j == patternlen) {
        std::cout << "Found at position " << i <<"\n";
    } else {
        std::cout << "Not found." << "\n";
    }
}