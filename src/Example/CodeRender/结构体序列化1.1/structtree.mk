NULL_FALSE<NULL_FALSE>=NULL_FALSE
	NULL_TRUE<NULL_TRUE>=NULL_TRUE
	逗号分隔符<逗号分隔符>=WORD(,)
	结构声明<结构声明>=结构声明1|结构声明2|结构声明3
	结构声明1<结构声明>=结构声明头关键词+结构体名+包<结构声明包开始,结构声明包结束,结构声明体>+WORD(;)
	结构声明2<结构声明>=WORD(typedef)+结构声明头关键词+结构体名+包<结构声明包开始,结构声明包结束,结构声明体>+结构体名称类型声明参数表+WORD(;)
	结构声明包开始<结构声明包开始>=WORD({)
	结构声明包结束<结构声明包结束>=WORD(})
	结构声明头关键词<结构声明头关键词>=WORD(struct)
	结构声明3<结构声明>=NULL_FALSE
	结构体名称类型声明参数表<函数参数声明>=N<结构体名称类型声明,逗号分隔符>|NULL_TRUE
	结构体名称类型声明<结构体名称类型声明>=结构体名称类型声明应用型|结构体名称类型声明指针型
	结构体名称类型声明应用型<结构体名称类型声明>=词型
	结构体名称类型声明指针型<结构体名称类型声明>=WORD(*)+词型
	
	结构体名<结构体名>=词型


	结构声明体<类声明体>=N<结构声明体内容,NULL_TRUE>|NULL_TRUE

	结构声明体内容<结构声明体内容>=结构声明体内容5|结构声明体内容6

	结构声明体内容5<结构声明体内容>=函数声明|函数定义
	结构声明体内容6<结构声明体内容>=变量声明


	函数定义<函数定义>=NULL_FALSE
	函数声明<函数声明>=函数声明1|函数声明2

	函数声明1<函数声明>=WORD(STDMETHOD)+WORD(()+函数名+WORD())+函数参数声明
	函数声明2<函数声明>=WORD(STDMETHOD_)+WORD(()+函数返回类型+WORD(,)+函数名+WORD())+函数参数声明
	函数返回类型<函数返回类型>=参数类型
	
	函数后缀<前缀>=WORD(PURE)
	函数参数前缀1<前缀>=WORD(THIS)|WORD(THIS_)
	函数参数前缀<前缀>=N<函数参数前缀1,NULL_TRUE>
	
	函数参数声明<函数参数声明>=包<函数声明包开始,函数声明包结束,函数声明参数表>|空参数声明
	空参数声明<函数参数声明>=WORD(()+WORD())+WORD(;)
	//无返回参数函数声明<函数声明>=NULL<函数调用约定>|函数名+函数参数声明

	函数名<函数名>=词型
	函数声明包开始<函数声明包开始>=WORD(()
	函数声明包结束<函数声明包结束>=WORD())+NULL<函数后缀>+WORD(;)
	函数声明参数表<函数参数声明>=N<函数声明参数声明,逗号分隔符>|函数参数前缀
	函数声明参数声明<函数声明参数声明>=参数类型+参数名称
	参数类型<参数类型>=NULL<函数参数前缀>|CONST指针指针型参数|CONST指针型参数|CONST引用型参数|CONST对象型参数|指针指针型参数|指针型参数|引用型参数|对象型参数
	
	CONST对象型参数<参数类型>=WORD(CONST)+词型
	CONST指针型参数<参数类型>=WORD(CONST)+词型+WORD(*)
	CONST指针指针型参数<参数类型>=WORD(CONST)+词型+WORD(*)+WORD(*)
	CONST引用型参数<参数类型>=WORD(CONST)+词型+WORD(&)
	
	对象型参数<参数类型>=词型
	指针型参数<参数类型>=词型+WORD(*)
	指针指针型参数<参数类型>=词型+WORD(*)+WORD(*)
	引用型参数<参数类型>=词型+WORD(&)
	
	//参数名有可能为空哦
	空参数名称<参数名称>=NULL_TRUE
	参数名称<参数名称>=词型|空参数名称

	变量声明<变量声明>=变量类型+变量名称+NULL<变量数目>+word(;)
	变量类型<变量类型>=变量类型1|变量类型2
	变量类型1<变量类型>=模板型
	模板型<变量类型>=词型+包<模板参数开始,模板参数结束,模板参数体>
	模板参数开始<模板类型>=WORD(<)
	模板参数结束<模板类型>=WORD(>)
	模板参数<模板类型>=变量类型|整数类型
	整数类型<整数类型>=整型
	模板参数体<模板类型>=N<模板参数,逗号分隔符>|NULL_TRUE
	
	变量类型2<变量类型>=变量声明前缀+词型
	
	变量名称<变量声明>=词型
	变量声明前缀<变量声明>=变量声明前缀1|NULL_TRUE
	变量声明前缀1<变量声明>=WORD("unsigned")
	
	变量数目<变量声明>=WORD([)+变量数目1+WORD(])
	变量数目1<变量声明>=整型

	变量声明表<变量声明表>=变量类型+N<变量声明表单元变量声明,逗号分隔符>+word(;)
	变量声明表单元变量声明<变量声明表单元变量声明>=变量名称
	
	