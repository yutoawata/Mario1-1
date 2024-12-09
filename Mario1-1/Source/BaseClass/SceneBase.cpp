#include "..\Scene\TitleScene.h"
#include "..\Scene\PlayScene.h"
#include "..\Scene\DebugScene_Awata.h"
#include "..\Scene\DebugScene_Itou.h"
#include "..\Scene\DebugScene_Monda.h"

//コンストラクタ
SceneBase::SceneBase(std::string type_)
	: type(type_) {}

//デストラクタ
SceneBase::~SceneBase() {}

template SceneBase* SceneBase::ChangeScene<TitleScene>();
template SceneBase* SceneBase::ChangeScene<PlayScene>();
template SceneBase* SceneBase::ChangeScene<DebugScene_Awata>();
template SceneBase* SceneBase::ChangeScene<DebugScene_Itou>();
template SceneBase* SceneBase::ChangeScene<DebugScene_Monda>();

//シーン遷移処理
template<class Scene>
SceneBase* SceneBase::ChangeScene() {
	//自身を削除し、指定したシーンに遷移する
	delete this;
	return static_cast<SceneBase*>(new Scene());
}

void SceneBase::DrawType() { DrawString(10, 10, type.c_str(), GetColor(255, 255, 255)); }