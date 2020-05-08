// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        return binary_search(1, n);
    }
    int binary_search(int s, int e){
        if(s == e)
            return s;
        int mid = ((long long)s+e)/2;
        if(isBadVersion(mid))
            return binary_search(s, mid);
        else
            return binary_search(mid + 1, e);
    }
};