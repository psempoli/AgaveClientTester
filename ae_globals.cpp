/*********************************************************************************
**
** Copyright (c) 2018 The University of Notre Dame
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
// Written by Peter Sempolinski, for the Natural Hazard Modeling Laboratory, director: Ahsan Kareem, at Notre Dame

#include "ae_globals.h"

#include "utilFuncs/agavesetupdriver.h"

AgaveSetupDriver * ae_globals::theDriver = nullptr;

ae_globals::ae_globals() {}

void ae_globals::displayFatalPopup(QString message, QString header)
{
    QMessageBox errorMessage;
    errorMessage.setWindowTitle(header);
    errorMessage.setText(message);
    errorMessage.setStandardButtons(QMessageBox::Close);
    errorMessage.setDefaultButton(QMessageBox::Close);
    errorMessage.setIcon(QMessageBox::Critical);
    errorMessage.exec();
    QCoreApplication::instance()->exit(1);
    qFatal("%s", qPrintable(message));
}

void ae_globals::displayPopup(QString message, QString header)
{
    QMessageBox infoMessage;
    infoMessage.setWindowTitle(header);
    infoMessage.setText(message);
    infoMessage.setIcon(QMessageBox::Information);
    infoMessage.exec();
}

bool ae_globals::isValidFolderName(QString folderName)
{
    if (folderName.isEmpty())
    {
        return false;
    }

    for (QChar aLetter : folderName)
    {
        if (aLetter.isDigit()) continue;
        if (aLetter.isSpace()) continue;
        if (aLetter.isLetter()) continue;
        if (aLetter == '_') continue;
        return false;
    }

    //TODO: PRS
    return true;
}

bool ae_globals::isExtantLocalFolder(QString folderName)
{
    if (folderName.isEmpty())
    {
        return false;
    }
    QDir dirCheck(folderName);

    return dirCheck.exists();
}

bool ae_globals::folderNamesMatch(QString folder1, QString folder2)
{
    QStringList folderParts1 = folder1.split('\\');
    QStringList folderParts2 = folder2.split('\\');

    if (folderParts1.size() != folderParts2.size())
    {
        return false;
    }

    for (int i = 0; i < folderParts1.size(); i++)
    {
        if (folderParts1.at(i) != folderParts2.at(i))
        {
            return false;
        }
    }
    return true;
}

AgaveSetupDriver * ae_globals::get_Driver()
{
    return theDriver;
}

void ae_globals::set_Driver(AgaveSetupDriver * newDriver)
{
    if (newDriver == nullptr)
    {
        displayFatalPopup("Program Driver object defined as null. Please note the circumstances of this error and report it to the developers.", "Internal Error");
    }
    if (theDriver != nullptr)
    {
        displayFatalPopup("Program Driver object has multiple definitions. Please note the circumstances of this error and report it to the developers.", "Internal Error");
    }
    theDriver = newDriver;
}

RemoteDataInterface * ae_globals::get_connection()
{
    if (theDriver == nullptr) return nullptr;
    return theDriver->getDataConnection();
}

JobOperator * ae_globals::get_job_handle()
{
    if (theDriver == nullptr) return nullptr;
    return theDriver->getJobHandler();
}

FileOperator * ae_globals::get_file_handle()
{
    if (theDriver == nullptr) return nullptr;
    return theDriver->getFileHandler();
}
