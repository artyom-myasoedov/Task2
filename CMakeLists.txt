cmake_minimum_required(VERSION 3.21)
project(Task2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task2 main.cpp Producer.cpp Producer.h Consumer.cpp Consumer.h Store.cpp Store.h Shop.cpp Shop.h WholesaleConsumer.cpp WholesaleConsumer.h RetailConsumer.cpp RetailConsumer.h GlobalProducer.cpp GlobalProducer.h Exception.cpp Exception.h Application.cpp Application.h Car.cpp Car.h Truck.cpp Truck.h GasolineTanker.cpp GasolineTanker.h)
