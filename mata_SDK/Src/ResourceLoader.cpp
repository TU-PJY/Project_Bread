#include "GameResource.h"
#include "Config.h"

#include <Soundutil.h>

// Use LoadT(), LoadClipT(), and LoadSpriteSheetT() to load image files and sprite sheets in this thread.
DWORD WINAPI ImageResourceLoader(LPVOID lpParam) {
	// load image resources here

	return 0;
}

DWORD WINAPI SoundResourceLoader(LPVOID lpParam) {
	soundUtil.Load(Snd.MetronomeLow, "Assets//Sound//Metronome//metronome_low.wav");
	soundUtil.Load(Snd.MetronomeHigh, "Assets//Sound//Metronome//metronome_high.wav");
	return 0;
}

DWORD WINAPI DataResourceLoader(LPVOID lpParam) {
	// load data resources here

	return 0;
}

DWORD WINAPI FontResourceLoader(LPVOID lpParam) {
	// Load font resources here

	return 0;
}

void InitText() {
	// Init Text objects here

}