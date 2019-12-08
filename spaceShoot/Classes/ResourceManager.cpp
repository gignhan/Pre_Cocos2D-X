
#include "ResourceManager.h"
ResourceManager* ResourceManager::s_instance;
ResourceManager::ResourceManager()
{

}

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
	auto isExist = FileUtils::getInstance()->isFileExist(fileName);
	string content = "";
	if (isExist) {
		content = FileUtils::getInstance()->getStringFromFile(fileName);
	}
	stringstream ss(content);
	string line;
	string text, numberLine, idPath;

	getline(ss, line, '\n');
	istringstream is(line);
	is >> text >> numberLine;
	int size = std::stoi(numberLine);
	if (text == "#SPRITE") {
		for (int i = 0; i < size; i++) {
			// get the ID line
			getline(ss, line, '\n');
			std::string number, idPath;
			std::istringstream idLine(line);
			idLine >> text >> number;
			// get PATH line
			std::getline(ss, line, '\n');
			std::istringstream pathLine(line);
			pathLine >> text >> idPath;
			// convert stringId to int
			int id = stoi(number);
			auto sprite = Sprite::create(idPath);
			this->m_Sprites.insert(id, sprite);
		}
	}
	if (text == "#BUTTON") {
		for (int i = 0; i < size; i++) {
			// get the ID line
			getline(ss, line, '\n');
			std::string number, idPath1, idPath2;
			std::istringstream idLine(line);
			idLine >> text >> number;
			// get PATH line
			std::getline(ss, line, '\n');
			std::istringstream pathLine1(line);
			pathLine1 >> text >> idPath1;
			// get PATH2 line
			std::getline(ss, line, '\n');
			std::istringstream pathLine2(line);
			pathLine2 >> text >> idPath2;
			int id = stoi(number);
			// convert stringId to int
			auto button = ui::Button::create(idPath1, idPath2);
			this->m_Buttons.insert(id, button);
		}
	}

	if (text == "#FONT") {
		for (int i = 0; i < size; i++) {
			// get the ID line
			getline(ss, line, '\n');
			std::string number, idPath1, idPath2;
			std::istringstream idLine(line);
			idLine >> text >> number;
			// get PATH line
			std::getline(ss, line, '\n');
			std::istringstream pathLine1(line);
			pathLine1 >> text >> idPath1;
			// convert stringId to int
			int id = stoi(number);
			auto label = Label::create("Hello", idPath, 24);
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

Sprite * ResourceManager::getBackGround()
{

	return getSpriteById(0);
}
