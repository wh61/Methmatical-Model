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
    int type;
    status11() {}
    status11(int u1_, int u2_, int d1_, int d2_, int d3_, int type_)
        :u1(u1_), u2(u2_), d1(d1_), d2(d2_), d3(d3_), type(type_) {
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

struct status12 {
    int uL1, uL2, uR1, uR2;
    int d1, d2, d3;
    int num1, num2, num3;
    int type;
    status12() {}
    status12(int uL1_, int uL2_, int uR1_, int uR2_, int d1_, int d2_, int d3_)
        :uL1(uL1_), uL2(uL2_), uR1(uR1_), uR2(uR2_), d1(d1_), d2(d2_), d3(d3_) {
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

struct status22 {
    int uL1, uL2, uR1, uR2;
    int dL1, dL2, dR1, dR2;
    int num1, num2, num3;
    int type;
    status22() {}
    status22(int uL1_, int uL2_, int uR1_, int uR2_, int dL1_, int dL2_, int dR1_, int dR2_)
        :uL1(uL1_), uL2(uL2_), uR1(uR1_), uR2(uR2_), dL1(dL1_), dL2(dL2_), dR1(dR1_), dR2(dR2_) {
        num1 = uL1 + uR1 + dL1 + dR1;
        num2 = uL2 + uR2 + dL2 + dR2;
        num3 = 0;
    }
    int toHash() {
        return num1 * 10000 + num2 * 100 + num3;
    }
    void print(ofstream &outfiles) {
        outfiles << num1 << ' ' << num2 << ' ' << num3 << endl;
        outfiles << "Up left:   " << uL1 << ' ' << uL2 << endl;
        outfiles << "Up right:  " << uR1 << ' ' << uR2 << endl;
        outfiles << "Down left: " << dL1 << ' ' << dL2 << endl;
        outfiles << "Down right:" << dR1 << ' ' << dR2 << endl;
    }
};


const double len1 = 4.618636364, len2 = 3.639, len3 = 4.596285714;


map<int, status11> mp11_1;
map<int, status11> mp11_2;
map<int, status11> mp11_3;

void get11(vector<status11> &vec, double LEN, int type) {
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

                        int tmp = status11(u1, u2, d1, d2, d3, type).toHash();

                        if (hs.find(tmp) == hs.end()) {
                            vec.push_back(status11(u1, u2, d1, d2, d3, type));
                            hs.insert(tmp);
                            map<int, status11> *p;
                            if (type == 1) p = &mp11_1;
                            if (type == 2) p = &mp11_2;
                            if (type == 3) p = &mp11_3;
                            (*p)[tmp] = status11(u1, u2, d1, d2, d3, type);
                        }
                    }
                }
            }
        }
    }
}

map<int, status12> mp12;

void get12(vector<status12> &vec, double LEN) {
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
                                    mp12[tmp] = status12(uL1, uL2, uR1, uR2, d1, d2, d3);

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

map<int, status22> mp22;

void get22(vector<status22> &vec, double LEN) {
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
                    for (int dL1 = 0; dL1 < 8; ++dL1) {
                        for (int dL2 = 0; dL2 < 8; ++dL2) {

                            double dLnowLen = len1 * dL1 + len2 * dL2 + (dL1 + dL2 - 1) * 0.1;
                            if (dLnowLen > LEN) continue;
                            if (dLnowLen + len1 + 0.1 <= LEN) continue;
                            if (dLnowLen + len2 + 0.1 <= LEN) continue;

                            for (int dR1 = 0; dR1 < 8; ++dR1) {
                                for (int dR2 = 0; dR2 < 8; ++dR2) {
                                    double dRnowLen = len1 * dR1 + len2 * dR2 + (dR1 + dR2 - 1) * 0.1;
                                    if (dRnowLen > LEN) continue;
                                    if (dRnowLen + len1 + 0.1 <= LEN) continue;
                                    if (dRnowLen + len2 + 0.1 <= LEN) continue;

                                    int tmp = status22(uL1, uL2, uR1, uR2, dL1, dL2, dR1, dR2).toHash();
                                    if (hs.find(tmp) == hs.end()) {
                                        vec.push_back(status22(uL1, uL2, uR1, uR2, dL1, dL2, dR1, dR2));
                                        hs.insert(tmp);
                                        mp22[tmp] = status22(uL1, uL2, uR1, uR2, dL1, dL2, dR1, dR2);
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}




const int max11_1 = 64, max11_2 = 35, max11_3 = 22;
const int max12 = 25, max22 = 5;

struct Val {
    int val11_1, val11_2, val11_3, val12, val22;
    Val(int val11_1_, int val11_2_, int val11_3_, int val12_,  int val22_)
        :val11_1(val11_1_), val11_2(val11_2_), val11_3(val11_3_), val12(val12_), val22(val22_) {}
    Val()
        :val11_1(inf), val11_2(inf), val11_3(inf), val12(inf), val22(inf) {}


    bool isValid() {
        return val11_1 <= max11_1 && val11_2 <= max11_2 && val11_3 <= max11_3 && val12 < max12 && val22 < max22;
    }


};


bool operator< (const Val& lhs, const Val& rhs) {
    if (lhs.val11_1 + lhs.val11_2 + lhs.val11_3 + lhs.val12 + lhs.val22 == rhs.val11_1 + rhs.val11_2 + rhs.val11_3 + rhs.val12 + rhs.val22) {
        if (lhs.val11_1 + lhs.val11_2 + lhs.val11_3 == rhs.val11_1 + rhs.val11_2 + rhs.val11_3) {
            if (lhs.val12 == rhs.val12) {
                return lhs.val22 < rhs.val22;
            }
            return lhs.val12 < rhs.val12;
        }
        return lhs.val11_1 + lhs.val11_2 + lhs.val11_3 < rhs.val11_1 + rhs.val11_2 + rhs.val11_3;
    }
    return lhs.val11_1 + lhs.val11_2 + lhs.val11_3 + lhs.val12 + lhs.val22 < rhs.val11_1 + rhs.val11_2 + rhs.val11_3 + rhs.val12 + rhs.val22;
}


const size_t maxI = 400, maxII = 150, maxIII = 100;

Val dp[maxI][maxII][maxIII];

struct index {
    int type, d1, d2, d3;
    index() {}
    index(int type_, int d1_, int d2_, int d3_): type(type_), d1(d1_), d2(d2_), d3(d3_) {}
}nx[maxI][maxII][maxIII];

void getAns(int X, int Y, int Z,
    vector<status11> &vec11_1,
    vector<status11> &vec11_2,
    vector<status11> &vec11_3,
    vector<status12> &vec12,
    vector<status22> &vec22,
    int& ans_11_1, int& ans_11_2, int& ans_11_3, int& ans_12, int& ans_22) {

    Val tmp;
    int tX, tY, tZ;
    for (int x = 0; x < maxI; ++x) {
        for (int y = 0; y < maxII; ++y) {
            for (int z = 0; z < maxIII; ++z) {
                if (x >= X && y >= Y && z >= Z) {
                    if (dp[x][y][z] < tmp) {
                        tmp = dp[x][y][z];
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
            vec11_1.push_back(mp11_1[dx * 10000 + dy * 100 + dz]);
        } else if (type == 2) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec11_2.push_back(mp11_2[dx * 10000 + dy * 100 + dz]);
        } else if (type == 3) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec11_3.push_back(mp11_3[dx * 10000 + dy * 100 + dz]);
        } else if (type == 4) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec12.push_back(mp12[dx * 10000 + dy * 100 + dz]);
        } else if (type == 5) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec22.push_back(mp22[dx * 10000 + dy * 100 + dz]);
        }
        x = x_;
        y = y_;
        z = z_;
    }
    ans_11_1 = tmp.val11_1;
    ans_11_2 = tmp.val11_2;
    ans_11_3 = tmp.val11_3;
    ans_12 = tmp.val12;
    ans_22 = tmp.val22;
}



int typeOfCar[55];
int type2[] = {1, 12, 17, 24, 25, 26, 31, 37};
int type3[] = {5, 20, 29, 40};

int main() {

    for (int i = 0; i < 55; ++i) typeOfCar[i] = 1;
    for (int i = 0; i < 8; ++i) {
        typeOfCar[type2[i]] = 2;
    }
    for (int i = 0; i < 4; ++i) {
        typeOfCar[type3[i]] = 3;
    }

    int cnt[4];
    memset(cnt, 0 ,sizeof(cnt));

    ifstream in("input.txt");
    for (int i = 1; i <= 45; ++i) {
        int tmp;
        in >> tmp;
        cnt[typeOfCar[i]] += tmp;
    }

    int I = cnt[1], II = cnt[2], III = cnt[3];

    vector<status11> vec11_1;
    vector<status11> vec11_2;
    vector<status11> vec11_3;
    vector<status12> vec12;
    vector<status22> vec22;

    get11(vec11_1, 18.5, 1);
    get11(vec11_2, 21.333, 2);
    get11(vec11_3, 24.3, 3);
    get12(vec12, 23.5);
    get22(vec22, 19);

    for (int x = 0; x < maxI; ++x) {
        for (int y = 0; y < maxII; ++y) {
            for (int z = 0; z < maxIII; ++z) {
                if (x == 0 && y == 0 && z == 0) {
                    dp[x][y][z].val11_1 = 0;
                    dp[x][y][z].val11_2 = 0;
                    dp[x][y][z].val11_3 = 0;
                    dp[x][y][z].val12 = 0;
                    dp[x][y][z].val22 = 0;
                    continue;
                }
                dp[x][y][z] = Val();
                size_t sz;
                //11_1
                sz = vec11_1.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec11_1[i].num1, dy = vec11_1[i].num2, dz = vec11_1[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    Val tmp = dp[x - dx][y - dy][z - dz];
                    tmp.val11_1++;
                    if (tmp.val12 * 5 > tmp.val11_1 + tmp.val11_2 + tmp.val11_3) continue;
                    if (tmp.isValid() == false) continue;
                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 1;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = tmp;
                    }
                }

                sz = vec11_2.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec11_2[i].num1, dy = vec11_2[i].num2, dz = vec11_2[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    Val tmp = dp[x - dx][y - dy][z - dz];
                    tmp.val11_2++;
                    if (tmp.val12 * 5 > tmp.val11_1 + tmp.val11_2 + tmp.val11_3) continue;
                    if (tmp.isValid() == false) continue;
                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 2;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = tmp;
                    }
                }

                sz = vec11_3.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec11_3[i].num1, dy = vec11_3[i].num2, dz = vec11_3[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    Val tmp = dp[x - dx][y - dy][z - dz];
                    tmp.val11_3++;
                    if (tmp.val12 * 5 > tmp.val11_1 + tmp.val11_2 + tmp.val11_3) continue;
                    if (tmp.isValid() == false) continue;
                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 3;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = tmp;
                    }
                }


                //1-2
                sz = vec12.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec12[i].num1, dy = vec12[i].num2, dz = vec12[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    Val tmp = dp[x - dx][y - dy][z - dz];
                    tmp.val12++;
                    if (tmp.val12 * 5 > tmp.val11_1 + tmp.val11_2 + tmp.val11_3) continue;
                    if (tmp.isValid() == false) continue;
                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 4;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = tmp;
                    }
                }

                //2-2
                sz = vec22.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec22[i].num1, dy = vec22[i].num2, dz = vec22[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    Val tmp = dp[x - dx][y - dy][z - dz];
                    tmp.val22++;
                    if (tmp.val22 * 5 > tmp.val11_1 + tmp.val11_2 + tmp.val11_3) continue;
                    if (tmp.isValid() == false) continue;
                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 5;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = tmp;
                    }
                }
            }
        }
    }

    int ans_11_1, ans_11_2, ans_11_3;
    int ans_12, ans_22;

    vector<status11> v11_1;
    vector<status11> v11_2;
    vector<status11> v11_3;
    vector<status12> v12;
    vector<status22> v22;


    getAns(I, II, III, v11_1, v11_2, v11_3, v12, v22, ans_11_1, ans_11_2, ans_11_3, ans_12, ans_22);

    string fileName = "output.txt";

    ofstream os(fileName.c_str());

    os << "number of 1-1 type 1: " << ans_11_1 << endl;
    os << "number of 1-1 type 2: " << ans_11_2 << endl;
    os << "number of 1-1 type 3: " << ans_11_3 << endl;
    os << "number of 1-2:        " << ans_12 << endl;
    os << "number of 2-2:        " << ans_22 << endl;
    os << endl << "1-1 type 1 plan: " << endl;
    for (int i = 0; i < v11_1.size(); ++i) {
        v11_1[i].print(os);
    }
    os << endl << "1-1 type 2 plan: " << endl;
    for (int i = 0; i < v11_2.size(); ++i) {
        v11_2[i].print(os);
    }
    os << endl << "1-1 type 3 plan: " << endl;
    for (int i = 0; i < v11_3.size(); ++i) {
        v11_3[i].print(os);
    }
    os << endl << "1-2 plan: " << endl;
    for (int i = 0; i < v12.size(); ++i) {
        v12[i].print(os);
    }
    os << endl << "2-2 plan: " << endl;
    for (int i = 0; i < v22.size(); ++i) {
        v22[i].print(os);
    }

    return 0;
}
