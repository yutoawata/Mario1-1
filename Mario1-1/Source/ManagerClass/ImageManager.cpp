#include "ImageManager.h"

// ブロック系
int ImageManager::fGroundBlockHnadle = 0;
int ImageManager::fBrickBlockHandle[2] = { 0,0 };
int ImageManager::bGroundBlockHandle = 0;
int ImageManager::bBrickBlockHandle = 0;
int ImageManager::unBreakBlockHandle = 0;
int ImageManager::questionBlockHandle[4] = { 0,0,0,0 };
// アイテム系
int ImageManager::fCoinHandle[3] = { 0,0,0 };
int ImageManager::bCoinHandle[3] = { 0,0,0 };
int ImageManager::mushroomHandle = 0;
int ImageManager::oneUpMushroomHandle = 0;
int ImageManager::starHandle[4] = { 0,0,0,0 };
// キャラクター系
int ImageManager::normalMarioHandle[9] = { 0,0,0,0,0,0,0,0,0 };
int ImageManager::goombaHandle[3] = { 0,0,0 };
int ImageManager::koopaTroopaHandle[4] = { 0,0,0,0 };

void ImageManager::LoadImages()
{
	// ブロック系
	fGroundBlockHnadle = LoadGraph("././Resource/Images/fGroundBlock.png");
	if (fGroundBlockHnadle == -1)
	{
		printfDx("ERROR:fGroundBlockHnadle");
		return;
	}
	LoadDivGraph("././Resource/Images/fBrickBlock.png", 2, 2, 1, 32, 32, fBrickBlockHandle);
	if (fBrickBlockHandle[0] == -1)
	{
		printfDx("ERROR:fBrickBlockHandle");
		return;
	}
	bGroundBlockHandle = LoadGraph("././Resource/Images/bGroundBlock.png");
	if (bGroundBlockHandle == -1)
	{
		printfDx("ERROR:bGroundBlockHandle");
		return;
	}
	bBrickBlockHandle = LoadGraph("././Resource/Images/bBrickBlock.png");
	if (bBrickBlockHandle == -1)
	{
		printfDx("ERROR:bBrickBlockHandle");
		return;
	}
	unBreakBlockHandle = LoadGraph("././Resource/Images/UnBreakBlock.png");
	if (unBreakBlockHandle == -1)
	{
		printfDx("ERROR:unBreakBlockHandle");
		return;
	}
	LoadDivGraph("././Resource/Images/QuestionBlock.png", 4, 4, 1, 32, 32, questionBlockHandle);
	if (questionBlockHandle[0] == -1)
	{
		printfDx("ERROR:questionBlockHandle");
		return;
	}

	// アイテム系
	LoadDivGraph("././Resource/Images/Coins_01.png", 3, 3, 1, 32, 32, fCoinHandle);
	if (fCoinHandle[0] == -1)
	{
		printfDx("ERROR:fCoinHandle");
		return;
	}
	LoadDivGraph("././Resource/Images/Coins_02.png", 3, 3, 1, 32, 32, bCoinHandle);
	if (bCoinHandle[0] == -1)
	{
		printfDx("ERROR:bCoinHandle");
		return;
	}
	mushroomHandle = LoadGraph("././Resource/Images/Mushroom.png");
	if (mushroomHandle == -1)
	{
		printfDx("ERROR:mushroomHandle");
		return;
	}
	oneUpMushroomHandle = LoadGraph("././Resource/Images/1UPMushroom.png");
	if (oneUpMushroomHandle == -1)
	{
		printfDx("ERROR:oneUpMushroomHandle");
		return;
	}
	LoadDivGraph("././Resource/Images/Star.png", 4, 4, 1, 32, 32, starHandle);
	if (starHandle[0] == -1)
	{
		printfDx("ERROR:starHandle");
		return;
	}

	// キャラクター計
	LoadDivGraph("././Resource/Images/NormalMario.png", 9, 3, 3, 32, 32, normalMarioHandle);
	if (normalMarioHandle[0] == -1)
	{
		printfDx("ERROE:normalMarioHandle");
		return;
	}
	LoadDivGraph("././Resource/Images/Goomba.png", 3, 3, 1, 32, 32, goombaHandle);
	if (goombaHandle[0] == -1)
	{
		printfDx("ERROR:goombaHandle");
		return;
	}
	LoadDivGraph("././Resource/Images/KoopaTroopa.png", 4, 4, 1, 32, 45, koopaTroopaHandle);
	if (koopaTroopaHandle[0] == -1)
	{
		printfDx("ERROR:koopaTroopaHandle");
		return;
	}

	printfDx("NONERROR");
}

void ImageManager::DeleteImages()
{
	// ブロック系
	DeleteGraph(fGroundBlockHnadle);
	DeleteImageArray(fBrickBlockHandle, 2);
	DeleteGraph(bGroundBlockHandle);
	DeleteGraph(bBrickBlockHandle);
	DeleteImageArray(questionBlockHandle, 4);
	DeleteGraph(unBreakBlockHandle);
	// アイテム系
	DeleteImageArray(fCoinHandle, 3);
	DeleteImageArray(bCoinHandle, 3);
	DeleteGraph(mushroomHandle);
	DeleteGraph(oneUpMushroomHandle);
	DeleteImageArray(starHandle, 4);
	// キャラクター系
	DeleteImageArray(normalMarioHandle, 9);
	DeleteImageArray(goombaHandle, 3);
	DeleteImageArray(koopaTroopaHandle, 4);
}

void ImageManager::DeleteImageArray(int* handle_, int size)
{
	for (int i = 0; i < size; ++i)
	{
		DeleteGraph(handle_[i]);
	}
}