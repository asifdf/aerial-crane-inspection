# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pegasus_msgs:msg/NodeHealth.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NodeHealth(type):
    """Metaclass of message 'NodeHealth'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('pegasus_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'pegasus_msgs.msg.NodeHealth')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__node_health
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__node_health
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__node_health
            cls._TYPE_SUPPORT = module.type_support_msg__msg__node_health
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__node_health

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NodeHealth(metaclass=Metaclass_NodeHealth):
    """Message class 'NodeHealth'."""

    __slots__ = [
        '_header',
        '_node_name',
        '_device_id',
        '_fps',
        '_avg_latency_ms',
        '_p95_latency_ms',
        '_p99_latency_ms',
        '_gpu_util_percent',
        '_gpu_mem_used_mb',
        '_gpu_mem_total_mb',
        '_cpu_util_percent',
        '_cpu_mem_used_mb',
        '_cpu_mem_total_mb',
        '_temperature_c',
        '_model_path',
        '_model_version',
        '_precision',
        '_input_width',
        '_input_height',
        '_frames_processed',
        '_detections_published',
        '_errors_count',
        '_last_error_time',
        '_status',
        '_active_alerts',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'node_name': 'string',
        'device_id': 'string',
        'fps': 'float',
        'avg_latency_ms': 'float',
        'p95_latency_ms': 'float',
        'p99_latency_ms': 'float',
        'gpu_util_percent': 'float',
        'gpu_mem_used_mb': 'float',
        'gpu_mem_total_mb': 'float',
        'cpu_util_percent': 'float',
        'cpu_mem_used_mb': 'float',
        'cpu_mem_total_mb': 'float',
        'temperature_c': 'float',
        'model_path': 'string',
        'model_version': 'string',
        'precision': 'string',
        'input_width': 'uint32',
        'input_height': 'uint32',
        'frames_processed': 'uint64',
        'detections_published': 'uint64',
        'errors_count': 'uint64',
        'last_error_time': 'uint64',
        'status': 'string',
        'active_alerts': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.node_name = kwargs.get('node_name', str())
        self.device_id = kwargs.get('device_id', str())
        self.fps = kwargs.get('fps', float())
        self.avg_latency_ms = kwargs.get('avg_latency_ms', float())
        self.p95_latency_ms = kwargs.get('p95_latency_ms', float())
        self.p99_latency_ms = kwargs.get('p99_latency_ms', float())
        self.gpu_util_percent = kwargs.get('gpu_util_percent', float())
        self.gpu_mem_used_mb = kwargs.get('gpu_mem_used_mb', float())
        self.gpu_mem_total_mb = kwargs.get('gpu_mem_total_mb', float())
        self.cpu_util_percent = kwargs.get('cpu_util_percent', float())
        self.cpu_mem_used_mb = kwargs.get('cpu_mem_used_mb', float())
        self.cpu_mem_total_mb = kwargs.get('cpu_mem_total_mb', float())
        self.temperature_c = kwargs.get('temperature_c', float())
        self.model_path = kwargs.get('model_path', str())
        self.model_version = kwargs.get('model_version', str())
        self.precision = kwargs.get('precision', str())
        self.input_width = kwargs.get('input_width', int())
        self.input_height = kwargs.get('input_height', int())
        self.frames_processed = kwargs.get('frames_processed', int())
        self.detections_published = kwargs.get('detections_published', int())
        self.errors_count = kwargs.get('errors_count', int())
        self.last_error_time = kwargs.get('last_error_time', int())
        self.status = kwargs.get('status', str())
        self.active_alerts = kwargs.get('active_alerts', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.node_name != other.node_name:
            return False
        if self.device_id != other.device_id:
            return False
        if self.fps != other.fps:
            return False
        if self.avg_latency_ms != other.avg_latency_ms:
            return False
        if self.p95_latency_ms != other.p95_latency_ms:
            return False
        if self.p99_latency_ms != other.p99_latency_ms:
            return False
        if self.gpu_util_percent != other.gpu_util_percent:
            return False
        if self.gpu_mem_used_mb != other.gpu_mem_used_mb:
            return False
        if self.gpu_mem_total_mb != other.gpu_mem_total_mb:
            return False
        if self.cpu_util_percent != other.cpu_util_percent:
            return False
        if self.cpu_mem_used_mb != other.cpu_mem_used_mb:
            return False
        if self.cpu_mem_total_mb != other.cpu_mem_total_mb:
            return False
        if self.temperature_c != other.temperature_c:
            return False
        if self.model_path != other.model_path:
            return False
        if self.model_version != other.model_version:
            return False
        if self.precision != other.precision:
            return False
        if self.input_width != other.input_width:
            return False
        if self.input_height != other.input_height:
            return False
        if self.frames_processed != other.frames_processed:
            return False
        if self.detections_published != other.detections_published:
            return False
        if self.errors_count != other.errors_count:
            return False
        if self.last_error_time != other.last_error_time:
            return False
        if self.status != other.status:
            return False
        if self.active_alerts != other.active_alerts:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def node_name(self):
        """Message field 'node_name'."""
        return self._node_name

    @node_name.setter
    def node_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'node_name' field must be of type 'str'"
        self._node_name = value

    @builtins.property
    def device_id(self):
        """Message field 'device_id'."""
        return self._device_id

    @device_id.setter
    def device_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'device_id' field must be of type 'str'"
        self._device_id = value

    @builtins.property
    def fps(self):
        """Message field 'fps'."""
        return self._fps

    @fps.setter
    def fps(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fps' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'fps' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._fps = value

    @builtins.property
    def avg_latency_ms(self):
        """Message field 'avg_latency_ms'."""
        return self._avg_latency_ms

    @avg_latency_ms.setter
    def avg_latency_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'avg_latency_ms' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'avg_latency_ms' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._avg_latency_ms = value

    @builtins.property
    def p95_latency_ms(self):
        """Message field 'p95_latency_ms'."""
        return self._p95_latency_ms

    @p95_latency_ms.setter
    def p95_latency_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p95_latency_ms' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'p95_latency_ms' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._p95_latency_ms = value

    @builtins.property
    def p99_latency_ms(self):
        """Message field 'p99_latency_ms'."""
        return self._p99_latency_ms

    @p99_latency_ms.setter
    def p99_latency_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p99_latency_ms' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'p99_latency_ms' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._p99_latency_ms = value

    @builtins.property
    def gpu_util_percent(self):
        """Message field 'gpu_util_percent'."""
        return self._gpu_util_percent

    @gpu_util_percent.setter
    def gpu_util_percent(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gpu_util_percent' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gpu_util_percent' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gpu_util_percent = value

    @builtins.property
    def gpu_mem_used_mb(self):
        """Message field 'gpu_mem_used_mb'."""
        return self._gpu_mem_used_mb

    @gpu_mem_used_mb.setter
    def gpu_mem_used_mb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gpu_mem_used_mb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gpu_mem_used_mb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gpu_mem_used_mb = value

    @builtins.property
    def gpu_mem_total_mb(self):
        """Message field 'gpu_mem_total_mb'."""
        return self._gpu_mem_total_mb

    @gpu_mem_total_mb.setter
    def gpu_mem_total_mb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'gpu_mem_total_mb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'gpu_mem_total_mb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._gpu_mem_total_mb = value

    @builtins.property
    def cpu_util_percent(self):
        """Message field 'cpu_util_percent'."""
        return self._cpu_util_percent

    @cpu_util_percent.setter
    def cpu_util_percent(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cpu_util_percent' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cpu_util_percent' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cpu_util_percent = value

    @builtins.property
    def cpu_mem_used_mb(self):
        """Message field 'cpu_mem_used_mb'."""
        return self._cpu_mem_used_mb

    @cpu_mem_used_mb.setter
    def cpu_mem_used_mb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cpu_mem_used_mb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cpu_mem_used_mb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cpu_mem_used_mb = value

    @builtins.property
    def cpu_mem_total_mb(self):
        """Message field 'cpu_mem_total_mb'."""
        return self._cpu_mem_total_mb

    @cpu_mem_total_mb.setter
    def cpu_mem_total_mb(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cpu_mem_total_mb' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cpu_mem_total_mb' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cpu_mem_total_mb = value

    @builtins.property
    def temperature_c(self):
        """Message field 'temperature_c'."""
        return self._temperature_c

    @temperature_c.setter
    def temperature_c(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'temperature_c' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'temperature_c' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._temperature_c = value

    @builtins.property
    def model_path(self):
        """Message field 'model_path'."""
        return self._model_path

    @model_path.setter
    def model_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model_path' field must be of type 'str'"
        self._model_path = value

    @builtins.property
    def model_version(self):
        """Message field 'model_version'."""
        return self._model_version

    @model_version.setter
    def model_version(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'model_version' field must be of type 'str'"
        self._model_version = value

    @builtins.property
    def precision(self):
        """Message field 'precision'."""
        return self._precision

    @precision.setter
    def precision(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'precision' field must be of type 'str'"
        self._precision = value

    @builtins.property
    def input_width(self):
        """Message field 'input_width'."""
        return self._input_width

    @input_width.setter
    def input_width(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'input_width' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'input_width' field must be an unsigned integer in [0, 4294967295]"
        self._input_width = value

    @builtins.property
    def input_height(self):
        """Message field 'input_height'."""
        return self._input_height

    @input_height.setter
    def input_height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'input_height' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'input_height' field must be an unsigned integer in [0, 4294967295]"
        self._input_height = value

    @builtins.property
    def frames_processed(self):
        """Message field 'frames_processed'."""
        return self._frames_processed

    @frames_processed.setter
    def frames_processed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'frames_processed' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'frames_processed' field must be an unsigned integer in [0, 18446744073709551615]"
        self._frames_processed = value

    @builtins.property
    def detections_published(self):
        """Message field 'detections_published'."""
        return self._detections_published

    @detections_published.setter
    def detections_published(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'detections_published' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'detections_published' field must be an unsigned integer in [0, 18446744073709551615]"
        self._detections_published = value

    @builtins.property
    def errors_count(self):
        """Message field 'errors_count'."""
        return self._errors_count

    @errors_count.setter
    def errors_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'errors_count' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'errors_count' field must be an unsigned integer in [0, 18446744073709551615]"
        self._errors_count = value

    @builtins.property
    def last_error_time(self):
        """Message field 'last_error_time'."""
        return self._last_error_time

    @last_error_time.setter
    def last_error_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'last_error_time' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'last_error_time' field must be an unsigned integer in [0, 18446744073709551615]"
        self._last_error_time = value

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'status' field must be of type 'str'"
        self._status = value

    @builtins.property
    def active_alerts(self):
        """Message field 'active_alerts'."""
        return self._active_alerts

    @active_alerts.setter
    def active_alerts(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'active_alerts' field must be a set or sequence and each value of type 'str'"
        self._active_alerts = value
