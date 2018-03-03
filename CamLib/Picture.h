//-----------------------------------------------------------------------------
// Picture (Prototypes) Version 1.00
//
// Routins 4 Showing Picture Files... (.BMP .DIB .EMF .GIF .ICO .JPG .WMF)
//
// Author: Dr. Yovav Gad, EMail: Sources@SuperMain.com ,Web: www.SuperMain.com
//=============================================================================

#if !defined(AFX_PICTURE_H__COPYFREE_BY_YOVAV_GAD__SOURCES_AT_SUPERMAIN_DOT_COM__INCLUDED_)
#define AFX_PICTURE_H__COPYFREE_BY_YOVAV_GAD__SOURCES_AT_SUPERMAIN_DOT_COM__INCLUDED_


#pragma once


/////////////////////////////////////////////////////////////////////////////
// DEPRECEATED: This class should be replaced by the CXImage library classes
/////////////////////////////////////////////////////////////////////////////
class CPicture
{
public:
    CPicture();
    virtual ~CPicture();

    BOOL Load(const CString& sFilePathName);
    BOOL LoadFromFile(FILE *fptr);
    BOOL SaveToFile(FILE *fptr);
    BOOL CopyToPicture(CPicture *dstPic, const CString& exchangeFile);

    IPicture *IPicturePtr()
    {
        return m_IPicture;
    }
    LONG Height() const
    {
        return m_Height;
    }
    LONG Width() const
    {
        return m_Width;
    }

protected:
    void FreePictureData();
    BOOL Load(UINT ResourceName, LPCTSTR ResourceType);
    BOOL LoadPictureData(BYTE *pBuffer, int nSize);
    BOOL SaveAsBitmap(const CString& sFilePathName);
    BOOL Show(CDC *pDC, CPoint LeftTop, CPoint WidthHeight, int MagnifyX, int MagnifyY);
    BOOL Show(CDC *pDC, CRect DrawRect);
    BOOL ShowBitmapResource(CDC *pDC, int BMPResource, CPoint LeftTop);
    BOOL UpdateSizeOnDC(CDC *pDC);

protected:
    IPicture *m_IPicture{0}; // Same As LPPICTURE (typedef IPicture __RPC_FAR *LPPICTURE)

    LONG m_Height{0}; // Height (In Pixels Ignor What Current Device Context Uses)
    LONG m_Width{0};  // Width (In Pixels Ignor What Current Device Context Uses)
    LONG m_Weight{0}; // Size Of The Image Object In Bytes (File OR Resource)
};

#endif // !defined(AFX_PICTURE_H__COPYFREE_BY_YOVAV_GAD__SOURCES_AT_SUPERMAIN_DOT_COM__INCLUDED_)
