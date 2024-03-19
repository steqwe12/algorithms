class Solution {
public:
    int compress(vector<char>& chars) {
        int i=chars.size()-1;
        int j=i;
        int num=0;
        while(j>=0 && i>=0){
            if(chars[j]==chars[i] && i>0){
                i--;
            }
            else if(i==0 && j-i>0 && chars[i]==chars[j]){
                i--;

                num=j-i;
                //chars.erase(chars.begin() + 2);
                if(num<=9){
                    chars[i+2]='0' + static_cast<char>(num);
                    for(int k=j;k>i+2;k--) chars.erase(chars.begin() + k);
                }
                else if(num<=99){
                    chars[i+2]='0' + static_cast<char>(num/10);
                    chars[i+3]='0' + static_cast<char>(num%10);
                    for(int k=j;k>i+3;k--) chars.erase(chars.begin() + k);
                }
                else if(num<=999){
                    chars[i+2]='0' + static_cast<char>(num/100);
                    chars[i+3]='0' + static_cast<char>((num/10)%10);
                    chars[i+4]='0' + static_cast<char>(num%10);
                    for(int k=j;k>i+4;k--) chars.erase(chars.begin() + k);
                }
                else { // 1000<=num<=2000
                    chars[i+2]='0' + static_cast<char>(num/1000);
                    chars[i+3]='0' + static_cast<char>((num/100)%10);
                    chars[i+4]='0' + static_cast<char>((num/10)%10);
                    chars[i+5]='0' + static_cast<char>(num%10);
                    for(int k=j;k>i+5;k--) chars.erase(chars.begin() + k);
                }

                j=i;
            }
            else if(j-i>1){
                num=j-i;
                //chars.erase(chars.begin() + 2);
                if(num<=9){
                    chars[i+2]='0' + static_cast<char>(num);
                    for(int k=j;k>i+2;k--) chars.erase(chars.begin() + k);
                }
                else if(num<=99){
                    chars[i+2]='0' + static_cast<char>(num/10);
                    chars[i+3]='0' + static_cast<char>(num%10);
                    for(int k=j;k>i+3;k--) chars.erase(chars.begin() + k);
                }
                else if(num<=999){
                    chars[i+2]='0' + static_cast<char>(num/100);
                    chars[i+3]='0' + static_cast<char>((num/10)%10);
                    chars[i+4]='0' + static_cast<char>(num%10);
                    for(int k=j;k>i+4;k--) chars.erase(chars.begin() + k);
                }
                else { // 1000<=num<=2000
                    chars[i+2]='0' + static_cast<char>(num/1000);
                    chars[i+3]='0' + static_cast<char>((num/100)%10);
                    chars[i+4]='0' + static_cast<char>((num/10)%10);
                    chars[i+5]='0' + static_cast<char>(num%10);
                    for(int k=j;k>i+5;k--) chars.erase(chars.begin() + k);
                }

                j=i;
            }
            else {
                j--;
            }
        }

        chars.shrink_to_fit();
        return chars.size();
    }
};