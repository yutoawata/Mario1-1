#include "GameManagerh.h"
#include "..\ManagerClass\ObjectManager.h"

const int SCREEN_WIDTH = 1920;	//�Q�[���E�B���h�E�̉���
const int SCREEN_HEIGHT = 1080;	//�Q�[���E�B���h�E�̏c��
const int SCREEN_COLOR = 32;		//�Q�[���E�B���h�E�̃J���[�r�b�g

//�R���X�g���N�^
GameManger::GameManger() {
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR);

	ChangeWindowMode(TRUE);
	isInit = DxLib_Init();

	//�}�E�X�J�[�\���̕\����OFF
	SetMouseDispFlag(FALSE);
	SetDrawScreen(DX_SCREEN_BACK);
}

//�f�X�g���N�^
GameManger::~GameManger(){
	ObjectManager::GetInstance()->DeleteInstance();
	delete currentScene;
}

//�Q�[�����[�v����
void GameManger::ExcuteGameLoop() {

	//�Q�[�����[�v
	while (!ProcessMessage() && isInit == FALSE)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			break;
		}

		//�`��̈�����Z�b�g
		ClearDrawScreen();

		currentScene = currentScene->Update();
		currentScene->Draw();

		ScreenFlip();
	}
}