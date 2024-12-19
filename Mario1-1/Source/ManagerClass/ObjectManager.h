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
	static ObjectManager* GetInstance() { return instance; }

	static void DeleteInstance();
	
	static bool CheckCollision(const BoxCollider& collider_01, const BoxCollider& collider_02);

	//更新処理
	void Update();
	//描画処理
	void Draw();
	//リスト削除処理
	void ClearList();
	//リスト登録処理
	void AddList(ObjectBase* object_);
	//当たり判定処理
	void CollideObjects(ObjectBase& object_,int object_num);
	CollideResult CreateResult(const ObjectBase& collider_01, const ObjectBase& collider_02);
	
	//メンバ変数
private:
	static ObjectManager* instance;		//外部参照用のインスタンス
	std::vector<ObjectBase*> objectList;//オブジェクトのリスト
};