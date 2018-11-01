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
// Written by Peter Sempolinski, for the Natural Hazard Modeling Laboratory, director: Ahsan Kareem, at Notre Dame

#ifndef AGAVESETUPDRIVER_H
#define AGAVESETUPDRIVER_H

#include <QObject>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QLoggingCategory>

enum class RequestState;
enum class RemoteDataInterfaceState;

class RemoteDataInterface;
class AgaveHandler;
class AuthForm;
class JobOperator;
class FileOperator;

/*! \brief The AgaveSetupDriver in an astract class for a driver object for certain SimCenter programs that invoke Agave.
 *
 *  Typically, a main() function will entail creating a subclass of this object, running loadStyleFiles(), and then calling startup() before starting the Qt loop.
 *
 *  The driver is responsible to creating and removing subordinate program objects, most prominantly, the login and main windows. There should be only one driver object for the program.
 */
class AgaveSetupDriver : public QObject
{
    Q_OBJECT
public:
    /*! \brief Constructs a new AgaveSetupDriver with given command-line parameters.
     *
     *  @param argc should be the argc from main()
     *  @param argv should be the argv from main()
     *  @param parent Typically, the main driver object should not have a parent.
     *
     *  The constructor for the driver object should be called in main(). There should be only one driver. The driver will register itself with ae_globals. As such, construction of a second driver will crash the program.
     */
    explicit AgaveSetupDriver(int argc, char *argv[], QObject *parent = nullptr);
    ~AgaveSetupDriver();

    /*! \brief This virtual function will load the QSS style files for the program.
     *
     * This function should be called in main, usually before startup().
     *
     */
    virtual void loadStyleFiles() = 0;

    /*! \brief This virtual function will load the QSS style files for the program.
     *
     * This function should be called in main, usually before startup().
     *
     */
    virtual void startup() = 0;
    void createAndStartAgaveThread();



    RemoteDataInterface *getDataConnection();
    JobOperator * getJobHandler();
    FileOperator * getFileHandler();

    virtual QString getBanner() = 0;
    virtual QString getVersion() = 0;

    static void setDebugLogging(bool loggingEnabled);
    static void debugCategoryFilter(QLoggingCategory *category);

    static bool sslCheckOkay();

private slots:
    void getAuthReply(RequestState authReply);
    void subWindowHidden(bool nowVisible);
    void newConnectionState(RemoteDataInterfaceState newState);
    void shutdownCallback();

public slots:
    void shutdown();

protected:
    virtual void closeAuthScreen() = 0;

    QNetworkAccessManager * theNetManager = nullptr;
    QThread * remoteInterfacesThread = nullptr;

    AuthForm * authWindow = nullptr;

    AgaveHandler * myDataInterface = nullptr;
    JobOperator * myJobHandle = nullptr;
    FileOperator * myFileHandle = nullptr;

    static QStringList enabledDebugs;
    bool shutdownStarted = false;
    bool debugLoggingEnabled = false;
    bool offlineMode = false;
};

#endif // AGAVESETUPDRIVER_H
