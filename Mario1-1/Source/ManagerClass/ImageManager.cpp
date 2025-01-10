#include "ImageManager.h"

int ImageManager::fGroundBlockHnadle = 0;
int ImageManager::fBrickBlockHandle[2] = { 0,0 };
int ImageManager::bGroundBlockHandle = 0;
int ImageManager::bBrickBlockHandle = 0;
int ImageManager::unBreakBlockHandle = 0;
int ImageManager::questionBlockHandle[4] = { 0,0,0,0 };
int ImageManager::fCoinHandle[3] = { 0,0,0 };
int ImageManager::bCoinHandle[3] = { 0,0,0 };
int ImageManager::mushroomHandle = 0;
int ImageManager::oneUpMushroomHandle = 0;
int ImageManager::starHandle[4] = { 0,0,0,0 };
int ImageManager::goombaHandle[3] = { 0,0,0 };
int ImageManager::koopaTroopaHandle[4] = { 0,0,0,0 };

void ImageManager::LoadImages()
{
	fGroundBlockHnadle = LoadGraph("././Resource/Images/fGroundBlock.png");
	if (fGroundBlockHnadle == -1)
	{
		printfDx("ERROR:fGroundBlockHnadle");
	}
	LoadDivGraph("././Resource/Images/fBrickBlock.png", 2, 2, 1, 32, 32, fBrickBlockHandle);
	if (fBrickBlockHandle[0] == -1)
	{
		printfDx("ERROR:fBrickBlockHandle");
	}
	bGroundBlockHandle = LoadGraph("././Resource/Images/bGroundBlock.png");
	if (bGroundBlockHandle == -1)
	{
		printfDx("ERROR:bGroundBlockHandle");
	}
	bBrickBlockHandle = LoadGraph("././Resource/Images/bBrickBlock.png");
	if (bBrickBlockHandle == -1)
	{
		printfDx("ERROR:bBrickBlockHandle");
	}
	unBreakBlockHandle = LoadGraph("././Resource/Images/UnBreakBlock.png");
	if (unBreakBlockHandle == -1)
	{
		printfDx("ERROR:unBreakBlockHandle");
	}
	LoadDivGraph("././Resource/Images/QuestionBlock.png", 4, 4, 1, 32, 32, questionBlockHandle);
	if (questionBlockHandle[0] == -1)
	{
		printfDx("ERROR:questionBlockHandle");
	}
	LoadDivGraph("././Resource/Images/Coins_01.png", 3, 3, 1, 32, 32, fCoinHandle);
	if (fCoinHandle[0] == -1)
	{
		printfDx("ERROR:fCoinHandle");
	}
	LoadDivGraph("././Resource/Images/Coins_02.png", 3, 3, 1, 32, 32, bCoinHandle);
	if (bCoinHandle[0] == -1)
	{
		printfDx("ERROR:bCoinHandle");
	}
	mushroomHandle = LoadGraph("././Resource/Images/Mushroom.png");
	if (mushroomHandle == -1)
	{
		printfDx("ERROR:mushroomHandle");
	}
	oneUpMushroomHandle = LoadGraph("././Resource/Images/1UPMushroom.png");
	if (oneUpMushroomHandle == -1)
	{
		printfDx("ERROR:oneUpMushroomHandle");
	}
	LoadDivGraph("././Resource/Images/Star.png", 4, 4, 1, 32, 32, starHandle);
	if (starHandle[0] == -1)
	{
		printfDx("ERROR:starHandle");
	}
	LoadDivGraph("././Resource/Images/Goomba.png", 3, 3, 1, 32, 32, goombaHandle);
	if (goombaHandle[0] == -1)
	{
		printfDx("ERROR:goombaHandle");
	}
	LoadDivGraph("././Resource/Images/KoopaTroopa.png", 4, 4, 1, 32, 45, koopaTroopaHandle);
	if (koopaTroopaHandle[0] == -1)
	{
		printfDx("ERROR:koopaTroopaHandle");
	}

	printfDx("FINISH:LOADIMAGES");
}

void ImageManager::DeleteImages()
{
	DeleteGraph(fGroundBlockHnadle);
	DeleteImageArray(fBrickBlockHandle, 2);
	DeleteGraph(bGroundBlockHandle);
	DeleteGraph(bBrickBlockHandle);
	DeleteImageArray(questionBlockHandle, 4);
	DeleteGraph(unBreakBlockHandle);
	DeleteImageArray(fCoinHandle, 3);
	DeleteImageArray(bCoinHandle, 3);
	DeleteGraph(mushroomHandle);
	DeleteGraph(oneUpMushroomHandle);
	DeleteImageArray(starHandle, 4);
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