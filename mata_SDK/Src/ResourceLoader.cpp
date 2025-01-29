#include "GameResource.h"
#include "Config.h"

#include <Soundutil.h>

// Use LoadT(), LoadClipT(), and LoadSpriteSheetT() to load image files and sprite sheets in this thread.
DWORD WINAPI ImageResourceLoader(LPVOID lpParam) {
	// load image resources here

	return 0;
}

DWORD WINAPI SoundResourceLoader(LPVOID lpParam) {
	// bgm ·Îµå
	soundUtil.Load(Snd.BGM, "Assets//Sound//Metronome//base_loop.wav", FMOD_LOOP_NORMAL);

	return 0;
}

DWORD WINAPI DataResourceLoader(LPVOID lpParam) {

	return 0;
}

DWORD WINAPI FontResourceLoader(LPVOID lpParam) {
	// Load font resources here

	return 0;
}

void InitText() {
	// Init Text objects here

}