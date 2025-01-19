#pragma once
#include <functional>
#include "..\BaseClass\SceneBase.h"
#include "..\BaseClass\ObjectBase.h"
#include "..\Input\Input.h"
#include "..\Mario\Mario.h"

class DebugObject : public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	DebugObject(Vector2 position_, std::string tag_, int width_, int height_);
	//デストラクタ
	~DebugObject();

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