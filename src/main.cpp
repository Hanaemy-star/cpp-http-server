#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

int main() {
    try {
        io_context io;

        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080));
        std::cout << "Server started at http://localhost:8080\n";

        tcp::socket socket(io);
        acceptor.accept(socket);
        std::cout << "Client connected!\n";

        std::string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Length: 12\r\n"
            "\r\n"
            "Hello world!";
        write(socket, buffer(response));
        std::cout << "Response sent!\n";
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}




