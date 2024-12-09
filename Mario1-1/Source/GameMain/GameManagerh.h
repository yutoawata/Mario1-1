#pragma once
#include "DxLib.h"
#include "..\BaseClass\SceneBase.h"
#include "..\Scene\TitleScene.h"

class GameManger {
	//メンバ関数
public:
	//コンストラクタ
	GameManger();
	//デストラクタ
	~GameManger();

	//ゲームループ処理
	void ExcuteGameLoop();

	//メンバ定数
public:
	//ゲームウィンドウ設定定数--------------
	static const int SCREEN_WIDTH = 256;	//ゲームウィンドウの横幅
	static const int SCREEN_HEIGHT = 240;	//ゲームウィンドウの縦幅
	static const int SCREEN_COLOR = 32;		//ゲームウィンドウのカラービット

	//メンバ変数
private:
	SceneBase* currentScene = new TitleScene();	//現在のシーン
	int isInit = FALSE;							//ライブラリ初期化関数の成功フラグ
};