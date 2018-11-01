/*********************************************************************************
**
** Copyright (c) 2018 The Regents of the University of California
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** 1. Redistributions of source code must retain the above copyright notice, this
** list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright notice, this
** list of conditions and the following disclaimer in the documentation and/or other
** materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its contributors may
** be used to endorse or promote products derived from this software without specific
** prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
** EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
** SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
** TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
** BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
** IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
** SUCH DAMAGE.
**
***********************************************************************************/

// Contributors:
// Written: fmckenna

#ifndef FOOTER_WIDGET_H
#define FOOTER_WIDGET_H

#include <QFrame>

#include <QLabel>
#include <QHBoxLayout>
#include <QBitmap>

/*! \brief The FooterWidget is variant of SimCenter's standard FooterWidget, for display at the bottom of all program windows.
 *
 *  The Footer Widget includes the NSF logo, the SimCenter logo and a reference to the NSF grant number.
 */
class FooterWidget : public QFrame
{
    Q_OBJECT
public:
    /*! \brief The FooterWidget is constructed in the manner of a QWidget.
     *
     * The easiet way is to use the "promote" functionality of the form editor in the Qt creator.
     *
     *  @param parent Typically, the containing window will be the parent
     */
    explicit FooterWidget(QWidget *parent = nullptr);
    ~FooterWidget();

    /*! \brief Removes the text from the FooterWidget
     *
     *  The logo graphics will remain.
     */
    void condense();

signals:

public slots:

private:
    QLabel * nsfText;

};

#endif // FOOTER_WIDGET_H
