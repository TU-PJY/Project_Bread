#pragma once
#include <GameObject.h>

class MetronomePlayer : public GameObject {
private:
	// 시작 BPM은 120
	int BPM{ 120 };

	// 한 번만 재생
	bool BGMPlay{};

	// 메트로놈
	Metronome Met{};

	GLfloat PlaySpeed{ 1.0 };


	// 채널
	SoundChannel ChBGM{};
	int ChannelIndex{};

public:
	MetronomePlayer() {
		Met.SetBPM(BPM);
	}

	void InputKey(KeyEvent& Event) {
		if (Event.Type == NORMAL_KEY_DOWN && Event.NormalKey == NK_SPACE) {
			PlaySpeed += 0.1; 
		}
	}

	void UpdateFunc(float FrameTime) {
		Glb.ElapsedTime += FrameTime * PlaySpeed;
		Met.Update(FrameTime * PlaySpeed);

		if (Met.IsBeat()) {
			if (!BGMPlay)
				soundUtil.PlayOnce(Snd.BGM, ChBGM, BGMPlay);
			soundUtil.SetPlaySpeed(ChBGM, PlaySpeed);
		}
	}

	bool GetIsBeat() {
		return Met.IsBeat();
	}
};