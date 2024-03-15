string caesarCipher(string s, int k) {
    k = k % 26;
    
    for (char& c : s) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (((c - base) + k) % 26) + base;
        }
    }
    return s;
}
