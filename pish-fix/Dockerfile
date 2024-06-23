FROM ubuntu:22.04
LABEL Description="Build environment"

ENV HOME /root

SHELL ["/bin/bash", "-c"]

RUN apt-get update && apt-get -y --no-install-recommends install \ 
    build-essential \
    clang \
    cmake \
    git \
    g++ \
    gdb \
    valgrind \
    vim \
    ca-certificates \
    cppcheck \
    cpplint \
    wget

RUN git clone https://github.com/google/googletest \
    && cd googletest \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && make install


CMD ["/bin/bash"]