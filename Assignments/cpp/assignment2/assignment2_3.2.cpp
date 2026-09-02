#include <iostream>
using namespace std;

namespace Physics {
    double clamp(double val, double min, double max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }

    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

namespace GameMath {
    
    int clamp(int val, int min, int max) {
        if (val < min) return min;
        if (val > max) return max;
        return val;
    }
    double lerp(double a, double b, double t) {
        return a + (b - a) * t;
    }
}

int main() {
    
    double velocity = Physics::clamp(150.5, 0.0, 100.0);
    cout << "Physics::clamp(150.5, 0, 100) = " << velocity << endl;

    double physicsLerp = Physics::lerp(0.0, 10.0, 0.5);
    cout << "Physics::lerp(0, 10, 0.5) = " << physicsLerp << endl;

    int health = GameMath::clamp(120, 0, 100);
    cout << "GameMath::clamp(120, 0, 100) = " << health << endl;

    double uiLerp = GameMath::lerp(0.0, 1.0, 0.25);
    cout << "GameMath::lerp(0, 1, 0.25) = " << uiLerp << endl;

    {
        using namespace GameMath;
        int level = clamp(15, 1, 10);  
        cout << "\n[Inside block scope with 'using namespace GameMath']" << endl;
        cout << "clamp(15, 1, 10) = " << level << endl;
    }
    
    return 0;
}