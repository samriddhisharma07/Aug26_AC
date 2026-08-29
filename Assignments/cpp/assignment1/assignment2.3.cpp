#include <iostream>
using namespace std;

int main(){
    int statusReg = 0b10110001;    // Read-only from firmware side
    int controlReg = 0b00000000;   // Firmware writes here
    int dataReg = 0b11001010;      // For reassignment demo

    // ---- regPtr1: const int* (pointer to const int) ----
    // Value cannot be changed through this pointer, but pointer can repoint
    const int* regPtr1 = &statusReg;
    cout << "regPtr1 (statusReg) value: " << *regPtr1 << endl;

    //*regPtr1 = 5;  
    // ERROR: cannot modify *regPtr1 because it points to a const int.
    // This correctly enforces "read-only" access to the status register —
    // firmware is not allowed to write to it, only the chip can.

    // regPtr1 = &dataReg;
    // This line is actually ALLOWED (no error) because regPtr1 itself is
    // not const — only what it points to is const. Repointing is fine here,
    // but the assignment asks us to demonstrate/comment it for clarity.


    // ---- regPtr2: int* const (const pointer to int) ----
    // Pointer address is fixed, but the value it points to CAN be changed
    int* const regPtr2 = &controlReg;
    *regPtr2 = 0b11111111;   // allowed — writing a new value through it
    cout << "regPtr2 (controlReg) new value: " << *regPtr2 << endl;

    // regPtr2 = &dataReg;
    // ERROR: cannot assign to variable 'regPtr2' because it is const.
    // regPtr2 must always point to the same address (controlReg) since the
    // control register's memory-mapped address is fixed in hardware — it
    // must never accidentally point somewhere else.


    // ---- regPtr3: const int* const (const pointer to const int) ----
    // Neither the pointer nor the value can be changed — full protection
    const int* const regPtr3 = &statusReg;
    cout << "regPtr3 (statusReg) value: " << *regPtr3 << endl;
    
    // *regPtr3 = 10;
    // ERROR: cannot modify *regPtr3 because it points to a const int.
    // Same reason as regPtr1 — status register must remain read-only.

    // regPtr3 = &dataReg;
    // ERROR: cannot assign to variable 'regPtr3' because it is const.
    // The pointer itself is locked to statusReg's address permanently —
    // this models the ROM config register: fixed value, fixed address,
    // burned at the factory, and never allowed to change in any way.

    return 0;
}