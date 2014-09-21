#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <fstream>
#include <map>
#include <set>

using namespace std;





const int inf = 1000000;


struct status11 {
    int u1, u2;
    int d1, d2, d3;
    int num1, num2, num3;
    status11() {}
    status11(int u1_, int u2_, int d1_, int d2_, int d3_):u1(u1_), u2(u2_), d1(d1_), d2(d2_), d3(d3_) {
        num1 = u1 + d1;
        num2 = u2 + d2;
        num3 = d3;
    }
    int toHash() {
        return num1 * 10000 + num2 * 100 + num3;
    }
    void print(ofstream &outfiles) {
        outfiles << num1 << ' ' << num2 << ' ' << num3 << endl;
        outfiles << "Up:       " << u1 << ' ' << u2 << endl;
        outfiles << "Down:     " << d1 << ' ' << d2 << ' ' << d3 << endl;
    }
};

map<int, status11> mp1;

void get11(vector<status11> &vec) {
    double LEN = 19;
    //vector<status11> vec;
    double len1 = 4.61, len2 = 3.615, len3 = 4.63;
    set<int> hs;
    hs.clear();
    for (int u1 = 0; u1 < 8; ++u1) {
        for (int u2 = 0; u2 < 8; ++u2) {
            double uNowLen = u1 * len1 + u2 * len2 + (u1 + u2 - 1) * 0.1;
            if (uNowLen > LEN) continue;
            if (uNowLen + len1 + 0.1 <= LEN) continue;
            if (uNowLen + len2 + 0.1 <= LEN) continue;
            for (int d1 = 0; d1 < 8; ++d1) {
                for (int d2 = 0; d2 < 8; ++d2) {
                    for (int d3 = 0; d3 < 8; ++d3) {
                        double dNowLen = len1 * d1 + len2 * d2 + len3 * d3 + (d1 + d2 + d3 - 1) * 0.1;
                        if (dNowLen > LEN) continue;
                        if (dNowLen + len1 + 0.1 <= LEN) continue;
                        if (dNowLen + len2 + 0.1 <= LEN) continue;
                        if (dNowLen + len3 + 0.1 <= LEN) continue;

                        int tmp = status11(u1, u2, d1, d2, d3).toHash();

                        if (hs.find(tmp) == hs.end()) {
                            vec.push_back(status11(u1, u2, d1, d2, d3));
                            hs.insert(tmp);
                            mp1[tmp] = status11(u1, u2, d1, d2, d3);
                        }
                    }
                }
            }
        }
    }
    ofstream outfiles("1-1.txt");
    for (int i = 0; i < vec.size(); ++i) {
        vec[i].print(outfiles);
        outfiles << endl;
    }
}



struct status12 {
    int uL1, uL2, uR1, uR2;
    int d1, d2, d3;
    int num1, num2, num3;
    status12() {}
    status12(int uL1_, int uL2_, int uR1_, int uR2_, int d1_, int d2_, int d3_):uL1(uL1_), uL2(uL2_), uR1(uR1_), uR2(uR2_), d1(d1_), d2(d2_), d3(d3_) {
        num1 = uL1 + uR1 + d1;
        num2 = uL2 + uR2 + d2;
        num3 = d3;
    }
    int toHash() {
        return num1 * 10000 + num2 * 100 + num3;
    }
    void print(ofstream &outfiles) {
        outfiles << num1 << ' ' << num2 << ' ' << num3 << endl;
        outfiles << "Up left:   " << uL1 << ' ' << uL2 << endl;
        outfiles << "Up right:  " << uR1 << ' ' << uR2 << endl;
        outfiles << "Down:      " << d1 << ' ' << d2 << ' ' << d3 << endl;
    }
};

map<int, status12> mp2;
ofstream os("debug.txt");

void get12(vector<status12> &vec) {
    double LEN = 24.3;
    //vector<status12> vec;
    double len1 = 4.61, len2 = 3.615, len3 = 4.63;

    set<int> hs;
    hs.clear();
    for (int uL1 = 0; uL1 < 8; ++uL1) {
        for (int uL2 = 0; uL2 < 8; ++uL2) {
            double uLnowLen = uL1 * len1 + uL2 * len2 + (uL1 + uL2 - 1) * 0.1;
            if (uLnowLen > LEN) continue;
            if (uLnowLen + len1 + 0.1 <= LEN) continue;
            if (uLnowLen + len2 + 0.1 <= LEN) continue;
            for (int uR1 = 0; uR1 < 8; ++uR1) {
                for (int uR2 = 0; uR2 < 8; ++uR2) {
                    double uRnowLen = uR1 * len1 + uR2 * len2 + (uR1 + uR2 - 1) * 0.1;
                    if (uRnowLen > LEN) continue;
                    if (uRnowLen + len1 + 0.1 <= LEN) continue;
                    if (uRnowLen + len2 + 0.1 <= LEN) continue;
                    for (int d1 = 0; d1 < 8; ++d1) {
                        for (int d2 = 0; d2 < 8; ++d2) {
                            for (int d3 = 0; d3 < 8; ++d3) {
                                double dNowLen = len1 * d1 + len2 * d2 + len3 * d3 + (len1 + len2 + len3 - 1) * 0.1;
                                if (dNowLen > LEN) continue;
                                if (dNowLen + len1 + 0.1 <= LEN) continue;
                                if (dNowLen + len2 + 0.1 <= LEN) continue;
                                if (dNowLen + len3 + 0.1 <= LEN) continue;
                                int tmp = status12(uL1, uL2, uR1, uR2, d1, d2, d3).toHash();
                                if (hs.find(tmp) == hs.end()) {
                                    vec.push_back(status12(uL1, uL2, uR1, uR2, d1, d2, d3));
                                    hs.insert(tmp);
                                    mp2[tmp] = status12(uL1, uL2, uR1, uR2, d1, d2, d3);

                                //    mp2[tmp].print(os);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ofstream outfiles("1-2.txt");
    for (int i = 0; i < vec.size(); ++i) {
        vec[i].print(outfiles);
    }
}


pair<int, int> dp[170][120][50];
struct index {
    int type, d1, d2, d3;
    index() {}
    index(int type_, int d1_, int d2_, int d3_): type(type_), d1(d1_), d2(d2_), d3(d3_) {}
}nx[170][120][50];

void getAns(int X, int Y, int Z,  vector<status11> &vec1, vector<status12> &vec2, int& ans_A, int& ans_B) {

    pair<int, int> pr = make_pair(inf, inf);

    int tX, tY, tZ;
    for (int x = 0; x < 170; ++x) {
        for (int y = 0; y < 120; ++y) {
            for (int z = 0; z < 50; ++z) {
                if (x >= X && y >= Y && z >= Z) {
                    if (dp[x][y][z] < pr) {
                        pr = dp[x][y][z];
                        tX = x;
                        tY = y;
                        tZ = z;
                    }
                }
            }
        }
    }

    int x = tX, y = tY, z = tZ;
    while (!(x == 0 && y == 0 && z == 0)) {
        int x_ = nx[x][y][z].d1, y_ = nx[x][y][z].d2, z_ = nx[x][y][z].d3;
        int type = nx[x][y][z].type;
        if (type == 1) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec1.push_back(mp1[dx * 10000 + dy * 100 + dz]);
        } else if (type == 2) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec2.push_back(mp2[dx * 10000 + dy * 100 + dz]);
        }
        x = x_;
        y = y_;
        z = z_;
    }


    ans_A = (pr.first) - (pr.second);
    ans_B = pr.second;



}


int main() {
    vector<status11> vec1;
    vector<status12> vec2;

    get11(vec1);
    get12(vec2);





    for (int x = 0; x < 170; ++x) {
        for (int y = 0; y < 120; ++y) {
            for (int z = 0; z < 50; ++z) {
                if (x == 0 && y == 0 && z == 0) {
                    dp[x][y][z] = make_pair(0, 0);
                    continue;
                }
                dp[x][y][z] = make_pair(inf, inf);
                //1-1
                int sz;
                sz = vec1.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec1[i].num1, dy = vec1[i].num2, dz = vec1[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    pair<int, int> pr = dp[x - dx][y - dy][z - dz];
                    pr.first++;
                    if (pr.second * 6 > pr.first) continue;
                    if (pr < dp[x][y][z]) {
                        nx[x][y][z].type = 1;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = pr;
                    }
                }
                sz = vec2.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec2[i].num1, dy = vec2[i].num2, dz = vec2[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    pair<int, int> pr = dp[x - dx][y - dy][z - dz];
                    pr.first++;
                    pr.second++;
                    if (pr.second * 6 > pr.first) continue;
                    if (pr < dp[x][y][z]) {
                        nx[x][y][z].type = 2;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = pr;
                    }
                }
            }
        }
    }



    int ans_A, ans_B;
    vector<status11> v1;
    vector<status12> v2;
    string fileName = "100 68 0.txt";
    getAns(100, 68, 0, v1, v2, ans_A, ans_B);
    ofstream os(fileName.c_str());
    os << ans_A << ' ' << ans_B << endl;
    for (int i = 0; i < v1.size(); ++i) {
        v1[i].print(os);
    }
    for (int i = 0; i < v2.size(); ++i) {
        v2[i].print(os);
    }


    return 0;
}
