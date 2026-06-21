# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pegasus_msgs:msg/ZoneInfo.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'waypoints_x'
# Member 'waypoints_y'
# Member 'waypoints_z'
# Member 'waypoints_yaw'
# Member 'camera_pitch'
# Member 'camera_yaw'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ZoneInfo(type):
    """Metaclass of message 'ZoneInfo'."""

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
                'pegasus_msgs.msg.ZoneInfo')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__zone_info
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__zone_info
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__zone_info
            cls._TYPE_SUPPORT = module.type_support_msg__msg__zone_info
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__zone_info

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

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


class ZoneInfo(metaclass=Metaclass_ZoneInfo):
    """Message class 'ZoneInfo'."""

    __slots__ = [
        '_header',
        '_zone_id',
        '_zone_name',
        '_zone_type',
        '_zone_center',
        '_zone_dimensions',
        '_waypoints_x',
        '_waypoints_y',
        '_waypoints_z',
        '_waypoints_yaw',
        '_camera_pitch',
        '_camera_yaw',
        '_expected_defects',
        '_priority',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'zone_id': 'string',
        'zone_name': 'string',
        'zone_type': 'string',
        'zone_center': 'geometry_msgs/Pose',
        'zone_dimensions': 'geometry_msgs/Vector3',
        'waypoints_x': 'sequence<float>',
        'waypoints_y': 'sequence<float>',
        'waypoints_z': 'sequence<float>',
        'waypoints_yaw': 'sequence<float>',
        'camera_pitch': 'sequence<float>',
        'camera_yaw': 'sequence<float>',
        'expected_defects': 'sequence<string>',
        'priority': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.zone_id = kwargs.get('zone_id', str())
        self.zone_name = kwargs.get('zone_name', str())
        self.zone_type = kwargs.get('zone_type', str())
        from geometry_msgs.msg import Pose
        self.zone_center = kwargs.get('zone_center', Pose())
        from geometry_msgs.msg import Vector3
        self.zone_dimensions = kwargs.get('zone_dimensions', Vector3())
        self.waypoints_x = array.array('f', kwargs.get('waypoints_x', []))
        self.waypoints_y = array.array('f', kwargs.get('waypoints_y', []))
        self.waypoints_z = array.array('f', kwargs.get('waypoints_z', []))
        self.waypoints_yaw = array.array('f', kwargs.get('waypoints_yaw', []))
        self.camera_pitch = array.array('f', kwargs.get('camera_pitch', []))
        self.camera_yaw = array.array('f', kwargs.get('camera_yaw', []))
        self.expected_defects = kwargs.get('expected_defects', [])
        self.priority = kwargs.get('priority', int())

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
        if self.zone_id != other.zone_id:
            return False
        if self.zone_name != other.zone_name:
            return False
        if self.zone_type != other.zone_type:
            return False
        if self.zone_center != other.zone_center:
            return False
        if self.zone_dimensions != other.zone_dimensions:
            return False
        if self.waypoints_x != other.waypoints_x:
            return False
        if self.waypoints_y != other.waypoints_y:
            return False
        if self.waypoints_z != other.waypoints_z:
            return False
        if self.waypoints_yaw != other.waypoints_yaw:
            return False
        if self.camera_pitch != other.camera_pitch:
            return False
        if self.camera_yaw != other.camera_yaw:
            return False
        if self.expected_defects != other.expected_defects:
            return False
        if self.priority != other.priority:
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
    def zone_name(self):
        """Message field 'zone_name'."""
        return self._zone_name

    @zone_name.setter
    def zone_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'zone_name' field must be of type 'str'"
        self._zone_name = value

    @builtins.property
    def zone_type(self):
        """Message field 'zone_type'."""
        return self._zone_type

    @zone_type.setter
    def zone_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'zone_type' field must be of type 'str'"
        self._zone_type = value

    @builtins.property
    def zone_center(self):
        """Message field 'zone_center'."""
        return self._zone_center

    @zone_center.setter
    def zone_center(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'zone_center' field must be a sub message of type 'Pose'"
        self._zone_center = value

    @builtins.property
    def zone_dimensions(self):
        """Message field 'zone_dimensions'."""
        return self._zone_dimensions

    @zone_dimensions.setter
    def zone_dimensions(self, value):
        if __debug__:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'zone_dimensions' field must be a sub message of type 'Vector3'"
        self._zone_dimensions = value

    @builtins.property
    def waypoints_x(self):
        """Message field 'waypoints_x'."""
        return self._waypoints_x

    @waypoints_x.setter
    def waypoints_x(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'waypoints_x' array.array() must have the type code of 'f'"
            self._waypoints_x = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'waypoints_x' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._waypoints_x = array.array('f', value)

    @builtins.property
    def waypoints_y(self):
        """Message field 'waypoints_y'."""
        return self._waypoints_y

    @waypoints_y.setter
    def waypoints_y(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'waypoints_y' array.array() must have the type code of 'f'"
            self._waypoints_y = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'waypoints_y' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._waypoints_y = array.array('f', value)

    @builtins.property
    def waypoints_z(self):
        """Message field 'waypoints_z'."""
        return self._waypoints_z

    @waypoints_z.setter
    def waypoints_z(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'waypoints_z' array.array() must have the type code of 'f'"
            self._waypoints_z = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'waypoints_z' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._waypoints_z = array.array('f', value)

    @builtins.property
    def waypoints_yaw(self):
        """Message field 'waypoints_yaw'."""
        return self._waypoints_yaw

    @waypoints_yaw.setter
    def waypoints_yaw(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'waypoints_yaw' array.array() must have the type code of 'f'"
            self._waypoints_yaw = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'waypoints_yaw' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._waypoints_yaw = array.array('f', value)

    @builtins.property
    def camera_pitch(self):
        """Message field 'camera_pitch'."""
        return self._camera_pitch

    @camera_pitch.setter
    def camera_pitch(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'camera_pitch' array.array() must have the type code of 'f'"
            self._camera_pitch = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'camera_pitch' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._camera_pitch = array.array('f', value)

    @builtins.property
    def camera_yaw(self):
        """Message field 'camera_yaw'."""
        return self._camera_yaw

    @camera_yaw.setter
    def camera_yaw(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'camera_yaw' array.array() must have the type code of 'f'"
            self._camera_yaw = value
            return
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
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'camera_yaw' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._camera_yaw = array.array('f', value)

    @builtins.property
    def expected_defects(self):
        """Message field 'expected_defects'."""
        return self._expected_defects

    @expected_defects.setter
    def expected_defects(self, value):
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
                "The 'expected_defects' field must be a set or sequence and each value of type 'str'"
        self._expected_defects = value

    @builtins.property
    def priority(self):
        """Message field 'priority'."""
        return self._priority

    @priority.setter
    def priority(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'priority' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'priority' field must be an unsigned integer in [0, 255]"
        self._priority = value
