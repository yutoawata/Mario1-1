#pragma once
#include <functional>
#include "..\BaseClass\SceneBase.h"
#include "..\BaseClass\ObjectBase.h"

class DebugObject : public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	DebugObject(int* handles_);
	//デストラクタ
	~DebugObject();

	void Update() override {
		int i = 0;
	}
	void Draw() override;

	int GetValue() { return i; }

private:
	int i = 0;
};

class DebugObject02 : public ObjectBase {
	//メンバ関数
public:
	//コンストラクタ
	DebugObject02(std::function<int(void)> add_func);
	//デストラクタ
	~DebugObject02();

	void Update() override;
	void Draw() override;


	void OnCollision(const CollideResult& other_) override;

	std::function<int(void)> addFunc;
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