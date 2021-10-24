#pragma once

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ�ļ����ų�����ʹ�õ�����
#define DLLAPI __declspec(dllexport)
// Windows ͷ�ļ�
#include <windows.h>
#include "../../Common/d3dUtil.h"
// This is the base class for the class
// retrieved from the DLL. This is used simply
// so that I can show how various types should
// be retrieved from a DLL. This class is to
// show how derived classes can be taken from
// a DLL.
//struct must complete and same with application
//dll export
#ifdef __cplusplus
 extern "C" {
#endif
	typedef void(*onFramebufferCallBack)(BYTE*, int, int, int, int);//buffer w h size userid
	typedef void(*onAudioCallBack)(BYTE*, int, int);//buffer size userid

	/*
	* �����ʼ����ID�������ɲ�ͬ�ķ���������л��֡�������Ϸ��
	  ���桢��Ƶ�ص�����ָ��java�Ĵ�������ڣ�
	  Ȼ�󴴽�һ��C++�߳̽�����Ϸѭ��
	*/
	DLLAPI int d3dInitialize(int gameServiceID, onFramebufferCallBack bufferCb, onAudioCallBack audioCb);//
	
	/*
	* buffer=1280[��]*720[��]*4Byte��ÿ���ֽڴ���һ����ɫ������RGBA��ÿ������ռ4�ֽ�
	*/
	
	/*
	* MouseStatus(int 0x00 = ���Ҷ�����״̬, 0x01 = �����ס״̬, 0x02 = �Ҽ���ס״̬, 3ͬʱ��ס)
	*/
	DLLAPI void setMouseMotion(int mouseStatus,int mouseX,int mouseY, _user userid);//���û���ƶ�ҲҪ����Ϊ��ÿ֡��ȡ���״̬
	
	/*
	* MouseClickKey(int 0=û��click�¼�,1=����һ˲��,2=�Ұ���һ˲��,3=�󰴵���˲��,4=�Ұ�����˲��)
	*/
	DLLAPI void setMouseClicked(int mouseClickKey, int mouseX, int mouseY, _user userid);
	
	/*
	* keycode(int=ASCII ����XXX�ַ��İ���һ˲��)
	*/
	DLLAPI void setKeyPressed(int keycode, _user userid);
	
	/*
	* ������Ҷ��󣬲���������Ϸ����������ϴδ浵����Ϸ���Ե�
	*/
	DLLAPI void setPlayerEnter(int id, int frameWidth, int frameHeight, int kbps, int fps, void* pUserData);
	/*
	* �����õķֱ��ʡ���������kbps������֡��fps(δʵ��)
	*/
	DLLAPI void setPlayData(int id,int frameWidth, int frameHeight, int kbps ,int fps);
	
	/*
	* ����˳���Ϸ�󣬷��������Գ־û��������
	*/
	DLLAPI void getPlayerData(int id, int frameWidth, int frameHeight, int codeRate);
	
	//���Ӧ�û���Ҫ��ͣ/�ش� buffer�Ŀ��أ�����������ʱ�жϡ��ͻ�����ʱ��ͣ

	/*
	* ɾ����Ҷ���
	*/
	DLLAPI void setPlayerQuit(int id);
	

	DLLAPI float getTotaltime();//��ȡ��Ϸ��ʱ��

	DLLAPI float getDeltatime();//��ȡ֡���ʱ��dt (fps = 1/dt)



	struct UDD {
		char* b[1280 * 720 * 4];
	};

	typedef void(*OnPlayerQuitCallBack)(float x, float y, float z);

#ifdef __cplusplus
}
#endif