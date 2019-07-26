#ifndef ENUMDATA_H
#define ENUMDATA_H

//���ݿ�����
enum DatabaseType {
	e_splite,
	e_sqlServer,
	e_mysql,
	e_firebird
};

enum 
{
	Register_Registered = 0,            // ��ע��
	Register_NotRegistered = 1,            // δע��
	Register_TimeOut = 2,            // ����
	Register_Forbidden = 3,             // ע�����ѽ���
	Register_WillTimeOut = 4,           // ��������
};

enum 
{
	BioType_None = 0,
	BioType_Face = 11,
	BioType_FVein = 12,
	//    BiometricType_ParmVein = 13,
	//    BiometricType_Eye = 14,
	BioType_FPrint = 15,
	//    BiometricType_Voice = 16,
};

enum 
{
	//    BioModel_Default = 0,
	ModelType_VIS = 111,         // �ɼ���
	ModelType_NIR = 112,         // ������
	ModelType_FVein = 121,        // ָ��������
	ModelType_FPrint = 151,        // ָ��
};

enum 
{
	CacheCode_Dict = 1001,      // �ֵ仺��
	CacheCode_Area = 1002,     // �������򻺴�
	CacheCode_Param = 1003,      // ��������
	CacheCode_Org = 1004,      // ͳ��������
	CacheCode_Unit = 1005,      // ��λ����
};

#endif