
// FocusDlg.h : ͷ�ļ�
//

#pragma once
#include <string>
#include <vector>
#include <map>
#include "afxwin.h"
#include "afxcmn.h"
// ������
struct Config {
	std::string config_name;
	int move_Up_times;					//���ƶ�����
    int move_Up_pixel;					//ÿ�������ƶ�������
	int Interval;						//�м���ͣ���
	int move_Down_times;				//ÿ���������������
	int move_Down_pixel;				//���ƶ�������	
	std::string hotkey;					// �ȼ�
};

// CFocusDlg �Ի���
class CFocusDlg : public CDialogEx
{
// ����
public:
	CFocusDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FOCUS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	void OnHotKeyPressed();
	virtual HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLbnDblclkList1();
	afx_msg void OnLbnSelchangeList1();
	bool m_bIsRunning;
	bool m_bActive;
	bool m_bUpComplete;
	bool m_bDownComplete;
	bool m_bInterval;
	long m_timeUpcomplete;
	int	m_HotKey;
	CListBox m_listConfig;
	CButton  m_button;
	CEdit  m_Editbox[8];
	POINT	 m_beginPos;
	void ReadConfig();
	void SaveConfig();
	void SetEditText(Config config);
	std::vector<Config> m_VecConfig;
	int m_nUp;
	int m_nDown;
	CStatic m_staticText;
	CStatic m_CurSelectText;
	CStatic m_URLText;
	CEdit m_editName;
	std::map<std::string, int> m_keyMap;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton_New();
	afx_msg void OnBnClickedButton_Delete();
	afx_msg void OnBnClickedButton_Default();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
};
