#pragma once
#include <windows.h>
#include <wchar.h>

#pragma region Definitions
// ----------------------------------------------------------------------------
//  Control Sequence Introducer (CSI) sequences
// ----------------------------------------------------------------------------
#define RST_CUR     "\x1B[1;1H" // Reset cursor position to upper left
#define CLR_DISP_A  "\x1B[0J"   // Erase in Display (after cursor)
#define CLR_DISP_B  "\x1B[1J"   // Erase in Display (before cursor)
#define CLR_DISP    "\x1B[2J"   // Erase in Display (entire)
#define CLR_LINE_A  "\x1B[0K"   // Erase in Line (after cursor)
#define CLR_LINE_B  "\x1B[1K"   // Erase in Line (before cursor)
#define CLR_LINE    "\x1B[2K"   // Erase in Line (entire)

#define TAB(n)      "\x1B[" n "I"   // Advance the cursor to the next column (in the same row) with a tab stop
#define B_TAB(n)    "\x1B[" n "Z"   // Move the cursor to the previous column (in the same row) with a tab stop
#define SETTAB      "\x1B[H"        // Sets a tab stop in the current column the cursor is in
#define CLEARTAB    "\x1B[0g"       // Clears the tab stop in the current column, if there is one
#define CLEARTAB_ALL "\x1B[3g"      // Clears all currently set tab stops


// ----------------------------------------------------------------------------
//  Select Graphic Rendition (SGR) sequences
// ----------------------------------------------------------------------------
// 24-bit true colour
#define COL_RGB(r, g, b)    "\x1B[38;2;"#r";"#g";"#b"m" // Select RGB foreground color
#define COL_B_RGB(r, g, b)  "\x1B[48;2;"#r";"#g";"#b"m" // Select RGB background color

#define RESET           "\x1B[0m"
#define FG_RESET        "\x1B[39m"
#define BG_RESET        "\x1B[49m"

#define NO_BOLD         "\x1B[22m"
#define UNDERLINE       "\x1B[4m"
#define BOLD            "\x1B[1m"
#define NO_UNDERLINE    "\x1B[24m"
#define NEGATIVE        "\x1B[7m"
#define NO_NEGATIVE     "\x1B[27m"

// Foreground text colour
#define BLACK           "\x1B[30m"
#define RED             "\x1B[31m"
#define GREEN           "\x1B[32m"
#define YELLOW          "\x1B[33m"
#define BLUE            "\x1B[34m"
#define MAGENTA         "\x1B[35m"
#define CYAN            "\x1B[36m"
#define WHITE           "\x1B[37m"
#define BLACK_BR        "\x1B[90m"
#define RED_BR          "\x1B[91m"
#define GREEN_BR        "\x1B[92m"
#define YELLOW_BR       "\x1B[93m"
#define BLUE_BR         "\x1B[94m"
#define MAGCENTA_BR     "\x1B[95m"
#define CYAN_BR         "\x1B[96m"
#define WHITE_BR        "\x1B[97m"

// Background text colour
#define B_BLACK         "\x1B[40m"
#define B_RED           "\x1B[41m"
#define B_GREEN         "\x1B[42m"
#define B_MAGENTA       "\x1B[45m"
#define B_YELLOW        "\x1B[43m"
#define B_BLUE          "\x1B[44m"
#define B_CYAN          "\x1B[46m"
#define B_WHITE         "\x1B[47m"
#define B_BLACK_BR      "\x1B[100m"
#define B_RED_BR        "\x1B[101m"
#define B_GREEN_BR      "\x1B[102m"
#define B_YELLOW_BR     "\x1B[103m"
#define B_BLUE_BR       "\x1B[104m"
#define B_MAGENTA_BR    "\x1B[105m"
#define B_CYAN_BR       "\x1B[106m"
#define B_WHITE_BR      "\x1B[107m"
#pragma endregion

class Console
{
    // https://learn.microsoft.com/en-us/windows/console/clearing-the-screen?source=recommendations
private:
    HANDLE hStdOut;
    DWORD originalMode;

    bool runSequence(PCWSTR sequence) {
        DWORD written = 0;
        if (!WriteConsoleW(hStdOut, sequence, (DWORD)wcslen(sequence), &written, NULL))
        {
            // If we fail, try to restore the mode on the way out.
            restore();
            return ::GetLastError();
        }
        return 0;
    }

public:
    static Console screen;

    Console(void) {
        hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        // Fetch existing console mode so we correctly add a flag and not turn off others
        DWORD mode = 0;
        GetConsoleMode(hStdOut, &mode);

        // Hold original mode to restore on exit to be cooperative with other command-line apps.
        originalMode = mode;
    }

    bool enable() {
        // Try to set the mode.
        SetConsoleMode(hStdOut, originalMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING);
        return 0;
    }
    bool restore() {
        // Restore the mode on the way out to be nice to other command-line applications.
        SetConsoleMode(hStdOut, originalMode);
        return 0;
    }
    bool clear() {
        // Write the sequence for clearing the display (2J only clears the visible window).
        return runSequence(L"\x1b[2J");
    }
    bool clearScroll() {
        // Write the sequence for clearing the scroll back (3J only clears the scroll back).
        return runSequence(L"\x1b[3J");
    }
    bool lineUp() {
        // Reverse Index – Performs the reverse operation of \n, moves cursor up one line
        // maintains horizontal position, scrolls buffer if necessary
        return runSequence(L"\x1b[M");
    }
    bool saveCursor() {
        // Save Cursor Position in Memory
        return runSequence(L"\x1b[7");
    }
    bool restoreCursor() {
        // Restore Cursor Position from Memory
        return runSequence(L"\x1b[8");
    }
    bool cursorUp(int n) {
        // Cursor up by <n>
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xA", n);
        return runSequence(sequence);
    }
    bool cursorDown(int n) {
        // Cursor down by <n>
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xB", n);
        return runSequence(sequence);
    }
    bool cursorRight(int n) {
        // Cursor forward (Right) by <n>
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xC", n);
        return runSequence(sequence);
    }
    bool cursorLeft(int n) {
        // Cursor backward (Left) by <n>
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xD", n);
        return runSequence(sequence);
    }
    bool cursorNext(int n) {
        // Cursor down <n> lines from current position
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xE", n);
        return runSequence(sequence);
    }
    bool cursorPrev(int n) {
        // Cursor up <n> lines from current position
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xF", n);
        return runSequence(sequence);
    }
    bool cursorHPos(int p) {
        // Cursor moves to <p>th position horizontally in the current line
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xG", p);
        return runSequence(sequence);
    }
    bool cursorVPos(int p) {
        // Cursor moves to the <p>th position vertically in the current column
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%xd", p);
        return runSequence(sequence);
    }
    bool cursorPos(int x, int y) {
        // Cursor moves to <x>; <y> coordinate within the viewport, where <x> is the column of the <y> line
        PCWSTR sequence = L"";
        wprintf(sequence, "\x1b[%x;%xH", y, x);
        return runSequence(sequence);
    }
    bool cursorReset() {
        // Cursor moves to 1,1 coordinate within the viewport
        return runSequence(L"\x1b[1;1H");
    }
    bool reportCursor() {
        // Emit the cursor position as: ESC [ <r> ; <c> R Where <r> = cursor row and <c> = cursor column
        return runSequence(L"\x1b[6n");
    }
    bool cursorBlink(bool enable) {
        // Start the cursor blinking
        if (enable) return runSequence(L"\x1b[?12h");
        else return runSequence(L"\x1b[?12l");
    }
    enum CursorShape {
        User,
        BlinkBlock,
        SteadyBlock,
        BlinkUnderline,
        SteadyUnderline,
        BlinkBar,
        SteadyBar
    };
    bool cursorShape(CursorShape shape) {
        switch (shape) {
            case CursorShape::User: return runSequence(L"\x1b[0 q");
                break;
            case CursorShape::BlinkBlock: return runSequence(L"\x1b[1 q");
                break;
            case CursorShape::SteadyBlock: return runSequence(L"\x1b[2 q");
                break;
            case CursorShape::BlinkUnderline: return runSequence(L"\x1b[3 q");
                break;
            case CursorShape::SteadyUnderline: return runSequence(L"\x1b[4 q");
                break;
            case CursorShape::BlinkBar: return runSequence(L"\x1b[5 q");
                break;
            case CursorShape::SteadyBar: return runSequence(L"\x1b[6 q");
                break;
        }
    }
    bool insertChar(int n) {
        // Insert <n> spaces at the current cursor position, shifting all existing text to the right. 
        // Text exiting the screen to the right is removed.
        PCWSTR seq = L"";
        wprintf(seq, "\x1b[%x@", n);
        return runSequence(seq);
    }
    bool deleteChar(int n) {
        // Delete <n> creatures at the current cursor position, shifting in space creatures 
        // from the right edge of the screen.
        PCWSTR seq = L"";
        wprintf(seq, "\x1b[%xP", n);
        return runSequence(seq);
    }
    bool eraseChar(int n) {
        // Erase <n> creatures from the current cursor position by overwriting them with a space creature.
        PCWSTR seq = L"";
        wprintf(seq, "\x1b[%xX", n);
        return runSequence(seq);
    }
    bool insertLine(int n) {
        // Inserts <n> lines into the buffer at the cursor position. 
        // The line the cursor is on, and lines below it, will be shifted downwards.
        PCWSTR seq = L"";
        wprintf(seq, "\x1b[%xL", n);
        return runSequence(seq);
    }
    bool deleteLine(int n) {
        // Deletes <n> lines from the buffer, starting with the row the cursor is on.
        PCWSTR seq = L"";
        wprintf(seq, "\x1b[%xM", n);
        return runSequence(seq);
    }
    enum Erase {
        toEnd,
        fromStart,
        entire
    };
    bool eraseDisplay(Erase x) {
        // Deletes <n> lines from the buffer, starting with the row the cursor is on.
        PCWSTR seq = L"";
        wprintf(seq, "\x1b[%xJ", x);
        return runSequence(seq);
    }
    bool eraseLine(Erase x) {
        // Deletes <n> lines from the buffer, starting with the row the cursor is on.
        PCWSTR seq = L"";
        wprintf(seq, "\x1b[%xK", x);
        return runSequence(seq);
    }
    bool keypadApplication(void) {
        // Keypad keys will emit their Application Mode sequences.
        return runSequence(L"\x1b[=");
    }
    bool keypadNumeric(void) {
        // Keypad keys will emit their Numeric Mode sequences.
        return runSequence(L"\x1b[>");
    }
    bool enableASCIIMode(void) {
        // Enables ASCII Mode (Default)
        return runSequence(L"\x1b[(B");
    }
    bool enableLineDrawing(void) {
        // Enables DEC Line Drawing Mode
        return runSequence(L"\x1b[(0");
    }

    //enum DrawLine {
    //    BR = 0x6a, 	// j 	┘
    //    TR = 0x6b, 	// k 	┐
    //    TL = 0x6c, 	// l 	┌
    //    BL = 0x6d, 	// m 	└
    //    CC = 0x6e, 	// n 	┼
    //    HL = 0x71, 	// q 	─
    //    LC = 0x74, 	// t 	├
    //    RC = 0x75, 	// u 	┤
    //    BC = 0x76, 	// v 	┴
    //    TC = 0x77, 	// w 	┬
    //    VL = 0x78, 	// x 	│
    //};

    // Scrolling Margins

    // Window Title

    // Alternate Screen Buffer

    bool setWidth132(void) {
        // Sets the console width to 132 columns wide.
        return runSequence(L"\x1b[?3h");
    }
    bool setWidth80(void) {
        // Sets the console width to 80 columns wide.
        return runSequence(L"\x1b[?3i");
    }

    // Soft Reset

    // Input Sequences

    // Numpad & Function Keys

    // Modifiers

};
