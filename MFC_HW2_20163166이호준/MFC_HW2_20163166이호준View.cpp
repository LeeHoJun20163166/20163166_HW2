
// MFC_HW2_20163166이호준View.cpp: CMFCHW220163166이호준View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFC_HW2_20163166이호준.h"
#endif

#include "MFC_HW2_20163166이호준Doc.h"
#include "MFC_HW2_20163166이호준View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCHW220163166이호준View

IMPLEMENT_DYNCREATE(CMFCHW220163166이호준View, CView)

BEGIN_MESSAGE_MAP(CMFCHW220163166이호준View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CMFCHW220163166이호준View 생성/소멸

CMFCHW220163166이호준View::CMFCHW220163166이호준View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCHW220163166이호준View::~CMFCHW220163166이호준View()
{
}

BOOL CMFCHW220163166이호준View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}
void CMFCHW220163166이호준View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnChar(nChar, nRepCnt, nFlags);
}
// CMFCHW220163166이호준View 그리기

void CMFCHW220163166이호준View::OnDraw(CDC* pDC)
{
	CMFCHW220163166이호준Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CBrush brush;
	brush.CreateSolidBrush(RGB(m_Radius % 256, 0, 0));
	pDC->SelectObject(&brush);
	pDC->Ellipse(
		m_ptStart.x - m_Radius, m_ptStart.y - m_Radius, 
		m_ptStart.x + m_Radius, m_ptStart.y + m_Radius);

	brush.DeleteObject();
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMFCHW220163166이호준View 인쇄

BOOL CMFCHW220163166이호준View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCHW220163166이호준View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCHW220163166이호준View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCHW220163166이호준View 진단

#ifdef _DEBUG
void CMFCHW220163166이호준View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCHW220163166이호준View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCHW220163166이호준Doc* CMFCHW220163166이호준View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCHW220163166이호준Doc)));
	return (CMFCHW220163166이호준Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCHW220163166이호준View 메시지 처리기


void CMFCHW220163166이호준View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_ptStart = point;
	
	CView::OnLButtonDown(nFlags, point);
}

void CMFCHW220163166이호준View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON)
	{
		m_ptEnd = point;
		m_Radius = Length(m_ptStart, m_ptEnd);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}

void CMFCHW220163166이호준View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ptEnd = point;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}







int CMFCHW220163166이호준View::Length(CPoint m_ptStart, CPoint m_ptEnd)
{
	// TODO: 여기에 구현 코드 추가.
	return((int)sqrt((m_ptEnd.x - m_ptStart.x) * (m_ptEnd.x - m_ptStart.x)
		+ (m_ptEnd.y - m_ptStart.y) * (m_ptEnd.y - m_ptStart.y)));
}
