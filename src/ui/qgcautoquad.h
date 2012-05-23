#ifndef QGCAUTOQUAD_H
#define QGCAUTOQUAD_H

#include "LinkManager.h"
#include "aqlogparser.h"
#include <SerialLinkInterface.h>
#include <SerialLink.h>
#include "QGCUASParamManager.h"
#include "UASInterface.h"
#include "qgcaqparamwidget.h"
#include "Linecharts.h"
#include "IncrementalPlot.h"
#include <QWidget>
#include <QProcess>
#include <QMap>
#include <QStandardItemModel>

namespace Ui {
class QGCAutoquad;
}

class QGCAutoquad : public QWidget 
{
    Q_OBJECT
    
public:
    explicit QGCAutoquad(QWidget *parent = 0);
    ~QGCAutoquad();
    UASInterface* getUAS();

signals:
    void visibilityChanged(bool visible);

protected slots:
    void selectFWToFlash();
    void handleConnectButton();
    void changeEvent(QEvent *e);
    void addUAS(UASInterface* uas_ext);
    void setActiveUAS(UASInterface* uas_ext);
    void setChannelScaled(int channelId, float normalized);
    void setChannelRaw(int channelId, float normalized);
    void getGUIpara();

private slots:
        void prtstexit(int);
        void prtstdout();
        void prtstderr();
        void setPortName(QString port);
        void setPortNameEsc32(QString port);
        void flashFW();
        void ConnectEsc32();
        void startcal1();
        void startcal2();
        void startcal3();
        void startsim1();
        void startsim1b();
        void startsim2();
        void startsim3();
        void abortcal1();
        void abortcal2();
        void abortcal3();
        void abortsim1();
        void abortsim1b();
        void abortsim2();
        void abortsim3();
        void raw_transmitter_view();
        void check_var();
        void check_stop();
        void addStatic();
        void delStatic();
        void addDynamic();
        void delDynamic();
        void setRadio();
        void setFrame();
        void setUsersParams();
        void CreateUsersParams();
        void WriteUsersParams();
		void LoadFrameFromFile();
		void SaveFrameToFile();
		void CalculatDeclination();
        void CurveItemChanged(QStandardItem *item);
        void OpenLogFile();
        void ReloadLogFile();
        void save_PID_toAQ1();
        void save_PID_toAQ2();
        void save_PID_toAQ3();
        void save_plot_image();

        void connectedEsc32();
        void disconnectedEsc32();
        void destroyedEsc32();
        void BytesRceivedEsc32(LinkInterface* link, QByteArray bytes);
        void read_config_esc32();
        void saveToEsc32();

private:
        Ui::QGCAutoquad *ui;
        QString output;
        QString output_cal1;
        QString output_cal2;
        QString output_cal3;
        QString output_sim1;
        QString output_sim1b;
        QString output_sim2;
        QString output_sim3;
        QString fileToFlash;
        QString portName;
        QString portNameEsc32;
        QProcess ps_master;
        LinkInterface* currLink;
        SerialLink* seriallink;
        SerialLink* seriallinkEsc32;
        void setupPortList();
        UASInterface* uas;
        QGCAQParamWidget* paramaq;
        int VisibleWidget;
        void loadSettings();
        void writeSettings();
        QStringList StaticFiles;
        QStringList DynamicFiles;
		quint32 active_cal_mode;
        QString UsersParamsFile;
        void ShowUsersParams(QString fileName);
        void DecodeLogFile(QString fileName);
        QString LogFile;
        void QuestionForROM();
        void exportPDF(QString fileName);
        void exportSVG(QString fileName);
        QString LastFilePath;
        int StepMessageFromEsc32;
        QString LIST_MessageFromEsc32;
        QString ParaWriten_MessageFromEsc32;
        void decodeParameterFromEsc32(QString Message);
        QMap<QString, QString> paramEsc32;
        QMap<QString, QString> paramEsc32Written;

protected:
        void showEvent(QShowEvent* event);
        void hideEvent(QHideEvent* event);
        void SetupListView();
        IncrementalPlot* plot;
        AQLogParser parser;

};

#endif // QGCAUTOQUAD_H
