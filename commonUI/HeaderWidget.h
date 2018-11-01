/*********************************************************************************
**
** Copyright (c) 2017 The University of Notre Dame
** Copyright (c) 2017 The Regents of the University of California
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
// Modified by Peter Sempolinski, for the Natural Hazard Modeling Laboratory, director: Ahsan Kareem, at Notre Dame

#ifndef HEADER_WIDGET_H
#define HEADER_WIDGET_H

#include <QFrame>

#include <QHBoxLayout>
#include <QLabel>

/*! \brief The HeaderWidget is variant of SimCenter's standard HeaderWidget, for display at the top of all program windows.
 *
 *  The HeaderWidget includes capacity for adding other widgets, for display of logged-in user or for a logout button, as needed.
 */
class HeaderWidget : public QFrame
{
    Q_OBJECT
public:
    /*! \brief The HeaderWidget is constructed in the manner of a QWidget.
     *
     *  The easiet way is to use the "promote" functionality of the form editor in the Qt creator.
     *
     *  @param parent Typically, the containing window will be the parent.
     */
    explicit HeaderWidget(QWidget *parent = nullptr);
    ~HeaderWidget();

    /*! \brief The message displayed in the header can be changed using this method.
     *
     *  @param newText will denote the new text displayed in the header
     */
    void setHeadingText(const QString &newText);
    /*! \brief On the right side of the header, a set of new widgets can be added.
     *
     *  @param newWidget is a pointer to the QWidget to be appended to the header.
     *
     *  The added widget will be reparented by the HeaderWidget.
     */
    void appendWidget(QWidget * newWidget);

signals:

public slots:

private:
    QHBoxLayout *subLayout;// leaving visible in case need to add stuff, i.e. login
    QLabel *titleText;    // need to change title from default
};

#endif // HEADER_WIDGET_H
