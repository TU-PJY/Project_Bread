#pragma once
#include <GameObject.h>

class MetronomePlayer : public GameObject {
private:
	// 시작 BPM은 120
	int BPM{ 120 };

	// BeatSeq가 4가 될 때마다 1로 초기화
	// BeatSeq가 1일 때만 하이 피치 사운드 재생
	int BeatSeq{1};

	// true일 시 높음 음 재생
	bool High{};

	// 메트로놈
	Metronome Met{};

	// 채널
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

			// 번갈아가면서 재생한다
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