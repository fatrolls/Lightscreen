#ifndef LIGHTSCREENWINDOW_H
#define LIGHTSCREENWINDOW_H

#include <QtGui/QDialog>
#include <QPointer>
#include <QSystemTrayIcon>

#include "updater/updater.h"
#include "tools/screenshot.h"

#include "ui_lightscreenwindow.h"

class QHttp;
class Updater;
class QSettings;
class LightscreenWindow : public QDialog
{
    Q_OBJECT

public:
  LightscreenWindow(QWidget *parent = 0);
  ~LightscreenWindow();

public slots:
  void action(int mode = 3);
  void areaHotkey();
  void checkForUpdates();
  void cleanup(Screenshot::Options options);
  bool closingWithoutTray();
  void goToFolder();
  void messageReceived(const QString message);
  void messageClicked();
  void preview(Screenshot* screenshot);
  void restoreNotification();
  void screenshotAction(int mode = 0);
  void screenshotActionTriggered(QAction* action);
  void showHotkeyError(QStringList hotkeys);
  void showOptions();
  void showScreenshotMenu();
  void showScreenshotMessage(Screenshot::Result result, QString fileName);
  void notify(Screenshot::Result result);
  void toggleVisibility(QSystemTrayIcon::ActivationReason reason = QSystemTrayIcon::DoubleClick);
  void updaterDone(bool result);
  void windowHotkey();
  void windowPickerHotkey();

private slots:
  void applySettings();

private:
  void compressPng(QString fileName);
  void connectHotkeys();
  void createTrayIcon();

  // Convenience function
  QSettings *settings() const;

protected:
  bool event(QEvent *event);

private:
  bool mDoCache;
  bool mHideTrigger;
  bool mReviveMain;
  bool mWasVisible;
  bool mIsOptimizing;
  int  mLastMode;
  QString mLastScreenshot;
  QPointer<QSystemTrayIcon> mTrayIcon;
  Ui::LightscreenWindowClass ui;

};

#endif // LIGHTSCREENWINDOW_H
