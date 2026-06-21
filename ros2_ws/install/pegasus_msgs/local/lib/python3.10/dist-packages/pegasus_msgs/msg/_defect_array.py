# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pegasus_msgs:msg/DefectArray.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DefectArray(type):
    """Metaclass of message 'DefectArray'."""

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
                'pegasus_msgs.msg.DefectArray')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__defect_array
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__defect_array
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__defect_array
            cls._TYPE_SUPPORT = module.type_support_msg__msg__defect_array
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__defect_array

            from pegasus_msgs.msg import DefectDetection
            if DefectDetection.__class__._TYPE_SUPPORT is None:
                DefectDetection.__class__.__import_type_support__()

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


class DefectArray(metaclass=Metaclass_DefectArray):
    """Message class 'DefectArray'."""

    __slots__ = [
        '_header',
        '_drone_id',
        '_zone_id',
        '_detections',
        '_total_count',
        '_crack_count',
        '_corrosion_count',
        '_paint_damage_count',
        '_max_risk_level',
        '_max_risk_id',
        '_inference_latency',
        '_total_latency',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'drone_id': 'string',
        'zone_id': 'string',
        'detections': 'sequence<pegasus_msgs/DefectDetection>',
        'total_count': 'uint32',
        'crack_count': 'uint32',
        'corrosion_count': 'uint32',
        'paint_damage_count': 'uint32',
        'max_risk_level': 'string',
        'max_risk_id': 'uint8',
        'inference_latency': 'float',
        'total_latency': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['pegasus_msgs', 'msg'], 'DefectDetection')),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.drone_id = kwargs.get('drone_id', str())
        self.zone_id = kwargs.get('zone_id', str())
        self.detections = kwargs.get('detections', [])
        self.total_count = kwargs.get('total_count', int())
        self.crack_count = kwargs.get('crack_count', int())
        self.corrosion_count = kwargs.get('corrosion_count', int())
        self.paint_damage_count = kwargs.get('paint_damage_count', int())
        self.max_risk_level = kwargs.get('max_risk_level', str())
        self.max_risk_id = kwargs.get('max_risk_id', int())
        self.inference_latency = kwargs.get('inference_latency', float())
        self.total_latency = kwargs.get('total_latency', float())

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
        if self.drone_id != other.drone_id:
            return False
        if self.zone_id != other.zone_id:
            return False
        if self.detections != other.detections:
            return False
        if self.total_count != other.total_count:
            return False
        if self.crack_count != other.crack_count:
            return False
        if self.corrosion_count != other.corrosion_count:
            return False
        if self.paint_damage_count != other.paint_damage_count:
            return False
        if self.max_risk_level != other.max_risk_level:
            return False
        if self.max_risk_id != other.max_risk_id:
            return False
        if self.inference_latency != other.inference_latency:
            return False
        if self.total_latency != other.total_latency:
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
    def drone_id(self):
        """Message field 'drone_id'."""
        return self._drone_id

    @drone_id.setter
    def drone_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'drone_id' field must be of type 'str'"
        self._drone_id = value

    @builtins.property
    def zone_id(self):
        """Message field 'zone_id'."""
        return self._zone_id

    @zone_id.setter
    def zone_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'zone_id' field must be of type 'str'"
        self._zone_id = value

    @builtins.property
    def detections(self):
        """Message field 'detections'."""
        return self._detections

    @detections.setter
    def detections(self, value):
        if __debug__:
            from pegasus_msgs.msg import DefectDetection
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
                 all(isinstance(v, DefectDetection) for v in value) and
                 True), \
                "The 'detections' field must be a set or sequence and each value of type 'DefectDetection'"
        self._detections = value

    @builtins.property
    def total_count(self):
        """Message field 'total_count'."""
        return self._total_count

    @total_count.setter
    def total_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'total_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'total_count' field must be an unsigned integer in [0, 4294967295]"
        self._total_count = value

    @builtins.property
    def crack_count(self):
        """Message field 'crack_count'."""
        return self._crack_count

    @crack_count.setter
    def crack_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'crack_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'crack_count' field must be an unsigned integer in [0, 4294967295]"
        self._crack_count = value

    @builtins.property
    def corrosion_count(self):
        """Message field 'corrosion_count'."""
        return self._corrosion_count

    @corrosion_count.setter
    def corrosion_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'corrosion_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'corrosion_count' field must be an unsigned integer in [0, 4294967295]"
        self._corrosion_count = value

    @builtins.property
    def paint_damage_count(self):
        """Message field 'paint_damage_count'."""
        return self._paint_damage_count

    @paint_damage_count.setter
    def paint_damage_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'paint_damage_count' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'paint_damage_count' field must be an unsigned integer in [0, 4294967295]"
        self._paint_damage_count = value

    @builtins.property
    def max_risk_level(self):
        """Message field 'max_risk_level'."""
        return self._max_risk_level

    @max_risk_level.setter
    def max_risk_level(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'max_risk_level' field must be of type 'str'"
        self._max_risk_level = value

    @builtins.property
    def max_risk_id(self):
        """Message field 'max_risk_id'."""
        return self._max_risk_id

    @max_risk_id.setter
    def max_risk_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_risk_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'max_risk_id' field must be an unsigned integer in [0, 255]"
        self._max_risk_id = value

    @builtins.property
    def inference_latency(self):
        """Message field 'inference_latency'."""
        return self._inference_latency

    @inference_latency.setter
    def inference_latency(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'inference_latency' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'inference_latency' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._inference_latency = value

    @builtins.property
    def total_latency(self):
        """Message field 'total_latency'."""
        return self._total_latency

    @total_latency.setter
    def total_latency(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'total_latency' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'total_latency' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._total_latency = value
