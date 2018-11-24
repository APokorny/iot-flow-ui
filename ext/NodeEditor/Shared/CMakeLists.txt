
set(_Shared_Sources
    Include/Builders.h
    Include/Drawing.h
    Include/Widgets.h
    Include/ScopeGuard.h

    Source/Builders.cpp
    Source/Drawing.cpp
    Source/Widgets.cpp
)


source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${_Shared_Sources})

add_library(Shared STATIC ${_Shared_Sources})

target_include_directories(Shared PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Source/Shared
)

target_link_libraries(Shared PRIVATE ImGui NodeEditor)
