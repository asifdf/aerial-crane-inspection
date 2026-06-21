# generated from rosidl_generator_py/resource/_idl.py.em
# with input from autopilot_interface_msgs:msg/OffboardFlag.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_OffboardFlag(type):
    """Metaclass of message 'OffboardFlag'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'INACTIVE': 0,
        'PX4_QUAD_ATTITUDE': 1,
        'PX4_VTOL_ATTITUDE': 2,
        'PX4_QUAD_RATES': 3,
        'PX4_VTOL_RATES': 4,
        'PX4_QUAD_TRAJECTORY': 5,
        'PX4_VTOL_TRAJECTORY': 6,
        'AP_QUAD_VELOCITY': 7,
        'AP_QUAD_ACCELERATION': 8,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.msg.OffboardFlag')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__offboard_flag
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__offboard_flag
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__offboard_flag
            cls._TYPE_SUPPORT = module.type_support_msg__msg__offboard_flag
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__offboard_flag

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'INACTIVE': cls.__constants['INACTIVE'],
            'PX4_QUAD_ATTITUDE': cls.__constants['PX4_QUAD_ATTITUDE'],
            'PX4_VTOL_ATTITUDE': cls.__constants['PX4_VTOL_ATTITUDE'],
            'PX4_QUAD_RATES': cls.__constants['PX4_QUAD_RATES'],
            'PX4_VTOL_RATES': cls.__constants['PX4_VTOL_RATES'],
            'PX4_QUAD_TRAJECTORY': cls.__constants['PX4_QUAD_TRAJECTORY'],
            'PX4_VTOL_TRAJECTORY': cls.__constants['PX4_VTOL_TRAJECTORY'],
            'AP_QUAD_VELOCITY': cls.__constants['AP_QUAD_VELOCITY'],
            'AP_QUAD_ACCELERATION': cls.__constants['AP_QUAD_ACCELERATION'],
        }

    @property
    def INACTIVE(self):
        """Message constant 'INACTIVE'."""
        return Metaclass_OffboardFlag.__constants['INACTIVE']

    @property
    def PX4_QUAD_ATTITUDE(self):
        """Message constant 'PX4_QUAD_ATTITUDE'."""
        return Metaclass_OffboardFlag.__constants['PX4_QUAD_ATTITUDE']

    @property
    def PX4_VTOL_ATTITUDE(self):
        """Message constant 'PX4_VTOL_ATTITUDE'."""
        return Metaclass_OffboardFlag.__constants['PX4_VTOL_ATTITUDE']

    @property
    def PX4_QUAD_RATES(self):
        """Message constant 'PX4_QUAD_RATES'."""
        return Metaclass_OffboardFlag.__constants['PX4_QUAD_RATES']

    @property
    def PX4_VTOL_RATES(self):
        """Message constant 'PX4_VTOL_RATES'."""
        return Metaclass_OffboardFlag.__constants['PX4_VTOL_RATES']

    @property
    def PX4_QUAD_TRAJECTORY(self):
        """Message constant 'PX4_QUAD_TRAJECTORY'."""
        return Metaclass_OffboardFlag.__constants['PX4_QUAD_TRAJECTORY']

    @property
    def PX4_VTOL_TRAJECTORY(self):
        """Message constant 'PX4_VTOL_TRAJECTORY'."""
        return Metaclass_OffboardFlag.__constants['PX4_VTOL_TRAJECTORY']

    @property
    def AP_QUAD_VELOCITY(self):
        """Message constant 'AP_QUAD_VELOCITY'."""
        return Metaclass_OffboardFlag.__constants['AP_QUAD_VELOCITY']

    @property
    def AP_QUAD_ACCELERATION(self):
        """Message constant 'AP_QUAD_ACCELERATION'."""
        return Metaclass_OffboardFlag.__constants['AP_QUAD_ACCELERATION']


class OffboardFlag(metaclass=Metaclass_OffboardFlag):
    """
    Message class 'OffboardFlag'.

    Constants:
      INACTIVE
      PX4_QUAD_ATTITUDE
      PX4_VTOL_ATTITUDE
      PX4_QUAD_RATES
      PX4_VTOL_RATES
      PX4_QUAD_TRAJECTORY
      PX4_VTOL_TRAJECTORY
      AP_QUAD_VELOCITY
      AP_QUAD_ACCELERATION
    """

    __slots__ = [
        '_offboard_flag',
    ]

    _fields_and_field_types = {
        'offboard_flag': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.offboard_flag = kwargs.get('offboard_flag', int())

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
        if self.offboard_flag != other.offboard_flag:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def offboard_flag(self):
        """Message field 'offboard_flag'."""
        return self._offboard_flag

    @offboard_flag.setter
    def offboard_flag(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'offboard_flag' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'offboard_flag' field must be an unsigned integer in [0, 255]"
        self._offboard_flag = value
