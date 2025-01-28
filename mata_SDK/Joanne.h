#pragma once
#include <GameObject.h>
#include <Scene.h>
#include <array>

class Joanne : public GameObject {
private:
	// 리듬의 패턴에 따라 모두 다른 간격이 기록, BeatData[Type][CurrentBeatSeq] 로 접근
	std::array<std::vector<GLfloat>, 12> RhythmPattern{};

	// 한 종류의 비트가 끝나면 다음 종류의 비트로 넘어간다
	int Type{};

	// 한 종류의 비트 세트 중 하나의 비트 순서이다
	int CurrentBeatSeq{};

	// 메트로놈 소리가 울린 횟수
	int MetronomeBeatCount{};

	// 메트로놈이 4번 울리면 빵을 만들 수 있는 상태가 비활성화 되고, 이후 다시 활성화 시켜야 빵을 만들 수 있다.
	bool CreateAble{true};

	// 메트로놈 객체 포인터
	GameObject* MetronomePtr{};

	// 사운드 끊김 방지를 위해 5개의 채널을 돌려가며 재생한다.
	SoundChannel Ch[5]{};

	// 채널 인덱스
	int ChannelIndex{};

	// 재생을 멈출 채널 인덱스
	int ChannelStopIndex{1}; 

public:
	Joanne() {
		MetronomePtr = scene.Find("metronome");

		// 12 종류의 패턴 로드
		for (int i = 0; i < 12; ++i) {
			std::string CategoryName = "Pattern";
			CategoryName += std::to_string(i + 1);
			RhythmPattern[i] = Dat.RhythmPatternScript.LoadCategoryDigitData(CategoryName);

			for (const auto& p : RhythmPattern[i])
				std::cout << p << " ";
			std::cout << "\n";
		}
	}

	void UpdateFunc(float FrameTime) {
		if (CreateAble) {
			// 특정 패턴 간격에 시간이 도달하면 빵을 만들고 시간을 다시 0.0으로 초기화한다.
			if (Glb.ElapsedTime >= RhythmPattern[Type][CurrentBeatSeq]) {
				
				// 채널 과부하를 방지하기 위해 채널 5개를 순환시켜 재생한다.
				soundUtil.Stop(Ch[ChannelStopIndex]);
				soundUtil.Play(Snd.BBang, Ch[ChannelIndex]);

				++ChannelIndex;
				++ChannelStopIndex;

				if (ChannelIndex > 4)
					ChannelIndex = 0;

				if (ChannelStopIndex > 4)
					ChannelStopIndex = 0;

				GLfloat OverTime = Glb.ElapsedTime - RhythmPattern[Type][CurrentBeatSeq];
				Glb.ElapsedTime = OverTime;

				++CurrentBeatSeq;
				
				// 패턴을 모두 실행하면 다음 패턴으로 전환될때까지 대기한다
				if (EX.CheckClampValue(CurrentBeatSeq, RhythmPattern[Type].size(), CLAMP_GREATER))
					CreateAble = false;
			}
		}

		if (MetronomePtr) {
			if (MetronomePtr->GetIsBeat()) {
				++MetronomeBeatCount;

				// 메트로놈이 8박자를 치면 죠안은 다시 빵을 만든다
				if (MetronomeBeatCount == 8) {
					CreateAble = true;
					MetronomeBeatCount = 0;

					// 다음 패턴으로 넘어간다
					++Type;
					if (Type > 11)
						Type = 0;

					CurrentBeatSeq = 0;
					Glb.ElapsedTime = -(0.5 - RhythmPattern[Type][0]);
				}
			}
		}
	}
};