#include "GameManagerh.h"
#include "..\ManagerClass\ObjectManager.h"
#include "..\ManagerClass\FPSManager.h"

const int SCREEN_WIDTH = 1920;	//ゲームウィンドウの横幅
const int SCREEN_HEIGHT = 1080;	//ゲームウィンドウの縦幅
const int SCREEN_COLOR = 32;		//ゲームウィンドウのカラービット

//コンストラクタ
GameManager::GameManager() {
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR);

	ChangeWindowMode(TRUE);
	isInit = DxLib_Init();

	//マウスカーソルの表示をOFF
	SetMouseDispFlag(FALSE);
	SetDrawScreen(DX_SCREEN_BACK);
}

//デストラクタ
GameManager::~GameManager(){
	ObjectManager::GetInstance()->DeleteInstance();
	delete currentScene;
}

//ゲームループ処理
void GameManager::ExcuteGameLoop() {

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
		FPSManager::GetInstance()->Update();

		ScreenFlip();
		FPSManager::GetInstance()->Wait();
	}
}