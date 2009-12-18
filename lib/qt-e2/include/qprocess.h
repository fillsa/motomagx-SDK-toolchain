/****************************************************************************
**
** Copyright (C) 1992-2008 Trolltech ASA. All rights reserved.
**
** This file is part of the QtCore module of the Qt Toolkit.
**
** This file may be used under the terms of the GNU General Public
** License versions 2.0 or 3.0 as published by the Free Software
** Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file.  Alternatively you may (at
** your option) use any later version of the GNU General Public
** License if such license has been publicly approved by Trolltech ASA
** (or its successors, if any) and the KDE Free Qt Foundation. In
** addition, as a special exception, Trolltech gives you certain
** additional rights. These rights are described in the Trolltech GPL
** Exception version 1.2, which can be found at
** http://www.trolltech.com/products/qt/gplexception/ and in the file
** GPL_EXCEPTION.txt in this package.
**
** Please review the following information to ensure GNU General
** Public Licensing requirements will be met:
** http://trolltech.com/products/qt/licenses/licensing/opensource/. If
** you are unsure which license is appropriate for your use, please
** review the following information:
** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
** or contact the sales department at sales@trolltech.com.
**
** In addition, as a special exception, Trolltech, as the sole
** copyright holder for Qt Designer, grants users of the Qt/Eclipse
** Integration plug-in the right for the Qt/Eclipse Integration to
** link to functionality provided by Qt Designer and its related
** libraries.
**
** This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
** INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE. Trolltech reserves all rights not expressly
** granted herein.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#ifndef QPROCESS_H
#define QPROCESS_H

#include <qiodevice.h>
#include <qstringlist.h>

class QProcessPrivate;

class QProcess : public QIODevice
{
    Q_OBJECT
public:
    enum ProcessError {
        FailedToStart, //### file not found, resource error
        Crashed,
        Timedout,
        ReadError,
        WriteError,
        UnknownError
    };
    enum ProcessState {
        NotRunning,
        Starting,
        Running
    };
    enum ProcessChannel {
        StandardOutput,
        StandardError
    };
    enum ProcessChannelMode {
        SeparateChannels,
        MergedChannels,
        ForwardedChannels
    };
    enum ExitStatus {
        NormalExit,
        CrashExit
    };

    explicit QProcess(QObject *parent = 0);
    virtual ~QProcess();

    void start(const QString &program, const QStringList &arguments);
    void start(const QString &program);
    void start();

    ProcessChannelMode readChannelMode() const;
    void setReadChannelMode(ProcessChannelMode mode);
    ProcessChannelMode processChannelMode() const;
    void setProcessChannelMode(ProcessChannelMode mode);

    ProcessChannel readChannel() const;
    void setReadChannel(ProcessChannel channel);

    void closeReadChannel(ProcessChannel channel);
    void closeWriteChannel();

    void setStandardInputFile(const QString &fileName);
    void setStandardOutputFile(const QString &fileName);
    void setStandardErrorFile(const QString &fileName);
    void setStandardOutputProcess(QProcess *destination);

    QString workingDirectory() const;
    void setWorkingDirectory(const QString &dir);

    void setEnvironment(const QStringList &environment);
    QStringList environment() const;

    QProcess::ProcessError error() const;
    QProcess::ProcessState state() const;

    // #### Qt 5: Q_PID is a pointer on Windows and a value on Unix
    //Q_PID pid() const;

    bool waitForStarted(int msecs = 30000);
    bool waitForReadyRead(int msecs = 30000);
    bool waitForBytesWritten(int msecs = 30000);
    bool waitForFinished(int msecs = 30000);

    QByteArray readAllStandardOutput();
    QByteArray readAllStandardError();

    int exitCode() const;
    QProcess::ExitStatus exitStatus() const;

    // QIODevice
//    qint64 bytesAvailable() const;
//    qint64 bytesToWrite() const;
    bool isSequential() const;
    bool canReadLine() const;
    void close();
    bool atEnd() const;

    static int execute(const QString &program, const QStringList &arguments);
    static int execute(const QString &program);

    //static bool startDetached(const QString &program, const QStringList &arguments, const QString &workingDirectory, qint64 *pid = 0);
    static bool startDetached(const QString &program, const QStringList &arguments);
    static bool startDetached(const QString &program);

    static QStringList systemEnvironment();

public slots:
    void terminate();
    void kill();

signals:
    void started();
    void finished(int exitCode);
    void finished(int exitCode, QProcess::ExitStatus exitStatus);
    void error(QProcess::ProcessError error);
    void stateChanged(QProcess::ProcessState state);

    void readyReadStandardOutput();
    void readyReadStandardError();

protected:
    void setProcessState(ProcessState state);

    virtual void setupChildProcess();

    // QIODevice
//    qint64 readData(char *data, qint64 maxlen);
//    qint64 writeData(const char *data, qint64 len);

private:
    /*Q_DECLARE_PRIVATE(QProcess)
    Q_DISABLE_COPY(QProcess)

    Q_PRIVATE_SLOT(d_func(), bool _q_canReadStandardOutput())
    Q_PRIVATE_SLOT(d_func(), bool _q_canReadStandardError())
    Q_PRIVATE_SLOT(d_func(), bool _q_canWrite())
    Q_PRIVATE_SLOT(d_func(), bool _q_startupNotification())
    Q_PRIVATE_SLOT(d_func(), bool _q_processDied())
    Q_PRIVATE_SLOT(d_func(), void _q_notified())*/
    friend class QProcessManager;
};

#endif // QPROCESS_H
