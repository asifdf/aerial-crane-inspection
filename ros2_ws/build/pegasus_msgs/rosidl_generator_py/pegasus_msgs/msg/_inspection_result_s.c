// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pegasus_msgs:msg/InspectionResult.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "pegasus_msgs/msg/detail/inspection_result__struct.h"
#include "pegasus_msgs/msg/detail/inspection_result__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose_stamped__convert_to_py(void * raw_ros_message);
bool pegasus_msgs__msg__defect_array__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * pegasus_msgs__msg__defect_array__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool pegasus_msgs__msg__inspection_result__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("pegasus_msgs.msg._inspection_result.InspectionResult", full_classname_dest, 52) == 0);
  }
  pegasus_msgs__msg__InspectionResult * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // drone_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "drone_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->drone_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // mission_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "mission_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->mission_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // zone_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->zone_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // drone_pose
    PyObject * field = PyObject_GetAttrString(_pymsg, "drone_pose");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose_stamped__convert_from_py(field, &ros_message->drone_pose)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // defects
    PyObject * field = PyObject_GetAttrString(_pymsg, "defects");
    if (!field) {
      return false;
    }
    if (!pegasus_msgs__msg__defect_array__convert_from_py(field, &ros_message->defects)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // coverage_percent
    PyObject * field = PyObject_GetAttrString(_pymsg, "coverage_percent");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->coverage_percent = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // images_captured
    PyObject * field = PyObject_GetAttrString(_pymsg, "images_captured");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->images_captured = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // images_with_defects
    PyObject * field = PyObject_GetAttrString(_pymsg, "images_with_defects");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->images_with_defects = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // zone_risk_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_risk_level");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->zone_risk_level, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // zone_risk_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "zone_risk_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->zone_risk_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // json_payload
    PyObject * field = PyObject_GetAttrString(_pymsg, "json_payload");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->json_payload, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pegasus_msgs__msg__inspection_result__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of InspectionResult */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pegasus_msgs.msg._inspection_result");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "InspectionResult");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pegasus_msgs__msg__InspectionResult * ros_message = (pegasus_msgs__msg__InspectionResult *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drone_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->drone_id.data,
      strlen(ros_message->drone_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "drone_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mission_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->mission_id.data,
      strlen(ros_message->mission_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mission_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->zone_id.data,
      strlen(ros_message->zone_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // drone_pose
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose_stamped__convert_to_py(&ros_message->drone_pose);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "drone_pose", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // defects
    PyObject * field = NULL;
    field = pegasus_msgs__msg__defect_array__convert_to_py(&ros_message->defects);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "defects", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // coverage_percent
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->coverage_percent);
    {
      int rc = PyObject_SetAttrString(_pymessage, "coverage_percent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // images_captured
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->images_captured);
    {
      int rc = PyObject_SetAttrString(_pymessage, "images_captured", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // images_with_defects
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->images_with_defects);
    {
      int rc = PyObject_SetAttrString(_pymessage, "images_with_defects", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_risk_level
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->zone_risk_level.data,
      strlen(ros_message->zone_risk_level.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_risk_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // zone_risk_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->zone_risk_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "zone_risk_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // json_payload
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->json_payload.data,
      strlen(ros_message->json_payload.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "json_payload", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
