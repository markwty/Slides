/***************************************************************
 * Name:      SlidesApp.h
 * Purpose:   Defines Application Class
 * Author:    Mark ()
 * Created:   2020-02-01
 * Copyright: Mark ()
 * License:
 **************************************************************/
#include "wx/wxprec.h"
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif


class wxmApp: public wxApp
{
public:
    virtual bool OnInit() override;
};

