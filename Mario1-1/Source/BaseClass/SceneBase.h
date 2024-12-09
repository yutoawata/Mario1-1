#pragma once
#include <string>
#include "DxLib.h"

class SceneBase {
	//メンバ関数
public:
	//コンストラクタ
	SceneBase(std::string type_);
	//デストラクタ
	~SceneBase();

public:
	//更新処理
	virtual SceneBase* Update() = 0;
	//描画処理
	virtual void Draw() = 0;

	//シーン遷移処理
	template<class Scene>
	SceneBase* ChangeScene();

	void DrawType();

	//メンバ変数
protected:
	std::string type = "Base";
};