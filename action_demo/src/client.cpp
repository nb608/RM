#include"rclcpp/rclcpp.hpp"
#include"rclcpp_action/rclcpp_action.hpp"
#include"interfaces_demo/action/progress.hpp"

class ActionClient: public rclcpp::Node
{
public:
    ActionClient(std::string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(),"ActionClient is running.");

        client = rclcpp_action::create_client<interfaces_demo::action::Progress>(
            this,
            "get_sum"
        ); 
        
        

        send_goal(10);   
    }

private:
    rclcpp_action::Client<interfaces_demo::action::Progress>::SharedPtr client;

    void feedback_callback(rclcpp_action::ClientGoalHandle<interfaces_demo::action::Progress>::SharedPtr goal_handle,
    const std::shared_ptr<const interfaces_demo::action::Progress::Feedback> feedback
    )
    {
        double progress= feedback->progress;
        RCLCPP_INFO(this->get_logger(),"%2f%%",progress);
    }
    /*
    FeedbackCallback = typename GoalHandle::FeedbackCallback
    GoalHandle = ClientGoalHandle<ActionT>;
    using GoalHandle = ClientGoalHandle<ActionT>;
  using WrappedResult = typename GoalHandle::WrappedResult;
  using GoalResponseCallback = std::function<void (typename GoalHandle::SharedPtr)>;
  ResultCallback = typename GoalHandle::ResultCallback
    */
   void goal_response_callback(rclcpp_action::ClientGoalHandle<interfaces_demo::action::Progress>::SharedPtr goal_handle)
   {
        if(!goal_handle)
        {
            RCLCPP_INFO(this->get_logger(),"Rejected");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(),"Accept");
        }
   }
   void result_callback(const rclcpp_action::ClientGoalHandle<interfaces_demo::action::Progress>::WrappedResult & result)
   {
        if (result.code==rclcpp_action::ResultCode::SUCCEEDED)
        {
            RCLCPP_INFO(this->get_logger(),"succeed");
        }
        else if (result.code==rclcpp_action::ResultCode::CANCELED)
        {
            RCLCPP_INFO(this->get_logger(),"canceled");
        }
        else if(result.code==rclcpp_action::ResultCode::ABORTED)
        {
            RCLCPP_INFO(this->get_logger(),"aborted");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(),"unknow");
        }
   }
   void send_goal(int num)
   {
        if(!client->wait_for_action_server(std::chrono::seconds(10)))
        {
            RCLCPP_ERROR(this->get_logger(),"false");
            return;
        }
        RCLCPP_ERROR(this->get_logger(),"ok");
        interfaces_demo::action::Progress::Goal goal;
        goal.num=10;
        rclcpp_action::Client<interfaces_demo::action::Progress>::SendGoalOptions options;
        options.goal_response_callback = std::bind(&ActionClient::goal_response_callback, this, std::placeholders::_1);
        options.feedback_callback = std::bind(&ActionClient::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
        options.result_callback = std::bind(&ActionClient::result_callback, this, std::placeholders::_1);

        client->async_send_goal(goal,options);
   }

};

int main(int argc ,char **argv)
{
    
    rclcpp::init(argc,argv);
    auto node = std::make_shared<ActionClient>("ActionClient");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
