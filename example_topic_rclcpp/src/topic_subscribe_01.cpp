#include<rclcpp/rclcpp.hpp>
#include<std_msgs/msg/string.hpp>
#include<interfaces_demo/msg/person_info.hpp>
class TopicSubscribe01 : public rclcpp::Node
{
public:    
    TopicSubscribe01(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(),"node is running.");
        command_subscribe_ = this->create_subscription<interfaces_demo::msg::PersonInfo>("name",
        10,
        std::bind(&TopicSubscribe01::command_callback, this, std::placeholders::_1));
    }

private:
    rclcpp::Subscription<interfaces_demo::msg::PersonInfo>::SharedPtr command_subscribe_;
    void command_callback(const interfaces_demo::msg::PersonInfo::SharedPtr msgs)
    {

        RCLCPP_INFO(this->get_logger(), "receiving ,name:%s,age:%ld",
        msgs->name.c_str(),
        msgs->age
        );
    }
};
int main(int argc,char **argv)
{
    rclcpp::init(argc, argv);
    auto node =std::make_shared<TopicSubscribe01>("topic_subscribe_01");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
