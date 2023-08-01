/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp ../dbus/org.mkiol.Speech.xml -a dbus_speech_adaptor
 *
 * qdbusxml2cpp is Copyright (C) 2022 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "dbus_speech_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class SpeechAdaptor
 */

SpeechAdaptor::SpeechAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

SpeechAdaptor::~SpeechAdaptor()
{
    // destructor
}

int SpeechAdaptor::currentTask() const
{
    // get the value of property CurrentTask
    return qvariant_cast< int >(parent()->property("CurrentTask"));
}

QString SpeechAdaptor::defaultMntLang() const
{
    // get the value of property DefaultMntLang
    return qvariant_cast< QString >(parent()->property("DefaultMntLang"));
}

void SpeechAdaptor::setDefaultMntLang(const QString &value)
{
    // set the value of property DefaultMntLang
    parent()->setProperty("DefaultMntLang", QVariant::fromValue(value));
}

QString SpeechAdaptor::defaultMntOutLang() const
{
    // get the value of property DefaultMntOutLang
    return qvariant_cast< QString >(parent()->property("DefaultMntOutLang"));
}

void SpeechAdaptor::setDefaultMntOutLang(const QString &value)
{
    // set the value of property DefaultMntOutLang
    parent()->setProperty("DefaultMntOutLang", QVariant::fromValue(value));
}

QString SpeechAdaptor::defaultSttLang() const
{
    // get the value of property DefaultSttLang
    return qvariant_cast< QString >(parent()->property("DefaultSttLang"));
}

void SpeechAdaptor::setDefaultSttLang(const QString &value)
{
    // set the value of property DefaultSttLang
    parent()->setProperty("DefaultSttLang", QVariant::fromValue(value));
}

QString SpeechAdaptor::defaultSttModel() const
{
    // get the value of property DefaultSttModel
    return qvariant_cast< QString >(parent()->property("DefaultSttModel"));
}

void SpeechAdaptor::setDefaultSttModel(const QString &value)
{
    // set the value of property DefaultSttModel
    parent()->setProperty("DefaultSttModel", QVariant::fromValue(value));
}

QString SpeechAdaptor::defaultTtsLang() const
{
    // get the value of property DefaultTtsLang
    return qvariant_cast< QString >(parent()->property("DefaultTtsLang"));
}

void SpeechAdaptor::setDefaultTtsLang(const QString &value)
{
    // set the value of property DefaultTtsLang
    parent()->setProperty("DefaultTtsLang", QVariant::fromValue(value));
}

QString SpeechAdaptor::defaultTtsModel() const
{
    // get the value of property DefaultTtsModel
    return qvariant_cast< QString >(parent()->property("DefaultTtsModel"));
}

void SpeechAdaptor::setDefaultTtsModel(const QString &value)
{
    // set the value of property DefaultTtsModel
    parent()->setProperty("DefaultTtsModel", QVariant::fromValue(value));
}

QVariantList SpeechAdaptor::mntLangList() const
{
    // get the value of property MntLangList
    return qvariant_cast< QVariantList >(parent()->property("MntLangList"));
}

QVariantMap SpeechAdaptor::mntLangs() const
{
    // get the value of property MntLangs
    return qvariant_cast< QVariantMap >(parent()->property("MntLangs"));
}

int SpeechAdaptor::state() const
{
    // get the value of property State
    return qvariant_cast< int >(parent()->property("State"));
}

QVariantList SpeechAdaptor::sttLangList() const
{
    // get the value of property SttLangList
    return qvariant_cast< QVariantList >(parent()->property("SttLangList"));
}

QVariantMap SpeechAdaptor::sttLangs() const
{
    // get the value of property SttLangs
    return qvariant_cast< QVariantMap >(parent()->property("SttLangs"));
}

QVariantMap SpeechAdaptor::sttModels() const
{
    // get the value of property SttModels
    return qvariant_cast< QVariantMap >(parent()->property("SttModels"));
}

QVariantList SpeechAdaptor::sttTtsLangList() const
{
    // get the value of property SttTtsLangList
    return qvariant_cast< QVariantList >(parent()->property("SttTtsLangList"));
}

int SpeechAdaptor::taskState() const
{
    // get the value of property TaskState
    return qvariant_cast< int >(parent()->property("TaskState"));
}

QVariantMap SpeechAdaptor::translations() const
{
    // get the value of property Translations
    return qvariant_cast< QVariantMap >(parent()->property("Translations"));
}

QVariantList SpeechAdaptor::ttsLangList() const
{
    // get the value of property TtsLangList
    return qvariant_cast< QVariantList >(parent()->property("TtsLangList"));
}

QVariantMap SpeechAdaptor::ttsLangs() const
{
    // get the value of property TtsLangs
    return qvariant_cast< QVariantMap >(parent()->property("TtsLangs"));
}

QVariantMap SpeechAdaptor::ttsModels() const
{
    // get the value of property TtsModels
    return qvariant_cast< QVariantMap >(parent()->property("TtsModels"));
}

QVariantMap SpeechAdaptor::tttLangs() const
{
    // get the value of property TttLangs
    return qvariant_cast< QVariantMap >(parent()->property("TttLangs"));
}

QVariantMap SpeechAdaptor::tttModels() const
{
    // get the value of property TttModels
    return qvariant_cast< QVariantMap >(parent()->property("TttModels"));
}

int SpeechAdaptor::Cancel(int task)
{
    // handle method call org.mkiol.Speech.Cancel
    int result;
    QMetaObject::invokeMethod(parent(), "Cancel", Q_RETURN_ARG(int, result), Q_ARG(int, task));
    return result;
}

int SpeechAdaptor::KeepAliveService()
{
    // handle method call org.mkiol.Speech.KeepAliveService
    int timer;
    QMetaObject::invokeMethod(parent(), "KeepAliveService", Q_RETURN_ARG(int, timer));
    return timer;
}

int SpeechAdaptor::KeepAliveTask(int task)
{
    // handle method call org.mkiol.Speech.KeepAliveTask
    int timer;
    QMetaObject::invokeMethod(parent(), "KeepAliveTask", Q_RETURN_ARG(int, timer), Q_ARG(int, task));
    return timer;
}

QVariantMap SpeechAdaptor::MntGetOutLangs(const QString &lang)
{
    // handle method call org.mkiol.Speech.MntGetOutLangs
    QVariantMap out_langs;
    QMetaObject::invokeMethod(parent(), "MntGetOutLangs", Q_RETURN_ARG(QVariantMap, out_langs), Q_ARG(QString, lang));
    return out_langs;
}

int SpeechAdaptor::MntTranslate(const QString &text, const QString &lang, const QString &out_lang)
{
    // handle method call org.mkiol.Speech.MntTranslate
    int task;
    QMetaObject::invokeMethod(parent(), "MntTranslate", Q_RETURN_ARG(int, task), Q_ARG(QString, text), Q_ARG(QString, lang), Q_ARG(QString, out_lang));
    return task;
}

int SpeechAdaptor::Reload()
{
    // handle method call org.mkiol.Speech.Reload
    int result;
    QMetaObject::invokeMethod(parent(), "Reload", Q_RETURN_ARG(int, result));
    return result;
}

double SpeechAdaptor::SttGetFileTranscribeProgress(int task)
{
    // handle method call org.mkiol.Speech.SttGetFileTranscribeProgress
    double progress;
    QMetaObject::invokeMethod(parent(), "SttGetFileTranscribeProgress", Q_RETURN_ARG(double, progress), Q_ARG(int, task));
    return progress;
}

int SpeechAdaptor::SttStartListen(int mode, const QString &lang, const QString &out_lang)
{
    // handle method call org.mkiol.Speech.SttStartListen
    int task;
    QMetaObject::invokeMethod(parent(), "SttStartListen", Q_RETURN_ARG(int, task), Q_ARG(int, mode), Q_ARG(QString, lang), Q_ARG(QString, out_lang));
    return task;
}

int SpeechAdaptor::SttStopListen(int task)
{
    // handle method call org.mkiol.Speech.SttStopListen
    int result;
    QMetaObject::invokeMethod(parent(), "SttStopListen", Q_RETURN_ARG(int, result), Q_ARG(int, task));
    return result;
}

int SpeechAdaptor::SttTranscribeFile(const QString &file, const QString &lang, const QString &out_lang)
{
    // handle method call org.mkiol.Speech.SttTranscribeFile
    int task;
    QMetaObject::invokeMethod(parent(), "SttTranscribeFile", Q_RETURN_ARG(int, task), Q_ARG(QString, file), Q_ARG(QString, lang), Q_ARG(QString, out_lang));
    return task;
}

double SpeechAdaptor::TtsGetSpeechToFileProgress(int task)
{
    // handle method call org.mkiol.Speech.TtsGetSpeechToFileProgress
    double progress;
    QMetaObject::invokeMethod(parent(), "TtsGetSpeechToFileProgress", Q_RETURN_ARG(double, progress), Q_ARG(int, task));
    return progress;
}

int SpeechAdaptor::TtsPlaySpeech(const QString &text, const QString &lang)
{
    // handle method call org.mkiol.Speech.TtsPlaySpeech
    int task;
    QMetaObject::invokeMethod(parent(), "TtsPlaySpeech", Q_RETURN_ARG(int, task), Q_ARG(QString, text), Q_ARG(QString, lang));
    return task;
}

int SpeechAdaptor::TtsSpeechToFile(const QString &text, const QString &lang)
{
    // handle method call org.mkiol.Speech.TtsSpeechToFile
    int task;
    QMetaObject::invokeMethod(parent(), "TtsSpeechToFile", Q_RETURN_ARG(int, task), Q_ARG(QString, text), Q_ARG(QString, lang));
    return task;
}

int SpeechAdaptor::TtsStopSpeech(int task)
{
    // handle method call org.mkiol.Speech.TtsStopSpeech
    int result;
    QMetaObject::invokeMethod(parent(), "TtsStopSpeech", Q_RETURN_ARG(int, result), Q_ARG(int, task));
    return result;
}

