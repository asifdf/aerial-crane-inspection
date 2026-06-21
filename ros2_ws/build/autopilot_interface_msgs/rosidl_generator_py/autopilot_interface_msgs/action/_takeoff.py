# generated from rosidl_generator_py/resource/_idl.py.em
# with input from autopilot_interface_msgs:action/Takeoff.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Takeoff_Goal(type):
    """Metaclass of message 'Takeoff_Goal'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TAKEOFF_ALTITUDE__DEFAULT': 50.0,
            'VTOL_TRANSITION_HEADING__DEFAULT': 90.0,
            'VTOL_LOITER_NORD__DEFAULT': 150.0,
            'VTOL_LOITER_EAST__DEFAULT': 0.0,
            'VTOL_LOITER_ALT__DEFAULT': 100.0,
        }

    @property
    def TAKEOFF_ALTITUDE__DEFAULT(cls):
        """Return default value for message field 'takeoff_altitude'."""
        return 50.0

    @property
    def VTOL_TRANSITION_HEADING__DEFAULT(cls):
        """Return default value for message field 'vtol_transition_heading'."""
        return 90.0

    @property
    def VTOL_LOITER_NORD__DEFAULT(cls):
        """Return default value for message field 'vtol_loiter_nord'."""
        return 150.0

    @property
    def VTOL_LOITER_EAST__DEFAULT(cls):
        """Return default value for message field 'vtol_loiter_east'."""
        return 0.0

    @property
    def VTOL_LOITER_ALT__DEFAULT(cls):
        """Return default value for message field 'vtol_loiter_alt'."""
        return 100.0


class Takeoff_Goal(metaclass=Metaclass_Takeoff_Goal):
    """Message class 'Takeoff_Goal'."""

    __slots__ = [
        '_takeoff_altitude',
        '_vtol_transition_heading',
        '_vtol_loiter_nord',
        '_vtol_loiter_east',
        '_vtol_loiter_alt',
    ]

    _fields_and_field_types = {
        'takeoff_altitude': 'double',
        'vtol_transition_heading': 'double',
        'vtol_loiter_nord': 'double',
        'vtol_loiter_east': 'double',
        'vtol_loiter_alt': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.takeoff_altitude = kwargs.get(
            'takeoff_altitude', Takeoff_Goal.TAKEOFF_ALTITUDE__DEFAULT)
        self.vtol_transition_heading = kwargs.get(
            'vtol_transition_heading', Takeoff_Goal.VTOL_TRANSITION_HEADING__DEFAULT)
        self.vtol_loiter_nord = kwargs.get(
            'vtol_loiter_nord', Takeoff_Goal.VTOL_LOITER_NORD__DEFAULT)
        self.vtol_loiter_east = kwargs.get(
            'vtol_loiter_east', Takeoff_Goal.VTOL_LOITER_EAST__DEFAULT)
        self.vtol_loiter_alt = kwargs.get(
            'vtol_loiter_alt', Takeoff_Goal.VTOL_LOITER_ALT__DEFAULT)

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
        if self.takeoff_altitude != other.takeoff_altitude:
            return False
        if self.vtol_transition_heading != other.vtol_transition_heading:
            return False
        if self.vtol_loiter_nord != other.vtol_loiter_nord:
            return False
        if self.vtol_loiter_east != other.vtol_loiter_east:
            return False
        if self.vtol_loiter_alt != other.vtol_loiter_alt:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def takeoff_altitude(self):
        """Message field 'takeoff_altitude'."""
        return self._takeoff_altitude

    @takeoff_altitude.setter
    def takeoff_altitude(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'takeoff_altitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'takeoff_altitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._takeoff_altitude = value

    @builtins.property
    def vtol_transition_heading(self):
        """Message field 'vtol_transition_heading'."""
        return self._vtol_transition_heading

    @vtol_transition_heading.setter
    def vtol_transition_heading(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vtol_transition_heading' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vtol_transition_heading' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vtol_transition_heading = value

    @builtins.property
    def vtol_loiter_nord(self):
        """Message field 'vtol_loiter_nord'."""
        return self._vtol_loiter_nord

    @vtol_loiter_nord.setter
    def vtol_loiter_nord(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vtol_loiter_nord' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vtol_loiter_nord' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vtol_loiter_nord = value

    @builtins.property
    def vtol_loiter_east(self):
        """Message field 'vtol_loiter_east'."""
        return self._vtol_loiter_east

    @vtol_loiter_east.setter
    def vtol_loiter_east(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vtol_loiter_east' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vtol_loiter_east' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vtol_loiter_east = value

    @builtins.property
    def vtol_loiter_alt(self):
        """Message field 'vtol_loiter_alt'."""
        return self._vtol_loiter_alt

    @vtol_loiter_alt.setter
    def vtol_loiter_alt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vtol_loiter_alt' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vtol_loiter_alt' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vtol_loiter_alt = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Takeoff_Result(type):
    """Metaclass of message 'Takeoff_Result'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Takeoff_Result(metaclass=Metaclass_Takeoff_Result):
    """Message class 'Takeoff_Result'."""

    __slots__ = [
        '_success',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())

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
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Takeoff_Feedback(type):
    """Metaclass of message 'Takeoff_Feedback'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Takeoff_Feedback(metaclass=Metaclass_Takeoff_Feedback):
    """Message class 'Takeoff_Feedback'."""

    __slots__ = [
        '_message',
    ]

    _fields_and_field_types = {
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.message = kwargs.get('message', str())

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
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Takeoff_SendGoal_Request(type):
    """Metaclass of message 'Takeoff_SendGoal_Request'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__send_goal__request

            from autopilot_interface_msgs.action import Takeoff
            if Takeoff.Goal.__class__._TYPE_SUPPORT is None:
                Takeoff.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Takeoff_SendGoal_Request(metaclass=Metaclass_Takeoff_SendGoal_Request):
    """Message class 'Takeoff_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'autopilot_interface_msgs/Takeoff_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['autopilot_interface_msgs', 'action'], 'Takeoff_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from autopilot_interface_msgs.action._takeoff import Takeoff_Goal
        self.goal = kwargs.get('goal', Takeoff_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from autopilot_interface_msgs.action._takeoff import Takeoff_Goal
            assert \
                isinstance(value, Takeoff_Goal), \
                "The 'goal' field must be a sub message of type 'Takeoff_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Takeoff_SendGoal_Response(type):
    """Metaclass of message 'Takeoff_SendGoal_Response'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Takeoff_SendGoal_Response(metaclass=Metaclass_Takeoff_SendGoal_Response):
    """Message class 'Takeoff_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_Takeoff_SendGoal(type):
    """Metaclass of service 'Takeoff_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__takeoff__send_goal

            from autopilot_interface_msgs.action import _takeoff
            if _takeoff.Metaclass_Takeoff_SendGoal_Request._TYPE_SUPPORT is None:
                _takeoff.Metaclass_Takeoff_SendGoal_Request.__import_type_support__()
            if _takeoff.Metaclass_Takeoff_SendGoal_Response._TYPE_SUPPORT is None:
                _takeoff.Metaclass_Takeoff_SendGoal_Response.__import_type_support__()


class Takeoff_SendGoal(metaclass=Metaclass_Takeoff_SendGoal):
    from autopilot_interface_msgs.action._takeoff import Takeoff_SendGoal_Request as Request
    from autopilot_interface_msgs.action._takeoff import Takeoff_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Takeoff_GetResult_Request(type):
    """Metaclass of message 'Takeoff_GetResult_Request'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Takeoff_GetResult_Request(metaclass=Metaclass_Takeoff_GetResult_Request):
    """Message class 'Takeoff_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Takeoff_GetResult_Response(type):
    """Metaclass of message 'Takeoff_GetResult_Response'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__get_result__response

            from autopilot_interface_msgs.action import Takeoff
            if Takeoff.Result.__class__._TYPE_SUPPORT is None:
                Takeoff.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Takeoff_GetResult_Response(metaclass=Metaclass_Takeoff_GetResult_Response):
    """Message class 'Takeoff_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'autopilot_interface_msgs/Takeoff_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['autopilot_interface_msgs', 'action'], 'Takeoff_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from autopilot_interface_msgs.action._takeoff import Takeoff_Result
        self.result = kwargs.get('result', Takeoff_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from autopilot_interface_msgs.action._takeoff import Takeoff_Result
            assert \
                isinstance(value, Takeoff_Result), \
                "The 'result' field must be a sub message of type 'Takeoff_Result'"
        self._result = value


class Metaclass_Takeoff_GetResult(type):
    """Metaclass of service 'Takeoff_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__takeoff__get_result

            from autopilot_interface_msgs.action import _takeoff
            if _takeoff.Metaclass_Takeoff_GetResult_Request._TYPE_SUPPORT is None:
                _takeoff.Metaclass_Takeoff_GetResult_Request.__import_type_support__()
            if _takeoff.Metaclass_Takeoff_GetResult_Response._TYPE_SUPPORT is None:
                _takeoff.Metaclass_Takeoff_GetResult_Response.__import_type_support__()


class Takeoff_GetResult(metaclass=Metaclass_Takeoff_GetResult):
    from autopilot_interface_msgs.action._takeoff import Takeoff_GetResult_Request as Request
    from autopilot_interface_msgs.action._takeoff import Takeoff_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Takeoff_FeedbackMessage(type):
    """Metaclass of message 'Takeoff_FeedbackMessage'."""

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
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__takeoff__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__takeoff__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__takeoff__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__takeoff__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__takeoff__feedback_message

            from autopilot_interface_msgs.action import Takeoff
            if Takeoff.Feedback.__class__._TYPE_SUPPORT is None:
                Takeoff.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Takeoff_FeedbackMessage(metaclass=Metaclass_Takeoff_FeedbackMessage):
    """Message class 'Takeoff_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'autopilot_interface_msgs/Takeoff_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['autopilot_interface_msgs', 'action'], 'Takeoff_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from autopilot_interface_msgs.action._takeoff import Takeoff_Feedback
        self.feedback = kwargs.get('feedback', Takeoff_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from autopilot_interface_msgs.action._takeoff import Takeoff_Feedback
            assert \
                isinstance(value, Takeoff_Feedback), \
                "The 'feedback' field must be a sub message of type 'Takeoff_Feedback'"
        self._feedback = value


class Metaclass_Takeoff(type):
    """Metaclass of action 'Takeoff'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('autopilot_interface_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'autopilot_interface_msgs.action.Takeoff')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__takeoff

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from autopilot_interface_msgs.action import _takeoff
            if _takeoff.Metaclass_Takeoff_SendGoal._TYPE_SUPPORT is None:
                _takeoff.Metaclass_Takeoff_SendGoal.__import_type_support__()
            if _takeoff.Metaclass_Takeoff_GetResult._TYPE_SUPPORT is None:
                _takeoff.Metaclass_Takeoff_GetResult.__import_type_support__()
            if _takeoff.Metaclass_Takeoff_FeedbackMessage._TYPE_SUPPORT is None:
                _takeoff.Metaclass_Takeoff_FeedbackMessage.__import_type_support__()


class Takeoff(metaclass=Metaclass_Takeoff):

    # The goal message defined in the action definition.
    from autopilot_interface_msgs.action._takeoff import Takeoff_Goal as Goal
    # The result message defined in the action definition.
    from autopilot_interface_msgs.action._takeoff import Takeoff_Result as Result
    # The feedback message defined in the action definition.
    from autopilot_interface_msgs.action._takeoff import Takeoff_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from autopilot_interface_msgs.action._takeoff import Takeoff_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from autopilot_interface_msgs.action._takeoff import Takeoff_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from autopilot_interface_msgs.action._takeoff import Takeoff_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
