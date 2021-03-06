
typedef struct _PROCESS_MEMORY_COUNTERS {
    DWORD cb;
    DWORD PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
} PROCESS_MEMORY_COUNTERS;

typedef struct _IO_COUNTERS {
    ULONGLONG  ReadOperationCount;
    ULONGLONG  WriteOperationCount;
    ULONGLONG  OtherOperationCount;
    ULONGLONG ReadTransferCount;
    ULONGLONG WriteTransferCount;
    ULONGLONG OtherTransferCount;
} IO_COUNTERS;

typedef struct _tagProcessInfo
{
	_PROCESS_MEMORY_COUNTERS 			Meminfo;
	vector<_IO_COUNTERS>				IOInfo;
	map<unsigned int,_PROCESS_MEMORY_COUNTERS,less<unsigned int> > 	MeminfoMap;
	DWORD nBuf[256];
	TCHAR szString[128];
	double test111;
	vector<tstring> szTest;
	SER_TO_X<DWORD,HexString>	Test;		
	__int64	nTest1;
	SER_TO_X<__int64,HexString>	nTest2;
	
}ProcessInfo;

typedef struct _tagTest
{
	vector<vector<_IO_COUNTERS>	>			IOInfo;
	map<unsigned int,_PROCESS_MEMORY_COUNTERS,less<unsigned int> > 	MeminfoMap;
	DWORD nBuf[256];
	DWORD nn;	
	SER_TO_X<DWORD,123>	Test;		
}Test;

typedef struct _tagSafeLevelInfoAttributes
{
	tstring		type;
	tstring		Id;
}SafeLevelInfoAttributes;

typedef struct _tagSafeLevelInfo
{
	_tagSafeLevelInfoAttributes MyObjectAttributes;
	tstring		priSafeLevelId;
	tstring		safelevelCnName;
	int			statusCode;
	int			levelNumber;
	tstring		safelevelCode;
	tstring		deptId;
	tstring		orderC0de;
}SafeLevelInfo;

typedef struct _tagLogonRetInfo
{
	tstring		ftpPwd;
	DWORD		result;
	BOOL		isCheckCert;
	BOOL		isImportCert;
	__int64		fileUploadMaxSize;
	TCHAR		ftpUser[64];
	vector<_tagSafeLevelInfo>	safelevelList;
	tstring		userType;
	tstring		ftpServer;
	tstring		userId;
	tstring		md5Pwd;
	USHORT		ftpPort;
	tstring		userSafelevelId;
	tstring		priDeptId;
	BOOL		isForceLogin;
	tstring		loginName;
}LogonRetInfo;

typedef struct _tagLogonRet
{
	tstring result;
	ObjectMapContainer<Serialize__tagLogonRetInfo,Serialize_MapContainerSet> values;
}LogonRet;









typedef struct _tagSystemInfoAuditRule
{
	tstring RuleID;
	tstring InfoAuditType;
	int InfoUploadCycle;
	int DifferentialValveCycle;
};


typedef struct _tagSystemInfoAuditFieldValveRule
{
	tstring RuleID;
	tstring FiledName;
	tstring ValveType;
	__int64 FiledValve;
};

typedef struct _tagProcessInfoAuditFieldValveRule
{
	tstring RuleID;
	tstring FiledName;
	tstring ValveType;
	__int64 FiledValve;
};

typedef struct _tagProcessInfoAuditRule
{
	tstring	RuleID;
	tstring	InfoAuditType;
	int InfoUploadCycle;
	int	DifferentialValveCycle;
	tstring ProcessFilterID;
};

typedef struct _tagProcessNameFilter
{
	tstring RuleID;
	tstring FilterRule;
	tstring ProcessName;
};

typedef struct _tagProcessExeMD5Filter
{
	tstring RuleID;
	tstring FilterRule;
	tstring ProcessBinMD5;
};

typedef struct _tagServerInfoRule
{
	_tagSystemInfoAuditRule						SystemInfoAuditRule;
	vector<_tagSystemInfoAuditFieldValveRule>	SystemInfoAuditFieldValveRule;

	vector<_tagProcessInfoAuditRule>			ProcessInfoAuditRule;
	vector<_tagProcessInfoAuditFieldValveRule>	ProcessInfoAuditFieldValveRule;

	vector<_tagProcessNameFilter>				ProcessNameFilter;
	vector<_tagProcessExeMD5Filter>				ProcessExeMD5Filter;
};

typedef struct _tagSystemInfoAuditMsg
{
	__int64 CommitLimit;
	__int64 CommitPeak;
	__int64 CommitTotal;
	__int64 HandleCount;
	__int64 KernelNonpaged;
	__int64 KernelPaged;
	__int64 KernelTotal;
	__int64 PageSize;
	__int64 PhysicalAvailable;
	__int64 PhysicalTotal;
	__int64 ProcessCount;
	__int64 SystemCache;
	__int64 ThreadCount;
}SystemInfoAuditMsg;


typedef struct _tagProcessInfoAuditMsg
{
	__int64 Processid;
	tstring ProcessName;
	__int64 HandleCount;
	__int64 OtherOperationCount;
	__int64 OtherTransferCount;
	__int64 ReadOperationCount;
	__int64 ReadTransferCount;
	__int64 WriteOperationCount;
	__int64 WriteTransferCount;

	__int64 PageFaultCount;
	__int64 PagefileUsage;
	__int64 PeakPagefileUsage;
	__int64 PeakWorkingSetSize;
	__int64 QuotaNonPagedPoolUsage;
	__int64 QuotaPagedPoolUsage;
	__int64 QuotaPeakNonPagedPoolUsage;
	__int64 QuotaPeakPagedPoolUsage;
	__int64 WorkingSetSize;

	tstring CreationTime;
	tstring ExitTime;
	tstring KernelTime;
	tstring UserTime;
}ProcessInfoAuditMsg;




#define MAKESTRUCTINFO


//MAKESTRUCTINFO(_IO_COUNTERS)
//MAKESTRUCTINFO(_tagTest)
MAKESTRUCTINFO(_tagProcessInfo)
MAKESTRUCTINFO(_PROCESS_MEMORY_COUNTERS)
MAKESTRUCTINFO(_IO_COUNTERS)

MAKESTRUCTINFO(_tagSafeLevelInfoAttributes)
MAKESTRUCTINFO(_tagLogonRet)
MAKESTRUCTINFO(_tagSafeLevelInfo)
MAKESTRUCTINFO(_tagLogonRetInfo)


MAKESTRUCTINFO(_tagSystemInfoAuditRule)
MAKESTRUCTINFO(_tagSystemInfoAuditFieldValveRule)
MAKESTRUCTINFO(_tagProcessInfoAuditRule)
MAKESTRUCTINFO(_tagProcessInfoAuditFieldValveRule)
MAKESTRUCTINFO(_tagProcessNameFilter)
MAKESTRUCTINFO(_tagProcessExeMD5Filter)
MAKESTRUCTINFO(_tagServerInfoRule)


MAKESTRUCTINFO(_tagSystemInfoAuditMsg)
MAKESTRUCTINFO(_tagProcessInfoAuditMsg)



struct _tagProcessProtectRule
{
	tstring RuleID;
	tstring ProcessName;
	tstring DirectoryName;
};

struct _tagFileDirectoryRule
{
	tstring RuleID;
	tstring DirectoryName;
	tstring FileDirectoryPath;
};

struct _tagServerProtectRule
{
	vector<_tagProcessProtectRule>	ProcessProtectRule;
	vector<_tagFileDirectoryRule>	FileDirectoryRule;
};

MAKESTRUCTINFO(_tagProcessProtectRule)
MAKESTRUCTINFO(_tagFileDirectoryRule)
MAKESTRUCTINFO(_tagServerProtectRule)



struct _tagDomainProcessRule
{
	tstring								ProcessName;
	SER_TO_X<unsigned int,HexString>	nDomainVal;
};

struct _tagDomainDirectoryRule
{
	tstring								DirectoryName;
	SER_TO_X<unsigned int,HexString>	nDomainVal;
};

struct _tagDomainRule
{
	SER_TO_X<unsigned int,HexString>		nMaskVal;
	vector<_tagDomainProcessRule>			ProcessRule;
	vector<_tagDomainDirectoryRule>			DirectoryRule;
};


MAKESTRUCTINFO(_tagDomainProcessRule)
MAKESTRUCTINFO(_tagDomainDirectoryRule)
MAKESTRUCTINFO(_tagDomainRule)


typedef struct _tagYDConfig
{
	tstring strRuleVer;
	//域用于测试连接计算得到本地ip
	tstring strNetDomainName;
	int		nNetDomainPort;

	tstring strWSDLUrl;
	tstring strRunDirectory;
	int		nSoapTimeout;
	int		nCheckCycle;
}YDConfig;

MAKESTRUCTINFO(_tagYDConfig)


typedef struct _tagSendProcessInfoAuditMsg_ProcessInfo
{
	_tagProcessInfoAuditMsg ProcessInfo;
}tSendProcessInfoAuditMsg_ProcessInfo;


//最上层XML 对象名必须是FunctionInterface
//进程性能监视报警
typedef struct _tagSendProcessInfoAuditMsgInterface
{
	_tagSendProcessInfoAuditMsg_ProcessInfo	SendProcessInfoAuditMsg;
}tSendProcessInfoAuditMsgInterface;

//保护进程性能监视报警
typedef struct _tagSendProtectProcessInfoAuditMsgInterface
{
	_tagSendProcessInfoAuditMsg_ProcessInfo	SendProtectProcessInfoAuditMsg;
}tSendProtectProcessInfoAuditMsgInterface;


//系统信息报警

typedef struct _tagSendSystemInfoAuditMsg
{
	_tagSystemInfoAuditMsg SystemInfo;
}tSendSystemInfoAuditMsg;


typedef struct _tagSendSystemInfoAuditMsgInterface
{
	_tagSendSystemInfoAuditMsg SendSystemInfoAuditMsg;
}tSendSystemInfoAuditMsgInterface;

MAKESTRUCTINFO(_tagSendProcessInfoAuditMsg_ProcessInfo)
MAKESTRUCTINFO(_tagSendProcessInfoAuditMsgInterface)
MAKESTRUCTINFO(_tagSendProtectProcessInfoAuditMsgInterface)
MAKESTRUCTINFO(_tagSendSystemInfoAuditMsg)
MAKESTRUCTINFO(_tagSendSystemInfoAuditMsgInterface)



typedef struct _tagUpdataInterface
{
	tstring Ver;
	vector<tstring> UpadataInterfaceList;
}tUpdataInterface;

typedef struct _tagGetUpdataInterface
{
	tstring		IsNeedUpDataRule;
}tGetUpdataInterface;

typedef struct _tagGetSystemInfoRule
{
	int GetSystemInfoRule;
}tGetSystemInfoRule;

typedef struct _tagGetServerProtectRule
{
	int GetServerProtectRule;
}tGetServerProtectRule;

typedef struct _tagGetServerProtectProcessRule
{
	int GetServerProtectProcessRule;
}tGetServerProtectProcessRule;


MAKESTRUCTINFO(_tagUpdataInterface)
MAKESTRUCTINFO(_tagGetUpdataInterface)
MAKESTRUCTINFO(_tagGetSystemInfoRule)
MAKESTRUCTINFO(_tagGetServerProtectRule)
MAKESTRUCTINFO(_tagGetServerProtectProcessRule)
