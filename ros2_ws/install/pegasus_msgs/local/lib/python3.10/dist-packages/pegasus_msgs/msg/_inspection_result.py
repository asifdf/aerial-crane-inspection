# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pegasus_msgs:msg/InspectionResult.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_InspectionResult(type):
    """Metaclass of message 'InspectionResult'."""

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
                'pegasus_msgs.msg.InspectionResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__inspection_result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__inspection_result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__inspection_result
            cls._TYPE_SUPPORT = module.type_support_msg__msg__inspection_result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__inspection_result

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

            from pegasus_msgs.msg import DefectArray
            if DefectArray.__class__._TYPE_SUPPORT is None:
                DefectArray.__class__.__import_type_support__()

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


class InspectionResult(metaclass=Metaclass_InspectionResult):
    """Message class 'InspectionResult'."""

    __slots__ = [
        '_header',
        '_drone_id',
        '_mission_id',
        '_zone_id',
        '_drone_pose',
        '_defects',
        '_coverage_percent',
        '_images_captured',
        '_images_with_defects',
        '_zone_risk_level',
        '_zone_risk_id',
        '_json_payload',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'drone_id': 'string',
        'mission_id': 'string',
        'zone_id': 'string',
        'drone_pose': 'geometry_msgs/PoseStamped',
        'defects': 'pegasus_msgs/DefectArray',
        'coverage_percent': 'float',
        'images_captured': 'uint32',
        'images_with_defects': 'uint32',
        'zone_risk_level': 'string',
        'zone_risk_id': 'uint8',
        'json_payload': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['pegasus_msgs', 'msg'], 'DefectArray'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.drone_id = kwargs.get('drone_id', str())
        self.mission_id = kwargs.get('mission_id', str())
        self.zone_id = kwargs.get('zone_id', str())
        from geometry_msgs.msg import PoseStamped
        self.drone_pose = kwargs.get('drone_pose', PoseStamped())
        from pegasus_msgs.msg import DefectArray
        self.defects = kwargs.get('defects', DefectArray())
        self.coverage_percent = kwargs.get('coverage_percent', float())
        self.images_captured = kwargs.get('images_captured', int())
        self.images_with_defects = kwargs.get('images_with_defects', int())
        self.zone_risk_level = kwargs.get('zone_risk_level', str())
        self.zone_risk_id = kwargs.get('zone_risk_id', int())
        self.json_payload = kwargs.get('json_payload', str())

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
        if self.mission_id != other.mission_id:
            return False
        if self.zone_id != other.zone_id:
            return False
        if self.drone_pose != other.drone_pose:
            return False
        if self.defects != other.defects:
            return False
        if self.coverage_percent != other.coverage_percent:
            return False
        if self.images_captured != other.images_captured:
            return False
        if self.images_with_defects != other.images_with_defects:
            return False
        if self.zone_risk_level != other.zone_risk_level:
            return False
        if self.zone_risk_id != other.zone_risk_id:
            return False
        if self.json_payload != other.json_payload:
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
    def mission_id(self):
        """Message field 'mission_id'."""
        return self._mission_id

    @mission_id.setter
    def mission_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'mission_id' field must be of type 'str'"
        self._mission_id = value

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
    def drone_pose(self):
        """Message field 'drone_pose'."""
        return self._drone_pose

    @drone_pose.setter
    def drone_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'drone_pose' field must be a sub message of type 'PoseStamped'"
        self._drone_pose = value

    @builtins.property
    def defects(self):
        """Message field 'defects'."""
        return self._defects

    @defects.setter
    def defects(self, value):
        if __debug__:
            from pegasus_msgs.msg import DefectArray
            assert \
                isinstance(value, DefectArray), \
                "The 'defects' field must be a sub message of type 'DefectArray'"
        self._defects = value

    @builtins.property
    def coverage_percent(self):
        """Message field 'coverage_percent'."""
        return self._coverage_percent

    @coverage_percent.setter
    def coverage_percent(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'coverage_percent' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'coverage_percent' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._coverage_percent = value

    @builtins.property
    def images_captured(self):
        """Message field 'images_captured'."""
        return self._images_captured

    @images_captured.setter
    def images_captured(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'images_captured' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'images_captured' field must be an unsigned integer in [0, 4294967295]"
        self._images_captured = value

    @builtins.property
    def images_with_defects(self):
        """Message field 'images_with_defects'."""
        return self._images_with_defects

    @images_with_defects.setter
    def images_with_defects(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'images_with_defects' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'images_with_defects' field must be an unsigned integer in [0, 4294967295]"
        self._images_with_defects = value

    @builtins.property
    def zone_risk_level(self):
        """Message field 'zone_risk_level'."""
        return self._zone_risk_level

    @zone_risk_level.setter
    def zone_risk_level(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'zone_risk_level' field must be of type 'str'"
        self._zone_risk_level = value

    @builtins.property
    def zone_risk_id(self):
        """Message field 'zone_risk_id'."""
        return self._zone_risk_id

    @zone_risk_id.setter
    def zone_risk_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'zone_risk_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'zone_risk_id' field must be an unsigned integer in [0, 255]"
        self._zone_risk_id = value

    @builtins.property
    def json_payload(self):
        """Message field 'json_payload'."""
        return self._json_payload

    @json_payload.setter
    def json_payload(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'json_payload' field must be of type 'str'"
        self._json_payload = value
