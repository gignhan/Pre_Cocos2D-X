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

#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "SettingScene.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    return MainMenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("./Sprites/bg_for_game.png");
	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(Vec2(0, 0));
	addChild(background);

	auto logo = Sprite::create("./Sprites/Logo/logo.png");
	logo->setAnchorPoint(Vec2(0,0));
	logo->setPosition(Vec2(40,400));
	addChild(logo);

	auto PlayItem = MenuItemImage::create("./Buttons/play_normal.png", "./Buttons/play_pressed.png",CC_CALLBACK_1(MainMenuScene::menuGamePlayCallback, this));
	auto SetItem = MenuItemImage::create("./Buttons/setting_normal.png", "./Buttons/setting_pressed.png", CC_CALLBACK_1(MainMenuScene::menuSettingCallback, this));
	PlayItem->setScale(0.5f);
	PlayItem->setPosition(250, 300);
	SetItem->setScale(0.5f);
	SetItem->setPosition(460,20);
	auto myMenu = Menu::create(PlayItem,SetItem, nullptr);
	myMenu->setPosition(0, 0);
	addChild(myMenu);

	

    return true;
}


void MainMenuScene::menuCloseCallback(Ref* pSender)
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
void MainMenuScene::menuSettingCallback(cocos2d::Ref * pSender)
{
	auto setting = SettingScene::createScene();
	Director::getInstance()->replaceScene(setting);
}

void MainMenuScene::menuGamePlayCallback(cocos2d::Ref * pSender)
{
	auto gameplay = GamePlayScene::createScene();
	Director::getInstance()->replaceScene(gameplay);
}

