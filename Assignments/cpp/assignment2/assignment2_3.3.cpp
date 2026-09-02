#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int level = 1;

namespace Engine {
    namespace Audio {
        void playSound(const string& name) {
            cout << "Playing: " << name << endl;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int R, C;
    cout << "Enter number of rows (R): ";
    cin >> R;
    cout << "Enter number of columns (C): ";
    cin >> C;

    int** map = new int*[R];
    for (int i = 0; i < R; i++) {
        map[i] = new int[C];
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] = rand() % 5;
        }
    }

    cout << "\n===== GAME MAP (" << R << " x " << C << ") =====" << endl;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLegend:" << endl;
    cout << "0=Grass" << endl;
    cout << "1=Water" << endl;
    cout << "2=Mountain" << endl;
    cout << "3=Forest" << endl;
    cout << "4=Dungeon" << endl;

    int grass = 0, water = 0, mountain = 0, forest = 0, dungeon = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            switch (map[i][j]) {
                case 0: grass++;    break;
                case 1: water++;    break;
                case 2: mountain++; break;
                case 3: forest++;   break;
                case 4: dungeon++;  break;
            }
        }
    }

    cout << "\nTile Count:" << endl;
    cout << "Grass    : " << grass << endl;
    cout << "Water    : " << water << endl;
    cout << "Mountain : " << mountain << endl;
    cout << "Forest   : " << forest << endl;
    cout << "Dungeon  : " << dungeon << endl;

    for (int i = 0; i < R; i++) {
        delete[] map[i];
    }
    delete[] map;

    int level = 5;

    cout << "\n----- Scope Resolution Demo -----" << endl;
    cout << "Local level (player)   : " << level << endl;
    cout << "Global level (::level) : " << ::level << endl;

    cout << "\n----- Namespace Demo -----" << endl;
    Engine::Audio::playSound("sword_clash");

    return 0;
}