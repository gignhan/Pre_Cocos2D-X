/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "LoadingScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* LoadingScene::createScene()
{
    return LoadingScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool LoadingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	scheduleUpdate();
	ResourceManager * resource = new ResourceManager();
	resource->Init("Data.bin");
	Sprite* background = resource->getBackGround();
	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(0, 0);
	background->setScale(0.7f);
	this->addChild(background);
	addLoading();
	this->schedule(schedule_selector(LoadingScene::changeMainMenu), 3.0f);
    return true;
}


void LoadingScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

void LoadingScene::addLoading()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto originSize = Director::getInstance()->getVisibleOrigin();

	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("./Sprites/Loading/loading1.plist", "./Sprites/Loading/loading1.png");
	auto loading = Sprite::create();
	loading->setPosition(Vec2(visibleSize.width / 2 + originSize.x, visibleSize.height / 2 + originSize.y));
	addChild(loading);
	Vector<SpriteFrame*> spriteFrames;
	int maxFrame = 36;
	const auto maxChar = 35;
	char frameName[maxChar] = { 0 };
	for (int i = 0; i <= maxFrame; i++) {
		sprintf(frameName, "frame_%d.png", i);
		spriteFrames.pushBack(spriteCache->getSpriteFrameByName(frameName));
	}
	auto animation = Animation::createWithSpriteFrames(spriteFrames, 0.15f);
	auto animate = Animate::create(animation);
	loading->runAction(RepeatForever::create(animate));
}
void LoadingScene::changeMainMenu(float dt)
{
	auto myScene = MainMenuScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(2.0f, myScene));
}
void LoadingScene::update(float deltaTime)
{
}