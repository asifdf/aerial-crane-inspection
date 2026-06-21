// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from pegasus_msgs:msg/NodeHealth.idl
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
#include "pegasus_msgs/msg/detail/node_health__struct.h"
#include "pegasus_msgs/msg/detail/node_health__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool pegasus_msgs__msg__node_health__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("pegasus_msgs.msg._node_health.NodeHealth", full_classname_dest, 40) == 0);
  }
  pegasus_msgs__msg__NodeHealth * ros_message = _ros_message;
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
  {  // node_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "node_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->node_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // device_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->device_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // fps
    PyObject * field = PyObject_GetAttrString(_pymsg, "fps");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->fps = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // avg_latency_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "avg_latency_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->avg_latency_ms = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p95_latency_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "p95_latency_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p95_latency_ms = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p99_latency_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "p99_latency_ms");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p99_latency_ms = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gpu_util_percent
    PyObject * field = PyObject_GetAttrString(_pymsg, "gpu_util_percent");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gpu_util_percent = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gpu_mem_used_mb
    PyObject * field = PyObject_GetAttrString(_pymsg, "gpu_mem_used_mb");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gpu_mem_used_mb = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gpu_mem_total_mb
    PyObject * field = PyObject_GetAttrString(_pymsg, "gpu_mem_total_mb");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->gpu_mem_total_mb = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cpu_util_percent
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_util_percent");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cpu_util_percent = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cpu_mem_used_mb
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_mem_used_mb");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cpu_mem_used_mb = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cpu_mem_total_mb
    PyObject * field = PyObject_GetAttrString(_pymsg, "cpu_mem_total_mb");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cpu_mem_total_mb = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // temperature_c
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature_c");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->temperature_c = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // model_path
    PyObject * field = PyObject_GetAttrString(_pymsg, "model_path");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->model_path, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // model_version
    PyObject * field = PyObject_GetAttrString(_pymsg, "model_version");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->model_version, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // precision
    PyObject * field = PyObject_GetAttrString(_pymsg, "precision");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->precision, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // input_width
    PyObject * field = PyObject_GetAttrString(_pymsg, "input_width");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->input_width = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // input_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "input_height");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->input_height = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // frames_processed
    PyObject * field = PyObject_GetAttrString(_pymsg, "frames_processed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->frames_processed = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // detections_published
    PyObject * field = PyObject_GetAttrString(_pymsg, "detections_published");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->detections_published = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // errors_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "errors_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->errors_count = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // last_error_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_error_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->last_error_time = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // status
    PyObject * field = PyObject_GetAttrString(_pymsg, "status");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->status, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // active_alerts
    PyObject * field = PyObject_GetAttrString(_pymsg, "active_alerts");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'active_alerts'");
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
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->active_alerts), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->active_alerts.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyUnicode_Check(item));
        PyObject * encoded_item = PyUnicode_AsUTF8String(item);
        if (!encoded_item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        rosidl_runtime_c__String__assign(&dest[i], PyBytes_AS_STRING(encoded_item));
        Py_DECREF(encoded_item);
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * pegasus_msgs__msg__node_health__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NodeHealth */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("pegasus_msgs.msg._node_health");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NodeHealth");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  pegasus_msgs__msg__NodeHealth * ros_message = (pegasus_msgs__msg__NodeHealth *)raw_ros_message;
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
  {  // node_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->node_name.data,
      strlen(ros_message->node_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "node_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->device_id.data,
      strlen(ros_message->device_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fps
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->fps);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fps", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // avg_latency_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->avg_latency_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "avg_latency_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p95_latency_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p95_latency_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p95_latency_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p99_latency_ms
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p99_latency_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p99_latency_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gpu_util_percent
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gpu_util_percent);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gpu_util_percent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gpu_mem_used_mb
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gpu_mem_used_mb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gpu_mem_used_mb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gpu_mem_total_mb
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->gpu_mem_total_mb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gpu_mem_total_mb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cpu_util_percent
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cpu_util_percent);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_util_percent", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cpu_mem_used_mb
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cpu_mem_used_mb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_mem_used_mb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cpu_mem_total_mb
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cpu_mem_total_mb);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cpu_mem_total_mb", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature_c
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->temperature_c);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature_c", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // model_path
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->model_path.data,
      strlen(ros_message->model_path.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "model_path", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // model_version
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->model_version.data,
      strlen(ros_message->model_version.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "model_version", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // precision
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->precision.data,
      strlen(ros_message->precision.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "precision", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // input_width
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->input_width);
    {
      int rc = PyObject_SetAttrString(_pymessage, "input_width", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // input_height
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->input_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "input_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frames_processed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->frames_processed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frames_processed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // detections_published
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->detections_published);
    {
      int rc = PyObject_SetAttrString(_pymessage, "detections_published", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // errors_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->errors_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "errors_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // last_error_time
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->last_error_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_error_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // status
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->status.data,
      strlen(ros_message->status.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // active_alerts
    PyObject * field = NULL;
    size_t size = ros_message->active_alerts.size;
    rosidl_runtime_c__String * src = ros_message->active_alerts.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      PyObject * decoded_item = PyUnicode_DecodeUTF8(src[i].data, strlen(src[i].data), "replace");
      if (!decoded_item) {
        return NULL;
      }
      int rc = PyList_SetItem(field, i, decoded_item);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "active_alerts", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
