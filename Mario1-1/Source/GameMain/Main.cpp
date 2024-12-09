#include "DxLib.h"
#include "GameManagerh.h"

//メイン関数
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	//ゲーム管理クラスをインスタンス化
	GameManger gameManger = GameManger();
	//ゲームループ処理
	gameManger.ExcuteGameLoop();

	return 0;
}