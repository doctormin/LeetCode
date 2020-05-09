#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    int rectangleArea(vector<vector<int>> &rectangles)
    {
        set<int> SetX;
        set<int> SetY;
        //用来去重和排序
        for (const auto &point : rectangles)
        {
            SetX.insert(point[0]);
            SetX.insert(point[2]);
            SetY.insert(point[1]);
            SetY.insert(point[3]);
        }

        vector<int> X(SetX.begin(), SetX.end());
        vector<int> Y(SetY.begin(), SetY.end());

        int M = X.size();
        int N = Y.size();

        vector<vector<bool>> points(M, vector<bool>(N, 0));

        //左下闭合，右上开的打点
        for (const auto &p : rectangles)
        {
            int Ax = lower_bound(X.begin(), X.end(), p[0]) - X.begin();
            int Ay = lower_bound(Y.begin(), Y.end(), p[1]) - Y.begin();
            int Bx = lower_bound(X.begin(), X.end(), p[2]) - X.begin();
            int By = lower_bound(Y.begin(), Y.end(), p[3]) - Y.begin();
            for (int i = Ax; i < Bx; i++)
            {
                for (int j = Ay; j < By; j++)
                {
                    points[i][j] = 1;
                }
            }
        }
        long long unsigned result = 0;
        int Mod = 1e9+7;
        for (int i = 0; i < M - 1; i++)
        {
            for (int j = 0; j < N - 1; j++)
            {
                if (points[i][j] == 0)
                    continue;
                result += (long long unsigned)(X[i + 1] - X[i]) * (long long unsigned)(Y[j + 1] - Y[j]);
                result = result%Mod;
            }

        }
        return result;
    }
};