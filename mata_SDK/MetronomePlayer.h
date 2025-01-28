#pragma once
#include <GameObject.h>

class MetronomePlayer : public GameObject {
private:
	// ���� BPM�� 120
	int BPM{ 120 };

	// BeatSeq�� 4�� �� ������ 1�� �ʱ�ȭ
	// BeatSeq�� 1�� ���� ���� ��ġ ���� ���
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