# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_generator_c:autopilot_interface_msgs__rosidl_generator_c;__rosidl_typesupport_fastrtps_c:autopilot_interface_msgs__rosidl_typesupport_fastrtps_c;__rosidl_typesupport_introspection_c:autopilot_interface_msgs__rosidl_typesupport_introspection_c;__rosidl_typesupport_c:autopilot_interface_msgs__rosidl_typesupport_c;__rosidl_generator_cpp:autopilot_interface_msgs__rosidl_generator_cpp;__rosidl_typesupport_fastrtps_cpp:autopilot_interface_msgs__rosidl_typesupport_fastrtps_cpp;__rosidl_typesupport_introspection_cpp:autopilot_interface_msgs__rosidl_typesupport_introspection_cpp;__rosidl_typesupport_cpp:autopilot_interface_msgs__rosidl_typesupport_cpp;__rosidl_generator_py:autopilot_interface_msgs__rosidl_generator_py")

# populate autopilot_interface_msgs_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "autopilot_interface_msgs::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'autopilot_interface_msgs' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND autopilot_interface_msgs_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
