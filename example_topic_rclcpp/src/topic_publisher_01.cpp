#include<rclcpp/rclcpp.hpp>
#include"std_msgs/msg/string.hpp"
#include<interfaces_demo/msg/person_info.hpp>

class TopicPublisher01 : public rclcpp::Node
{
public:
    TopicPublisher01(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "node is running");
        command_publisher_ = this->create_publisher<interfaces_demo::msg::PersonInfo>("name",10);
        
        timer_=this->create_wall_timer(
            std::chrono::seconds(1),
            std::bind(&TopicPublisher01::timer_callback,this)
        );
    
    }
private:


    rclcpp::Publisher<interfaces_demo::msg::PersonInfo>::SharedPtr command_publisher_;
    void timer_callback()
    {
        // 创建消息
        
        
        interfaces_demo::msg::PersonInfo info;
        info.name = "zhangsan";
        info.age =18;
        
        // 日志打印
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", info.name.c_str());
        // 发布消息
        command_publisher_->publish(info);

    }
    // 声名定时器指针
    rclcpp::TimerBase::SharedPtr timer_;
    // 声明话题发布者指针
    

    
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TopicPublisher01>("topic_publisher_01");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}