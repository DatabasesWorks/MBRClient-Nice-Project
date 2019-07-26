#include "DictionaryManager.h"
#include "DefineData.h"

DictionaryManager* DictionaryManager::m_instance = NULL;
DictionaryManager::DictionaryManager()
{
	initNecessaryDictKeys();
}

DictionaryManager::~DictionaryManager()
{
  
}

void DictionaryManager::initNecessaryDictKeys()
{
	m_necessaryDictNames.insert("AAC058");
}

void DictionaryManager::getNecessaryDictKeys(QSet<QString>& dictKeys )
{
	dictKeys = m_necessaryDictNames;
}

void DictionaryManager::getDictionaryItem(QString name, QMap<QString, QString>& dictItem)
{
	if(m_dictItemsByName.contains(name)) {
		dictItem = m_dictItemsByName[name];
	}
}

QString DictionaryManager::getDictionaryNote(QString name, QString value)
{
	if(m_dictItemsByName.contains(name)) {
		if(m_dictItemsByName[name].contains(value)) {
			return m_dictItemsByName[name][value];
		}
	}

	return "";
}

QString DictionaryManager::getDictionaryValue(QString name, QString note)
{
	if(m_dictItemsByName.contains(name)) {
		return m_dictItemsByName[name].key(note);
	}

	return "";
}

void DictionaryManager::loadFromDB()
{
	if(!m_dictItemsByName.isEmpty()) {
		return;
	}

	QSet<QString>::iterator it = m_necessaryDictNames.begin();
	for(; it != m_necessaryDictNames.end(); it++) {
		QMap<QString, QString> dictItem;
		if(DBHELPER->m_pDictionaryTable->getDict(*it, dictItem)) {
			m_dictItemsByName.insert(*it, dictItem);
		}
	}

	if(m_dictItemsByName.isEmpty()) {
		QMap<QString, QString> dictItem;
		dictItem["0"] = "���֤";
		dictItem["0"] = "���֤";
		dictItem["1"] = "����";
		dictItem["2"] = "�۰�̨���������ڵ�ͨ��֤";
		dictItem["3"] = "���ڲ�";
		dictItem["4"] = "����";
		dictItem["5"] = "�籣��";
		dictItem["6"] = "�������ھ������֤";
		dictItem["7"] = "����������ջ�ͨ��֤";
		dictItem["8"] = "�����������ջ�ͨ��֤";
		dictItem["9"] = "̨���������ջ�ͨ��֤";
		dictItem["10"] = "����˻���";
		dictItem["11"] = "����������֤��";

		m_dictItemsByName.insert("AAC058", dictItem);
	}
}