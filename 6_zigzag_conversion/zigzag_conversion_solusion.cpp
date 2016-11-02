#include <iostream>
#include <string>
#include <vector>

using namespace std;
class GenMatrixSolusion {
    public:
        static string convert(string s, int numRows) {
            string result = "";
            if(numRows<=0)
                return "";
            if(numRows==1)
                return s;
            int maxculs = s.length();
            char *matrix = new char[numRows*maxculs];
            memset(matrix, 0, numRows*maxculs);
            int strIndex = 0;
            int i = 0;
            int j = 0;
            bool down = true;
            while(strIndex< s.length()) {
                *(matrix+i*maxculs+j) = s.at(strIndex++);
                if(down) {
                    if(i == numRows-1) {
                        down = false;
                        i--;
                        j++;
                    }
                    else
                        i++;
                } else {
                    if(i == 0) {
                        down = true;
                        i++;
                    }
                    else {
                        i--;
                        j++;
                    }
                }
            }
            for(int n = 0; n< numRows; n++) {
                for(int m = 0; m< maxculs; m++) {
                    if(*(matrix+n*maxculs+m)>0)
                        result.append(1,*(matrix+n*maxculs+m));
                }
            }
            return result;
        }
};

int main() {
    //string s = "PAYPALISHIRING";
    //string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcoendtomfgdwdwfcgpxiqvkuytdlcgdewhtaciohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhl";
    string s = "A";
    std::cout << GenMatrixSolusion::convert(s, 2);
}
