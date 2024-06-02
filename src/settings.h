/* Copyright (C) 2021-2024 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFont>
#include <QObject>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QUrl>
#ifdef USE_DESKTOP
#include <QQmlApplicationEngine>
#endif

#include "qdebug.h"
#include "singleton.h"

class settings : public QSettings, public singleton<settings> {
    Q_OBJECT

    // app
    Q_PROPERTY(QString note READ note WRITE set_note NOTIFY note_changed)
    Q_PROPERTY(speech_mode_t speech_mode READ speech_mode WRITE set_speech_mode
                   NOTIFY speech_mode_changed)
    Q_PROPERTY(insert_mode_t insert_mode READ insert_mode WRITE set_insert_mode
                   NOTIFY insert_mode_changed)
    Q_PROPERTY(mode_t mode READ mode WRITE set_mode NOTIFY mode_changed)

    Q_PROPERTY(QString audio_file_save_dir READ audio_file_save_dir WRITE
                   set_audio_file_save_dir NOTIFY audio_file_save_dir_changed)
    Q_PROPERTY(
        QUrl audio_file_save_dir_url READ audio_file_save_dir_url WRITE
            set_audio_file_save_dir_url NOTIFY audio_file_save_dir_changed)
    Q_PROPERTY(QString audio_file_save_dir_name READ audio_file_save_dir_name
                   NOTIFY audio_file_save_dir_changed)
    Q_PROPERTY(QString audio_file_save_filename READ audio_file_save_filename
                   NOTIFY audio_file_save_dir_changed)

    Q_PROPERTY(QString video_file_save_dir READ video_file_save_dir WRITE
                   set_video_file_save_dir NOTIFY video_file_save_dir_changed)
    Q_PROPERTY(
        QUrl video_file_save_dir_url READ video_file_save_dir_url WRITE
            set_audio_file_save_dir_url NOTIFY video_file_save_dir_changed)
    Q_PROPERTY(QString video_file_save_dir_name READ video_file_save_dir_name
                   NOTIFY video_file_save_dir_changed)
    Q_PROPERTY(QString video_file_save_filename READ video_file_save_filename
                   NOTIFY video_file_save_dir_changed)

    Q_PROPERTY(QString text_file_save_dir READ text_file_save_dir WRITE
                   set_text_file_save_dir NOTIFY text_file_save_dir_changed)
    Q_PROPERTY(QUrl text_file_save_dir_url READ text_file_save_dir_url WRITE
                   set_text_file_save_dir_url NOTIFY text_file_save_dir_changed)
    Q_PROPERTY(QString text_file_save_dir_name READ text_file_save_dir_name
                   NOTIFY text_file_save_dir_changed)
    Q_PROPERTY(QString text_file_save_filename READ text_file_save_filename
                   NOTIFY text_file_save_dir_changed)

    Q_PROPERTY(QString file_open_dir READ file_open_dir WRITE set_file_open_dir
                   NOTIFY file_open_dir_changed)
    Q_PROPERTY(QUrl file_open_dir_url READ file_open_dir_url WRITE
                   set_file_open_dir_url NOTIFY file_open_dir_changed)
    Q_PROPERTY(QString file_open_dir_name READ file_open_dir_name NOTIFY
                   file_open_dir_changed)
    Q_PROPERTY(QString prev_app_ver READ prev_app_ver WRITE set_prev_app_ver
                   NOTIFY prev_app_ver_changed)
    Q_PROPERTY(bool translator_mode READ translator_mode WRITE
                   set_translator_mode NOTIFY translator_mode_changed)
    Q_PROPERTY(
        bool translate_when_typing READ translate_when_typing WRITE
            set_translate_when_typing NOTIFY translate_when_typing_changed)
    Q_PROPERTY(text_format_t mnt_text_format READ mnt_text_format WRITE
                   set_mnt_text_format NOTIFY mnt_text_format_changed)
    Q_PROPERTY(text_format_t stt_tts_text_format READ stt_tts_text_format WRITE
                   set_stt_tts_text_format NOTIFY stt_tts_text_format_changed)
    Q_PROPERTY(bool hint_translator READ hint_translator WRITE
                   set_hint_translator NOTIFY hint_translator_changed)
    Q_PROPERTY(bool hint_addons READ hint_addons WRITE set_hint_addons NOTIFY
                   hint_addons_changed)
    Q_PROPERTY(int qt_style_idx READ qt_style_idx WRITE set_qt_style_idx NOTIFY
                   qt_style_changed)
    Q_PROPERTY(QString qt_style_name READ qt_style_name WRITE set_qt_style_name
                   NOTIFY qt_style_changed)
    Q_PROPERTY(bool qt_style_auto READ qt_style_auto WRITE set_qt_style_auto
                   NOTIFY qt_style_changed)
    Q_PROPERTY(bool restart_required READ restart_required NOTIFY
                   restart_required_changed)
    Q_PROPERTY(unsigned int speech_speed READ speech_speed WRITE
                   set_speech_speed NOTIFY speech_speed_changed)
    Q_PROPERTY(QFont notepad_font READ notepad_font WRITE set_notepad_font
                   NOTIFY notepad_font_changed)
    Q_PROPERTY(text_file_format_t text_file_format READ text_file_format WRITE
                   set_text_file_format NOTIFY text_file_format_changed)
    Q_PROPERTY(video_file_format_t video_file_format READ video_file_format
                   WRITE set_video_file_format NOTIFY video_file_format_changed)
    Q_PROPERTY(audio_format_t audio_format READ audio_format WRITE
                   set_audio_format NOTIFY audio_format_changed)
    Q_PROPERTY(QString audio_format_str READ audio_format_str NOTIFY
                   audio_format_changed)
    Q_PROPERTY(audio_quality_t audio_quality READ audio_quality WRITE
                   set_audio_quality NOTIFY audio_quality_changed)
    Q_PROPERTY(QString mtag_album_name READ mtag_album_name WRITE
                   set_mtag_album_name NOTIFY mtag_album_name_changed)
    Q_PROPERTY(QString mtag_artist_name READ mtag_artist_name WRITE
                   set_mtag_artist_name NOTIFY mtag_artist_name_changed)
    Q_PROPERTY(bool mtag READ mtag WRITE set_mtag NOTIFY mtag_changed)
    Q_PROPERTY(bool hotkeys_enabled READ hotkeys_enabled WRITE
                   set_hotkeys_enabled NOTIFY hotkeys_enabled_changed)
    Q_PROPERTY(QString hotkey_start_listening READ hotkey_start_listening WRITE
                   set_hotkey_start_listening NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_start_listening_active_window READ
            hotkey_start_listening_active_window WRITE
                set_hotkey_start_listening_active_window NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_start_listening_clipboard READ
            hotkey_start_listening_clipboard WRITE
                set_hotkey_start_listening_clipboard NOTIFY hotkeys_changed)
    Q_PROPERTY(QString hotkey_stop_listening READ hotkey_stop_listening WRITE
                   set_hotkey_stop_listening NOTIFY hotkeys_changed)
    Q_PROPERTY(QString hotkey_start_reading READ hotkey_start_reading WRITE
                   set_hotkey_start_reading NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_start_reading_clipboard READ
            hotkey_start_reading_clipboard WRITE
                set_hotkey_start_reading_clipboard NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_pause_resume_reading READ hotkey_pause_resume_reading
            WRITE set_hotkey_pause_resume_reading NOTIFY hotkeys_changed)
    Q_PROPERTY(QString hotkey_cancel READ hotkey_cancel WRITE set_hotkey_cancel
                   NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_switch_to_next_stt_model READ
            hotkey_switch_to_next_stt_model WRITE
                set_hotkey_switch_to_next_stt_model NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_switch_to_next_tts_model READ
            hotkey_switch_to_next_tts_model WRITE
                set_hotkey_switch_to_next_tts_model NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_switch_to_prev_stt_model READ
            hotkey_switch_to_prev_stt_model WRITE
                set_hotkey_switch_to_prev_stt_model NOTIFY hotkeys_changed)
    Q_PROPERTY(
        QString hotkey_switch_to_prev_tts_model READ
            hotkey_switch_to_prev_tts_model WRITE
                set_hotkey_switch_to_prev_tts_model NOTIFY hotkeys_changed)
    Q_PROPERTY(
        bool use_toggle_for_hotkey READ use_toggle_for_hotkey WRITE
            set_use_toggle_for_hotkey NOTIFY use_toggle_for_hotkey_changed)
    Q_PROPERTY(
        desktop_notification_policy_t desktop_notification_policy READ
            desktop_notification_policy WRITE set_desktop_notification_policy
                NOTIFY desktop_notification_policy_changed)
    Q_PROPERTY(
        bool desktop_notification_details READ desktop_notification_details
            WRITE set_desktop_notification_details NOTIFY
                desktop_notification_details_changed)
    Q_PROPERTY(bool actions_api_enabled READ actions_api_enabled WRITE
                   set_actions_api_enabled NOTIFY actions_api_enabled_changed)
    Q_PROPERTY(bool diacritizer_enabled READ diacritizer_enabled WRITE
                   set_diacritizer_enabled NOTIFY diacritizer_enabled_changed)
    Q_PROPERTY(bool gpu_scan_cuda READ gpu_scan_cuda WRITE set_gpu_scan_cuda
                   NOTIFY gpu_scan_cuda_changed)
    Q_PROPERTY(bool gpu_scan_hip READ gpu_scan_hip WRITE set_gpu_scan_hip NOTIFY
                   gpu_scan_hip_changed)
    Q_PROPERTY(bool gpu_scan_opencl READ gpu_scan_opencl WRITE
                   set_gpu_scan_opencl NOTIFY gpu_scan_opencl_changed)
    Q_PROPERTY(
        bool gpu_scan_opencl_legacy READ gpu_scan_opencl_legacy WRITE
            set_gpu_scan_opencl_legacy NOTIFY gpu_scan_opencl_legacy_changed)
    Q_PROPERTY(QString active_tts_ref_voice READ active_tts_ref_voice WRITE
                   set_active_tts_ref_voice NOTIFY active_tts_ref_voice_changed)
    Q_PROPERTY(QString active_tts_for_in_mnt_ref_voice READ
                   active_tts_for_in_mnt_ref_voice WRITE
                       set_active_tts_for_in_mnt_ref_voice NOTIFY
                           active_tts_for_in_mnt_ref_voice_changed)
    Q_PROPERTY(QString active_tts_for_out_mnt_ref_voice READ
                   active_tts_for_out_mnt_ref_voice WRITE
                       set_active_tts_for_out_mnt_ref_voice NOTIFY
                           active_tts_for_out_mnt_ref_voice_changed)
    Q_PROPERTY(bool mnt_clean_text READ mnt_clean_text WRITE set_mnt_clean_text
                   NOTIFY mnt_clean_text_changed)
    Q_PROPERTY(bool whisper_translate READ whisper_translate WRITE
                   set_whisper_translate NOTIFY whisper_translate_changed)
    Q_PROPERTY(
        bool use_tray READ use_tray WRITE set_use_tray NOTIFY use_tray_changed)
    Q_PROPERTY(bool start_in_tray READ start_in_tray WRITE set_start_in_tray
                   NOTIFY start_in_tray_changed)
    Q_PROPERTY(bool clean_ref_voice READ clean_ref_voice WRITE
                   set_clean_ref_voice NOTIFY clean_ref_voice_changed)
    Q_PROPERTY(
        unsigned int addon_flags READ addon_flags NOTIFY addon_flags_changed)
    Q_PROPERTY(unsigned int sub_min_segment_dur READ sub_min_segment_dur WRITE
                   set_sub_min_segment_dur NOTIFY sub_config_changed)
    Q_PROPERTY(unsigned int sub_min_line_length READ sub_min_line_length WRITE
                   set_sub_min_line_length NOTIFY sub_config_changed)
    Q_PROPERTY(unsigned int sub_max_line_length READ sub_max_line_length WRITE
                   set_sub_max_line_length NOTIFY sub_config_changed)
    Q_PROPERTY(bool sub_break_lines READ sub_break_lines WRITE
                   set_sub_break_lines NOTIFY sub_config_changed)
    Q_PROPERTY(bool keep_last_note READ keep_last_note WRITE set_keep_last_note
                   NOTIFY keep_last_note_changed)
    Q_PROPERTY(
        default_export_tab_t default_export_tab READ default_export_tab WRITE
            set_default_export_tab NOTIFY default_export_tab_changed)
    Q_PROPERTY(bool show_repair_text READ show_repair_text WRITE
                   set_show_repair_text NOTIFY show_repair_text_changed)
    Q_PROPERTY(QString x11_compose_file READ x11_compose_file WRITE
                   set_x11_compose_file NOTIFY x11_compose_file_changed)
    Q_PROPERTY(bool tts_split_into_sentences READ tts_split_into_sentences WRITE
                   set_tts_split_into_sentences NOTIFY
                       tts_split_into_sentences_changed)
    Q_PROPERTY(
        bool tts_use_engine_speed_control READ tts_use_engine_speed_control
            WRITE set_tts_use_engine_speed_control NOTIFY
                tts_use_engine_speed_control_changed)
    Q_PROPERTY(
        unsigned int error_flags READ error_flags NOTIFY error_flags_changed)

    // service
    Q_PROPERTY(QString models_dir READ models_dir WRITE set_models_dir NOTIFY
                   models_dir_changed)
    Q_PROPERTY(QUrl models_dir_url READ models_dir_url WRITE set_models_dir_url
                   NOTIFY models_dir_changed)
    Q_PROPERTY(
        QString models_dir_name READ models_dir_name NOTIFY models_dir_changed)
    Q_PROPERTY(QString cache_dir READ cache_dir WRITE set_cache_dir NOTIFY
                   cache_dir_changed)
    Q_PROPERTY(QUrl cache_dir_url READ cache_dir_url WRITE set_cache_dir_url
                   NOTIFY cache_dir_changed)
    Q_PROPERTY(bool restore_punctuation READ restore_punctuation WRITE
                   set_restore_punctuation NOTIFY restore_punctuation_changed)
    Q_PROPERTY(QString default_stt_model READ default_stt_model WRITE
                   set_default_stt_model NOTIFY default_stt_model_changed)
    Q_PROPERTY(QString default_tts_model READ default_tts_model WRITE
                   set_default_tts_model NOTIFY default_tts_model_changed)
    Q_PROPERTY(QString default_mnt_lang READ default_mnt_lang WRITE
                   set_default_mnt_lang NOTIFY default_mnt_lang_changed)
    Q_PROPERTY(QString default_mnt_out_lang READ default_mnt_out_lang WRITE
                   set_default_mnt_out_lang NOTIFY default_mnt_out_lang_changed)    
    Q_PROPERTY(QString audio_input_device READ audio_input_device WRITE
                   set_audio_input_device NOTIFY audio_input_device_changed)
    Q_PROPERTY(bool py_feature_scan READ py_feature_scan WRITE
                   set_py_feature_scan NOTIFY py_feature_scan_changed)
    Q_PROPERTY(
        cache_audio_format_t cache_audio_format READ cache_audio_format WRITE
            set_cache_audio_format NOTIFY cache_audio_format_changed)
    Q_PROPERTY(cache_policy_t cache_policy READ cache_policy WRITE
                   set_cache_policy NOTIFY cache_policy_changed)
    Q_PROPERTY(int num_threads READ num_threads WRITE set_num_threads NOTIFY
                   num_threads_changed)
    Q_PROPERTY(
        QString py_path READ py_path WRITE set_py_path NOTIFY py_path_changed)
    Q_PROPERTY(bool gpu_override_version READ gpu_override_version WRITE
                   set_gpu_override_version NOTIFY gpu_override_version_changed)
    Q_PROPERTY(
        QString gpu_overrided_version READ gpu_overrided_version WRITE
            set_gpu_overrided_version NOTIFY gpu_overrided_version_changed)
    Q_PROPERTY(
        file_import_action_t file_import_action READ file_import_action WRITE
            set_file_import_action NOTIFY file_import_action_changed)
    Q_PROPERTY(
        tts_subtitles_sync_mode_t tts_subtitles_sync READ tts_subtitles_sync
            WRITE set_tts_subtitles_sync NOTIFY tts_subtitles_sync_changed)
    Q_PROPERTY(int mix_volume_change READ mix_volume_change WRITE
                   set_mix_volume_change NOTIFY mix_volume_change_changed)

    // engine options

#define ENGINE_OPTS(name)                         \
    Q_PROPERTY(                                   \
        bool name##_short_audio_optimization READ \
            name##_short_audio_optimization WRITE \
                set_##name##_short_audio_optimization NOTIFY name##_changed)
    ENGINE_OPTS(whispercpp)
#undef ENGINE_OPTS

#define ENGINE_OPTS(name)                                                  \
    Q_PROPERTY(bool name##_gpu_flash_attn READ name##_gpu_flash_attn WRITE \
                   set_##name##_gpu_flash_attn NOTIFY name##_changed)      \
    Q_PROPERTY(int name##_cpu_threads READ name##_cpu_threads WRITE        \
                   set_##name##_cpu_threads NOTIFY name##_changed)         \
    Q_PROPERTY(int name##_beam_search READ name##_beam_search WRITE        \
                   set_##name##_beam_search NOTIFY name##_changed)

    ENGINE_OPTS(whispercpp)
    ENGINE_OPTS(fasterwhisper)
#undef ENGINE_OPTS

    // whisper.cpp
    Q_PROPERTY(
        bool whispercpp_gpu_flash_attn READ whispercpp_gpu_flash_attn WRITE
            set_whispercpp_gpu_flash_attn NOTIFY whispercpp_changed)
    Q_PROPERTY(int whispercpp_cpu_threads READ whispercpp_cpu_threads WRITE
                   set_whispercpp_cpu_threads NOTIFY whispercpp_changed)
    Q_PROPERTY(int whispercpp_beam_search READ whispercpp_beam_search WRITE
                   set_whispercpp_beam_search NOTIFY whispercpp_changed)

    // faster-whisper

#define ENGINE_OPTS(name)                                                    \
    Q_PROPERTY(bool name##_use_gpu READ name##_use_gpu WRITE                 \
                   set_##name##_use_gpu NOTIFY name##_use_gpu_changed)       \
    Q_PROPERTY(QStringList name##_gpu_devices READ name##_gpu_devices NOTIFY \
                   gpu_devices_changed)                                      \
    Q_PROPERTY(                                                              \
        int name##_gpu_device_idx READ name##_gpu_device_idx WRITE           \
            set_##name##_gpu_device_idx NOTIFY name##_gpu_device_changed)    \
    Q_PROPERTY(QString name##_gpu_device READ name##_gpu_device WRITE        \
                   set_##name##_gpu_device NOTIFY name##_gpu_device_changed) \
    Q_PROPERTY(QString name##_auto_gpu_device READ                           \
                   name##_auto_gpu_device NOTIFY name##_gpu_device_changed)

    ENGINE_OPTS(whispercpp)
    ENGINE_OPTS(fasterwhisper)
    ENGINE_OPTS(coqui)
    ENGINE_OPTS(whisperspeech)
#undef ENGINE_OPTS

   public:
    enum class mode_t { Stt = 0, Tts = 1 };
    Q_ENUM(mode_t)
    friend QDebug operator<<(QDebug d, mode_t mode);

    enum class launch_mode_t { app_stanalone, app, service };
    friend QDebug operator<<(QDebug d, launch_mode_t launch_mode);

    enum class speech_mode_t {
        SpeechAutomatic = 0,
        SpeechManual = 1,
        SpeechSingleSentence = 2
    };
    Q_ENUM(speech_mode_t)
    friend QDebug operator<<(QDebug d, speech_mode_t speech_mode);

    enum class insert_mode_t {
        InsertNewLine = 0,
        InsertInLine = 1,
        InsertAfterEmptyLine = 2
    };
    Q_ENUM(insert_mode_t)

    enum class tts_subtitles_sync_mode_t {
        TtsSubtitleSyncOff = 0,
        TtsSubtitleSyncOnDontFit = 1,
        TtsSubtitleSyncOnAlwaysFit = 2,
        TtsSubtitleSyncOnFitOnlyIfLonger = 3
    };
    Q_ENUM(tts_subtitles_sync_mode_t)

    enum class file_import_action_t {
        FileImportActionAsk = 0,
        FileImportActionAppend = 1,
        FileImportActionReplace = 2
    };
    Q_ENUM(file_import_action_t)

    enum class audio_format_t {
        AudioFormatAuto = 0,
        AudioFormatWav = 1,
        AudioFormatMp3 = 2,
        AudioFormatOggVorbis = 3,
        AudioFormatOggOpus = 4
    };
    Q_ENUM(audio_format_t)

    enum class text_file_format_t {
        TextFileFormatAuto = 0,
        TextFileFormatRaw = 1,
        TextFileFormatSrt = 2,
        TextFileFormatAss = 3,
        TextFileFormatVtt = 4
    };
    Q_ENUM(text_file_format_t)

    enum class video_file_format_t {
        VideoFileFormatAuto = 0,
        VideoFileFormatMp4 = 1,
        VideoFileFormatMkv = 2,
        VideoFileFormatWebm = 3
    };
    Q_ENUM(video_file_format_t)

    enum class cache_audio_format_t {
        CacheAudioFormatWav = 0,
        CacheAudioFormatMp3 = 1,
        CacheAudioFormatOggVorbis = 2,
        CacheAudioFormatOggOpus = 3,
        CacheAudioFormatFlac = 4
    };
    Q_ENUM(cache_audio_format_t)

    enum class cache_policy_t { CacheRemove = 0, CacheNoRemove = 1 };
    Q_ENUM(cache_policy_t)

    enum class audio_quality_t {
        AudioQualityVbrHigh = 10,
        AudioQualityVbrMedium = 11,
        AudioQualityVbrLow = 12,
    };
    Q_ENUM(audio_quality_t)

    enum class desktop_notification_policy_t {
        DesktopNotificationNever = 0,
        DesktopNotificationWhenInacvtive = 1,
        DesktopNotificationAlways = 2
    };
    Q_ENUM(desktop_notification_policy_t)

    enum class text_format_t {
        TextFormatRaw = 0,
        TextFormatHtml = 1,
        TextFormatMarkdown = 2,
        TextFormatSubRip = 3
    };
    Q_ENUM(text_format_t)

    enum class default_export_tab_t {
        DefaultExportTabText = 0,
        DefaultExportTabAudio = 1
    };
    Q_ENUM(default_export_tab_t)

    enum error_flags_t : unsigned int {
        ErrorNoError = 0U,
        ErrorCudaUnknown = 1U << 0U,
        ErrorMoreThanOneGpuAddons = 1U << 1U
    };
    Q_ENUM(error_flags_t)

    enum addon_flags_t : unsigned int {
        AddonNone = 0U,
        AddonNvidia = 1U << 0U,
        AddonAmd = 1U << 1U
    };
    Q_ENUM(addon_flags_t)

    enum gpu_feature_flags_t : unsigned int {
        gpu_feature_none = 0U,
        gpu_feature_stt_whispercpp_cuda = 1U << 0U,
        gpu_feature_stt_whispercpp_hip = 1U << 1U,
        gpu_feature_stt_whispercpp_opencl = 1U << 2U,
        gpu_feature_stt_fasterwhisper_cuda = 1U << 3U,
        gpu_feature_tts_coqui_cuda = 1U << 4U,
        gpu_feature_tts_coqui_hip = 1U << 5U,
        gpu_feature_tts_whisperspeech_cuda = 1U << 6U,
        gpu_feature_tts_whisperspeech_hip = 1U << 7U,
        gpu_feature_all =
            gpu_feature_stt_whispercpp_cuda | gpu_feature_stt_whispercpp_hip |
            gpu_feature_stt_whispercpp_opencl |
            gpu_feature_stt_fasterwhisper_cuda | gpu_feature_tts_coqui_cuda |
            gpu_feature_tts_coqui_hip | gpu_feature_tts_whisperspeech_cuda |
            gpu_feature_tts_whisperspeech_hip
    };
    friend QDebug operator<<(QDebug d, gpu_feature_flags_t gpu_feature_flags);

    settings();

    launch_mode_t launch_mode() const;
    void set_launch_mode(launch_mode_t launch_mode);
    QString module_checksum(const QString &name) const;
    void set_module_checksum(const QString &name, const QString &value);
    void scan_gpu_devices(unsigned int gpu_feature_flags);
    void disable_gpu_scan();
    void disable_py_scan();
#ifdef USE_DESKTOP
    void update_qt_style(QQmlApplicationEngine *engine);
#endif
    // app
    QString note() const;
    void set_note(const QString &value);
    speech_mode_t speech_mode() const;
    void set_speech_mode(speech_mode_t value);
    unsigned int speech_speed() const;
    void set_speech_speed(unsigned int value);
    insert_mode_t insert_mode() const;
    void set_insert_mode(insert_mode_t value);
    mode_t mode() const;
    void set_mode(mode_t value);

    QString audio_file_save_dir() const;
    void set_audio_file_save_dir(const QString &value);
    QUrl audio_file_save_dir_url() const;
    void set_audio_file_save_dir_url(const QUrl &value);
    QString audio_file_save_dir_name() const;
    QString audio_file_save_filename() const;
    Q_INVOKABLE void update_audio_file_save_path(const QString &path);
    QString video_file_save_dir() const;
    void set_video_file_save_dir(const QString &value);
    QUrl video_file_save_dir_url() const;
    void set_video_file_save_dir_url(const QUrl &value);
    QString video_file_save_dir_name() const;
    QString video_file_save_filename() const;
    Q_INVOKABLE void update_video_file_save_path(const QString &path);
    QString text_file_save_dir() const;
    void set_text_file_save_dir(const QString &value);
    QUrl text_file_save_dir_url() const;
    void set_text_file_save_dir_url(const QUrl &value);
    QString text_file_save_dir_name() const;
    QString text_file_save_filename() const;
    Q_INVOKABLE void update_text_file_save_path(const QString &path);
    QString file_open_dir() const;
    void set_file_open_dir(const QString &value);
    QUrl file_open_dir_url() const;
    void set_file_open_dir_url(const QUrl &value);
    QString file_open_dir_name() const;
    QString file_audio_open_dir() const;
    QString prev_app_ver() const;
    void set_prev_app_ver(const QString &value);
    bool translator_mode() const;
    void set_translator_mode(bool value);
    bool translate_when_typing() const;
    void set_translate_when_typing(bool value);
    void set_mnt_text_format(text_format_t value);
    text_format_t mnt_text_format() const;
    void set_stt_tts_text_format(text_format_t value);
    text_format_t stt_tts_text_format() const;
    QString default_tts_model_for_mnt_lang(const QString &lang);
    void set_default_tts_model_for_mnt_lang(const QString &lang,
                                            const QString &value);
    bool hint_translator() const;
    void set_hint_translator(bool value);
    bool hint_addons() const;
    void set_hint_addons(bool value);
    int qt_style_idx() const;
    void set_qt_style_idx(int value);
    QString qt_style_name() const;
    void set_qt_style_name(QString value);
    void set_qt_style_auto(bool value);
    bool qt_style_auto() const;
    bool restart_required() const;
    void set_notepad_font(const QFont &value);
    QFont notepad_font() const;
    void set_text_file_format(text_file_format_t value);
    text_file_format_t text_file_format() const;
    void set_video_file_format(video_file_format_t value);
    video_file_format_t video_file_format() const;
    void set_audio_format(audio_format_t value);
    audio_format_t audio_format() const;
    void set_audio_quality(audio_quality_t value);
    audio_quality_t audio_quality() const;
    QString mtag_album_name() const;
    void set_mtag_album_name(const QString &value);
    QString mtag_artist_name() const;
    void set_mtag_artist_name(const QString &value);
    void set_mtag(bool value);
    bool mtag() const;
    QString audio_format_str() const;
    bool hotkeys_enabled() const;
    void set_hotkeys_enabled(bool value);
    QString hotkey_start_listening() const;
    void set_hotkey_start_listening(const QString &value);
    QString hotkey_start_listening_active_window() const;
    void set_hotkey_start_listening_active_window(const QString &value);
    QString hotkey_start_listening_clipboard() const;
    void set_hotkey_start_listening_clipboard(const QString &value);
    QString hotkey_stop_listening() const;
    void set_hotkey_stop_listening(const QString &value);
    QString hotkey_start_reading() const;
    void set_hotkey_start_reading(const QString &value);
    QString hotkey_start_reading_clipboard() const;
    void set_hotkey_start_reading_clipboard(const QString &value);
    QString hotkey_pause_resume_reading() const;
    void set_hotkey_pause_resume_reading(const QString &value);
    QString hotkey_cancel() const;
    void set_hotkey_cancel(const QString &value);
    QString hotkey_switch_to_next_stt_model() const;
    void set_hotkey_switch_to_next_stt_model(const QString &value);
    QString hotkey_switch_to_next_tts_model() const;
    void set_hotkey_switch_to_next_tts_model(const QString &value);
    QString hotkey_switch_to_prev_stt_model() const;
    void set_hotkey_switch_to_prev_stt_model(const QString &value);
    QString hotkey_switch_to_prev_tts_model() const;
    void set_hotkey_switch_to_prev_tts_model(const QString &value);
    void set_use_toggle_for_hotkey(bool value);
    bool use_toggle_for_hotkey() const;
    desktop_notification_policy_t desktop_notification_policy() const;
    void set_desktop_notification_policy(desktop_notification_policy_t value);
    bool desktop_notification_details() const;
    void set_desktop_notification_details(bool value);
    bool actions_api_enabled() const;
    void set_actions_api_enabled(bool value);
    bool diacritizer_enabled() const;
    void set_diacritizer_enabled(bool value);
    bool gpu_scan_cuda() const;
    void set_gpu_scan_cuda(bool value);
    bool gpu_scan_hip() const;
    void set_gpu_scan_hip(bool value);
    bool gpu_scan_opencl() const;
    void set_gpu_scan_opencl(bool value);
    bool gpu_scan_opencl_legacy() const;
    void set_gpu_scan_opencl_legacy(bool value);
    QString active_tts_ref_voice() const;
    void set_active_tts_ref_voice(const QString &value);
    QString active_tts_for_in_mnt_ref_voice() const;
    void set_active_tts_for_in_mnt_ref_voice(const QString &value);
    QString active_tts_for_out_mnt_ref_voice() const;
    void set_active_tts_for_out_mnt_ref_voice(const QString &value);
    bool mnt_clean_text() const;
    void set_mnt_clean_text(bool value);
    bool whisper_translate() const;
    void set_whisper_translate(bool value);
    bool use_tray() const;
    void set_use_tray(bool value);
    bool start_in_tray() const;
    void set_start_in_tray(bool value);
    bool show_repair_text() const;
    void set_show_repair_text(bool value);
    bool tts_split_into_sentences() const;
    void set_tts_split_into_sentences(bool value);
    bool tts_use_engine_speed_control() const;
    void set_tts_use_engine_speed_control(bool value);
    bool clean_ref_voice() const;
    void set_clean_ref_voice(bool value);
    unsigned int addon_flags() const;
    unsigned int error_flags() const;
    void set_sub_min_segment_dur(unsigned int value);
    unsigned int sub_min_segment_dur() const;
    void set_sub_min_line_length(unsigned int value);
    unsigned int sub_min_line_length() const;
    void set_sub_max_line_length(unsigned int value);
    unsigned int sub_max_line_length() const;
    bool sub_break_lines() const;
    void set_sub_break_lines(bool value);
    bool keep_last_note() const;
    void set_keep_last_note(bool value);
    file_import_action_t file_import_action() const;
    void set_file_import_action(file_import_action_t value);
    default_export_tab_t default_export_tab() const;
    void set_default_export_tab(default_export_tab_t value);
    int mix_volume_change() const;
    void set_mix_volume_change(int value);
    QString x11_compose_file() const;
    void set_x11_compose_file(const QString &value);

    Q_INVOKABLE QUrl app_icon() const;
    Q_INVOKABLE bool py_supported() const;
    Q_INVOKABLE bool gpu_supported() const;
    Q_INVOKABLE bool is_wayland() const;
    Q_INVOKABLE bool is_xcb() const;
    Q_INVOKABLE bool is_flatpak() const;
    Q_INVOKABLE QStringList qt_styles() const;
    Q_INVOKABLE bool file_exists(const QString &file_path) const;
    Q_INVOKABLE QString
    add_ext_to_audio_filename(const QString &filename) const;
    Q_INVOKABLE QString
    add_ext_to_audio_file_path(const QString &file_path) const;
    Q_INVOKABLE QString
    base_name_from_file_path(const QString &file_path) const;
    Q_INVOKABLE QString file_path_from_url(const QUrl &file_url) const;
    Q_INVOKABLE QString dir_of_file(const QString &file_path) const;
    Q_INVOKABLE audio_format_t
    filename_to_audio_format(const QString &filename) const;
    static QString audio_format_str_from_filename(
        settings::audio_format_t audio_format, const QString &filename);
    static QString audio_ext_from_filename(
        settings::audio_format_t audio_format, const QString &filename);
    static audio_format_t audio_format_from_filename(const QString &filename);
    static audio_format_t filename_to_audio_format_static(
        const QString &filename);
    Q_INVOKABLE QString
    add_ext_to_text_file_filename(const QString &filename) const;
    Q_INVOKABLE QString
    add_ext_to_text_file_path(const QString &file_path) const;
    Q_INVOKABLE text_file_format_t
    filename_to_text_file_format(const QString &filename) const;
    static QString text_file_ext_from_filename(const QString &filename);
    static text_file_format_t text_file_format_from_filename(
        const QString &filename);
    static text_file_format_t filename_to_text_file_format_static(
        const QString &filename);
    Q_INVOKABLE QString
    add_ext_to_video_file_filename(const QString &filename) const;
    Q_INVOKABLE QString
    add_ext_to_video_file_path(const QString &file_path) const;
    Q_INVOKABLE video_file_format_t
    filename_to_video_file_format(const QString &filename) const;
    static QString video_file_ext_from_filename(const QString &filename);
    static video_file_format_t video_file_format_from_filename(
        const QString &filename);
    static video_file_format_t filename_to_video_file_format_static(
        const QString &filename);
    Q_INVOKABLE bool is_debug() const;
    Q_INVOKABLE bool is_native_style() const;

    // service
    QString models_dir() const;
    void set_models_dir(const QString &value);
    QUrl models_dir_url() const;
    void set_models_dir_url(const QUrl &value);
    QString models_dir_name() const;
    QString cache_dir() const;
    void set_cache_dir(const QString &value);
    QUrl cache_dir_url() const;
    void set_cache_dir_url(const QUrl &value);
    bool restore_punctuation() const;
    void set_restore_punctuation(bool value);
    QStringList enabled_models();
    void set_enabled_models(const QStringList &value);
    QString audio_input_device() const;
    void set_audio_input_device(QString value);
    bool py_feature_scan() const;
    void set_py_feature_scan(bool value);
    int num_threads() const;
    void set_num_threads(int value);
    QString py_path() const;
    void set_py_path(const QString &value);
    void set_cache_audio_format(cache_audio_format_t value);
    cache_audio_format_t cache_audio_format() const;
    void set_cache_policy(cache_policy_t value);
    cache_policy_t cache_policy() const;
    QString default_stt_model() const;
    void set_default_stt_model(const QString &value);
    QString default_stt_model_for_lang(const QString &lang);
    void set_default_stt_model_for_lang(const QString &lang,
                                        const QString &value);
    QString default_tts_model() const;
    void set_default_tts_model(const QString &value);
    QString default_tts_model_for_lang(const QString &lang);
    void set_default_tts_model_for_lang(const QString &lang,
                                        const QString &value);
    QString default_mnt_lang() const;
    void set_default_mnt_lang(const QString &value);
    QString default_mnt_out_lang() const;
    void set_default_mnt_out_lang(const QString &value);
    bool gpu_override_version() const;
    void set_gpu_override_version(bool value);
    QString gpu_overrided_version();
    void set_gpu_overrided_version(QString new_value);
    tts_subtitles_sync_mode_t tts_subtitles_sync() const;
    void set_tts_subtitles_sync(tts_subtitles_sync_mode_t value);

#define ENGINE_OPTS(name)                         \
    bool name##_short_audio_optimization() const; \
    void set_##name##_short_audio_optimization(bool value);
    ENGINE_OPTS(whispercpp)
#undef ENGINE_OPTS

#define ENGINE_OPTS(name)                         \
    bool name##_gpu_flash_attn() const;           \
    void set_##name##_gpu_flash_attn(bool value); \
    int name##_cpu_threads() const;               \
    void set_##name##_cpu_threads(int value);     \
    int name##_beam_search() const;               \
    void set_##name##_beam_search(int value);     \
    Q_INVOKABLE void reset_##name##_options();
    ENGINE_OPTS(whispercpp)
    ENGINE_OPTS(fasterwhisper)
#undef ENGINE_OPTS

#define ENGINE_OPTS(name)                             \
    bool name##_use_gpu() const;                      \
    void set_##name##_use_gpu(bool value);            \
    Q_INVOKABLE bool has_##name##_gpu_device() const; \
    QStringList name##_gpu_devices() const;           \
    QString name##_gpu_device() const;                \
    QString name##_auto_gpu_device() const;           \
    void set_##name##_gpu_device(QString value);      \
    int name##_gpu_device_idx() const;                \
    void set_##name##_gpu_device_idx(int value);
    ENGINE_OPTS(whispercpp)
    ENGINE_OPTS(fasterwhisper)
    ENGINE_OPTS(coqui)
    ENGINE_OPTS(whisperspeech)
#undef ENGINE_OPTS

   signals:
    // app
    void speech_mode_changed();
    void note_changed();
    void insert_mode_changed();
    void mode_changed();
    void audio_file_save_dir_changed();
    void video_file_save_dir_changed();
    void text_file_save_dir_changed();
    void file_open_dir_changed();
    void file_audio_open_dir_changed();
    void prev_app_ver_changed();
    void translator_mode_changed();
    void translate_when_typing_changed();
    void default_tts_models_for_mnt_changed(const QString &lang);
    void hint_translator_changed();
    void hint_addons_changed();
    void qt_style_changed();
    void restart_required_changed();
    void speech_speed_changed();
    void notepad_font_changed();
    void text_file_format_changed();
    void video_file_format_changed();
    void audio_format_changed();
    void audio_quality_changed();
    void mtag_album_name_changed();
    void mtag_artist_name_changed();
    void mtag_changed();
    void hotkeys_enabled_changed();
    void hotkeys_changed();
    void desktop_notification_policy_changed();
    void desktop_notification_details_changed();
    void actions_api_enabled_changed();
    void diacritizer_enabled_changed();
    void gpu_scan_cuda_changed();
    void gpu_scan_hip_changed();
    void gpu_scan_opencl_changed();
    void gpu_scan_opencl_legacy_changed();
    void active_tts_ref_voice_changed();
    void active_tts_for_in_mnt_ref_voice_changed();
    void active_tts_for_out_mnt_ref_voice_changed();
    void mnt_clean_text_changed();
    void whisper_translate_changed();
    void use_tray_changed();
    void start_in_tray_changed();
    void mnt_text_format_changed();
    void stt_tts_text_format_changed();
    void clean_ref_voice_changed();
    void addon_flags_changed();
    void sub_config_changed();
    void keep_last_note_changed();
    void file_import_action_changed();
    void default_export_tab_changed();
    void tts_subtitles_sync_changed();
    void mix_volume_change_changed();
    void show_repair_text_changed();
    void x11_compose_file_changed();
    void tts_split_into_sentences_changed();
    void tts_use_engine_speed_control_changed();
    void use_toggle_for_hotkey_changed();
    void error_flags_changed();

    // service
    void models_dir_changed();
    void cache_dir_changed();
    void restore_punctuation_changed();
    void default_stt_model_changed();
    void default_stt_models_changed(const QString &lang);
    void default_tts_model_changed();
    void default_tts_models_changed(const QString &lang);
    void default_mnt_lang_changed();
    void default_mnt_out_lang_changed();
    void audio_input_device_changed();
    void py_feature_scan_changed();
    void cache_audio_format_changed();
    void cache_policy_changed();
    void num_threads_changed();
    void py_path_changed();
    void gpu_override_version_changed();
    void gpu_overrided_version_changed();
    void gpu_devices_changed();

#define ENGINE_OPTS(name) void name##_changed();
    ENGINE_OPTS(whispercpp)
    ENGINE_OPTS(fasterwhisper)
#undef ENGINE_OPTS

#define ENGINE_OPTS(name)             \
    void name##_gpu_device_changed(); \
    void name##_use_gpu_changed();
    ENGINE_OPTS(whispercpp)
    ENGINE_OPTS(fasterwhisper)
    ENGINE_OPTS(coqui)
    ENGINE_OPTS(whisperspeech)
#undef ENGINE_OPTS

   private:
    inline static const QString settings_filename =
        QStringLiteral("settings.conf");
    inline static const QString default_qt_style =
        QStringLiteral("org.kde.desktop");
    inline static const QString default_qt_style_fallback =
        QStringLiteral("org.kde.breeze");
    bool m_restart_required = false;
#define ENGINE_OPTS(name) QStringList m_##name##_gpu_devices;
    ENGINE_OPTS(whispercpp)
    ENGINE_OPTS(fasterwhisper)
    ENGINE_OPTS(coqui)
    ENGINE_OPTS(whisperspeech)
#undef ENGINE_OPTS
    std::vector<QString> m_rocm_gpu_versions;
    unsigned int m_addon_flags = addon_flags_t::AddonNone;
    unsigned int m_error_flags = error_flags_t::ErrorNoError;
    bool m_native_style = false;

    static QString settings_filepath();
    void set_restart_required(bool value);
    void enforce_num_threads() const;
    void add_error_flags(error_flags_t new_flag);
    void update_addon_flags();

    launch_mode_t m_launch_mode = launch_mode_t::app_stanalone;
    QString m_note;
};

#endif  // SETTINGS_H
