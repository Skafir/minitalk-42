# Minitalk 📡

Minitalk is a small data communication program using UNIX signals to exchange text messages between two executables: a server and a client.

## Features

- **Real-time communication**: Send and receive messages instantly.
- **Uses UNIX signals**: The program utilizes `SIGUSR1` and `SIGUSR2` for data transmission.
- **Error handling**: Both server and client properly manage communication errors.

## Prerequisites

Before running Minitalk, ensure your system is capable of compiling code with `cc` and handling UNIX signals.

## Installation

Clone this GitHub repository to your local machine.

Compile the server and client programs using `make`:

```bash
make
```

## Usage

To start the server, execute:

```bash
./server
```

The server will display its PID. Use this PID to connect the client by running:

```bash
./client <server_PID> "Your message here"
```

The message will be sent to the server, which will then display it on the screen.