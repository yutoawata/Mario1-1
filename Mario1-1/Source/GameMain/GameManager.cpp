#include "GameManagerh.h"
#include "..\ManagerClass\ObjectManager.h"

const int SCREEN_WIDTH = 1920;	//ゲームウィンドウの横幅
const int SCREEN_HEIGHT = 1080;	//ゲームウィンドウの縦幅
const int SCREEN_COLOR = 32;		//ゲームウィンドウのカラービット

//コンストラクタ
GameManger::GameManger() {
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR);

	ChangeWindowMode(TRUE);
	isInit = DxLib_Init();

	//マウスカーソルの表示をOFF
	SetMouseDispFlag(FALSE);
	SetDrawScreen(DX_SCREEN_BACK);
}

//デストラクタ
GameManger::~GameManger(){
	ObjectManager::GetInstance()->DeleteInstance();
	delete currentScene;
}

//ゲームループ処理
void GameManger::ExcuteGameLoop() {

	//ゲームループ
	while (!ProcessMessage() && isInit == FALSE)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}

		//描画領域をリセット
		ClearDrawScreen();

		currentScene = currentScene->Update();
		currentScene->Draw();

		ScreenFlip();
	}
}