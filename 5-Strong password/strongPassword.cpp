#include <string>
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    
    bool foundDigit=false, foundLowerCase=false, foundUpperCase=false, foundSpecial=false;
    int help=4;
    
    for (char c : password) {
        if (numbers.find(c) != string::npos && foundDigit==false) {
           foundDigit=true; help--;
        }
        else if (lower_case.find(c) != string::npos && foundLowerCase==false) {
           foundLowerCase=true; help--;
        }
        else if (upper_case.find(c) != string::npos && foundUpperCase==false) {
           foundUpperCase=true; help--;
        }
        else if (special_characters.find(c) != string::npos && foundSpecial==false) {
           foundSpecial=true; help--;
        }
    }
    if (n>=6) return help;
    else if ((6-n) < help) return help;
    else return 6-n;
}