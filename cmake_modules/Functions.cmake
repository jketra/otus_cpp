# Получение всех целей от указанного каталога.
function(get_all_targets _result _dir)
	get_property(_subdirs DIRECTORY "${_dir}" PROPERTY SUBDIRECTORIES)
	foreach(_subdir IN LISTS _subdirs)
		get_all_targets(${_result} "${_subdir}")
	endforeach()

	get_property(_sub_targets DIRECTORY "${_dir}" PROPERTY BUILDSYSTEM_TARGETS)

	foreach(_target IN LISTS _sub_targets)
		get_target_property(target_type ${_target} TYPE)
		if (NOT ${target_type} STREQUAL "INTERFACE_LIBRARY")
			list(APPEND sub_targets ${_target})
		endif()
	endforeach()

	set(${_result} ${${_result}} ${sub_targets} PARENT_SCOPE)
endfunction()

# Применение FOLDER фильтра на цели в каталоге _dir (для компоновки проектов по папкам в IDE).
# Первый уровень дерева будет с названием _parent_dir_name.
function(apply_folder_filter _parent_dir_name _dir)
	get_property(_subdirs DIRECTORY ${_dir} PROPERTY SUBDIRECTORIES)

	foreach(_subdir IN LISTS _subdirs)
		get_filename_component(_dir_name ${_subdir} NAME)
		apply_folder_filter("${_parent_dir_name}/${_dir_name}" ${_subdir})
	endforeach()

	get_all_targets(_targets "${_dir}")

	list(LENGTH _targets _targets_count)
	if (${_targets_count} GREATER 1)
		foreach(_target IN LISTS _targets)
			get_target_property(folder ${_target} FOLDER)
			if (NOT folder)
				set_target_properties(${_target} PROPERTIES FOLDER ${_parent_dir_name})
			endif()
		endforeach()
	endif()
endfunction()

function(post_buld_copy_executable _current_binary_dir _target_name _output_target_name)
	if (WIN32)
		set(FROM_DIR ${_current_binary_dir}/${CMAKE_CFG_INTDIR})
	else()
		set(FROM_DIR ${_current_binary_dir})
	endif()

	add_custom_command(TARGET ${_target_name} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
		${FROM_DIR}/${_output_target_name}${CMAKE_EXECUTABLE_SUFFIX}
		${CMAKE_BINARY_DIR}/bin/${_output_target_name}${CMAKE_EXECUTABLE_SUFFIX})
endfunction()
