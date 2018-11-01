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

/*! \mainpage Agave Explorer Summary
 *
 * \section intro_sec Executive Summary
 *
 *  The SimCenter Agave Explorer is intened to be a framework and example for UI application which access remote resources through and Agave server. In particular, this Agave Explorer accesses the Agave server run by DesignSafe.
 *
 * The Agave Explorer framework uses the Remote Interface, File Handler and Job Handler frameworks of the AgaveClientInterface repo. In addition to that, the Agave Explorer provides several untilites, including a controller object for a UI application (AgaveSetupDriver), window widgets for authentication (AuthForm), quick user prompts (SingleLineDialog), display of the copyright information (CopyrightDialog), a static class for commonly used global actions (ae_globals) and common header and footer widgets (FooterWidget and HeaderWidget).
 *
 * Using these, the Agave Explorer is a simple UI application which can view and manipulate the remote file system, and create an monitor remote Agave jobs.
 */

#ifndef AE_GLOBALS_H
#define AE_GLOBALS_H

#include <QMessageBox>
#include <QLoggingCategory>
#include <QDir>

Q_DECLARE_LOGGING_CATEGORY(agaveAppLayer)

class AgaveSetupDriver;
class RemoteDataInterface;
class FileOperator;
class JobOperator;

/*! \brief The ae_globals are a set of static methods, intended as global functions for AgaveExplorer programs.
 *
 *  These utility functions include error popups, folder name parsing, and locating key objects of the AgaveExplorer Program.
 */

class ae_globals
{
public:
    /*! \brief ae_globals is a static class. The constructor should never be used.
     */
    ae_globals();

    /*! \brief This will display an informational popup and kill the program.
     *
     *  \param message This is the content of the message displayed in the popup.
     *  \param header This short text appears in the header of the popup. The default is: "Critical Error"
     */
    [[ noreturn ]] static void displayFatalPopup(QString message, QString header = "Critical Error");

    /*! \brief This will display an informational popup and block the program until the user dismisses it.
     *
     *  \param message This is the content of the message displayed in the popup.
     *  \param header This short text appears in the header of the popup. The default is: "Error"
     */
    static void displayPopup(QString message, QString header = "Error");

    /*! \brief INCOMPLETE METHOD This method tests if a given string is a valid folder name.
     *
     *  Does not test if folder exists, only if its name is legal.
     *
     *  \param folderName Will return true if no invalid characters are in this string
     */
    static bool isValidFolderName(QString folderName);
    /*! \brief This method tests if a given string is a valid local folder name.
     *
     *  \param folderName Will return true if no this folder exists locally
     */
    static bool isExtantLocalFolder(QString folderName);
    /*! \brief This method tests if two given strings match each other as folder names.
     *
     *  This method accounts for potential extra slashes, and only recognizes \ slashes.
     */
    static bool folderNamesMatch(QString folder1, QString folder2);

    /*! \brief Returns a pointer to the driver object.
     */
    static AgaveSetupDriver * get_Driver();
    /*! \brief Sets the driver object for this program.
     *
     *  Kills the program if the new driver is a null pointer or if driver is already set.
     */
    static void set_Driver(AgaveSetupDriver * newDriver);

    /*! \brief Uses driver object to get RemoteDataInterface for this program.
     */
    static RemoteDataInterface * get_connection();
    /*! \brief Uses driver object to get JobOperator for this program.
     */
    static JobOperator * get_job_handle();
    /*! \brief Uses driver object to get FileOperator for this program.
     */
    static FileOperator * get_file_handle();

private:    
    static AgaveSetupDriver * theDriver;
};

#endif // AE_GLOBALS_H
