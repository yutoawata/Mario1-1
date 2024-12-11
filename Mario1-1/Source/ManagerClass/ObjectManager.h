#pragma once
#include<vector>
#include "..\BaseClass\ObjectBase.h"

class ObjectManager {
	//メンバ関数
private:
	//コンストラクタ
	ObjectManager();
	//コピーコンストラクタを削除
	ObjectManager(const ObjectManager&) = delete;
	//デストラクタ
	~ObjectManager();

	//アクセサ
public:
	static ObjectManager* getInstance() { return instance; }

	//登録処理
	static void AddList(ObjectBase* object_);
	static void ClearList();
	static void DeleteInstance();

	//更新処理
	void Update();
	//描画処理
	void Draw();
	//当たり判定処理
	void CollideObjects(ObjectBase& object_,int object_num);
	bool CheckCollision(const BoxCollider& collider_01, const BoxCollider& colliser_02);

	static ObjectManager* instance;
	//メンバ変数
private:
	static std::vector<ObjectBase*> objectList;//オブジェクトのリスト
};