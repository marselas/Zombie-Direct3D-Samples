//--------------------------------------------------------------------------------------
// File: WaitDlg.h
//
// Wait dialog for shader compilation
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------
#include <process.h>

//--------------------------------------------------------------------------------------
INT_PTR CALLBACK WaitDialogProc( HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam );
unsigned int __stdcall WaitThread( void* pArg );

//--------------------------------------------------------------------------------------
class CWaitDlg
{
private:
    HWND	m_hDialogWnd;
    HANDLE	m_hThread;
    HWND	m_hProgressWnd;
    int		m_iProgress;
    BOOL	m_bDone;
    RECT	m_AppRect;
    WCHAR	m_szText[MAX_PATH];

public:
    CWaitDlg() : 
          m_hDialogWnd( NULL ),
          m_hThread( NULL ), 
          m_hProgressWnd( NULL ), 
          m_iProgress( 0 ), 
          m_bDone( FALSE ) 
    {
    }
    ~CWaitDlg() { DestroyDialog(); }

    bool IsRunning() { return !m_bDone; }

    void UpdateProgressBar()
    {
        m_iProgress ++;
        if( m_iProgress > 110 )
            m_iProgress = 0;

        SendMessage( m_hProgressWnd, PBM_SETPOS, m_iProgress, 0 );
        InvalidateRect( m_hDialogWnd, NULL, FALSE );
        UpdateWindow( m_hDialogWnd );
    }

    bool GetDialogControls()
    {
        m_bDone = FALSE;

        m_hDialogWnd = CreateDialog( DXUTGetHINSTANCE(), MAKEINTRESOURCE( IDD_COMPILINGSHADERS ), NULL, WaitDialogProc );
        if( !m_hDialogWnd )
            return false;

		SetWindowLongPtr( m_hDialogWnd, GWLP_USERDATA, (LONG_PTR)this );

        // Set the position
        int left = ( m_AppRect.left + m_AppRect.right ) / 2;
        int up = ( m_AppRect.top + m_AppRect.bottom ) / 2;

        SetWindowPos( m_hDialogWnd, NULL, left, up, 0, 0, SWP_NOSIZE );
        ShowWindow( m_hDialogWnd, SW_SHOW );

        // Get the progress bar
        m_hProgressWnd = GetDlgItem( m_hDialogWnd, IDC_PROGRESSBAR );
        SendMessage( m_hProgressWnd, PBM_SETRANGE, 0, MAKELPARAM( 0, 100 ) );

        // Update the static text
        HWND hMessage = GetDlgItem( m_hDialogWnd, IDC_MESSAGE );
        SetWindowText( hMessage, m_szText );

        return true;
    }

    bool ShowDialog( WCHAR* pszInputText )
    {
        // Get the window rect
        GetWindowRect( DXUTGetHWND(), &m_AppRect );
        wcscpy_s( m_szText, MAX_PATH, pszInputText );

        // spawn a thread that does nothing but update the progress bar
        unsigned int threadAddr;
        m_hThread = (HANDLE)_beginthreadex( NULL, 0, WaitThread, this, 0, &threadAddr );
        return true;
    }

    void DestroyDialog()
    {
        m_bDone = TRUE;
        WaitForSingleObject( m_hThread, INFINITE );

        if( m_hDialogWnd )
            DestroyWindow( m_hDialogWnd );
        m_hDialogWnd = NULL;
    }
};

//--------------------------------------------------------------------------------------
INT_PTR CALLBACK WaitDialogProc( HWND hwndDlg, UINT uMsg, WPARAM /*wParam*/, LPARAM /*lParam*/ )
{
    CWaitDlg* pThisDialog = (CWaitDlg*)GetWindowLongPtr( hwndDlg, GWLP_USERDATA );

    switch( uMsg )
    {
    case WM_INITDIALOG:
        return TRUE;
    case WM_CLOSE:
        pThisDialog->DestroyDialog();
        return TRUE;
    }

    return FALSE;
}

//--------------------------------------------------------------------------------------
unsigned int __stdcall WaitThread( void* pArg )
{
    CWaitDlg* pThisDialog = (CWaitDlg*)pArg;

    // We create the dialog in this thread, so we can call SendMessage without blocking on the
    // main thread's message pump
    pThisDialog->GetDialogControls();

    while( pThisDialog->IsRunning() )
    {
        pThisDialog->UpdateProgressBar();
        Sleep(100);
    }

    return 0;
}