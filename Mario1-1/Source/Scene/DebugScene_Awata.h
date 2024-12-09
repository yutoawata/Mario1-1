#pragma once
#include "..\BaseClass\SceneBase.h"
#include "..\BaseClass\ObjectBase.h"

class DebugObject : public ObjectBase {
public:
	DebugObject();
	~DebugObject();

	void Update() override;
	void Draw() override;
};

class DebugScene_Awata : public SceneBase {
	//メンバ関数
public:
	//コンストラクタ
	DebugScene_Awata();
	//デストラクタ
	~DebugScene_Awata();

	SceneBase* Update() override;

	void Draw() override;

	//メンバ変数
private:
};