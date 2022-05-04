#ifndef TETRISSOUND_H_INCLUDED
#define TETRISSOUND_H_INCLUDED

#include <windows.h> // WinApi header

/*
 Source:
 https://www.c-plusplus.net/forum/topic/308112/beep-und-die-tetris-melodie/7
*/

namespace tetris {
void playSound(){
    const int C    = 261;
		const int Cis  = 277;
		const int D    = 293;
		const int Dis  = 311;
		const int E    = 329;
		const int F    = 349;
		const int Fis  = 369;
		const int G    = 391;
		const int Gis  = 415;
		const int A    = 440;
		const int Ais  = 466;
		const int H    = 493;
		const int Takt = 1700;

        Beep(E * 2, Takt / 4);
        Beep(H * 1, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(C * 2, Takt / 8);
        Beep(H * 1, Takt / 8);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(D * 2, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(H * 1, Takt / 2.5);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 4);
        Sleep(Takt / (8 / 3));
        Beep(D * 2, Takt / 3.25);
        Beep(F * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(G * 2, Takt / 8);
        Beep(F * 2, Takt / 8);
        Beep(E * 2, Takt / 3);
        Beep(C * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(D * 2, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(H * 1, Takt / 4);
        Beep(H * 1, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 4);
}
}

#endif // TETRISSOUND_H_INCLUDED
