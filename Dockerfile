# initialize from the image

FROM debian:9

# update repositories

RUN apt-get update

# install build tools and dependencies

RUN apt-get install -y build-essential git python python-ecdsa gcc-arm-none-eabi
