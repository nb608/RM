#include"rclcpp/rclcpp.hpp"
#include"rclcpp_action/rclcpp_action.hpp"
#include"interfaces_demo/action/progress.hpp"

class ActionServer: public rclcpp::Node
{
public:
    ActionServer(std::string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(),"ActionServer is running.");

        server = rclcpp_action::create_server<interfaces_demo::action::Progress>(
            this,
            "get_sum",
            std::bind(&ActionServer::handle_goal,this,std::placeholders::_1,std::placeholders::_2),
            std::bind(&ActionServer::handle_cancel,this,std::placeholders::_1),
            std::bind(&ActionServer::handle_accepted,this,std::placeholders::_1));
    }

private:
    rclcpp_action::Server<interfaces_demo::action::Progress>::SharedPtr server;

    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const interfaces_demo::action::Progress::Goal> goal
    )
    {
        if (goal->num <=1)
        {
            RCLCPP_INFO(this->get_logger(),"must >1");
            return rclcpp_action::GoalResponse::REJECT;
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(std::shared_ptr<rclcpp_action::ServerGoalHandle<interfaces_demo::action::Progress>> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(),"Canceled!");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void execute(std::shared_ptr<rclcpp_action::ServerGoalHandle<interfaces_demo::action::Progress>> goal_handle)
    {
        auto feedback = std::make_shared<interfaces_demo::action::Progress::Feedback>();
        auto result = std::make_shared<interfaces_demo::action::Progress::Result>();
        int num = goal_handle->get_goal()->num;
        int sum = 0;
        rclcpp::Rate rate(1);
        for (int i=1;i <= num; i++)
        {
            sum +=i;
            double progress = i/(double)num;
            feedback->progress =progress;
            goal_handle->publish_feedback(feedback);

            if(goal_handle->is_canceling())
            {
                RCLCPP_INFO(this->get_logger(),"Canceled");
                result->sum;
                goal_handle->canceled(result);

            }
            rate.sleep();
        }
        result->sum =sum;
        goal_handle->succeed(result);
        
    }


    void handle_accepted(std::shared_ptr<rclcpp_action::ServerGoalHandle<interfaces_demo::action::Progress>> goal_handle)
    {
        std::thread(std::bind(&ActionServer::execute,this,goal_handle)).detach();
    }

    
};

int main(int argc ,char **argv)
{
    
    rclcpp::init(argc,argv);
    auto node = std::make_shared<ActionServer>("ActionServer");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
