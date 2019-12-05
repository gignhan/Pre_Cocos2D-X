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
#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"
#include<string>
#include<iostream>

//#include "SimpleAudioEngine.h"
using namespace std;
//using namespace ui;
USING_NS_CC;
class ResourceManager
{
private: 
	 static ResourceManager* s_instance;
	  string m_dataFolderPath;
	  Map<char, Sprite*> m_Sprites;
	  Map<char, ui::Button*> m_Buttons;
	  Map<char, Label*> m_Labels;
public:
	ResourceManager();
	~ResourceManager();
	static ResourceManager* getInstance();
	 void Init(const string path );
	 void Load(string fileName);
	 Sprite* getSpriteById(char id);
	 ui::Button* getButtonById(char id);
	 Label* getLabelById(char id);
	 Sprite* getBackGround();
};
#endif
