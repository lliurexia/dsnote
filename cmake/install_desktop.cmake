install(TARGETS ${info_binary_id} RUNTIME DESTINATION bin)

install(FILES "${desktop_dir}/${info_binary_id}.desktop" DESTINATION share/applications)
install(FILES "${desktop_dir}/${info_binary_id}.metainfo.xml" DESTINATION share/metainfo)
install(FILES "${desktop_dir}/${info_binary_id}.svg" DESTINATION share/icons/hicolor/scalable/apps)
install(FILES "${desktop_dir}/icons/16x16/${info_binary_id}.png" DESTINATION share/icons/hicolor/16x16/apps)
install(FILES "${desktop_dir}/icons/32x32/${info_binary_id}.png" DESTINATION share/icons/hicolor/32x32/apps)
install(FILES "${desktop_dir}/icons/48x48/${info_binary_id}.png" DESTINATION share/icons/hicolor/48x48/apps)
install(FILES "${desktop_dir}/icons/64x64/${info_binary_id}.png" DESTINATION share/icons/hicolor/64x64/apps)
install(FILES "${desktop_dir}/icons/96x96/${info_binary_id}.png" DESTINATION share/icons/hicolor/96x96/apps)
install(FILES "${desktop_dir}/icons/128x128/${info_binary_id}.png" DESTINATION share/icons/hicolor/128x128/apps)
install(FILES "${desktop_dir}/icons/256x256/${info_binary_id}.png" DESTINATION share/icons/hicolor/256x256/apps)
install(FILES "${desktop_dir}/icons/512x512/${info_binary_id}.png" DESTINATION share/icons/hicolor/512x512/apps)

configure_file("${desktop_dir}/dbus_app.service.in" "${PROJECT_BINARY_DIR}/dbus_app.service")
if(WITH_FLATPAK)
    install(FILES "${PROJECT_BINARY_DIR}/dbus_app.service" DESTINATION share/dbus-1/services RENAME ${info_dbus_app_service}.service)
else()
    install(FILES "${PROJECT_BINARY_DIR}/dbus_app.service" DESTINATION share/dbus-1/services RENAME ${info_binary_id}.service)
endif()

function(strip_all file)
    install(CODE "execute_process(COMMAND ${CMAKE_STRIP} --strip-all ${file})")
endfunction()

if(BUILD_WHISPERCPP)
    strip_all("${external_lib_dir}/libwhisper-openblas.so")
    strip_all("${external_lib_dir}/libwhisper-fallback.so")
    install(FILES "${external_lib_dir}/libwhisper-openblas.so" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libwhisper-fallback.so" DESTINATION ${lib_install_dir})
    if(arch_x8664)
        if(BUILD_WHISPERCPP_CLBLAST)
            strip_all("${external_lib_dir}/libclblast.so.1.6.1")
            strip_all("${external_lib_dir}/libwhisper-clblast.so")
            install(FILES "${external_lib_dir}/libclblast.so" DESTINATION ${lib_install_dir})
            install(FILES "${external_lib_dir}/libclblast.so.1" DESTINATION ${lib_install_dir})
            install(FILES "${external_lib_dir}/libclblast.so.1.6.1" DESTINATION ${lib_install_dir})
            install(FILES "${external_lib_dir}/libwhisper-clblast.so" DESTINATION ${lib_install_dir})
        endif()
        if(BUILD_WHISPERCPP_CUBLAS)
            strip_all("${external_lib_dir}/libwhisper-cublas.so")
            install(FILES "${external_lib_dir}/libwhisper-cublas.so" DESTINATION ${lib_install_dir})
        endif()
        if(BUILD_WHISPERCPP_HIPBLAS)
            strip_all("${external_lib_dir}/libwhisper-hipblas.so")
            install(FILES "${external_lib_dir}/libwhisper-hipblas.so" DESTINATION ${lib_install_dir})
        endif()
    endif()
endif()

if(DOWNLOAD_LIBSTT)
    strip_all("${external_lib_dir}/libstt.so")
    strip_all("${external_lib_dir}/libkenlm.so")
    strip_all("${external_lib_dir}/libtensorflowlite.so")
    strip_all("${external_lib_dir}/libtflitedelegates.so")
    install(FILES "${external_lib_dir}/libstt.so" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libkenlm.so" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libtensorflowlite.so" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libtflitedelegates.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_OPENBLAS)
    strip_all("${external_lib_dir}/libopenblas.so.0.3")
    install(FILES "${external_lib_dir}/libopenblas.so.0.3" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libopenblas.so.0" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libopenblas.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_PIPER OR BUILD_ESPEAK)
    strip_all("${external_bin_dir}/mbrola")
    strip_all("${external_bin_dir}/espeak-ng")
    install(PROGRAMS "${external_bin_dir}/mbrola" DESTINATION ${bin_install_dir})
    install(PROGRAMS "${external_bin_dir}/espeak" DESTINATION ${bin_install_dir})
    install(PROGRAMS "${external_bin_dir}/espeak-ng" DESTINATION ${bin_install_dir})
    install(DIRECTORY "${external_share_dir}/espeak-ng-data" DESTINATION ${share_install_dir})
endif()
install(FILES "${PROJECT_BINARY_DIR}/espeakdata.tar.xz" DESTINATION ${module_install_dir})

if(BUILD_RHVOICE)
    strip_all("${external_lib_dir}/libRHVoice_core.so.1.2.2")
    strip_all("${external_lib_dir}/libRHVoice.so.1.2.2")
    install(FILES "${external_lib_dir}/libRHVoice_core.so.1.2.2" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libRHVoice_core.so.1" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libRHVoice_core.so" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libRHVoice.so.1.2.2" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libRHVoice.so.1" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libRHVoice.so" DESTINATION ${lib_install_dir})
endif()
if(BUILD_RHVOICE_MODULE)
    install(FILES "${PROJECT_BINARY_DIR}/rhvoicedata.tar.xz" DESTINATION ${module_install_dir})
    install(FILES "${PROJECT_BINARY_DIR}/rhvoiceconfig.tar.xz" DESTINATION ${module_install_dir})
endif()

if(BUILD_PIPER)
    strip_all("${external_lib_dir}/libonnxruntime.so.1.16.1")
    install(FILES "${external_lib_dir}/libonnxruntime.so.1.16.1" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libonnxruntime.so" DESTINATION ${lib_install_dir})
endif()

if(${BUILD_VOSK} OR ${DOWNLOAD_VOSK})
    install(FILES "${external_lib_dir}/libvosk.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_BERGAMOT)
    strip_all("${external_lib_dir}/libbergamot_api.so")
    install(FILES "${external_lib_dir}/libbergamot_api.so" DESTINATION ${lib_install_dir})
    if(arch_x8664)
        strip_all("${external_lib_dir}/libbergamot_api-fallback.so")
        install(FILES "${external_lib_dir}/libbergamot_api-fallback.so" DESTINATION ${lib_install_dir})
    endif()
endif()

if(BUILD_LIBNUMBERTEXT)
    install(DIRECTORY "${external_share_dir}/libnumbertext" DESTINATION ${share_install_dir})
endif()

if(BUILD_UROMAN)
    if(arch_x8664)
        install(DIRECTORY "${external_share_dir}/uroman" DESTINATION ${share_install_dir})
    endif()
endif()

if(BUILD_APRILASR)
    strip_all("${external_lib_dir}/libaprilasr.so.2023.5.12")
    install(FILES "${external_lib_dir}/libaprilasr.so.2023.5.12" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libaprilasr.so.2023" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libaprilasr.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_ESPEAK)
    strip_all("${external_lib_dir}/libespeak-ng.so.1.1.51")
    install(FILES "${external_lib_dir}/libespeak-ng.so.1.1.51" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libespeak-ng.so.1" DESTINATION ${lib_install_dir})
    install(FILES "${external_lib_dir}/libespeak-ng.so" DESTINATION ${lib_install_dir})
endif()

if(WITH_SYSTEMD_SERVICE)
    configure_file("${systemd_dir}/speech.service.in" "${PROJECT_BINARY_DIR}/speech.service")
    install(FILES "${PROJECT_BINARY_DIR}/speech.service" DESTINATION lib/systemd/user RENAME ${info_binary_id}.service)

    configure_file("${dbus_dir}/dbus_speech.service.in" "${PROJECT_BINARY_DIR}/dbus_speech.service")
    install(FILES "${PROJECT_BINARY_DIR}/dbus_speech.service" DESTINATION share/dbus-1/services RENAME ${info_dbus_service}.service)
endif()

if(BUILD_QQC2_BREEZE_STYLE)
    install(DIRECTORY "${external_lib_dir}/qml" DESTINATION ${lib_install_dir})
    install(DIRECTORY "${external_lib_dir}/plugins" DESTINATION ${lib_install_dir})
endif()
