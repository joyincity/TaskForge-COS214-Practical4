FROM ubuntu:22.04

#Avoid interactive prompt hangs during package installation
ENV DEBIAN_FRONTEND=noninteractive

#Install g++, make, gdb, and valgrind
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

#Set working directory inside the container
WORKDIR /app

#Copy all project files into the container
#Note its dangerous ,copying EVERYTHING
COPY . .

#Build the application using Makefile
RUN make clean && make

#Default command when running the container
CMD ["./taskforge"]