#ifndef __ONLINEGAME_SCENE_H__
#define __ONLINEGAME_SCENE_H__

#include "cocos2d.h"
#include <vector>
#include "sock.h"
#include"GameScene.h"
USING_NS_CC;
//enum type
//{
//	tag_o = 0,
//	tag_x,
//	tag_none
//};
//enum gameState
//{
//	o_win = 0,
//	x_win,
//	none_win,
//	undone
//};
class OnlineGameScene : public Layer
{
public:
	OnlineGameScene();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(OnlineGameScene);
	virtual void onTouchEnded(Touch*, Event*);
	virtual bool onTouchBegan(Touch*, Event*);
	gameState getState();
	void restart();
	void setFlag(std::string t);

	//启动服务器  
	void makeServer(Ref*);

	//启动客服端  
	void makeClient(Ref*);
	//接受连接  
	void Accept(Ref*);
	void First(Ref*);
	void scheduleRecv();
	void Send(char*);
private:
	std::vector<std::vector<type> > data;
	type flag;
	bool myTurn;
    SockServer* _server;
	SockClient* _client;
};
#endif

