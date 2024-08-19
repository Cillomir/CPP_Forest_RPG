#pragma once
#include <string>
#include <windows.h>
#include <wchar.h>
#include "Colors.h"

#ifndef CONSOLE_DEFS_H
#define CONSOLE_DEFS_H

#define ESC     "\x1B"      // Standard escape sequence
#define CSI     "\x1B["     // Control Sequence Introducer
#define OSC     "\x1B]"     // Operating System Command

namespace CSL_Line
{
    // ----------------------------------------------------------------------------
    //  Control Sequence Introducer (CSI) sequences
    // ----------------------------------------------------------------------------
    const std::string RESET_CURSOR(CSI"1;1H");    // Reset cursor position to upper left
    const std::string CLR_DISP(CSI"2J");          // Erase in Display (entire)
    const std::string CLR_DISP_AFTER(CSI"0J");    // Erase in Display (after cursor)
    const std::string CLR_DISP_BEFOR(CSI"1J");    // Erase in Display (before cursor)
    const std::string CLR_LINE(CSI"2K");          // Erase in Line (entire)
    const std::string CLR_LINE_AFTER(CSI"0K");    // Erase in Line (after cursor)
    const std::string CLR_LINE_BEFORE(CSI"1K");   // Erase in Line (before cursor)

    const std::string SETTAB(CSI"H");             // Sets a tab stop in the current column the cursor is in
    const std::string CLEARTAB(CSI"0g");          // Clears the tab stop in the current column, if there is one
    const std::string CLEARTAB_ALL(CSI"3g");      // Clears all currently set tab stops

    class Tab
    {
    public:
        /// <summary>
        /// Advance the cursor to the next column (in the same row) with a tab stop
        /// </summary>
        static void tab()
        {
            printf(CSI"1I");
        }

        /// <summary>
        /// Advance the cursor to the <n>th tab stop column (in the same row)
        /// </summary>
        static void tab(int n)
        {
            printf(CSI"%dI", n);
        }

        /// <summary>
        /// Move the cursor to the previous column (in the same row) with a tab stop
        /// </summary>
        static void backtab()
        {
            printf(CSI"1Z");
        }

        /// <summary>
        /// Move the cursor to the <n>th previous tab column (in the same row)
        /// </summary>
        static void backtab(int n)
        {
            printf(CSI"%dZ", n);
        }
    };

    class Line
    {
    public:
        enum LN
        {
            BR, TR, TL, BL,
            HOR, VER, CROSS,
            LEFT_T, RIGHT_T, BOTTOM_T, TOP_T,
        };
        /// <summary>
        /// Enable "Line Drawing" mode
        /// </summary>
        static void lineDrawingOn()
        {
            printf(ESC "(0");
        }

        /// <summary>
        /// Disable "Line Drawing" mode
        /// </summary>
        static void lineDrawingOff()
        {
            printf(ESC "(B");
        }

        /// <summary>
        /// Draw a line while in "Line Drawing" mode
        /// </summary>
        /// <param name="line">Line to draw</param>
        static void lineDraw(LN line)
        {
            switch (line)
            {
            case LN::BR: printf("j");
                break;
            case LN::TR: printf("k");
                break;
            case LN::TL: printf("l");
                break;
            case LN::BL: printf("m");
                break;
            case LN::HOR: printf("q");
                break;
            case LN::VER: printf("x");
                break;
            case LN::CROSS: printf("n");
                break;
            case LN::LEFT_T: printf("t");
                break;
            case LN::RIGHT_T: printf("u");
                break;
            case LN::BOTTOM_T: printf("v");
                break;
            case LN::TOP_T: printf("w");
                break;
            };
        }
    };
}

namespace CSL_Cursor
{
    // ----------------------------------------------------------------------------
    //  Cursor Sequences
    // ----------------------------------------------------------------------------
    const std::string RESET_CURSOR("\x1B[1;1H");        // Reset cursor position to upper left
    const std::string CUR_SAVE("\x1B[s");               // With no parameters, performs a save cursor operation
    const std::string CUR_LOAD("\x1B[U");               // With no parameters, performs a restore cursor operation

    const std::string CUR_BLINK("\x1B[12h");            // Start the cursor blinking
    const std::string CUR_BLINK_OFF("\x1B[12l");        // Stop blinking the cursor
    const std::string CUR_SOLID("\x1B[12l");            // Stop blinking the cursor
    const std::string CUR_SHOW("\x1B[?25h");            // Show the cursor
    const std::string CUR_SHOW_OFF("\x1B[?25l");        // Hide the cursor
    const std::string CUR_HIDE("\x1B[?25l");            // Hide the cursor

    const std::string CUR_SHAPE_USER("\x1B[0 q");       // Default cursor shape configured by the user
    const std::string CUR_SHAPE_BLOCK_B("\x1B[1 q");    // Blinking block cursor shape
    const std::string CUR_SHAPE_BLOCK_S("\x1B[2 q");    // Steady block cursor shape
    const std::string CUR_SHAPE_UNDER_B("\x1B[3 q");    // Blinking underline cursor shape
    const std::string CUR_SHAPE_UNDER_S("\x1B[4 q");    // Steady underline cursor shape
    const std::string CUR_SHAPE_BAR_B("\x1B[5 q");      // Blinking bar cursor shape
    const std::string CUR_SHAPE_BAR_S("\x1B[6 q");      // Steady bar cursor shape

    class Cursor
    {
    public:
        /// <summary>
        /// Cursor up by [n]
        /// </summary>
        static void up(int n)
        {
            printf(CSI"%dA", n);
        }

        /// <summary>
        /// Cursor down by [n]
        /// </summary>
        static void down(int n)
        {
            printf(CSI"%dB", n);
        }

        /// <summary>
        /// Cursor forward (Right) by [n]
        /// </summary>
        static void right(int n)
        {
            printf(CSI"%dC", n);
        }

        /// <summary>
        /// Cursor backward (Left) by [n]
        /// </summary>
        static void left(int n)
        {
            printf(CSI"%dD", n);
        }

        /// <summary>
        /// Cursor down [n] lines from current position
        /// </summary>
        static void nextLine(int n)
        {
            printf(CSI"%dE", n);
        }

        /// <summary>
        /// Cursor up [n] lines from current position
        /// </summary>
        static void prevLine(int n)
        {
            printf(CSI"%dF", n);
        }

        /// <summary>
        /// Cursor moves to [x]; [y] coordinate within the viewport
        /// </summary>
        static void setPos(int x, int y)
        {
            if (x < 1) x = 1;
            if (y < 1) y = 1;
            if (x > 132) x = 132;
            if (y > 30) y = 30;
            printf(CSI "%d;%dH", y, x);
        }

        /// <summary>
        /// Cursor moves to [x]th position horizontally in the current line
        /// </summary>
        static void setHor(int x)
        {
            if (x < 1) x = 1;
            if (x > 132) x = 132;
            printf(CSI"%dG", x);
        }

        /// <summary>
        /// Cursor moves to the [n]th position vertically in the current column
        /// </summary>
        static void setVer(int y)
        {
            if (y < 1) y = 1;
            if (y > 80) y = 80;
            printf(CSI"%dd", y);
        }
    };
}

namespace CSL_Key
{
    // ----------------------------------------------------------------------------
    //  Console Key Modes
    // ----------------------------------------------------------------------------
    const std::string KEYPAD_APP_MODE(ESC"=");      // Keypad keys will emit their Application Mode sequences
    const std::string KEYPAD_NUM_MODE(ESC">");      // Keypad keys will emit their Numeric Mode sequences
    const std::string CURSOR_APP_MODE(CSI"?1h");    // Keypad keys will emit their Application Mode sequences
    const std::string CURSOR_NUM_MODE(CSI"?1l");    // Keypad keys will emit their Numeric Mode sequences

    // These sequences are emitted by the console host on the input stream if the ENABLE_VIRTUAL_TERMINAL_INPUT flag
    // is set on the input buffer handle. There are two internal modes that control which sequences are emitted for
    // the given input keys: the Cursor Keys Mode and the Keypad Keys Mode.
    const std::string UP_ARROW_NORM(CSI"A");        // Up Arrow, Normal Mode
    const std::string UP_ARROW_APP(ESC"OA");        // Up Arrow, Application Mode
    const std::string DOWN_ARROW_NORM(CSI"B");      // Down Arrow, Normal Mode
    const std::string DOWN_ARROW_APP(ESC"OB");      // Down Arrow, Application Mode
    const std::string RIGHT_ARROW_NORM(CSI"C");     // Right Arrow, Normal Mode
    const std::string RIGHT_ARROW_APP(ESC"OC");     // Right Arrow, Application Mode
    const std::string LEFT_ARROW_NORM(CSI"D");      // Left Arrow, Normal Mode
    const std::string LEFT_ARROW_APP(ESC"OD");      // Left Arrow, Application Mode
    const std::string HOME_KEY_NORM(CSI"H");        // Home Key, Normal Mode
    const std::string HOME_KEY_APP(ESC"OH");        // Home Key, Application Mode
    const std::string END_KEY_NORM(CSI"F");         // End Key, Normal Mode
    const std::string END_KEY_APP(ESC"OF");         // End Key, Application Mode

    const std::string CTRL_UP_ARROW(CSI"1;5A");     // CTRL + Up Arrow, Both Modes
    const std::string CTRL_DOWN_ARROW(CSI"1;5B");   // CTRL + Down Arrow, Both Modes
    const std::string CTRL_RIGHT_ARROW(CSI"1;5C");  // CTRL + Right Arrow, Both Modes
    const std::string CTRL_LEFT_ARROW(CSI"1;5D");   // CTRL + Left Arrow, Both Modes
    const std::string CTRL_SPACE("0x00");           // CTRL + Space, Both Modes

    const std::string BACKSPACE_K("0x7f");  // Backspace Key (DEL)
    const std::string PAUSE_K("0x1a");      // Pause Key (SUB)
    const std::string ESCAPE_K("0x1b");     // Escape Key (ESC)
    const std::string INSERT_K(CSI"2~");    // Insert Key
    const std::string DELETE_K(CSI"3~");    // Delete Key
    const std::string PAGE_UP(CSI"5~");     // Page Up Key
    const std::string PAGE_DOWN(CSI"6~");   // Page Down Key
    const std::string F1(ESC"OP");          // F1 Key
    const std::string F2(ESC"OQ");          // F2 Key
    const std::string F3(ESC"OR");          // F3 Key
    const std::string F4(ESC"OS");          // F4 Key
    const std::string F5(CSI"15~");         // F5 Key
    const std::string F6(CSI"17~");         // F6 Key
    const std::string F7(CSI"18~");         // F7 Key
    const std::string F8(CSI"19~");         // F8 Key
    const std::string F9(CSI"20~");         // F9 Key
    const std::string F10(CSI"21~");        // F10 Key
    const std::string F11(CSI"23~");        // F11 Key
    const std::string F12(CSI"24~");        // F12 Key

    const char KEY_CR('\x0D');
    const char KEY_RETURN('\x0D');
    const char KEY_LF('\x0A');
    const char KEY_LINEFEED('\x0A');
    const char KEY_BKSP('\x08');
    const char KEY_TAB('\x09');
    const char KEY_ESC('\x1B');
    const char KEY_SHFT_TAB('\x0F');
    const char KEY_BELL('\x07');
    const char KEY_F1('\x3B');
    const char KEY_F2('\x3C');
    const char KEY_F3('\x3D');
    const char KEY_F4('\x3E');
    const char KEY_F5('\x3F');
    const char KEY_F6('\x40');
    const char KEY_F7('\x41');
    const char KEY_F8('\x42');
    const char KEY_F9('\x43');
    const char KEY_F10('\x44');
    const char KEY_F11('\x57');
    const char KEY_F12('\x58');
    const char KEY_HOME('\x47');
    const char KEY_END('\x4F');
    const char KEY_PG_UP('\x49');
    const char KEY_PG_DOWN('\x51');
    const char KEY_ARR_UP('\x48');
    const char KEY_ARR_DOWN('\x50');
    const char KEY_ARR_LEFT('\x4B');
    const char KEY_ARR_RIGHT('\x4D');
    const char KEY_CENTER('\x4C');
    const char KEY_INS('\x52');
    const char KEY_DEL('\x53');
}

namespace CSL_Console
{
    class CSL
    {
    public:
        /// <summary> 
        /// Set output mode to handle virtual terminal sequences 
        /// </summary>
        static bool enableVTMode()
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE)
                return false;

            DWORD dwMode = 0;
            if (!GetConsoleMode(hOut, &dwMode))
                return false;

            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            if (!SetConsoleMode(hOut, dwMode))
                return false;

            return true;
        }

        /// <summary>
        /// Reset certain terminal settings to their defaults
        /// Cursor: Visible, Num Keypad: Numeric, Cur Keypad: Normal,
        /// Margins: 1 / Height, Char Set: US ASCII, SGR: Off, Save Cursor: Home (1, 1)
        /// </summary>
        static void softReset()
        {
            printf(CSI "!p");
        }
        /// <summary>
        /// Reset the cursor to coordinate [1,1] and clear the display
        /// </summary>
        static void clear()
        {
            printf(CSI "1;1H");
            printf(CSI "2J");
        }

        /// <summary>
        /// Switches to the main buffer
        /// </summary>
        static void setMainBuffer()
        {
            printf(CSI "?1049l");
        }

        /// <summary>
        /// Switches to a new alternate screen buffer
        /// </summary>
        static void setAltBuffer()
        {
            printf(CSI "?1049h");
        }

        /// <summary>
        /// Set a Title for the Window (up to 255 characters)
        /// </summary>
        static bool setWindowTitle(std::string title)
        {
            if (title.size() > 255)
                return false;
            //printf(OSC "0;%s\x1B(\x1B \x5C)", title);
            //std::string str = OSC"0;" + s + ESC"(\0x1B \0x5C)";
            return true;
        }

        /// <summary>
        /// Sets the console width to 132 columns wide
        /// </summary>
        static void setWidth132()
        {
            printf(CSI "?3h");
        }

        /// <summary>
        /// Sets the console width to 80 columns wide
        /// </summary>
        static void setWidth80()
        {
            printf(CSI "?3i");
        }

        /// <summary>
        /// Sets the VT scrolling margins of the viewport
        /// </summary>
        /// <param name="top"></param>
        /// <param name="bottom"></param>
        static void setScrollMargin(int top, int bottom)
        {
            //std::string str = CSI std::to_string(top) ";" std::to_string(bottom) "r";
            printf(CSI "%d;%dr", top, bottom);
        }

        static void getScreenInfo(COORD& buffer, COORD& size, COORD& cursor, COORD& maxWindow)
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE)
                return;
            CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
            GetConsoleScreenBufferInfo(hOut, &ScreenBufferInfo);
            buffer = ScreenBufferInfo.dwSize;
            size.X = ScreenBufferInfo.srWindow.Right - ScreenBufferInfo.srWindow.Left + 1;
            size.Y = ScreenBufferInfo.srWindow.Bottom - ScreenBufferInfo.srWindow.Top + 1;
            cursor = ScreenBufferInfo.dwCursorPosition;
            maxWindow = ScreenBufferInfo.dwMaximumWindowSize;
        }
        static COORD getWindowSize()
            // Emit the cursor position as : ESC[<r>; <c> R Where <r> = cursor row and <c> = cursor column
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE)
                return { 0, 0 };
            CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
            GetConsoleScreenBufferInfo(hOut, &ScreenBufferInfo);
            COORD size;
            size.X = ScreenBufferInfo.srWindow.Right - ScreenBufferInfo.srWindow.Left + 1;
            size.Y = ScreenBufferInfo.srWindow.Bottom - ScreenBufferInfo.srWindow.Top + 1;
            return size;
        }
        static COORD getBufferSize()
            // Emit the cursor position as : ESC[<r>; <c> R Where <r> = cursor row and <c> = cursor column
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE)
                return { 0, 0 };
            CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
            GetConsoleScreenBufferInfo(hOut, &ScreenBufferInfo);
            COORD buffer;
            buffer = ScreenBufferInfo.dwSize;
            return buffer;
        }
        static COORD getCursorPos()
            // Emit the cursor position as : ESC[<r>; <c> R Where <r> = cursor row and <c> = cursor column
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE)
                return { 0, 0 };
            CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo;
            GetConsoleScreenBufferInfo(hOut, &ScreenBufferInfo);
            COORD cursor;
            cursor = ScreenBufferInfo.dwCursorPosition;
            return cursor;
        }
        static void setWindowSize(short h, short w)
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE)
                return;
            COORD size = { w, h };
            SetConsoleScreenBufferSize(hOut, size);
        }
        static void setBufferSize(short h, short w)
        {
            HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
            if (hOut == INVALID_HANDLE_VALUE)
                return;
            COORD size = { w, h };
            SetConsoleScreenBufferSize(hOut, size);
        }
    };
}
#endif