/* Copyright (C) 2021-2023 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef MODELSLISTMODEL_H
#define MODELSLISTMODEL_H

#include <QByteArray>
#include <QDebug>
#include <QHash>
#include <QObject>
#include <QString>
#include <QUrl>
#include <QVariant>
#include <QVariantList>

#include "itemmodel.h"
#include "listmodel.h"
#include "models_manager.h"

class ModelsListModel : public SelectableItemModel {
    Q_OBJECT
    Q_PROPERTY(bool downloading READ downloading NOTIFY downloadingChanged)
    Q_PROPERTY(QString lang READ lang WRITE setLang NOTIFY langChanged)
    Q_PROPERTY(unsigned int roleFilterFlags READ roleFilterFlags WRITE
                   setRoleFilterFlags NOTIFY roleFilterFlagsChanged)
    Q_PROPERTY(unsigned int featureFilterFlags READ featureFilterFlags WRITE
                   setFeatureFilterFlags NOTIFY featureFilterFlagsChanged)
    Q_PROPERTY(
        unsigned int disabledFeatureFilterFlags READ disabledFeatureFilterFlags
            NOTIFY disabledFeatureFilterFlagsChanged)
    Q_PROPERTY(
        bool defaultFilters READ defaultFilters NOTIFY defaultFiltersChanged)
   public:
    enum ModelRole { Stt = 0, Tts = 1, Mnt = 2, Ttt = 3 };
    Q_ENUM(ModelRole)

    enum ModelRoleFilterFlags : unsigned int {
        RoleNone = 0U,
        RoleStart = 1U << 0U,
        RoleStt = RoleStart,
        RoleTts = 1U << 1U,
        RoleMnt = 1U << 2U,
        RoleOther = 1U << 3U,
        RoleEnd = RoleOther,
        RoleAll = RoleStt | RoleTts | RoleMnt | RoleOther,
        RoleDefault = RoleAll
    };
    Q_ENUM(ModelRoleFilterFlags)

    enum ModelFeatureFilterFlags : unsigned int {
        FeatureNone = 0U,
        FeatureGenericStart = 1U << 0U,
        FeatureFirst = FeatureGenericStart,
        FeatureFastProcessing = FeatureGenericStart,
        FeatureMediumProcessing = 1U << 1U,
        FeatureSlowProcessing = 1U << 2U,
        FeatureQualityHigh = 1U << 3U,
        FeatureQualityMedium = 1U << 4U,
        FeatureQualityLow = 1U << 5U,
        FeatureEngineSttStart = 1U << 6U,
        FeatureEngineSttDs = FeatureEngineSttStart,
        FeatureEngineSttVosk = 1U << 7U,
        FeatureEngineSttWhisper = 1U << 8U,
        FeatureEngineSttFasterWhisper = 1U << 9U,
        FeatureEngineSttApril = 1U << 10U,
        FeatureEngineSttEnd = FeatureEngineSttApril,
        FeatureEngineTtsStart = 1U << 11U,
        FeatureEngineTtsEspeak = FeatureEngineTtsStart,
        FeatureEngineTtsPiper = 1U << 12U,
        FeatureEngineTtsRhvoice = 1U << 13U,
        FeatureEngineTtsCoqui = 1U << 14U,
        FeatureEngineTtsMimic3 = 1U << 15U,
        FeatureEngineTtsWhisperSpeech = 1U << 16U,
        FeatureEngineTtsEnd = FeatureEngineTtsWhisperSpeech,
        FeatureEngineOther = 1U << 17U,
        FeatureHwOpenVino = 1U << 18U,
        FeatureGenericEnd = FeatureEngineOther,
        FeatureSttStart = 1U << 20U,
        FeatureSttIntermediateResults = FeatureSttStart,
        FeatureSttPunctuation = 1U << 21U,
        FeatureSttEnd = FeatureSttPunctuation,
        FeatureTtsStart = 1U << 30U,
        FeatureTtsVoiceCloning = FeatureTtsStart,
        FeatureTtsEnd = FeatureTtsVoiceCloning,
        FeatureLast = FeatureTtsEnd,
        FeatureAllSttEngines = FeatureEngineSttDs | FeatureEngineSttVosk |
                               FeatureEngineSttWhisper |
                               FeatureEngineSttFasterWhisper |
                               FeatureEngineSttApril,
        FeatureAllTtsEngines = FeatureEngineTtsEspeak | FeatureEngineTtsPiper |
                               FeatureEngineTtsRhvoice | FeatureEngineTtsCoqui |
                               FeatureEngineTtsMimic3 |
                               FeatureEngineTtsWhisperSpeech,
        FeatureAll = FeatureFastProcessing | FeatureMediumProcessing |
                     FeatureSlowProcessing | FeatureQualityHigh |
                     FeatureQualityMedium | FeatureQualityLow |
                     FeatureAllSttEngines | FeatureAllTtsEngines |
                     FeatureSttIntermediateResults | FeatureSttPunctuation |
                     FeatureTtsVoiceCloning,
        FeatureDefault = FeatureFastProcessing | FeatureMediumProcessing |
                         FeatureSlowProcessing | FeatureQualityHigh |
                         FeatureQualityMedium | FeatureQualityLow |
                         FeatureAllSttEngines | FeatureAllTtsEngines,
        FeatureAdditional = FeatureSttIntermediateResults |
                            FeatureSttPunctuation | FeatureTtsVoiceCloning

    };
    Q_ENUM(ModelFeatureFilterFlags)
    friend QDebug operator<<(QDebug d, ModelFeatureFilterFlags flags);

    explicit ModelsListModel(QObject *parent = nullptr);
    ~ModelsListModel() override;
    Q_INVOKABLE void addRoleFilterFlag(ModelRoleFilterFlags flag);
    Q_INVOKABLE void removeRoleFilterFlag(ModelRoleFilterFlags flag);
    Q_INVOKABLE void resetRoleFilterFlags();
    Q_INVOKABLE void addFeatureFilterFlag(ModelFeatureFilterFlags flag);
    Q_INVOKABLE void removeFeatureFilterFlag(ModelFeatureFilterFlags flag);
    Q_INVOKABLE void resetFeatureFilterFlags();

   signals:
    void itemChanged(int idx);
    void downloadingChanged();
    void langChanged();
    void roleFilterFlagsChanged();
    void featureFilterFlagsChanged();
    void disabledFeatureFilterFlagsChanged();
    void defaultFiltersChanged();

   private:
    int m_changedItem = -1;
    bool m_downloading = false;
    QString m_lang;
    unsigned int m_roleFilterFlags = ModelRoleFilterFlags::RoleDefault;
    unsigned int m_featureFilterFlags = ModelFeatureFilterFlags::FeatureDefault;
    unsigned int m_disabledFeatureFilterFlags =
        ModelFeatureFilterFlags::FeatureNone;

    QList<ListItem *> makeItems() override;
    static ListItem *makeItem(const models_manager::model_t &model);
    size_t firstChangedItemIdx(const QList<ListItem *> &oldItems,
                               const QList<ListItem *> &newItems) override;
    void updateItem(ListItem *oldItem, const ListItem *newItem) override;
    inline bool downloading() const { return m_downloading; }
    inline QString lang() const { return m_lang; }
    inline auto roleFilterFlags() const { return m_roleFilterFlags; }
    inline auto featureFilterFlags() const { return m_featureFilterFlags; }
    inline auto disabledFeatureFilterFlags() const {
        return m_disabledFeatureFilterFlags;
    }
    void setLang(const QString &lang);
    void setRoleFilterFlags(unsigned roleFilterFlags);
    void setFeatureFilterFlags(unsigned int featureFilterFlags);
    void updateDownloading(const std::vector<models_manager::model_t> &models);
    bool roleFilterPass(const models_manager::model_t &model) const;
    bool featureFilterPass(const models_manager::model_t &model) const;
    bool defaultFilters() const;
};

class ModelsListItem : public SelectableItem {
    Q_OBJECT
   public:
    enum Roles {
        NameRole = Qt::DisplayRole,
        IdRole = Qt::UserRole,
        LangIdRole,
        AvailableRole,
        DlMultiRole,
        DlOffRole,
        ScoreRole,
        FeaturesRole,
        DefaultRole,
        DownloadingRole,
        ProgressRole,
        ModelRole,
        LicenseIdRole,
        LicenseNameRole,
        LicenseUrlRole,
        LicenseAccceptRequiredRole,
        DownloadUrlsRole,
        DownloadSizeRole
    };

    struct License {
        QString id;
        QString name;
        QUrl url;
        bool accept_required = false;
    };

    struct DownloadInfo {
        QStringList urls;
        QString size = 0;
    };

    ModelsListItem(QObject *parent = nullptr) : SelectableItem{parent} {}
    ModelsListItem(const QString &id, QString name, QString lang_id,
                   ModelsListModel::ModelRole role, License license,
                   DownloadInfo download_info, bool available = true,
                   bool dl_multi = false, bool dl_off = false,
                   unsigned int features = 0, int score = 2,
                   bool default_for_lang = false, bool downloading = false,
                   double progress = 0.0, QObject *parent = nullptr);
    QVariant data(int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    inline QString id() const override { return m_id; }
    inline QString name() const { return m_name; }
    inline QString lang_id() const { return m_lang_id; }
    inline ModelsListModel::ModelRole modelRole() const { return m_role; }
    inline bool available() const { return m_available; }
    inline bool dl_multi() const { return m_dl_multi; }
    inline bool dl_off() const { return m_dl_off; }
    inline auto features() const { return m_features; }
    inline int score() const { return m_score; }
    inline bool default_for_lang() const { return m_default_for_lang; }
    inline bool downloading() const { return m_downloading; }
    inline double progress() const { return m_progress; }
    inline QString license_id() const { return m_license.id; }
    inline QString license_name() const { return m_license.name; }
    inline QUrl license_url() const { return m_license.url; }
    inline bool license_accept_required() const {
        return m_license.accept_required;
    }
    inline QStringList download_urls() const { return m_download_info.urls; }
    inline QString download_size() const { return m_download_info.size; }
    void update(const ModelsListItem *item);

   private:
    QString m_id;
    QString m_name;
    QString m_lang_id;
    ModelsListModel::ModelRole m_role = ModelsListModel::ModelRole::Stt;
    License m_license;
    DownloadInfo m_download_info;
    bool m_available = false;
    bool m_dl_multi = false;
    bool m_dl_off = false;
    unsigned int m_features = 0;
    int m_score = 2;
    bool m_default_for_lang = false;
    bool m_downloading = false;
    double m_progress = 0.0;
};

#endif  // MODELSLISTMODEL_H
