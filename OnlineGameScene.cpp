//#include "OnlineGameScene.h"
//#include"HelloWorldScene.h"
//OnlineGameScene::OnlineGameScene()
//{
//	std::vector<type> temp(3);
//	for (std::vector<type>::iterator it = temp.begin(); it != temp.end(); it++)
//		*it = tag_none;
//	for (int i = 0; i < 3; i++)
//		data.push_back(temp);
//	flag = tag_none;
//	myTurn = false;
//	f = false;
//}
//Scene* OnlineGameScene::createScene()
//{
//	Scene* scene = Scene::create();
//	Layer* layer = OnlineGameScene::create();
//	scene->addChild(layer);
//	return scene;
//}
//bool OnlineGameScene::init()
//{
//	if (!Layer::init())
//	{
//		return false;
//	}
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	auto bg = Sprite::create("backgroundGame.png");
//	bg->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
//	addChild(bg);
//	auto labelMakeServer = Label::create("Make Server", "Arial", 20);
//	auto menuMakeServer = MenuItemLabel::create(labelMakeServer, CC_CALLBACK_1(OnlineGameScene::makeServer, this));
//	auto labelMakeClient = Label::create("Make Client", "Arial", 20);
//	auto menuMakeClient = MenuItemLabel::create(labelMakeClient, CC_CALLBACK_1(OnlineGameScene::makeClient, this));
//	auto labelAccept = Label::create("Accept", "Arial", 20);
//	auto menuAccept = MenuItemLabel::create(labelAccept, CC_CALLBACK_1(OnlineGameScene::Accept, this));
//	auto labelFirst = Label::create("First", "Arial", 20);
//	auto menuFirst = MenuItemLabel::create(labelFirst, CC_CALLBACK_1(OnlineGameScene::First, this));
//	auto menu = Menu::create(menuMakeServer, menuMakeClient, menuAccept, menuFirst, NULL);
//	menu->alignItemsInColumns(2, 2, NULL);
//	menu->setPosition(visibleSize.width / 2, visibleSize.height * 7 / 8);
//	addChild(menu);
//	/*auto flag = Sprite::create("o.png");
//	flag->setTag(tag_o);
//	flag->setScale(0.3);
//	flag->setPosition(visibleSize.width / 2, visibleSize.height / 12);
//	addChild(flag);
//	auto label = Label::create("turns", "Arial", 20);
//	label->setPosition(visibleSize.width * 2 / 3, visibleSize.height / 12);
//	addChild(label);
//	auto listener = EventListenerTouchOneByOne::create();
//	listener->setSwallowTouches(true);
//	listener->onTouchBegan = CC_CALLBACK_2(OnlineGameScene::onTouchBegan, this);
//	listener->onTouchEnded = CC_CALLBACK_2(OnlineGameScene::onTouchEnded, this);
//	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);*/
//	schedule(schedule_selector(OnlineGameScene::scheduleRecv), 1.0);
//	return true;
//}
//gameState OnlineGameScene::getState()
//{
//	gameState winner = undone;
//	for (int i = 0; i < 3; i++)//horizontal
//	{
//		type temp = data.at(i).at(0);
//		int j = 1;
//		for (; j < 3; j++)
//		{
//			if (data.at(i).at(j) != temp)
//				break;
//		}
//		if (j == 3 && temp != tag_none)
//		{
//			winner = temp == tag_x ? x_win : o_win;
//			return winner;
//		}
//	}
//	for (int i = 0; i < 3; i++)//vertical
//	{
//		type temp = data.at(0).at(i);
//		int j = 1;
//		for (; j < 3; j++)
//		{
//			if (data.at(j).at(i) != temp)
//				break;
//		}
//		if (j == 3 && temp != tag_none)
//		{
//			winner = temp == tag_x ? x_win : o_win;
//			return winner;
//		}
//	}
//	if (data.at(0).at(0) == data.at(1).at(1) && data.at(0).at(0) == data.at(2).at(2) && data.at(0).at(0) != tag_none)
//	{
//		winner = data.at(0).at(0) == tag_x ? x_win : o_win;
//		return winner;
//	}
//	if (data.at(0).at(2) == data.at(1).at(1) && data.at(0).at(2) == data.at(2).at(0) && data.at(2).at(0) != tag_none)
//	{
//		winner = data.at(0).at(2) == tag_x ? x_win : o_win;
//		return winner;
//	}
//	bool doneTag = true;
//	for (int i = 0; i < 3; i++)
//	{
//		if (!doneTag)
//			break;
//		for (int j = 0; j < 3; j++)
//		{
//			if (data[i][j] == tag_none)
//			{
//				doneTag = false;
//				break;
//			}
//		}
//	}
//	if (doneTag && winner == undone)
//		winner = none_win;
//	return winner;
//}
//void OnlineGameScene::restart()
//{
//	auto labelRestart = Label::create("Restart", "Arial", 20);
//	auto menuItemRestart = MenuItemLabel::create(labelRestart, [](Ref* pSender) {
//		auto scene = OnlineGameScene::createScene();
//		auto sc = TransitionFade::create(1.0f, scene);
//		Director::getInstance()->replaceScene(sc);
//	});
//	auto labelExit = Label::create("Exit", "Arial", 20);
//	auto menuItemExit = MenuItemLabel::create(labelExit, [](Ref* pSender) {
//		auto scene = HelloWorld::createScene();
//		auto sc = TransitionFade::create(1.0f, scene);
//		Director::getInstance()->replaceScene(sc);
//	});
//	auto menu = Menu::create(menuItemRestart, menuItemExit, NULL);
//	menu->alignItemsHorizontallyWithPadding(100);
//	menu->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
//	addChild(menu);
//}
//void OnlineGameScene::onTouchEnded(Touch* touch, Event* event)
//{
//	Vec2 t = touch->getLocation();
//	int i = (t.x - 15) / 110;
//	int j = (Director::getInstance()->getVisibleSize().height - t.y - 130) / 110;
//	if (i >= 0 && i < 3 && j >= 0 && j < 3 && data[i][j] == tag_none)
//	{
//		log("ok");
//		Sprite* flagSprite;
//		if (flag == tag_o)
//		{
//			flagSprite = Sprite::create("o.png");
//		}
//		else
//		{
//			flagSprite = Sprite::create("x.png");
//		}
//		data.at(i).at(j) = flag;
//		this->removeChildByTag(flag);
//		flag = flag == tag_o ? tag_x : tag_o;
//		flagSprite->setAnchorPoint(Vec2(0, 1));
//		flagSprite->setPosition(i * 110 + 15, Director::getInstance()->getVisibleSize().height - (110 * j + 130));
//		addChild(flagSprite);
//		Size visibleSize = Director::getInstance()->getVisibleSize();
//		Sprite* f;
//		if (flag == tag_o)
//		{
//			f = Sprite::create("o.png");
//		}
//		else
//		{
//			f = Sprite::create("x.png");
//		}
//		f->setTag(flag);
//		f->setScale(0.3);
//		f->setPosition(visibleSize.width / 2, visibleSize.height / 12);
//		addChild(f);
//		gameState state = getState();
//		if (state != undone)
//		{
//			Sprite* sprite;
//			switch (state)
//			{
//			case o_win:
//				sprite = Sprite::create("o_win.png");
//				break;
//			case x_win:
//				sprite = Sprite::create("x_win.png");
//				break;
//			case none_win:
//				sprite = Sprite::create("none_win.png");
//				break;
//			}
//			sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
//			addChild(sprite);
//			restart();
//		}
//	}
//}
//bool OnlineGameScene::onTouchBegan(Touch*, Event*)
//{
//	gameState  state = getState();
//	if (state == undone)
//		return true;
//	else
//		return false;
//}
////启动服务器  
//void OnlineGameScene::makeServer(Ref* pSender)
//{
//	this->_server = new SockServer(9888);
//
//	if (!this->_server->isValidSocket())
//	{
//		log("server ERR");
//	}
//	else
//	{
//		log("server OK");
//	}
//}
////启动客服端  
//void OnlineGameScene::makeClient(Ref* spSender)
//{
//	this->_client = new SockClient(9888, "127.0.0.1");
//
//	if (!this->_client->isValidSocket())
//	{
//		log("Client ERR");
//	}
//	else
//	{
//		log("Client OK");
//
//	}
//}
////接受连接  
//void OnlineGameScene::Accept(Ref* pSender)
//{
//	this->_client = this->_server->accept();
//	if (_client == NULL)
//		return;
//	if (!this->_client->isValidSocket())
//	{
//		log("Accept ERR");
//	}
//	else
//	{
//		/*char* temp = "HelloW";
//		this->_client->send(temp, strlen(temp) + 1);*/
//		log("Accept OK");
//	}
//}
//void OnlineGameScene::recv(Ref *)
//{
//	if (_client->isValidSocket())
//	{
//		char temp[3];
//		_client->recv(temp, sizeof(temp));
//		log(temp);
//	}
//}
//void OnlineGameScene::First(Ref * pSender)
//{
//	if (flag == tag_none)
//	{
//		_client->send("33", 3);
//		myTurn = true;
//		flag = tag_o;
//	}
//}
//void OnlineGameScene::scheduleRecv(float delta)
//{
//	if (f == false)
//	{
//		if (_client == NULL)
//			return;
//		f = true;
//		char data[3];
//		_client->recv(data, sizeof(data));
//		if (data[0] == '3' && data[1] == '3')
//		{
//			myTurn = false;
//			flag = tag_x;
//			log("recv first");
//			f = false;
//		}
//	}
//}
//#include "OnlineGameScene.h"
//#include"HelloWorldScene.h"
//OnlineGameScene::OnlineGameScene()
//{
//	std::vector<type> temp(3);
//	for (std::vector<type>::iterator it = temp.begin(); it != temp.end(); it++)
//		*it = tag_none;
//	for (int i = 0; i < 3; i++)
//		data.push_back(temp);
//	myTurn = false;
//	flag = tag_none;
//	f = false;
//	_server = NULL;
//	_client = NULL;
//}
//Scene* OnlineGameScene::createScene()
//{
//	Scene* scene = Scene::create();
//	Layer* layer = OnlineGameScene::create();
//	scene->addChild(layer);
//	return scene;
//}
//bool OnlineGameScene::init()
//{
//	if (!Layer::init())
//	{
//		return false;
//	}
//
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	auto bg = Sprite::create("backgroundGame.png");
//	bg->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
//	addChild(bg);
//
//	auto labelMakeServer = Label::create("Make Server", "Arial", 20);
//	auto menuMakeServer = MenuItemLabel::create(labelMakeServer, CC_CALLBACK_1(OnlineGameScene::makeServer, this));
//	auto labelMakeClient = Label::create("Make Client", "Arial", 20);
//	auto menuMakeClient = MenuItemLabel::create(labelMakeClient, CC_CALLBACK_1(OnlineGameScene::makeClient, this));
//	auto labelAccept = Label::create("Accept", "Arial", 20);
//	auto menuAccept = MenuItemLabel::create(labelAccept, CC_CALLBACK_1(OnlineGameScene::Accept, this));
//	auto labelFirst = Label::create("First", "Arial", 20);
//	auto menuFirst = MenuItemLabel::create(labelFirst, CC_CALLBACK_1(OnlineGameScene::First, this));
//	auto menu = Menu::create(menuMakeServer, menuMakeClient, menuAccept, menuFirst, NULL);
//	menu->alignItemsInColumns(2, 2, NULL);
//	menu->setPosition(visibleSize.width / 2, visibleSize.height * 7 / 8);
//	addChild(menu);
//	std::thread t(std::mem_fn(&OnlineGameScene::scheduleRecv), this);
//	t.detach();
//	/*schedule(schedule_selector(OnlineGameScene::scheduleRecv), 1.0);*/
//	auto flag = Sprite::create("o.png");
//	flag->setTag(tag_o);
//	flag->setScale(0.3);
//	flag->setPosition(visibleSize.width / 2, visibleSize.height / 12);
//	addChild(flag);
//	auto label = Label::create("turns", "Arial", 20);
//	label->setPosition(visibleSize.width * 2 / 3, visibleSize.height / 12);
//	addChild(label);
//	auto listener = EventListenerTouchOneByOne::create();
//	listener->setSwallowTouches(true);
//	listener->onTouchBegan = CC_CALLBACK_2(OnlineGameScene::onTouchBegan, this);
//	listener->onTouchEnded = CC_CALLBACK_2(OnlineGameScene::onTouchEnded, this);
//	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
//	return true;
//
//}
//gameState OnlineGameScene::getState()
//{
//	gameState winner = undone;
//	for (int i = 0; i < 3; i++)//horizontal
//	{
//		type temp = data.at(i).at(0);
//		int j = 1;
//		for (; j < 3; j++)
//		{
//			if (data.at(i).at(j) != temp)
//				break;
//		}
//		if (j == 3 && temp != tag_none)
//		{
//			winner = temp == tag_x ? x_win : o_win;
//			return winner;
//		}
//	}
//	for (int i = 0; i < 3; i++)//vertical
//	{
//		type temp = data.at(0).at(i);
//		int j = 1;
//		for (; j < 3; j++)
//		{
//			if (data.at(j).at(i) != temp)
//				break;
//		}
//		if (j == 3 && temp != tag_none)
//		{
//			winner = temp == tag_x ? x_win : o_win;
//			return winner;
//		}
//	}
//	if (data.at(0).at(0) == data.at(1).at(1) && data.at(0).at(0) == data.at(2).at(2) && data.at(0).at(0) != tag_none)
//	{
//		winner = data.at(0).at(0) == tag_x ? x_win : o_win;
//		return winner;
//	}
//	if (data.at(0).at(2) == data.at(1).at(1) && data.at(0).at(2) == data.at(2).at(0) && data.at(2).at(0) != tag_none)
//	{
//		winner = data.at(0).at(2) == tag_x ? x_win : o_win;
//		return winner;
//	}
//	bool doneTag = true;
//	for (int i = 0; i < 3; i++)
//	{
//		if (!doneTag)
//			break;
//		for (int j = 0; j < 3; j++)
//		{
//			if (data[i][j] == tag_none)
//			{
//				doneTag = false;
//				break;
//			}
//		}
//	}
//	if (doneTag && winner == undone)
//		winner = none_win;
//	return winner;
//}
//void OnlineGameScene::restart()
//{
//	auto labelRestart = Label::create("Restart", "Arial", 20);
//	auto menuItemRestart = MenuItemLabel::create(labelRestart, [](Ref* pSender) {
//		auto scene = OnlineGameScene::createScene();
//		auto sc = TransitionFade::create(1.0f, scene);
//		Director::getInstance()->replaceScene(sc);
//	});
//	auto labelExit = Label::create("Exit", "Arial", 20);
//	auto menuItemExit = MenuItemLabel::create(labelExit, [](Ref* pSender) {
//		auto scene = HelloWorld::createScene();
//		auto sc = TransitionFade::create(1.0f, scene);
//		Director::getInstance()->replaceScene(sc);
//	});
//	auto menu = Menu::create(menuItemRestart, menuItemExit, NULL);
//	menu->alignItemsHorizontallyWithPadding(100);
//	menu->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
//	addChild(menu);
//}
//void OnlineGameScene::onTouchEnded(Touch* touch, Event* event)
//{
//	Vec2 t = touch->getLocation();
//	int i = (t.x - 15) / 110;
//	int j = (Director::getInstance()->getVisibleSize().height - t.y - 130) / 110;
//	if (i >= 0 && i < 3 && j >= 0 && j < 3 && data[i][j] == tag_none)
//	{
//		char temp[4];
//		temp[0] = '1';
//		temp[1] = '0' + i;
//		temp[2] = '0' + j;
//		temp[3] = '\0';
//		log(temp);
//		_client->send(temp, strlen(temp) + 1);
//		log("sendok");
//		Sprite* flagSprite;
//		if (flag == tag_o)
//		{
//			flagSprite = Sprite::create("o.png");
//		}
//		else
//		{
//			flagSprite = Sprite::create("x.png");
//		}
//		data.at(i).at(j) = flag;
//		this->removeChildByTag(flag);
//		auto nextFlag = flag == tag_o ? tag_x : tag_o;
//		flagSprite->setAnchorPoint(Vec2(0, 1));
//		flagSprite->setPosition(i * 110 + 15, Director::getInstance()->getVisibleSize().height - (110 * j + 130));
//		addChild(flagSprite);
//		myTurn = false;
//		Size visibleSize = Director::getInstance()->getVisibleSize();
//		Sprite* f;
//		if (nextFlag == tag_o)
//		{
//			f = Sprite::create("o.png");
//		}
//		else
//		{
//			f = Sprite::create("x.png");
//		}
//		f->setTag(flag);
//		f->setScale(0.3);
//		f->setPosition(visibleSize.width / 2, visibleSize.height / 12);
//		addChild(f);
//		gameState state = getState();
//		if (state != undone)
//		{
//			Sprite* sprite;
//			switch (state)
//			{
//			case o_win:
//				sprite = Sprite::create("o_win.png");
//				break;
//			case x_win:
//				sprite = Sprite::create("x_win.png");
//				break;
//			case none_win:
//				sprite = Sprite::create("none_win.png");
//				break;
//			}
//			sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
//			addChild(sprite);
//			restart();
//		}
//	}
//}
//bool OnlineGameScene::onTouchBegan(Touch*, Event*)
//{
//	if (!myTurn)
//		return false;
//	gameState  state = getState();
//	if (state == undone)
//		return true;
//	else
//		return false;
//}
////启动服务器  
//void OnlineGameScene::makeServer(Ref* pSender)
//{
//	this->_server = new SockServer(9888);
//
//	if (!this->_server->isValidSocket())
//	{
//		log("server ERR");
//	}
//	else
//	{
//		log("server OK");
//	}
//}
//
//
////启动客服端  
//void OnlineGameScene::makeClient(Ref* spSender)
//{
//	this->_client = new SockClient(9888, "127.0.0.1");
//
//	if (!this->_client->isValidSocket())
//	{
//		log("Client ERR");
//	}
//	else
//	{
//		log("Client OK");
//
//	}
//}
////接受连接  
//void OnlineGameScene::Accept(Ref* pSender)
//{
//	this->_client = this->_server->accept();
//	if (_client == NULL)
//		return;
//	if (!this->_client->isValidSocket())
//	{
//		log("Accept ERR");
//	}
//	else
//	{
//		/*char* temp = "Hello";
//		this->_client->send(temp, strlen(temp) + 1);*/
//		log("Accept OK");
//	}
//}
//void OnlineGameScene::First(Ref * pSender)
//{
//	if (flag == tag_none)
//	{
//		log("first");
//		_client->send("133", 4);
//		myTurn = true;
//		flag = tag_o;
//	}
//}
//
//void OnlineGameScene::scheduleRecv()
//{
//	while (1)
//	{
//		if (_client == NULL)
//			continue;
//		char temp[8];
//		_client->recv(temp, sizeof(temp));
//		if (temp[0] == '1')
//		{
//			if (temp[1] == '3' && temp[2] == '3')
//			{
//				myTurn = false;
//				flag = tag_x;
//				log("recv first");
//				
//			}
//			else if (temp[2] >= '0' && temp[2] < '3' && temp[1] >= '0' && temp[1] < '3')
//			{
//				log("getKeys");
//				myTurn = true;
//				Sprite* flagSprite = Sprite::create("x.png");
//				/*if (flag == tag_o)
//				{
//					flagSprite = Sprite::create("o.png");
//				}
//				else
//				{
//					flagSprite = Sprite::create("x.png");
//				}*/
//				log(temp);
//				data[temp[1] - '0'][temp[2] - '0'] = flag;
//				if (flagSprite != NULL)
//				{
//					log("recv keys");
//					auto sprite = Sprite::create("o.png");
//					sprite->setPosition((temp[1] - '0') * 110 + 15, Director::getInstance()->getVisibleSize().height - (110 * (temp[2] - '0') + 130));
//					sprite->setAnchorPoint(Vec2(0, 1));
//					addChild(sprite);
//					//flagSprite->setAnchorPoint(Vec2(0, 1));
//					//flagSprite->setPosition((temp[1] - '0') * 110 + 15, Director::getInstance()->getVisibleSize().height - (110 * (temp[2] - '0') + 130));
//					//addChild(flagSprite);
//				}
//				this->removeChildByTag(flag);
//				auto nextFlag = flag == tag_o ? tag_x : tag_o;
//				Size visibleSize = Director::getInstance()->getVisibleSize();
//				Sprite* f;
//				if (nextFlag == tag_o)
//				{
//					f = Sprite::create("o.png");
//				}
//				else
//				{
//					f = Sprite::create("x.png");
//				}
//				f->setTag(flag);
//				f->setScale(0.3);
//				f->setPosition(visibleSize.width / 2, visibleSize.height / 12);
//				addChild(f);
//				gameState state = getState();
//				if (state != undone)
//				{
//					Sprite* sprite;
//					switch (state)
//					{
//					case o_win:
//						sprite = Sprite::create("o_win.png");
//						break;
//					case x_win:
//						sprite = Sprite::create("x_win.png");
//						break;
//					case none_win:
//						sprite = Sprite::create("none_win.png");
//						break;
//					}
//					sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
//					addChild(sprite);
//					restart();
//				}
//			}
//		}
//		memset(temp, '0', sizeof(temp));
//	}
//
//}
#include "OnlineGameScene.h"
#include"HelloWorldScene.h"
OnlineGameScene::OnlineGameScene()
{
	std::vector<type> temp(3);
	for (std::vector<type>::iterator it = temp.begin(); it != temp.end(); it++)
		*it = tag_none;
	for (int i = 0; i < 3; i++)
		data.push_back(temp);
	myTurn = false;
	flag = tag_none;
	_server = NULL;
	_client = NULL;
}
Scene* OnlineGameScene::createScene()
{
	Scene* scene = Scene::create();
	Layer* layer = OnlineGameScene::create();
	scene->addChild(layer);
	return scene;
}
bool OnlineGameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto bg = Sprite::create("backgroundGame.png");
	bg->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	addChild(bg);

	auto labelMakeServer = Label::create("Make Server", "Arial", 20);
	auto menuMakeServer = MenuItemLabel::create(labelMakeServer, CC_CALLBACK_1(OnlineGameScene::makeServer, this));
	auto labelMakeClient = Label::create("Make Client", "Arial", 20);
	auto menuMakeClient = MenuItemLabel::create(labelMakeClient, CC_CALLBACK_1(OnlineGameScene::makeClient, this));
	auto labelAccept = Label::create("Accept", "Arial", 20);
	auto menuAccept = MenuItemLabel::create(labelAccept, CC_CALLBACK_1(OnlineGameScene::Accept, this));
	auto labelFirst = Label::create("First", "Arial", 20);
	auto menuFirst = MenuItemLabel::create(labelFirst, CC_CALLBACK_1(OnlineGameScene::First, this));
	auto menu = Menu::create(menuMakeServer, menuMakeClient, menuAccept, menuFirst, NULL);
	menu->alignItemsInColumns(2, 2, NULL);
	menu->setPosition(visibleSize.width / 2, visibleSize.height * 7 / 8);
	addChild(menu);
	/*schedule(schedule_selector(OnlineGameScene::scheduleRecv), 1.0);*/
	auto flag = Sprite::create("o.png");
	//flag->setTag(tag_o);
	flag->setScale(0.3);
	flag->setPosition(visibleSize.width / 2, visibleSize.height / 12);
	addChild(flag);
	auto label = Label::create("turns", "Arial", 20);
	label->setPosition(visibleSize.width * 2 / 3, visibleSize.height / 12);
	addChild(label);
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(OnlineGameScene::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(OnlineGameScene::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	std::thread t(std::mem_fn(&OnlineGameScene::scheduleRecv), this);
	t.detach();
	return true;

}
gameState OnlineGameScene::getState()
{
	gameState winner = undone;
	for (int i = 0; i < 3; i++)//horizontal
	{
		type temp = data.at(i).at(0);
		int j = 1;
		for (; j < 3; j++)
		{
			if (data.at(i).at(j) != temp)
				break;
		}
		if (j == 3 && temp != tag_none)
		{
			winner = temp == tag_x ? x_win : o_win;
			return winner;
		}
	}
	for (int i = 0; i < 3; i++)//vertical
	{
		type temp = data.at(0).at(i);
		int j = 1;
		for (; j < 3; j++)
		{
			if (data.at(j).at(i) != temp)
				break;
		}
		if (j == 3 && temp != tag_none)
		{
			winner = temp == tag_x ? x_win : o_win;
			return winner;
		}
	}
	if (data.at(0).at(0) == data.at(1).at(1) && data.at(0).at(0) == data.at(2).at(2) && data.at(0).at(0) != tag_none)
	{
		winner = data.at(0).at(0) == tag_x ? x_win : o_win;
		return winner;
	}
	if (data.at(0).at(2) == data.at(1).at(1) && data.at(0).at(2) == data.at(2).at(0) && data.at(2).at(0) != tag_none)
	{
		winner = data.at(0).at(2) == tag_x ? x_win : o_win;
		return winner;
	}
	bool doneTag = true;
	for (int i = 0; i < 3; i++)
	{
		if (!doneTag)
			break;
		for (int j = 0; j < 3; j++)
		{
			if (data[i][j] == tag_none)
			{
				doneTag = false;
				break;
			}
		}
	}
	if (doneTag && winner == undone)
		winner = none_win;
	return winner;
}
void OnlineGameScene::restart()
{
	auto labelRestart = Label::create("Restart", "Arial", 20);
	auto menuItemRestart = MenuItemLabel::create(labelRestart, [](Ref* pSender) {
		auto scene = OnlineGameScene::createScene();
		auto sc = TransitionFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(sc);
	});
	auto labelExit = Label::create("Exit", "Arial", 20);
	auto menuItemExit = MenuItemLabel::create(labelExit, [](Ref* pSender) {
		auto scene = HelloWorld::createScene();
		auto sc = TransitionFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(sc);
	});
	auto menu = Menu::create(menuItemRestart, menuItemExit, NULL);
	menu->alignItemsHorizontallyWithPadding(100);
	menu->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	addChild(menu);
}
void OnlineGameScene::setFlag(std::string t)
{
	auto sprite = Sprite::create(t);
	sprite->setTag(flag);
	sprite->setScale(0.3);
	sprite->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 12);
	addChild(sprite);
}
void OnlineGameScene::onTouchEnded(Touch* touch, Event* event)
{
	Vec2 t = touch->getLocation();
	int i = (t.x - 15) / 110;
	int j = (Director::getInstance()->getVisibleSize().height - t.y - 130) / 110;
	if (i >= 0 && i < 3 && j >= 0 && j < 3 && data[i][j] == tag_none)
	{
		char temp[4];
		temp[0] = '1';
		temp[1] = '0' + i;
		temp[2] = '0' + j;
		temp[3] = '\0';
		log(temp);
		
		// _client->send(temp, strlen(temp) + 1);
		log("sendok");
		std::string tmp;
		if (flag == tag_o)
		{
			tmp = "o.png";
		}
		else
		{
			tmp = "x.png";
		}
		data.at(i).at(j) = flag;
		this->removeChildByTag(flag);
		auto nextFlag = flag == tag_o ? tag_x : tag_o;

		auto flagSprite = Sprite::create(tmp.c_str());
		flagSprite->setAnchorPoint(Vec2(0, 1));
		flagSprite->setPosition(i * 110 + 15, Director::getInstance()->getVisibleSize().height - (110 * j + 130));
		addChild(flagSprite);
         std::thread t(&OnlineGameScene::Send, this, temp);
		t.join();
		myTurn = false;
		Size visibleSize = Director::getInstance()->getVisibleSize();
		/*if (nextFlag == tag_o)
		{
			tmp = "o.png";
		}
		else
		{
			tmp = "x.png";
		}
		auto f = Sprite::create(tmp);
		f->setTag(nextFlag);
		f->setScale(0.3);
		f->setPosition(visibleSize.width / 2, visibleSize.height / 12);
		addChild(f);*/
		gameState state = getState();
		if (state != undone)
		{
			switch (state)
			{
			case o_win:
				tmp = "o_win.png";
				break;
			case x_win:
				tmp = "x_win.png";
				break;
			case none_win:
				tmp = "none_win.png";
				break;
			}
			auto sprite = Sprite::create(tmp.c_str());
			sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
			addChild(sprite);
			restart();
		}
	}
}
bool OnlineGameScene::onTouchBegan(Touch*, Event*)
{
	if (!myTurn)
		return false;
	gameState  state = getState();
	if (state == undone)
		return true;
	else
		return false;
}
//启动服务器  
void OnlineGameScene::makeServer(Ref* pSender)
{
	this->_server = new SockServer(9888);

	if (!this->_server->isValidSocket())
	{
		log("server ERR");
	}
	else
	{
		log("server OK");
	}
}


//启动客服端  
void OnlineGameScene::makeClient(Ref* spSender)
{
	this->_client = new SockClient(9888, "127.0.0.1");

	if (!this->_client->isValidSocket())
	{
		log("Client ERR");
	}
	else
	{
		log("Client OK");

	}
}
//接受连接  
void OnlineGameScene::Accept(Ref* pSender)
{
	this->_client = this->_server->accept();
	if (_client == NULL)
		return;
	if (!this->_client->isValidSocket())
	{
		log("Accept ERR");
	}
	else
	{
		/*char* temp = "Hello";
		this->_client->send(temp, strlen(temp) + 1);*/
		log("Accept OK");
	}
}
void OnlineGameScene::First(Ref * pSender)
{
	if (flag == tag_none)
	{
		log("first");
		_client->send("133", 4);
		myTurn = true;
		flag = tag_x;
	}
}

void OnlineGameScene::scheduleRecv()
{
	while (1)
	{
		if (_client == NULL)
			continue;
		char temp[8];
		_client->recv(temp, sizeof(temp));
		if (temp[0] == '1')
		{
			if (temp[1] == '3' && temp[2] == '3')
			{
				myTurn = false;
				flag = tag_o;
				log("recv first");
			}
			else if (temp[2] >= '0' && temp[2] < '3' && temp[1] >= '0' && temp[1] < '3')
			{
				log("getKeys");
				myTurn = true;
				std::string tmp;
				if (flag == tag_o)
				{
					tmp = "x.png";
				}
				else if(flag == tag_x)
				{
					tmp = "o.png";
				}
				log(temp);
				auto nextFlag = flag == tag_o ? tag_x : tag_o;
				data[temp[1] - '0'][temp[2] - '0'] = nextFlag;
				log("recv keys");
				auto g = Sprite::create("x.png");
				g->setPosition(0, 0);
				g->setAnchorPoint(Vec2(0, 0));
				addChild(g);
				auto sprite = Sprite::create(tmp.c_str());
				sprite->setPosition((temp[1] - '0') * 110 + 15, Director::getInstance()->getVisibleSize().height - (110 * (temp[2] - '0') + 130));
				sprite->setAnchorPoint(Vec2(0, 1));
				this->addChild(sprite);
				Size visibleSize = Director::getInstance()->getVisibleSize();
				/*this->removeChildByTag(nextFlag);

				
				std::string t;
				if (flag == tag_o)
				{
					t = "o.png";
				}
				else
				{
					t = "x.png";
				}*/
				//log(t.c_str());
				//log("turn");
				//setFlag(t);
				gameState state = getState();
				if (state != undone)
				{
					std::string tm;
					switch (state)
					{
					case o_win:
						tm = "o_win.png";
						break;
					case x_win:
						tm = "x_win.png";
						break;
					case none_win:
						tm = "none_win.png";
						break;
					}
					auto sprite = Sprite::create(tm.c_str());
					sprite->setPosition(visibleSize.width / 2, visibleSize.height / 2);
					addChild(sprite);
					restart();
				}
			}
		}
		memset(temp, '0', sizeof(temp));
	}

}

void OnlineGameScene::Send(char * temp)
{
	_client->send(temp, strlen(temp) + 1);
}


