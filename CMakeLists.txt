cmake_minimum_required(VERSION 3.23)
project(nitay-and-ilan-last-mission)

set(CMAKE_CXX_STANDARD 14)

add_executable(nitay-and-ilan-last-mission
        CanDistance.cpp
        CanDistance.h
        CheDistance.cpp
        CheDistance.h
        Distance.h
        DistancesFunc.cpp
        Distance.h
        EucDistance.cpp
        EucDistance.h
        KNN.cpp
        KNN.h
        ManDistance.cpp
        ManDistance.h
        MinDistance.cpp
        MinDistance.h
        client.cpp
        func1.cpp
        func1.h
        func2.cpp
        func2.h
        func3.cpp
        func3.h
        func4.cpp
        func4.h
        func5.cpp
        func5.h
        CLI.cpp
        CLI.h
        SocketIO.cpp
        DefultIO.h
        HoldInfo.cpp
        HoldInfo.h
        server.cpp
        Command.h)
