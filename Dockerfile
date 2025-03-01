FROM gcc:latest
RUN apt-get update && apt-get install -y \
    cmake \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build . && \
    ctest --output-on-failure
# CMD ["/app/build/calculator"] 
# modified CMD to not run the executable
CMD ["tail", "-f", "/dev/null"] 