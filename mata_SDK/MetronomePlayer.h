#pragma once
#include <GameObject.h>

class MetronomePlayer : public GameObject {
private:
	// ���� BPM�� 120
	int BPM{ 120 };

	// BeatSeq�� 4�� �� ������ 1�� �ʱ�ȭ
	// BeatSeq�� 1�� ���� ���� ��ġ ���� ���
	int BeatSeq{1};

	// true�� �� ���� �� ���
	bool High{};

	// ��Ʈ�γ�
	Metronome Met{};

	// ä��
	SoundChannel Ch[5]{};
	int ChannelIndex{};
	int ChannelStopIndex{ 1 };

public:
	MetronomePlayer() {
		Met.SetBPM(BPM);
	}

	void UpdateFunc(float FrameTime) {
		Glb.ElapsedTime += FrameTime * 1.0;
		Met.Update(FrameTime * 1.0);

		if (Met.IsBeat()) {
			soundUtil.Stop(Ch[ChannelStopIndex]);

			// �����ư��鼭 ����Ѵ�
			if (!High) {
				soundUtil.Play(Snd.DrumLow, Ch[ChannelIndex]);
				High = true;
			}
			else {
				soundUtil.Play(Snd.DrumHigh, Ch[ChannelIndex]);
				High = false;
			}

			++ChannelIndex;
			++ChannelStopIndex;

			if (ChannelIndex > 4)
				ChannelIndex = 0;

			if (ChannelStopIndex > 4)
				ChannelStopIndex = 0;
		}
	}

	bool GetIsBeat() {
		return Met.IsBeat();
	}
};