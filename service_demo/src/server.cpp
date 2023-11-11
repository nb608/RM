#include "rclcpp/rclcpp.hpp"
#include "interfaces_demo/srv/add_two_int.hpp"

class Server : public rclcpp::Node
{
public:
    Server(std::string name) : Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "Server is running.");
        server = this->create_service<interfaces_demo::srv::AddTwoInt>(
            "add",
            std::bind(&Server::server_callback,this,std::placeholders::_1,std::placeholders::_2)
        );
    }
private:
    rclcpp::Service<interfaces_demo::srv::AddTwoInt>::SharedPtr server;
    void server_callback(
        const interfaces_demo::srv::AddTwoInt::Request::SharedPtr request,
        const interfaces_demo::srv::AddTwoInt::Response::SharedPtr response
    )
    {
        RCLCPP_INFO(this->get_logger(),"receving");
        float x1=request->x1;
        float y1=request->y1;
        float a=request->a;
        float b=request->b;
        float angle=request->angle;

        response->x2 =(x1+a)*cos(angle*3.1415926/180.0)+(y1+b)*sin(angle*3.1415926/180.0);
        response->y2 =(y1+b)*cos(angle*3.1415926/180.0)-(x1+a)*sin(angle*3.1415916/180.0);
    }
};

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);

    auto node = std::make_shared<Server>("Server");

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}