add_executable(engine
	main.cpp
	App.cpp
)

target_link_libraries(engine PRIVATE SFML::Graphics)

add_custom_command(TARGET engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:engine>
        $<TARGET_FILE_DIR:engine>
    COMMAND_EXPAND_LISTS
)