#pragma once
#include "DxLib.h"
#include "..\BaseClass\SceneBase.h"
#include "..\Scene\TitleScene.h"

class GameManager {
	//メンバ関数
public:
	//コンストラクタ
	GameManager();
	//デストラクタ
	~GameManager();

	//ゲームループ処理
	void ExcuteGameLoop();

	//メンバ定数

	//ゲームウィンドウ設定定数--------------
	static const int SCREEN_WIDTH = 512;	//ゲームウィンドウの横幅
	static const int SCREEN_HEIGHT = 480;	//ゲームウィンドウの縦幅
	static const int SCREEN_COLOR = 32;		//ゲームウィンドウのカラービット

	//メンバ変数
private:
	SceneBase* currentScene = new TitleScene();	//現在のシーン
	int isInit = FALSE;							//ライブラリ初期化関数の成功フラグ
};