#pragma once
#include "DxLib.h"


class ImageManager
{
public:
	// メンバ関数

	static ImageManager& GetInstance()
	{
		static ImageManager instance;
		return instance;
	}

	~ImageManager(); // デストラクタ

	// アクセサ
	int GetFGroundBlockHandle() { return fGroundBlockHnadle; }
	int* GetFBrickBlockHandle() { return fBrickBlockHandle; }
	int GetBGroundBlockHandle() { return bGroundBlockHandle; }
	int GetBBrickBlockHandle() { return bBrickBlockHandle; }
	int GetUnBreakBlockHandle() { return unBreakBlockHandle; }
	int* GetQuestionBlockHandle() { return questionBlockHandle; }
	int* GetFCoinHandle() { return fCoinHandle; }
	int* GetBCoinHandle() { return bCoinHandle; }
	int GetMushroomHandle() { return mushroomHandle; }
	int GetOneUpMushroomHandle() { return oneUpMushroomHandle; }
	int* GetStarHandle() { return starHandle; }
	int* GetGoombaHandle() { return goombaHandle; }
	int* GetKoopaTroopaHandle(){ return koopaTroopaHandle; }
private:

	// メンバ関数
	ImageManager(); // コンストラクタ
	ImageManager(const ImageManager&) = delete;
	ImageManager& operator=(const ImageManager&) = delete;

	void DeleteImageArray(int* handle, int size); // イメージハンドル解放

	// メンバ変数
	int fGroundBlockHnadle;		// 表面用地面ブロック画像保存ハンドル
	int fBrickBlockHandle[2];	// 表面用レンガブロック画像保存ハンドル
	int bGroundBlockHandle;		// 裏面用地面ブロック画像保存ハンドル
	int bBrickBlockHandle;		// 裏面用レンガブロック画像保存ハンドル
	int unBreakBlockHandle;		// 非破壊ブロック保存ハンドル
	int questionBlockHandle[4]; // ？ブロック保存ハンドル
	int fCoinHandle[3];			// 表面用コイン画像保存ハンドル
	int bCoinHandle[3];			// 裏面用コイン画像保存ハンドル
	int mushroomHandle;			// キノコ画像保存ハンドル
	int oneUpMushroomHandle;	// 1UPキノコ画像保存ハンドル
	int starHandle[4];			// スター画像保存ハンドル
	int goombaHandle[3];			// クリボー画像保存ハンドル
	int koopaTroopaHandle[4];	// ノコノコ画像保存ハンドル
};