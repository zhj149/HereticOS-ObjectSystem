///////////////////////////////////////////////////////////////////////////////////
//	Copyright 2017 shushen,ye
//	Licensed under the Apache License, Version 2.0 (the "License");
//	you may not use this file except in compliance with the License.
//	You may obtain a copy of the License at
//	http://www.apache.org/licenses/LICENSE-2.0
//	Unless required by applicable law or agreed to in writing, software
//	distributed under the License is distributed on an "AS IS" BASIS,
//	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//	See the License for the specific language governing permissions and
//	limitations under the License.
///////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "shellapi.h"

class CObjectFileOperation_Nop
{
public:
	CObjectFileOperation_Nop(void) {};
	~CObjectFileOperation_Nop(void) {};
	HANDLE m_hObject;
	template<typename StringT>
	BOOL OpenObjectFile(StringT & szDirPath, BOOL bClear) { return TRUE; };
	template<typename StringT>
	BOOL ReadObject(OUT StringT & szObject) { return TRUE; };
	template<typename StringT>
	BOOL WriteObject(IN StringT & szObject) { return TRUE; };
	template<typename StringT>
	BOOL DelObjectOrDir(StringT & szDirPath) { return TRUE; };
	BOOL CloseObject() { return TRUE; };

	template<typename StringT>
	BOOL ClearFile(StringT & szObjectPath) { return TRUE; };
	template<typename StringT>
	BOOL OpenObjectFile_OnlyOpen(StringT & szObject) { return FALSE; };
	template<typename StringT>
	static BOOL GetDirectoryInfo(IN StringT & DirectoryPath, IN StringT & szFinder, OUT ObjectSystem::_tagDirectoryInfo & DirectoryInfo, OUT ObjectSystem::SYSTEMERROR * pError) { return TRUE; };


};


class CObjectFileOperation
{
public:
	
	HANDLE m_hObject;
	CObjectFileOperation(void) {
		m_hObject = NULL;
	};

	~CObjectFileOperation(void) {
		CloseObject();
	};

	template<typename StringT>
	BOOL OpenObjectFile(StringT & szDirPath,BOOL bClear)
	{

		//打开创建文件
		m_hObject = CreateFile(szObject.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			0,
			bClear ? TRUNCATE_EXISTING : OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, 0);
		DWORD nError = GetLastError();
		if (nError == ERROR_FILE_NOT_FOUND)
		{
			m_hObject = CreateFile(szObject.c_str(),
				GENERIC_READ | GENERIC_WRITE,
				FILE_SHARE_READ | FILE_SHARE_WRITE,
				0,
				OPEN_ALWAYS,
				FILE_ATTRIBUTE_NORMAL, 0);
		}
		if (m_hObject == INVALID_HANDLE_VALUE)
		{
			if (CreatedObjectMultipleDirectory(szObject))
			{
				//创建目录成功
				m_hObject = CreateFile(szObject.c_str(),
					GENERIC_READ | GENERIC_WRITE,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					0, OPEN_ALWAYS,
					FILE_ATTRIBUTE_NORMAL, 0);
				if (m_hObject == INVALID_HANDLE_VALUE)
				{
					//
					//OutputDebugString(_T());
					return FALSE;
				}
				else
				{
					return TRUE;
				}
			}
		}
		else
		{
			return TRUE;
		}
		//如果失败创建目录

		//打开创建文件
		return FALSE;
	};
	template<typename StringT>
	BOOL ReadObject(OUT StringT & szObject) 
	{
		DWORD nLen = GetFileSize(m_hObject, NULL);
		BYTE * pBuf = new BYTE[nLen + 64];
		pBuf[nLen] = 0; pBuf[nLen + 1] = 0;
		std::auto_ptr<BYTE> mem(pBuf);
		BOOL bRet = ReadFile(m_hObject, pBuf, nLen, &nLen, NULL);
		if (bRet)
		{
			szObject = (TCHAR*)pBuf;
		}

		return bRet;
	};
	template<typename StringT>
	BOOL WriteObject(IN StringT & szObject) {
		DWORD nLen;
		SetFilePointer(m_hObject, 0, 0, FILE_BEGIN);
		BOOL bRet = WriteFile(m_hObject, szObject.c_str(), (szObject.length() + 1) * sizeof(TCHAR), &nLen, NULL);
		return TRUE;
	};
	template<typename StringT>
	BOOL DelObjectOrDir(StringT & szDirPath) {
		if (m_hObject)
		{
			CloseHandle(m_hObject);
			m_hObject = NULL;
		}

		if (DeleteFile(szDirPath.c_str()) == FALSE)
		{
			RemoveDir(szDirPath);
			/*SHFILEOPSTRUCT FileOp;
			FileOp.fFlags = FOF_NOCONFIRMATION;
			FileOp.hNameMappings = NULL;
			FileOp.hwnd = NULL;
			FileOp.lpszProgressTitle = NULL;
			FileOp.pFrom = szDirPath.c_str();
			FileOp.pTo = NULL;
			FileOp.wFunc = FO_DELETE;
			return SHFileOperation(&FileOp) == 0;*/
		}
		return TRUE;
	}
	;

	BOOL CloseObject()
	{
		::CloseHandle(m_hObject);
		return TRUE;
	};
	


	template<typename StringT>
	BOOL ClearFile(StringT & szObjectPath)
	{
		FILE_ALLOCATION_INFO filesize;
		filesize.AllocationSize.QuadPart = 0;
		//::SetFileInformationByHandle(m_hObject,FileAllocationInfo,&filesize,sizeof(FILE_ALLOCATION_INFO));
		CloseObject();
		m_hObject = CreateFile(szObjectPath.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			0,
			TRUNCATE_EXISTING,
			FILE_ATTRIBUTE_NORMAL, 0);
		return TRUE;
	};

	template<typename StringT>
	BOOL OpenObjectFile_OnlyOpen(StringT & szObject)
	{

		//打开创建文件
		m_hObject = CreateFile(szObject.c_str(),
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			0,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL, 0);
		/*DWORD nError=GetLastError();
		if(nError==ERROR_FILE_NOT_FOUND )
		{
		m_hObject=CreateFile(szObject.c_str(),
		GENERIC_READ|GENERIC_WRITE,
		FILE_SHARE_READ|FILE_SHARE_WRITE,
		0,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,0);
		}*/

		if (m_hObject == INVALID_HANDLE_VALUE)
		{
			return FALSE;
		}
		return TRUE;
	};

	template<typename StringT>
	static BOOL GetDirectoryInfo(IN StringT & DirectoryPath, IN StringT & szFinder, OUT ObjectSystem::_tagDirectoryInfo & DirectoryInfo, OUT ObjectSystem::SYSTEMERROR * pError)
	{


		WIN32_FIND_DATA wfd;
		HANDLE hFind = FindFirstFile((DirectoryPath + szFinder).c_str(), &wfd);
		if (hFind == INVALID_HANDLE_VALUE)
			return FALSE;

		ObjectSystem::_tagDirectoryInfoSet Set;
		do
		{
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (stricmp_t(wfd.cFileName, _T(".")) != 0 &&
					stricmp_t(wfd.cFileName, _T("..")) != 0)
				{
					Set.ObjectType = ObjectSystem::Directory;
					Set.ObjectName = wfd.cFileName;
					DirectoryInfo.DirectoryInfoArray.push_back(Set);
				}
			}
			else
			{
				Set.ObjectType = (unsigned int)ObjectSystem::File;
				Set.ObjectName = wfd.cFileName;
				DirectoryInfo.DirectoryInfoArray.push_back(Set);
			}
		} while (FindNextFile(hFind, &wfd));
		FindClose(hFind);

		return TRUE;
	};

private:
	template<typename StringT>
	BOOL RemoveDir(StringT & szFileDir) {
		tstring strDir = szFileDir;
		if (strDir.at(strDir.length() - 1) != '\\')
		{
			strDir += '\\';
		}
		WIN32_FIND_DATA wfd;
		HANDLE hFind = FindFirstFile((strDir + _T("*.*")).c_str(), &wfd);
		if (hFind == INVALID_HANDLE_VALUE)
			return false;
		do
		{
			if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (stricmp_t(wfd.cFileName, _T(".")) != 0 &&
					stricmp_t(wfd.cFileName, _T("..")) != 0)
					RemoveDir((strDir + wfd.cFileName));
			}
			else
			{
				DeleteFile((strDir + wfd.cFileName).c_str());
			}
		} while (FindNextFile(hFind, &wfd));
		FindClose(hFind);
		RemoveDirectory(szFileDir.c_str());
		return true;
	};

	template<typename StringT>
	BOOL GetObjectDirPath(IN StringT & szObjectPath,OUT tstring & szDirPath)
	{
		size_t n = szObjectPath.rfind('\\');
		if (n == 0) return FALSE;

		szDirPath.append(szObjectPath.c_str(), n);
		return TRUE;
	};

	template<typename StringT>
	BOOL FolderExist(StringT & szDirPath) 
	{
		WIN32_FIND_DATA wfd;
		BOOL rValue = FALSE;
		HANDLE hFind = FindFirstFile(szDirPath.c_str(), &wfd);
		if ((hFind != INVALID_HANDLE_VALUE) &&
			(wfd.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
		{
			rValue = TRUE;
		}
		FindClose(hFind);
		return rValue;
	};
	
	template<typename StringT>
	BOOL CreatedObjectMultipleDirectory(StringT & szObjectPath)
	{
		tstring Directoryname = szObjectPath;

		if (Directoryname[Directoryname.length() - 1] != '\\')
		{
			//Directoryname += 
			Directoryname.append(1, '\\');
		}
		std::list<tstring> vpath;
		tstring strtemp;
		bool  bSuccess = false;
		for (unsigned int i = 0; i < Directoryname.length(); i++)
		{
			if (Directoryname[i] != '\\')
			{
				strtemp.append(1, Directoryname[i]);
			}
			else
			{
				vpath.push_back(strtemp);
				strtemp.append(1, '\\');
			}
		}

		vpath.pop_back();

		std::list<tstring>::const_iterator vIterDepth;

		for (vIterDepth = vpath.begin(); vIterDepth != vpath.end(); vIterDepth++)
		{
			bSuccess = CreateDirectory(vIterDepth->c_str(), NULL) ? true : false;
		}

		return bSuccess;
	}
	

};
//#include "ObjectFileOperation.cpp"