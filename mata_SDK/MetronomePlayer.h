#pragma once
#include <GameObject.h>

class MetronomePlayer : public GameObject {
private:
	// 시작 BPM은 120
	int BPM{ 120 };

	// BeatSeq가 4가 될 때마다 1로 초기화
	// BeatSeq가 1일 때만 하이 피치 사운드 재생
	int BeatSeq{1};
	GLfloat BPMInterval{};
	Metronome Met{};

public:
	MetronomePlayer() {
		Met.SetBPM(BPM);
		BPMInterval = 60.0 / (GLfloat)BPM;
	}

	void UpdateFunc(float FrameTime) {
		Met.Update(FrameTime);
		if (Met.IsBeat()) {
			if(BeatSeq == 1)
				soundUtil.Play(Snd.MetronomeHigh, Snd.MetronomeChannel);
			else
				soundUtil.Play(Snd.MetronomeLow, Snd.MetronomeChannel);
			EX.ClampValue(++BeatSeq, 1, 4, CLAMP_RETURN);
		}
	}
};