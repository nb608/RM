#include "rclcpp/rclcpp.hpp"
#include "interfaces_demo/srv/add_two_int.hpp"

class Client : public rclcpp::Node
{
public:
    Client(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Client is running.");

        client = this->create_client<interfaces_demo::srv::AddTwoInt>("add");

        send_msgs();
    }
private:
    rclcpp::Client<interfaces_demo::srv::AddTwoInt>::SharedPtr client;

    void send_msgs()
    {
        while(!client->wait_for_service(std::chrono::seconds(2)))
        {
            RCLCPP_INFO(this->get_logger(),"wait for server");
        }

        auto request = std::make_shared<interfaces_demo::srv::AddTwoInt_Request>();
        request-> x1 = 10;
        request-> y1 = 20;
        request-> a =1;
        request-> b =1; 
        request-> angle =1;

        client->async_send_request(request,std::bind(&Client::client_callback,this,std::placeholders::_1));
    }
    
    void client_callback(const rclcpp::Client<interfaces_demo::srv::AddTwoInt>::SharedFuture response)
    {
        auto result = response.get();

        float x2=result->x2;
        float y2=result->y2;
        RCLCPP_INFO(this->get_logger(),"x2:%f,y2:%f",x2,y2);
    }
};

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);

    auto node = std::make_shared<Client>("Client");

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}