#include <iostream>

#define BIT(n)       (1ULL << (n)) // 1ULL代表ULL类型的数1

using std::cout;

enum ELayoutHints {
    kLHintsNoHints = 0,
    kLHintsLeft    = BIT(0),
    kLHintsCenterX = BIT(1),
    kLHintsRight   = BIT(2),
    kLHintsTop     = BIT(3),
    kLHintsCenterY = BIT(4),
    kLHintsBottom  = BIT(5),
    kLHintsExpandX = BIT(6),
    kLHintsExpandY = BIT(7),
    kLHintsNormal  = (kLHintsLeft | kLHintsTop)
    // bits 8-11 used by ETableLayoutHints
 };


 int main(int argc, char const *argv[])
 {
     cout << "kLHintsNoHints = " << kLHintsNoHints << "\n";
     cout << "kLHintsLeft = " << kLHintsLeft << "\n";
     cout << "kLHintsCenterX = " << kLHintsCenterX << "\n";
     cout << "kLHintsRight = " << kLHintsRight << "\n";
     cout << "kLHintsTop = " << kLHintsTop << "\n";
     cout << "kLHintsCenterY = " << kLHintsCenterY << "\n";
     cout << "kLHintsBottom = " << kLHintsBottom << "\n";
     cout << "kLHintsExpandX = " << kLHintsExpandX << "\n";
     cout << "kLHintsExpandY = " << kLHintsExpandY << "\n";
     cout << "kLHintsNormal = " << kLHintsNormal << "\n";

     int a = 1ULL<<1;
     cout << "1ULL = " << 1ULL << "\n";
     cout << "1ULL << 1 = " << a << "\n";
     return 0;
 }

// 1ULL的含义？也可以有2ULL等
