#include "ImageManager.h"

ImageManager::ImageManager()
{
	
	fGroundBlockHnadle = LoadGraph("././Resource/Images/fGroundBlock.png");
	LoadDivGraph("././Resource/Images/fBrickBlock.png",2,2,1,32,32,fBrickBlockHandle);
	bGroundBlockHandle = LoadGraph("././Resource/Images/bGroundBlock.png");
	bBrickBlockHandle = LoadGraph("././Resource/Images/bBrickBlock.png");
	unBreakBlockHandle = LoadGraph("././Resource/Images/UnBreakBlock.png");
	LoadDivGraph("././Resource/Images/QuestionBlock.png",4,4,1,32,32,questionBlockHandle);
	LoadDivGraph("././Resource/Images/fCoin.png",3,3,1,32,32,fCoinHandle);
	LoadDivGraph("././Resource/Images/bCoin.png",3,3,1,32,32,bCoinHandle);
	mushroomHandle = LoadGraph("././Resource/Images/Mushroom.png");
	oneUpMushroomHandle = LoadGraph("././Resource/Images/1UPMushroom.png");
	LoadDivGraph("././Resource/Images/Star.png",4,4,1,32,32,starHandle);
	LoadDivGraph("././Resource/Images/Goomba.png",3,3,1,32,32,goombaHandle);
	LoadDivGraph("././Resource/Images/KoopaTroopa.png",4,4,1,32,45,koopaTroopaHandle);
}

ImageManager::~ImageManager()
{
	DeleteGraph(fGroundBlockHnadle);
	DeleteImageArray(fBrickBlockHandle, 2);
	DeleteGraph(bGroundBlockHandle);
	DeleteGraph(bBrickBlockHandle);
	DeleteImageArray(questionBlockHandle,4);
	DeleteGraph(unBreakBlockHandle);
	DeleteImageArray(fCoinHandle,3);
	DeleteImageArray(bCoinHandle,3);
	DeleteGraph(mushroomHandle);
	DeleteGraph(oneUpMushroomHandle);
	DeleteImageArray(starHandle,4);
	DeleteImageArray(goombaHandle,3);
	DeleteImageArray(koopaTroopaHandle,4);

}

void ImageManager::DeleteImageArray(int* handle_, int size)
{
	for (int i = 0; i < size; ++i)
	{
		DeleteGraph(handle_[i]);
	}
}

void ImageManager::DebugDraw()
{
	DrawGraph(10,10,fGroundBlockHnadle,FALSE);
}