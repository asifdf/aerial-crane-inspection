// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pegasus_msgs:msg/DefectDetection.idl
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
#include "pegasus_msgs/msg/detail/defect_detection__struct.h"
#include "pegasus_msgs/msg/detail/defect_detection__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__compressed_image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__compressed_image__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__point__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__point__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool pegasus_msgs__msg__defect_detection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
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
    assert(strncmp("pegasus_msgs.msg._defect_detection.DefectDetection", full_classname_dest, 50) == 0);
  }
  pegasus_msgs__msg__DefectDetection * ros_message = _ros_message;
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
  {  // type
    PyObject * field = PyObject_GetAttrString(_pymsg, "type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // class_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "class_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->class_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // confidence
    PyObject * field = PyObject_GetAttrString(_pymsg, "confidence");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->confidence = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_width
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_width");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_width = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_height = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_x_norm
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_x_norm");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_x_norm = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_y_norm
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_y_norm");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_y_norm = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_width_norm
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_width_norm");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_width_norm = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // bbox_height_norm
    PyObject * field = PyObject_GetAttrString(_pymsg, "bbox_height_norm");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->bbox_height_norm = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // risk_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "risk_level");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->risk_level, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // risk_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "risk_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->risk_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "mask");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__compressed_image__convert_from_py(field, &ros_message->mask)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // position_3d
    PyObject * field = PyObject_GetAttrString(_pymsg, "position_3d");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__point__convert_from_py(field, &ros_message->position_3d)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // has_3d_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "has_3d_position");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->has_3d_position = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pegasus_msgs__msg__defect_detection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DefectDetection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pegasus_msgs.msg._defect_detection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DefectDetection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pegasus_msgs__msg__DefectDetection * ros_message = (pegasus_msgs__msg__DefectDetection *)raw_ros_message;
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
  {  // type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->type.data,
      strlen(ros_message->type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // class_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->class_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "class_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // confidence
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->confidence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "confidence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_width
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_width", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_x_norm
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_x_norm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_x_norm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_y_norm
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_y_norm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_y_norm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_width_norm
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_width_norm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_width_norm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // bbox_height_norm
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->bbox_height_norm);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bbox_height_norm", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // risk_level
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->risk_level.data,
      strlen(ros_message->risk_level.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "risk_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // risk_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->risk_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "risk_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // mask
    PyObject * field = NULL;
    field = sensor_msgs__msg__compressed_image__convert_to_py(&ros_message->mask);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position_3d
    PyObject * field = NULL;
    field = geometry_msgs__msg__point__convert_to_py(&ros_message->position_3d);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "position_3d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // has_3d_position
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->has_3d_position ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "has_3d_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
