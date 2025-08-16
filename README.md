# 🚀 High-performance HTTP Server in C++  

A multi-threaded HTTP server built with **Boost.Asio**, designed for high load and low latency.  

## Features  
- ✅ Asynchronous I/O with Boost.Asio  
- ✅ Thread pool for handling concurrent connections  
- ✅ LRU caching for frequent requests  
- ✅ Benchmarking with `wrk` (10k+ RPS)  

## Build & Run  
```bash  
git clone https://github.com/твой-ник/cpp-http-server.git  
cd cpp-http-server  
mkdir build && cd build  
cmake .. && make  
./server  
```  

## Usage  
```bash  
curl http://localhost:8080  
```  

## TODO  
- [ ] Add SSL support  
- [ ] Implement REST API  
