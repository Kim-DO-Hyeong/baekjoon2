#include <iostream>
#include <string.h>
 
using namespace std;
 
int N;
int map[2200][2200];
int answer[3];
 
bool allSameNumber(int x, int y, int n) {
    
    int check = map[x][y];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[x + i][y + j] != check) {
                return false;
            }
        }
    }
 
    return true;
}
 
void makePaper(int x, int y, int n) {
 
    if (allSameNumber(x, y, n)) {
        int paperNum = map[x][y];
        answer[paperNum + 1]++;
        return;
    }
 
    int div = n / 3;
 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            makePaper(x + div * i, y + div * j, div);
        }
    }
}
 
int main() {
 
    N = 0;
    memset(map, 0, sizeof(map));
    memset(answer, 0, sizeof(answer));
 
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
 
    makePaper(0, 0, N);
 
    for (int i = 0; i < 3; i++) {
        cout << answer[i] << "\n";
    }
 
    return 0;
}
