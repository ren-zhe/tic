#include "sock.h"  

//���캯��  
Sock::Sock() :_fd(INVALID_SOCKET)
{

#ifdef WIN32  

	//��ʼ��Windoes�µ�Sock  
	static bool winInit = false;
	if (!winInit)
	{
		winInit = true;

		WSADATA data;
		WSAStartup(MAKEWORD(2, 2), &data);
	}
#endif  
}


//�鹹����  
Sock::~Sock()
{
	if (isValidSocket())
	{
		close();
	}
}