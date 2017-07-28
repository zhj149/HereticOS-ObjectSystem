#pragma once

#include "ViewTree.h"

class CAdminTreeViewToolBar : public CMFCToolBar
{
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)
	{
		CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList() const { return FALSE; }
};

// CAdminTreeView

class CAdminTreeView : public CDockablePane
{
	DECLARE_DYNAMIC(CAdminTreeView)

public:
	CAdminTreeView();
	virtual ~CAdminTreeView();

public:
	void AdjustLayout();

protected:
	void FillFileView();

protected:
	CViewTree m_wndFileView;
	CImageList m_FileViewImages;
	//CAdminTreeViewToolBar m_wndToolBar;

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);

	DECLARE_MESSAGE_MAP()
};


