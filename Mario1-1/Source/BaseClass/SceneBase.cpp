#include "..\Scene\TitleScene.h"
#include "..\Scene\PlayScene.h"
#include "..\Scene\DebugScene_Awata.h"
#include "..\Scene\DebugScene_Itou.h"
#include "..\Scene\DebugScene_Monda.h"

//�R���X�g���N�^
SceneBase::SceneBase(std::string type_)
	: type(type_) {}

//�f�X�g���N�^
SceneBase::~SceneBase() {}

template SceneBase* SceneBase::ChangeScene<TitleScene>();
template SceneBase* SceneBase::ChangeScene<PlayScene>();
template SceneBase* SceneBase::ChangeScene<DebugScene_Awata>();
template SceneBase* SceneBase::ChangeScene<DebugScene_Itou>();
template SceneBase* SceneBase::ChangeScene<DebugScene_Monda>();

//�V�[���J�ڏ���
template<class Scene>
SceneBase* SceneBase::ChangeScene() {
	//���g���폜���A�w�肵���V�[���ɑJ�ڂ���
	delete this;
	return static_cast<SceneBase*>(new Scene());
}

void SceneBase::DrawType() { DrawString(10, 10, type.c_str(), GetColor(255, 255, 255)); }