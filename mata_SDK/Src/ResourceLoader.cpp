#include "GameResource.h"
#include "Config.h"

#include <Soundutil.h>

// Use LoadT(), LoadClipT(), and LoadSpriteSheetT() to load image files and sprite sheets in this thread.
DWORD WINAPI ImageResourceLoader(LPVOID lpParam) {
	// load image resources here

	return 0;
}

DWORD WINAPI SoundResourceLoader(LPVOID lpParam) {
	// �巳 ���� �ε�
	soundUtil.Load(Snd.DrumHigh, "Assets//Sound//Metronome//drum_high.wav");
	soundUtil.Load(Snd.DrumLow, "Assets//Sound//Metronome//drum_low.wav");

	// ��Ʈ�γ� ���� �ε�
	soundUtil.Load(Snd.MetronomeHigh, "Assets//Sound//Metronome//metronome_high.wav");
	soundUtil.Load(Snd.MetronomeLow, "Assets//Sound//Metronome//metronome_low.wav");

	// �Ҿ� ���� �ε�
	soundUtil.Load(Snd.BBang, "Assets//Sound//Joanne//bbang.wav");

	return 0;
}

DWORD WINAPI DataResourceLoader(LPVOID lpParam) {
	// ���� ���� ��ũ��Ʈ �ε�
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