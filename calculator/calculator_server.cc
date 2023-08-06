#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "calculator/calculator.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using calculator::AddRequest;
using calculator::AddResponse;
using calculator::CalculatorService;

class CalculatorServiceImpl final : public CalculatorService::Service {
  Status Add(ServerContext* context, const AddRequest* request,
                  AddResponse* reply) override {
    int sum = 0;
    for (const int& n : request->integers()) {
        sum += n;
    }
    reply->set_sum(sum);
    return Status::OK;
  }
};

void RunServer() {
  std::string address = "0.0.0.0";
  std::string port = "50051";
  std::string server_address = address + ":" + port;
  CalculatorServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}