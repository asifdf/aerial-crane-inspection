// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autopilot_interface_msgs:action/Offboard.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__OFFBOARD__BUILDER_HPP_
#define AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__OFFBOARD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autopilot_interface_msgs/action/detail/offboard__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_Goal_max_duration_sec
{
public:
  explicit Init_Offboard_Goal_max_duration_sec(::autopilot_interface_msgs::action::Offboard_Goal & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Offboard_Goal max_duration_sec(::autopilot_interface_msgs::action::Offboard_Goal::_max_duration_sec_type arg)
  {
    msg_.max_duration_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_Goal msg_;
};

class Init_Offboard_Goal_offboard_setpoint_type
{
public:
  Init_Offboard_Goal_offboard_setpoint_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Offboard_Goal_max_duration_sec offboard_setpoint_type(::autopilot_interface_msgs::action::Offboard_Goal::_offboard_setpoint_type_type arg)
  {
    msg_.offboard_setpoint_type = std::move(arg);
    return Init_Offboard_Goal_max_duration_sec(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_Goal>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_Goal_offboard_setpoint_type();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_Result_success
{
public:
  Init_Offboard_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopilot_interface_msgs::action::Offboard_Result success(::autopilot_interface_msgs::action::Offboard_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_Result>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_Result_success();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_Feedback_message
{
public:
  Init_Offboard_Feedback_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopilot_interface_msgs::action::Offboard_Feedback message(::autopilot_interface_msgs::action::Offboard_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_Feedback>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_Feedback_message();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_SendGoal_Request_goal
{
public:
  explicit Init_Offboard_SendGoal_Request_goal(::autopilot_interface_msgs::action::Offboard_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Offboard_SendGoal_Request goal(::autopilot_interface_msgs::action::Offboard_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_SendGoal_Request msg_;
};

class Init_Offboard_SendGoal_Request_goal_id
{
public:
  Init_Offboard_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Offboard_SendGoal_Request_goal goal_id(::autopilot_interface_msgs::action::Offboard_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Offboard_SendGoal_Request_goal(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_SendGoal_Request>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_SendGoal_Request_goal_id();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_SendGoal_Response_stamp
{
public:
  explicit Init_Offboard_SendGoal_Response_stamp(::autopilot_interface_msgs::action::Offboard_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Offboard_SendGoal_Response stamp(::autopilot_interface_msgs::action::Offboard_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_SendGoal_Response msg_;
};

class Init_Offboard_SendGoal_Response_accepted
{
public:
  Init_Offboard_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Offboard_SendGoal_Response_stamp accepted(::autopilot_interface_msgs::action::Offboard_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Offboard_SendGoal_Response_stamp(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_SendGoal_Response>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_SendGoal_Response_accepted();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_GetResult_Request_goal_id
{
public:
  Init_Offboard_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopilot_interface_msgs::action::Offboard_GetResult_Request goal_id(::autopilot_interface_msgs::action::Offboard_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_GetResult_Request>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_GetResult_Request_goal_id();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_GetResult_Response_result
{
public:
  explicit Init_Offboard_GetResult_Response_result(::autopilot_interface_msgs::action::Offboard_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Offboard_GetResult_Response result(::autopilot_interface_msgs::action::Offboard_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_GetResult_Response msg_;
};

class Init_Offboard_GetResult_Response_status
{
public:
  Init_Offboard_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Offboard_GetResult_Response_result status(::autopilot_interface_msgs::action::Offboard_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Offboard_GetResult_Response_result(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_GetResult_Response>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_GetResult_Response_status();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Offboard_FeedbackMessage_feedback
{
public:
  explicit Init_Offboard_FeedbackMessage_feedback(::autopilot_interface_msgs::action::Offboard_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Offboard_FeedbackMessage feedback(::autopilot_interface_msgs::action::Offboard_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_FeedbackMessage msg_;
};

class Init_Offboard_FeedbackMessage_goal_id
{
public:
  Init_Offboard_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Offboard_FeedbackMessage_feedback goal_id(::autopilot_interface_msgs::action::Offboard_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Offboard_FeedbackMessage_feedback(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Offboard_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Offboard_FeedbackMessage>()
{
  return autopilot_interface_msgs::action::builder::Init_Offboard_FeedbackMessage_goal_id();
}

}  // namespace autopilot_interface_msgs

#endif  // AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__OFFBOARD__BUILDER_HPP_
