#pragma once
#include <functional>
#include "..\BaseClass\SceneBase.h"
#include "..\BaseClass\ObjectBase.h"
#include "..\Input\Input.h"
#include "..\Mario\Mario.h"

class DebugObject02 : public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	DebugObject02();
	//デストラクタ
	~DebugObject02();

	void Update() override;
	void Draw() override;


	void OnCollision(const CollideResult& other_) override;
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
	Mario* mario = new Mario(Vector2(0, 0));
	float timer = 0.0f;
};