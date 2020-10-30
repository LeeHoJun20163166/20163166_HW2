
// MFC_HW2_20163166이호준View.h: CMFCHW220163166이호준View 클래스의 인터페이스
//

#pragma once


class CMFCHW220163166이호준View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCHW220163166이호준View() noexcept;
	DECLARE_DYNCREATE(CMFCHW220163166이호준View)

// 특성입니다.
public:
	CMFCHW220163166이호준Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCHW220163166이호준View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_ptStart;
	CPoint m_ptEnd;
	COLORREF m_brushColor;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	int m_Radius;
	int Length(CPoint m_ptStart, CPoint m_ptEnd);
};

#ifndef _DEBUG  // MFC_HW2_20163166이호준View.cpp의 디버그 버전
inline CMFCHW220163166이호준Doc* CMFCHW220163166이호준View::GetDocument() const
   { return reinterpret_cast<CMFCHW220163166이호준Doc*>(m_pDocument); }
#endif

