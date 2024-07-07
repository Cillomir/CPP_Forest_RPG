#pragma once
#include <string>

#ifndef CSL_COLORS_DEF_H
#define CSL_COLORS_DEF_H
namespace CSL_Color
{
	// ----------------------------------------------------------------------------
	//  Set Graphic Rendition (SGR) sequences
	// ----------------------------------------------------------------------------
	const std::string SGR_RESET = "\x1B[0m";
	const std::string FG_RESET = "\x1B[39m";
	const std::string BG_RESET = "\x1B[49m";

	// Text Formatting
	const std::string BOLD = "\x1B[1m";
	const std::string NO_BOLD = "\x1B[22m";
	const std::string UNDERLINE = "\x1B[4m";
	const std::string NO_UNDERLINE = "\x1B[24m";
	const std::string NEGATIVE = "\x1B[7m";
	const std::string POSITIVE = "\x1B[27m";
	const std::string NO_NEGATIVE = "\x1B[27m";

	// ----------------------------------------------------------------------------
	//  Standard Color Sequences
	// ----------------------------------------------------------------------------
	static std::string RGB_FG(int r, int g, int b)
		// Select RGB foreground color \x1B[38;2;<r>;<g>;<b>m
	{
		return "\x1B[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
	}
	static std::string RGB_BG(int r, int g, int b)
		// Select RGB background color \x1B[48;2;<r>;<g>;<b>m
	{
		return "\x1B[48;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
	}

	// Foreground text colour
	const std::string BLACK = "\x1B[30m";
	const std::string RED = "\x1B[31m";
	const std::string GREEN = "\x1B[32m";
	const std::string YELLOW = "\x1B[33m";
	const std::string BLUE = "\x1B[34m";
	const std::string MAGENTA = "\x1B[35m";
	const std::string CYAN = "\x1B[36m";
	const std::string WHITE = "\x1B[37m";
	const std::string BLACK_BR = "\x1B[90m";
	const std::string RED_BR = "\x1B[91m";
	const std::string GREEN_BR = "\x1B[92m";
	const std::string YELLOW_BR = "\x1B[93m";
	const std::string BLUE_BR = "\x1B[94m";
	const std::string MAGCENTA_BR = "\x1B[95m";
	const std::string CYAN_BR = "\x1B[96m";
	const std::string WHITE_BR = "\x1B[97m";

	// Background text colour
	const std::string B_BLACK = "\x1B[40m";
	const std::string B_RED = "\x1B[41m";
	const std::string B_GREEN = "\x1B[42m";
	const std::string B_MAGENTA = "\x1B[45m";
	const std::string B_YELLOW = "\x1B[43m";
	const std::string B_BLUE = "\x1B[44m";
	const std::string B_CYAN = "\x1B[46m";
	const std::string B_WHITE = "\x1B[47m";
	const std::string B_BLACK_BR = "\x1B[100m";
	const std::string B_RED_BR = "\x1B[101m";
	const std::string B_GREEN_BR = "\x1B[102m";
	const std::string B_YELLOW_BR = "\x1B[103m";
	const std::string B_BLUE_BR = "\x1B[104m";
	const std::string B_MAGENTA_BR = "\x1B[105m";
	const std::string B_CYAN_BR = "\x1B[106m";
	const std::string B_WHITE_BR = "\x1B[107m";

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Expanded to 72 Colors + 10 Grayscale (26 + 5 foreground & 26 + 5 background)
	// https://www.canva.com/colors/color-wheel/
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// Foreground Colors
	const std::string FG_RED1 = "\x1B[38;2;255;0;0m";		// Light Red, Foreground
	const std::string FG_RED2 = "\x1B[38;2;163;0;0m";		// Medium Red, Foreground
	const std::string FG_RED3 = "\x1B[38;2;81;0;0m";		// Dark Red, Foreground
	const std::string FG_ORANGE1 = "\x1B[38;2;255;161;0m";	// Light Orange, Foreground
	const std::string FG_ORANGE2 = "\x1B[38;2;163;107;0m";	// Medium Orange, Foreground
	const std::string FG_ORANGE3 = "\x1B[38;2;81;53;0m";		// Dark Orange, Foreground
	const std::string FG_YELLOW1 = "\x1B[38;2;255;255;0m";	// Light Yellow, Foreground
	const std::string FG_YELLOW2 = "\x1B[38;2;163;163;0m";	// Medium Yellow, Foreground
	const std::string FG_YELLOW3 = "\x1B[38;2;81;81;0m";		// Dark Yellow, Foreground
	const std::string FG_EMERALD1 = "\x1B[38;2;161;255;0m";	// Light Emerald (Green), Foreground
	const std::string FG_EMERALD2 = "\x1B[38;2;107;163;0m";	// Medium Emerald (Green), Foreground
	const std::string FG_EMERALD3 = "\x1B[38;2;53;81;0m";		// Dark Emerald (Green), Foreground
	const std::string FG_GREEN1 = "\x1B[38;2;0;255;0m";		// Light Green, Foreground
	const std::string FG_GREEN2 = "\x1B[38;2;0;163;0m";		// Medium Green, Foreground
	const std::string FG_GREEN3 = "\x1B[38;2;0;81;0m";		// Dark Green, Foreground
	const std::string FG_SPRING1 = "\x1B[38;2;0;255;161m";	// Light Spring (Green), Foreground
	const std::string FG_SPRING2 = "\x1B[38;2;0;163;107m";	// Medium Spring (Green), Foreground
	const std::string FG_SPRING3 = "\x1B[38;2;0;81;53m";		// Dark Spring (Green), Foreground
	const std::string FG_CYAN1 = "\x1B[38;2;0;255;255m";	// Light Cyan, Foreground
	const std::string FG_CYAN2 = "\x1B[38;2;0;163;163m";	// Medium Cyan, Foreground
	const std::string FG_CYAN3 = "\x1B[38;2;0;81;81m";		// Dark Cyan, Foreground
	const std::string FG_AZURE1 = "\x1B[38;2;0;161;255m";	// Light Azure (Blue), Foreground
	const std::string FG_AZURE2 = "\x1B[38;2;0;107;163m";	// Medium Azure (Blue), Foreground
	const std::string FG_AZURE3 = "\x1B[38;2;0;53;81m";		// Dark Azure (Blue), Foreground
	const std::string FG_BLUE1 = "\x1B[38;2;0;0;255m";		// Light Blue, Foreground
	const std::string FG_BLUE2 = "\x1B[38;2;0;0;163m";		// Medium Blue, Foreground
	const std::string FG_BLUE3 = "\x1B[38;2;0;0;81m";		// Dark Blue, Foreground
	const std::string FG_VIOLET1 = "\x1B[38;2;161;0;255m";	// Light Violet, Foreground
	const std::string FG_VIOLET2 = "\x1B[38;2;107;0;163m";	// Medium Violet, Foreground
	const std::string FG_VIOLET3 = "\x1B[38;2;53;0;81m";		// Dark Violet, Foreground
	const std::string FG_PURPLE1 = "\x1B[38;2;255;0;255m";	// Light Purple, Foreground
	const std::string FG_PURPLE2 = "\x1B[38;2;163;0;163m";	// Medium Purple, Foreground
	const std::string FG_PURPLE3 = "\x1B[38;2;81;0;81m";		// Dark Purple, Foreground
	const std::string FG_ROSE1 = "\x1B[38;2;255;0;161m";	// Light Rose, Foreground
	const std::string FG_ROSE2 = "\x1B[38;2;163;0;107m";	// Medium Rose, Foreground
	const std::string FG_ROSE3 = "\x1B[38;2;81;0;53m";		// Dark Rose, Foreground

	const std::string FG_WHITE = "\x1B[38;2;255;255;255m";	// White, Foreground
	const std::string FG_GRAY1 = "\x1B[38;2;191;191;191m";	// Light Gray, Foreground
	const std::string FG_GRAY2 = "\x1B[38;2;127;127;127m";	// Medium Gray, Foreground
	const std::string FG_GRAY3 = "\x1B[38;2;63;63;63m";	// Dark Gray, Foreground
	const std::string FG_BLACK = "\x1B[38;2;0;0;0m";		// Black, Foreground

	// Additional Named Foreground Colors
	const std::string FG_BROWN1 = "\x1B[38;2;231;114;0m";	// Light Brown, Foreground
	const std::string FG_BROWN2 = "\x1B[38;2;153;75;0m";	// Medium Brown, Foreground
	const std::string FG_BROWN3 = "\x1B[38;2;76;37;0m";		// Dark Brown, Foreground
	const std::string FG_PINK1 = "\x1B[38;2;255;191;202m";	// Light Pink, Foreground
	const std::string FG_PINK2 = "\x1B[38;2;163;127;133m";	// Medium Pink, Foreground
	const std::string FG_PINK3 = "\x1B[38;2;81;63;66m";	// Dark Pink, Foreground
	const std::string FG_TAN1 = "\x1B[38;2;209;179;139m";	// Light Tan, Foreground
	const std::string FG_TAN2 = "\x1B[38;2;139;119;91m";	// Medium Tan, Foreground
	const std::string FG_TAN3 = "\x1B[38;2;69;59;46m";	// Dark Tan, Foreground
	const std::string FG_GOLD1 = "\x1B[38;2;212;176;56m";	// Light Gold, Foreground
	const std::string FG_GOLD2 = "\x1B[38;2;145;120;38m";	// Medium Gold, Foreground
	const std::string FG_GOLD3 = "\x1B[38;2;99;82;26m";	// Dark Gold, Foreground
	const std::string FG_SILVER1 = "\x1B[38;2;170;164;179m";	// Light Silver, Foreground
	const std::string FG_SILVER2 = "\x1B[38;2;123;120;129m";	// Medium Silver, Foreground
	const std::string FG_SILVER3 = "\x1B[38;2;75;72;78m";	// Dark Silver, Foreground
	const std::string FG_COPPER1 = "\x1B[38;2;236;148;66m";	// Light Copper, Foreground
	const std::string FG_COPPER2 = "\x1B[38;2;184;115;51m";	// Medium Copper, Foreground
	const std::string FG_COPPER3 = "\x1B[38;2;132;82;36m";	// Dark Copper, Foreground

	// Background Colors
	const std::string BG_RED1 = "\x1B[48;2;255;0;0m";		// Light Red, Background
	const std::string BG_RED2 = "\x1B[48;2;163;0;0m";		// Medium Red, Background
	const std::string BG_RED3 = "\x1B[48;2;81;0;0m";		// Dark Red, Background
	const std::string BG_ORANGE1 = "\x1B[48;2;255;161;0m";	// Light Orange, Background
	const std::string BG_ORANGE2 = "\x1B[48;2;163;107;0m";	// Medium Orange, Background
	const std::string BG_ORANGE3 = "\x1B[48;2;81;53;0m";		// Dark Orange, Background
	const std::string BG_YELLOW1 = "\x1B[48;2;255;255;0m";	// Light Yellow, Background
	const std::string BG_YELLOW2 = "\x1B[48;2;163;163;0m";	// Medium Yellow, Background
	const std::string BG_YELLOW3 = "\x1B[48;2;81;81;0m";		// Dark Yellow, Background
	const std::string BG_EMERALD1 = "\x1B[48;2;161;255;0m";	// Light Emerald (Green), Background
	const std::string BG_EMERALD2 = "\x1B[48;2;107;163;0m";	// Medium Emerald (Green), Background
	const std::string BG_EMERALD3 = "\x1B[48;2;53;81;0m";		// Dark Emerald (Green), Background
	const std::string BG_GREEN1 = "\x1B[48;2;0;255;0m";		// Light Green, Background
	const std::string BG_GREEN2 = "\x1B[48;2;0;163;0m";		// Medium Green, Background
	const std::string BG_GREEN3 = "\x1B[48;2;0;81;0m";		// Dark Green, Background
	const std::string BG_SPRING1 = "\x1B[48;2;0;255;161m";	// Light Spring (Green), Background
	const std::string BG_SPRING2 = "\x1B[48;2;0;163;107m";	// Medium Spring (Green), Background
	const std::string BG_SPRING3 = "\x1B[48;2;0;81;53m";		// Dark Spring (Green), Background
	const std::string BG_CYAN1 = "\x1B[48;2;0;255;255m";	// Light Cyan, Background
	const std::string BG_CYAN2 = "\x1B[48;2;0;163;163m";	// Medium Cyan, Background
	const std::string BG_CYAN3 = "\x1B[48;2;0;81;81m";		// Dark Cyan, Background
	const std::string BG_AZURE1 = "\x1B[48;2;0;161;255m";	// Light Azure (Blue), Background
	const std::string BG_AZURE2 = "\x1B[48;2;0;107;163m";	// Medium Azure (Blue), Background
	const std::string BG_AZURE3 = "\x1B[48;2;0;53;81m";		// Dark Azure (Blue), Background
	const std::string BG_BLUE1 = "\x1B[48;2;0;0;255m";		// Light Blue, Background
	const std::string BG_BLUE2 = "\x1B[48;2;0;0;163m";		// Medium Blue, Background
	const std::string BG_BLUE3 = "\x1B[48;2;0;0;81m";		// Dark Blue, Background
	const std::string BG_VIOLET1 = "\x1B[48;2;161;0;255m";	// Light Violet, Background
	const std::string BG_VIOLET2 = "\x1B[48;2;107;0;163m";	// Medium Violet, Background
	const std::string BG_VIOLET3 = "\x1B[48;2;53;0;81m";		// Dark Violet, Background
	const std::string BG_PURPLE1 = "\x1B[48;2;255;0;255m";	// Light Purple, Background
	const std::string BG_PURPLE2 = "\x1B[48;2;163;0;163m";	// Medium Purple, Background
	const std::string BG_PURPLE3 = "\x1B[48;2;81;0;81m";		// Dark Purple, Background
	const std::string BG_ROSE1 = "\x1B[48;2;255;0;161m";	// Light Rose, Background
	const std::string BG_ROSE2 = "\x1B[48;2;163;0;107m";	// Medium Rose, Background
	const std::string BG_ROSE3 = "\x1B[48;2;81;0;53m";		// Dark Rose, Background

	const std::string BG_WHITE = "\x1B[48;2;255;255;255m";	// White, Background
	const std::string BG_GRAY1 = "\x1B[48;2;191;191;191m";	// Light Gray, Background
	const std::string BG_GRAY2 = "\x1B[48;2;127;127;127m";	// Medium Gray, Background
	const std::string BG_GRAY3 = "\x1B[48;2;63;63;63m";	// Dark Gray, Background
	const std::string BG_BLACK = "\x1B[48;2;0;0;0m";		// Black, Background

	// Additional Named Foreground Colors
	const std::string BG_BROWN1 = "\x1B[48;2;231;114;0m";	// Light Brown, Background
	const std::string BG_BROWN2 = "\x1B[48;2;153;75;0m";	// Medium Brown, Background
	const std::string BG_BROWN3 = "\x1B[48;2;76;37;0m";		// Dark Brown, Background
	const std::string BG_PINK1 = "\x1B[48;2;255;191;202m";	// Light Pink, Background
	const std::string BG_PINK2 = "\x1B[48;2;163;127;133m";	// Medium Pink, Background
	const std::string BG_PINK3 = "\x1B[48;2;81;63;66m";	// Dark Pink, Background
	const std::string BG_TAN1 = "\x1B[48;2;209;179;139m";	// Light Tan, Background
	const std::string BG_TAN2 = "\x1B[48;2;139;119;91m";	// Medium Tan, Background
	const std::string BG_TAN3 = "\x1B[48;2;69;59;46m";	// Dark Tan, Background
	const std::string BG_GOLD1 = "\x1B[48;2;212;176;56m";	// Light Gold, Background
	const std::string BG_GOLD2 = "\x1B[48;2;145;120;38m";	// Medium Gold, Background
	const std::string BG_GOLD3 = "\x1B[48;2;99;82;26m";	// Dark Gold, Background
	const std::string BG_SILVER1 = "\x1B[48;2;170;164;179m";	// Light Silver, Background
	const std::string BG_SILVER2 = "\x1B[48;2;123;120;129m";	// Medium Silver, Background
	const std::string BG_SILVER3 = "\x1B[48;2;75;72;78m";	// Dark Silver, Background
	const std::string BG_COPPER1 = "\x1B[48;2;236;148;66m";	// Light Copper, Background
	const std::string BG_COPPER2 = "\x1B[48;2;184;115;51m";	// Medium Copper, Background
	const std::string BG_COPPER3 = "\x1B[48;2;132;82;36m";	// Dark Copper, Background
}
#endif
