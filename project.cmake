# 编译目标
add_library(${ProjectName} STATIC)
target_import_src(${ProjectName})

if(platform STREQUAL "msys")
	target_import_base(${ProjectName} PUBLIC)
endif()


# 添加测试程序
if(platform STREQUAL "msys")
	set(exe_name "test")
	add_executable(${exe_name} ${CMAKE_CURRENT_SOURCE_DIR}/exe/main.cpp)
	target_link_libraries(${exe_name} ${ProjectName})
	target_install(${exe_name})
endif()
