/* Copyright (C) 2023 Michal Kosciesza <michal@mkiol.net>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef WHISPER_WRAPPER_H
#define WHISPER_WRAPPER_H

#include <whisper.h>

#include <memory>
#include <string>
#include <vector>

#include "engine_wrapper.hpp"

class whisper_wrapper : public engine_wrapper {
   public:
    whisper_wrapper(config_t config, callbacks_t call_backs);
    ~whisper_wrapper() override;

   private:
    using whisper_buf_t = std::vector<float>;

    inline static const size_t m_speech_max_size = m_sample_rate * 60;  // 60s

    whisper_buf_t m_speech_buf;
    std::unique_ptr<whisper_context, decltype(&whisper_free)> m_whisper_ctx;
    whisper_full_params m_wparams{};
    samples_process_result_t process_buff() override;
    void decode_speech(const whisper_buf_t& buf);
    static void push_buf_to_whisper_buf(
        const std::vector<in_buf_t::buf_t::value_type>& buf,
        whisper_buf_t& whisper_buf);
    bool sentence_timer_timed_out();
    whisper_full_params make_wparams() const;
    void reset_engine() override;
};

#endif  // WHISPER_WRAPPER_H