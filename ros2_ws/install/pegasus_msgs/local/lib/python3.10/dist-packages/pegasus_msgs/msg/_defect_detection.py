# generated from rosidl_generator_py/resource/_idl.py.em
# with input from pegasus_msgs:msg/DefectDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DefectDetection(type):
    """Metaclass of message 'DefectDetection'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_CRACK': 0,
        'CLASS_CORROSION': 1,
        'CLASS_PAINT_DAMAGE': 2,
        'RISK_LOW': 0,
        'RISK_MEDIUM': 1,
        'RISK_HIGH': 2,
        'RISK_CRITICAL': 3,
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
                'pegasus_msgs.msg.DefectDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__defect_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__defect_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__defect_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__defect_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__defect_detection

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from sensor_msgs.msg import CompressedImage
            if CompressedImage.__class__._TYPE_SUPPORT is None:
                CompressedImage.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_CRACK': cls.__constants['CLASS_CRACK'],
            'CLASS_CORROSION': cls.__constants['CLASS_CORROSION'],
            'CLASS_PAINT_DAMAGE': cls.__constants['CLASS_PAINT_DAMAGE'],
            'RISK_LOW': cls.__constants['RISK_LOW'],
            'RISK_MEDIUM': cls.__constants['RISK_MEDIUM'],
            'RISK_HIGH': cls.__constants['RISK_HIGH'],
            'RISK_CRITICAL': cls.__constants['RISK_CRITICAL'],
        }

    @property
    def CLASS_CRACK(self):
        """Message constant 'CLASS_CRACK'."""
        return Metaclass_DefectDetection.__constants['CLASS_CRACK']

    @property
    def CLASS_CORROSION(self):
        """Message constant 'CLASS_CORROSION'."""
        return Metaclass_DefectDetection.__constants['CLASS_CORROSION']

    @property
    def CLASS_PAINT_DAMAGE(self):
        """Message constant 'CLASS_PAINT_DAMAGE'."""
        return Metaclass_DefectDetection.__constants['CLASS_PAINT_DAMAGE']

    @property
    def RISK_LOW(self):
        """Message constant 'RISK_LOW'."""
        return Metaclass_DefectDetection.__constants['RISK_LOW']

    @property
    def RISK_MEDIUM(self):
        """Message constant 'RISK_MEDIUM'."""
        return Metaclass_DefectDetection.__constants['RISK_MEDIUM']

    @property
    def RISK_HIGH(self):
        """Message constant 'RISK_HIGH'."""
        return Metaclass_DefectDetection.__constants['RISK_HIGH']

    @property
    def RISK_CRITICAL(self):
        """Message constant 'RISK_CRITICAL'."""
        return Metaclass_DefectDetection.__constants['RISK_CRITICAL']


class DefectDetection(metaclass=Metaclass_DefectDetection):
    """
    Message class 'DefectDetection'.

    Constants:
      CLASS_CRACK
      CLASS_CORROSION
      CLASS_PAINT_DAMAGE
      RISK_LOW
      RISK_MEDIUM
      RISK_HIGH
      RISK_CRITICAL
    """

    __slots__ = [
        '_header',
        '_type',
        '_class_id',
        '_confidence',
        '_bbox_x',
        '_bbox_y',
        '_bbox_width',
        '_bbox_height',
        '_bbox_x_norm',
        '_bbox_y_norm',
        '_bbox_width_norm',
        '_bbox_height_norm',
        '_risk_level',
        '_risk_id',
        '_mask',
        '_position_3d',
        '_has_3d_position',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'type': 'string',
        'class_id': 'uint8',
        'confidence': 'float',
        'bbox_x': 'float',
        'bbox_y': 'float',
        'bbox_width': 'float',
        'bbox_height': 'float',
        'bbox_x_norm': 'float',
        'bbox_y_norm': 'float',
        'bbox_width_norm': 'float',
        'bbox_height_norm': 'float',
        'risk_level': 'string',
        'risk_id': 'uint8',
        'mask': 'sensor_msgs/CompressedImage',
        'position_3d': 'geometry_msgs/Point',
        'has_3d_position': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'CompressedImage'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.type = kwargs.get('type', str())
        self.class_id = kwargs.get('class_id', int())
        self.confidence = kwargs.get('confidence', float())
        self.bbox_x = kwargs.get('bbox_x', float())
        self.bbox_y = kwargs.get('bbox_y', float())
        self.bbox_width = kwargs.get('bbox_width', float())
        self.bbox_height = kwargs.get('bbox_height', float())
        self.bbox_x_norm = kwargs.get('bbox_x_norm', float())
        self.bbox_y_norm = kwargs.get('bbox_y_norm', float())
        self.bbox_width_norm = kwargs.get('bbox_width_norm', float())
        self.bbox_height_norm = kwargs.get('bbox_height_norm', float())
        self.risk_level = kwargs.get('risk_level', str())
        self.risk_id = kwargs.get('risk_id', int())
        from sensor_msgs.msg import CompressedImage
        self.mask = kwargs.get('mask', CompressedImage())
        from geometry_msgs.msg import Point
        self.position_3d = kwargs.get('position_3d', Point())
        self.has_3d_position = kwargs.get('has_3d_position', bool())

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
        if self.type != other.type:
            return False
        if self.class_id != other.class_id:
            return False
        if self.confidence != other.confidence:
            return False
        if self.bbox_x != other.bbox_x:
            return False
        if self.bbox_y != other.bbox_y:
            return False
        if self.bbox_width != other.bbox_width:
            return False
        if self.bbox_height != other.bbox_height:
            return False
        if self.bbox_x_norm != other.bbox_x_norm:
            return False
        if self.bbox_y_norm != other.bbox_y_norm:
            return False
        if self.bbox_width_norm != other.bbox_width_norm:
            return False
        if self.bbox_height_norm != other.bbox_height_norm:
            return False
        if self.risk_level != other.risk_level:
            return False
        if self.risk_id != other.risk_id:
            return False
        if self.mask != other.mask:
            return False
        if self.position_3d != other.position_3d:
            return False
        if self.has_3d_position != other.has_3d_position:
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

    @builtins.property  # noqa: A003
    def type(self):  # noqa: A003
        """Message field 'type'."""
        return self._type

    @type.setter  # noqa: A003
    def type(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'type' field must be of type 'str'"
        self._type = value

    @builtins.property
    def class_id(self):
        """Message field 'class_id'."""
        return self._class_id

    @class_id.setter
    def class_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'class_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'class_id' field must be an unsigned integer in [0, 255]"
        self._class_id = value

    @builtins.property
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'confidence' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._confidence = value

    @builtins.property
    def bbox_x(self):
        """Message field 'bbox_x'."""
        return self._bbox_x

    @bbox_x.setter
    def bbox_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_x = value

    @builtins.property
    def bbox_y(self):
        """Message field 'bbox_y'."""
        return self._bbox_y

    @bbox_y.setter
    def bbox_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_y = value

    @builtins.property
    def bbox_width(self):
        """Message field 'bbox_width'."""
        return self._bbox_width

    @bbox_width.setter
    def bbox_width(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_width' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_width' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_width = value

    @builtins.property
    def bbox_height(self):
        """Message field 'bbox_height'."""
        return self._bbox_height

    @bbox_height.setter
    def bbox_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_height' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_height' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_height = value

    @builtins.property
    def bbox_x_norm(self):
        """Message field 'bbox_x_norm'."""
        return self._bbox_x_norm

    @bbox_x_norm.setter
    def bbox_x_norm(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_x_norm' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_x_norm' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_x_norm = value

    @builtins.property
    def bbox_y_norm(self):
        """Message field 'bbox_y_norm'."""
        return self._bbox_y_norm

    @bbox_y_norm.setter
    def bbox_y_norm(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_y_norm' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_y_norm' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_y_norm = value

    @builtins.property
    def bbox_width_norm(self):
        """Message field 'bbox_width_norm'."""
        return self._bbox_width_norm

    @bbox_width_norm.setter
    def bbox_width_norm(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_width_norm' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_width_norm' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_width_norm = value

    @builtins.property
    def bbox_height_norm(self):
        """Message field 'bbox_height_norm'."""
        return self._bbox_height_norm

    @bbox_height_norm.setter
    def bbox_height_norm(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'bbox_height_norm' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'bbox_height_norm' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._bbox_height_norm = value

    @builtins.property
    def risk_level(self):
        """Message field 'risk_level'."""
        return self._risk_level

    @risk_level.setter
    def risk_level(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'risk_level' field must be of type 'str'"
        self._risk_level = value

    @builtins.property
    def risk_id(self):
        """Message field 'risk_id'."""
        return self._risk_id

    @risk_id.setter
    def risk_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'risk_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'risk_id' field must be an unsigned integer in [0, 255]"
        self._risk_id = value

    @builtins.property
    def mask(self):
        """Message field 'mask'."""
        return self._mask

    @mask.setter
    def mask(self, value):
        if __debug__:
            from sensor_msgs.msg import CompressedImage
            assert \
                isinstance(value, CompressedImage), \
                "The 'mask' field must be a sub message of type 'CompressedImage'"
        self._mask = value

    @builtins.property
    def position_3d(self):
        """Message field 'position_3d'."""
        return self._position_3d

    @position_3d.setter
    def position_3d(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'position_3d' field must be a sub message of type 'Point'"
        self._position_3d = value

    @builtins.property
    def has_3d_position(self):
        """Message field 'has_3d_position'."""
        return self._has_3d_position

    @has_3d_position.setter
    def has_3d_position(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'has_3d_position' field must be of type 'bool'"
        self._has_3d_position = value
