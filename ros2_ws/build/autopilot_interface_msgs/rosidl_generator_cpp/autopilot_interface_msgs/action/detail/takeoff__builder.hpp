// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autopilot_interface_msgs:action/Takeoff.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__TAKEOFF__BUILDER_HPP_
#define AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__TAKEOFF__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autopilot_interface_msgs/action/detail/takeoff__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_Goal_vtol_loiter_alt
{
public:
  explicit Init_Takeoff_Goal_vtol_loiter_alt(::autopilot_interface_msgs::action::Takeoff_Goal & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Takeoff_Goal vtol_loiter_alt(::autopilot_interface_msgs::action::Takeoff_Goal::_vtol_loiter_alt_type arg)
  {
    msg_.vtol_loiter_alt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_Goal msg_;
};

class Init_Takeoff_Goal_vtol_loiter_east
{
public:
  explicit Init_Takeoff_Goal_vtol_loiter_east(::autopilot_interface_msgs::action::Takeoff_Goal & msg)
  : msg_(msg)
  {}
  Init_Takeoff_Goal_vtol_loiter_alt vtol_loiter_east(::autopilot_interface_msgs::action::Takeoff_Goal::_vtol_loiter_east_type arg)
  {
    msg_.vtol_loiter_east = std::move(arg);
    return Init_Takeoff_Goal_vtol_loiter_alt(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_Goal msg_;
};

class Init_Takeoff_Goal_vtol_loiter_nord
{
public:
  explicit Init_Takeoff_Goal_vtol_loiter_nord(::autopilot_interface_msgs::action::Takeoff_Goal & msg)
  : msg_(msg)
  {}
  Init_Takeoff_Goal_vtol_loiter_east vtol_loiter_nord(::autopilot_interface_msgs::action::Takeoff_Goal::_vtol_loiter_nord_type arg)
  {
    msg_.vtol_loiter_nord = std::move(arg);
    return Init_Takeoff_Goal_vtol_loiter_east(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_Goal msg_;
};

class Init_Takeoff_Goal_vtol_transition_heading
{
public:
  explicit Init_Takeoff_Goal_vtol_transition_heading(::autopilot_interface_msgs::action::Takeoff_Goal & msg)
  : msg_(msg)
  {}
  Init_Takeoff_Goal_vtol_loiter_nord vtol_transition_heading(::autopilot_interface_msgs::action::Takeoff_Goal::_vtol_transition_heading_type arg)
  {
    msg_.vtol_transition_heading = std::move(arg);
    return Init_Takeoff_Goal_vtol_loiter_nord(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_Goal msg_;
};

class Init_Takeoff_Goal_takeoff_altitude
{
public:
  Init_Takeoff_Goal_takeoff_altitude()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Takeoff_Goal_vtol_transition_heading takeoff_altitude(::autopilot_interface_msgs::action::Takeoff_Goal::_takeoff_altitude_type arg)
  {
    msg_.takeoff_altitude = std::move(arg);
    return Init_Takeoff_Goal_vtol_transition_heading(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_Goal>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_Goal_takeoff_altitude();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_Result_success
{
public:
  Init_Takeoff_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopilot_interface_msgs::action::Takeoff_Result success(::autopilot_interface_msgs::action::Takeoff_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_Result>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_Result_success();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_Feedback_message
{
public:
  Init_Takeoff_Feedback_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopilot_interface_msgs::action::Takeoff_Feedback message(::autopilot_interface_msgs::action::Takeoff_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_Feedback>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_Feedback_message();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_SendGoal_Request_goal
{
public:
  explicit Init_Takeoff_SendGoal_Request_goal(::autopilot_interface_msgs::action::Takeoff_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Takeoff_SendGoal_Request goal(::autopilot_interface_msgs::action::Takeoff_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_SendGoal_Request msg_;
};

class Init_Takeoff_SendGoal_Request_goal_id
{
public:
  Init_Takeoff_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Takeoff_SendGoal_Request_goal goal_id(::autopilot_interface_msgs::action::Takeoff_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Takeoff_SendGoal_Request_goal(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_SendGoal_Request>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_SendGoal_Request_goal_id();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_SendGoal_Response_stamp
{
public:
  explicit Init_Takeoff_SendGoal_Response_stamp(::autopilot_interface_msgs::action::Takeoff_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Takeoff_SendGoal_Response stamp(::autopilot_interface_msgs::action::Takeoff_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_SendGoal_Response msg_;
};

class Init_Takeoff_SendGoal_Response_accepted
{
public:
  Init_Takeoff_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Takeoff_SendGoal_Response_stamp accepted(::autopilot_interface_msgs::action::Takeoff_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Takeoff_SendGoal_Response_stamp(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_SendGoal_Response>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_SendGoal_Response_accepted();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_GetResult_Request_goal_id
{
public:
  Init_Takeoff_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopilot_interface_msgs::action::Takeoff_GetResult_Request goal_id(::autopilot_interface_msgs::action::Takeoff_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_GetResult_Request>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_GetResult_Request_goal_id();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_GetResult_Response_result
{
public:
  explicit Init_Takeoff_GetResult_Response_result(::autopilot_interface_msgs::action::Takeoff_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Takeoff_GetResult_Response result(::autopilot_interface_msgs::action::Takeoff_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_GetResult_Response msg_;
};

class Init_Takeoff_GetResult_Response_status
{
public:
  Init_Takeoff_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Takeoff_GetResult_Response_result status(::autopilot_interface_msgs::action::Takeoff_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Takeoff_GetResult_Response_result(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_GetResult_Response>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_GetResult_Response_status();
}

}  // namespace autopilot_interface_msgs


namespace autopilot_interface_msgs
{

namespace action
{

namespace builder
{

class Init_Takeoff_FeedbackMessage_feedback
{
public:
  explicit Init_Takeoff_FeedbackMessage_feedback(::autopilot_interface_msgs::action::Takeoff_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::autopilot_interface_msgs::action::Takeoff_FeedbackMessage feedback(::autopilot_interface_msgs::action::Takeoff_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_FeedbackMessage msg_;
};

class Init_Takeoff_FeedbackMessage_goal_id
{
public:
  Init_Takeoff_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Takeoff_FeedbackMessage_feedback goal_id(::autopilot_interface_msgs::action::Takeoff_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Takeoff_FeedbackMessage_feedback(msg_);
  }

private:
  ::autopilot_interface_msgs::action::Takeoff_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::action::Takeoff_FeedbackMessage>()
{
  return autopilot_interface_msgs::action::builder::Init_Takeoff_FeedbackMessage_goal_id();
}

}  // namespace autopilot_interface_msgs

#endif  // AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__TAKEOFF__BUILDER_HPP_
