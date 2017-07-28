
// ChildFrm.h : CChildFrame 类的接口
//

#pragma once



class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// 属性
public:
	TreeIndex m_ProjectIndex;

// 操作
public:
	

// 重写
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
	BOOL CanShowOnMDITabs();
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT OnMoveTabComplete(WPARAM wp, LPARAM lp);
};
