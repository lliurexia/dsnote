/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ../dbus/org.mkiol.Stt.xml -p dbus_stt_inf
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUS_STT_INF_H
#define DBUS_STT_INF_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface org.mkiol.Speech
 */
class OrgMkiolSpeechInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "org.mkiol.Speech"; }

public:
    OrgMkiolSpeechInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~OrgMkiolSpeechInterface();

    Q_PROPERTY(int CurrentTask READ currentTask)
    inline int currentTask() const
    { return qvariant_cast< int >(property("CurrentTask")); }

    Q_PROPERTY(QString DefaultSttLang READ defaultSttLang WRITE setDefaultSttLang)
    inline QString defaultSttLang() const
    { return qvariant_cast< QString >(property("DefaultSttLang")); }
    inline void setDefaultSttLang(const QString &value)
    { setProperty("DefaultSttLang", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultSttModel READ defaultSttModel WRITE setDefaultSttModel)
    inline QString defaultSttModel() const
    { return qvariant_cast< QString >(property("DefaultSttModel")); }
    inline void setDefaultSttModel(const QString &value)
    { setProperty("DefaultSttModel", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultTtsLang READ defaultTtsLang WRITE setDefaultTtsLang)
    inline QString defaultTtsLang() const
    { return qvariant_cast< QString >(property("DefaultTtsLang")); }
    inline void setDefaultTtsLang(const QString &value)
    { setProperty("DefaultTtsLang", QVariant::fromValue(value)); }

    Q_PROPERTY(QString DefaultTtsModel READ defaultTtsModel WRITE setDefaultTtsModel)
    inline QString defaultTtsModel() const
    { return qvariant_cast< QString >(property("DefaultTtsModel")); }
    inline void setDefaultTtsModel(const QString &value)
    { setProperty("DefaultTtsModel", QVariant::fromValue(value)); }

    Q_PROPERTY(int Speech READ speech)
    inline int speech() const
    { return qvariant_cast< int >(property("Speech")); }

    Q_PROPERTY(int State READ state)
    inline int state() const
    { return qvariant_cast< int >(property("State")); }

    Q_PROPERTY(QVariantMap SttLangs READ sttLangs)
    inline QVariantMap sttLangs() const
    { return qvariant_cast< QVariantMap >(property("SttLangs")); }

    Q_PROPERTY(QVariantMap SttModels READ sttModels)
    inline QVariantMap sttModels() const
    { return qvariant_cast< QVariantMap >(property("SttModels")); }

    Q_PROPERTY(QVariantMap Translations READ translations)
    inline QVariantMap translations() const
    { return qvariant_cast< QVariantMap >(property("Translations")); }

    Q_PROPERTY(QVariantMap TtsLangs READ ttsLangs)
    inline QVariantMap ttsLangs() const
    { return qvariant_cast< QVariantMap >(property("TtsLangs")); }

    Q_PROPERTY(QVariantMap TtsModels READ ttsModels)
    inline QVariantMap ttsModels() const
    { return qvariant_cast< QVariantMap >(property("TtsModels")); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<int> Cancel(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("Cancel"), argumentList);
    }

    inline QDBusPendingReply<int> KeepAliveService()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("KeepAliveService"), argumentList);
    }

    inline QDBusPendingReply<int> KeepAliveTask(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("KeepAliveTask"), argumentList);
    }

    inline QDBusPendingReply<int> Reload()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Reload"), argumentList);
    }

    inline QDBusPendingReply<double> SttGetFileTranscribeProgress(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("SttGetFileTranscribeProgress"), argumentList);
    }

    inline QDBusPendingReply<int> SttStartListen(int mode, const QString &lang, bool translate)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(mode) << QVariant::fromValue(lang) << QVariant::fromValue(translate);
        return asyncCallWithArgumentList(QStringLiteral("SttStartListen"), argumentList);
    }

    inline QDBusPendingReply<int> SttStopListen(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("SttStopListen"), argumentList);
    }

    inline QDBusPendingReply<int> SttTranscribeFile(const QString &file, const QString &lang, bool translate)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(file) << QVariant::fromValue(lang) << QVariant::fromValue(translate);
        return asyncCallWithArgumentList(QStringLiteral("SttTranscribeFile"), argumentList);
    }

    inline QDBusPendingReply<int> TtsPlaySpeech(const QString &text, const QString &lang)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(text) << QVariant::fromValue(lang);
        return asyncCallWithArgumentList(QStringLiteral("TtsPlaySpeech"), argumentList);
    }

    inline QDBusPendingReply<int> TtsStopSpeech(int task)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(task);
        return asyncCallWithArgumentList(QStringLiteral("TtsStopSpeech"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void CurrentTaskPropertyChanged(int task);
    void DefaultSttLangPropertyChanged(const QString &lang);
    void DefaultSttModelPropertyChanged(const QString &model);
    void DefaultTtsLangPropertyChanged(const QString &lang);
    void DefaultTtsModelPropertyChanged(const QString &model);
    void ErrorOccured(int code);
    void SpeechPropertyChanged(int speech);
    void StatePropertyChanged(int state);
    void SttFileTranscribeFinished(int task);
    void SttFileTranscribeProgress(double progress, int task);
    void SttIntermediateTextDecoded(const QString &text, const QString &lang, int task);
    void SttLangsPropertyChanged(const QVariantMap &langs);
    void SttModelsPropertyChanged(const QVariantMap &models);
    void SttTextDecoded(const QString &text, const QString &lang, int task);
    void TtsLangsPropertyChanged(const QVariantMap &langs);
    void TtsModelsPropertyChanged(const QVariantMap &models);
    void TtsPlaySpeechFinished(int task);
};

namespace org {
  namespace mkiol {
    typedef ::OrgMkiolSpeechInterface Speech;
  }
}
#endif
