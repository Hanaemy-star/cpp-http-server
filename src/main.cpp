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

        streambuf buf;
        read_until(socket, buf, "\r\n\r\n");
        std::istream is(&buf);
        std::string request;
        std::getline(is, request);
        std::cout << "Request: " << request << std::endl;

        std::string path = request.substr(4, request.find(' ', 4) - 4);


        std::string response =
            "HTTP/1.1 200 OK\r\nContent-Length: " +
                std::to_string(path.size() + 6) +
                    "\r\n\r\nPATH: " +
                        path;

        write(socket, buffer(response));
        std::cout << "Response sent!\n";
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}




