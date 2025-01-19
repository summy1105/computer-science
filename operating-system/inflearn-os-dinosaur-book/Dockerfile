FROM ubuntu:20.04

ENV TZ=Asia/Seoul

RUN apt update && apt install -y gcc
RUN apt-get update && apt-get install -y \
    openjdk-8-jdk \
    tzdata \
    && ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezone \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*


WORKDIR /home/ostudy/