#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>
#include<std_msgs/msg/float64.hpp>
//#include<interfaces_demo/msg/person_info.hpp>
class Timesub : public rclcpp::Node
{
public:    
    Timesub(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(),"node is running.");
        command_subscribe_ = this->create_subscription<std_msgs::msg::Float64>("name",
        10,
        std::bind(&Timesub::command_callback, this, std::placeholders::_1));
    }

private:
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr command_subscribe_;
    void command_callback(const std_msgs::msg::Float64::SharedPtr msg)
    {

        RCLCPP_INFO(this->get_logger(), "receiving ,time:%lf",
        msg->data
        );
    }
};
int main(int argc,char **argv)
{
    rclcpp::init(argc, argv);
    auto node =std::make_shared<Timesub>("timesub");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
