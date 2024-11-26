find_package(Protobuf REQUIRED)
add_library(edgericc edgeric.cpp edgeric.h wrapper.cpp wrapper.h control_mcs.pb.cc control_weights.pb.cc metrics.pb.cc control_mcs.pb.h control_weights.pb.h metrics.pb.h)

target_include_directories(edgericc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${PROTOBUF_INCLUDE_DIRS})

target_link_libraries(edgericc PUBLIC ${ZMQ_LIBRARIES} ${Protobuf_LIBRARIES} zmq)
