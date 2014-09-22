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
    //    outfiles << num1 << ' ' << num2 << ' ' << num3 << endl;
   //     outfiles << "Up:       " << u1 << ' ' << u2 << endl;
   //     outfiles << "Down:     " << d1 << ' ' << d2 << ' ' << d3 << endl;
		outfiles << u1 << ' ' << u2 << ' ' << 0 << ' ' << d1 << ' ' << d2 << ' ' << d3 << endl;
    }
};

map<int, status11> mp1;

double len1 = 4.61, len2 = 3.615, len3 = 4.63;


void get11(vector<status11> &vec) {
    double LEN = 22;
    //vector<status11> vec;

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


struct status22 {
    int uL1, uL2, uR1, uR2;
    int dL1, dL2, dR1, dR2;
    int num1, num2, num3;
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
      //  outfiles << num1 << ' ' << num2 << ' ' << num3 << endl;
      //  outfiles << "Up left:   " << uL1 << ' ' << uL2 << endl;

      //  outfiles << "Up right:  " << uR1 << ' ' << uR2 << endl;
      //  outfiles << "Down left: " << dL1 << ' ' << dL2 << endl;
      //  outfiles << "Down right:" << dR1 << ' ' << dR2 << endl;
		outfiles << uL1 + uR1 << ' ' << uL2 + uR2 << ' ' << 0 << ' ';
		outfiles << dL1 + dR1 << ' ' << dL2 + dR2 << ' ' << 0 << endl;
    }
};

map<int, status22> mp22;

void get22(vector<status22> &vec) {
    double LEN = 19;
    //vector<status12> vec;

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
    ofstream outfiles("2-2.txt");
    for (int i = 0; i < vec.size(); ++i) {
        vec[i].print(outfiles);
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
     //   outfiles << num1 << ' ' << num2 << ' ' << num3 << endl;
    //    outfiles << "Up left:   " << uL1 << ' ' << uL2 << endl;
    //    outfiles << "Up right:  " << uR1 << ' ' << uR2 << endl;
    //    outfiles << "Down:      " << d1 << ' ' << d2 << ' ' << d3 << endl;
	      outfiles << uL1 + uR1 << ' ' << uL2 + uR2 << ' ' << 0 << ' ';
	      outfiles << d1 << ' ' << d2 << ' ' << d3 << endl;
    }
};

map<int, status12> mp2;

void get12(vector<status12> &vec) {
    double LEN = 24.3;
    //vector<status12> vec;
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

struct Val {
    int val1, val2, val3;
    Val(int val1_, int val2_, int val3_):val1(val1_), val2(val2_), val3(val3_) {}
    Val():val1(inf), val2(inf), val3(inf) {}
};

bool operator< (const Val& lhs, const Val& rhs) {
    if (lhs.val1 + lhs.val2 + lhs.val3 == rhs.val1 + rhs.val2 + rhs.val3) {
        if (lhs.val1 == rhs.val1) {
            if (lhs.val2 == rhs.val2) {
                return lhs.val3 < rhs.val3;
            }
            return lhs.val2 < rhs.val2;
        }
        return lhs.val1 < rhs.val1;
    }
    return lhs.val1 + lhs.val2 + lhs.val3 < rhs.val1 + rhs.val2 + rhs.val3;
}


Val dp[180][120][60];
struct index {
    int type, d1, d2, d3;
    index() {}
    index(int type_, int d1_, int d2_, int d3_): type(type_), d1(d1_), d2(d2_), d3(d3_) {}
}nx[180][120][60];

void getAns(int X, int Y, int Z,  vector<status11> &vec1, vector<status12> &vec2, vector<status22> &vec22, int& ans_A, int& ans_B, int& ans_C) {

    Val tmp;

    int tX, tY, tZ;
    for (int x = 0; x < 180; ++x) {
        for (int y = 0; y < 120; ++y) {
            for (int z = 0; z < 60; ++z) {
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
            vec1.push_back(mp1[dx * 10000 + dy * 100 + dz]);
        } else if (type == 2) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec2.push_back(mp2[dx * 10000 + dy * 100 + dz]);
        } else if (type == 3) {
            int dx = x - x_, dy = y - y_, dz = z - z_;
            vec22.push_back(mp22[dx * 10000 + dy * 100 + dz]);
        }
        x = x_;
        y = y_;
        z = z_;
    }


    ans_A = tmp.val1;
    ans_B = tmp.val2;
    ans_C = tmp.val3;



}


int main() {

	freopen("表3.txt", "r", stdin);


	int vv2[] = {12, 17, 24, 25, 26, 31, 37};
	int vv3[] = {5, 20, 29, 40};

	int ind[50];
	for (int i = 0; i < 50; ++i) ind[i] = 1;
	for (int i = 0; i < 7; ++i) ind[vv2[i]] = 2;
	for (int i = 0; i < 4; ++i) ind[vv3[i]] = 3;

	int cnt1 = 0, cnt2 = 0, cnt3 = 0;

	for (int i = 1; i <= 45; ++i) {
		int x, y;
		cin >> x >> y;
		if (ind[i] == 1) cnt1++;
		if (ind[i] == 2) cnt2++;
		if (ind[i] == 3) cnt3++;
	}



    vector<status11> vec1;
    vector<status12> vec2;
    vector<status22> vec22;

    get11(vec1);
    get12(vec2);
    get22(vec22);

    for (int x = 0; x < 180; ++x) {
        for (int y = 0; y < 120; ++y) {
            for (int z = 0; z < 60; ++z) {
                if (x == 0 && y == 0 && z == 0) {
                    dp[x][y][z].val1 = 0;
                    dp[x][y][z].val2 = 0;
                    dp[x][y][z].val3 = 0;
                    continue;
                }
                dp[x][y][z] = Val();
                //1-1
                int sz;
                sz = vec1.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec1[i].num1, dy = vec1[i].num2, dz = vec1[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    Val tmp = dp[x - dx][y - dy][z - dz];
                    tmp.val1++;
                    if (tmp.val2 * 5 > tmp.val1) continue;
                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 1;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = tmp;
                    }
                }
                //1-2
    double len1 = 4.61, len2 = 3.615, len3 = 4.63;
                sz = vec2.size();
                for (int i = 0; i < sz; ++i) {
                    int dx = vec2[i].num1, dy = vec2[i].num2, dz = vec2[i].num3;
                    if (x - dx < 0 || y - dy < 0 || z - dz < 0) continue;
                    Val tmp = dp[x - dx][y - dy][z - dz];
                    tmp.val2++;
                    if (tmp.val2 * 5 > tmp.val1) continue;

                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 2;
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
                    tmp.val3++;
                    if (tmp.val2 * 5 > tmp.val1) continue;

                    if (tmp < dp[x][y][z]) {
                        nx[x][y][z].type = 3;
                        nx[x][y][z].d1 = x - dx;
                        nx[x][y][z].d2 = y - dy;
                        nx[x][y][z].d3 = z - dz;
                        dp[x][y][z] = tmp;
                    }
                }
            }
        }
    }

    int ans_A, ans_B, ans_C;
    vector<status11> v1;
    vector<status12> v2;
    vector<status22> v22;

    string fileName = "表4.txt";
    getAns(cnt1, cnt2, cnt2, v1, v2, v22, ans_A, ans_B, ans_C);
    ofstream os(fileName.c_str());
   // os << ans_A << ' ' << ans_B << ' ' << ans_C << endl;
    for (int i = 0; i < v1.size(); ++i) {
		if (i < 22) os << 3;
		else if (i < 32) os << 5;
		else if (i < 47) os << 4;
		else if (i < 63) os << 8;
		else if (i < 67) os << 3;
		os << ' ';
        v1[i].print(os);
    }
    for (int i = 0; i < v2.size(); ++i) {
		if (i < 15) os << 10;
		else os << 5;
		os << endl;
        v2[i].print(os);
    }
    for (int i = 0; i < v22.size(); ++i) {
		os << 9 << ' ';
        v22[i].print(os);
    }

    return 0;
}
