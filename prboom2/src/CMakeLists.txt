
function(ApplySDL2NetOptions TARGET)
    if(SDL2_NET_FOUND)
        target_include_directories(${TARGET} PRIVATE ${SDL2_NET_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${SDL2_NET_LIBRARIES})
    endif()
endfunction()

# PrBoom main executable

set(COMMON_SRC
    am_map.cc
    am_map.h
    doomdata.h
    doomdef.cc
    doomdef.h
    doomstat.cc
    doomstat.h
    doomtype.h
    dstrings.cc
    dstrings.h
    d_deh.cc
    d_deh.h
    d_englsh.h
    d_event.h
    d_items.cc
    d_items.h
    d_main.cc
    d_main.h
    d_net.h
    d_player.h
    d_think.h
    d_ticcmd.h
    e6y.cc
    e6y.h
    f_finale.cc
    f_finale.h
    f_finale2.cc
    f_wipe.cc
    f_wipe.h
    g_game.cc
    g_game.h
    g_overflow.cc
    g_overflow.h
    hu_lib.cc
    hu_lib.h
    hu_stuff.cc
    hu_stuff.h
    hu_tracers.cc
    hu_tracers.h
    info.cc
    info.h
    i_capture.cc
    i_capture.h
    i_joy.h
    i_main.h
    i_network.h
    i_pcsound.cc
    i_pcsound.h
    i_sound.h
    i_system.h
    i_video.h
    lprintf.cc
    lprintf.h
    md5.cc
    md5.h
    m_argv.cc
    m_argv.h
    m_bbox.cc
    m_bbox.h
    m_cheat.cc
    m_cheat.h
    m_fixed.h
    m_menu.cc
    m_menu.h
    m_misc.cc
    m_misc.h
    m_random.cc
    m_random.h
    m_swap.h
    protocol.h
    p_ceilng.cc
    p_checksum.cc
    p_checksum.h
    p_doors.cc
    p_enemy.cc
    p_enemy.h
    p_floor.cc
    p_genlin.cc
    p_inter.cc
    p_inter.h
    p_lights.cc
    p_map.cc
    p_map.h
    p_maputl.cc
    p_maputl.h
    p_mobj.cc
    p_mobj.h
    p_plats.cc
    p_pspr.cc
    p_pspr.h
    p_saveg.cc
    p_saveg.h
    p_setup.cc
    p_setup.h
    p_sight.cc
    p_spec.cc
    p_spec.h
    p_switch.cc
    p_telept.cc
    p_tick.cc
    p_tick.h
    p_user.cc
    p_user.h
    r_bsp.cc
    r_bsp.h
    r_data.cc
    r_data.h
    r_defs.h
    r_demo.cc
    r_demo.h
    r_draw.cc
    r_draw.h
    r_filter.cc
    r_filter.h
    r_fps.cc
    r_fps.h
    r_main.cc
    r_main.h
    r_patch.cc
    r_patch.h
    r_plane.cc
    r_plane.h
    r_segs.cc
    r_segs.h
    r_sky.cc
    r_sky.h
    r_state.h
    r_things.cc
    r_things.h
    scanner.cc
    scanner.h
    sc_man.cc
    sc_man.h
    sounds.cc
    sounds.h
    statdump.cc
    statdump.h
    st_lib.cc
    st_lib.h
    st_stuff.cc
    st_stuff.h
    s_advsound.cc
    s_advsound.h
    s_sound.cc
    s_sound.h
    tables.cc
    tables.h
    umapinfo.cc
    umapinfo.h
    version.cc
    version.h
    v_trans.cc
    v_trans.h
    v_video.cc
    v_video.h
    wi_stuff.cc
    wi_stuff.h
    w_wad.cc
    w_wad.h
    z_bmalloc.cc
    z_bmalloc.h
    z_zone.cc
    z_zone.h
)

set(NET_CLIENT_SRC
    d_client.cc
)

if(HAVE_MMAP)
    set(WAD_SRC w_mmap.cc)
else()
    set(WAD_SRC w_memcache.cc)
endif()

set(MUS2MID_SRC
    memio.cc
    memio.h
    mus2mid.cc
    mus2mid.h
)

set(SDLDOOM_SOURCES
    SDL/i_joy.cc
    SDL/i_main.cc
    SDL/i_network.cc
    SDL/i_sound.cc
    SDL/i_sshot.cc
    SDL/i_system.cc
    SDL/i_video.cc
)

set(PCSOUND_SOURCES
    PCSOUND/pcsound.cc
    PCSOUND/pcsound.h
    PCSOUND/pcsound_linux.cc
    PCSOUND/pcsound_sdl.cc
    PCSOUND/pcsound_win32.cc
)

set(TEXTSCREEN_SOURCES
    TEXTSCREEN/doomkeys.h
    TEXTSCREEN/txt_main.h
    TEXTSCREEN/txt_font.h
    TEXTSCREEN/txt_largefont.h
    TEXTSCREEN/txt_sdl.cc
    TEXTSCREEN/txt_sdl.h
    TEXTSCREEN/txt_smallfont.h
)

set(DOOMMUSIC_SOURCES
    MUSIC/dbopl.cc
    MUSIC/dbopl.h
    MUSIC/dumbplayer.cc
    MUSIC/dumbplayer.h
    MUSIC/flplayer.cc
    MUSIC/flplayer.h
    MUSIC/madplayer.cc
    MUSIC/madplayer.h
    MUSIC/midifile.cc
    MUSIC/midifile.h
    MUSIC/musicplayer.h
    MUSIC/opl.cc
    MUSIC/opl.h
    MUSIC/oplplayer.cc
    MUSIC/oplplayer.h
    MUSIC/opl_queue.cc
    MUSIC/opl_queue.h
    MUSIC/portmidiplayer.cc
    MUSIC/portmidiplayer.h
    MUSIC/vorbisplayer.cc
    MUSIC/vorbisplayer.h
)

set(EXTRA_FILES
    r_drawcolpipeline.inl
    r_drawcolumn.inl
    r_drawflush.inl
    r_drawspan.inl
)

set(PRBOOM_PLUS_SOURCES
    ${COMMON_SRC}
    ${NET_CLIENT_SRC}
    ${WAD_SRC}
    ${MUS2MID_SRC}
    ${SDLDOOM_SOURCES}
    ${PCSOUND_SOURCES}
    ${TEXTSCREEN_SOURCES}
    ${DOOMMUSIC_SOURCES}
    ${EXTRA_FILES}
)

function(AddGameExecutable TARGET SOURCES)
    if(OPENGL_FOUND AND OPENGL_GLU_FOUND)
        set(SOURCES
            ${SOURCES}
            gl_clipper.cc
            gl_detail.cc
            gl_drawinfo.cc
            gl_fbo.cc
            gl_gamma.cc
            gl_hires.cc
            gl_hqresize.cc
            gl_intern.h
            gl_light.cc
            gl_main.cc
            gl_map.cc
            gl_missingtexture.cc
            gl_opengl.cc
            gl_opengl.h
            gl_preprocess.cc
            gl_shader.cc
            gl_shadow.cc
            gl_sky.cc
            gl_struct.h
            gl_texture.cc
            gl_vertex.cc
            gl_wipe.cc
        )
    endif()

    if(WIN32)
        add_definitions("-DUSE_WIN32_PCSOUND_DRIVER -DUSE_WINDOWS_LAUNCHER")
        set(SOURCES
            ${SOURCES}
            ../ICONS/icons.rc
            e6y_launcher.cc
            e6y_launcher.h
            SDL/SDL_windows_main.cc
        )
    endif()

    add_definitions("-DUSE_EXPERIMENTAL_MUSIC")

    add_executable(${TARGET} WIN32 ${SOURCES})
    target_include_directories(${TARGET} PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_link_libraries(${TARGET} PRIVATE
        ${SDL2_LIBRARIES}
    )
    if(WIN32)
        target_link_libraries(${TARGET} PRIVATE
            winmm
            comctl32
        )
    endif()
    set_target_properties(${TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PRBOOM_OUTPUT_PATH}
    )
    if(SDL2_IMAGE_FOUND)
        target_include_directories(${TARGET} PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${SDL2_IMAGE_LIBRARIES})
    endif()
    if(SDL2_MIXER_FOUND)
        target_include_directories(${TARGET} PRIVATE ${SDL2_MIXER_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${SDL2_MIXER_LIBRARIES})
    endif()
    if(PCREPOSIX_FOUND)
        target_include_directories(${TARGET} PRIVATE ${PCRE_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${PCREPOSIX_LIBRARIES})
    endif()
    ApplySDL2NetOptions(${TARGET})
    if(ZLIB_FOUND)
        target_include_directories(${TARGET} PRIVATE ${ZLIB_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${ZLIB_LIBRARIES})
    endif()
    if(LIBMAD_FOUND)
        target_include_directories(${TARGET} PRIVATE ${LIBMAD_INCLUDE_DIRS})
        target_link_libraries(${TARGET} PRIVATE ${LIBMAD_LIBRARIES})
    endif()
    if(FLUIDSYNTH_FOUND)
        target_include_directories(${TARGET} PRIVATE ${FLUIDSYNTH_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${FLUIDSYNTH_LIBRARIES})
    endif()
    if(DUMB_FOUND)
        target_include_directories(${TARGET} PRIVATE ${DUMB_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${DUMB_LIBRARY})
    endif()
    if(VORBIS_FOUND)
        target_include_directories(${TARGET} PRIVATE ${VORBIS_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${VORBISFILE_LIBRARY})
    endif()
    if(PortMidi_FOUND)
        target_include_directories(${TARGET} PRIVATE ${PORTMIDI_INCLUDE_DIR})
        target_link_libraries(${TARGET} PRIVATE ${PORTMIDI_LIBRARIES})
    endif()
    add_dependencies(${TARGET} prboomwad)

    if(MSVC)
        set_target_properties(${TARGET} PROPERTIES
            LINK_FLAGS "/MANIFEST:NO"
        )
        add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND "mt.exe" -manifest \"${CMAKE_CURRENT_SOURCE_DIR}\\..\\ICONS\\prboom-plus.exe.manifest\" -outputresource:\"$<TARGET_FILE:prboom-plus>\"\;\#1
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${WAD_DATA_PATH} $<TARGET_FILE_DIR:prboom-plus>
        )
    endif()

    install(TARGETS ${TARGET} COMPONENT "Game executable" RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")

    if(OPENGL_FOUND AND OPENGL_GLU_FOUND)
        target_compile_definitions(${TARGET} PRIVATE
            GL_DOOM
            USE_SHADERS
            USE_FBO_TECHNIQUE
            USE_GLU_IMAGESCALE
            USE_GLU_MIPMAP
            USE_GLU_TESS
        )
        target_link_libraries(${TARGET} PRIVATE
            ${OPENGL_gl_LIBRARY}
            ${OPENGL_glu_LIBRARY}
        )
    endif()
endfunction()

AddGameExecutable(prboom-plus "${PRBOOM_PLUS_SOURCES}")


# PrBoom-Plus server executable

option(BUILD_SERVER "Build PrBoom-Plus server executable" ON)

if(BUILD_SERVER AND SDL2_NET_FOUND)
    set(PRBOOM_PLUS_GAME_SERVER_SOURCES
        d_server.cc
        protocol.h
        SDL/i_network.cc
    )

    if(MSVC)
        set(PRBOOM_PLUS_GAME_SERVER_SOURCES
            ${PRBOOM_PLUS_GAME_SERVER_SOURCES}
            SDL/i_system.cc
        )
    else()
        set(PRBOOM_PLUS_GAME_SERVER_SOURCES
            ${PRBOOM_PLUS_GAME_SERVER_SOURCES}
            POSIX/i_system.cc
        )
    endif()

    add_executable(prboom-plus-game-server ${PRBOOM_PLUS_GAME_SERVER_SOURCES})
    target_include_directories(prboom-plus-game-server PRIVATE
        ${SDL2_INCLUDE_DIRS}
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    target_link_libraries(prboom-plus-game-server PRIVATE
        ${SDL2_LIBRARIES}
    )
    set_target_properties(prboom-plus-game-server PROPERTIES
        COMPILE_DEFINITIONS PRBOOM_SERVER
        RUNTIME_OUTPUT_DIRECTORY ${PRBOOM_OUTPUT_PATH}
    )
    ApplySDL2NetOptions(prboom-plus-game-server)
    install(TARGETS prboom-plus-game-server COMPONENT "Game server executable" RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
endif()


# PrBoom-Plus macOS launcher

if(APPLE)
    set(LAUNCHER_SOURCES
        MAC/ANSIString.m
        MAC/ConsoleController.h
        MAC/ConsoleController.m
        MAC/DrawerButton.h
        MAC/DrawerButton.m
        MAC/FileButtonController.h
        MAC/FileButtonController.m
        MAC/LauncherApp.h
        MAC/LauncherApp.m
        MAC/LauncherMain.m
        MAC/ResolutionDataSource.h
        MAC/ResolutionDataSource.m
        MAC/UKFileWatcher.h
        MAC/UKKQueue.h
        MAC/UKKQueue.m
        MAC/UKMainThreadProxy.h
        MAC/UKMainThreadProxy.m
        MAC/WadViewController.h
        MAC/WadViewController.m
    )

    set(LAUNCHER_RESOURCES
        MAC/Launcher.icns
        MAC/PrBoom.icns
        MAC/PrBoom.sdef
    )
    set_source_files_properties(${LAUNCHER_RESOURCES} PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources
    )

    set(LAUNCHER_MAINMENU_RESOURCES
        MAC/English.lproj/MainMenu.nib/classes.nib
        MAC/English.lproj/MainMenu.nib/info.nib
        MAC/English.lproj/MainMenu.nib/keyedobjects.nib
    )
    set_source_files_properties(${LAUNCHER_MAINMENU_RESOURCES} PROPERTIES
        MACOSX_PACKAGE_LOCATION Resources/English.lproj/MainMenu.nib
    )

    add_executable(prboom-plus-launcher MACOSX_BUNDLE
        ${LAUNCHER_SOURCES}
        ${LAUNCHER_RESOURCES}
        ${LAUNCHER_MAINMENU_RESOURCES}
    )
    target_include_directories(prboom-plus-launcher PRIVATE
        ${CMAKE_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
    set_target_properties(prboom-plus-launcher PROPERTIES
        LINK_FLAGS "-framework Cocoa"
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/MAC/Info.plist"
        OUTPUT_NAME "Launcher"
        RUNTIME_OUTPUT_DIRECTORY ${PRBOOM_OUTPUT_PATH}
        XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
    )
    add_dependencies(prboom-plus-launcher prboom-plus)

    set(BUNDLE_GAME_EXECUTABLE prboom-plus)

    add_custom_command(TARGET prboom-plus-launcher POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${BUNDLE_GAME_EXECUTABLE}> $<TARGET_FILE_DIR:prboom-plus-launcher>/PrBoom-Plus
        COMMAND ${CMAKE_COMMAND} -E copy_if_different ${WAD_DATA_PATH} $<TARGET_FILE_DIR:prboom-plus-launcher>
    )

    if(BUILD_SERVER AND SDL2_NET_FOUND)
        add_dependencies(prboom-plus-launcher prboom-plus-game-server)
        add_custom_command(TARGET prboom-plus-launcher POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:prboom-plus-game-server> $<TARGET_FILE_DIR:prboom-plus-launcher>
        )
    endif()
endif()
