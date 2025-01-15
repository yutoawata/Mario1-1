#include "Input.h"

Input* Input::instance = nullptr;

//コンストラクタ
Input::Input() {}

//デストラクタ
Input::~Input() {

}


void Input::SetUpJoypadInput(int input_type) {
	switch (input_type) {
		//PlayStationコントローター用の設定
	case DX_PADTYPE_DUAL_SENSE:
		upButtonNum = 3;
		downButtonNum = 1;
		leftButtonNum = 0;
		rightButtonNum = 2;
		break;
		//XBox・SwitchProコントローラー用設定
	case DX_PADTYPE_XBOX_ONE:
		upButtonNum = 3;
		downButtonNum = 0;
		leftButtonNum = 2;
		rightButtonNum = 1;
		break;
	}
}


void Input::GetInputState() {
	GetJoypadDirectInputState(DX_INPUT_PAD1, &inputState);

	char i = inputState.Buttons[0];

	DrawFormatString(10, 100, GetColor(255, 255, 0), "%c", i);

	DrawFormatString(10, 50, GetColor(255, 255, 0), "%d", inputState.Buttons[0]);
	DrawFormatString(10, 100, GetColor(255, 255, 0), "%d", inputState.Buttons[1]);
	DrawFormatString(10, 150, GetColor(255, 255, 0), "%d", inputState.Buttons[2]);
	DrawFormatString(10, 200, GetColor(255, 255, 0), "%d", inputState.Buttons[3]);
}