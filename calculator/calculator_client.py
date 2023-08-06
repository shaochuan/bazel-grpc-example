"""The Python implementation of the GRPC calculator.CalculatorService client."""

from __future__ import print_function
import logging

import grpc

import calculator.calculator_pb2
import calculator.calculator_pb2_grpc


def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = calculator.calculator_pb2_grpc.CalculatorServiceStub(channel)
        response = stub.Add(calculator.calculator_pb2.AddRequest(integers=[1,2,3]))
    print(f'Adding 1 + 2 + 3 = {response.sum}')


if __name__ == '__main__':
    logging.basicConfig()
    run()