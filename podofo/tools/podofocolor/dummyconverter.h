/**
 * SPDX-FileCopyrightText: (C) 2010 Dominik Seichter <domseichter@web.de>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef _DUMMY_CONVERTER_H_
#define _DUMMY_CONVERTER_H_

#include "iconverter.h"

 /**
  * Dummy implementation of a converter,
  * which sets all colors to RGB red.
  */
class DummyConverter : public IConverter
{
public:
    DummyConverter();

    /**
     * A helper method that is called to inform the converter
     * when a new page is analyzed.
     *
     * @param page page object
     * @param pageIndex index of the page in the document
     */
    virtual void StartPage(PoDoFo::PdfPage& page, int pageIndex);

    /**
     * A helper method that is called to inform the converter
     * when a new page has been analyzed completely.
     *
     * @param page page object
     * @param pageIndex index of the page in the document
     */
    virtual void EndPage(PoDoFo::PdfPage& page, int pageIndex);

    /**
     * A helper method that is called to inform the converter
     * when a new xobjext is analyzed.
     *
     * @param obj the xobject
     */
    virtual void StartXObject(PoDoFo::PdfXObject& obj);

    /**
     * A helper method that is called to inform the converter
     * when a xobjext has been analyzed.
     *
     * @param obj the xobject
     */
    virtual void EndXObject(PoDoFo::PdfXObject& obj);

    /**
     * This method is called whenever a gray stroking color is set
     * using the 'G' PDF command.
     *
     * @param a grayscale color object
     * @returns a new color which should be set instead (any colorspace)
     */
    virtual PoDoFo::PdfColor SetStrokingColorGray(const PoDoFo::PdfColor& color);

    virtual PoDoFo::PdfColor SetStrokingColorRGB(const PoDoFo::PdfColor& color);
    virtual PoDoFo::PdfColor SetStrokingColorCMYK(const PoDoFo::PdfColor& color);

    virtual PoDoFo::PdfColor SetNonStrokingColorGray(const PoDoFo::PdfColor& color);
    virtual PoDoFo::PdfColor SetNonStrokingColorRGB(const PoDoFo::PdfColor& color);
    virtual PoDoFo::PdfColor SetNonStrokingColorCMYK(const PoDoFo::PdfColor& color);

};

#endif // _DUMMY_CONVERTER_H_
