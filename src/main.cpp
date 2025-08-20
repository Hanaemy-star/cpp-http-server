#include <iostream>
#include<vector>
#include <thread>
#include <sstream>
#include <boost/asio.hpp>


using namespace boost::asio;
using ip::tcp;

int main() {
    try {
        io_context io;

        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 8080));
        std::vector<std::thread> threads;

        for (int i = 0; i < 4; ++i) {
            threads.emplace_back([&io]() {io.run();});
        }

        while (true) {
            tcp::socket socket(io);
            acceptor.accept(socket);

            std::thread([socket = std::move(socket)]() mutable {
                streambuf buf;
                read_until(socket, buf, "\r\n\r\n");
                std::ostringstream oss;
                oss << std::this_thread::get_id();
                std::string response = "HTTP/1.1 200 OK\r\n\r\nThread ID: " +
                     oss.str();
            write(socket, buffer(response));
            }).detach();
        }

        for (auto& t : threads) t.join();

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}




