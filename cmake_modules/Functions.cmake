# Получение всех целей от указанного каталога.
function(get_all_targets _result _dir)
	get_property(_subdirs DIRECTORY "${_dir}" PROPERTY SUBDIRECTORIES)
	foreach(_subdir IN LISTS _subdirs)
		get_all_targets(${_result} "${_subdir}")
	endforeach()

	get_property(_sub_targets DIRECTORY "${_dir}" PROPERTY BUILDSYSTEM_TARGETS)

	set(${_result} ${${_result}} ${_sub_targets} PARENT_SCOPE)
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
