#pragma once
#include <GameObject.h>
#include <Scene.h>
#include <array>

class Joanne : public GameObject {
private:
	// ������ ���Ͽ� ���� ��� �ٸ� ������ ���, BeatData[Type][CurrentBeatSeq] �� ����
	std::array<std::vector<GLfloat>, 12> RhythmPattern{};

	// �� ������ ��Ʈ�� ������ ���� ������ ��Ʈ�� �Ѿ��
	int Type{};

	// �� ������ ��Ʈ ��Ʈ �� �ϳ��� ��Ʈ �����̴�
	int CurrentBeatSeq{};

	// ��Ʈ�γ� �Ҹ��� �︰ Ƚ��
	int MetronomeBeatCount{};

	// ��Ʈ�γ��� 4�� �︮�� ���� ���� �� �ִ� ���°� ��Ȱ��ȭ �ǰ�, ���� �ٽ� Ȱ��ȭ ���Ѿ� ���� ���� �� �ִ�.
	bool CreateAble{true};

	// ��Ʈ�γ� ��ü ������
	GameObject* MetronomePtr{};

	// ���� ���� ������ ���� 5���� ä���� �������� ����Ѵ�.
	SoundChannel Ch[5]{};

	// ä�� �ε���
	int ChannelIndex{};

	// ����� ���� ä�� �ε���
	int ChannelStopIndex{1}; 

public:
	Joanne() {
		MetronomePtr = scene.Find("metronome");

		// 12 ������ ���� �ε�
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
			// Ư�� ���� ���ݿ� �ð��� �����ϸ� ���� ����� �ð��� �ٽ� 0.0���� �ʱ�ȭ�Ѵ�.
			if (Glb.ElapsedTime >= RhythmPattern[Type][CurrentBeatSeq]) {
				
				// ä�� �����ϸ� �����ϱ� ���� ä�� 5���� ��ȯ���� ����Ѵ�.
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
				
				// ������ ��� �����ϸ� ���� �������� ��ȯ�ɶ����� ����Ѵ�
				if (EX.CheckClampValue(CurrentBeatSeq, RhythmPattern[Type].size(), CLAMP_GREATER))
					CreateAble = false;
			}
		}

		if (MetronomePtr) {
			if (MetronomePtr->GetIsBeat()) {
				++MetronomeBeatCount;

				// ��Ʈ�γ��� 8���ڸ� ġ�� �Ҿ��� �ٽ� ���� �����
				if (MetronomeBeatCount == 8) {
					CreateAble = true;
					MetronomeBeatCount = 0;

					// ���� �������� �Ѿ��
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