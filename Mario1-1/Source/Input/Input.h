#pragma once
#include "..\Math\Vector2.h"

class Input {
	//メンバ関数
private:
	//コンストラクタ
	Input();
	//コピーコンストラクタを削除
	Input(const Input&) = delete;
	//デストラクタ
	~Input();

	//アクセサ
public:
	//外部参照用のインスタンスを渡す
	static Input& GetInstance() { return *instance; }
	//左のJoyStickの入力情報を取得
	Vector2 GetInputLeftJoyStick() { return leftJoyStick; }
	//右のJoyStickの入力情報を取得
	Vector2 GetInputRightJoyStick() { return rightJoyStick; }

	//右側の四つのボタンのうち上のボタンの入力状態を渡す
	bool GetInputUpButton() { return inputState.Buttons[upButtonNum] != 0; }
	//右側の四つのボタンのうち下のボタンの入力状態を渡す
	bool GetInputDownButton() { return inputState.Buttons[downButtonNum] != 0; }
	//右側の四つのボタンのうち左のボタンの入力状態を渡す
	bool GetInputLeftButton() { return inputState.Buttons[leftButtonNum] != 0; }
	//右側の四つのボタンのうち右のボタンの入力状態を渡す
	bool GetInputRightButton() { return inputState.Buttons[rightButtonNum] != 0; }

	//十字キーの左入力状態を渡す
	bool GetInputDirectionButtonLeft() { return inputState.POV[0] == 27000; }
	//十字キーの右入力状態を渡す
	bool GetInputDirectionButtonRight() { return inputState.POV[0] == 9000; }
	//十字キーの下入力状態を渡す
	bool GetInputDirectionButtonDown(){return inputState.POV[0] == 18000; }

	//外部参照用のインスタンスを生成
	static void CreateInstance() { if (instance == nullptr)instance = new Input(); }
	//外部参照用のインスタンスを削除
	static void DeleteInsatance() { if (instance != nullptr)delete instance; }
	//使用すrコントローラーの種類ごとの設定を適応
	void SetUpJoypadInput(int input_type);
	//コントローラーの入力状態を取得
	void GetInputState();

	//メンバ変数
private:
	static Input* instance;					//外部参照用のインスタンス
	DINPUT_JOYSTATE inputState;				//入力状態を保存する構造体
	Vector2 leftJoyStick = Vector2::ZERO;	//左スティックの入力状態
	Vector2 rightJoyStick = Vector2::ZERO;	//右スティックの入力状態

	//右側4ボタンの入力状態が保存されている配列の要素番号
	int upButtonNum = -1;	//上のボタンの要素番号				
	int downButtonNum = -1;	//下のボタンの要素番号
	int leftButtonNum = -1;	//左のボタンの要素番号
	int rightButtonNum = -1;//右のボタンの要素番号
};