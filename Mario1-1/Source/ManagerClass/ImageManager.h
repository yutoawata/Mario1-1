#pragma once
#include "DxLib.h"


class ImageManager
{
public:
	// メンバ関数

	static void LoadImages();
	static void DeleteImages();


	// アクセサ
	static int GetFGroundBlockHandle() { return fGroundBlockHnadle; }
	static int* GetFBrickBlockHandle() { return fBrickBlockHandle; }
	static int GetBGroundBlockHandle() { return bGroundBlockHandle; }
	static int GetBBrickBlockHandle() { return bBrickBlockHandle; }
	static int GetUnBreakBlockHandle() { return unBreakBlockHandle; }
	static int* GetQuestionBlockHandle() { return questionBlockHandle; }
	static int* GetFCoinHandle() { return fCoinHandle; }
	static int* GetBCoinHandle() { return bCoinHandle; }
	static int GetMushroomHandle() { return mushroomHandle; }
	static int GetOneUpMushroomHandle() { return oneUpMushroomHandle; }
	static int* GetStarHandle() { return starHandle; }
	static int* GetGoombaHandle() { return goombaHandle; }
	static int* GetKoopaTroopaHandle(){ return koopaTroopaHandle; }

private:

	static void DeleteImageArray(int* handle, int size); // イメージハンドル解放


	// メンバ変数

	//ブロック系
	static int fGroundBlockHnadle;		// 表面用地面ブロック画像保存ハンドル
	static int fBrickBlockHandle[2];	// 表面用レンガブロック画像保存ハンドル
	static int bGroundBlockHandle;		// 裏面用地面ブロック画像保存ハンドル
	static int bBrickBlockHandle;		// 裏面用レンガブロック画像保存ハンドル
	static int unBreakBlockHandle;		// 非破壊ブロック保存ハンドル
	static int questionBlockHandle[4];  // ？ブロック保存ハンドル
	static int fCoinHandle[3];			// 表面用コイン画像保存ハンドル
	static int bCoinHandle[3];			// 裏面用コイン画像保存ハンドル

	// アイテム系
	static int mushroomHandle;			// キノコ画像保存ハンドル
	static int oneUpMushroomHandle;		// 1UPキノコ画像保存ハンドル
	static int starHandle[4];			// スター画像保存ハンドル

	// キャラクター系
	static int goombaHandle[3];			// クリボー画像保存ハンドル
	static int koopaTroopaHandle[4];	// ノコノコ画像保存ハンドル
};