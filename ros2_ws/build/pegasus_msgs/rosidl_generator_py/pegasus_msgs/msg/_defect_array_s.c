// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pegasus_msgs:msg/DefectArray.idl
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
#include "pegasus_msgs/msg/detail/defect_array__struct.h"
#include "pegasus_msgs/msg/detail/defect_array__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "pegasus_msgs/msg/detail/defect_detection__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool pegasus_msgs__msg__defect_detection__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * pegasus_msgs__msg__defect_detection__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool pegasus_msgs__msg__defect_array__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
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
    assert(strncmp("pegasus_msgs.msg._defect_array.DefectArray", full_classname_dest, 42) == 0);
  }
  pegasus_msgs__msg__DefectArray * ros_message = _ros_message;
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
  {  // detections
    PyObject * field = PyObject_GetAttrString(_pymsg, "detections");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'detections'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!pegasus_msgs__msg__DefectDetection__Sequence__init(&(ros_message->detections), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create pegasus_msgs__msg__DefectDetection__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    pegasus_msgs__msg__DefectDetection * dest = ros_message->detections.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!pegasus_msgs__msg__defect_detection__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // total_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "total_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->total_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // crack_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "crack_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->crack_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // corrosion_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "corrosion_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->corrosion_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // paint_damage_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "paint_damage_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->paint_damage_count = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // max_risk_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_risk_level");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->max_risk_level, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // max_risk_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_risk_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_risk_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // inference_latency
    PyObject * field = PyObject_GetAttrString(_pymsg, "inference_latency");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->inference_latency = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // total_latency
    PyObject * field = PyObject_GetAttrString(_pymsg, "total_latency");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->total_latency = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pegasus_msgs__msg__defect_array__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DefectArray */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pegasus_msgs.msg._defect_array");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DefectArray");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pegasus_msgs__msg__DefectArray * ros_message = (pegasus_msgs__msg__DefectArray *)raw_ros_message;
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
  {  // detections
    PyObject * field = NULL;
    size_t size = ros_message->detections.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    pegasus_msgs__msg__DefectDetection * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->detections.data[i]);
      PyObject * pyitem = pegasus_msgs__msg__defect_detection__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "detections", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // total_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->total_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "total_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // crack_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->crack_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "crack_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // corrosion_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->corrosion_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "corrosion_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // paint_damage_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->paint_damage_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "paint_damage_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_risk_level
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->max_risk_level.data,
      strlen(ros_message->max_risk_level.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_risk_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_risk_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->max_risk_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_risk_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // inference_latency
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->inference_latency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "inference_latency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // total_latency
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->total_latency);
    {
      int rc = PyObject_SetAttrString(_pymessage, "total_latency", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
