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

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "ResourceManager.h"

//ResourceManager::ResourceManager()
//{
//
//}

ResourceManager::~ResourceManager()
{
}

ResourceManager * ResourceManager::getInstance()
{
	if (!s_instance) s_instance = new ResourceManager();
	return s_instance;
}

void ResourceManager::Init(const string path)
{
	Load("Data.bin");
}

void ResourceManager::Load(string fileName)
{
	auto isExit = FileUtils::getInstance()->isFileExist(fileName);
	string content = "";
	if (isExit) {
		auto file = FileUtils::getInstance()->getStringFromFile(fileName);
	}
	stringstream ss(content);
	string line;
	string text, numberLine, idPath;
	getline(ss, line, '\n');
	istringstream is(line);
	is >> text >> numberLine;
	int size = stoi(numberLine);
	if (text == "#SPRITE")
	{
		for (int i = 0; i < size; i++)
		{
			getline(ss, line, '\n');
			string num, idPath;
			istringstream idLine(line);
			idLine >> text >> num;

			getline(ss, line, '\n');
			istringstream pathLine(line);
			pathLine >> text >> idPath;

			int id = stoi(num);
			auto sprite = Sprite::create(idPath);
			this->m_Sprites.insert(id, sprite);

		}
	}
	if (text == "#BUTTON")
	{
		for (int i = 0; i < size; i++)
		{
			getline(ss, line, '\n');
			string num, idPath,idPath1;
			istringstream idLine(line);
			idLine >> text >> num;

			getline(ss, line, '\n');
			istringstream pathLine(line);
			pathLine >> text >> idPath;

			getline(ss, line, '\n');
			istringstream pathLine1(line);
			pathLine1 >> text >> idPath1;

			int id = stoi(num);
			auto button = ui::Button::create(idPath,idPath1);
			this->m_Buttons.insert(id, button);
		}
	}
	if (text == "#FONT")
	{
		for (int i = 0; i < size; i++)
		{
			getline(ss, line, '\n');
			string num, idPath;
			istringstream idLine(line);
			idLine >> text >> num;

			getline(ss, line, '\n');
			istringstream pathLine(line);
			pathLine >> text >> idPath;

			int id = stoi(num);
			auto label = Label::create("Hello",idPath,24);
			this->m_Labels.insert(id, label);

		}
	}

}

Sprite * ResourceManager::getSpriteById(char id)
{
	return m_Sprites.at(id);
}

ui::Button * ResourceManager::getButtonById(char id)
{
	return m_Buttons.at(id);
}

Label * ResourceManager::getLabelById(char id)
{
	return m_Labels.at(id);
}
Sprite* ResourceManager::GetBackgroundSprite()
{
	Sprite* bg = Sprite::create("./Sprites/background.png");
	bg->retain();
	return bg;
}
