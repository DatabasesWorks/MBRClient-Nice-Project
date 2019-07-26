////////////////////////////////////////////////////////////
// base64.h

// �ο����£�http://www.cstc.net.cn/docs/docs.php?id=202

//************************************************************************/
//    base64�����
// 
//		0 A 17 R 34 i 51 z 
//		1 B 18 S 35 j 52 0 
//		2 C 19 T 36 k 53 1 
//		3 D 20 U 37 l 54 2 
//		4 E 21 V 38 m 55 3 
//		5 F 22 W 39 n 56 4 
//		6 G 23 X 40 o 57 5 
//		7 H 24 Y 41 p 58 6 
//		8 I 25 Z 42 q 59 7 
//		9 J 26 a 43 r 60 8 
//		10 K 27 b 44 s 61 9 
//		11 L 28 c 45 t 62 + 
//		12 M 29 d 46 u 63 / 
//		13 N 30 e 47 v (pad) = 
//		14 O 31 f 48 w 
//		15 P 32 g 49 x 
//		16 Q 33 h 50 y 
//
// base64���벽�裺
// 
//		ԭ�ģ�
//
//		���
//		C4 E3 BA C3
//		11000100 11100011 10111010 11000011
//		00110001 00001110 00001110 00111010
//		49       14							��ʮ���ƣ�
//		x        O        O        6		�ַ�
//		01111000 01001111 01001111 00110110
//		78									��ʮ�����ƣ�
//		xOO6
//
//		���룺
//		xOO6
//		78 4f 4f 36
//		01111000 01001111 01001111 00110110
//		49       14 
//		00110001 00001110 00001110 00111010   31 0e 0e 3a
//
//		11000100 11100011 10111010
//		C4       E3       BA
//

// �����ĳ���һ���ԭ�Ķ�ռ1/3�Ĵ洢�ռ䣬�뱣֤base64code���㹻�Ŀռ�
// �����ĳ���һ���ԭ������ռ1/4�Ĵ洢�ռ䣬�뱣֤buf���㹻�Ŀռ�

#ifndef __AEYEBASE64HELPER_H__
#define __AEYEBASE64HELPER_H__


#define ENCRYPT 0  
#define DECRYPT 1  

#define ECB 0  
#define CBC 1  

#define KEY_LEN_8 8  
#define KEY_LEN_16 16  
#define KEY_LEN_24 24  

#define PAD_ISO_1   0  
#define PAD_ISO_2   1  
#define PAD_PKCS_7  2  
typedef char (*PSubKey)[16][48];  

class  AES {
public:
	AES();
	virtual ~AES();
public:

  
    /*���ܺ�,�������ַ�ȥ��*/  
    void RunRsm(char* Text);  
  
    /*��48λ��������Կת����24���ַ�����Կ*/  
    int CovertKey(char* iKey, char *oKey);  
  
    /******************************************************************* 
      �� �� �� ��:  RunPad 
      �� �� �� ����  ����Э��Լ���ǰ�����ݽ������ 
      �� �� ˵ ����  bType   :���ͣ�PAD���� 
                    In      :���ݴ�ָ�� 
                    Out     :��������ָ�� 
                    in_len  :���ݵĳ��� 
                    padlen  :(in,out)���buffer�ĳ��ȣ�����ĳ��� 
 
      ����ֵ ˵����   char    :�Ƿ����ɹ� 
    *******************************************************************/  
    int RunPad(int nType,const char* In,unsigned in_len,char* Out,int* padlen);  
  
    /******************************************************************* 
    �� �� �� ��:    Run1Des 
    �� �� �� ����    ִ�е�DES�㷨���ı��ӽ��� 
    �� �� ˵ ����    bType   :���ͣ�����ENCRYPT������DECRYPT 
                    bMode   :ģʽ��ECB,CBC 
                    In      :�����ܴ�ָ�� 
                    in_len  :�����ܴ��ĳ��ȣ�ͬʱOut�Ļ�������СӦ���ڻ��ߵ���in_len 
                    Key     :��Կ(��Ϊ8λ,16λ,24λ)֧��3��Կ 
                    key_len :��Կ���ȣ����24λ���ֽ����Զ��ü� 
                    Out     :�������ָ�� 
                    out_len :��������С 
                    cvecstr :8�ֽ��漴�ַ��� 
 
    ����ֵ ˵���� int     :�Ƿ���ܳɹ���1���ɹ���0��ʧ�� 
    *******************************************************************/  
    int Run1Des(int bType, int bMode, const char *In, unsigned int in_len, const char *Key, unsigned int key_len, char* Out, unsigned int out_len, const char cvecstr[8]);  
  
    /******************************************************************* 
      �� �� �� ��:  Run3Des 
      �� �� �� ����  ִ��3DES�㷨���ı��ӽ��� 
      �� �� ˵ ����  bType   :���ͣ�����ENCRYPT������DECRYPT 
                    bMode   :ģʽ��ECB,CBC 
                    In      :�����ܴ�ָ�� 
                    in_len  :�����ܴ��ĳ��ȣ�ͬʱOut�Ļ�������СӦ���ڻ��ߵ���in_len 
                    Key     :��Կ(��Ϊ8λ,16λ,24λ)֧��3��Կ 
                    key_len :��Կ���ȣ����24λ���ֽ����Զ��ü� 
                    Out     :�������ָ�� 
                    out_len :��������С 
                    cvecstr :8�ֽ��漴�ַ��� 
 
      ����ֵ ˵����   int     :�Ƿ���ܳɹ���1���ɹ���0��ʧ�� 
 
      ��       ��:    huangjf 
      �� �� �� �ڣ�  2009.6.17 
 
      3DES(����) = DES(key1, ����) DES(key2, ����)  DES(key3, ����) 
      3DES(����) = DES(key3, ����) DES(key2, ����)  DES(key1, ����) 
      ÿ��KEYΪ64λ���ܹ�������192λ��KEY, ��һ�㶼ֻʹ��128λ��key 
      ���ֻ��128λ��Կ����key3 = key1 
 
    *******************************************************************/  
    int Run3Des(int bType, int bMode, const char *In, unsigned int in_len, const char *Key, unsigned int key_len, char* Out, unsigned int out_len, const char cvecstr[8]);  
  
    /******************************************************************* 
    �� �� �� ��:    Crypt3Des 
    �� �� �� ����    ʵ��3DES�ļӽ��� 
    �� �� ˵ ����    type    :���ͣ�����ENCRYPT������DECRYPT 
                    in      :�����ܴ�ָ����ߴ����ܵ������ַ���ָ�� 
                    Out     :���ܺ��������߽��ܺ������ 
                    Key     :��Կ(48λ��ASCII�ַ���) 
 
    ����ֵ ˵���� 
                    0:�ɹ� 
                    -1:�Ƿ�����Կ���� 
                    -2:��Կ���з�16�����ַ� 
                    -3:�������ʧ�� 
                    -4:�ӽ���ʧ�� 
                    -5:�Ƿ��Ĳ������� 
    *******************************************************************/  
    int Crypt3Des(int type,char* in,int nsrclen,char* key,char* out,int & outLen);

    unsigned char GetByte(char *s);  
	void MyDesInit(int* cryptmode,int* padmode,char* cvec);
};

#endif
