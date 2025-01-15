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
}