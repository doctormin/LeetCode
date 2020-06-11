class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool flag = false;
        int l1 = ransomNote.length();
        int l2 = magazine.length();
        if(l2 == 0){
            return l1 == 0;
        }
        bool used[l2];
        for(int i = 0; i < l2; i++){
            used[i] = 0;
        }
        for(auto &r : ransomNote){
            flag = false;
            for(int i = 0; i < l2; i++){
                if(r == magazine[i] && used[i] != 1) {
                    flag = true;
                    used[i] = 1;
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
};