#ifndef __Sock_H__  
#define __Sock_H__  

#ifdef WIN32  
#include <WinSock2.h>  
#define SOCK_TYPE SOCKET  
#else  
#define SOCK_TYPE int  
#define INVALID_SOCKET -1  
#endif  

#define MyLog(...)   

//����Sock��  
class Sock
{
public:
	//���캯��  
	Sock();
	//��������  
	virtual ~Sock();
	//���óɷ�����ģʽ  
	bool setNonBlock()
	{
		SOCK_TYPE fd = _fd;
#ifdef WIN32  
		BOOL flg = TRUE;
		//����Socket��ģʽ  
		if (ioctlsocket(fd, FIONBIO, (unsigned long *)&flg) != 0)
		{
			return false;
		}
		return true;
#else  
		int flags = fcntl(fd, F_GETFL, 0);
		flags |= O_NONBLOCK;
		return fcntl(fd, F_SETFL, flags) != -1;
#endif  
	}
	//�ر�Sock  
	void close()
	{
#ifdef WIN32  
		closesocket(_fd);
#else  
		::close(_fd);
#endif  
	}

	void attach(SOCK_TYPE fd)
	{
		_fd = fd;
	}

	//�ж�Sock�Ƿ�Ϸ�  
	bool isValidSocket()
	{
		return _fd != INVALID_SOCKET;
	}

protected:

	SOCK_TYPE _fd;
};


//�ͻ��˵�Sock  
class SockClient : public Sock
{
public:
	//���캯��  
	SockClient(unsigned short port = 0, const char* ip = NULL)
	{
		if (port == 0 && ip == NULL)
		{
			return;
		}

		//����  
		connect(port, ip);
	}

	//��������  
	~SockClient() {}


	//����  
	//��һ���������˿�  
	//�ڶ���������ip��ַ  
	int connect(unsigned short port, const char* ip)
	{
		//����һ��Socket  
		//��һ��������AF_INET��ʾָ����ַ��(��ַ����)  
		//�ڶ���������SOCK_STREAM��ʾ��ʽ�׽���TCP(Socket����)  
		//������������0(Э��)  
		_fd = socket(AF_INET, SOCK_STREAM, 0);

		//��ַ��Ϣ�ṹ  
		struct sockaddr_in addr;

		//��ַ����  
		addr.sin_family = AF_INET;

		//�˿ں�  
		addr.sin_port = htons(port);

		//������ַ  
		addr.sin_addr.s_addr = inet_addr(ip);

		//����  
		int ret = ::connect(_fd, (struct sockaddr*)&addr, sizeof(addr));

		if (ret < 0)
		{
			MyLog("connect error errno=%d", errno);
			return -1;
		}

		return 0;
	}

	//����  
	int recv(char* buf, int len)
	{
		return ::recv(_fd, buf, len, 0);
	}

	//����  
	int send(const char* buf, int len)
	{
		return ::send(_fd, buf, len, 0);
	}
};

//�������˵�Sock  
class SockServer :public Sock
{
public:
	//���캯��  
	SockServer(unsigned short port, const char* ip = NULL)
	{
		//����  
		listen(port, ip);
	}

	//�鹹����  
	~SockServer() {}

	//��������  
	SockClient* accept()
	{
		//���ܿͻ��˵ķ�������,�ȴ��ͻ��˷���connect����  
		SOCK_TYPE fd = ::accept(_fd, NULL, NULL);

		if (fd != INVALID_SOCKET)
		{
			//����һ��SockClient  
			SockClient* ret = new SockClient;
			ret->attach(fd);
			return ret;
		}
		return NULL;
	}

protected:
	//����  
	//��һ���������˿�  
	//�ڶ���������ip��ַ  
	int listen(unsigned short port, const char* ip = NULL)
	{
		//����һ��Socket  
		//��һ��������AF_INET��ʾָ����ַ��(��ַ����)  
		//�ڶ���������SOCK_STREAM��ʾ��ʽ�׽���TCP(Socket����)  
		//������������0(Э��)  
		_fd = socket(AF_INET, SOCK_STREAM, 0);

		//��ַ��Ϣ���  
		struct sockaddr_in addr;

		//��ַ����  
		addr.sin_family = AF_INET;

		//�˿ں�  
		addr.sin_port = htons(port);

		if (ip == NULL)
		{
			//����һ����ȷ����ip��ַ  
			addr.sin_addr.s_addr = INADDR_ANY;
		}
		else
		{
			//��ip��ַת��Ϊ32λ�����������ֽ����IPV4��ַ  
			addr.sin_addr.s_addr = inet_addr(ip);
		}

		//��  
		int ret = bind(_fd, (struct sockaddr*)&addr, sizeof(addr));

		if (ret < 0)
		{
			MyLog("bind error");
			return -1;
		}

		//���óɷ�����  
		//this->setNonBlock();

		//����  
		::listen(_fd, 10);

		return 0;
	}
};

#endif  

