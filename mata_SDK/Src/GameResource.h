#pragma once
#include "SDKHeader.h"
#include "ScriptUtil.h"
#include "FileUtil.h"

// Declare the sprite resource here. 
class ImageResource {
public:

};

// Declare the sound resource here. 
class SoundResource {
public:
	// 드럼
	Sound DrumHigh{}, DrumLow{};
	
	// 메트로놈 
	Sound MetronomeHigh{}, MetronomeLow{};

	// 죠안
	Sound BBang{};
};

// Data Format list
// Write your data format here.
// {  Data Type, Category Name, Data Name, Digit Value, String Value }
class DataFormatResource {
public:

};

// Decalre the data resource here.
class DataResource {
public:
	ScriptUtil RhythmPatternScript{};
};

// Declare the global value here.
class GlobalResource {
public:
	// 게임 전체 공유 시간
	GLfloat ElapsedTime{};
};

class TextResource {
public:

};

extern ImageResource Img;
extern SoundResource Snd;
extern DataFormatResource Fmt;
extern DataResource Dat;
extern GlobalResource Glb;
extern TextResource Txt;

DWORD WINAPI ImageResourceLoader(LPVOID lpParam);
DWORD WINAPI SoundResourceLoader(LPVOID lpParam);
DWORD WINAPI DataResourceLoader(LPVOID lpParam);
DWORD WINAPI FontResourceLoader(LPVOID lpParam);
void InitText();