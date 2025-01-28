#include "GameResource.h"
#include "Config.h"

#include <Soundutil.h>

// Use LoadT(), LoadClipT(), and LoadSpriteSheetT() to load image files and sprite sheets in this thread.
DWORD WINAPI ImageResourceLoader(LPVOID lpParam) {
	// load image resources here

	return 0;
}

DWORD WINAPI SoundResourceLoader(LPVOID lpParam) {
	// 드럼 사운드 로드
	soundUtil.Load(Snd.DrumHigh, "Assets//Sound//Metronome//drum_high.wav");
	soundUtil.Load(Snd.DrumLow, "Assets//Sound//Metronome//drum_low.wav");

	// 메트로놈 사운드 로드
	soundUtil.Load(Snd.MetronomeHigh, "Assets//Sound//Metronome//metronome_high.wav");
	soundUtil.Load(Snd.MetronomeLow, "Assets//Sound//Metronome//metronome_low.wav");

	// 죠안 사운드 로드
	soundUtil.Load(Snd.BBang, "Assets//Sound//Joanne//bbang.wav");

	return 0;
}

DWORD WINAPI DataResourceLoader(LPVOID lpParam) {
	// 리듬 패턴 스크립트 로드
	Dat.RhythmPatternScript.Load("Assets//Script//rhythm_pattern.xml");

	return 0;
}

DWORD WINAPI FontResourceLoader(LPVOID lpParam) {
	// Load font resources here

	return 0;
}

void InitText() {
	// Init Text objects here

}