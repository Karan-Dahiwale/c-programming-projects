
# BUS RESEVATION SYSTEM

This project is a Console-Based Bus Reservation System in C, designed to simulate a basic but functional ticket booking system. It allows users to log in securely, view available buses, book and cancel seats, and check current seat status. The system is fully menu-driven and operates through the terminal. It uses file handling to store booking data like passenger names and seat numbers, ensuring data persists across sessions. Key C concepts used include arrays, strings, loops, functions, and system calls for cross-platform compatibility. It’s a practical project for learning file I/O and structuring real-world applications in C.










## Features

- Secure login system
- View list of available buses
- Book tickets and assign passenger names to seat numbers
- Cancel booked tickets
- View seat-wise status (booked/empty)
- Persistent data using text files



## Tech Stack


- **Language**: C
- **Platform**: Terminal / Command Line Interface
- **Data Storage**: File Handling (text files)


## HOW TO RUN
Prerequsites

- GCC Compiler

- Linux/Mac or Windows terminal




## run locally

Clone the project

```bash
  git clone https://github.com/Karan-Dahiwale/c-programming-projects.git
```

Go to the project directory

```bash
  cd Bus_Resevation_system
```

Compilation

```bash
  gcc main.c -o bus_reservation_system
```

 Run the Program

```bash
  ./bus_reservation_system
```


## Login Credentials



```bash
  Username: user
  Password: pass
```


## Functionalities Explained


| Option               | Description                                                  |
|----------------------|--------------------------------------------------------------|
| **View Bus List**    | Displays the list of available buses.                        |
| **Book Tickets**     | Allows users to choose a bus, select number of seats, assign seat numbers, and input passenger names. |
| **Cancel Booking**   | Cancels an existing ticket by entering the seat number.      |
| **Bus Status Board** | Shows current status of all seats (booked or empty) for a selected bus. |
| **Log Out**          | Exits the application.                                       |

## Files Generated Per Bus
Each bus (1 to 4) generates:
- trX.txt: Remaining seat count

- statusX.txt: Names of passengers

- numberX.txt: Seat numbers booked
Where X is the bus number.
## Authors

- Hi, I'm [@Karan-Dahiwale](https://github.com/Karan-Dahiwale), an engineering graduate passionate about building efficient and scalable applications. 


## License


MIT License

Copyright (c) 2025 Karan Dahiwale

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, and distribute copies of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.



